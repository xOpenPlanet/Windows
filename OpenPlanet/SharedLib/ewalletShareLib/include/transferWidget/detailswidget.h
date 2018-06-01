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
	void mousePressEvent(QMouseEvent *event);        //µ¥»÷
	void mouseReleaseEvent(QMouseEvent *event);      //ÊÍ·Å
	void mouseMoveEvent(QMouseEvent *event);         //ÒÆ¶¯

private:
	Ui::DetailsWidget ui;

	QPoint mouse;
};
