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
	// Qualifier:连接登陆数据库
	void ConnectLoginDB();

	// Qualifier:加载数据库信息
	void LoadDatabase();

	// Qualifier:初始化widget
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
