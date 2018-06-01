#pragma once

#include <QWidget>
#include <QCryptographicHash>
#include "messagebox.h"
#include "ui_passwordwidget.h"

class PasswordWidget : public QWidget
{
	Q_OBJECT

public:
	PasswordWidget(QString password, QWidget *parent = NULL);
	~PasswordWidget();

signals:
	void sigPasswordTrue();

private slots:
void slotClickedEnterBtn();

private:
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�

private:
	Ui::PasswordWidget ui;

	QPoint mouse;

	QString password;
};
