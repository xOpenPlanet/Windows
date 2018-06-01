#ifndef IMSOCKETMESSAGEINFO_H
#define IMSOCKETMESSAGEINFO_H

#include <QObject>
#include "imsocketnetworksharelib.h"

//ͼƬ��Ϣ
struct PicMessage : QObjectUserData {
	int nFromUserID;
	int nToUserID;
	int nDeliverType;
	QString strUpLoadUrl;
	QString strDownLoadUrl;
	QString strPicPath;
	int nPicHeight;
	int nPicWidth;
};
struct FileMessage : QObjectUserData
{
	int nFromUserID;
	int nToUserID;
	int nDeliverType;
	QString strUpLoadUrl;
	QString strFilePath;
	QString FileType;
	QString FileSize;
	QString FileName;
};
Q_DECLARE_METATYPE(PicMessage)
Q_DECLARE_METATYPE(FileMessage)

typedef struct IM_Server
{
	QString ServerIP;
	QString ServerPort;
	QString ServerToken;
}ServerInfo;

struct RequestSocketInfo       //����socket��Ϣ
{
	QString strUrl;
	QString strUserID;
	QString strPwd;
};

class IMSocketMessageInfo : public QObject
{
	Q_OBJECT

public:
	IMSocketMessageInfo(QObject *parent=0);
	~IMSocketMessageInfo();

	//************************************
	// Method:    RequestSocketUrl
	// FullName:  IMSocketMessageInfo::RequestSocketUrl
	// Access:    public 
	// Returns:   void
	// Qualifier: ����socket��ַ
	// Parameter: QString strUrl
	// Parameter: QString strUserID
	// Parameter: QString strUserPwd
	//************************************
	void RequestSocketUrl(QString strUrl,QString strUserID,QString strUserPwd);

	//************************************
	// Method:    ByteConversion
	// FullName:  IMNetWorkShared::ByteConversion
	// Access:    public 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: �ֽ�ת�� �Զ�������MB ����KB ���� XXMB XXKB XXB
	// Parameter: int nByte
	//************************************
	QString ByteConversion(int nByte);

	//************************************
	// Method:    GetExeDir
	// FullName:  IMSocketMessageInfo::GetExeDir
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: ��ȡ��������·��
	//************************************
	QString GetExeDir();
private:

	//************************************
	// Method:    StitchSocketParameter
	// FullName:  IMSocketMessageInfo::StitchSocketParameter
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: ƴ������socket����
	// Parameter: QString url
	// Parameter: QString AccountName
	// Parameter: QString PassWord
	//************************************
	QString StitchSocketParameter(QString url, QString AccountName, QString PassWord);

	//************************************
	// Method:    OnConnectSocket
	// FullName:  JFMessageManager::OnConnectSocket
	// Access:    public 
	// Returns:   void
	// Qualifier: ����socket
	//************************************
	bool OnConnectSocket(QString strServerIP, QString strServerPort, QString strToken);

	//************************************
	// Method:    ConnectDataBase
	// FullName:  IMSocketNetWorkShareLib::ConnectDataBase
	// Access:    public 
	// Returns:   void
	// Qualifier: �������ݿ�
	//************************************
	void ConnectDataBase();

public:

	//************************************
	// Method:    SendTextMessage
	// FullName:  IMSocketMessageInfo::SendTextMessage
	// Access:    public 
	// Returns:   void 
	// Qualifier: �����ı���Ϣ
	// Parameter: int nFromUserID
	// Parameter: int nToUserID
	// Parameter: int nDeliverType
	// Parameter: short MessageChildType
	// Parameter: QString strMsg
	//************************************
	MessageInfo SendTextMessage(int nFromUserID, int nToUserID, int nDeliverType, short MessageChildType, QString strMsg);

	//************************************
	// Method:    SendMessageReadMessage
	// FullName:  IMSocketMessageInfo::SendMessageReadMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: ������Ϣ�Ѷ�
	// Parameter: int nFromUserID
	// Parameter: int nToUserID
	// Parameter: int nDeliverType
	// Parameter: QString strMsg
	//************************************
	void SendMessageReadMessage(int nFromUserID, int nToUserID, int nDeliverType, QString strMsg);

	//************************************
	// Method:    SendPicMessage
	// FullName:  IMSocketMessageInfo::SendPicMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: ����ͼƬ��Ϣ
	// Parameter: int nFromUserID
	// Parameter: int nToUserID
	// Parameter: int nDeliverType
	// Parameter: short MessageChildType
	// Parameter: QString strMsg
	//************************************
	MessageInfo SendPicMessage(int nFromUserID, int nToUserID, int nDeliverType, QString strMsg);
	//************************************
	// Method:    SendFileMessae
	// FullName:  IMSocketMessageInfo::SendFileMessae
	// Access:    public 
	// Returns:   void
	// Qualifier: �����ļ���Ϣ
	// Parameter: int nFromUserID
	// Parameter: int nToUserID
	// Parameter: int nDeliverType
	// Parameter: short MessageChildType
	// Parameter: QString strMsg
	//************************************
	MessageInfo SendFileMessage(int nFromUserID, int nToUserID, int nDeliverType, QString strMsg);

	// Qualifier: ��������״̬
	void setReConnectState(bool bState);

	//************************************
	// Method:    slotUpFileReplyFinished
	// FullName:  IMSocketMessageInfo::slotUpFileReplyFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: �ϴ��ļ��ɹ�
	// Parameter: bool bResult
	// Parameter: QByteArray result
	//************************************
	void setUpFileReplyFinished(QByteArray result,FileMessage*,MessageInfo);

	//************************************
	// Method:    slotUpFileReplyFinished
	// FullName:  IMSocketMessageInfo::slotUpFileReplyFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: �ϴ�ͼƬ�ļ��ɹ�
	//************************************
	void setUpPicReplyFinished(QByteArray result,PicMessage *,MessageInfo);

	//************************************
	// Method:    SetMessageState
	// FullName:  IMSocketMessageInfo::SetMessageState
	// Access:    public 
	// Returns:   void 
	// Qualifier: ������Ϣ״̬
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void SetMessageState(QByteArray msgID, int nState);

	//************************************
	// Method:    SetIMUserID
	// FullName:  IMNetWorkShared::SetIMUserID
	// Access:    public 
	// Returns:   void
	// Qualifier: ���õ�ǰ��¼��IMUserID
	// Parameter: int nIMID
	//************************************
	void SetIMUserID(int nIMID);

	//************************************
	// Method:    GetDBAllMessage
	// FullName:  IMNetWorkShared::GetDBAllMessage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: ��ȡȫ������Ϣ����
	//************************************
	QMap<QString, QList<MessageInfo> > DBGetAllMessage();

	//************************************
	// Method:    GetDBCurrentDayMessage
	// FullName:  IMNetWorkShared::GetDBCurrentDayMessage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: ��ȡ�������Ϣ
	//************************************
	QMap<QString, QList<MessageInfo> > DBGetCurrentDayMessage();

	//************************************
	// Method:    GetDBCurrentDayMessageWithIMUserID
	// FullName:  IMNetWorkShared::GetDBCurrentDayMessageWithIMUserID
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: ��ȡ����Ի�ID ����Ϣ����
	// Parameter: int nChatID
	//************************************
	QMap<QString, QList<MessageInfo> > DBGetCurrentDayMessageWithIMUserID(int nChatID);


	//************************************
	// Method:    GetDBMessageRecordPage
	// FullName:  IMNetWorkShared::GetDBMessageRecordPage
	// Access:    public 
	// Returns:   int
	// Qualifier: ��ȡ����ID�µ���Ϣҳ��
	// Parameter: int nChatID  ����ID
	// Parameter: int nPageNum  ÿһҳ��Ϣ���� Ĭ��20
	//************************************
	int DBGetMessageRecordPageNum(int nChatID, int nPageNum = 20);

	//************************************
	// Method:    GetDBMessageRecord
	// FullName:  IMNetWorkShared::GetDBMessageRecord
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: ��ȡ��Ϣ��¼����
	// Parameter: int nChatID     ����ID
	// Parameter: int nPage   ҳ��
	// Parameter: int messageType    ��ȡ��Ϣ������
	//************************************
	QList<MessageInfo> DBGetMessageRecordByPage(int nChatID, int nPage = 0, int messageType = MessageRecordAll);


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
	int DBGetSearchMessagePageNum(int nChatID, QString strLikeMsg, int nPageNum = 20);

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
	QList<MessageInfo> DBGetSearchMessageRecordByPage(int nChatID, int nPage = 0, int messageType = MessageRecordAll);

	//************************************
	// Method:    GetDBMessageInfoWithMsgID
	// FullName:  IMNetWorkShared::GetDBMessageInfoWithMsgID
	// Access:    public 
	// Returns:   MessageInfo
	// Qualifier: ����MessageID��ȡ���ݿ���Ϣ
	// Parameter: QString strMsgID
	//************************************
	MessageInfo DBGetMessageInfoWithMsgID(QString strMsgID);

	//************************************
	// Method:    SetPerMessageRead
	// FullName:  IMSocketMessageInfo::SetPerMessageRead
	// Access:    public 
	// Returns:   QList<QByteArray>
	// Qualifier: ���ø�����Ϣ�Ѷ�
	// Parameter: int nUserID
	//************************************
	QList<QByteArray> SetPerMessageRead(int nUserID);

	//************************************
	// Method:    SetGroupMessageRead
	// FullName:  IMSocketMessageInfo::SetGroupMessageRead
	// Access:    public 
	// Returns:   QList<QByteArray>
	// Qualifier: ����Ⱥ����Ϣ�Ѷ�
	// Parameter: int nGroupID
	//************************************
	QList<QByteArray> SetGroupMessageRead(int nGroupID);
private:
	//************************************
	// Method:    ParseSocketInfo
	// FullName:  IMSocketMessageInfo::ParseSocketInfo
	// Access:    private 
	// Returns:   bool
	// Qualifier: ����socket��Ϣ
	// Parameter: QString socketInfo
	//************************************
	bool ParseSocketInfo(QString socketInfo);

	//************************************
	// Method:    SendMessage
	// FullName:  IMSocketMessageInfo::SendMessage
	// Access:    public 
	// Returns:   MessageInfo
	// Qualifier: ������Ϣ
	// Parameter: int nFromUserID
	// Parameter: int nToUserID
	// Parameter: int nDeliverType
	// Parameter: short MessageChildType
	// Parameter: QString strMsg
	//************************************
	MessageInfo SendMessage(int nFromUserID, int nToUserID, int nDeliverType, short MessageChildType, int nMessageState, QString strMsg);

	//************************************
	// Method:    GetMessageLastTime
	// FullName:  JFDataManager::GetMessageLastTime
	// Access:    public 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: ��ȡ���һ����Ϣʱ��
	// Parameter: int nIMUserID
	//************************************
	QString DBGetMessageLastTime(int nIMUserID);

	//************************************
	// Method:    DBUpdateMessageStateInfo
	// FullName:  IMSocketMessageInfo::DBUpdateMessageStateInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: �������ݿ���Ϣ״̬
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void DBUpdateMessageStateInfo(QByteArray msgID, int nState);

	//************************************
	// Method:    DBInsertMessageInfo
	// FullName:  IMSocketMessageInfo::DBInsertMessageInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ���ݿ������Ϣ
	// Parameter: int nSelfID
	// Parameter: int nUserID
	// Parameter: MessageInfo messageInfo
	//************************************
	void DBInsertMessageInfo(int nSelfID, int nUserID, MessageInfo messageInfo);

	//************************************
	// Method:    OnDealMessageText
	// FullName:  IMSocketMessageInfo::OnDealMessageText
	// Access:    private 
	// Returns:   void
	// Qualifier: �����յ����ı���Ϣ
	// Parameter: MessageInfo msgInfo
	//************************************
	void OnDealMessageText(MessageInfo msgInfo);

	//************************************
	// Method:    OnDealMessagePic
	// FullName:  IMSocketMessageInfo::OnDealMessagePic
	// Access:    private 
	// Returns:   void
	// Qualifier: �����յ���ͼƬ��Ϣ
	// Parameter: MessageInfo msgInfo
	//************************************
	void OnDealMessagePic(MessageInfo msgInfo);

	//************************************
	// Method:    OnDealMessageAudio
	// FullName:  IMSocketMessageInfo::OnDealMessageAudio
	// Access:    private 
	// Returns:   void
	// Qualifier: �����յ�����Ƶ��Ϣ
	// Parameter: MessageInfo msgInfo
	//************************************
	void OnDealMessageAudio(MessageInfo msgInfo);

	//************************************
	// Method:    OnDealMessageVeido
	// FullName:  IMSocketMessageInfo::OnDealMessageVeido
	// Access:    private 
	// Returns:   void
	// Qualifier: �����յ�����Ƶ��Ϣ
	//************************************
	void OnDealMessageVeido(MessageInfo msgInfo);

	//************************************
	// Method:    OnDealMessageFile
	// FullName:  IMSocketMessageInfo::OnDealMessageFile
	// Access:    private 
	// Returns:   void
	// Qualifier: �����յ����ļ���Ϣ
	// Parameter: messageInfo
	//************************************
	void OnDealMessageFile(MessageInfo messageInfo);

	//************************************
	// Method:    OnDealMessageTask
	// FullName:  IMSocketMessageInfo::OnDealMessageTask
	// Access:    private 
	// Returns:   void
	// Qualifier: �����յ���������Ϣ
	// Parameter: messageInfo
	//************************************
	void OnDealMessageCommon(MessageInfo messageInfo);

	//************************************
	// Method:    OnDealMessageRobot
	// FullName:  IMSocketMessageInfo::OnDealMessageRobot
	// Access:    private 
	// Returns:   void
	// Qualifier: �����յ��Ļ�������Ϣ
	// Parameter: MessageInfo messageInfo
	//************************************
	void OnDealMessageRobot(MessageInfo messageInfo);
private slots:
	//************************************
	// Method:    slotRecSystemMessage
	// FullName:  IMSocketMessageInfo::slotRecSystemMessage
	// Access:    private 
	// Returns:   void 
	// Qualifier: ���յ�ϵͳ��Ϣ
	// Parameter: MessageInfo msgInfo
	//************************************
	void slotRecSystemMessage(MessageInfo msgInfo);

	//************************************
	// Method:    slotRevServerMessage
	// FullName:  IMSocketMessageInfo::slotRevServerMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: �յ�����������Ϣ  //ͼƬ���ı����ļ���
	// Parameter: MessageInfo msgInfo
	//************************************
	void slotRevServerMessage(MessageInfo msgInfo);

	//************************************
	// Method:    slotSendUpdateMessage
	// FullName:  IMSocketMessageInfo::slotSendUpdateMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: �յ���Ϣ״̬���
	// Parameter: QByteArray
	// Parameter: int
	//************************************
	void slotRevUpdateMessage(MessageInfo, int);

	//************************************
	// Method:    slotSendMessage
	// FullName:  IMSocketMessageInfo::slotSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ������Ϣ�ź�
	// Parameter: MessageInfo
	//************************************
	void slotSendMessage(MessageInfo);

	//************************************
	// Method:    slotDisConnectServerServer
	// FullName:  IMSocketMessageInfo::slotDisConnectServerServer
	// Access:    private 
	// Returns:   void
	// Qualifier: ��������Ͽ������ź�
	//************************************
	void slotDisConnectServerServer();

	//************************************
	// Method:    slotReplySocketInfoFinished
	// FullName:  IMSocketMessageInfo::slotReplySocketInfoFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: ����socket��Ϣ����
	// Parameter: bool bResult
	// Parameter: QString strResult
	//************************************
	void slotReplySocketInfoFinished(bool bResult, QString strResult);

	//************************************
	// Method:    slotReConnectSocketInfoFinished
	// FullName:  IMSocketMessageInfo::slotReConnectSocketInfoFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: ����socket
	// Parameter: bool bResult
	// Parameter: QByteArray result
	//************************************
	void slotReConnectSocketInfoFinished(bool bResult, QString result);

	//************************************
	// Method:    slotDownFileFinish
	// FullName:  IMSocketMessageInfo::slotDownFileFinish
	// Access:    private 
	// Returns:   void
	// Qualifier: �ļ��������
	// Parameter: bool bResult
	//************************************
	void slotDownFileFinish(bool bResult);
signals:

	//************************************
	// Method:    sigSendMessage
	// FullName:  IMSocketMessageInfo::sigSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ������Ϣ�ź�
	// Parameter: MessageInfo
	//************************************
	void sigSendMessage(MessageInfo);

	//************************************
	// Method:    sigRevSystemMessage
	// FullName:  IMSocketMessageInfo::sigRevSystemMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ���յ�ϵͳ��Ϣ
	// Parameter: MessageInfo
	//************************************
	void sigRevSystemMessage(MessageInfo);

	//************************************
	// Method:    sigSendOtherDeviceMsg
	// FullName:  IMSocketMessageInfo::sigSendOtherDeviceMsg
	// Access:    private 
	// Returns:   void
	// Qualifier: �յ�ͨ�������豸���͵���Ϣ
	// Parameter: MessageInfo
	//************************************
	void sigRevOtherDeviceMsg(MessageInfo);

	//************************************
	// Method:    sigRevMessage
	// FullName:  IMSocketMessageInfo::sigRevMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ���յ���Ϣ
	// Parameter: MessageInfo
	// Parameter: int
	//************************************
	void sigRevMsgInfo(MessageInfo, int);

	//************************************
	// Method:    sigRevUpdateMessage
	// FullName:  IMSocketMessageInfo::sigRevUpdateMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ������Ϣ״̬
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void sigRevUpdateMessageState(MessageInfo msgInfo, int nState);

	//************************************
	// Method:    sigDisConnectServerServer
	// FullName:  IMSocketMessageInfo::sigDisConnectServerServer
	// Access:    private 
	// Returns:   void
	// Qualifier: ��������Ͽ������ź�
	//************************************
	void sigDisConnectServerServer(QString msg);

	//************************************
	// Method:    sigGetSocketAddressErro
	// FullName:  IMSocketMessageInfo::sigGetSocketAddressErro
	// Access:    private 
	// Returns:   void
	// Qualifier: ��ȡsocket��Ϣʧ��
	//************************************
	void sigGetSocketAddressErro(QString errMsg);

	//************************************
	// Method:    sigConnectSocketSuccess
	// FullName:  IMSocketMessageInfo::sigConnectSocketSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: ����socket�ɹ�
	//************************************
	void sigConnectSocketSuccess();

	//************************************
	// Method:    sigReConnectSuccess
	// FullName:  IMSocketMessageInfo::sigReConnectSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: �����ɹ�
	//************************************
	void sigReConnectSuccess();
private:
	IMSocketNetWorkShareLib *mSocketOpera;
	IMSocketDataBaseShareLib *mSocketDataBase; //���ݿ����  
	int		nIMUserID;      //��ǰ��½��IM ID  
	ServerInfo mSocketInfo;
	RequestSocketInfo mRequestSocketInfo;        //��¼����socket��Ϣ
	QTimer		*mReConnectTimer;   //������ʱ��
	bool mbReConnect;
};

#endif // IMSOCKETMESSAGEINFO_H
