#ifndef OPWINDOWSMANAGERSHARELIB_H
#define OPWINDOWSMANAGERSHARELIB_H

#include <QObject>
#include <QJsonDocument>
#include "stdafx.h"
#include "opmainmanagersharelib.h"
#include "opdatamanager.h"
#include "common.h"
#include "scanqrloginsharelib.h"
#include "opdatebasesharelib.h"
#include "recoverywidget.h"
#include "messagebox.h"

class OPWindowsManagerShareLib:public QObject
{
	Q_OBJECT
public:
	OPWindowsManagerShareLib(QObject *parent = 0);
	~OPWindowsManagerShareLib();

	// Qualifier: ������½����
	void StartLoginWidget(QString strYWYHRequestURL, QString appID);

	// Qualifier: ���ٵ�½����
	void DestroyLoginWidget();

	// Qualifier: ����������
	void StartIMMainWidget(UserInfo userInfo);

	// Qualifier: ����������
	void DestroyIMMainWidget();

	// Qualifier: ���յ���������Ϣ
	void RevServerMessageInfo(MessageInfo msgInfo);

	void ChangeLoginWidget(QString);

	//��ȡ���ش洢�Ļ��ص�ַ��
	void ReadWalletAddress();

private slots:
	// Qualifier: �յ����������Ϣ�ź�
	void slotInsertBuddyInfo(BuddyInfo);

	// Qualifier: ����Ⱥ����Ϣ
	void slotInsertGroupInfo(GroupInfo groupInfo);

	void slotCloseApp();

	//�ָ�Ǯ���Ĵ���
	void slotRecoveryWallet(QString);
	//��ûָ�Ǯ���Ľ����
	void slotRecoveryResult(QString);
signals:
	// Qualifier: ��½�ɹ��ź�
	void sigLoginSuccess(QVariantMap);

	// Qualifier: ������Ϣ״̬
	void sigUpdateMessageState(MessageInfo, int);

	// Qualifier: ����������״̬��ǩ
	void sigSetMainWidgetStatusLabel(QString msg);

	// Qualifier: �����û���Ϣ
	void sigUpdateUserInfo(UserInfo);

	// Qualifier: ���º�����Ϣ
	void sigUpdateInfo(int, QVariant);

	// Qualifier: �û��˳�Ⱥ��
	void sigUserQuitGroup(QString groupID, QString buddyID);

	// Qualifier: ������Ӻ��ѳɹ�
	void sigAddFriendSuccess(BuddyInfo);

	// Qualifier: �������Ⱥ��ɹ�
	void sigAddSuccessGroup(GroupInfo);

	// Qualifier: /*Ⱥ����ӳ�Ա�ɹ�*/
	void sigAddSuccessGroupUserInfo(QString groupID, BuddyInfo buddyInfo);

	// Qualifier: ɾ������
	//************************************
	void sigDeleteFriend(int type, QVariant userID);

	// Qualifier: ���������豸���͵���Ϣ
	void sigRevOtherDeviceMsg(MessageInfo msgInfo);

	void sigExit();

	//��û��ص�ַ�󣬷��ͼ���Ⱥ��ͺ��ѵ��źš�
	void sigInitBuddyGroup();

	//ɾ��Ⱥ��
	void sigDeleteGroup(QString groupID);
private:
	OPMainManagerShareLib  *mMainManager;
	ScanQRLoginShareLib *m_pScanQR;
	RecoveryWidget* recoveryWidget;
	QCefView *cefView;
};

#endif // OPWINDOWSMANAGERSHARELIB_H
