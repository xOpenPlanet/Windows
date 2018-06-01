#ifndef IMSOCKETDATABASESHARELIB_H
#define IMSOCKETDATABASESHARELIB_H

/*��Ϣ���ݿ�*/
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
	// Qualifier: �������ݿ�
	//************************************
	bool ConnectDB(QString strDBPath, QString strDBName, QString strPsw="");

	//************************************
	// Method:    DisConnectDB
	// FullName:  JFDataOpera::DisConnectDB
	// Access:    public 
	// Returns:   void
	// Qualifier: �Ͽ�����
	//************************************
	void DisConnectDB();

	//************************************
	// Method:    InserMessageInfo
	// FullName:  JFDataBaseOpera::InserMessageInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: �����ݿ��в�����Ϣ
	// Parameter: int nUserID
	// Parameter: MessageInfo
	//************************************
	void InserMessageInfo(int nSelfID, int nUserID, MessageInfo messageInfo);

	//************************************
	// Method:    GetAllMessage
	// FullName:  JFDataBaseOpera::GetAllMessage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: ��ȡ���е���Ϣ
	//************************************
	QMap<QString, QList<MessageInfo> > GetAllMessage(int nSelfID);

	//************************************
	// Method:    GetDBCurrentDayMessage
	// FullName:  IMSocketDataBaseShareLib::GetDBCurrentDayMessage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: ��ȡ�������Ϣ
	// Parameter: int nSelfID
	//************************************
	QMap<QString, QList<MessageInfo> > GetDBCurrentDayMessage(int nSelfID);

	//************************************
	// Method:    GetDBUnSendMessageInfo
	// FullName:  JFDataBaseOpera::GetDBUnSendMessageInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ȡ���ݿ���δ���ͳɹ�����Ϣ
	//************************************
	void GetDBUnSendMessageInfo(int nSelfID);

	//************************************
	// Method:    UpdataMessageStateInfo
	// FullName:  IMSocketDataBaseShareLib::UpdataMessageStateInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: �������ݿ�����Ϣ״̬
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void UpdataMessageStateInfo(QByteArray msgID, int nState, int integral);

	//************************************
	// Method:    GetDBMessageInfoWithMsgID
	// FullName:  IMSocketDBManager::GetDBMessageInfoWithMsgID
	// Access:    public 
	// Returns:   MessageInfo
	// Qualifier: ����MsgID��ȡMessageInfo
	// Parameter: int nIMUserID
	// Parameter: QString strMsgID
	//************************************
	MessageInfo GetDBMessageInfoWithMsgID(int nIMUserID, QString strMsgID);

	//************************************
	// Method:    GetDBCurrentDayMessageWithIMUserID
	// FullName:  IMSocketDBManager::GetDBCurrentDayMessageWithIMUserID
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: ��������ID ��ȡ��Ϣ
	// Parameter: int nIMUserID 
	// Parameter: int nChatID
	//************************************
	QMap<QString, QList<MessageInfo> > GetDBCurrentDayMessageWithIMUserID(int nIMUserID, int nChatID);

	//************************************
	// Method:    GetDBMessageRecordPage
	// FullName:  IMSocketDBManager::GetDBMessageRecordPage
	// Access:    public 
	// Returns:   int
	// Qualifier: ���ط�ҳ��ҳ��
	// Parameter: int nChatID
	// Parameter: int nPageNum
	//************************************
	int GetDBMessageRecordPageNum(int nChatID, int nPageNum);

	//************************************
	// Method:    GetDBMessageRecordByPage
	// FullName:  IMSocketDBManager::GetDBMessageRecordByPage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: ����ҳ���ȡ��Ϣ��¼
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
	// Qualifier: ��ȡ�����ķ�ҳҳ��
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
	// Qualifier: ����ҳ����ȡ�����Ľ��
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
	// Qualifier: ��ȡ���һ����Ϣ
	// Parameter: int nIMUserID
	//************************************
	QString DBGetMessageLastTime(int nIMUserID);
private:
	SqlLiteShareLib *mSocketDB;
	QString strSql;
	int mPageNum;          //��Ϣÿһҳ������
	int mSearchPageNum;    //������Ϣÿһҳ������
	QString mSearchMsg;    //������Ϣ�ֶ�
};

#endif // IMSOCKETDATABASESHARELIB_H
