#ifndef IMSOCKETDATABASESHARELIB_H
#define IMSOCKETDATABASESHARELIB_H

/*消息数据库*/
#include "sqllitesharelib.h"
#include "imusermessage.h"

class IMSocketDataBaseShareLib
{
public:
	IMSocketDataBaseShareLib();
	~IMSocketDataBaseShareLib();

	//************************************
	// Method:    ConnectDB
	// FullName:  JFDataOpera::ConnectDB
	// Access:    public 
	// Returns:   bool
	// Qualifier: 连接数据库
	//************************************
	bool ConnectDB(QString strDBPath, QString strDBName, QString strPsw="");

	//************************************
	// Method:    DisConnectDB
	// FullName:  JFDataOpera::DisConnectDB
	// Access:    public 
	// Returns:   void
	// Qualifier: 断开连接
	//************************************
	void DisConnectDB();

	//************************************
	// Method:    InserMessageInfo
	// FullName:  JFDataBaseOpera::InserMessageInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 向数据库中插入消息
	// Parameter: int nUserID
	// Parameter: MessageInfo
	//************************************
	void InserMessageInfo(int nSelfID, int nUserID, MessageInfo messageInfo);

	//************************************
	// Method:    GetAllMessage
	// FullName:  JFDataBaseOpera::GetAllMessage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: 获取所有的消息
	//************************************
	QMap<QString, QList<MessageInfo> > GetAllMessage(int nSelfID);

	//************************************
	// Method:    GetDBCurrentDayMessage
	// FullName:  IMSocketDataBaseShareLib::GetDBCurrentDayMessage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: 获取当天的消息
	// Parameter: int nSelfID
	//************************************
	QMap<QString, QList<MessageInfo> > GetDBCurrentDayMessage(int nSelfID);

	//************************************
	// Method:    GetDBUnSendMessageInfo
	// FullName:  JFDataBaseOpera::GetDBUnSendMessageInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 获取数据库中未发送成功的消息
	//************************************
	void GetDBUnSendMessageInfo(int nSelfID);

	//************************************
	// Method:    UpdataMessageStateInfo
	// FullName:  IMSocketDataBaseShareLib::UpdataMessageStateInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新数据库中消息状态
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void UpdataMessageStateInfo(QByteArray msgID, int nState, int integral);

	//************************************
	// Method:    GetDBMessageInfoWithMsgID
	// FullName:  IMSocketDBManager::GetDBMessageInfoWithMsgID
	// Access:    public 
	// Returns:   MessageInfo
	// Qualifier: 根据MsgID获取MessageInfo
	// Parameter: int nIMUserID
	// Parameter: QString strMsgID
	//************************************
	MessageInfo GetDBMessageInfoWithMsgID(int nIMUserID, QString strMsgID);

	//************************************
	// Method:    GetDBCurrentDayMessageWithIMUserID
	// FullName:  IMSocketDBManager::GetDBCurrentDayMessageWithIMUserID
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: 根据联信ID 获取消息
	// Parameter: int nIMUserID 
	// Parameter: int nChatID
	//************************************
	QMap<QString, QList<MessageInfo> > GetDBCurrentDayMessageWithIMUserID(int nIMUserID, int nChatID);

	//************************************
	// Method:    GetDBMessageRecordPage
	// FullName:  IMSocketDBManager::GetDBMessageRecordPage
	// Access:    public 
	// Returns:   int
	// Qualifier: 返回分页的页数
	// Parameter: int nChatID
	// Parameter: int nPageNum
	//************************************
	int GetDBMessageRecordPageNum(int nChatID, int nPageNum);

	//************************************
	// Method:    GetDBMessageRecordByPage
	// FullName:  IMSocketDBManager::GetDBMessageRecordByPage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: 根据页码获取消息记录
	// Parameter: int nChatID
	// Parameter: int nPage
	// Parameter: int messageType
	//************************************
	QList<MessageInfo> GetDBMessageRecordByPage(int nChatID, int nPage, int messageType);

	//************************************
	// Method:    GetSearchMessagePageNum
	// FullName:  IMNetWorkShared::GetSearchMessagePageNum
	// Access:    public 
	// Returns:   int
	// Qualifier: 获取搜索的分页页数
	// Parameter: int nChatID
	// Parameter: QString strLikeMsg
	// Parameter: int nPageNum
	//************************************
	int GetSearchMessagePageNum(int nChatID, QString strLikeMsg, int nPageNum);

	//************************************
	// Method:    GetDBSearchMessageRecordByPage
	// FullName:  IMNetWorkShared::GetDBSearchMessageRecordByPage
	// Access:    public 
	// Returns:   QList<MessageInfo>
	// Qualifier: 根据页数获取搜索的结果
	// Parameter: int nChatID
	// Parameter: int nPage
	// Parameter: int messageType
	//************************************
	QList<MessageInfo> GetDBSearchMessageRecordByPage(int nChatID, int nPage, int messageType);

	//************************************
	// Method:    DBGetMessageLastTime
	// FullName:  IMSocketDataBaseShareLib::DBGetMessageLastTime
	// Access:    public 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: 获取最后一条消息
	// Parameter: int nIMUserID
	//************************************
	QString DBGetMessageLastTime(int nIMUserID);
private:
	SqlLiteShareLib *mSocketDB;
	QString strSql;
	int mPageNum;          //消息每一页的数量
	int mSearchPageNum;    //搜索消息每一页的数量
	QString mSearchMsg;    //搜索消息字段
};

#endif // IMSOCKETDATABASESHARELIB_H
