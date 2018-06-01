#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <qmath.h>
#include "ui_messagebox.h"

class IMessageBox : public QWidget
{
	Q_OBJECT

public:
	IMessageBox(QWidget *parent = Q_NULLPTR);
	~IMessageBox();

	static void tip(QWidget *parent, QString title, QString text);

	void init(QString title, QString text);

private:
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�

	void paintEvent(QPaintEvent * event);

private:
	Ui::IMessageBox ui;

	QPoint mouse;
};
