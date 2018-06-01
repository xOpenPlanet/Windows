#pragma once

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <qmath.h>
#include "common.h"
#include "ui_userinfowidget.h"

class UserInfoWidget : public QWidget
{
	Q_OBJECT

public:
	UserInfoWidget(QWidget *parent = Q_NULLPTR);
	~UserInfoWidget();

	//************************************
	// Method:    setUserInfo
	// FullName:  UserInfoWidget::setUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: UserInfo
	//************************************
	void setUserInfo(UserInfo);

protected:
	bool eventFilter(QObject *obj, QEvent *e);
	void paintEvent(QPaintEvent * event);

signals:
	void sigUserInfo(UserInfo);

private slots:
	//************************************
	// Method:    slotUserInfo
	// FullName:  UserInfoWidget::slotUserInfo
	// Access:    private 
	// Returns:   void
	// Qualifier:
	//************************************
	void slotUserInfo();

private:
	Ui::UserInfoWidget ui;

	QPoint mouse;  //用于窗口移动的暂存变量
};
