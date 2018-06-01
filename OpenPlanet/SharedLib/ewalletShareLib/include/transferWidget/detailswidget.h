#pragma once

#include <QWidget>
#include <QEvent>
#include "ui_detailswidget.h"

class DetailsWidget : public QWidget
{
	Q_OBJECT

public:
	DetailsWidget(QWidget *parent = Q_NULLPTR);
	~DetailsWidget();

	void setData(QVariantMap);

private:
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�

private:
	Ui::DetailsWidget ui;

	QPoint mouse;
};
