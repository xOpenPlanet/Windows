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

	// Qualifier: 启动登陆界面
	void StartLoginWidget(QString strYWYHRequestURL, QString appID);

	// Qualifier: 销毁登陆窗口
	void DestroyLoginWidget();

	// Qualifier: 启动主界面
	void StartIMMainWidget(UserInfo userInfo);

	// Qualifier: 销毁主界面
	void DestroyIMMainWidget();

	// Qualifier: 接收到服务器消息
	void RevServerMessageInfo(MessageInfo msgInfo);

	void ChangeLoginWidget(QString);

	//读取本地存储的基地地址。
	void ReadWalletAddress();

private slots:
	// Qualifier: 收到插入好友信息信号
	void slotInsertBuddyInfo(BuddyInfo);

	// Qualifier: 插入群组信息
	void slotInsertGroupInfo(GroupInfo groupInfo);

	void slotCloseApp();

	//恢复钱包的处理。
	void slotRecoveryWallet(QString);
	//获得恢复钱包的结果。
	void slotRecoveryResult(QString);
signals:
	// Qualifier: 登陆成功信号
	void sigLoginSuccess(QVariantMap);

	// Qualifier: 更新消息状态
	void sigUpdateMessageState(MessageInfo, int);

	// Qualifier: 设置主窗口状态标签
	void sigSetMainWidgetStatusLabel(QString msg);

	// Qualifier: 更新用户信息
	void sigUpdateUserInfo(UserInfo);

	// Qualifier: 更新好友信息
	void sigUpdateInfo(int, QVariant);

	// Qualifier: 用户退出群组
	void sigUserQuitGroup(QString groupID, QString buddyID);

	// Qualifier: 申请添加好友成功
	void sigAddFriendSuccess(BuddyInfo);

	// Qualifier: 申请加入群组成功
	void sigAddSuccessGroup(GroupInfo);

	// Qualifier: /*群组添加成员成功*/
	void sigAddSuccessGroupUserInfo(QString groupID, BuddyInfo buddyInfo);

	// Qualifier: 删除好友
	//************************************
	void sigDeleteFriend(int type, QVariant userID);

	// Qualifier: 处理其他设备发送的消息
	void sigRevOtherDeviceMsg(MessageInfo msgInfo);

	void sigExit();

	//获得基地地址后，发送加载群组和好友的信号。
	void sigInitBuddyGroup();

	//删除群组
	void sigDeleteGroup(QString groupID);
private:
	OPMainManagerShareLib  *mMainManager;
	ScanQRLoginShareLib *m_pScanQR;
	RecoveryWidget* recoveryWidget;
	QCefView *cefView;
};

#endif // OPWINDOWSMANAGERSHARELIB_H
