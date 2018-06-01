#include "userprofiledatamanager.h"

UserProfileDataManager::UserProfileDataManager(QObject *parent)
	: QObject(parent)
{
	userWidget = new UserProfileWidget;
	avatarWidget = new ChangeAvatarWidget;
	avatarWidget->setUserInfo(gDataManager->getUserInfo());
	infoWidget = new UserInfoWidget;
	infoWidget->setUserInfo(gDataManager->getUserInfo());

	connect(userWidget, SIGNAL(sigOpenAvatarWidget()), avatarWidget, SLOT(show()));
	connect(userWidget, SIGNAL(sigOpenUserInfoWidget()), infoWidget, SLOT(show()));
	connect(avatarWidget, SIGNAL(sigUploadHeaderImage(QString)), this, SLOT(slotUploadHeaderImage(QString)));
	connect(infoWidget, SIGNAL(sigUserInfo(UserInfo)), this, SLOT(slotUserInfo(UserInfo)));
}

UserProfileDataManager::~UserProfileDataManager()
{

}

void UserProfileDataManager::slotProfileWidget()
{
	QDesktopWidget *deskdop = QApplication::desktop();
	userWidget->move((deskdop->width() - userWidget->width()) / 2, (deskdop->height() - userWidget->height()) / 2);
	userWidget->show();
	
	userWidget->setUserInfo(gDataManager->getUserInfo());
}

void UserProfileDataManager::slotUploadHeaderImage(QString filePath)
{
	headerImage.load(filePath);

	HttpNetWork::HttpUpLoadFile *upload = new HttpNetWork::HttpUpLoadFile;
	connect(upload, SIGNAL(sigUpLoadFinished(bool, QByteArray)), this, SLOT(slotHttpChangeAvatar(bool, QByteArray)));
	QVariantMap pargram;
	pargram.insert("parentId", "66662");
	pargram.insert("createUser", "6662");
	upload->StartUpLoadFile(gDataManager->getAppConfigInfo().PanServerUploadURL, filePath, pargram);
}

void UserProfileDataManager::slotHttpChangeAvatar(bool success, QByteArray byte)
{
	if (success)
	{
		QVariantMap map = QJsonDocument::fromJson(byte).toVariant().toMap();
		QString fileid = map["fileid"].toString();

		//上传成功了，通知服务器登录用户的头像已经改变。
		QString avatarURL = gDataManager->getAppConfigInfo().PanServerDownloadURL + fileid + "/download";
		UserInfo userInfo = gDataManager->getUserInfo();
		QString url = gDataManager->getAppConfigInfo().MessageServerAddress +
			QString("/IMServer/user/updateUserByUserId?userId=%1&passWord=%2&avatar=%3").arg(userInfo.nUserID).arg(userInfo.strUserPWD).arg(avatarURL);

		HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
		connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotAvatarChanged(bool, QString)));
		http->getHttpRequest(url);
	}
}

void UserProfileDataManager::slotAvatarChanged(bool success, QString byte)
{
	avatarWidget->upPicFileFinished(success);
	if (success)
	{
		userWidget->setHeaderImage(headerImage);
	}
}

void UserProfileDataManager::slotUserInfo(UserInfo userInfo)
{
	UserInfo user = gDataManager->getUserInfo();
	user.strUserNickName = userInfo.strUserNickName;
	user.strSign = userInfo.strSign;
	user.strSex = userInfo.strSex;
	user.strPhone = userInfo.strPhone;
	user.strEmil = userInfo.strEmil;

	userWidget->setUserInfo(user);

	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/user/updateUserByUserId"
		+ QString("?userId=%1&passWord=%2&nickName=%3&sex=%4&mobilePhone=%5&email=%6&sign=%7")
		.arg(user.nUserID).arg(user.strUserPWD).arg(user.strUserNickName).arg(user.strSex).arg(user.strPhone).arg(user.strEmil).arg(user.strSign);
	
	http->getHttpRequest(url);
}