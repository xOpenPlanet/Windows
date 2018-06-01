#include "myemotionitemwidget.h"
#include <QMovie>
#include <QDebug>

MyEmotionItemWidget::MyEmotionItemWidget(QString fileName , QSize emotionMoiveSize)
	: QLabel(NULL)
{
	//���ȹ��캯���н��г�ʼ��;
	QMovie* iconMovie = new QMovie;
	iconMovie->setFileName(fileName);
	this->setMovie(iconMovie);
	setContentsMargins(3, 3, 3, 3);
	iconMovie->setScaledSize(QSize(emotionMoiveSize.width(), emotionMoiveSize.height()));
	//Ϊ�˶�̬ͼƬ������ʾ����������startͼƬ����ʾ��������stopͼƬһ�ִ��ڶ�̬Ч����
	iconMovie->start();
	iconMovie->stop();
	setStyleSheet("QLabel:hover{border: 1px solid rgb(111, 156, 207);\
								color: rgb(2, 65, 132);\
								background: rgba(255, 255, 255, 200);}");
}

MyEmotionItemWidget::~MyEmotionItemWidget()
{}

// ������Label�¼�
void MyEmotionItemWidget::enterEvent(QEvent* event)
{
	QMovie* movie = this->movie();
	movie->start();
	setContentsMargins(4, 2, 2, 4);
    return QLabel::enterEvent(event);
}
// ����뿪Label�¼�
void MyEmotionItemWidget::leaveEvent(QEvent* event)
{
	QMovie* movie = this->movie();
	movie->jumpToFrame(0);
	movie->stop();
	setContentsMargins(3, 3, 3, 3);
    return QLabel::leaveEvent(event);
}
