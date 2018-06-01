#ifndef PARSESYSTEMMESSAGE_H
#define PARSESYSTEMMESSAGE_H

#include <QObject>
#include "stdafx.h"
#include "alphabeticalsortsharedlib.h"
/*����ϵͳ��Ϣ*/

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
	// Qualifier: ����ϵͳ��Ϣ
	// Parameter: MessageInfo messageInfo
	//************************************
	void ParseSysMessage(MessageInfo messageInfo);

private:
	//************************************
	// Method:    GetExeDir
	// FullName:  ParseSystemMessage::GetExeDir
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: ��ȡ��������·��
	//************************************
	QString GetExeDir();

	//************************************
	// Method:    OnDealUpUser
	// FullName:  ParseSystemMessage::OnDealUpUser
	// Access:    private 
	// Returns:   void
	// Qualifier: ������º�����Ϣ
	// Parameter: QVariantMap mapResult
	//************************************
	void OnDealUpDateUser(MessageInfo msgInfo, QVariantMap mapResult);

	//************************************
	// Method:    OnDealUpdateGroupInfo
	// FullName:  ParseSystemMessage::OnDealUpdateGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ����Ⱥ����Ϣ
	// Parameter: GroupInfo groupInfo
	//************************************
	void OnDealUpdateGroupInfo(QVariantMap mapResult);

	//************************************
	// Method:    OnDealUserQuitGroup
	// FullName:  ParseSystemMessage::OnDealUserQuitGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: �����û��˳�Ⱥ��
	// Parameter: QVariantMap mapResult
	//************************************
	void OnDealUserQuitGroup(QVariantMap mapResult);

	//************************************
	// Method:    OnDealAddFriend
	// FullName:  ParseSystemMessage::OnDealAddFriend
	// Access:    private 
	// Returns:   void 
	// Qualifier: ��Ӻ���
	// Parameter: QVariantMap result
	//************************************
	void OnDealAddFriend(QVariantMap result);

	//************************************
	// Method:    OnDealAddUserToGroup
	// FullName:  ParseSystemMessage::OnDealAddUserToGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: �������Ⱥ��ɹ�
	// Parameter: QVariantMap result
	//************************************
	void OnDealAddUserToGroup(QVariantMap result);

	//��ɢȺ��
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
	// Qualifier: �����û���Ϣ
	// Parameter: UserInfo userInfo
	//************************************
	void sigUpdateUserInfo(UserInfo userInfo);

	//************************************
	// Method:    sigUpdateBuddyInfo
	// FullName:  ParseSystemMessage::sigUpdateBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ���º�����Ϣ
	// Parameter: BuddyInfo
	//************************************
	void sigUpdateInfo(int,QVariant);

	//************************************
	// Method:    sigAddFriendSuccess
	// FullName:  ParseSystemMessage::sigAddFriendSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: ��Ӻ��ѳɹ�
	//************************************
	void sigAddFriendSuccess(BuddyInfo);

	//************************************
	// Method:    sigAddSuccessGroup
	// FullName:  ParseSystemMessage::sigAddSuccessGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: ���Ⱥ��ɹ�
	// Parameter: GroupInfo
	//************************************
	void sigAddSuccessGroup(GroupInfo);

	//************************************
	// Method:    sigAddSuccessGroupUserInfo
	// FullName:  ParseSystemMessage::sigAddSuccessGroupUserInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: /*Ⱥ����ӳ�Ա�ɹ�*/
	// Parameter: QString strGroupID
	// Parameter: BuddyInfo buddy
	//************************************
	void sigAddSuccessGroupUserInfo(QString strGroupID, BuddyInfo buddy);

	//************************************
	// Method:    sigUserQuitGroup
	// FullName:  ParseSystemMessage::sigUserQuitGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: �û��˳�Ⱥ����Ϣ
	// Parameter: QString groupID
	// Parameter: QString userID
	//************************************
	void sigUserQuitGroup(QString groupID, QString userID);
private:
	AlphabeticalSortSharedLib mAlphabeticalSort;   //���ݺ��ַ�������ĸƴ��
};

#endif // PARSESYSTEMMESSAGE_H
