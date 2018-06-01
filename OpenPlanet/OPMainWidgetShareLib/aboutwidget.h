#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>
#include <qpainter.h>
#include <qevent.h>
#include <qmath.h>
#include "ui_aboutwidget.h"

class AboutWidget : public QWidget
{
	Q_OBJECT

public:
	AboutWidget(QWidget *parent = 0);
	~AboutWidget();

	void setName(QString);
	void setNumber(QString);

protected:
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�

private:
	Ui::AboutWidget ui;

	QPoint mouse;
};

#endif // ABOUTWIDGET_H
