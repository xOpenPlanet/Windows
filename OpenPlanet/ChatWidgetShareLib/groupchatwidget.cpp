#include "groupchatwidget.h"
#include <QFileDialog>
#include "childWidget/filetypeex.h"
#include <QDesktopServices>
#include "childWidget/zoomimg.h"
#include <QProcess>
#include "imvideoplayer.h"

GroupChatWidget::GroupChatWidget(QWidget *parent)
	: QWidget(parent), 
	mbExpress_widget_is_showing(false)
{
	ui.setupUi(this);
	mExpressWidget = NULL;

	drag = false;  //�Ƿ�ͨ����ק���������С��
	copying = false;   //ctrl���£���ʾҪ���������

	connect(ui.mGroupWebView, SIGNAL(sigZoomImg(QString)), this, SLOT(slotZoomImg(QString)));
	connect(ui.mGroupWebView, SIGNAL(sigVideoPlay(QString)), this, SLOT(slotVideoPlay(QString)));

	connect(ui.mGroupWebView, SIGNAL(sigOpenDocument(QString)), this, SLOT(slotOpenDocument(QString)));
	connect(ui.mGroupWebView, SIGNAL(sigCancleLoadorDownLoad()), this, SLOT(slotCancleLoadorDownLoad()));
	connect(ui.mGroupWebView, SIGNAL(sigGetFile(QString)), this, SLOT(slotGetFile(QString)));
	connect(ui.mGroupWebView, SIGNAL(sigSaveFile(QString)), this, SLOT(slotSaveFile(QString)));

	connect(ui.mGroupWebView, SIGNAL(sigOpenGroupFile(QString)), this, SLOT(slotOpenGroupFile(QString)));
	connect(ui.mGroupWebView, SIGNAL(sigSendFile(QString)), this, SLOT(slotSendFile(QString)));
	connect(ui.mGroupWebView, SIGNAL(sigSendFileByID(QString)), this, SLOT(slotSendFileByID(QString)));

	connect(ui.mGroupWebView, SIGNAL(sigDrag(QStringList)), this, SLOT(slotCefDrags(QStringList)));

	ui.mGroupWebView->InitCefUrl("file:///./html/chat.html");

	// ����Ⱥ��Ա�б�Ĵ�ֱ����������ʽ
	QFile scroolbar_style_qss(":/ScrollBar/Resources/QSS/scrollbarStyle.qss");
	scroolbar_style_qss.open(QFile::ReadOnly);
	ui.mGroupUserlistWidget->verticalScrollBar()->setStyleSheet(scroolbar_style_qss.readAll());
	ui.mGroupUserlistWidget->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(ui.mGroupUserlistWidget, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slotContextMenuRequested(const QPoint &)));
	connect(ui.mGroupUserlistWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slotClickedDoubleItem(QListWidgetItem*)));
	connect(ui.mGroupUserlistWidget->verticalScrollBar(), SIGNAL(sliderMoved(int)), this, SLOT(slotGroupUserInfoLoad(int)));

	ui.mLabelGroupNum->setStyleSheet("font: 75 10pt ΢���ź�;font-size:14px;color:#108ee9");
	movie = new QMovie(":/GroupChat/Resources/groupchat/refresh.gif");
	ui.refreshBtn->installEventFilter(this);

	ui.mGroupWebView->setContextMenuPolicy(Qt::NoContextMenu);
	ui.mTextEditGroup->setContextMenuPolicy(Qt::NoContextMenu);

	ui.mGroupWebView->setAcceptDrops(false);
	ui.mTextEditGroup->setAcceptDrops(false);

	RegisterHandle();
	
	setChildWidgetFixedSize(); 
	initLayout(); 

	ui.mPButtonGroupCloseW->hide();

	QFile file(":/qssWidget/Resources/qssWidget/groupchatwidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();

	ui.mPButtonGroupFont->hide();
	ui.mPButtonGroupShake->hide();
	ui.mPButtonGroupVoiceChat->hide();
}

GroupChatWidget::~GroupChatWidget()
{
	if (mExpressWidget)
		delete mExpressWidget;

	if (thread)
		delete thread;

	if (searchWidget)
		delete searchWidget;

	if (sendTip)
		delete sendTip;

	if (cut_line)
		delete cut_line;

	if (movie)
		delete movie;
}

void GroupChatWidget::slotZoomImg(QString strFileName)
{
	QString fileName = strFileName.mid(strFileName.indexOf("file:///") + 8);

	ZoomImg* zoom = new ZoomImg();
	zoom->OpenImg(fileName);
}

void GroupChatWidget::slotVideoPlay(QString mediaPath)
{
	QString path = mediaPath;
	IMVideoPlayer *video = new IMVideoPlayer();
	video->videoPlay(path);
	video->setAttribute(Qt::WA_DeleteOnClose);
}

void GroupChatWidget::slotOpenDocument(QString msgID)
{
	UserInfo userInfo = gDataManager->getUserInfo();
	QString fileName = gDataBaseOpera->DBGetFileInfoLocalPath(msgID);
	//��QT��Ŀ¼
	if (fileName == "")
	{
		QString filePath = msgID.left(msgID.lastIndexOf("/"));
		QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));//�򿪴����ĵ�Ŀ¼
	}
	else{
		QString filePath = fileName.left(fileName.lastIndexOf("/"));
		QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));//�򿪴����ĵ�Ŀ¼
	}
}

void GroupChatWidget::resizeEvent(QResizeEvent * event)
{
	if (searchWidget->isVisible())
	{
		searchWidget->clearAndHide();
		ui.searchBtn->setChecked(false);
	}

	QWidget::resizeEvent(event);
}

void GroupChatWidget::RegisterHandle()
{
	if (mExpressWidget == NULL)
	{
		mExpressWidget = new ExpressWidget(this);
		rectExpressWidget = QRect(mExpressWidget->pos() + this->pos(), mExpressWidget->size());
	}

	//�رհ�ť
	connect(ui.mPButtonGroupCloseW, SIGNAL(clicked()), this, SLOT(slotOnBtnCloseWClicked()));
	//��ͼ
	connect(ui.mPButtonGroupCutPicture, SIGNAL(clicked()), this, SLOT(slotClickedCutPic()));
	//����
	connect(ui.mPButtonGroupExpress, SIGNAL(clicked()), this, SLOT(slotClickedExpress()));
	//����
	connect(ui.mPButtonGroupFont, SIGNAL(clicked()), this, SLOT(slotClickedFont()));
	//ͼƬ
	connect(ui.mPButtonGroupPicture, SIGNAL(clicked()), this, SLOT(slotClickedPicture()));
	//����
	connect(ui.mPButtonGroupSend, SIGNAL(clicked()), this, SLOT(slotClickedSend()));
	//����
	connect(ui.mPButtonGroupShake, SIGNAL(clicked()), this, SLOT(slotClickedShake()));
	//����
	connect(ui.mPButtonGroupVoiceChat, SIGNAL(clicked()), this, SLOT(slotClickedVoiceChat()));

	connect(mExpressWidget, SIGNAL(sigExpressImagePath(QString)), this, SLOT(slotExpressNormalImagePath(QString)));

	//��Ϣ��¼��
	connect(ui.mPButtonGroupLog, SIGNAL(clicked()), this, SIGNAL(sigOpenMessageLog()));

	//Ⱥ��Ա�����̡߳�
	thread = new ThreadLoadGroupUserList;
	connect(thread, SIGNAL(sigLoadGroupUserList(BuddyInfo)), this, SLOT(slotThreadLoadGroupUserInfo(BuddyInfo)));

	ui.mGroupWebView->installEventFilter(this);
	ui.mTextEditGroup->installEventFilter(this);
	ui.mGroupUserlistWidget->installEventFilter(this);
	ui.mTextEditGroup->setFocus();

	searchWidget = new GroupSearchWidget(this);
	searchWidget->hide();
	connect(ui.searchBtn, SIGNAL(toggled(bool)), this, SLOT(slotShowOrHideSearch(bool)));
	connect(searchWidget, SIGNAL(sigOpenSearchUser(QString)), this, SLOT(slotOpenSearchUser(QString)));

	sendTip = new QLabel(this);
	QPixmap tipImage(":/PerChat/Resources/person/sendtip.png");
	sendTip->resize(tipImage.size());
	sendTip->setPixmap(tipImage);
	sendTip->hide();
}

void GroupChatWidget::slotOpenGroupFile(QString msgID)
{
	UserInfo userInfo = gDataManager->getUserInfo();
	QString fileName = gDataBaseOpera->DBGetFileInfoLocalPath( msgID);
	//��QT��Ŀ¼
	if (fileName == "")
	{
		qDebug() << "fileNameΪ��!OpenFile Failed!" << endl;
	}
	else{

		QDesktopServices bs;
		bs.openUrl(QUrl::fromLocalFile(fileName));
	}
}

void GroupChatWidget::OnInsertGroupUserList(QString strGroupID)
{
	mCurrentID = strGroupID;
	searchWidget->setGroupID(mCurrentID);

	thread->requestInterruption();
	Sleep(200);
	slotStartGroupUserThread();
}

void GroupChatWidget::OnInsertGroupUser(BuddyInfo info)
{
	slotThreadLoadGroupUserInfo(info);
}

void GroupChatWidget::slotStartGroupUserThread()    //����groupuser���̵߳ķ�����
{
	ui.mGroupUserlistWidget->clear();
	QList<BuddyInfo> groupInfo = gDataBaseOpera->DBGetGroupBuddyInfoFromID(mCurrentID);//�����ݿ��м���Ⱥ���Ա��Ϣ
	updateGroupMemberCount(groupInfo.size());     // ����Ⱥ��Ա������Label��
	thread->SetListBuddyInfo(groupInfo);
	thread->start();
}

void GroupChatWidget::slotGroupUserInfoLoad(int value)
{
	if (value == ui.mGroupUserlistWidget->verticalScrollBar()->maximum())
		thread->start();
}

void GroupChatWidget::slotThreadLoadGroupUserInfo(BuddyInfo buddyInfo)
{
	QString strUserID = QString("%1").arg(buddyInfo.nUserId);

	if (buddyInfo.strNote.isEmpty())
	{
		OnInsertGroupUserItem(strUserID, buddyInfo.strLocalAvatar,
			buddyInfo.strNickName, buddyInfo.nUserType);
	}
	else
	{
		OnInsertGroupUserItem(strUserID, buddyInfo.strLocalAvatar,
			buddyInfo.strNote, buddyInfo.nUserType);
	}

	QFileInfo info(buddyInfo.strLocalAvatar);
	if (info.size() == 0)  //�ļ������ڣ������ļ�����Ϊ�ա�
	{
		IMDownLoadHeaderImg *down = new IMDownLoadHeaderImg;
		connect(down, SIGNAL(sigUpdateBuddyHeaderImage(int, QPixmap)), this, SLOT(slotUpdateGroupBuddyImage(int, QPixmap)));
		down->StartDownLoadBuddyeHeaderImage(buddyInfo);
	}
}

void GroupChatWidget::slotReLoadGroupUserList()
{
	IMRequestBuddyInfo *request = new IMRequestBuddyInfo();
	UserInfo userInfo = gDataManager->getUserInfo();
	QString url = gDataManager->getAppConfigInfo().MessageServerAddress;
	connect(request, SIGNAL(sigParseGroupBuddyInfo(QString, QList<BuddyInfo>)), this, SLOT(slotParseGroupBuddyInfo(QString, QList<BuddyInfo>)));
	request->RequestGroupBuddyInfo(url, QString::number(userInfo.nUserID), userInfo.strUserPWD, mCurrentID);
}

void  GroupChatWidget::slotSendFile(QString fileName)
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

	MessageInfo messageInfo = gSocketMessage->SendFileMessage(nUserID, mCurrentID.toInt(), 1, "");
	gDataBaseOpera->DBOnInsertFileInfo(QString(messageInfo.msgID), fileName, "");//�������ļ���Ϣ�������ݿ�

	FileTypeEx* fileType = new FileTypeEx(this);
	QString strPath = fileType->GetFilePic(fileName);

	QString strLiID = QString(messageInfo.msgID) + QString("send");
	QString strsize = gSocketMessage->ByteConversion(fileType->GetFileSize(fileName));
	delete fileType;
	strsize = QString("(") + strsize + QString(")");
	QString strend = QString("SendGroupFile(\"%1\",\"%2\",\"%3\",%4,\"%5\",\"%6\",\"%7\")").arg(strHeadPath).arg(FileName).arg(QString(messageInfo.msgID)).arg(0).arg(strPath).arg(strLiID).arg(strsize);
	ui.mGroupWebView->ExecuteJavaScript(strend);

	AppConfig conf = gDataManager->getAppConfigInfo();

	FileMessage *fileMessage = new FileMessage;
	fileMessage->nFromUserID = nUserID;
	fileMessage->nToUserID = mCurrentID.toInt();
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

void GroupChatWidget::slotGroupFile()
{
	QString strFileName = QFileDialog::getOpenFileName(this, tr("����"), ".", tr("All(*.*)"));

	if (!strFileName.isEmpty())
	   slotSendFile(strFileName);
}

void GroupChatWidget::slotCancleLoadorDownLoad()
{
	emit sigCancle();
}

void GroupChatWidget::doUpLoadFileProgress(qint64 sendnum, qint64 total)
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
			ui.mGroupWebView->ExecuteJavaScript(strend);
		}
		else{
			QString processID = msgInfo.msgID + QString("bar");
			QString strend = QString("ProgressBar(\"%1\",%2)").arg(processID).arg(0);;
			ui.mGroupWebView->ExecuteJavaScript(strend);
		}
	}
}

void GroupChatWidget::slotUpFileReplyFinished(bool bResult, QByteArray result)
{
	HttpNetWork::HttpUpLoadFile *requestHttp = qobject_cast<HttpNetWork::HttpUpLoadFile*>(sender());
	if (bResult && requestHttp)
	{
		FileMessage *fileMessage = (FileMessage *)requestHttp->userData(Qt::UserRole);
		QVariant var = requestHttp->getData();
		MessageInfo msgInfo = var.value<MessageInfo>();

		QString newLiID = QString(msgInfo.msgID) + QString("send");
		QString changeLi = QString("ChangeLi(\"%1\")").arg(newLiID);
		ui.mGroupWebView->ExecuteJavaScript(changeLi);

		QString cancleID = msgInfo.msgID + QString("can");
		QString cancle = QString("ChangeLi(\"%1\")").arg(cancleID);
		ui.mGroupWebView->ExecuteJavaScript(cancle);

		gSocketMessage->setUpFileReplyFinished(result, fileMessage, msgInfo);
	}
}

//�ر�
void GroupChatWidget::slotClickedClose()
{
	emit sigClose();
}

//��ͼ
void GroupChatWidget::slotClickedCutPic()
{
	OnCloseExpress();
	emit sigShowWindowMinsize();
	TCHAR szAppPath[MAX_PATH] = { 0 };
	_stprintf(szAppPath, L"0x%x", this->winId());
	ShellExecute(HWND(this->winId()), L"open", L"ScreenShotTool.exe", szAppPath, NULL, SW_SHOW);
}

bool GroupChatWidget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	PMSG msg = (PMSG)message;
	if (msg->message == WM_MESSAGE_SCREENSHOT)
	{
		QString strTemp = QString::number(msg->lParam);
		OnSendScreenShotPic(strTemp);
	}
	return QWidget::nativeEvent(eventType, message, result);
}

//����
void GroupChatWidget::slotClickedExpress()
{
	if (mExpressWidget != NULL)
	{
		if (!mbExpress_widget_is_showing)
		{
			mExpressWidget->showNormalEmotion(QPoint());   // ������ ExpressWidget ������ move, ��ΪGroupChatWidget�Ǹ�����, �Ӵ����ڲ��޷����ݸ����ڵ�λ���ƶ� wxd note
			mExpressWidget->move(QPoint(0, ui.mLabelBKTool->y() - mExpressWidget->height()));
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
//����
void GroupChatWidget::slotClickedFont()
{
	OnCloseExpress();
	ui.mTextEditGroup->append("\n");
}
//ͼƬ
void GroupChatWidget::slotClickedPicture()
{
	OnCloseExpress();
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("��"), ".",
		tr("ͼ���ļ�(*.bmp;*.jpeg;*.jpg;*.png;*.gif)"));
	if (!fileName.isEmpty())
	{
		SendPicture(fileName);
	}
	OnCloseExpress();
}

void GroupChatWidget::SendPicture(QString fileName)
{
	QString strFileName = QString("<img src='") + QString("file:///") + fileName + QString("'/>");
	QImage img(fileName);
	UserInfo userInfo = gDataManager->getUserInfo();
	int nUserID = userInfo.nUserID;
	AppConfig configInfo = gDataManager->getAppConfigInfo();
	MessageInfo messageInfo = gSocketMessage->SendPicMessage(nUserID, mCurrentID.toInt(), 1, "");

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


	QString strSend = QString("SendGroupAppend(\"%1\",\"%2\",\"%3\",%4);").arg(strPath).arg(strFileName).arg(QString(messageInfo.msgID)).arg(0);
	ui.mGroupWebView->ExecuteJavaScript(strSend);

	PicMessage *picMessage = new PicMessage;
	picMessage->nFromUserID = nUserID;
	picMessage->nToUserID = mCurrentID.toInt();
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

/*����ͼƬ �ϴ���ͼƬ ���*/
void GroupChatWidget::slotUpPicReplyFinished(bool result, QByteArray strResult)
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

//����
void GroupChatWidget::slotClickedSend()
{
	OnCloseExpress();
	if (gSocketMessage)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		int nUserID = userInfo.nUserID;
		QString strHtmlText("");
		{
			QString str_html = ui.mTextEditGroup->toHtml();   // wxd add
			QString tag_p = str_html.mid(str_html.indexOf("<p"));
			QString msg_text = tag_p.mid(tag_p.indexOf(">") + 1);
			strHtmlText = msg_text.left(msg_text.indexOf("</p>"));
			strHtmlText.replace("\"", "'");
			strHtmlText.replace("img", "img class='expression' ");  //��������������������������ͼƬ�����֡�
		}

		QString strText = formatSendMessageFromImgPathToImgDescription(strHtmlText);

		// ��Ϊ�ǻ�ȡ�� QTextEdit ��html����   ���� < > "�ᱻת��
		strText = strText.replace("&lt;", "<");
		strText = strText.replace("&gt;", ">");
		strText = strText.replace("&quot;", "\"");
		if (strText == "<br />")
		{
			if (sendTip->isHidden())
			{
				QTimer *timer = new QTimer(this);
				connect(timer, SIGNAL(timeout()), sendTip, SLOT(hide()));
				int x = ui.mTextEditGroup->pos().x() + ui.mTextEditGroup->width() - sendTip->width() - 10;
				int y = ui.mTextEditGroup->pos().y() + ui.mTextEditGroup->height() - sendTip->height() - 60;
				sendTip->move(x, y);
				sendTip->show();
				timer->setSingleShot(true);
				timer->start(3000);
			}
			return;
		}
		strText.replace("<br />", "\n");
		MessageInfo msgInfo = gSocketMessage->SendTextMessage(nUserID, mCurrentID.toInt(), 1, (short)0, strText);
		OnInertSendMessageTextInfo(strHtmlText, userInfo.strUserAvatarLocal, msgInfo);

		GroupInfo group = gDataBaseOpera->DBGetGroupFromID(mCurrentID);
		MessageListInfo messageListInfo;
		messageListInfo.nBudyyID = group.groupId.toInt();
		messageListInfo.strLastMessage = msgInfo.strMsg;
		messageListInfo.nLastTime = msgInfo.ClientTime;
		messageListInfo.strBuddyName = group.groupName;
		messageListInfo.strBuddyHeaderImage = group.groupLoacalHeadImage;
		messageListInfo.messageType = msgInfo.MessageChildType;
		messageListInfo.nUnReadNum = 0;
		messageListInfo.isGroup = 1;
		gDataBaseOpera->DBInsertGroupMessageListInfo(messageListInfo);

		ui.mTextEditGroup->clear();
	}
}
//����
void GroupChatWidget::slotClickedShake()
{
	OnCloseExpress();
}
//����
void GroupChatWidget::slotClickedVoiceChat()
{
	OnCloseExpress();
}

void GroupChatWidget::slotExpressNormalImagePath(QString strPath)
{
	QString qrc_path("<img src='./html");
	qrc_path = qrc_path + strPath + "'/>";
	QTextCursor cursor = ui.mTextEditGroup->textCursor();
	cursor.insertHtml(qrc_path);
	OnCloseExpress();
}

void GroupChatWidget::OnCloseExpress()
{
	if (mExpressWidget != NULL)
		mExpressWidget->hide();
	mbExpress_widget_is_showing = false;   // ���±��鴰��״̬Ϊ ����  wxd add
}

void GroupChatWidget::ExpressHide(QRect rect, QPoint pos)
{
	if (rect.contains(pos))
	{
		OnCloseExpress();
	}
}

void GroupChatWidget::mousePressEvent(QMouseEvent *event)
{
	QRect rect;
	rect = QRect(ui.mLabelBKTool->pos() + this->pos(), ui.mLabelBKTool->size());
	ExpressHide(rect, event->pos());
	rect = QRect(ui.mLabelGroupNum->pos() + this->pos(), ui.mLabelBKTool->size());
	ExpressHide(rect, event->pos());
	rect = QRect(ui.mLabelSend->pos() + this->pos(), ui.mLabelSend->size());
	ExpressHide(rect, event->pos());
	if (!rectExpressWidget.contains(event->pos()))
	{
		if (mExpressWidget != NULL)
			mExpressWidget->hide();
		mbExpress_widget_is_showing = false; 
	}
	return QWidget::mousePressEvent(event);
}

bool GroupChatWidget::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == ui.mGroupWebView)
	{
		if (e->type() == QEvent::FocusIn)
		{
			OnCloseExpress();
		}
	}
	if (obj == ui.mTextEditGroup)
	{
		if (e->type() == QEvent::FocusIn)
		{
			OnCloseExpress();
		}
		if (e->type() == QEvent::KeyPress)
		{
			QKeyEvent *event = static_cast<QKeyEvent*>(e);
			if (event->key() == Qt::Key_Return  && !(event->modifiers() == Qt::ShiftModifier))//&& (event->modifiers() & Qt::ControlModifier))
			{
				slotClickedSend();
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
				QString text = ui.mTextEditGroup->toPlainText();
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
	if (obj == ui.mGroupUserlistWidget)
	{
		if (e->type() == QEvent::FocusIn)
		{
			OnCloseExpress();
		}
	}
	if (obj == ui.refreshBtn)
	{
		if (e->type() == QEvent::MouseButtonPress)
		{
			ui.refreshBtn->setMovie(movie);
			movie->start();

			slotReLoadGroupUserList();
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
			int h = ui.mTextEditGroup->height() + diff;
			if (h > 200)
				h = 200;
			if (h < 50)
				h = 50;
			ui.mTextEditGroup->setFixedHeight(h);
		}
	}

	return QWidget::eventFilter(obj, e);
}

//������Ϣ��ӵ�webview
void GroupChatWidget::OnInertSendMessageTextInfo(QString strMsg, QString strHeadImage,MessageInfo msgInfo)
{
	QString strPath;
	/*��Ҫ�ж��ļ��Ƿ�����*/
	QFile buddyHeadImageFile(strHeadImage);
	if (buddyHeadImageFile.exists())
	{
		if (buddyHeadImageFile.size() == 0)
		{
			strPath = "file:///./html/temp.png";
		}
		else
		{
			strPath = QString("file:///") + strHeadImage;
		}
	}
	else
		strPath = "file:///./html/temp.png";

	strMsg = strMsg.replace("\n", "<br>");
	int msgState = msgInfo.MessageState;
	if (msgState > MESSAGE_STATE_SEND)
	{
		msgState = MESSAGE_STATE_SEND;
	}
	if (msgInfo.MessageChildType == 0)
	{
		QString strMessage = formatMessageFromImgDescriptionToImgPath(strMsg);
		strMessage = strMessage.replace("\n", "<br>");
		strMessage = strMessage.replace("./html", ".");

		QString strSend = QString("SendGroupAppend(\"%1\",\"%2\",\"%3\",%4);").arg(strPath).arg(strMessage).arg(QString(msgInfo.msgID)).arg(msgState);
		ui.mGroupWebView->ExecuteJavaScript(strSend);
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
		QString strSend = QString("SendGroupAppend(\"%1\",\"%2\",\"%3\",%4);").arg(strPath).arg(strFileName).arg(QString(msgInfo.msgID)).arg(msgInfo.MessageState);
		ui.mGroupWebView->ExecuteJavaScript(strSend);
	}
	if (msgInfo.MessageChildType == 5)
	{
		InsertSendFileMessage(msgInfo);
	}
}

void GroupChatWidget::InsertSendFileMessage(MessageInfo msgInfo)
{
	UserInfo userinfo = gDataManager->getUserInfo();
	QString strHeadPath;

	QFile buddyHeadImageFile(userinfo.strUserAvatarLocal);
	if (buddyHeadImageFile.exists() && buddyHeadImageFile.size() != 0)
	{
		strHeadPath = QString("file:///") + userinfo.strUserAvatarLocal;
	}
	else
	{
		strHeadPath = "file:///./html/temp.png";
	}

	//����messageinfo���������ļ�����·��
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
	QString strPath = fileType->GetFilePic(strFileName);

	QString newUlID = QString(msgInfo.msgID) + QString("send");
	QString strSize = QString("(") + gSocketMessage->ByteConversion(fileType->GetFileSize(strFileLocalPath)) + QString(")");
	delete fileType;
	QString strend = QString("SendGroupFile(\"%1\",\"%2\",\"%3\",%4,\"%5\",\"%6\",\"%7\")").arg(strHeadPath).arg(strFileName).arg(QString(msgInfo.msgID)).arg(msgInfo.MessageState).arg(strPath).arg(newUlID).arg(strSize);
	ui.mGroupWebView->ExecuteJavaScript(strend);

	if (msgInfo.MessageState == 3 || msgInfo.MessageState == 4 || msgInfo.MessageState == 5 || msgInfo.MessageState == 6 || msgInfo.MessageState == 7)
	{
		//���ڷ���--->�ѳɹ�����
		QString newLiID = QString(msgInfo.msgID) + QString("send");
		QString changeLi = QString("ChangeLi(\"%1\")").arg(newLiID);
		ui.mGroupWebView->ExecuteJavaScript(changeLi);

		//ȡ����ǩ��ʧ
		QString cancleID = QString(msgInfo.msgID) + QString("can");
		QString changeLi2 = QString("ChangeLi(\"%1\")").arg(cancleID);
		ui.mGroupWebView->ExecuteJavaScript(changeLi2);
	}
}
//������Ϣ��ӵ�webview
void GroupChatWidget::OnInsertRecMessageTextInfo(QString strMsg, QString strHeadImage, int score)
{
	QString strPath;
	/*��Ҫ�ж��ļ��Ƿ�����*/
	QFile buddyHeadImageFile(strHeadImage);
	if (buddyHeadImageFile.exists())
	{
		if (buddyHeadImageFile.size() == 0)
		{
			strPath = "file:///./html/temp.png";
		}
		else
		{
			strPath = QString("file:///") + strHeadImage;
		}
	}
	else
		strPath = "file:///./html/temp.png";

	strMsg = strMsg.replace("\n", "<br>");
	QString strSend = QString("RecAppend(\"%1\",\"%2\",%3)").arg(strPath).arg(strMsg).arg(score);
	ui.mGroupWebView->ExecuteJavaScript(strSend);
}

//������Ϣ��ӵ�webview
void GroupChatWidget::OnInsertRecvMessageTextInfo(QString strMsg, QString strHeadImage, QString strNickName,QString strMsgId, int score)
{
	QString strPath;
	/*��Ҫ�ж��ļ��Ƿ�����*/
	QFile buddyHeadImageFile(strHeadImage);
	if (buddyHeadImageFile.exists())
	{
		if (buddyHeadImageFile.size() == 0)
		{
			strPath = "file:///./html/temp.png";
		}
		else
		{
			strPath = QString("file:///") + strHeadImage;
		}
	}
	else
		strPath = "file:///./html/temp.png";
	
	QString strMessage = formatMessageFromImgDescriptionToImgPath(strMsg);
	strMessage = strMessage.replace("\n", "<br>");
	strPath.replace(" ", "%20");
	QString strSend = QString("GroupRecvAppend(\"%1\",\"%2\",\"%3\",\"%4\",%5)").arg(strPath).arg(strMessage).arg(strNickName).arg(strMsgId).arg(score); 
	ui.mGroupWebView->ExecuteJavaScript(strSend);
}

void GroupChatWidget::OnInsertRecVideoInfo(QString strMsg, QString strHeadImage, QString strNickName, QString strMsgId, int score)
{
	QString strPath;
	/*��Ҫ�ж��ļ��Ƿ�����*/
	QFile buddyHeadImageFile(strHeadImage);
	if (buddyHeadImageFile.exists())
	{
		if (buddyHeadImageFile.size() == 0)
		{
			strPath = "file:///./html/temp.png";
		}
		else
		{
			strPath = QString("file:///") + strHeadImage;
		}
	}
	else
		strPath = "file:///./html/temp.png";

	QString strMessage = formatMessageFromImgDescriptionToImgPath(strMsg);
	strMessage = strMessage.replace("\n", "<br>");

	strPath.replace(" ", "%20");
	QString strSend = QString("GroupVdoAppend(\"%1\",\"%2\",\"%3\",\"%4\",%5)").arg(strPath).arg(strMessage).arg(strNickName).arg(strMsgId).arg(score);
	ui.mGroupWebView->ExecuteJavaScript(strSend);
}

void GroupChatWidget::InitMessageInfo(QString strCurrentID, QString strUserID)
{
	mCurrentID = strCurrentID;
	searchWidget->setGroupID(mCurrentID);
	//���
	OnClearMessageInfo();
	//��ȡ����ͷ��
	UserInfo userInfo = gDataManager->getUserInfo();
	QString strUserHeadImage = userInfo.strUserAvatarLocal;

	QMap<QString, QList<MessageInfo> > mapTemp = gSocketMessage->DBGetCurrentDayMessage();
	QMap<QString, QList<MessageInfo> >::iterator itor = mapTemp.begin();
	for (; itor != mapTemp.end(); ++itor)
	{
		if (itor.key() == strUserID)
		{
			for (int i = 0; i < itor.value().size(); i++)
			{
				if (itor.value()[i].nFromUserID == userInfo.nUserID)
				{
					//˵�����Ƿ��ͷ�
					OnInertSendMessageTextInfo(itor.value()[i].strMsg, strUserHeadImage, itor.value()[i]);
				}
				else
				{
					QString strBuddyID = QString("%1").arg(itor.value()[i].nFromUserID);
					QString strBuddyHeadImage = GetBuddyHeaderImage(itor.key(), strBuddyID);
			
					QList<BuddyInfo> buddyInfo = gDataBaseOpera->DBGetGroupBuddyInfoFromID(QString::number(itor.value()[i].nToUserID));
					QString strBuddyNickName;
					for (int j = 0; j < buddyInfo.count(); j++)
					{
						if (buddyInfo.at(j).nUserId == strBuddyID.toInt())
						{
							strBuddyNickName = buddyInfo.at(j).strNickName;
						}
					}

					if (strBuddyNickName.isEmpty())
						strBuddyNickName = strBuddyID;
					
					if (itor.value()[i].MessageChildType == 0)
					{
						OnInsertRecvMessageTextInfo(itor.value()[i].strMsg, strBuddyHeadImage, strBuddyNickName, QString(itor.value()[i].msgID), itor.value()[i].integral);
					}
					else if (itor.value()[i].MessageChildType == 1)
					{
						QString strPath = QString("<img src='") + QString("file:///")+ itor.value()[i].strMsg + QString("'/>");
						OnInsertRecvMessageTextInfo(strPath, strBuddyHeadImage, strBuddyNickName, QString(itor.value()[i].msgID), itor.value()[i].integral);
					}
					else if (itor.value()[i].MessageChildType == 3)
					{
						QString strPath = QString("<video width='320px' height='180px' style='object-fit: fill;' src='") + QString("file:///") + itor.value()[i].strMsg + QString("'/>");
						OnInsertRecVideoInfo(strPath, strBuddyHeadImage, strBuddyNickName, QString(itor.value()[i].msgID), itor.value()[i].integral);
					}
					else if (itor.value()[i].MessageChildType == 5)
					{
						OnInsertRecvFileMessage(itor.value()[i], strBuddyNickName);
					}
					else{
						OnInsertRecvMessageTextInfo(itor.value()[i].strMsg, strBuddyHeadImage, strBuddyNickName, QString(itor.value()[i].msgID), itor.value()[i].integral);
					}				
				}
			}
			break;
		}
	}
}
void GroupChatWidget::OnInsertRecvFileMessage(MessageInfo msgInfo,QString strBuddyNickName)
{
	QString strFromID = QString("%1").arg(msgInfo.nToUserID);
	QString strBuddyID = QString("%1").arg(msgInfo.nFromUserID);
	QString strBuddyHeadImage = GetBuddyHeaderImage(strFromID, strBuddyID);
	//QString strNickName = msgInfo.
	//����messageinfo���������ļ�����·��
	QJsonParseError jsonError;
	QString strFileName;
	QString FileName;
	QString strFileLocalPath;
	QString fileSize;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(msgInfo.strMsg.toUtf8(), &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QVariantMap result = jsonDocument.toVariant().toMap();
			strFileName = result["FileName"].toString();
			strFileLocalPath = result["FileLocalPath"].toString();
			fileSize = result["FileSize"].toString();
		}

		//FileName = strFileName.mid(strFileName.lastIndexOf("/") + 1);

		FileTypeEx* fileType = new FileTypeEx(this);
		QString strPath = fileType->GetFilePic(strFileName);
		delete fileType;

		QString OtherHeadImg;
		//��Ҫ�ж��ļ��Ƿ�����
		QFile buddyHeadImageFile(strBuddyHeadImage);
		if (buddyHeadImageFile.exists())
		{
			if (buddyHeadImageFile.size() == 0)
			{
				OtherHeadImg = "file:///./html/temp.png";
			}
			else
			{
				OtherHeadImg = QString("file:///") + strBuddyHeadImage;
			}
		}
		else
			OtherHeadImg = "file:///./html/temp.png";

		QString strUlID = QString(msgInfo.msgID) + QString("recv");
		QString strUlID2 = QString(msgInfo.msgID) + QString("recv2");
		QString strSize = QString("(") + fileSize + QString(")");
		QString strRecFile = QString("RecGroupFile(\"%1\",\"%2\",\"%3\",\"%4\",\"%5\",\"%6\",\"%7\",\"%8\",%9)").arg(OtherHeadImg).arg(strBuddyNickName).arg(strFileName).arg(strPath).arg(QString(msgInfo.msgID)).arg(strUlID).arg(strUlID2).arg(strSize).arg(msgInfo.integral);
		ui.mGroupWebView->ExecuteJavaScript(strRecFile);

		UserInfo userInfo = gDataManager->getUserInfo();
		QString strFilePath = gDataBaseOpera->DBGetFileInfoLocalPath(QString(msgInfo.msgID));
		if (strFilePath != "")
		{
			QString strUlId = QString(msgInfo.msgID) + QString("recv");
			QString changeLi = QString("ChangeLiTwo(\"%1\")").arg(strUlId);
			ui.mGroupWebView->ExecuteJavaScript(changeLi);

			QString strUlId2 = QString(msgInfo.msgID) + QString("recv2");
			QString changeLi2 = QString("ChangeLiTwo(\"%1\")").arg(strUlId2);
			ui.mGroupWebView->ExecuteJavaScript(changeLi2);

			QString strUlId3 = QString(msgInfo.msgID) + QString("recv2");
			QString changeLi3 = QString("ChangeLiTwo(\"%1\")").arg(strUlId3);
			ui.mGroupWebView->ExecuteJavaScript(changeLi3);
		}
	}
}

QString GroupChatWidget::GetBuddyHeaderImage(QString strGroupID, QString strBuddyID)
{
	BuddyInfo buddyInfo = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(strGroupID, strBuddyID);
	if (buddyInfo.nUserId == strBuddyID.toInt())
	{
		return buddyInfo.strLocalAvatar;
	}

	return "";
}

void GroupChatWidget::OnRevMessage(MessageInfo messageInfo)
{
	QString strFromID = QString("%1").arg(messageInfo.nToUserID);
	QString strBuddyID = QString("%1").arg(messageInfo.nFromUserID);
	QString strBuddyHeadImage = GetBuddyHeaderImage(strFromID, strBuddyID);
	
	QList<BuddyInfo> buddyInfo = gDataBaseOpera->DBGetGroupBuddyInfoFromID(strFromID);
	QString strBuddyNickName;
	for (int j = 0; j < buddyInfo.count(); j++)
	{
		if (buddyInfo.at(j).nUserId == strBuddyID.toInt())
		{
			strBuddyNickName = buddyInfo.at(j).strNickName;
		}
	}

	if (strBuddyNickName.isEmpty())
		strBuddyNickName = strBuddyID;

	switch (messageInfo.MessageChildType)
	{
	case 0: // ������Ϣ
		OnInsertRecvMessageTextInfo(messageInfo.strMsg, strBuddyHeadImage, strBuddyNickName, QString(messageInfo.msgID), messageInfo.integral);
		break;
	case 1: // ͼƬ��Ϣ
	{
		  if (messageInfo.strMsg == "load")
		  {
			   QString strTemp = "file:///./html/load.gif";
			   QString strPhotoImgTag = QString("<img width=30px height=30px src='") + strTemp + QString("'/>");
			   OnInsertRecvMessageTextInfo(strPhotoImgTag, strBuddyHeadImage, strBuddyNickName, QString(messageInfo.msgID), messageInfo.integral);
		  }
		  else if(messageInfo.strMsg != "fail"){
			  messageInfo.strMsg.replace(" ", "%20");
			   QString strPhotoImgTag = QString("<img src='") + QString("file:///") + messageInfo.strMsg + QString("'/>");
			   OnInsertRecvMessageTextInfo(strPhotoImgTag, strBuddyHeadImage, strBuddyNickName, QString(messageInfo.msgID), messageInfo.integral);
		  }
	}
		break;
	case 3: // ��Ƶ��Ϣ
	{
			if (messageInfo.strMsg == "load")
			{
				QString strTemp = "file:///./html/load.gif";
				QString strPhotoImgTag = QString("<img width=30px height=30px src='") + strTemp + QString("'/>");
				OnInsertRecvMessageTextInfo(strPhotoImgTag, strBuddyHeadImage, strBuddyNickName, QString(messageInfo.msgID), messageInfo.integral);
			}
			else if (messageInfo.strMsg != "fail"){
				messageInfo.strMsg.replace(" ", "%20");
				QString strPhotoImgTag = QString("<video width='320px' height='180px' style='object-fit: fill;' src='") + QString("file:///") + messageInfo.strMsg + QString("'/>");
				OnInsertRecVideoInfo(strPhotoImgTag, strBuddyHeadImage, strBuddyNickName, QString(messageInfo.msgID), messageInfo.integral);
			}
	}
		break;
	case 5://�ļ���Ϣ
		OnRecvGroupFile(messageInfo, strBuddyNickName);
		break;
	default:
		break;
	}	
	// wxd add code - end
}

void GroupChatWidget::OnRecvGroupFile(MessageInfo messageInfo, QString strBuddyNickName)
{
	QString strFromID = QString("%1").arg(messageInfo.nToUserID);
	QString strBuddyID = QString("%1").arg(messageInfo.nFromUserID);
	QString strBuddyHeadImage = GetBuddyHeaderImage(strFromID, strBuddyID);

	QJsonParseError jsonError;
	QString strFileName;
	QString FileName;
	QString strFileLocalPath;
	QString fileSize;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(messageInfo.strMsg.toUtf8(), &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QVariantMap result = jsonDocument.toVariant().toMap();
			strFileName = result["FileName"].toString();
			strFileLocalPath = result["FileLocalPath"].toString();
			fileSize = result["FileSize"].toString();
		}
	}

	FileTypeEx* fileType = new FileTypeEx(this);
	QString strPath = fileType->GetFilePic(strFileName);
	delete fileType;
	QString OtherHeadImg;
	/*��Ҫ�ж��ļ��Ƿ�����*/
	QFile buddyHeadImageFile(strBuddyHeadImage);
	if (buddyHeadImageFile.exists())
	{
		if (buddyHeadImageFile.size() == 0)
		{
			OtherHeadImg = "file:///./html/temp.png";
		}
		else
		{
			OtherHeadImg = QString("file:///") + strBuddyHeadImage;
		}
	}
	else
		OtherHeadImg = "file:///./html/temp.png";

	QString strUlID = QString(messageInfo.msgID) + QString("recv");
	QString strUlID2 = QString(messageInfo.msgID) + QString("recv2");
	QString strSize = QString("(") + fileSize + QString(")");
	QString strRecFile = QString("RecGroupFile(\"%1\",\"%2\",\"%3\",\"%4\",\"%5\",\"%6\",\"%7\",\"%8\",%9)").arg(OtherHeadImg).arg(strBuddyNickName).arg(strFileName).arg(strPath).arg(QString(messageInfo.msgID)).arg(strUlID).arg(strUlID2).arg(strSize).arg(messageInfo.integral);
	ui.mGroupWebView->ExecuteJavaScript(strRecFile);
}

//���ڽ����ļ�
void GroupChatWidget::slotGetFile(QString msgID)
{
	MessageInfo messageInfo = gSocketMessage->DBGetMessageInfoWithMsgID(msgID);
	QJsonDocument jsonDocument = QJsonDocument::fromJson(messageInfo.strMsg.toUtf8());
	QVariantMap result = jsonDocument.toVariant().toMap();
	QString fileName = result["FileName"].toString();
	QString fileID = result["FileId"].toString();

	QString strUlID2 = QString(messageInfo.msgID) + QString("recv2");
	QString changeLi = QString("ChangeLiTwo(\"%1\")").arg(strUlID2);
	ui.mGroupWebView->ExecuteJavaScript(changeLi);

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

bool GroupChatWidget::slotSaveFile(QString msgID)
{
	QString dir = QFileDialog::getExistingDirectory(this, QStringLiteral("���ļ���"), "/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (dir == "")
	{
		return false;
	}
	QString strUlID2 = QString(msgID) + QString("recv2");
	QString changeLi = QString("ChangeLiTwo(\"%1\")").arg(strUlID2);
	ui.mGroupWebView->ExecuteJavaScript(changeLi);

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
void  GroupChatWidget::slotDownLoadFileProgress(qint64 recvnum, qint64 total)
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
			ui.mGroupWebView->ExecuteJavaScript(strend);
		}
		else{
			QString barId = msgInfo.msgID + "bar";
			QString strend = QString("ProgressBar(\"%1\",%2)").arg(barId).arg(0);
			ui.mGroupWebView->ExecuteJavaScript(strend);
		}
	}
}

void GroupChatWidget::slotRequestHttpFileResult(bool result)
{
	HttpNetWork::HttpDownLoadFile *act = qobject_cast<HttpNetWork::HttpDownLoadFile*>(sender());
	if (act)
	{
		QVariant var = act->getData();
		MessageInfo msgInfo = var.value<MessageInfo>();
		QString filePath = act->objectName();
		if (result)
		{
			gDataBaseOpera->DBOnInsertFileInfo(QString(msgInfo.msgID), filePath, "");//�����յ����ļ���Ϣ�������ݿ�

			QString strUlID = msgInfo.msgID + QString("recv");
			QString strChange = QString("ChangeLiTwo(\"%1\")").arg(strUlID);
			ui.mGroupWebView->ExecuteJavaScript(strChange);

			QString strUlID2 = msgInfo.msgID + QString("recv2");
			QString strChange2 = QString("ChangeLiTwo(\"%1\")").arg(strUlID2);
			ui.mGroupWebView->ExecuteJavaScript(strChange2);
		}
		else{
			QString strUlID = msgInfo.msgID + QString("recv");
			QString strChange = QString("ChangeLiThr(\"%1\")").arg(strUlID);
			ui.mGroupWebView->ExecuteJavaScript(strChange);

			QString strUlID2 = msgInfo.msgID + QString("recv2");
			QString strChange2 = QString("ChangeLiThr(\"%1\")").arg(strUlID2);
			ui.mGroupWebView->ExecuteJavaScript(strChange2);
		}
	}
}


void GroupChatWidget::OnClearMessageInfo()
{
	ui.mGroupWebView->ExecuteJavaScript("clear()");
}

void GroupChatWidget::showEvent(QShowEvent *event)
{
	ui.mTextEditGroup->setFocus();
}

void GroupChatWidget::OnUpdateGroupBuddyHeaderImg(QString strBuddyID, QString strPath)
{
	for (int i = 0; i < ui.mGroupUserlistWidget->count(); i++)
	{
		QListWidgetItem *item = ui.mGroupUserlistWidget->item(i);
		CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
		if (buddy == NULL)
		{
			qDebug() << "GroupChatWidget::OnUpdateGroupBuddyHeaderImg��ָ��";
			return;
		}
		if (buddy->mNickName->objectName() == strBuddyID)
		{
			buddy->OnSetPicPath(strPath);
			break;
		}
	}
}

void GroupChatWidget::UpdateMessageStateInfo(QByteArray msgID, int nState, int integral)
{
	nState = MESSAGE_STATE_SEND;
	
	QString strSend = QString("SetGroupMsgState(\"%1\",%2,%3)").arg(QString(msgID)).arg(nState).arg(integral);
	ui.mGroupWebView->ExecuteJavaScript(strSend);
}


void GroupChatWidget::slotOnBtnCloseWClicked()
{
	emit sigBtnCloseWClicked(); 
}

// ��ʼ���ؼ��Ĺ̶��߶�
void GroupChatWidget::setChildWidgetFixedSize()
{
	QPushButton* btn_font = ui.mPButtonGroupFont;
	QPushButton* btn_express = ui.mPButtonGroupExpress;
	QPushButton* btn_shake = ui.mPButtonGroupShake;
	QPushButton* btn_voice_chat = ui.mPButtonGroupVoiceChat;
	QPushButton* btn_picture = ui.mPButtonGroupPicture;
	QPushButton* btn_cut_picture = ui.mPButtonGroupCutPicture;
	QPushButton* btn_send = ui.mPButtonGroupSend;
	QPushButton* btn_down_close = ui.mPButtonGroupCloseW;    // ���Ͱ�ť�ԱߵĹر�
	QLabel* back_mid = ui.mLabelBKTool; 
	QLabel* back_bot = ui.mLabelSend; 
	QTextEdit* input_edit = ui.mTextEditGroup; 
	QLabel* member_num = ui.mLabelGroupNum; 

	btn_font->setFixedSize(btn_font->size()); 
	btn_express->setFixedSize(btn_express->size()); 
	btn_shake->setFixedSize(btn_shake->size()); 
	btn_voice_chat->setFixedSize(btn_voice_chat->size()); 
	btn_picture->setFixedSize(btn_picture->size()); 
	btn_cut_picture->setFixedSize(btn_cut_picture->size()); 
	btn_send->setFixedSize(btn_send->size()); 
	btn_down_close->setFixedSize(btn_down_close->size()); 
	input_edit->setFixedHeight(input_edit->height()); 

	back_mid->setFixedHeight(back_mid->height()); 
	back_bot->setFixedHeight(back_bot->height()+10);   // ������ ��ť����10px�Ŀհ�

	ui.mGroupUserlistWidget->setFixedWidth(ui.mGroupUserlistWidget->width()); 
	member_num->setFixedHeight(member_num->height() + 5);
	//member_num->setFixedSize(member_num->width(), );   // +5Ϊ��ʹ��ʾ���ַ�����ֱ����
}

// ��ʼ���ؼ�����
void GroupChatWidget::initLayout()
{
	// �����沿��
	QVBoxLayout* left_bot_part_layout = new QVBoxLayout;
	{
		QPushButton* btn_font = ui.mPButtonGroupFont;
		QPushButton* btn_express = ui.mPButtonGroupExpress;
		QPushButton* btn_shake = ui.mPButtonGroupShake;
		QPushButton* btn_voice_chat = ui.mPButtonGroupVoiceChat;
		QPushButton* btn_picture = ui.mPButtonGroupPicture;
		QPushButton* btn_cut_picture = ui.mPButtonGroupCutPicture;
		QPushButton* btn_send = ui.mPButtonGroupSend;
		QPushButton* btn_down_close = ui.mPButtonGroupCloseW;    // ���Ͱ�ť�ԱߵĹر�
		QPushButton* btn_log = ui.mPButtonGroupLog;

		// ��һ��
		QLabel* first_line_back = ui.mLabelBKTool;
		QHBoxLayout* first_line_layout = new QHBoxLayout;
		QWidget* first_line_right_spacer = new QWidget(this);
		first_line_right_spacer->setFixedHeight(28);

		QHBoxLayout* btns_layout = new QHBoxLayout; 
		btns_layout->addWidget(btn_font);
		btns_layout->addWidget(btn_express);
		btns_layout->addWidget(btn_shake);
		btns_layout->addWidget(btn_voice_chat);
		btns_layout->addWidget(btn_picture);
		btns_layout->addWidget(btn_cut_picture);
		QSpacerItem *leftSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding);
		QSpacerItem *rightSpacer = new QSpacerItem(6, 20, QSizePolicy::Fixed);
		btns_layout->addSpacerItem(leftSpacer);
		btns_layout->addWidget(btn_log);
		btns_layout->addWidget(btn_send);
		btns_layout->addSpacerItem(rightSpacer);
		removeLayoutSpacing(btns_layout);

		first_line_layout->addLayout(btns_layout);
		first_line_layout->addWidget(first_line_right_spacer);
		removeLayoutSpacing(first_line_layout);

		first_line_back->setLayout(first_line_layout);

		// �ڶ��� �����
		QTextEdit* second_line = ui.mTextEditGroup;

		// ������ ���͡��رհ�ť
		QHBoxLayout* third_line_layout = new QHBoxLayout;

		QHBoxLayout* send_close_layout_h = new QHBoxLayout;
		QWidget* between_close_right_spacer = new QWidget(this);
		QWidget* send_right_spacer = new QWidget(this);
		between_close_right_spacer->setFixedSize(80, btn_send->height());
		send_right_spacer->setFixedSize(22, btn_send->height());

		send_close_layout_h->addWidget(btn_down_close);
		send_close_layout_h->addWidget(between_close_right_spacer);
		send_close_layout_h->addWidget(send_right_spacer);
		removeLayoutSpacing(send_close_layout_h);

		QVBoxLayout* send_close_layout = new QVBoxLayout; 
		QWidget* third_line_down_spacer = new QWidget(this); 
		third_line_down_spacer->setFixedSize(btn_send->width()*2+10, 10); 
		send_close_layout->addLayout(send_close_layout_h); 
		send_close_layout->addWidget(third_line_down_spacer); 

		QLabel* third_line_back = ui.mLabelSend;   // ���͹رհ�ť�ı���label
		QWidget* third_line_left_spacer = new QWidget(this);
		third_line_left_spacer->setFixedHeight(btn_down_close->height());

		third_line_layout->addWidget(third_line_left_spacer);
		third_line_layout->addLayout(send_close_layout);
		removeLayoutSpacing(third_line_layout); 

		third_line_back->setLayout(third_line_layout);

		left_bot_part_layout->addWidget(first_line_back);
		left_bot_part_layout->addWidget(second_line);
		left_bot_part_layout->addWidget(third_line_back);
		removeLayoutSpacing(left_bot_part_layout);
	}

	// ��ߵĲ���
	QVBoxLayout* left_layout = new QVBoxLayout;
	{
		cut_line = new QWidget(this);        // ������webView�ķָ���
		cut_line->installEventFilter(this);
		cut_line->setMouseTracking(true);
		cut_line->resize(ui.mLabelBKTool->width(), 1);
		cut_line->setFixedHeight(1);
		cut_line->setStyleSheet("background-color: #073552;");

		left_layout->addWidget(ui.mGroupWebView);
		left_layout->addWidget(cut_line);
		left_layout->addLayout(left_bot_part_layout);
		removeLayoutSpacing(left_layout);
	}

	// �ұߵĲ���
	QVBoxLayout* right_layout = new QVBoxLayout;
	{
		QHBoxLayout *top_layout = new QHBoxLayout;
		top_layout->addWidget(ui.mLabelGroupNum);
		top_layout->addWidget(ui.searchBtn);
		top_layout->addWidget(ui.refreshBtn);
		removeLayoutSpacing(top_layout);
		right_layout->addLayout(top_layout);
		right_layout->addWidget(ui.mGroupUserlistWidget);
		removeLayoutSpacing(right_layout);
	}

	QHBoxLayout* this_layout = new QHBoxLayout; 

	QWidget* cut_line = new QWidget(this);			// Ⱥ��Ա�б���ߵı߿�, ���ܵĲ������ҷָ���
	cut_line->resize(1, this->height());
	cut_line->setFixedWidth(1);
	cut_line->setStyleSheet("background-color: #073552;");

	right_layout->addWidget(cut_line);
	this_layout->addLayout(left_layout); 
	this_layout->addLayout(right_layout); 
	removeLayoutSpacing(this_layout); 
	this->setLayout(this_layout);

	//setStyleSheet(QString::fromUtf8("border:1px solid gray"));    // ���������ڱ߿�  �����۲첼�����
}

// Access: private
// ���� :  ������ layout�еĿؼ�֮��ļ�϶ȥ��
void GroupChatWidget::removeLayoutSpacing(QLayout* layout)
{
	layout->setSpacing(0);
	layout->setMargin(0);
}

// member_count: Ⱥ���Ա����
// ���� : ���������µ� Ⱥ��Ա�б������Label
void GroupChatWidget::updateGroupMemberCount(int member_count)
{
	QString str_member_count = QString(" Ⱥ��Ա %1").arg(member_count); 
	ui.mLabelGroupNum->setText(str_member_count); 
}

// ����������� <img src='xxx'/> ��ʽ���ַ���ת��Ϊ ����������� [xx]  eg: [΢Ц]
QString GroupChatWidget::formatSendMessageFromImgPathToImgDescription(const QString& strSendMessage)
{
	if (strSendMessage.isEmpty())
		return strSendMessage;

	QString str_src(strSendMessage);
	str_src = str_src.replace("/ >", "/>");

	QRegExp re_img("<img[\\.A-Za-z0-9/:?%&=\\-_+#;' ]*/[ ]*>");      // �� strSendMessage �й��� <img */> ��ǩ��������ʽ
	QRegExp re_img_key("src='./html/[\\.A-Za-z0-9/:?%&=\\-_+#;' ]*'");    // �� <img */> ��ǩ�й��� src ��������ʽ

	QString cur_img_tag("");
	QString str_result("");
	while (re_img.indexIn(str_src) != -1)
	{
		cur_img_tag = re_img.cap(0);					// �õ���һ�γ��ֵ��ַ���
		int cur_idx = re_img.indexIn(str_src);
		str_result += str_src.left(cur_idx);
		str_src.remove(0, cur_idx + cur_img_tag.length());    // ɾ���Ѿ����������ַ�

		QString str_img_description("");
		cur_img_tag.replace(" ", "");
		if (re_img_key.indexIn(cur_img_tag) != -1)
		{
			QString str_img_key = re_img_key.cap(0);
			str_img_key = str_img_key.replace(" ", "");
			str_img_key = str_img_key.left(str_img_key.length() - 1);						// ȥ�����ұߵ� ������ '
			str_img_key = str_img_key.mid(QString("src='./html").length());					// �õ������Ӧ�� qrc��Դ·��
			str_img_description = mExpressWidget->GetDescriptionByImagePath(str_img_key);	// ����key�õ���Ӧ�ı���������
			str_result += str_img_description;				// ��������׷�ӵ� str_result��
		}
		else
		{
			str_result += "[����]";
		}
	}
	str_result += str_src;
	return str_result;
}

// �� ����[xx]������ʽ����Ϣ�ַ��� ת��Ϊ �����·����ʽ���ַ���
QString GroupChatWidget::formatMessageFromImgDescriptionToImgPath(const QString& strMessage)
{
	if (strMessage.isEmpty())
		return strMessage;

	QString str_src(strMessage);
	str_src = str_src.replace("/ >", "/>");

	QRegExp re_img_val("\\[[^\\[^\\]]*\\]");      // �� strMessage �й��� [xxx] ��ʽ��������ʽ

	QString str_result("");
	while (re_img_val.indexIn(str_src) != -1)
	{
		QString img_descrip = re_img_val.cap(0);
		int cur_idx = re_img_val.indexIn(str_src);
		str_result += str_src.left(cur_idx);
		str_src.remove(0, cur_idx + img_descrip.length());    // ɾ���Ѿ����������ַ�

		QString img_path = mExpressWidget->GetImagePathByDescription(img_descrip);
		if (!img_path.isEmpty())
			str_result += "<img src='." + img_path + "'/>";  // ��ʽ��Ϊ <img />��ǩ��ʽ
		else
			str_result += img_descrip;   // ���û���ҵ��򱣳�ԭ�ַ�������
	}
	str_result += str_src;
	return str_result;
}

void GroupChatWidget::slotClickedDoubleItem(QListWidgetItem *item)
{
	CFrientStyleWidget *group = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
	if (group == NULL)
	{
		qDebug() << "GroupChatWidget::slotClickedDoubleItem��ָ��";
		return;
	}
	QString strUserID = group->mNickName->objectName();
	UserInfo userInfo = gDataManager->getUserInfo();

	if (strUserID != QString::number(userInfo.nUserID))
		emit sigGroupBuddyPerChat(strUserID);
	/*ԭ�������жϸ�id�Ƿ�Ϊ�û��ĺ��ѣ����Ͳ�ͬ���źš��°�˴������жϣ�����chatdatamanager���д���
	{
		//�ж��Ƿ��Ǻ���
		BuddyInfo buddyInfo = gDataBaseOpera->DBGetBuddyInfoByID(strUserID);
		if (buddyInfo.nUserId == strUserID.toInt())
		{
			emit sigShowPerChat(strUserID);
		}
		else
		{
			
		}
	}
	*/
}

void GroupChatWidget::OnSendScreenShotPic(QString strShotFileName)
{
	QString strCurrentPath = gSocketMessage->GetExeDir();
	QString strTemp = strCurrentPath + QString("/ScreenShot/%1.jpg").arg(strShotFileName);
	
	SendPicture(strTemp);

	emit sigShowNormalWindow();
}

void GroupChatWidget::scrollBottom()
{
	/*
	int max = ui.mGroupWebView->page()->mainFrame()->scrollBarMaximum(Qt::Vertical);
	ui.mGroupWebView->page()->mainFrame()->setScrollBarValue(Qt::Vertical, max);
	*/
}

void GroupChatWidget::userQuitGroup(QString userID)
{
	QString numString = ui.mLabelGroupNum->text();
	QString numText = numString.split(" ").last();
	updateGroupMemberCount(numText.toInt() - 1);

	for (int i = 0; i < ui.mGroupUserlistWidget->count(); i++)
	{
		QListWidgetItem *item = ui.mGroupUserlistWidget->item(i);
		CFrientStyleWidget *group = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
		if (group != NULL)
		{
			if (group->mNickName->objectName() == userID)
			{
				ui.mGroupUserlistWidget->takeItem(i);
				break;
			}	
		}
	}
}

void GroupChatWidget::slotCefDrags(QStringList list)
{
	for each (QString file in list)
	{
		file = file.replace("\\", "/");
		this->slotSendFile(file);
	}
}

void GroupChatWidget::slotContextMenuRequested(const QPoint &pos)
{
	QListWidgetItem* curItem = ui.mGroupUserlistWidget->itemAt(pos);
	if (curItem == NULL)
		return;

	QMenu *popMenu = new QMenu(this);

	//��ȡ������Ϣ��
	UserInfo info = gDataManager->getUserInfo();

	//��ȡ�����Ⱥ��Ա�������Ϣ��
	CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(curItem);
	QString strBuddyID = buddy->mNickName->objectName();

	//�����������Լ���û����صĲ�����
	if (strBuddyID.toInt() == info.nUserID)
		return;

	//������Ⱥ��Ա���ͻ�ȡ������Ϣ��
	BuddyInfo buddyInfo = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(mCurrentID, strBuddyID);

	//����&ȡ������Ա���ܵ��жϡ�
	BuddyInfo user = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(mCurrentID, QString::number(info.nUserID));
	if (user.nUserType == 9)  //9��Ⱥ������Ȩ�����û���ȡ������Ա��
	{
		
		if (buddyInfo.nUserType == 1)  //1�ǹ���Ա��������ӡ�ȡ������Ա����ѡ�
		{
			QAction *cancelMangaer = new QAction(tr("ȡ������Ա"), this);
			connect(cancelMangaer, SIGNAL(triggered()), this, SLOT(slotCancelManager()));
			popMenu->addAction(cancelMangaer);
			//delete cancelMangaer;
		}
		if (buddyInfo.nUserType == 0)  //0����ͨ��Ա��������ӡ����ù���Ա����ѡ�
		{
			QAction *setManager = new QAction(tr("��Ϊ����Ա"), this);
			connect(setManager, SIGNAL(triggered()), this, SLOT(slotSetManager()));
			popMenu->addAction(setManager);
			//delete setManager;
		}
	}
	
	//�Ƿ���ѵ��жϡ�
	if (!gDataBaseOpera->DBJudgeFriendIsHaveByID(strBuddyID))  //���Ǻ��ѡ�
	{
		QAction *addFriend = new QAction(tr("��Ϊ����"), this);
		connect(addFriend, SIGNAL(triggered()), this, SLOT(slotAddFriend()));
		popMenu->addAction(addFriend);
		//delete addFriend;
	}

	if (popMenu->actions().count() > 0)
	    popMenu->exec(QCursor::pos());
	delete popMenu;
}

void GroupChatWidget::slotAddFriend()
{
	/*
	QListWidgetItem *item = ui.mGroupUserlistWidget->currentItem();
	CFrientStyleWidget *group = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
	if (group == NULL)
	{
		qDebug() << "GroupChatWidget::slotAddFriend��ָ��";
		return;
	}

	//��ȡҪ��ӵĺ��ѵ�id��
	QString strUserID = group->mNickName->objectName();
	
	if (gDataManager)
	{
		UserInfo userInfo = gDataManager->GetLoginInfo();
		//�����ж��ǲ���������Լ���
		if (strUserID.toInt() == userInfo.nUserID)
		{
			MyMessageBox::showMyMessageBox(NULL, QStringLiteral("�������"), QStringLiteral("����������Լ�Ϊ����!"), MESSAGE_WARNNING, BUTTON_OK, true);
			return;
		}
		//֮���ж��ǲ��Ǻ��ѡ�
		if (!gDataManager->DB_JudgeBuddyIsHaveByID(strUserID))
		{
			JFRequestHttp *addBuddy = new JFRequestHttp();
			connect(addBuddy, SIGNAL(sigHttpResult(bool, QString)), this, SLOT(slotHttpAddPersonResultInfo(bool, QString)));
			UserInfo userInfo = gDataManager->GetLoginInfo();
			QString strID = QString("%1").arg(userInfo.nUserID);
			addBuddy->Http_AddBuddy(strUserID, strID, userInfo.strUserPWD);
		}
		else
		{
			MyMessageBox::showMyMessageBox(NULL, QStringLiteral("�������"), QStringLiteral("�Ѿ�����ú���!"), MESSAGE_WARNNING, BUTTON_OK, true);
		}
	}
	*/
}

void GroupChatWidget::slotSetManager()
{
	QListWidgetItem *item = ui.mGroupUserlistWidget->currentItem();
	CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
	if (buddy == NULL)
	{
		qDebug() << "GroupChatWidget::slotSetManager��ָ��";
		return;
	}
	//������ʾ��
	buddy->onSetIdentity(1);  //1�ǹ���Ա��

	//��ȡҪ���ù���Ա�ĺ��ѵ�id��
	QString strUserID = buddy->mNickName->objectName();
	UserInfo user = gDataManager->getUserInfo();
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotDebug(bool, QString)));
	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/setGroupMana"
		+ QString("?userId=%1&passWord=%2&groupId=%3&otherUserId=%4").arg(user.nUserID).arg(user.strUserPWD).arg(mCurrentID).arg(strUserID);

	http->getHttpRequest(url);

	//д�����ݿ⡣
	BuddyInfo info = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(mCurrentID, strUserID);
	info.nUserType = 1;  //1�ǹ���Ա��
	gDataBaseOpera->DBInsertGroupBuddyInfo(mCurrentID, info);
}

void GroupChatWidget::slotCancelManager()
{
	QListWidgetItem *item = ui.mGroupUserlistWidget->currentItem();
	CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
	if (buddy == NULL)
	{
		qDebug() << "GroupChatWidget::slotSetManager��ָ��";
		return;
	}
	//������ʾ��
	buddy->onSetIdentity(0);  //0����ͨ��Ա��

	//��ȡҪȡ������Ա�ĺ��ѵ�id��
	QString strUserID = buddy->mNickName->objectName();
	UserInfo user = gDataManager->getUserInfo();
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotDebug(bool, QString)));
	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/cancelGroupMana"
		+ QString("?userId=%1&passWord=%2&groupId=%3&otherUserId=%4").arg(user.nUserID).arg(user.strUserPWD).arg(mCurrentID).arg(strUserID);

	http->getHttpRequest(url);

	//д�����ݿ⡣
	BuddyInfo info = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(mCurrentID, strUserID);
	info.nUserType = 0;  //0����ͨ��Ա��
	gDataBaseOpera->DBInsertGroupBuddyInfo(mCurrentID, info);
}

void GroupChatWidget::slotHttpAddPersonResultInfo(bool bResult, QString strResult)
{
	QJsonParseError jsonError;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(strResult.toUtf8(), &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QJsonObject obj = jsonDocument.object();
			if (obj["result"].toString() == "success")
			{
				QMessageBox::information(this, QStringLiteral("�������"), QStringLiteral("������ѳɹ�!"));
				return;
			}
		}
	}

	QMessageBox::critical(this, QStringLiteral("�������"), QStringLiteral("�������ʧ��!"));
}

void GroupChatWidget::slotShowOrHideSearch(bool checked)
{
	int margin = 5;
	if (checked)
	{
		int x = ui.mGroupUserlistWidget->x() + margin;
		int y = ui.mGroupUserlistWidget->y() + margin;
		int w = ui.mGroupUserlistWidget->width() - 2 * margin;

		searchWidget->move(x, y);
		searchWidget->resize(w, searchWidget->height());
		searchWidget->show();
		searchWidget->getFocus();
		searchWidget->setMaximumHeight(ui.mGroupUserlistWidget->height() - 2 * margin);
	}
	else
		searchWidget->clearAndHide();
}

void GroupChatWidget::slotOpenSearchUser(QString strUserID)
{
	/*
	UserInfo userInfo = gDataManager->GetLoginInfo();
	if (strUserID != QString::number(userInfo.nUserID))
	{
		//�ж��Ƿ��Ǻ���
		if (gDataManager->DB_JudgeBuddyIsHaveByID(strUserID))
			emit sigShowPerChat(strUserID);
		else
			emit sigGroupBuddyPerChat(strUserID);

		searchWidget->clearAndHide();
		ui.searchBtn->setChecked(false);
	}
*/
}

void GroupChatWidget::OnInsertGroupUserItem(QString strUserID, QString strPicPath, QString strNickName, int mana, int nHeight)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->OnInitGroupUserList(strUserID);
	buddy->OnSetPicPath(strPicPath);
	buddy->OnSetNickNameText(strNickName);
	buddy->onSetIdentity(mana);
	QListWidgetItem *newItem = new QListWidgetItem(); //����һ��newItem
	newItem->setSizeHint(QSize(ui.mGroupUserlistWidget->width(), nHeight));

	ui.mGroupUserlistWidget->insertItem(ui.mGroupUserlistWidget->count(), newItem); //����newItem���뵽����
	ui.mGroupUserlistWidget->setItemWidget(newItem, buddy); //��buddy������newItem
}

void GroupChatWidget::slotUpdateGroupBuddyImage(int userID, QPixmap image)
{
	for (int i = 0; i < ui.mGroupUserlistWidget->count(); i++)
	{
		QListWidgetItem *item = ui.mGroupUserlistWidget->item(i);
		CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
		if (buddy == NULL)
		{
			qDebug() << "GroupChatWidget::OnUpdateGroupBuddyHeaderImg��ָ��";
			return;
		}
		if (buddy->mNickName->objectName().toInt() == userID)
		{
			buddy->onSetHeaderImage(image);
			break;
		}
	}
}

void GroupChatWidget::slotParseGroupBuddyInfo(QString string, QList<BuddyInfo> list)
{
	movie->stop();
	ui.refreshBtn->setPixmap(QPixmap(":/GroupChat/Resources/groupchat/refresh.png"));

	for (int i = 0; i < list.size();i++)
	{
		gDataBaseOpera->DBInsertGroupBuddyInfo(string, list[i]);
	}

	thread->requestInterruption();
	Sleep(200);
	slotStartGroupUserThread();
}

void GroupChatWidget::slotSendFileByID(QString msgID)
{
	UserInfo userInfo = gDataManager->getUserInfo();
	QString fileName = gDataBaseOpera->DBGetFileInfoLocalPath(msgID);
	slotSendFile(fileName);
}

void GroupChatWidget::slotDebug(bool success, QString result)
{
	if (success)
		qDebug() << result;
}

