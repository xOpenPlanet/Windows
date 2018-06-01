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

//���ӵ�½���ݿ�
void ScanQRLoginShareLib::ConnectLoginDB()
{
	if (pDataBase == NULL)
		pDataBase = new LoginDatabaseOperaShareLib;
	if (pDataBase->ConnectLoginDB("database//common.db", "login"))
		qDebug() << QStringLiteral("�������ݿ�ɹ�!");
	else
		qDebug() << QStringLiteral("�������ݿ�ʧ��!");
}

//��ʼ������
void ScanQRLoginShareLib::OnInitWidget()
{
	scanWidget = new ScanQRWidget;
	connect(scanWidget, SIGNAL(sigCloseLoginWidget()), this, SIGNAL(sigCloseLoginWidget()));
	//connect(scanWidget, SIGNAL(sigClickedLogin()), this, SIGNAL(sigClickedLogin()));
	connect(scanWidget, SIGNAL(sigQRLoginSuccess(QVariantMap)), this, SIGNAL(sigQRLoginSuccess(QVariantMap)));
	scanWidget->hide();
	scanWidget->showQrWidget();
}

//�������ݿ���Ϣ
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