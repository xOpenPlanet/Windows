#pragma once

#include <QWidget>
#include <QEvent>
#include "messagebox.h"
#include "ui_secretletterwidget.h"

class SecretLetterWidget : public QWidget
{
	Q_OBJECT

public:
	SecretLetterWidget(QWidget *parent = Q_NULLPTR);
	~SecretLetterWidget();

private slots:
	void slotClickedEnterBtn();

signals:
	void sigSecretLetter(QString password, QString text);

private:
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�
	
private:
	Ui::SecretLetterWidget ui;

	QPoint mouse;
};
