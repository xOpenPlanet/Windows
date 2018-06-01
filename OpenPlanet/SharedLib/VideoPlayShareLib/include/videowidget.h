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

	void setMedia(QString address); //������Ƶ��ַ�ķ�������������Ƶ��ַ��
	void setVolume(int volume);     //����������
	void setPosition(qint64 pos);    //���ý��ȡ�

	QSize getVideoSize();           //��ȡ��Ƶ�ĳߴ硣
	qint64 getDuration();        //��ȡ��Ƶ�ĳ��ȡ�

	//���ſ��Ʒ��������š���ͣ��ֹͣ��
	void play();
	void pause();
	void stop();

private:
	QMediaPlayer *media;
};

#endif // VIDEOWIDGET_H
