#ifndef USERPROFILEDATAMANAGER_H
#define USERPROFILEDATAMANAGER_H

#include <QObject>
#include <QJsonDocument>
#include <QDesktopWidget>
#include "userprofile/userprofilewidget.h"
#include "userprofile/changeavatarwidget.h"
#include "userprofile/userinfowidget.h"
#include "userprofile/menuwidget.h"
#include "common.h"
#include "stdafx.h"
#include "httpnetworksharelib.h"

class UserProfileDataManager : public QObject
{
	Q_OBJECT

public:
	UserProfileDataManager(QObject *parent = NULL);
	~UserProfileDataManager();

private slots:
	void slotProfileWidget();
	void slotUploadHeaderImage(QString);
	void slotHttpChangeAvatar(bool, QByteArray);
	void slotAvatarChanged(bool, QString);
	void slotUserInfo(UserInfo);

private:
	UserProfileWidget *userWidget;
	ChangeAvatarWidget *avatarWidget;
	UserInfoWidget *infoWidget;

	QPixmap headerImage;
};

#endif // USERPROFILEDATAMANAGER_H
