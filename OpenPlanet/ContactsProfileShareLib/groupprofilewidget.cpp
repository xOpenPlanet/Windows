#include "groupprofilewidget.h"

GroupProfileWidget::GroupProfileWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QPixmap mask(":/profile/Resources/profile/profileMask.png");
	this->setMask(mask.mask());

	headerLabel = new QLabelHeader(this);
	headerLabel->setScaledContents(true);
	headerLabel->setFixedSize(70, 70);
	headerLabel->move(15, 15);

	headerLabel->installEventFilter(this);

	groupChatBtn = new QPushButton(this);
	groupChatBtn->setStyleSheet("QPushButton{border-image:url(:/profile/Resources/profile/chatBtn.png)}"
		"QPushButton:hover{border-image:url(:/profile/Resources/profile/chatBtn_hover.png)}");
	groupChatBtn->resize(48, 48);
	groupChatBtn->move(275, 76);
	//groupChatBtn->setCursor(Qt::PointingHandCursor);
	groupChatBtn->setToolTip(QStringLiteral("发消息"));

	connect(groupChatBtn, SIGNAL(clicked(bool)), this, SLOT(slotGroupChat()));

	avatarWidget = new GroupAvatarWidget();
	connect(avatarWidget, SIGNAL(sigUploadImagePath(QString)), this, SLOT(slotUploadHeaderImage(QString)));

	QFile file(":/qssWidget/Resources/qssWidget/groupprofilewidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();

	ui.indexBtn->hide();
	ui.memberBtn->hide();
	ui.settingsBtn->hide();
}

void GroupProfileWidget::setGroup(QString groupID)
{
	this->groupID = groupID;

	GroupInfo group = gDataBaseOpera->DBGetGroupFromID(groupID);

	QPixmap pix(group.groupLoacalHeadImage);
	if (pix.isNull())
	{
		QByteArray bytearray = "";
		QFile file(group.groupLoacalHeadImage);
		if (file.open(QIODevice::ReadOnly) && file.size() != 0)
		{
			bytearray = file.readAll();
		}
		file.close();
		if (!pix.loadFromData(bytearray) || bytearray == "")
		{
			pix.load(":/GroupChat/Resources/groupchat/group.png");
		}
	}

	headerLabel->setPixmap(pix);

	UserInfo userInfo = gDataManager->getUserInfo();
	if (group.createUserId == QString::number(userInfo.nUserID))   //自己是群主。
	{
		headerLabel->setToolTip(QStringLiteral("修改头像"));
		headerLabel->setCursor(Qt::PointingHandCursor);
	}
	else
	{
		headerLabel->setToolTip(QStringLiteral("群组头像"));
		headerLabel->setCursor(Qt::ArrowCursor);
	}
	
	ui.groupLabel->setText(group.groupName);
	ui.numberLabel->setText(group.groupId);
	ui.nameLabel->setText(group.groupName);
	ui.createrLabel->setText(group.createUserId);
	ui.timeLabel->setText(group.createTime);
}

void GroupProfileWidget::slotGroupChat()
{
	emit sigGroupChat(OpenGroup, QVariant::fromValue(groupID));
}

bool GroupProfileWidget::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		if (obj == headerLabel && headerLabel->cursor().shape() == Qt::PointingHandCursor)
		{
			GroupInfo groupInfo = gDataBaseOpera->DBGetGroupFromID(groupID);
			avatarWidget->setGroupInfo(groupInfo);
			avatarWidget->show();
		}
			
	}

	return QWidget::eventFilter(obj, event);
}

void GroupProfileWidget::slotUploadHeaderImage(QString filePath)
{
	headerImage.load(filePath);

	HttpNetWork::HttpUpLoadFile *upload = new HttpNetWork::HttpUpLoadFile;
	connect(upload, SIGNAL(sigUpLoadFinished(bool, QByteArray)), this, SLOT(slotHttpChangeAvatar(bool, QByteArray)));
	QVariantMap pargram;
	pargram.insert("parentId", "66662");
	pargram.insert("createUser", "6662");
	upload->StartUpLoadFile(gDataManager->getAppConfigInfo().PanServerUploadURL, filePath, pargram);
}

void GroupProfileWidget::slotHttpChangeAvatar(bool success, QByteArray byte)
{
	if (success)
	{
		QVariantMap map = QJsonDocument::fromJson(byte).toVariant().toMap();
		QString fileid = map["fileid"].toString();

		GroupInfo groupInfo = gDataBaseOpera->DBGetGroupFromID(groupID);

		//上传成功了，通知服务器登录用户的头像已经改变。
		QString avatarURL = gDataManager->getAppConfigInfo().PanServerDownloadURL + fileid + "/download";
		UserInfo userInfo = gDataManager->getUserInfo();
		QString url = gDataManager->getAppConfigInfo().MessageServerAddress +
			QString("/IMServer/group/updateGroup?userId=%1&passWord=%2&groupId=%3&groupName=%4&avatar=%5")
			.arg(userInfo.nUserID).arg(userInfo.strUserPWD).arg(groupInfo.groupId).arg(groupInfo.groupName).arg(avatarURL);

		HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
		connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotAvatarChanged(bool, QString)));
		http->getHttpRequest(url);
	}
}

void GroupProfileWidget::slotAvatarChanged(bool success, QString byte)
{
	avatarWidget->upPicFileFinished(success);
	if (success)
	{
		headerLabel->setPixmap(headerImage);
	}
}


