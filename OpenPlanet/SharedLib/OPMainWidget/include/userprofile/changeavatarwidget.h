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
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

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

	UserInfo userInfo;  //保存用户信息。

	bool changed;       //如果头像没有改变，就不进行上传。
	bool isUploading;   //如果已经在上传过程中，就不进行上传。

	QLabel *picMask;  //头像遮罩。
	QPoint point;   //记录鼠标点击的位置，用于拖动头像位置的判断。
	QPixmap originImg;  //记录原始图像。
	int times;     //记录缩放的倍数。
};

#endif // CHANGEAVATARWIDGET_H
