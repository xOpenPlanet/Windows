#ifndef CHANGEAVATARWIDGET_H
#define CHANGEAVATARWIDGET_H

#include <QWidget>
#include <qpainter.h>
#include <qevent.h>
#include <qscrollbar.h>
#include <qmath.h>
#include <QFileDialog>
#include <QLabel>
#include "common.h"
#include "ui_changeavatarwidget.h"
#include "messagebox.h"

class ChangeAvatarWidget : public QWidget
{
	Q_OBJECT

public:
	ChangeAvatarWidget(QWidget *parent = 0);
	~ChangeAvatarWidget();

	void setUserInfo(UserInfo);
	void upPicFileFinished(bool);

protected:
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�

	void paintEvent(QPaintEvent * event);
	bool eventFilter(QObject *obj, QEvent *e);

signals:
	void sigUploadHeaderImage(QString);

private slots:
	void slotUploadImage();
	void slotConfirmImage();
	void slotCancel();

private:
	Ui::ChangeAvatarWidget ui;

	void setAvatar(QString headerPath);

	QPoint mouse;

	UserInfo userInfo;  //�����û���Ϣ��

	bool changed;       //���ͷ��û�иı䣬�Ͳ������ϴ���
	bool isUploading;   //����Ѿ����ϴ������У��Ͳ������ϴ���

	QLabel *picMask;  //ͷ�����֡�
	QPoint point;   //��¼�������λ�ã������϶�ͷ��λ�õ��жϡ�
	QPixmap originImg;  //��¼ԭʼͼ��
	int times;     //��¼���ŵı�����
};

#endif // CHANGEAVATARWIDGET_H
