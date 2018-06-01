#ifndef PERPROFILEWIDGET_H
#define PERPROFILEWIDGET_H

#include <QWidget>
#include <qpainter.h>
#include <qbitmap.h>
#include <QPushButton>
#include <QFile>
#include <qclipboard.h>
#include "opcommon.h"
#include "imbuddy.h"
#include "stdafx.h"
#include "imtranstype.h"
#include "ui_perprofilewidget.h"

class perProfileWidget : public QWidget
{
	Q_OBJECT

public:
	perProfileWidget(QWidget *parent = 0);
	~perProfileWidget();

	void setBuddy(BuddyInfo buddy, AddressInfo info);

public slots:
	void slotPerChat();

private slots:
void slotCopyAddress();

signals:
	void sigPerChat(int, QVariant);



private:
	void setStar(QString star);

private:
	Ui::perProfileWidget ui;

	QString buddyID;
};

#endif // PERPROFILEWIDGET_H
