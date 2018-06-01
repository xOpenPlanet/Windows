#ifndef SCANQRLOGINSHARELIB_H
#define SCANQRLOGINSHARELIB_H

#include <QObject>
#include "scanqrwidget.h"
#include "logindatabaseoperasharelib.h"

class ScanQRLoginShareLib : public QObject
{
	Q_OBJECT
public:
	ScanQRLoginShareLib(QObject *parent = NULL);
	~ScanQRLoginShareLib();

	void showErro(QString strMsg);
private:
	// Qualifier:���ӵ�½���ݿ�
	void ConnectLoginDB();

	// Qualifier:�������ݿ���Ϣ
	void LoadDatabase();

	// Qualifier:��ʼ��widget
	void OnInitWidget();

signals:
	void sigCloseLoginWidget();
	//void sigClickedLogin();
	void sigQRLoginSuccess(QVariantMap);
private:
	ScanQRWidget *scanWidget;
	LoginDatabaseOperaShareLib *pDataBase;
};

#endif // SCANQRLOGINSHARELIB_H
