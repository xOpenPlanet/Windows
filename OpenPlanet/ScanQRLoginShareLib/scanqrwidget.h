#ifndef SCANQRWIDGET_H
#define SCANQRWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "ui_scanqrwidget.h"
#include "scanshowqrwidget.h"
#include "scanloginwidget.h"
#include "scannetworksetwidget.h"
#include "threadpoll.h"
#include "Common.h"

class ScanQRWidget : public QWidget
{
	Q_OBJECT

public:
	ScanQRWidget(QWidget *parent = 0);
	~ScanQRWidget();

	/*显示二维码窗口*/
	void showQrWidget();

	void showErro(QString strMsg);

	/*显示用户窗口*/
	//void showUserWidget(UserInfo userInfo);
private:
	// Qualifier: 初始化样式表
	void OnInitStyleSheet();
	// Qualifier: 初始化
	void OnInit();
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

public slots:
	//设置用户
	void slotClickSetUser();
	//设置
	void slotClickSet();
	//关闭
	void slotClickClose();
	//创建二维码
	void slotCreateQR(QString);
signals:
	void sigCloseLoginWidget();
//	void sigClickedLogin();
	void sigQRLoginSuccess(QVariantMap);
private:
	Ui::ScanQRWidget ui;
	/*实现无边框可拖拽*/
	bool        mMoveing;
	QPoint      mMovePosition;
	ScanShowQRWidget *pShowQRWidget;
	ScanLoginWidget  *pScanLoginWidget;
	ScanNetWorkSetWidget *pScanNetWorkSetWidget;
};

#endif // SCANQRWIDGET_H
