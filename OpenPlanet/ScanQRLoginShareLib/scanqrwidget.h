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

	/*��ʾ��ά�봰��*/
	void showQrWidget();

	void showErro(QString strMsg);

	/*��ʾ�û�����*/
	//void showUserWidget(UserInfo userInfo);
private:
	// Qualifier: ��ʼ����ʽ��
	void OnInitStyleSheet();
	// Qualifier: ��ʼ��
	void OnInit();
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

public slots:
	//�����û�
	void slotClickSetUser();
	//����
	void slotClickSet();
	//�ر�
	void slotClickClose();
	//������ά��
	void slotCreateQR(QString);
signals:
	void sigCloseLoginWidget();
//	void sigClickedLogin();
	void sigQRLoginSuccess(QVariantMap);
private:
	Ui::ScanQRWidget ui;
	/*ʵ���ޱ߿����ק*/
	bool        mMoveing;
	QPoint      mMovePosition;
	ScanShowQRWidget *pShowQRWidget;
	ScanLoginWidget  *pScanLoginWidget;
	ScanNetWorkSetWidget *pScanNetWorkSetWidget;
};

#endif // SCANQRWIDGET_H
