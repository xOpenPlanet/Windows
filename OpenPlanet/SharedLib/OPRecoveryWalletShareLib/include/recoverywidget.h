#pragma once

#include <QWidget>
#include <QMouseEvent>
#include "ui_recoverywidget.h"
#include "messagebox.h"

class RecoveryWidget : public QWidget
{
	Q_OBJECT

public:
	RecoveryWidget(QWidget *parent = Q_NULLPTR);
	~RecoveryWidget();

	private slots:
	void slotSwitchStackedWidget();
	void slotClickedBtn();

protected:
	void mousePressEvent(QMouseEvent *event);        //µ¥»÷
	void mouseReleaseEvent(QMouseEvent *event);      //ÊÍ·Å
	void mouseMoveEvent(QMouseEvent *event);         //ÒÆ¶¯

signals:
	void sigClose();
	void sigRecoveryWord(QString);
	void sigPrivateKey(QString);

private:
	Ui::RecoveryWidget ui;

	QPoint mouse;
};
