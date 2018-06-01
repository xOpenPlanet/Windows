#ifndef GROUPPROFILEWIDGET_H
#define GROUPPROFILEWIDGET_H

#include <QWidget>
#include <qbitmap.h>
#include <QFile>
#include <QJsonDocument>
#include "qlabelheader.h"
#include "imbuddy.h"
#include "stdafx.h"
#include "imtranstype.h"
#include "ui_groupprofilewidget.h"
#include "groupavatarwidget.h"
#include "httpnetworksharelib.h"

class GroupProfileWidget : public QWidget
{
	Q_OBJECT

public:
	GroupProfileWidget(QWidget *parent = 0);
	void setGroup(QString);

private slots:
	void slotGroupChat();
	void slotUploadHeaderImage(QString filePath);
	void slotHttpChangeAvatar(bool success, QByteArray byte);
	void slotAvatarChanged(bool success, QString byte);

signals:
	void sigGroupChat(int, QVariant);

private:
	bool eventFilter(QObject *, QEvent *);

private:
	Ui::GroupProfileWidget ui;

	QLabelHeader *headerLabel;

	QPushButton *groupChatBtn;

	QString groupID;

	QPixmap headerImage;

	GroupAvatarWidget *avatarWidget;
};

#endif // GROUPPROFILEWIDGET_H
