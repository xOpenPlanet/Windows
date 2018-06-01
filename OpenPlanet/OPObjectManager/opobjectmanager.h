#ifndef OPOBJECTMANAGER_H
#define OPOBJECTMANAGER_H

#include <QObject>
#include "imrequestbuddyinfo.h"
#include "imsocketmessageinfo.h"
#include "opwindowsmanagersharelib.h"
#include "parsesystemmessage.h"
#include "updatesharelib.h"

class OPObjectManager : public QObject
{
	Q_OBJECT
public:
	OPObjectManager(QObject *parent = NULL);
	~OPObjectManager();

	// Qualifier: ���·���
	void update();

	// Qualifier: ��ȡ������Ϣ
	AppConfig readAppConf();

	// Qualifier: ����LoginWidget
	void StartLoginWidget();

	// Qualifier: ��ʼ������
	void InitApp();
private:
	// Qualifier: ע���ź�����
	void RegisterMetaType();

	// Qualifier: ��ʼ����־��Ϣ
	void InitLog();

	// Qualifier: ��־��Ϣ
	void LogInfo(QtMsgType type, const QMessageLogContext &context, const QString &msg);

	// Qualifier: ���������Ϣ
	void RequestPersonInfo();

	// Qualifier: ���������Ϣ
	void RequestBuddyInfo();

	// Qualifier: ����Ⱥ����Ϣ
	void RequestGroupInfo();

	// Qualifier: ����socket
	void ConnectSocketServer();

	// Qualifier: �ж��Ƿ����������Ϣ
	void InitBuddyInfo();

	// Qualifier: �ж��Ƿ�����Ⱥ����Ϣ
	void InitGroupInfo();

	// Qualifier: ���غ�����Ϣ
	void LoadBuddyInfo();

	// Qualifier: ����Ⱥ����Ϣ
	void LoadGroupInfo();

	// Qualifier: �����ӷ��������ظ��ĸ�����Ϣ
	UserInfo ParseUserInfoFromServer(QVariantMap varMap);

private slots:
	// Qualifier: ��������Ĳۡ�
	void slotStart();

	// Qualifier: ��½�ɹ�
	void slotLoginSuccess(QVariantMap varMap);

	// Qualifier: ����������Ϣ�ɹ�
	void slotParsePersonInfo(bool bResult, UserInfo userInfo);

	//Qualifier: ���յ�ϵͳ��Ϣ
	void slotRevSystemMessage(MessageInfo);

	//Qualifier: ���յ���Ϣ
	void slotRevMsgInfo(MessageInfo, int);

	//Qualifier: ���յ���Ϣ
	//void slotRevUpdateMessageState(MessageInfo, int);

	//Qualifier: ��ȡsocket��Ϣʧ��
	void slotGetSocketAddressErro(QString);

	//Qualifier: ����socket�ɹ�
	void slotConnectSocketSuccess();

	//Qualifier:����socket�ɹ�
	void slotReConnectSuccess();

	void slotExit();

	//��ȡ���ص�ַ�ɹ��󣬼��غ��Ѻ�Ⱥ����Ϣ��
	void slotInitBuddyGroup();

signals:
	void sigReConnectServerSuccess(QString msg);

	void sigUpdateBuddyInfo(BuddyInfo buddyInfo);

private:
	OPWindowsManagerShareLib *mWindowManager;
	ParseSystemMessage *sysMessage;
};

#endif // OPOBJECTMANAGER_H
