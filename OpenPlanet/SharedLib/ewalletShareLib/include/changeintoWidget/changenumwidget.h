#pragma once

#include <QWidget>
#include <QMouseEvent>
#include "ui_changenumwidget.h"

class ChangeNumWidget : public QWidget
{
	Q_OBJECT

public:
	ChangeNumWidget(QWidget *parent = Q_NULLPTR);
	~ChangeNumWidget();

signals:
	void sigChangeNum(QString);

private slots:
	void slotSetChangeNum();

private:
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�

private:
	Ui::ChangeNumWidget ui;

	QPoint mouse;
};
