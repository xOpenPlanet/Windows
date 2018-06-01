#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QVideoWidget>
#include <QMediaPlayer>

class VideoWidget : public QVideoWidget
{
	Q_OBJECT

public:
	VideoWidget(QObject *parent = NULL);
	~VideoWidget();

	void setMedia(QString address); //设置视频地址的方法，参数是视频地址。
	void setVolume(int volume);     //设置音量。
	void setPosition(qint64 pos);    //设置进度。

	QSize getVideoSize();           //获取视频的尺寸。
	qint64 getDuration();        //获取视频的长度。

	//播放控制方法：播放、暂停、停止。
	void play();
	void pause();
	void stop();

private:
	QMediaPlayer *media;
};

#endif // VIDEOWIDGET_H
