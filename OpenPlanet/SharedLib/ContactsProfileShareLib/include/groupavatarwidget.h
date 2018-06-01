#ifndef GroupAvatarWidget_H
#define GroupAvatarWidget_H

#include <QWidget>
#include <qpainter.h>
#include <qevent.h>
#include <qscrollbar.h>
#include <qmath.h>
#include <QFileDialog>
#include <QLabel>
#include "common.h"
#include "imbuddy.h"
#include "ui_groupavatarwidget.h"
#include "messagebox.h"

class GroupAvatarWidget : public QWidget
{
	Q_OBJECT

public:
	GroupAvatarWidget(QWidget *parent = 0);
	~GroupAvatarWidget();

	void setGroupInfo(GroupInfo);
	void upPicFileFinished(bool);

protected:
	void mousePressEvent(QMouseEvent *event);        //����
	void mouseReleaseEvent(QMouseEvent *event);      //�ͷ�
	void mouseMoveEvent(QMouseEvent *event);         //�ƶ�

	void paintEvent(QPaintEvent * event);
	bool eventFilter(QObject *obj, QEvent *e);

signals:
	void sigUploadImagePath(QString);

private slots:
	void slotUploadImage();
	void slotConfirmImage();
	void slotCancel();

private:
	Ui::GroupAvatarWidget ui;

	void setAvatar(QString headerPath);
	
	QPoint mouse;

	GroupInfo groupInfo;  //����Ⱥ����Ϣ��

	bool changed;       //���ͷ��û�иı䣬�Ͳ������ϴ���
	bool isUploading;   //����Ѿ����ϴ������У��Ͳ������ϴ���

	QLabel *picMask;  //ͷ�����֡�
	QPoint point;   //��¼�������λ�ã������϶�ͷ��λ�õ��жϡ�
	QPixmap originImg;  //��¼ԭʼͼ��
	int times;     //��¼���ŵı�����
};

#endif // GroupAvatarWidget_H
