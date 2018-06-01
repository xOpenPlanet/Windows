#ifndef OPMAINMANAGERSHARELIB_H
#define OPMAINMANAGERSHARELIB_H

#include <QObject>
#include "immainwidget.h"
#include "contactsdatamanager.h"
#include "chatdatamanager.h"
#include "common.h"
#include "userprofiledatamanager.h"
#include "ewalletmanager.h"
#include "creategroupwidget.h"
#include "imaddperson.h"

class OPMainManagerShareLib : public QObject
{
	Q_OBJECT
public:
	OPMainManagerShareLib(QObject *parent);
	~OPMainManagerShareLib();

	//************************************
	// Method:    startMainWidget
	// FullName:  IMainObjectManager::startMainWidget
	// Access:    public 
	// Returns:   void
	// Qualifier:
	//************************************
	void startMainWidget(UserInfo userInfo);

	//************************************
	// Method:    RevServerMessage
	// FullName:  IMainObjectManager::RevServerMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: ���յ���������Ϣ
	// Parameter: MessageInfo msgInfo
	//************************************
	void RevServerMessage(MessageInfo msgInfo);

	//�����ǵ���Ǯ��������õķ�����
	void setWalletInfo(WalletInfo);

	public slots:
	//************************************
	// Method:    slotBuddysManager
	// FullName:  IMainObjectManager::slotBuddysManager
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: int type
	// Parameter: QVariant data
	//************************************
	void slotBuddysManager(int type, QVariant data);

	//************************************
	// Method:    slotGroupsManager
	// FullName:  IMainObjectManager::slotGroupsManager
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: int type
	// Parameter: QVariant data
	//************************************
	void slotGroupsManager(int type, QVariant data);

	//************************************
	// Method:    slotUpdateUserHeaderImg
	// FullName:  IMainObjectManager::slotUpdateUserHeaderImg
	// Access:    private 
	// Returns:   void
	// Qualifier: �����û�ͷ��
	// Parameter: int nUserID
	// Parameter: QPixmap pix
	//************************************
	void slotUpdateUserHeaderImg(int nUserID, QPixmap pix);

	//************************************
	// Method:    slotUpdateBuddyHeaderImg
	// FullName:  IMainObjectManager::slotUpdateBuddyHeaderImg
	// Access:    private 
	// Returns:   void
	// Qualifier: ���º���ͷ��
	// Parameter: int nUserID
	// Parameter: QPixmap pix
	//************************************
	void slotUpdateBuddyHeaderImg(int nUserID, QPixmap pix);

	//************************************
	// Method:    slotUpdateGroupHeaderImg
	// FullName:  IMainObjectManager::slotUpdateGroupHeaderImg
	// Access:    private 
	// Returns:   void
	// Qualifier: ����Ⱥ��ͷ��
	// Parameter: int nUserID
	// Parameter: QPixmap pix
	//************************************
	void slotUpdateGroupHeaderImg(int nUserID, QPixmap pix);

	//************************************
	// Method:    slotOpenChat
	// FullName:  IMainObjectManager::slotOpenChat
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: QString userID
	//************************************
	void slotOpenChat(int type, QVariant userID);

	//************************************
	// Method:    slotUpdateInfo
	// FullName:  IMainObjectManager::slotUpdateInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ���º��ѡ�Ⱥ����Ϣ
	// Parameter: int type
	// Parameter: QVariant var
	//************************************
	void slotUpdateInfo(int type, QVariant var);

	//************************************
	// Method:    slotUserQuitGroup
	// FullName:  IMainObjectManager::slotUserQuitGroup
	// Access:    public 
	// Returns:   void
	// Qualifier: �û��˳�Ⱥ��
	// Parameter: QString
	// Parameter: QString
	//************************************
	void slotUserQuitGroup(QString groupID, QString buddyID);

	//************************************
	// Method:    slotAddFriendSuccess
	// FullName:  IMainObjectManager::slotAddFriendSuccess
	// Access:    public 
	// Returns:   void
	// Qualifier: ��Ӻ��ѳɹ�
	//************************************
	void slotAddFriendSuccess(BuddyInfo buddyInfo);

	//************************************
	// Method:    slotAddSuccessGroup
	// FullName:  IMainObjectManager::slotAddSuccessGroup
	// Access:    public 
	// Returns:   void
	// Qualifier: ����Ⱥ��ɹ�
	// Parameter: GroupInfo
	//************************************
	void slotAddSuccessGroup(GroupInfo);

	//************************************
	// Method:    slotAddSuccessGroupUserInfo
	// FullName:  IMainObjectManager::slotAddSuccessGroupUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: Ⱥ����ӳ�Ա�ɹ�
	// Parameter: QString
	// Parameter: BuddyInfo
	//************************************
	void slotAddSuccessGroupUserInfo(QString, BuddyInfo);

	//************************************
	// Method:    slotInitMainWidget
	// FullName:  IMainObjectManager::slotInitMainWidget
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ʼ��������
	// Parameter: UserInfo userInfo
	//************************************
	void slotInitMainWidget(UserInfo userInfo);

	void slotWidgetMinSize();

	void slotShowNormalWindow();

private slots:
	void slotAddCreateGroup();
	void slotAddPerson();
	void slotDormancyState(bool bState);//��������״̬,������ߣ���������������ѣ����¿�ʼ����
	void slotDeleteGroup(QString);   //ɾ��Ⱥ��
	void slotDeleteBuddy(int type, QVariant userID);

	void slotDownloadStranger(bool, QString);
signals:
	void sigUpdateMessageState(MessageInfo, int);
	void sigSetMainWidgetStatusLabel(QString);
	void sigExit();
	void sigRevOtherDeviceMsg(MessageInfo);

private:
	IMMainWidget *mainWidget;
	UserProfileDataManager *userProfileManager;
	ContactsDataManager *contactsManager;
	ChatDataManager *chatManager;
	EWalletManager *walletManager;
};

#endif // OPMAINMANAGERSHARELIB_H
