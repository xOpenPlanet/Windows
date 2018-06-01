#include "imperchat.h"
#include <QDesktopWidget>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include "httpnetworksharelib.h"
#include "imvideoplayer.h"

IMPerChat::IMPerChat(QWidget *parent)
: QWidget(parent),
mbExpress_widget_is_showing(false)
{
	ui.setupUi(this);
	mExpressWidget = NULL;
	cut_line = NULL;

	connect(ui.mWebView, SIGNAL(sigZoomImg(QString)), this, SLOT(slotZoomImg(QString)));
	connect(ui.mWebView, SIGNAL(sigVideoPlay(QString)), this, SLOT(slotVideoPlay(QString)));
	connect(ui.mWebView, SIGNAL(sigOpenFile(QString)), this, SLOT(slotOpenFile(QString)));

	connect(ui.mWebView, SIGNAL(sigOpenDocument(QString)), this, SLOT(slotOpenDocument(QString)));
	connect(ui.mWebView, SIGNAL(sigCancleLoadorDownLoad()), this, SLOT(slotCancleLoadorDownLoad()));
	connect(ui.mWebView, SIGNAL(sigSendFileByID(QString)), this, SLOT(slotSendFileByID(QString)));
	connect(ui.mWebView, SIGNAL(sigGetFile(QString)), this, SLOT(slotGetFile(QString)));
	connect(ui.mWebView, SIGNAL(sigSaveFile(QString)), this, SLOT(slotSaveFile(QString)));
	connect(ui.mWebView, SIGNAL(sigDrag(QStringList)), this, SLOT(slotCefDrags(QStringList)));
	
	ui.mWebView->InitCefUrl("file:///./html/chat.html");

	ui.mTextEditPer->installEventFilter(this);
	ui.mTextEditPer->setFocus();

	ui.mTextEditPer->setAcceptDrops(false);
	this->setAcceptDrops(true);

	drag = false;   

	copying = false;   

	mChatHeaderImage = NULL;   
	mUpFileName = "";

	ui.mTextEditPer->setContextMenuPolicy(Qt::NoContextMenu);

	RegisterHandle();
	
	setAttribute(Qt::WA_DeleteOnClose, true);

	QFile file(":/qssWidget/Resources/qssWidget/imperchat.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();

	ui.mPButtonPerFont->hide();
	ui.mPButtonPerShake->hide();
	ui.mPButtonPerVoiceChat->hide();
	ui.mPButtonSecretLetter->hide();
}

IMPerChat::~IMPerChat()
{
	if (mExpressWidget != NULL)
	{
		delete mExpressWidget;
		mExpressWidget = NULL;
	}

	if (mChatHeaderImage != NULL)
	{
		delete mChatHeaderImage;
		mChatHeaderImage = NULL;
	}

	if (cut_line != NULL)
	{
		delete cut_line;
		cut_line = NULL;
	}

	if (sendTip)
		delete sendTip;
}

void IMPerChat::slotZoomImg(QString strfileName)
{
	QString fileName = strfileName.mid(strfileName.indexOf("file:///") + 8);
	
	ZoomImg *zoom = new ZoomImg();
	zoom->OpenImg(fileName);
}

void IMPerChat::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}

void IMPerChat::dropEvent(QDropEvent *event)
{
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty())
		return;
	foreach(QUrl url, urls)
	{
		QString file_name = url.toLocalFile();
		SendDragFile(file_name);
	}
}

void IMPerChat::slotCefDrags(QStringList list)
{
	for each (QString file in list)
	{
		file = file.replace("\\", "/");
		this->SendDragFile(file);
	}
}

void IMPerChat::SendDragFile(QString fileName)
{
	QString FileName = fileName.mid(fileName.lastIndexOf("/") + 1);
	UserInfo userinfo = gDataManager->getUserInfo();
	QString strHeadPath;
	QFile file(userinfo.strUserAvatarLocal);
	if (file.exists() && file.size() != 0)
	{
		strHeadPath = "file:///" + userinfo.strUserAvatarLocal;
	}
	else
	{
		strHeadPath = "file:///./html/temp.png";
	}
	file.close();

	int nUserID = userinfo.nUserID;
	if (ui.mLabelPerNickChat == NULL)
	{
		qDebug() << QStringLiteral("IMPerChat::SendDragFile空指针");
		return;
	}
	QString toUserID = ui.mLabelPerNickChat->objectName();
	MessageInfo messageInfo = gSocketMessage->SendFileMessage(nUserID, toUserID.toInt(), 0,"");
	gDataBaseOpera->DBOnInsertFileInfo(QString(messageInfo.msgID), fileName, "");//将发送文件信息插入数据库

	FileTypeEx* fileType = new FileTypeEx(this);
	QString strPath = fileType->GetFilePic(fileName);

	QString strLiID = QString(messageInfo.msgID) + QString("send");
	QString strsize = gSocketMessage->ByteConversion(fileType->GetFileSize(fileName));
	delete fileType;
	strsize = QString("(") + strsize + QString(")");
	QString strend = QString("SendFile(\"%1\",\"%2\",\"%3\",%4,\"%5\",\"%6\",\"%7\")").arg(strHeadPath).arg(FileName).arg(QString(messageInfo.msgID)).arg(0).arg(strPath).arg(strLiID).arg(strsize);
	qDebug() << "153"<<strend;
	ui.mWebView->ExecuteJavaScript(strend);

	AppConfig conf = gDataManager->getAppConfigInfo();

	FileMessage *fileMessage = new FileMessage;
	fileMessage->nFromUserID = nUserID;
	fileMessage->nToUserID = toUserID.toInt();
	fileMessage->nDeliverType = 0;
	fileMessage->strUpLoadUrl = conf.PanServerUploadURL;
	fileMessage->strFilePath = fileName;

	QFile upfile(fileName);
	int nIndex = fileName.lastIndexOf("/");
	QString strFileName = fileName.mid(nIndex + 1);
	nIndex = strFileName.lastIndexOf(".");
	fileMessage->FileName = strFileName;
	fileMessage->FileType = strFileName.mid(nIndex + 1, strFileName.length());
	fileMessage->FileSize = gSocketMessage->ByteConversion(upfile.size());
	HttpNetWork::HttpUpLoadFile *httpUpLoad = new HttpNetWork::HttpUpLoadFile(this);
	httpUpLoad->setUserData(Qt::UserRole, fileMessage);
	httpUpLoad->setData(QVariant::fromValue(messageInfo));
	connect(httpUpLoad, SIGNAL(sigUpLoadFinished(bool, QByteArray)), this, SLOT(slotUpFileReplyFinished(bool, QByteArray)));
	connect(httpUpLoad, SIGNAL(sigUpLoadProgress(qint64, qint64)), this, SLOT(doUpLoadFileProgress(qint64, qint64)));
	connect(this, SIGNAL(sigCancle()), httpUpLoad, SLOT(slotLoadorDownLoadCancle()));
	QVariantMap pargram;
	pargram.insert("parentId", "66662");
	pargram.insert("createUser", "6662");
	httpUpLoad->StartUpLoadFile(conf.PanServerUploadURL, fileName, pargram);
}

void IMPerChat::RegisterHandle()
{
	if (mExpressWidget == NULL)
		mExpressWidget = new ExpressWidget(this);
	rectExpressWidget = QRect(QPoint(0, ui.toolWidget->y() - mExpressWidget->height()), mExpressWidget->size());

	if (!mChatHeaderImage)
		mChatHeaderImage = new QLabelHeader(this);
	mChatHeaderImage->hide();
	mChatHeaderImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");

	connect(mExpressWidget, SIGNAL(sigExpressImagePath(QString)), this, SLOT(doExpressNormalImagePath(QString)));

	connect(ui.mPButtonPerFont, SIGNAL(clicked()), this, SLOT(doClickedSetFont()));
	connect(ui.mPButtonPerExpress, SIGNAL(clicked()), this, SLOT(doSelectExpress()));
	connect(ui.mPButtonPerSend, SIGNAL(clicked()), this, SLOT(doSendMessage()));

	connect(ui.mPButtonPerShake, SIGNAL(clicked()), this, SLOT(doClickedShake()));
	connect(ui.mPButtonPerVoiceChat, SIGNAL(clicked()), this, SLOT(doClickedVoiceChat()));
	connect(ui.mPButtonPerPicture, SIGNAL(clicked()), this, SLOT(doClickedPicture()));
	connect(ui.mPButtonPerCutPicture, SIGNAL(clicked()), this, SLOT(doClickedCutPicture()));
	connect(ui.mPButtonPerLog, SIGNAL(clicked()), this, SLOT(slotOpenPerLog()));

	connect(ui.mPButtonSecretLetter, SIGNAL(clicked()), this, SLOT(slotClickedSendLetter()));

	sendTip = new QLabel(this);
	QPixmap tipImage(":/PerChat/Resources/person/sendtip.png");
	sendTip->resize(tipImage.size());
	sendTip->setPixmap(tipImage);
	sendTip->hide();
}

void IMPerChat::slotOpenPerLog()
{
	emit sigOpenPerLog(objectName());
}

void IMPerChat::slotOpenFile(QString msgID)
{
	QString fileName = gDataBaseOpera->DBGetFileInfoLocalPath(msgID);
	if (fileName == "")
	{
		qDebug() << QStringLiteral("fileName为空!OpenFile Failed!") << endl;
	}
	else
	{
		QDesktopServices bs;
		bs.openUrl(QUrl::fromLocalFile(fileName));
	}
}

void IMPerChat::slotVideoPlay(QString mediaPath)
{
	QString path = mediaPath;
	IMVideoPlayer *video = new IMVideoPlayer();
	video->videoPlay(path);
	video->setAttribute(Qt::WA_DeleteOnClose);
}

void IMPerChat::slotSendFileByID(QString msgID)
{
	UserInfo userInfo = gDataManager->getUserInfo();
	QString fileName = gDataBaseOpera->DBGetFileInfoLocalPath(msgID);
	SendDragFile(fileName);
}

void IMPerChat::slotOpenDocument(QString msgID)
{
	QString fileName = gDataBaseOpera->DBGetFileInfoLocalPath(msgID);
	if (fileName == "")
	{
		qDebug() << QStringLiteral("fileName为空!OpenDocument Failed!") << endl;
	}
	else
	{
		QString filePath = fileName.left(fileName.lastIndexOf("/"));
		QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
	}
}


void IMPerChat::doClickedSetFont()
{
	OnCloseExpress();
	ui.mTextEditPer->append("\n");
}

void IMPerChat::doSelectExpress()
{
	if (mExpressWidget != NULL)
	{
		if (!mbExpress_widget_is_showing)
		{
			mExpressWidget->showNormalEmotion(QPoint());   // 不能在 ExpressWidget 类里面 move, 因为GroupChatWidget是父窗口, 子窗口内部无法根据父窗口的位置移动 wxd note
			mExpressWidget->move(QPoint(0, ui.toolWidget->y() - mExpressWidget->height()));
			mExpressWidget->show();
			mbExpress_widget_is_showing = true;
		}
		else
		{
			mExpressWidget->hide();
			mbExpress_widget_is_showing = false;
		}
	}
}

//发送消息
void IMPerChat::doSendMessage()
{
	OnCloseExpress();
	if (gSocketMessage)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		int nUserID = userInfo.nUserID;
		if (ui.mLabelPerNickChat == NULL)
		{
			qDebug() << "IMPerChat::doSendMessage空指针";
			return;
		}
		QString toUserID = ui.mLabelPerNickChat->objectName();

		QString strHtmlText("");
		{
			QString str_html = ui.mTextEditPer->toHtml();   // wxd add
			QString tag_p = str_html.mid(str_html.indexOf("<p"));
			QString msg_text = tag_p.mid(tag_p.indexOf(">") + 1);
			strHtmlText = msg_text.left(msg_text.indexOf("</p>"));
			strHtmlText.replace("\"", "'");   // 此处的表情是以 <img src='qrc:/xxx/xxx/x.gif'/> 形式保存在字符串中的
			strHtmlText.replace("img", "img class='expression' ");  //给表情增加类名，用于与其他图片的区分。
		}

		QString strText = formatSendMessageFromImgPathToImgDescription(strHtmlText);

		// 因为是获取的 QTextEdit 的html内容   所以 < > "会被转义
		strText = strText.replace("&lt;", "<");
		strText = strText.replace("&gt;", ">");
		strText = strText.replace("&quot;", "\"");
		if (strText == "<br />")
		{
			if (sendTip->isHidden())
			{
				QTimer *timer = new QTimer(this);
				connect(timer, SIGNAL(timeout()), sendTip, SLOT(hide()));
				int x = ui.toolWidget->x() + ui.mPButtonPerSend->pos().x() - 140;
				int y = ui.toolWidget->y() + ui.mPButtonPerSend->pos().y() + 30;
				sendTip->move(x, y);
				sendTip->show();
				timer->setSingleShot(true);
				timer->start(3000);
			}
			return;
		}
		strText.replace("<br />", "\n");
		MessageInfo msgInfo = gSocketMessage->SendTextMessage(nUserID, toUserID.toInt(), 0, (short)0, strText);
		OnInertSendMessageTextInfo(strHtmlText, userInfo.strUserAvatarLocal, msgInfo);

		//根据消息类型设置显示的内容。
		if (msgInfo.MessageChildType == 1) //1图片3视频5文件。
			msgInfo.strMsg = QStringLiteral("[图片]");
		if (msgInfo.MessageChildType == 3) //1图片3视频5文件。
			msgInfo.strMsg = QStringLiteral("[视频]");
		if (msgInfo.MessageChildType == 5) //1图片3视频5文件。
			msgInfo.strMsg = QStringLiteral("[文件]");

		MessageListInfo messageListInfo;
		messageListInfo.nBudyyID = this->objectName().toInt();
		messageListInfo.strLastMessage = msgInfo.strMsg;
		messageListInfo.nLastTime = msgInfo.ClientTime;
		messageListInfo.strBuddyName = ui.mLabelPerNickChat->text();
		BuddyInfo buddy = gDataBaseOpera->DBGetBuddyInfoByID(this->objectName());
		if(buddy.strNickName.isEmpty())
			buddy = gDataBaseOpera->DBGetGroupUserFromID(this->objectName());
		messageListInfo.strBuddyHeaderImage = buddy.strLocalAvatar;
		messageListInfo.messageType = msgInfo.MessageChildType;
		messageListInfo.nUnReadNum = 0;
		messageListInfo.isGroup = 0;
		gDataBaseOpera->DBInsertPerMessageListInfo(messageListInfo);

		ui.mTextEditPer->clear();
	}
}

void IMPerChat::doExpressNormalImagePath(QString strImgPath)
{
	QString qrc_path("<img src='./html");
	qrc_path = qrc_path + strImgPath + "'/>";
	QTextCursor cursor = ui.mTextEditPer->textCursor();
	cursor.insertHtml(qrc_path);

	OnCloseExpress();
}

void IMPerChat::slotCancleLoadorDownLoad()
{
	emit sigCancle();
}

void IMPerChat::slotUpFileReplyFinished(bool bResult,QByteArray result)
{
	HttpNetWork::HttpUpLoadFile *requestHttp = qobject_cast<HttpNetWork::HttpUpLoadFile*>(sender());
	if (bResult && requestHttp)
	{
		FileMessage *fileMessage = (FileMessage *)requestHttp->userData(Qt::UserRole);
		QVariant var = requestHttp->getData();
		MessageInfo msgInfo = var.value<MessageInfo>();

		QString newLiID = QString(msgInfo.msgID) + QString("send");
		QString changeLi = QString("ChangeLi(\"%1\")").arg(newLiID);
		qDebug() << "390" << changeLi;
		ui.mWebView->ExecuteJavaScript(changeLi);

		QString cancleID = msgInfo.msgID + QString("can");
		QString cancle = QString("ChangeLi(\"%1\")").arg(cancleID);
		qDebug() << "395" << cancle;
		ui.mWebView->ExecuteJavaScript(cancle);

		gSocketMessage->setUpFileReplyFinished(result,fileMessage,msgInfo);
	}
}

void IMPerChat::doUpLoadFileProgress(qint64 sendnum, qint64 total)
{
	HttpNetWork::HttpUpLoadFile *requestHttp = qobject_cast<HttpNetWork::HttpUpLoadFile*>(sender());
	if (requestHttp)
	{
		QVariant var = requestHttp->getData();
		MessageInfo msgInfo = var.value<MessageInfo>();
		if (total > 0)
		{
			int num = 250 * sendnum / total;
			QString processID = msgInfo.msgID + QString("bar");
			QString strend = QString("ProgressBar(\"%1\",%2)").arg(processID).arg(num);
			qDebug() << "414" << strend;
			ui.mWebView->ExecuteJavaScript(strend);
		}
		else{
			QString processID = msgInfo.msgID + QString("bar");
			QString strend = QString("ProgressBar(\"%1\",%2)").arg(processID).arg(0);
			qDebug() << "420" << strend;
			ui.mWebView->ExecuteJavaScript(strend);
		}
	}
}

//点击发送窗口抖动
void IMPerChat::doClickedShake()
{
	OnCloseExpress();
}

//点击发送语音
void IMPerChat::doClickedVoiceChat()
{
	OnCloseExpress();
}

//点击发送图片
void IMPerChat::doClickedPicture()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("打开"), ".",
		tr("图像文件(*.bmp;*.jpeg;*.jpg;*.png;*.gif)"));
	if (!fileName.isEmpty())
	{
		SendPicture(fileName);
	}
	OnCloseExpress();
}

void IMPerChat::SendPicture(QString fileName)
{
	QString strFileName = QString("<img src='") + QString("file:///") + fileName + QString("'/>");
	QImage img(fileName);
	UserInfo userInfo = gDataManager->getUserInfo();
	int nUserID = userInfo.nUserID;
	if (ui.mLabelPerNickChat == NULL)
	{
		return;
	}
	QString toUserID = ui.mLabelPerNickChat->objectName();
	AppConfig configInfo = gDataManager->getAppConfigInfo();
	MessageInfo messageInfo = gSocketMessage->SendPicMessage(nUserID, toUserID.toInt(), 0, "");

	QString strPath;
	QFile file(userInfo.strUserAvatarLocal);
	if (!file.exists() || file.size() == 0)
	{
		strPath = "file:///./html/temp.png";
	}
	else
	{
		strPath = QString("file:///") + userInfo.strUserAvatarLocal;
	}


	QString strSend = QString("SendAppend(\"%1\",\"%2\",\"%3\",%4,%5);").arg(strPath).arg(strFileName).arg(QString(messageInfo.msgID)).arg(0).arg(messageInfo.integral);
	qDebug() << "478" << strSend;
	ui.mWebView->ExecuteJavaScript(strSend);

	PicMessage *picMessage = new PicMessage;
	picMessage->nFromUserID = nUserID;
	picMessage->nToUserID = toUserID.toInt();
	picMessage->nDeliverType = 1;
	picMessage->strUpLoadUrl = configInfo.PanServerUploadURL;
	picMessage->strDownLoadUrl = configInfo.PanServerDownloadURL;
	picMessage->strPicPath = fileName;
	picMessage->nPicHeight = img.height();
	picMessage->nPicWidth = img.width();

	HttpNetWork::HttpUpLoadFile *httpUpLoad = new HttpNetWork::HttpUpLoadFile(this);
	httpUpLoad->setUserData(Qt::UserRole, picMessage);
	httpUpLoad->setData(QVariant::fromValue(messageInfo));
	connect(httpUpLoad, SIGNAL(sigUpLoadFinished(bool, QByteArray)), this, SLOT(slotUpPicReplyFinished(bool, QByteArray)));
	QVariantMap pargram;
	pargram.insert("parentId", "66662");
	pargram.insert("createUser", "6662");
	httpUpLoad->StartUpLoadFile(configInfo.PanServerUploadURL, fileName, pargram);
}

/*发送图片 上传完图片 结果*/
void IMPerChat::slotUpPicReplyFinished(bool result,QByteArray strResult)
{
	if (result)
	{
		HttpNetWork::HttpUpLoadFile *act = qobject_cast<HttpNetWork::HttpUpLoadFile*>(sender());
		if (act)
		{
			PicMessage *picMessage = (PicMessage *)act->userData(Qt::UserRole);
			QVariant var = act->getData();
			MessageInfo msgInfo = var.value<MessageInfo>();
			gSocketMessage->setUpPicReplyFinished(strResult, picMessage, msgInfo);
		}
	}
}

//点击截图
void IMPerChat::doClickedCutPicture()
{
	OnCloseExpress();

	emit sigWidgetMinSize();

	TCHAR szAppPath[MAX_PATH] = { 0 };
	_stprintf(szAppPath, L"0x%x", this->winId());

	ShellExecute(HWND(this->winId()), L"open", L"ScreenShotTool.exe", szAppPath, NULL, SW_SHOW);
}

bool IMPerChat::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	PMSG msg = (PMSG)message;
	if (msg->message == WM_MESSAGE_SCREENSHOT)
	{
		QString strTemp = QString::number(msg->lParam);
		OnSendScreenShotPic(strTemp);
	}
	return QWidget::nativeEvent(eventType, message, result);
}

//发送消息添加到webview
void IMPerChat::OnInertSendMessageTextInfo(QString strMsg, QString strHeadImage, MessageInfo msgInfo)
{
	QString strPath;

	QFile file(strHeadImage);
	if (file.exists() && file.size() != 0)
	{
		strPath = "file:///" + strHeadImage;
	}
	else
	{
		strPath = "file:///./html/temp.png";
	}
	file.close();

	if (msgInfo.MessageChildType == 0)
	{
		QString strMessage = formatMessageFromImgDescriptionToImgPath(strMsg);
		strMessage = strMessage.replace("\n", "<br>");
		strMessage = strMessage.replace("./html", ".");

		QString strSend = QString("SendAppend(\"%1\",\"%2\",\"%3\",%4,%5);").arg(strPath).arg(strMessage).arg(QString(msgInfo.msgID)).arg(msgInfo.MessageState).arg(msgInfo.integral);
		qDebug() << "564" << strSend;
		ui.mWebView->ExecuteJavaScript(strSend);
	}
	if (msgInfo.MessageChildType == 1)
	{
		QJsonParseError jsonError;
		QString strFileName;
		QString FileName;
		QString strFileLocalPath;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(msgInfo.strMsg.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (jsonDocument.isObject())
			{
				QVariantMap result = jsonDocument.toVariant().toMap();
				strFileLocalPath = result["path"].toString();
			}
		}
		strFileName = QString("<img src='") + QString("file:///") + strFileLocalPath + QString("'/>");
		QString strSend = QString("SendAppend(\"%1\",\"%2\",\"%3\",%4,%5);").arg(strPath).arg(strFileName).arg(QString(msgInfo.msgID)).arg(msgInfo.MessageState).arg(msgInfo.integral);
		qDebug() << "584" << strSend;
		ui.mWebView->ExecuteJavaScript(strSend);
	}
	if (msgInfo.MessageChildType == 5)
	{
		QJsonParseError jsonError;
		QString strFileName;
		QString FileName;
		QString strFileLocalPath;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(msgInfo.strMsg.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (jsonDocument.isObject())
			{
				QVariantMap result = jsonDocument.toVariant().toMap();
				strFileName = result["FileName"].toString();
				strFileLocalPath = result["FileLocalPath"].toString();
			}
		}

		FileTypeEx* fileType = new FileTypeEx(this);
		QString strPicPath = fileType->GetFilePic(strFileName);

		QString strSize = QString("(") + gSocketMessage->ByteConversion(fileType->GetFileSize(strFileLocalPath)) + QString(")");
		delete fileType;
		QString newLiID = QString(msgInfo.msgID) + QString("send");
		QString strend = QString("SendFile(\"%1\",\"%2\",\"%3\",%4,\"%5\",\"%6\",\"%7\")").arg(strPath).arg(strFileName).arg(QString(msgInfo.msgID)).arg(msgInfo.MessageState).arg(strPicPath).arg(newLiID).arg(strSize);
		qDebug() << "611" << strend;
		ui.mWebView->ExecuteJavaScript(strend);

		if (msgInfo.MessageState == 3 || msgInfo.MessageState == 4 || msgInfo.MessageState == 5 || msgInfo.MessageState == 6 || msgInfo.MessageState == 7)
		{
			QString newLiID = QString(msgInfo.msgID) + QString("send");
			QString changeLi = QString("ChangeLi(\"%1\")").arg(newLiID);
			qDebug() << "618" << changeLi;
			ui.mWebView->ExecuteJavaScript(changeLi);

			QString canID = QString(msgInfo.msgID) + QString("can");
			QString Cancle = QString("ChangeLi(\"%1\")").arg(canID);
			qDebug() << "623" << Cancle;
			ui.mWebView->ExecuteJavaScript(Cancle);
		}
	}
	if (msgInfo.MessageChildType == 62)
	{
		QString strSystemName;
		QString strTime;
		QString strTitle;
		QJsonParseError jsonError;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(msgInfo.strMsg.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (jsonDocument.isObject())
			{
				QVariantMap result = jsonDocument.toVariant().toMap();
				strSystemName = result["systemName"].toString();
				strTime = result["time"].toString();
				strTitle = result["title"].toString();
			}
		}
		QString strSendMask = QString("SendTask(\"%1\",\"%2\",\"%3\",\"%4\",\"%5\",%6,\"%7\")").arg(strPath).arg(strSystemName).arg("qrc:/Task/Resources/task/task.png").arg(strTime).arg(strTitle).arg(msgInfo.MessageState).arg(QString(msgInfo.msgID));
		qDebug() << "645" << strSendMask;
		ui.mWebView->ExecuteJavaScript(strSendMask);
	}
}

/*表单消息*/
void IMPerChat::OnRecvFormMessage(MessageInfo messageInfo, QString strHeaderPath)
{
	QStringList listTemp = messageInfo.strMsg.split("&");
	QString strTitle;
	QString strTime;
	QString strClicketUrl = "www.baidu.com";
	QString strImgeUrl;
	for (int i = 0; i < listTemp.size(); i++)
	{
		int pos = listTemp[i].indexOf("=");
		QString strKey = listTemp[i].mid(0, pos);
		QString strValue = listTemp[i].mid(pos + 1, listTemp[i].length());
		if (strKey == "title")
		{
			strTitle = strValue;
		}
		if (strKey == "time")
		{
			strTime = strValue;
		}
	}
	strImgeUrl = "file:///./html/temp.png";
	QString strPath;
	QFile file(strHeaderPath);
	if (file.exists() && file.size() != 0)
	{
		strPath = "file:///" + strHeaderPath;
	}
	else
	{
		strPath = "file:///./html/temp.png";
	}
	file.close();

	QString strRecFile = QString("RecTask(\"%1\",\"%2\",\"%3\",\"%4\",\"%5\",\"%6\",\"%7\",\"%8\")").arg(strPath).arg("表单").arg(strImgeUrl).arg(strTime).arg(strTitle).arg("").arg(strClicketUrl).arg(QString(messageInfo.msgID));
	qDebug() << "686" << strRecFile;
	ui.mWebView->ExecuteJavaScript(strRecFile);
}

void IMPerChat::OnRecvTaskMessage(MessageInfo messageInfo, QString strHeadImage)
{
	QJsonParseError jsonError;
	QString strState;
	QString strSystemName;
	QString strImgeUrl;
	QString strTime;
	QString strTitle;
	QString strSubtitle;
	QString strClicketUrl = "www.baidu.com";
	QJsonDocument jsonDocument = QJsonDocument::fromJson(messageInfo.strMsg.toUtf8(), &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QVariantMap result = jsonDocument.toVariant().toMap();
			strState = result["state"].toString();
			strSystemName = result["systemName"].toString();
			strImgeUrl = result["image"].toString();
			strTime = result["time"].toString();
			strTitle = result["title"].toString();
			strSubtitle = result["subtitle"].toString();
		}
	}

	strImgeUrl = "file:///./html/task.png";

	bool bOk = false;
	qlonglong ntime = strTime.toLong(&bOk);
	if (strTime.size() == 13 && bOk)
	{
		qlonglong nTemp = strTime.toLongLong();
		int nTime = nTemp / 1000;
		QDateTime dt = QDateTime::fromTime_t(nTime);
		QDate tempDate = dt.date();
		strTime = QString("%1年%2月%3日").arg(tempDate.year()).arg(tempDate.month()).arg(tempDate.day());
	}


	QString strPath;
	QFile file(strHeadImage);
	if (file.exists() && file.size() != 0)
	{
		strPath = "file:///" + strHeadImage;
	}
	else
	{
		strPath = "file:///./html/temp.png";
	}
	file.close();

	QString strRecFile = QString("RecTask(\"%1\",\"%2\",\"%3\",\"%4\",\"%5\",\"%6\",\"%7\",\"%8\")").arg(strPath).arg(strSystemName).arg(strImgeUrl).arg(strTime).arg(strTitle).arg(strSubtitle).arg(strClicketUrl).arg(QString(messageInfo.msgID));
	qDebug() << "742" << strRecFile;
	ui.mWebView->ExecuteJavaScript(strRecFile);
}

void IMPerChat::OnRecvFileMessage(MessageInfo messageInfo, QString strHeadImage,QString fileLocalPath)
{
	QJsonDocument doc = QJsonDocument::fromJson(messageInfo.strMsg.toUtf8());
	QVariantMap map = doc.toVariant().toMap();

	QString strFileName = map["FileName"].toString();
	QString  fileSize = map["FileSize"].toString();

	FileTypeEx* fileType = new FileTypeEx(this);
	QString strPath = fileType->GetFilePic(strFileName);
	fileType->deleteLater();
	fileType = NULL;

	QString OtherHeadImg = QString("file:///") + strHeadImage;

	QString strUlID = QString(messageInfo.msgID) + QString("recv");
	QString strUlID2 = QString(messageInfo.msgID) + QString("recv2");
	QString strSize = QString("(") + fileSize + QString(")");
	QString strRecFile = QString("RecFile(\"%1\",\"%2\",\"%3\",\"%4\",\"%5\",\"%6\",\"%7\",%8)").arg(OtherHeadImg).arg(strFileName).arg(strPath).arg(QString(messageInfo.msgID)).arg(strUlID).arg(strUlID2).arg(strSize).arg(messageInfo.integral);
	qDebug() << "765" << strRecFile;
	ui.mWebView->ExecuteJavaScript(strRecFile);

	if (fileLocalPath != "")
	{
		QString strUlID = QString(messageInfo.msgID) + QString("recv");
		QString changeLi = QString("ChangeLiTwo(\"%1\")").arg(strUlID);
		qDebug() << "772" << changeLi;
		ui.mWebView->ExecuteJavaScript(changeLi);

		QString strUlID2 = QString(messageInfo.msgID) + QString("recv2");
		QString changeLi2 = QString("ChangeLiTwo(\"%1\")").arg(strUlID2);
		qDebug() << "777" << changeLi2;
		ui.mWebView->ExecuteJavaScript(changeLi2);

		QString strUlID3 = QString(messageInfo.msgID) + QString("recv2");
		QString changeLi3 = QString("ChangeLiTwo(\"%1\")").arg(strUlID3);
		qDebug() << "782" << changeLi3;
		ui.mWebView->ExecuteJavaScript(changeLi3);
	}
}

void IMPerChat::slotGetFile(QString msgID)
{
	MessageInfo messageInfo = gSocketMessage->DBGetMessageInfoWithMsgID(msgID);
	QJsonDocument jsonDocument = QJsonDocument::fromJson(messageInfo.strMsg.toUtf8());
	QVariantMap result = jsonDocument.toVariant().toMap();
	QString fileName = result["FileName"].toString();
	QString fileID = result["FileId"].toString();

	QString strUlID2 = QString(messageInfo.msgID) + QString("recv2");
	QString changeLi = QString("ChangeLiTwo(\"%1\")").arg(strUlID2);
	qDebug() << "797" << changeLi;
	ui.mWebView->ExecuteJavaScript(changeLi);

	AppConfig configInfo = gDataManager->getAppConfigInfo();
	QString httpUrl = QString(configInfo.PanServerDownloadURL) + fileID + QString("/download");
	UserInfo userInfo = gDataManager->getUserInfo();
	QDir dir;
	QString currentPath = dir.currentPath();
	QString strFilePath = currentPath + QString("/files/") + QString("%1").arg(userInfo.nUserID) + QString("/") + fileName;
	HttpNetWork::HttpDownLoadFile *netWork = new HttpNetWork::HttpDownLoadFile;
	netWork->setData(QVariant::fromValue(messageInfo));
	netWork->setObjectName(strFilePath);
	connect(netWork, SIGNAL(sigDownFinished(bool)), this, SLOT(slotRequestHttpFileResult(bool)));
	connect(netWork, SIGNAL(sigDownloadProgress(qint64, qint64)), this, SLOT(slotDownLoadFileProgress(qint64, qint64)));
	connect(this, SIGNAL(sigCancle()), netWork, SLOT(slotLoadorDownLoadCancle()));
	netWork->StartDownLoadFile(httpUrl, strFilePath);
}

bool IMPerChat::slotSaveFile(QString msgID)
{
	QString dir = QFileDialog::getExistingDirectory(this, QStringLiteral("打开文件夹"),"/",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (dir == "")
	{
		return false;
	}
	QString strUlID2 = QString(msgID) + QString("recv2");
	QString changeLi = QString("ChangeLiTwo(\"%1\")").arg(strUlID2);
	qDebug() << "824" << changeLi;
	ui.mWebView->ExecuteJavaScript(changeLi);

	MessageInfo messageInfo = gSocketMessage->DBGetMessageInfoWithMsgID(msgID);
	QJsonDocument jsonDocument = QJsonDocument::fromJson(messageInfo.strMsg.toUtf8());
	QVariantMap result = jsonDocument.toVariant().toMap();
	QString fileName = result["FileName"].toString();
	QString fileID = result["FileId"].toString();

	AppConfig configInfo = gDataManager->getAppConfigInfo();
	QString httpUrl = QString(configInfo.PanServerDownloadURL) + fileID + QString("/download");

	QString strFilePath = dir + QString("/") + fileName;
	HttpNetWork::HttpDownLoadFile *netWork = new HttpNetWork::HttpDownLoadFile;
	netWork->setData(QVariant::fromValue(messageInfo));
	netWork->setObjectName(strFilePath);
	connect(netWork, SIGNAL(sigDownFinished(bool)), this, SLOT(slotRequestHttpFileResult(bool)));
	connect(netWork, SIGNAL(sigDownloadProgress(qint64, qint64)), this, SLOT(slotDownLoadFileProgress(qint64, qint64)));
	connect(this, SIGNAL(sigCancle()), netWork, SLOT(slotLoadorDownLoadCancle()));
	netWork->StartDownLoadFile(httpUrl, strFilePath);
	return true;
}

void IMPerChat::slotDownLoadFileProgress(qint64 recvnum, qint64 total)
{
	HttpNetWork::HttpDownLoadFile *act = qobject_cast<HttpNetWork::HttpDownLoadFile*>(sender());
	if (act)
	{
		QVariant var = act->getData();
		MessageInfo msgInfo = var.value<MessageInfo>();
		if (total > 0)
		{
			int num = recvnum * 250 / total;
			QString barId = msgInfo.msgID + "bar";
			QString strend = QString("ProgressBar(\"%1\",%2)").arg(barId).arg(num);
			qDebug() << "859" << strend;
			ui.mWebView->ExecuteJavaScript(strend);
		}
		else{
			QString barId = msgInfo.msgID + "bar";
			QString strend = QString("ProgressBar(\"%1\",%2)").arg(barId).arg(0);
			qDebug() << "865" << strend;
			ui.mWebView->ExecuteJavaScript(strend);
		}
	}
}

void IMPerChat::slotRequestHttpFileResult(bool result)
{
	HttpNetWork::HttpDownLoadFile *act = qobject_cast<HttpNetWork::HttpDownLoadFile*>(sender());
	if (act)
	{
		QVariant var = act->getData();
		MessageInfo msgInfo = var.value<MessageInfo>();
		QString filePath = act->objectName();
		if (result)
		{
			gDataBaseOpera->DBOnInsertFileInfo(QString(msgInfo.msgID), filePath, "");//将接收到的文件信息插入数据库

			QString strUlID = msgInfo.msgID + QString("recv");
			QString strChange = QString("ChangeLiTwo(\"%1\")").arg(strUlID);
			qDebug() << "885" << strChange;
			ui.mWebView->ExecuteJavaScript(strChange);

			QString strUlID2 = msgInfo.msgID + QString("recv2");
			QString strChange2 = QString("ChangeLiTwo(\"%1\")").arg(strUlID2);
			qDebug() << "889" << strChange2;
			ui.mWebView->ExecuteJavaScript(strChange2);
		}
		else{
			QString strUlID = msgInfo.msgID + QString("recv");
			QString strChange = QString("ChangeLiThr(\"%1\")").arg(strUlID);
			qDebug() << "896" << strChange;
			ui.mWebView->ExecuteJavaScript(strChange);

			QString strUlID2 = msgInfo.msgID + QString("recv2");
			QString strChange2 = QString("ChangeLiThr(\"%1\")").arg(strUlID2);
			qDebug() << "901" << strChange2;
			ui.mWebView->ExecuteJavaScript(strChange2);
		}
	}
}

void IMPerChat::OnRecvImgMessage(MessageInfo messageInfo, QString strHeadImage)
{
	QString strMsg = "";

	QString msgID = QString(messageInfo.msgID);
	if (messageInfo.strMsg == "load")
	{
		strMsg = "file:///./html/load.gif";
		QString strPhotoImgTag = QString("<img width=30px height=30px src='") + strMsg + QString("' />");
		OnInsertRecMessageTextInfo(strPhotoImgTag, strHeadImage, msgID, messageInfo.integral);
	}
	else if (messageInfo.strMsg != "fail")
	{
		messageInfo.strMsg.replace(" ", "%20");
		QString strPhotoImgPath = QString("<img src='") + QString("file:///") + messageInfo.strMsg + QString("' />");
		OnInsertRecMessageTextInfo(strPhotoImgPath, strHeadImage, msgID, messageInfo.integral);
	}
}

void IMPerChat::OnRecVdoMessage(MessageInfo messageInfo, QString strHeadImage)
{
	QString strMsg = "";

	QString msgID = QString(messageInfo.msgID);
	if (messageInfo.strMsg == "load")
	{
		strMsg = "file:///./html/load.gif";
		QString strPhotoImgTag = QString("<img width=30px height=30px src='") + strMsg + QString("' />");
		OnInsertRecMessageTextInfo(strPhotoImgTag, strHeadImage, msgID, messageInfo.integral);
	}
	else if (messageInfo.strMsg != "fail")
	{
		messageInfo.strMsg.replace(" ", "%20");
		QString strPhotoImgPath = QString("<video width='320px' height='180px' style='object-fit: fill;' src='") + QString("file:///") + messageInfo.strMsg + QString("' />");
		OnInsertRecVideoInfo(strPhotoImgPath, strHeadImage, msgID, messageInfo.integral);
	}
}

//接收消息添加到webview
void IMPerChat::OnInsertRecMessageTextInfo(QString strMsg, QString strHeadImage, QString strMsgID, int score)
{
	QString strPath;
	QDir dir;
	if (strHeadImage == ":/PerChat/Resources/person/temp.png")
	{
		strPath = "file:///./html/temp.png";
	}
	else
	{
		QFile file(strHeadImage);
		if (file.exists() && file.size() != 0)
		{
			strPath = "file:///" + strHeadImage;
		}
		else
		{
			strPath = "file:///./html/temp.png";
		}
		file.close();
	}
	QString strMessage = formatMessageFromImgDescriptionToImgPath(strMsg);
	strMessage = strMessage.replace("\n", "<br>");
	strPath.replace(" ", "%20");
	QString strSend = QString("RecAppend(\"%1\",\"%2\",\"%3\",%4);").arg(strPath).arg(strMessage).arg(strMsgID).arg(score);
	qDebug() << "971" << strSend;
	ui.mWebView->ExecuteJavaScript(strSend);
}
void IMPerChat::OnInsertRecVideoInfo(QString strMsg, QString strHeadImage, QString strMsgID, int score)
{
	QString strPath;
	QDir dir;
	if (strHeadImage == ":/PerChat/Resources/person/temp.png")
	{
		strPath = "file:///./html/temp.png";
	}
	else
	{
		QFile file(strHeadImage);
		if (file.exists() && file.size() != 0)
		{
			strPath = "file:///" + strHeadImage;
		}
		else
		{
			strPath = "file:///./html/temp.png";
		}
		file.close();
	}
	QString strMessage = formatMessageFromImgDescriptionToImgPath(strMsg);
	strMessage = strMessage.replace("\n", "<br>");
	strPath.replace(" ", "%20");
	QString strSend = QString("VdoAppend(\"%1\",\"%2\",\"%3\",%4);").arg(strPath).arg(strMessage).arg(strMsgID).arg(score);
	qDebug() << "999" << strSend;
	ui.mWebView->ExecuteJavaScript(strSend);
}

void IMPerChat::OnClearMessageInfo()
{
	qDebug() << "1005" << "clear()";
	ui.mWebView->ExecuteJavaScript("clear()");
}

void IMPerChat::OnCloseExpress()
{
	if (mExpressWidget != NULL)
		mExpressWidget->hide();
	mbExpress_widget_is_showing = false;    // wxd add   更新表情窗口状态为隐藏
}

void IMPerChat::OnSetNikeName(QString strText, QString strBuddyID)
{
	ui.mLabelPerNickChat->setText(strText);
	ui.mLabelPerNickChat->setObjectName(strBuddyID);
	QFont font;
	font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font.setPointSize(16);
	QFontMetrics fm(font);
	int str_width = fm.width(strText);
	ui.mLabelPerNickChat->setFixedSize(str_width + 8, ui.mLabelPerNickChat->height());
}

// 设置头像 imchat 中调用
void IMPerChat::OnSetChatHeaderImage(QString strHeaderImg)
{
	QByteArray bytearray;
	QFile file(strHeaderImg);
	if (file.open(QIODevice::ReadOnly) && file.size() != 0)
	{
		bytearray = file.readAll();
	}
	file.close();
	QPixmap pix;
	if (!pix.loadFromData(bytearray) || bytearray == "")
	{
		pix.load(":/PerChat/Resources/person/temp.png");
	}
	mChatHeaderImage->setAutoFillBackground(true);
	mChatHeaderImage->setPixmap(pix);
	mChatHeaderImage->setScaledContents(true);
	mChatHeaderImage->setObjectName(strHeaderImg);
}

// 隐藏聊天窗口头像
void IMPerChat::HideChatHeaderImage()
{
	mChatHeaderImage->hide();
}

void IMPerChat::InitMessageInfo(QString strUserID)
{
	if (strUserID.isEmpty())
		strUserID = this->objectName();

	//清空
	OnClearMessageInfo();

	//获取好友头像
	UserInfo userInfo = gDataManager->getUserInfo();
	QString strUserHeadImage = userInfo.strUserAvatarLocal;

	//int nTemp

	QMap<QString, QList<MessageInfo> > mapTemp = gSocketMessage->DBGetCurrentDayMessage();
	
	QMap<QString, QList<MessageInfo> >::iterator itor = mapTemp.begin();
	for (; itor != mapTemp.end(); ++itor)
	{
		if (itor.key() == strUserID)
		{
			for (int i = 0; i < itor.value().size(); i++)
			{
				//added by wangqingjie
				if (itor.value()[i].MessageState == 7){//将数据库中未读消息更新为已读
					gSocketMessage->SetMessageState(itor.value()[i].msgID, 6);
				}

				if (itor.value()[i].nFromUserID == userInfo.nUserID)
				{
					//说明我是发送方
					OnInertSendMessageTextInfo(itor.value()[i].strMsg, strUserHeadImage, itor.value()[i]);
				}
				else
				{
					MessageInfo message = itor.value()[i];

					BuddyInfo buddy = gDataBaseOpera->DBGetBuddyInfoByID(QString::number(message.nFromUserID));
					if (buddy.strNickName.isEmpty())
						buddy = gDataBaseOpera->DBGetGroupUserFromID(QString::number(message.nFromUserID));

					QString strBuddyHeadImage = buddy.strLocalAvatar;
					if (strBuddyHeadImage.isEmpty())
						strBuddyHeadImage = "file:///./html/temp.png";

					switch (message.MessageChildType)
					{
					case 0: // 文字消息
						OnInsertRecMessageTextInfo(message.strMsg, buddy.strLocalAvatar, QString(message.msgID), message.integral);
						break;
					case 1: // 图片消息
						OnRecvImgMessage(message, buddy.strLocalAvatar);
						break;
					case 3: //视频消息
						OnRecVdoMessage(message, buddy.strLocalAvatar);
						break;
					case 5://文件消息
						if (gDataBaseOpera)
						{
							QString strLocalFilePath = gDataBaseOpera->DBGetFileInfoLocalPath(message.msgID);
							OnRecvFileMessage(message, buddy.strLocalAvatar, strLocalFilePath);
						}
						break;
					case 62:      //任务消息
						OnRecvTaskMessage(message, buddy.strLocalAvatar);
						break;
					default:
						break;
					}
				}
			}
		}
	}
}

void IMPerChat::mousePressEvent(QMouseEvent *event)
{
	QRect rect = QRect(ui.mWebView->pos() + this->pos(), ui.mWebView->size());
	ExpressHide(rect, event->pos());
	rect = QRect(ui.titleWidget->pos() + this->pos(), ui.titleWidget->size());
	ExpressHide(rect, event->pos());
	rect = QRect(ui.toolWidget->pos() + this->pos(), ui.toolWidget->size());
	ExpressHide(rect, event->pos());
	rect = QRect(ui.mLabelPerNickChat->pos() + this->pos(), ui.mLabelPerNickChat->size());
	ExpressHide(rect, event->pos());
	if (!rectExpressWidget.contains(event->pos()))
	{
		OnCloseExpress();
	}
	return QWidget::mousePressEvent(event);
}
void IMPerChat::ExpressHide(QRect rect, QPoint pos)
{
	if (rect.contains(pos))
	{
		OnCloseExpress();
	}
}

void IMPerChat::UpdateMessageStateInfo(QByteArray msgID, int nState, int score)
{
	QString strSend = QString("SetMsgState(\"%1\",%2,%3)").arg(QString(msgID)).arg(nState).arg(score);
	qDebug() << "1157" << strSend;
	ui.mWebView->ExecuteJavaScript(strSend);
}

//事件过滤器
bool IMPerChat::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == ui.mWebView)
	{
		if (e->type() == QEvent::FocusIn)
		{
			OnCloseExpress();
		}
	}
	else if (obj == ui.mTextEditPer)
	{
		if (e->type() == QEvent::FocusIn)
		{
			OnCloseExpress();
		}
		if (e->type() == QEvent::KeyPress)
		{
			QKeyEvent *event = static_cast<QKeyEvent*>(e);
			if (event->key() == Qt::Key_Return && !(event->modifiers() == Qt::ShiftModifier))
			{
				doSendMessage();
				return true;
			}
			if (event->key() == Qt::Key_Control)
				copying = true;
			if (event->key() == Qt::Key_V && copying)
			{
				QClipboard *board = QApplication::clipboard();
				const QMimeData *mimeData = board->mimeData();
				if (mimeData->hasHtml())
				{
					QString html = mimeData->html();
					QTextDocument doc;
					doc.setHtml(html);
					html = doc.toPlainText();
					board->setText(html);
				}
			}

			if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
			{
				QString text = ui.mTextEditPer->toPlainText();
				if (!text.contains("\n"))
				    emit sigKeyUpDown(event);
			}	
		}
		if (e->type() == QEvent::KeyRelease)
		{
			QKeyEvent *event = static_cast<QKeyEvent*>(e);
			if (event->key() == Qt::Key_Control)
				copying = false;
		}
	}
	if (obj == cut_line)
	{
		if (e->type() == QEvent::Enter)
			this->setCursor(Qt::SizeVerCursor);
		if (e->type() == QEvent::Leave)
			this->setCursor(Qt::ArrowCursor);
		if (e->type() == QEvent::MouseButtonPress)
			drag = true;
		if (e->type() == QEvent::MouseButtonRelease)
			drag = false;
		if (e->type() == QEvent::MouseMove && drag)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			int diff = -event->pos().y();
			int h = ui.mTextEditPer->height() + diff;
			if (h > 200)
				h = 200;
			if (h < 50)
				h = 50;
			ui.mTextEditPer->setFixedHeight(h);
		}
	}
	return QWidget::eventFilter(obj, e);
}

void IMPerChat::showEvent(QShowEvent *event)
{
	ui.mTextEditPer->setFocus();
}

QString IMPerChat::formatSendMessageFromImgPathToImgDescription(const QString& strSendMessage)
{
	if (strSendMessage.isEmpty())
		return strSendMessage;

	QString str_src(strSendMessage);
	str_src = str_src.replace("/ >", "/>");

	QRegExp re_img("<img[\\.A-Za-z0-9/:?%&=\\-_+#;' ]*/[ ]*>");      // 从 strSendMessage 中过滤 <img */> 标签的正则表达式
	QRegExp re_img_key("src='./html[\\.A-Za-z0-9/:?%&=\\-_+#;' ]*'");    // 从 <img */> 标签中过滤 src 的正则表达式

	QString cur_img_tag("");
	QString str_result("");
	while (re_img.indexIn(str_src) != -1)
	{
		cur_img_tag = re_img.cap(0);
		int cur_idx = re_img.indexIn(str_src);
		str_result += str_src.left(cur_idx);
		str_src.remove(0, cur_idx + cur_img_tag.length());    // 删除已经遍历过的字符

		QString str_img_description("");
		cur_img_tag.replace(" ", "");
		if (re_img_key.indexIn(cur_img_tag) != -1)
		{
			QString str_img_key = re_img_key.cap(0);
			str_img_key = str_img_key.replace(" ", "");
			str_img_key = str_img_key.left(str_img_key.length() - 1);						// 去掉最右边的 单引号 '
			str_img_key = str_img_key.mid(QString("src='./html").length());					// 拿到表情对应的 qrc资源路径
			str_img_description = mExpressWidget->GetDescriptionByImagePath(str_img_key);	// 根据key拿到对应的表情描述字
			str_result += str_img_description;				// 将描述字追加到 str_result中
		}
		else
		{
			str_result += "[表情]";
		}
	}
	str_result += str_src;
	return str_result;
}

// 将 包含[xx]表情形式的信息字符串 转换为 表情的路径形式的字符串
QString IMPerChat::formatMessageFromImgDescriptionToImgPath(const QString& strMessage)
{
	if (strMessage.isEmpty())
		return strMessage;

	QString str_src(strMessage);
	str_src = str_src.replace("/ >", "/>");

	QRegExp re_img_val("\\[[^\\[^\\]]*\\]");     

	QString str_result("");
	while (re_img_val.indexIn(str_src) != -1)
	{
		QString img_descrip = re_img_val.cap(0);
		int cur_idx = re_img_val.indexIn(str_src);
		str_result += str_src.left(cur_idx);
		str_src.remove(0, cur_idx + img_descrip.length());    

		QString img_path = mExpressWidget->GetImagePathByDescription(img_descrip);
		if (!img_path.isEmpty())
			str_result += "<img src='." + img_path + "'/>";  
		else
			str_result += img_descrip;   
	}
	str_result += str_src;
	return str_result;
}

void IMPerChat::OnSendScreenShotPic(QString strShotFileName)
{
	QString strCurrentPath = gSocketMessage->GetExeDir();
	QString strTemp = strCurrentPath + QString("/ScreenShot/%1.jpg").arg(strShotFileName);
	SendPicture(strTemp);
	emit sigShowNormalWindow();
}

void IMPerChat::slotClickedSendLetter()
{
	SecretLetterWidget *letterWidget = new SecretLetterWidget();
	connect(letterWidget, SIGNAL(sigSecretLetter(QString, QString)), this, SLOT(slotSecretLetter(QString, QString)));
	letterWidget->show();
}

void IMPerChat::slotSecretLetter(QString password, QString text)
{
	qDebug() << password;
	qDebug() << text;
}
