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
	// Qualifier: 接收到服务器消息
	// Parameter: MessageInfo msgInfo
	//************************************
	void RevServerMessage(MessageInfo msgInfo);

	//以下是电子钱包界面调用的方法。
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
	// Qualifier: 更新用户头像
	// Parameter: int nUserID
	// Parameter: QPixmap pix
	//************************************
	void slotUpdateUserHeaderImg(int nUserID, QPixmap pix);

	//************************************
	// Method:    slotUpdateBuddyHeaderImg
	// FullName:  IMainObjectManager::slotUpdateBuddyHeaderImg
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新好友头像
	// Parameter: int nUserID
	// Parameter: QPixmap pix
	//************************************
	void slotUpdateBuddyHeaderImg(int nUserID, QPixmap pix);

	//************************************
	// Method:    slotUpdateGroupHeaderImg
	// FullName:  IMainObjectManager::slotUpdateGroupHeaderImg
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新群组头像
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
	// Qualifier: 更新好友、群组信息
	// Parameter: int type
	// Parameter: QVariant var
	//************************************
	void slotUpdateInfo(int type, QVariant var);

	//************************************
	// Method:    slotUserQuitGroup
	// FullName:  IMainObjectManager::slotUserQuitGroup
	// Access:    public 
	// Returns:   void
	// Qualifier: 用户退出群组
	// Parameter: QString
	// Parameter: QString
	//************************************
	void slotUserQuitGroup(QString groupID, QString buddyID);

	//************************************
	// Method:    slotAddFriendSuccess
	// FullName:  IMainObjectManager::slotAddFriendSuccess
	// Access:    public 
	// Returns:   void
	// Qualifier: 添加好友成功
	//************************************
	void slotAddFriendSuccess(BuddyInfo buddyInfo);

	//************************************
	// Method:    slotAddSuccessGroup
	// FullName:  IMainObjectManager::slotAddSuccessGroup
	// Access:    public 
	// Returns:   void
	// Qualifier: 加入群组成功
	// Parameter: GroupInfo
	//************************************
	void slotAddSuccessGroup(GroupInfo);

	//************************************
	// Method:    slotAddSuccessGroupUserInfo
	// FullName:  IMainObjectManager::slotAddSuccessGroupUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 群组添加成员成功
	// Parameter: QString
	// Parameter: BuddyInfo
	//************************************
	void slotAddSuccessGroupUserInfo(QString, BuddyInfo);

	//************************************
	// Method:    slotInitMainWidget
	// FullName:  IMainObjectManager::slotInitMainWidget
	// Access:    public 
	// Returns:   void
	// Qualifier: 初始化主窗口
	// Parameter: UserInfo userInfo
	//************************************
	void slotInitMainWidget(UserInfo userInfo);

	void slotWidgetMinSize();

	void slotShowNormalWindow();

private slots:
	void slotAddCreateGroup();
	void slotAddPerson();
	void slotDormancyState(bool bState);//设置休眠状态,如果休眠，不重连。如果唤醒，重新开始重连
	void slotDeleteGroup(QString);   //删除群组
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
