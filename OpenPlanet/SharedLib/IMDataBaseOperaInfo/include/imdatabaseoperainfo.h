#ifndef IMDATABASEOPERAINFO_H
#define IMDATABASEOPERAINFO_H

/*�������ݿ������*/
#include "sqllitesharelib.h"
#include "imbuddy.h"

class IMDataBaseOperaInfo
{
public:
	IMDataBaseOperaInfo();
	~IMDataBaseOperaInfo();

	//************************************
	// Method:    ConnectDB
	// FullName:  JFDataBaseOpera::ConnectDB
	// Access:    public 
	// Returns:   void
	// Qualifier: �������ݿ�
	// Parameter: QString strDBPath
	// Parameter: QString strDBName
	//************************************
	void ConnectDB(QString strDBPath, QString strDBName);

	//************************************
	// Method:    DBGetBuddyInfo
	// FullName:  IMDataBaseOperaInfo::DBGetBuddyInfo
	// Access:    public 
	// Returns:   QMap<QString, QList<BuddyInfo> >
	// Qualifier: ��ȡȫ��������Ϣ
	//************************************
	QList<BuddyInfo> DBGetBuddyInfo();

	//************************************
	// Method:    DBInsertGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertGroupInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ����Ⱥ����Ϣ
	// Parameter: GroupInfo groupInfo
	//************************************
	void DBInsertGroupInfo(GroupInfo groupInfo);

	//************************************
	// Method:    DBInsertGroupBuddyInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertGroupBuddyInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ���ݿ���������Ϣ
	// Parameter: QString strGroupID
	// Parameter: BuddyInfo buddyInfo
	//************************************
	void DBInsertGroupBuddyInfo(QString strGroupID, BuddyInfo buddyInfo);

	//************************************
	// Method:    DBGetGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBGetGroupInfo
	// Access:    public 
	// Returns:   QMap<GroupInfo, QList<BuddyInfo> >
	// Qualifier: ��ȡȺ����Ϣ
	//************************************
	QMap<GroupInfo, QList<BuddyInfo> > DBGetGroupInfo();

	//************************************
	// Method:    DBGetGroupFromID
	// FullName:  IMDataBaseOperaInfo::DBGetGroupFromID
	// Access:    public 
	// Returns:   GroupInfo
	// Qualifier: ����Ⱥ��ID��ȡȺ����Ϣ
	// Parameter: QString strGroupID
	//************************************
	GroupInfo DBGetGroupFromID(QString strGroupID);

	//************************************
	// Method:    DBGetGroupBuddyInfoFromID
	// FullName:  IMDataBaseOperaInfo::DBGetGroupBuddyInfoFromID
	// Access:    public 
	// Returns:   QList<BuddyInfo>
	// Qualifier: ��ȡȺ���еĺ�����Ϣ
	// Parameter: QString strGroupID
	//************************************
	QList<BuddyInfo> DBGetGroupBuddyInfoFromID(QString strGroupID);

	//************************************
	// Method:    DBUpdateGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBUpdateGroupInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ����Ⱥ����Ϣ
	// Parameter: GroupInfo groupInfo
	//************************************
	void DBUpdateGroupInfo(GroupInfo groupInfo);

	//************************************
	// Method:    DBGetBuddyInfoByID
	// FullName:  IMDataBaseOperaInfo::DBGetBuddyInfoByID
	// Access:    public 
	// Returns:   BuddyInfo
	// Qualifier: ���ݺ���ID ���Һ�����Ϣ
	// Parameter: QString nUserID
	//************************************
	BuddyInfo DBGetBuddyInfoByID(QString nUserID);

	//************************************
	// Method:    DBGetGroupUserFromID
	// FullName:  IMDataBaseOperaInfo::DBGetGroupUserFromID
	// Access:    public 
	// Returns:   BuddyInfo
	// Qualifier: //����userid��ѯĳ���˵���Ϣ�������ڲ�ѯȺ������ķǺ��ѵ���Ϣ��ֻ��ͨ�����������
	// Parameter: QString nUserID
	//************************************
	BuddyInfo DBGetGroupUserFromID(QString nUserID);

	//************************************
	// Method:    DBSearchBuddyInfo
	// FullName:  IMDataBaseOperaInfo::DBSearchBuddyInfo
	// Access:    public 
	// Returns:   QList<BuddyInfo>
	// Qualifier: �����ַ�������������Ϣ�ķ�����
	// Parameter: int userid
	// Parameter: QString key
	//************************************
	QList<BuddyInfo> DBSearchBuddyInfo(int userid, QString key);

	//************************************
	// Method:    DBSearchGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBSearchGroupInfo
	// Access:    public 
	// Returns:   QList<GroupInfo>
	// Qualifier: �����ַ�������Ⱥ����Ϣ�ķ�����
	// Parameter: int userId
	// Parameter: QString key
	//************************************
	QList<GroupInfo> DBSearchGroupInfo(int userId, QString key);

	//************************************
	// Method:    DBSearchGroupUser
	// FullName:  IMDataBaseOperaInfo::DBSearchGroupUser
	// Access:    public 
	// Returns:   QList<BuddyInfo>
	// Qualifier: 
	// Parameter: int groupID
	// Parameter: QString key
	//************************************
	QList<BuddyInfo> DBSearchGroupUser(int groupID, QString key);

	//************************************
	// Method:    DBUpdateGroupBuddyHeaderImg
	// FullName:  IMDataBaseOperaInfo::DBUpdateGroupBuddyHeaderImg
	// Access:    public 
	// Returns:   void
	// Qualifier: ����Ⱥ���Աͷ��
	// Parameter: QString strBuddyID
	// Parameter: QString strGroupID
	// Parameter: QString strPath
	//************************************
	void DBUpdateGroupBuddyHeaderImg(QString strBuddyID, QString strGroupID, QString strPath);

	//************************************
	// Method:    DBDeleteBuddyInfoByID
	// FullName:  IMDataBaseOperaInfo::DBDeleteBuddyInfoByID
	// Access:    public 
	// Returns:   void
	// Qualifier: ɾ��������Ϣ
	// Parameter: QString strBuddyID
	// Parameter: QString strUserID
	//************************************
	void DBDeleteBuddyInfoByID(QString strBuddyID);

	//************************************
	// Method:    DBDeleteGroupUserByID
	// FullName:  IMDataBaseOperaInfo::DBDeleteGroupUserByID
	// Access:    public 
	// Returns:   void
	// Qualifier: ɾ��Ⱥ���Ա
	// Parameter: QString strBuddyID
	// Parameter: QString strUserID
	//************************************
	void DBDeleteGroupUserByID(QString strBuddyID, QString strUserID);

	//************************************
	// Method:    DBDeleteGroupInfoByID
	// FullName:  IMDataBaseOperaInfo::DBDeleteGroupInfoByID
	// Access:    public 
	// Returns:   void
	// Qualifier: ɾ��Ⱥ����Ϣ
	// Parameter: QString strBuddyID
	// Parameter: QString strUserID
	//************************************
	void DBDeleteGroupInfoByID(QString strBuddyID);

	QList<ApplyMessage> DBGetApplyMessageList();
	void DBInsertApplyMessage(ApplyMessage);
	void DBApplyMessageRead(QString applyId, QString groupId = "");

	//************************************
	// Method:    DBInsertOrgTree
	// FullName:  IMDataBaseOperaInfo::DBInsertOrgTree
	// Access:    public 
	// Returns:   void
	// Qualifier: ���ݿ������֯��
	// Parameter: OrgStruct orgStruct
	//************************************
	void DBInsertOrgTree(OrgStruct orgStruct);

	//************************************
	// Method:    DBGetOrgTree
	// FullName:  IMDataBaseOperaInfo::DBGetOrgTree
	// Access:    public 
	// Returns:   QList<OrgStruct>
	// Qualifier: ��ȡ��֯��
	// Parameter: QString bh
	//************************************
	QList<OrgStruct> DBGetOrgTree(QString bh);

	//************************************
	// Method:    DisConnectDB
	// FullName:  IMDataBaseOperaInfo::DisConnectDB
	// Access:    public 
	// Returns:   void
	// Qualifier: �����ݿ�Ͽ�����
	//************************************
	void DisConnectDB();

	//************************************
	// Method:    DBOnInsertFileInfo
	// FullName:  IMDataBaseOperaInfo::DBOnInsertFileInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: �������ݿ�����ļ���Ϣ
	// Parameter: int nUserID
	// Parameter: QString strMsgID
	// Parameter: QString strFileLocalPath
	// Parameter: QString strFileHttpPath
	//************************************
	void DBOnInsertFileInfo(QString strMsgID, QString strFileLocalPath, QString strFileHttpPath);

	//************************************
	// Method:    DBGetFileInfoLocalPath
	// FullName:  IMDataBaseOperaInfo::DBGetFileInfoLocalPath
	// Access:    public 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: ��ȡ�����ļ��ı��ص�ַ
	// Parameter: int nUserID
	// Parameter: QString strMsgID
	//************************************
	QString DBGetFileInfoLocalPath(QString strMsgID);

	//************************************
	// Method:    DBInsertBuddyInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertBuddyInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ���������Ϣ
	// Parameter: BuddyInfo buddyInfo
	//************************************
	void DBInsertBuddyInfo(BuddyInfo buddyInfo);

	void DBInsertBuddyInfo(QList<BuddyInfo>);

	//************************************
	// Method:    DBInsertPerMessageListInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertPerMessageListInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ������Ϣ�б���չʾ������
	// Parameter: MessageListInfo messagelist
	//************************************
	void DBInsertPerMessageListInfo(MessageListInfo messagelist);

	//************************************
	// Method:    DBInsertGroupMessageListInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertGroupMessageListInfo
	// Access:    public 
	// Returns:   void
	// Qualifier:Ⱥ����Ϣ�б���չʾ������
	// Parameter: MessageListInfo messagelist
	//************************************
	void DBInsertGroupMessageListInfo(MessageListInfo messagelist);

	//************************************
	// Method:    DBUpdateMessageListInfo
	// FullName:  IMDataBaseOperaInfo::DBUpdateMessageListInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ������Ϣ�б�������
	// Parameter: int nBuddyID
	//************************************
	void DBUpdateMessageListInfo(int nBuddyID);

	//************************************
	// Method:    DBDeleteMessageByID
	// FullName:  IMDataBaseOperaInfo::DBDeleteMessageByID
	// Access:    public 
	// Returns:   void
	// Qualifier: ɾ��ĳ�˵�����
	// Parameter: QString userID
	//************************************
	void DBDeleteMessageByID(QString userID);

	//************************************
	// Method:    DBClearAllMessageList
	// FullName:  IMDataBaseOperaInfo::DBClearAllMessageList
	// Access:    public 
	// Returns:   void
	// Qualifier:
	//************************************
	void DBClearAllMessageList();

	//************************************
	// Method:    DBJudgeBuddyIsHaveByID
	// FullName:  IMDataBaseOperaInfo::DBJudgeBuddyIsHaveByID
	// Access:    public 
	// Returns:   bool
	// Qualifier: ����ID�ж��Ƿ��Ǻ���
	// Parameter: QString strUserID
	//************************************
	bool DBJudgeBuddyIsHaveByID(QString strUserID);

	bool DBJudgeFriendIsHaveByID(QString strUserID);

	//************************************
	// Method:    DBJudgetGroupBuddyIsEmpty
	// FullName:  IMDataBaseOperaInfo::DBJudgetGroupBuddyIsEmpty
	// Access:    public 
	// Returns:   bool
	// Qualifier: �ж�Ⱥ���Ա�Ƿ�Ϊ��
	// Parameter: QString strGroupID
	//************************************
	bool DBJudgetGroupBuddyIsEmpty(QString strGroupID);

	//************************************
	// Method:    DBGetALLMessageListInfo
	// FullName:  IMDataBaseOperaInfo::DBGetALLMessageListInfo
	// Access:    public 
	// Returns:   QList<MessageListInfo>
	// Qualifier: ��ȡȫ������Ϣ�б�����
	//************************************
	QList<MessageListInfo> DBGetALLMessageListInfo();

	//************************************
	// Method:    DBJudgeBuddyIsEmpty
	// FullName:  IMDataBaseOperaInfo::DBJudgeBuddyIsEmpty
	// Access:    public 
	// Returns:   bool
	// Qualifier: �жϺ����б��Ƿ�Ϊ��
	//************************************
	bool DBJudgeBuddyIsEmpty();

	//************************************
	// Method:    DBJudgeGroupIsHaveByID
	// FullName:  IMDataBaseOperaInfo::DBJudgeGroupIsHaveByID
	// Access:    public 
	// Returns:   bool
	// Qualifier: ����Ⱥ��ID�ж��Ƿ��и�Ⱥ��
	// Parameter: QString strGroupID
	//************************************
	bool DBJudgeGroupIsHaveByID(QString strGroupID);

	//************************************
	// Method:    DBJudgeGroupIsHaveBuddy
	// FullName:  IMDataBaseOperaInfo::DBJudgeGroupIsHaveBuddy
	// Access:    public 
	// Returns:   bool
	// Qualifier: �ж�Ⱥ�����Ƿ��иó�Ա
	// Parameter: QString strGroupID
	// Parameter: QString strBuddyID
	//************************************
	bool DBJudgeGroupIsHaveBuddy(QString strGroupID, QString strBuddyID);

	//************************************
	// Method:    DBGetGroupBuddyInfoWithGroupBuddyID
	// FullName:  IMDataBaseOperaInfo::DBGetGroupBuddyInfoWithGroupBuddyID
	// Access:    public 
	// Returns:   BuddyInfo
	// Qualifier: ����Ⱥ��ID����ԱID ��ȡ��Ա��Ϣ
	// Parameter: QString strGroupID
	// Parameter: QString strBuddyID
	//************************************
	BuddyInfo DBGetGroupBuddyInfoWithGroupBuddyID(QString strGroupID, QString strBuddyID);
	
	//************************************
	// Method:    DBGetAllGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBGetAllGroupInfo
	// Access:    public 
	// Returns:   QList<GroupInfo>
	// Qualifier://��ȡȺ����Ϣ
	//************************************
	QList<GroupInfo> DBGetAllGroupInfo();

	//************************************
	// Method:    DBJudgetGroupIsEmpty
	// FullName:  IMDataBaseOperaInfo::DBJudgetGroupIsEmpty
	// Access:    public 
	// Returns:   bool
	// Qualifier: �ж�Ⱥ���Ƿ�Ϊ��
	//************************************
	bool DBJudgetGroupIsEmpty();
	QMap<QString, QList<BuddyInfo>> DB_GetBuddyInfo();
private:
	SqlLiteShareLib *mDateBase;
};

#endif // IMDATABASEOPERAINFO_H
