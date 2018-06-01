#pragma once

#include <QWidget>
#include <QFile>
#include "ui_menuwidget.h"

class MenuWidget : public QWidget
{
	Q_OBJECT

public:
	MenuWidget(QWidget *parent = Q_NULLPTR);
	~MenuWidget();

	void setUserInfo(QString nickName, QString sign);

protected:
	void focusOutEvent(QFocusEvent *e);

private slots:
    void slotClickedBtn();

signals:
	void sigUserProfile();
	void sigClickedMenuItem(QString);

private:
	Ui::MenuWidget ui;
};
