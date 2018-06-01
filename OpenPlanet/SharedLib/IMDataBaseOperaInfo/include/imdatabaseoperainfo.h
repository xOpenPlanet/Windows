#ifndef IMDATABASEOPERAINFO_H
#define IMDATABASEOPERAINFO_H

/*联信数据库操作类*/
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
	// Qualifier: 连接数据库
	// Parameter: QString strDBPath
	// Parameter: QString strDBName
	//************************************
	void ConnectDB(QString strDBPath, QString strDBName);

	//************************************
	// Method:    DBGetBuddyInfo
	// FullName:  IMDataBaseOperaInfo::DBGetBuddyInfo
	// Access:    public 
	// Returns:   QMap<QString, QList<BuddyInfo> >
	// Qualifier: 获取全部好友信息
	//************************************
	QList<BuddyInfo> DBGetBuddyInfo();

	//************************************
	// Method:    DBInsertGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertGroupInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 插入群组信息
	// Parameter: GroupInfo groupInfo
	//************************************
	void DBInsertGroupInfo(GroupInfo groupInfo);

	//************************************
	// Method:    DBInsertGroupBuddyInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertGroupBuddyInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 数据库插入好友信息
	// Parameter: QString strGroupID
	// Parameter: BuddyInfo buddyInfo
	//************************************
	void DBInsertGroupBuddyInfo(QString strGroupID, BuddyInfo buddyInfo);

	//************************************
	// Method:    DBGetGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBGetGroupInfo
	// Access:    public 
	// Returns:   QMap<GroupInfo, QList<BuddyInfo> >
	// Qualifier: 获取群组信息
	//************************************
	QMap<GroupInfo, QList<BuddyInfo> > DBGetGroupInfo();

	//************************************
	// Method:    DBGetGroupFromID
	// FullName:  IMDataBaseOperaInfo::DBGetGroupFromID
	// Access:    public 
	// Returns:   GroupInfo
	// Qualifier: 根据群组ID获取群组信息
	// Parameter: QString strGroupID
	//************************************
	GroupInfo DBGetGroupFromID(QString strGroupID);

	//************************************
	// Method:    DBGetGroupBuddyInfoFromID
	// FullName:  IMDataBaseOperaInfo::DBGetGroupBuddyInfoFromID
	// Access:    public 
	// Returns:   QList<BuddyInfo>
	// Qualifier: 获取群组中的好友信息
	// Parameter: QString strGroupID
	//************************************
	QList<BuddyInfo> DBGetGroupBuddyInfoFromID(QString strGroupID);

	//************************************
	// Method:    DBUpdateGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBUpdateGroupInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新群组信息
	// Parameter: GroupInfo groupInfo
	//************************************
	void DBUpdateGroupInfo(GroupInfo groupInfo);

	//************************************
	// Method:    DBGetBuddyInfoByID
	// FullName:  IMDataBaseOperaInfo::DBGetBuddyInfoByID
	// Access:    public 
	// Returns:   BuddyInfo
	// Qualifier: 根据好友ID 查找好友信息
	// Parameter: QString nUserID
	//************************************
	BuddyInfo DBGetBuddyInfoByID(QString nUserID);

	//************************************
	// Method:    DBGetGroupUserFromID
	// FullName:  IMDataBaseOperaInfo::DBGetGroupUserFromID
	// Access:    public 
	// Returns:   BuddyInfo
	// Qualifier: //根据userid查询某个人的信息（常用于查询群组里面的非好友的信息，只能通过这个方法）
	// Parameter: QString nUserID
	//************************************
	BuddyInfo DBGetGroupUserFromID(QString nUserID);

	//************************************
	// Method:    DBSearchBuddyInfo
	// FullName:  IMDataBaseOperaInfo::DBSearchBuddyInfo
	// Access:    public 
	// Returns:   QList<BuddyInfo>
	// Qualifier: 根据字符串搜索好友信息的方法。
	// Parameter: int userid
	// Parameter: QString key
	//************************************
	QList<BuddyInfo> DBSearchBuddyInfo(int userid, QString key);

	//************************************
	// Method:    DBSearchGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBSearchGroupInfo
	// Access:    public 
	// Returns:   QList<GroupInfo>
	// Qualifier: 根据字符串搜索群组信息的方法。
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
	// Qualifier: 更新群组成员头像
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
	// Qualifier: 删除好友信息
	// Parameter: QString strBuddyID
	// Parameter: QString strUserID
	//************************************
	void DBDeleteBuddyInfoByID(QString strBuddyID);

	//************************************
	// Method:    DBDeleteGroupUserByID
	// FullName:  IMDataBaseOperaInfo::DBDeleteGroupUserByID
	// Access:    public 
	// Returns:   void
	// Qualifier: 删除群组成员
	// Parameter: QString strBuddyID
	// Parameter: QString strUserID
	//************************************
	void DBDeleteGroupUserByID(QString strBuddyID, QString strUserID);

	//************************************
	// Method:    DBDeleteGroupInfoByID
	// FullName:  IMDataBaseOperaInfo::DBDeleteGroupInfoByID
	// Access:    public 
	// Returns:   void
	// Qualifier: 删除群组信息
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
	// Qualifier: 数据库插入组织树
	// Parameter: OrgStruct orgStruct
	//************************************
	void DBInsertOrgTree(OrgStruct orgStruct);

	//************************************
	// Method:    DBGetOrgTree
	// FullName:  IMDataBaseOperaInfo::DBGetOrgTree
	// Access:    public 
	// Returns:   QList<OrgStruct>
	// Qualifier: 获取组织树
	// Parameter: QString bh
	//************************************
	QList<OrgStruct> DBGetOrgTree(QString bh);

	//************************************
	// Method:    DisConnectDB
	// FullName:  IMDataBaseOperaInfo::DisConnectDB
	// Access:    public 
	// Returns:   void
	// Qualifier: 与数据库断开连接
	//************************************
	void DisConnectDB();

	//************************************
	// Method:    DBOnInsertFileInfo
	// FullName:  IMDataBaseOperaInfo::DBOnInsertFileInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 插入数据库接收文件信息
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
	// Qualifier: 获取接收文件的本地地址
	// Parameter: int nUserID
	// Parameter: QString strMsgID
	//************************************
	QString DBGetFileInfoLocalPath(QString strMsgID);

	//************************************
	// Method:    DBInsertBuddyInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertBuddyInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 插入好友信息
	// Parameter: BuddyInfo buddyInfo
	//************************************
	void DBInsertBuddyInfo(BuddyInfo buddyInfo);

	void DBInsertBuddyInfo(QList<BuddyInfo>);

	//************************************
	// Method:    DBInsertPerMessageListInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertPerMessageListInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 个人消息列表中展示的内容
	// Parameter: MessageListInfo messagelist
	//************************************
	void DBInsertPerMessageListInfo(MessageListInfo messagelist);

	//************************************
	// Method:    DBInsertGroupMessageListInfo
	// FullName:  IMDataBaseOperaInfo::DBInsertGroupMessageListInfo
	// Access:    public 
	// Returns:   void
	// Qualifier:群组消息列表中展示的内容
	// Parameter: MessageListInfo messagelist
	//************************************
	void DBInsertGroupMessageListInfo(MessageListInfo messagelist);

	//************************************
	// Method:    DBUpdateMessageListInfo
	// FullName:  IMDataBaseOperaInfo::DBUpdateMessageListInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新消息列表中数据
	// Parameter: int nBuddyID
	//************************************
	void DBUpdateMessageListInfo(int nBuddyID);

	//************************************
	// Method:    DBDeleteMessageByID
	// FullName:  IMDataBaseOperaInfo::DBDeleteMessageByID
	// Access:    public 
	// Returns:   void
	// Qualifier: 删除某人的聊天
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
	// Qualifier: 根据ID判断是否是好友
	// Parameter: QString strUserID
	//************************************
	bool DBJudgeBuddyIsHaveByID(QString strUserID);

	bool DBJudgeFriendIsHaveByID(QString strUserID);

	//************************************
	// Method:    DBJudgetGroupBuddyIsEmpty
	// FullName:  IMDataBaseOperaInfo::DBJudgetGroupBuddyIsEmpty
	// Access:    public 
	// Returns:   bool
	// Qualifier: 判断群组成员是否为空
	// Parameter: QString strGroupID
	//************************************
	bool DBJudgetGroupBuddyIsEmpty(QString strGroupID);

	//************************************
	// Method:    DBGetALLMessageListInfo
	// FullName:  IMDataBaseOperaInfo::DBGetALLMessageListInfo
	// Access:    public 
	// Returns:   QList<MessageListInfo>
	// Qualifier: 获取全部的消息列表数据
	//************************************
	QList<MessageListInfo> DBGetALLMessageListInfo();

	//************************************
	// Method:    DBJudgeBuddyIsEmpty
	// FullName:  IMDataBaseOperaInfo::DBJudgeBuddyIsEmpty
	// Access:    public 
	// Returns:   bool
	// Qualifier: 判断好友列表是否为空
	//************************************
	bool DBJudgeBuddyIsEmpty();

	//************************************
	// Method:    DBJudgeGroupIsHaveByID
	// FullName:  IMDataBaseOperaInfo::DBJudgeGroupIsHaveByID
	// Access:    public 
	// Returns:   bool
	// Qualifier: 根据群组ID判断是否有该群组
	// Parameter: QString strGroupID
	//************************************
	bool DBJudgeGroupIsHaveByID(QString strGroupID);

	//************************************
	// Method:    DBJudgeGroupIsHaveBuddy
	// FullName:  IMDataBaseOperaInfo::DBJudgeGroupIsHaveBuddy
	// Access:    public 
	// Returns:   bool
	// Qualifier: 判断群组中是否有该成员
	// Parameter: QString strGroupID
	// Parameter: QString strBuddyID
	//************************************
	bool DBJudgeGroupIsHaveBuddy(QString strGroupID, QString strBuddyID);

	//************************************
	// Method:    DBGetGroupBuddyInfoWithGroupBuddyID
	// FullName:  IMDataBaseOperaInfo::DBGetGroupBuddyInfoWithGroupBuddyID
	// Access:    public 
	// Returns:   BuddyInfo
	// Qualifier: 根据群组ID，成员ID 获取成员信息
	// Parameter: QString strGroupID
	// Parameter: QString strBuddyID
	//************************************
	BuddyInfo DBGetGroupBuddyInfoWithGroupBuddyID(QString strGroupID, QString strBuddyID);
	
	//************************************
	// Method:    DBGetAllGroupInfo
	// FullName:  IMDataBaseOperaInfo::DBGetAllGroupInfo
	// Access:    public 
	// Returns:   QList<GroupInfo>
	// Qualifier://获取群组信息
	//************************************
	QList<GroupInfo> DBGetAllGroupInfo();

	//************************************
	// Method:    DBJudgetGroupIsEmpty
	// FullName:  IMDataBaseOperaInfo::DBJudgetGroupIsEmpty
	// Access:    public 
	// Returns:   bool
	// Qualifier: 判断群组是否为空
	//************************************
	bool DBJudgetGroupIsEmpty();
	QMap<QString, QList<BuddyInfo>> DB_GetBuddyInfo();
private:
	SqlLiteShareLib *mDateBase;
};

#endif // IMDATABASEOPERAINFO_H
