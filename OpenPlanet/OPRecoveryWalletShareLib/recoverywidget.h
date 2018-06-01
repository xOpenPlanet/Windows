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
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�

signals:
	void sigClose();
	void sigRecoveryWord(QString);
	void sigPrivateKey(QString);

private:
	Ui::RecoveryWidget ui;

	QPoint mouse;
};
