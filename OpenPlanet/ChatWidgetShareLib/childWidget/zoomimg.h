#ifndef ZOOMIMG_H
#define ZOOMIMG_H

#include <QWidget>
#include "ui_zoomimg.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>

class ZoomImg : public QWidget
{
	Q_OBJECT

public:
	ZoomImg(QWidget *parent = 0);
	~ZoomImg();
	void OpenImg(QString filePath);
	QString decodeURI(QString str);
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
private:
	Ui::zoomImg ui;
	//QImage *image;
	//QGraphicsView *graphicsView;
	QLabel* label;
	QPushButton *myButton;
	/*实现无边框可拖拽*/
	bool        mMoveing;
	QPoint      mMovePosition;
};

#endif // ZOOMIMG_H
