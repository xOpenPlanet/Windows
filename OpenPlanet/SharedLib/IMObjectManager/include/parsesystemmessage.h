#ifndef PARSESYSTEMMESSAGE_H
#define PARSESYSTEMMESSAGE_H

#include <QObject>
#include "stdafx.h"
#include "alphabeticalsortsharedlib.h"
/*解析系统消息*/

class ParseSystemMessage : public QObject
{
	Q_OBJECT

public:
	ParseSystemMessage(QObject *parent = 0);
	~ParseSystemMessage();

	//************************************
	// Method:    ParseSystemMessage
	// FullName:  ParseSystemMessage::ParseSystemMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: 解析系统消息
	// Parameter: MessageInfo messageInfo
	//************************************
	void ParseSysMessage(MessageInfo messageInfo);

private:
	//************************************
	// Method:    GetExeDir
	// FullName:  ParseSystemMessage::GetExeDir
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: 获取程序运行路径
	//************************************
	QString GetExeDir();

	//************************************
	// Method:    OnDealUpUser
	// FullName:  ParseSystemMessage::OnDealUpUser
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理更新好友信息
	// Parameter: QVariantMap mapResult
	//************************************
	void OnDealUpDateUser(MessageInfo msgInfo, QVariantMap mapResult);

	//************************************
	// Method:    OnDealUpdateGroupInfo
	// FullName:  ParseSystemMessage::OnDealUpdateGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新群组信息
	// Parameter: GroupInfo groupInfo
	//************************************
	void OnDealUpdateGroupInfo(QVariantMap mapResult);

	//************************************
	// Method:    OnDealUserQuitGroup
	// FullName:  ParseSystemMessage::OnDealUserQuitGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理用户退出群组
	// Parameter: QVariantMap mapResult
	//************************************
	void OnDealUserQuitGroup(QVariantMap mapResult);

	//************************************
	// Method:    OnDealAddFriend
	// FullName:  ParseSystemMessage::OnDealAddFriend
	// Access:    private 
	// Returns:   void 
	// Qualifier: 添加好友
	// Parameter: QVariantMap result
	//************************************
	void OnDealAddFriend(QVariantMap result);

	//************************************
	// Method:    OnDealAddUserToGroup
	// FullName:  ParseSystemMessage::OnDealAddUserToGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 申请加入群组成功
	// Parameter: QVariantMap result
	//************************************
	void OnDealAddUserToGroup(QVariantMap result);

	//解散群组
	void OnDealDisSolveGroup(QVariantMap result);
	private slots:
	void slotRequestPersonInfoFinished(bool bResult, QString result);
	void slotRequestGroupInfoFinished(bool bResult, QString result);
	void slotRecvAddGroupUser(bool success, QString data);
signals:
	//************************************
	// Method:    sigUpdateUserInfo
	// FullName:  ParseSystemMessage::sigUpdateUserInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新用户信息
	// Parameter: UserInfo userInfo
	//************************************
	void sigUpdateUserInfo(UserInfo userInfo);

	//************************************
	// Method:    sigUpdateBuddyInfo
	// FullName:  ParseSystemMessage::sigUpdateBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新好友信息
	// Parameter: BuddyInfo
	//************************************
	void sigUpdateInfo(int,QVariant);

	//************************************
	// Method:    sigAddFriendSuccess
	// FullName:  ParseSystemMessage::sigAddFriendSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: 添加好友成功
	//************************************
	void sigAddFriendSuccess(BuddyInfo);

	//************************************
	// Method:    sigAddSuccessGroup
	// FullName:  ParseSystemMessage::sigAddSuccessGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 添加群组成功
	// Parameter: GroupInfo
	//************************************
	void sigAddSuccessGroup(GroupInfo);

	//************************************
	// Method:    sigAddSuccessGroupUserInfo
	// FullName:  ParseSystemMessage::sigAddSuccessGroupUserInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: /*群组添加成员成功*/
	// Parameter: QString strGroupID
	// Parameter: BuddyInfo buddy
	//************************************
	void sigAddSuccessGroupUserInfo(QString strGroupID, BuddyInfo buddy);

	//************************************
	// Method:    sigUserQuitGroup
	// FullName:  ParseSystemMessage::sigUserQuitGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 用户退出群组消息
	// Parameter: QString groupID
	// Parameter: QString userID
	//************************************
	void sigUserQuitGroup(QString groupID, QString userID);
private:
	AlphabeticalSortSharedLib mAlphabeticalSort;   //根据汉字返回首字母拼音
};

#endif // PARSESYSTEMMESSAGE_H
