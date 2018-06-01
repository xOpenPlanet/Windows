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

	drag = false;  //是否通过拖拽变更输入框大小，
	copying = false;   //ctrl按下，表示要进行黏贴。

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

	// 设置群成员列表的垂直滚动条的样式
	QFile scroolbar_style_qss(":/ScrollBar/Resources/QSS/scrollbarStyle.qss");
	scroolbar_style_qss.open(QFile::ReadOnly);
	ui.mGroupUserlistWidget->verticalScrollBar()->setStyleSheet(scroolbar_style_qss.readAll());
	ui.mGroupUserlistWidget->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(ui.mGroupUserlistWidget, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(slotContextMenuRequested(const QPoint &)));
	connect(ui.mGroupUserlistWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slotClickedDoubleItem(QListWidgetItem*)));
	connect(ui.mGroupUserlistWidget->verticalScrollBar(), SIGNAL(sliderMoved(int)), this, SLOT(slotGroupUserInfoLoad(int)));

	ui.mLabelGroupNum->setStyleSheet("font: 75 10pt 微软雅黑;font-size:14px;color:#108ee9");
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
	//用QT打开目录
	if (fileName == "")
	{
		QString filePath = msgID.left(msgID.lastIndexOf("/"));
		QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));//打开带中文的目录
	}
	else{
		QString filePath = fileName.left(fileName.lastIndexOf("/"));
		QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));//打开带中文的目录
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

	//关闭按钮
	connect(ui.mPButtonGroupCloseW, SIGNAL(clicked()), this, SLOT(slotOnBtnCloseWClicked()));
	//截图
	connect(ui.mPButtonGroupCutPicture, SIGNAL(clicked()), this, SLOT(slotClickedCutPic()));
	//表情
	connect(ui.mPButtonGroupExpress, SIGNAL(clicked()), this, SLOT(slotClickedExpress()));
	//字体
	connect(ui.mPButtonGroupFont, SIGNAL(clicked()), this, SLOT(slotClickedFont()));
	//图片
	connect(ui.mPButtonGroupPicture, SIGNAL(clicked()), this, SLOT(slotClickedPicture()));
	//发送
	connect(ui.mPButtonGroupSend, SIGNAL(clicked()), this, SLOT(slotClickedSend()));
	//抖动
	connect(ui.mPButtonGroupShake, SIGNAL(clicked()), this, SLOT(slotClickedShake()));
	//语音
	connect(ui.mPButtonGroupVoiceChat, SIGNAL(clicked()), this, SLOT(slotClickedVoiceChat()));

	connect(mExpressWidget, SIGNAL(sigExpressImagePath(QString)), this, SLOT(slotExpressNormalImagePath(QString)));

	//消息记录。
	connect(ui.mPButtonGroupLog, SIGNAL(clicked()), this, SIGNAL(sigOpenMessageLog()));

	//群成员加载线程。
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
	//用QT打开目录
	if (fileName == "")
	{
		qDebug() << "fileName为空!OpenFile Failed!" << endl;
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

void GroupChatWidget::slotStartGroupUserThread()    //加载groupuser到线程的方法。
{
	ui.mGroupUserlistWidget->clear();
	QList<BuddyInfo> groupInfo = gDataBaseOpera->DBGetGroupBuddyInfoFromID(mCurrentID);//从数据库中加载群组成员信息
	updateGroupMemberCount(groupInfo.size());     // 更新群成员计数到Label上
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
	if (info.size() == 0)  //文件不存在，或者文件内容为空。
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
	gDataBaseOpera->DBOnInsertFileInfo(QString(messageInfo.msgID), fileName, "");//将发送文件信息插入数据库

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
	QString strFileName = QFileDialog::getOpenFileName(this, tr("发送"), ".", tr("All(*.*)"));

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

//关闭
void GroupChatWidget::slotClickedClose()
{
	emit sigClose();
}

//截图
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

//表情
void GroupChatWidget::slotClickedExpress()
{
	if (mExpressWidget != NULL)
	{
		if (!mbExpress_widget_is_showing)
		{
			mExpressWidget->showNormalEmotion(QPoint());   // 不能在 ExpressWidget 类里面 move, 因为GroupChatWidget是父窗口, 子窗口内部无法根据父窗口的位置移动 wxd note
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
//字体
void GroupChatWidget::slotClickedFont()
{
	OnCloseExpress();
	ui.mTextEditGroup->append("\n");
}
//图片
void GroupChatWidget::slotClickedPicture()
{
	OnCloseExpress();
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("打开"), ".",
		tr("图像文件(*.bmp;*.jpeg;*.jpg;*.png;*.gif)"));
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

/*发送图片 上传完图片 结果*/
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

//发送
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
//抖动
void GroupChatWidget::slotClickedShake()
{
	OnCloseExpress();
}
//语音
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
	mbExpress_widget_is_showing = false;   // 更新表情窗口状态为 隐藏  wxd add
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

//发送消息添加到webview
void GroupChatWidget::OnInertSendMessageTextInfo(QString strMsg, QString strHeadImage,MessageInfo msgInfo)
{
	QString strPath;
	/*需要判断文件是否完整*/
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

	//解析messageinfo，解析出文件名，路径
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
		//正在发送--->已成功发送
		QString newLiID = QString(msgInfo.msgID) + QString("send");
		QString changeLi = QString("ChangeLi(\"%1\")").arg(newLiID);
		ui.mGroupWebView->ExecuteJavaScript(changeLi);

		//取消标签消失
		QString cancleID = QString(msgInfo.msgID) + QString("can");
		QString changeLi2 = QString("ChangeLi(\"%1\")").arg(cancleID);
		ui.mGroupWebView->ExecuteJavaScript(changeLi2);
	}
}
//接收消息添加到webview
void GroupChatWidget::OnInsertRecMessageTextInfo(QString strMsg, QString strHeadImage, int score)
{
	QString strPath;
	/*需要判断文件是否完整*/
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

//接收消息添加到webview
void GroupChatWidget::OnInsertRecvMessageTextInfo(QString strMsg, QString strHeadImage, QString strNickName,QString strMsgId, int score)
{
	QString strPath;
	/*需要判断文件是否完整*/
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
	/*需要判断文件是否完整*/
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
	//清空
	OnClearMessageInfo();
	//获取好友头像
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
					//说明我是发送方
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
	//解析messageinfo，解析出文件名，路径
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
		//需要判断文件是否完整
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
	case 0: // 文字消息
		OnInsertRecvMessageTextInfo(messageInfo.strMsg, strBuddyHeadImage, strBuddyNickName, QString(messageInfo.msgID), messageInfo.integral);
		break;
	case 1: // 图片消息
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
	case 3: // 视频消息
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
	case 5://文件消息
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
	/*需要判断文件是否完整*/
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

//用于接收文件
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
	QString dir = QFileDialog::getExistingDirectory(this, QStringLiteral("打开文件夹"), "/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
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
			gDataBaseOpera->DBOnInsertFileInfo(QString(msgInfo.msgID), filePath, "");//将接收到的文件信息插入数据库

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
			qDebug() << "GroupChatWidget::OnUpdateGroupBuddyHeaderImg空指针";
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

// 初始化控件的固定高度
void GroupChatWidget::setChildWidgetFixedSize()
{
	QPushButton* btn_font = ui.mPButtonGroupFont;
	QPushButton* btn_express = ui.mPButtonGroupExpress;
	QPushButton* btn_shake = ui.mPButtonGroupShake;
	QPushButton* btn_voice_chat = ui.mPButtonGroupVoiceChat;
	QPushButton* btn_picture = ui.mPButtonGroupPicture;
	QPushButton* btn_cut_picture = ui.mPButtonGroupCutPicture;
	QPushButton* btn_send = ui.mPButtonGroupSend;
	QPushButton* btn_down_close = ui.mPButtonGroupCloseW;    // 发送按钮旁边的关闭
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
	back_bot->setFixedHeight(back_bot->height()+10);   // 包含了 按钮下面10px的空白

	ui.mGroupUserlistWidget->setFixedWidth(ui.mGroupUserlistWidget->width()); 
	member_num->setFixedHeight(member_num->height() + 5);
	//member_num->setFixedSize(member_num->width(), );   // +5为了使显示的字符串竖直居中
}

// 初始化控件布局
void GroupChatWidget::initLayout()
{
	// 左下面部分
	QVBoxLayout* left_bot_part_layout = new QVBoxLayout;
	{
		QPushButton* btn_font = ui.mPButtonGroupFont;
		QPushButton* btn_express = ui.mPButtonGroupExpress;
		QPushButton* btn_shake = ui.mPButtonGroupShake;
		QPushButton* btn_voice_chat = ui.mPButtonGroupVoiceChat;
		QPushButton* btn_picture = ui.mPButtonGroupPicture;
		QPushButton* btn_cut_picture = ui.mPButtonGroupCutPicture;
		QPushButton* btn_send = ui.mPButtonGroupSend;
		QPushButton* btn_down_close = ui.mPButtonGroupCloseW;    // 发送按钮旁边的关闭
		QPushButton* btn_log = ui.mPButtonGroupLog;

		// 第一行
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

		// 第二行 输入框
		QTextEdit* second_line = ui.mTextEditGroup;

		// 第三行 发送、关闭按钮
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

		QLabel* third_line_back = ui.mLabelSend;   // 发送关闭按钮的背景label
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

	// 左边的布局
	QVBoxLayout* left_layout = new QVBoxLayout;
	{
		cut_line = new QWidget(this);        // 输入框和webView的分割线
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

	// 右边的布局
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

	QWidget* cut_line = new QWidget(this);			// 群成员列表左边的边框, 即总的布局左右分割线
	cut_line->resize(1, this->height());
	cut_line->setFixedWidth(1);
	cut_line->setStyleSheet("background-color: #073552;");

	right_layout->addWidget(cut_line);
	this_layout->addLayout(left_layout); 
	this_layout->addLayout(right_layout); 
	removeLayoutSpacing(this_layout); 
	this->setLayout(this_layout);

	//setStyleSheet(QString::fromUtf8("border:1px solid gray"));    // 给整个窗口边框  用来观察布局情况
}

// Access: private
// 功能 :  将布局 layout中的控件之间的间隙去掉
void GroupChatWidget::removeLayoutSpacing(QLayout* layout)
{
	layout->setSpacing(0);
	layout->setMargin(0);
}

// member_count: 群组成员数量
// 功能 : 将数量更新到 群成员列表上面的Label
void GroupChatWidget::updateGroupMemberCount(int member_count)
{
	QString str_member_count = QString(" 群成员 %1").arg(member_count); 
	ui.mLabelGroupNum->setText(str_member_count); 
}

// 将包含表情的 <img src='xxx'/> 形式的字符串转化为 表情的描述字 [xx]  eg: [微笑]
QString GroupChatWidget::formatSendMessageFromImgPathToImgDescription(const QString& strSendMessage)
{
	if (strSendMessage.isEmpty())
		return strSendMessage;

	QString str_src(strSendMessage);
	str_src = str_src.replace("/ >", "/>");

	QRegExp re_img("<img[\\.A-Za-z0-9/:?%&=\\-_+#;' ]*/[ ]*>");      // 从 strSendMessage 中过滤 <img */> 标签的正则表达式
	QRegExp re_img_key("src='./html/[\\.A-Za-z0-9/:?%&=\\-_+#;' ]*'");    // 从 <img */> 标签中过滤 src 的正则表达式

	QString cur_img_tag("");
	QString str_result("");
	while (re_img.indexIn(str_src) != -1)
	{
		cur_img_tag = re_img.cap(0);					// 拿到第一次出现的字符串
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
QString GroupChatWidget::formatMessageFromImgDescriptionToImgPath(const QString& strMessage)
{
	if (strMessage.isEmpty())
		return strMessage;

	QString str_src(strMessage);
	str_src = str_src.replace("/ >", "/>");

	QRegExp re_img_val("\\[[^\\[^\\]]*\\]");      // 从 strMessage 中过滤 [xxx] 形式的正则表达式

	QString str_result("");
	while (re_img_val.indexIn(str_src) != -1)
	{
		QString img_descrip = re_img_val.cap(0);
		int cur_idx = re_img_val.indexIn(str_src);
		str_result += str_src.left(cur_idx);
		str_src.remove(0, cur_idx + img_descrip.length());    // 删除已经遍历过的字符

		QString img_path = mExpressWidget->GetImagePathByDescription(img_descrip);
		if (!img_path.isEmpty())
			str_result += "<img src='." + img_path + "'/>";  // 格式化为 <img />标签形式
		else
			str_result += img_descrip;   // 如果没有找到则保持原字符串不变
	}
	str_result += str_src;
	return str_result;
}

void GroupChatWidget::slotClickedDoubleItem(QListWidgetItem *item)
{
	CFrientStyleWidget *group = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
	if (group == NULL)
	{
		qDebug() << "GroupChatWidget::slotClickedDoubleItem空指针";
		return;
	}
	QString strUserID = group->mNickName->objectName();
	UserInfo userInfo = gDataManager->getUserInfo();

	if (strUserID != QString::number(userInfo.nUserID))
		emit sigGroupBuddyPerChat(strUserID);
	/*原代码是判断该id是否为用户的好友，发送不同的信号。新版此处不再判断，交由chatdatamanager进行处理。
	{
		//判断是否是好友
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

	//获取个人信息。
	UserInfo info = gDataManager->getUserInfo();

	//获取点击的群成员的相关信息。
	CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(curItem);
	QString strBuddyID = buddy->mNickName->objectName();

	//如果点击的是自己，没有相关的操作。
	if (strBuddyID.toInt() == info.nUserID)
		return;

	//是其他群成员，就获取他的信息。
	BuddyInfo buddyInfo = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(mCurrentID, strBuddyID);

	//设置&取消管理员功能的判断。
	BuddyInfo user = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(mCurrentID, QString::number(info.nUserID));
	if (user.nUserType == 9)  //9是群主，有权限设置或者取消管理员。
	{
		
		if (buddyInfo.nUserType == 1)  //1是管理员，因此增加“取消管理员”的选项。
		{
			QAction *cancelMangaer = new QAction(tr("取消管理员"), this);
			connect(cancelMangaer, SIGNAL(triggered()), this, SLOT(slotCancelManager()));
			popMenu->addAction(cancelMangaer);
			//delete cancelMangaer;
		}
		if (buddyInfo.nUserType == 0)  //0是普通成员，因此增加“设置管理员”的选项。
		{
			QAction *setManager = new QAction(tr("设为管理员"), this);
			connect(setManager, SIGNAL(triggered()), this, SLOT(slotSetManager()));
			popMenu->addAction(setManager);
			//delete setManager;
		}
	}
	
	//是否好友的判断。
	if (!gDataBaseOpera->DBJudgeFriendIsHaveByID(strBuddyID))  //不是好友。
	{
		QAction *addFriend = new QAction(tr("加为好友"), this);
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
		qDebug() << "GroupChatWidget::slotAddFriend空指针";
		return;
	}

	//获取要添加的好友的id。
	QString strUserID = group->mNickName->objectName();
	
	if (gDataManager)
	{
		UserInfo userInfo = gDataManager->GetLoginInfo();
		//首先判断是不是在添加自己。
		if (strUserID.toInt() == userInfo.nUserID)
		{
			MyMessageBox::showMyMessageBox(NULL, QStringLiteral("请求好友"), QStringLiteral("您不能添加自己为好友!"), MESSAGE_WARNNING, BUTTON_OK, true);
			return;
		}
		//之后判断是不是好友。
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
			MyMessageBox::showMyMessageBox(NULL, QStringLiteral("请求好友"), QStringLiteral("已经加入该好友!"), MESSAGE_WARNNING, BUTTON_OK, true);
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
		qDebug() << "GroupChatWidget::slotSetManager空指针";
		return;
	}
	//更改显示。
	buddy->onSetIdentity(1);  //1是管理员。

	//获取要设置管理员的好友的id。
	QString strUserID = buddy->mNickName->objectName();
	UserInfo user = gDataManager->getUserInfo();
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotDebug(bool, QString)));
	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/setGroupMana"
		+ QString("?userId=%1&passWord=%2&groupId=%3&otherUserId=%4").arg(user.nUserID).arg(user.strUserPWD).arg(mCurrentID).arg(strUserID);

	http->getHttpRequest(url);

	//写入数据库。
	BuddyInfo info = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(mCurrentID, strUserID);
	info.nUserType = 1;  //1是管理员。
	gDataBaseOpera->DBInsertGroupBuddyInfo(mCurrentID, info);
}

void GroupChatWidget::slotCancelManager()
{
	QListWidgetItem *item = ui.mGroupUserlistWidget->currentItem();
	CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
	if (buddy == NULL)
	{
		qDebug() << "GroupChatWidget::slotSetManager空指针";
		return;
	}
	//更改显示。
	buddy->onSetIdentity(0);  //0是普通成员。

	//获取要取消管理员的好友的id。
	QString strUserID = buddy->mNickName->objectName();
	UserInfo user = gDataManager->getUserInfo();
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotDebug(bool, QString)));
	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/cancelGroupMana"
		+ QString("?userId=%1&passWord=%2&groupId=%3&otherUserId=%4").arg(user.nUserID).arg(user.strUserPWD).arg(mCurrentID).arg(strUserID);

	http->getHttpRequest(url);

	//写入数据库。
	BuddyInfo info = gDataBaseOpera->DBGetGroupBuddyInfoWithGroupBuddyID(mCurrentID, strUserID);
	info.nUserType = 0;  //0是普通成员。
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
				QMessageBox::information(this, QStringLiteral("请求好友"), QStringLiteral("请求好友成功!"));
				return;
			}
		}
	}

	QMessageBox::critical(this, QStringLiteral("请求好友"), QStringLiteral("请求好友失败!"));
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
		//判断是否是好友
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
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	newItem->setSizeHint(QSize(ui.mGroupUserlistWidget->width(), nHeight));

	ui.mGroupUserlistWidget->insertItem(ui.mGroupUserlistWidget->count(), newItem); //将该newItem插入到后面
	ui.mGroupUserlistWidget->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void GroupChatWidget::slotUpdateGroupBuddyImage(int userID, QPixmap image)
{
	for (int i = 0; i < ui.mGroupUserlistWidget->count(); i++)
	{
		QListWidgetItem *item = ui.mGroupUserlistWidget->item(i);
		CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.mGroupUserlistWidget->itemWidget(item);
		if (buddy == NULL)
		{
			qDebug() << "GroupChatWidget::OnUpdateGroupBuddyHeaderImg空指针";
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

