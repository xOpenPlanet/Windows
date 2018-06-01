#ifndef VLCWIDGET_H
#define VLCWIDGET_H

#include <Windows.h>
#include <QWidget>
#include <qtimer.h>
#include <qdesktopwidget.h>
#include <QMouseEvent>
#include <QTime>
#include "ui_imvideoplayer.h"
#include "videowidget.h"

class IMVideoPlayer : public QWidget
{
	Q_OBJECT

public:
	IMVideoPlayer(QWidget *parent = 0);
	~IMVideoPlayer();

	void videoPlay(QString mediaPath);

protected:
	void mousePressEvent(QMouseEvent *event);        //µ¥»÷
	void mouseReleaseEvent(QMouseEvent *event);      //ÊÍ·Å
	void mouseDoubleClickEvent(QMouseEvent *event);  //Ë«»÷
	void mouseMoveEvent(QMouseEvent *event);         //ÒÆ¶¯

private:
	Ui::IMVideoPlayer ui;

	QString address;
	QTimer *initTimer;
	QTimer *playTimer;
	QSize originSize;
	bool isPlaying;
	int duration;
	QPoint mouse;

	QPixmap closeImg;
	QPixmap playImg;
	QPixmap pauseImg;

	void setProgress();

public slots:
    void sizeInitSlot();
	void playPauseSlot();
	void stepSliderSlot();
	void setSliderSlot(int);
};

#endif // VLCWIDGET_H
