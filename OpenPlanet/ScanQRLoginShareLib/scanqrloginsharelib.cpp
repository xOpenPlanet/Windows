#include "scanqrloginsharelib.h"
#include <QDebug>

ScanQRLoginShareLib::ScanQRLoginShareLib(QObject *parent)
: QObject(parent)
{
	scanWidget = NULL;
	pDataBase = NULL;
	ConnectLoginDB();
	OnInitWidget();
	//LoadDatabase();
}

ScanQRLoginShareLib::~ScanQRLoginShareLib()
{
	if (scanWidget)
	{
		scanWidget->deleteLater();
		scanWidget = NULL;
	}
}

//连接登陆数据库
void ScanQRLoginShareLib::ConnectLoginDB()
{
	if (pDataBase == NULL)
		pDataBase = new LoginDatabaseOperaShareLib;
	if (pDataBase->ConnectLoginDB("database//common.db", "login"))
		qDebug() << QStringLiteral("连接数据库成功!");
	else
		qDebug() << QStringLiteral("连接数据库失败!");
}

//初始化窗口
void ScanQRLoginShareLib::OnInitWidget()
{
	scanWidget = new ScanQRWidget;
	connect(scanWidget, SIGNAL(sigCloseLoginWidget()), this, SIGNAL(sigCloseLoginWidget()));
	//connect(scanWidget, SIGNAL(sigClickedLogin()), this, SIGNAL(sigClickedLogin()));
	connect(scanWidget, SIGNAL(sigQRLoginSuccess(QVariantMap)), this, SIGNAL(sigQRLoginSuccess(QVariantMap)));
	scanWidget->hide();
	scanWidget->showQrWidget();
}

//加载数据库信息
void ScanQRLoginShareLib::LoadDatabase()
{

}

void ScanQRLoginShareLib::showErro(QString strMsg)
{
	if (scanWidget)
	{
		scanWidget->showErro(strMsg);
	}
}