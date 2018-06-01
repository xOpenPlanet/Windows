#ifndef IMSOCKETMESSAGEINFO_H
#define IMSOCKETMESSAGEINFO_H

#include <QObject>
#include "imsocketnetworksharelib.h"

//图片信息
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

struct RequestSocketInfo       //请求socket信息
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
	// Qualifier: 请求socket地址
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
	// Qualifier: 字节转换 自动计算是MB 还是KB 返回 XXMB XXKB XXB
	// Parameter: int nByte
	//************************************
	QString ByteConversion(int nByte);

	//************************************
	// Method:    GetExeDir
	// FullName:  IMSocketMessageInfo::GetExeDir
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: 获取程序运行路径
	//************************************
	QString GetExeDir();
private:

	//************************************
	// Method:    StitchSocketParameter
	// FullName:  IMSocketMessageInfo::StitchSocketParameter
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: 拼接请求socket参数
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
	// Qualifier: 连接socket
	//************************************
	bool OnConnectSocket(QString strServerIP, QString strServerPort, QString strToken);

	//************************************
	// Method:    ConnectDataBase
	// FullName:  IMSocketNetWorkShareLib::ConnectDataBase
	// Access:    public 
	// Returns:   void
	// Qualifier: 连接数据库
	//************************************
	void ConnectDataBase();

public:

	//************************************
	// Method:    SendTextMessage
	// FullName:  IMSocketMessageInfo::SendTextMessage
	// Access:    public 
	// Returns:   void 
	// Qualifier: 发送文本消息
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
	// Qualifier: 发送消息已读
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
	// Qualifier: 发送图片消息
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
	// Qualifier: 发送文件消息
	// Parameter: int nFromUserID
	// Parameter: int nToUserID
	// Parameter: int nDeliverType
	// Parameter: short MessageChildType
	// Parameter: QString strMsg
	//************************************
	MessageInfo SendFileMessage(int nFromUserID, int nToUserID, int nDeliverType, QString strMsg);

	// Qualifier: 设置重连状态
	void setReConnectState(bool bState);

	//************************************
	// Method:    slotUpFileReplyFinished
	// FullName:  IMSocketMessageInfo::slotUpFileReplyFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: 上传文件成功
	// Parameter: bool bResult
	// Parameter: QByteArray result
	//************************************
	void setUpFileReplyFinished(QByteArray result,FileMessage*,MessageInfo);

	//************************************
	// Method:    slotUpFileReplyFinished
	// FullName:  IMSocketMessageInfo::slotUpFileReplyFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: 上传图片文件成功
	//************************************
	void setUpPicReplyFinished(QByteArray result,PicMessage *,MessageInfo);

	//************************************
	// Method:    SetMessageState
	// FullName:  IMSocketMessageInfo::SetMessageState
	// Access:    public 
	// Returns:   void 
	// Qualifier: 设置消息状态
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void SetMessageState(QByteArray msgID, int nState);

	//************************************
	// Method:    SetIMUserID
	// FullName:  IMNetWorkShared::SetIMUserID
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置当前登录的IMUserID
	// Parameter: int nIMID
	//************************************
	void SetIMUserID(int nIMID);

	//************************************
	// Method:    GetDBAllMessage
	// FullName:  IMNetWorkShared::GetDBAllMessage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: 获取全部的消息内容
	//************************************
	QMap<QString, QList<MessageInfo> > DBGetAllMessage();

	//************************************
	// Method:    GetDBCurrentDayMessage
	// FullName:  IMNetWorkShared::GetDBCurrentDayMessage
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: 获取当天的消息
	//************************************
	QMap<QString, QList<MessageInfo> > DBGetCurrentDayMessage();

	//************************************
	// Method:    GetDBCurrentDayMessageWithIMUserID
	// FullName:  IMNetWorkShared::GetDBCurrentDayMessageWithIMUserID
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: 获取当天对话ID 的消息内容
	// Parameter: int nChatID
	//************************************
	QMap<QString, QList<MessageInfo> > DBGetCurrentDayMessageWithIMUserID(int nChatID);


	//************************************
	// Method:    GetDBMessageRecordPage
	// FullName:  IMNetWorkShared::GetDBMessageRecordPage
	// Access:    public 
	// Returns:   int
	// Qualifier: 获取聊天ID下的消息页数
	// Parameter: int nChatID  聊天ID
	// Parameter: int nPageNum  每一页消息数量 默认20
	//************************************
	int DBGetMessageRecordPageNum(int nChatID, int nPageNum = 20);

	//************************************
	// Method:    GetDBMessageRecord
	// FullName:  IMNetWorkShared::GetDBMessageRecord
	// Access:    public 
	// Returns:   QMap<QString, QList<MessageInfo> >
	// Qualifier: 获取消息记录数据
	// Parameter: int nChatID     聊天ID
	// Parameter: int nPage   页数
	// Parameter: int messageType    获取消息的类型
	//************************************
	QList<MessageInfo> DBGetMessageRecordByPage(int nChatID, int nPage = 0, int messageType = MessageRecordAll);


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
	int DBGetSearchMessagePageNum(int nChatID, QString strLikeMsg, int nPageNum = 20);

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
	QList<MessageInfo> DBGetSearchMessageRecordByPage(int nChatID, int nPage = 0, int messageType = MessageRecordAll);

	//************************************
	// Method:    GetDBMessageInfoWithMsgID
	// FullName:  IMNetWorkShared::GetDBMessageInfoWithMsgID
	// Access:    public 
	// Returns:   MessageInfo
	// Qualifier: 根据MessageID获取数据库消息
	// Parameter: QString strMsgID
	//************************************
	MessageInfo DBGetMessageInfoWithMsgID(QString strMsgID);

	//************************************
	// Method:    SetPerMessageRead
	// FullName:  IMSocketMessageInfo::SetPerMessageRead
	// Access:    public 
	// Returns:   QList<QByteArray>
	// Qualifier: 设置个人消息已读
	// Parameter: int nUserID
	//************************************
	QList<QByteArray> SetPerMessageRead(int nUserID);

	//************************************
	// Method:    SetGroupMessageRead
	// FullName:  IMSocketMessageInfo::SetGroupMessageRead
	// Access:    public 
	// Returns:   QList<QByteArray>
	// Qualifier: 设置群组消息已读
	// Parameter: int nGroupID
	//************************************
	QList<QByteArray> SetGroupMessageRead(int nGroupID);
private:
	//************************************
	// Method:    ParseSocketInfo
	// FullName:  IMSocketMessageInfo::ParseSocketInfo
	// Access:    private 
	// Returns:   bool
	// Qualifier: 解析socket信息
	// Parameter: QString socketInfo
	//************************************
	bool ParseSocketInfo(QString socketInfo);

	//************************************
	// Method:    SendMessage
	// FullName:  IMSocketMessageInfo::SendMessage
	// Access:    public 
	// Returns:   MessageInfo
	// Qualifier: 发送消息
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
	// Qualifier: 获取最后一条消息时间
	// Parameter: int nIMUserID
	//************************************
	QString DBGetMessageLastTime(int nIMUserID);

	//************************************
	// Method:    DBUpdateMessageStateInfo
	// FullName:  IMSocketMessageInfo::DBUpdateMessageStateInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新数据库消息状态
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void DBUpdateMessageStateInfo(QByteArray msgID, int nState);

	//************************************
	// Method:    DBInsertMessageInfo
	// FullName:  IMSocketMessageInfo::DBInsertMessageInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 数据库插入消息
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
	// Qualifier: 处理收到的文本消息
	// Parameter: MessageInfo msgInfo
	//************************************
	void OnDealMessageText(MessageInfo msgInfo);

	//************************************
	// Method:    OnDealMessagePic
	// FullName:  IMSocketMessageInfo::OnDealMessagePic
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理收到的图片消息
	// Parameter: MessageInfo msgInfo
	//************************************
	void OnDealMessagePic(MessageInfo msgInfo);

	//************************************
	// Method:    OnDealMessageAudio
	// FullName:  IMSocketMessageInfo::OnDealMessageAudio
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理收到的音频消息
	// Parameter: MessageInfo msgInfo
	//************************************
	void OnDealMessageAudio(MessageInfo msgInfo);

	//************************************
	// Method:    OnDealMessageVeido
	// FullName:  IMSocketMessageInfo::OnDealMessageVeido
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理收到的视频消息
	//************************************
	void OnDealMessageVeido(MessageInfo msgInfo);

	//************************************
	// Method:    OnDealMessageFile
	// FullName:  IMSocketMessageInfo::OnDealMessageFile
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理收到的文件消息
	// Parameter: messageInfo
	//************************************
	void OnDealMessageFile(MessageInfo messageInfo);

	//************************************
	// Method:    OnDealMessageTask
	// FullName:  IMSocketMessageInfo::OnDealMessageTask
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理收到的任务消息
	// Parameter: messageInfo
	//************************************
	void OnDealMessageCommon(MessageInfo messageInfo);

	//************************************
	// Method:    OnDealMessageRobot
	// FullName:  IMSocketMessageInfo::OnDealMessageRobot
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理收到的机器人消息
	// Parameter: MessageInfo messageInfo
	//************************************
	void OnDealMessageRobot(MessageInfo messageInfo);
private slots:
	//************************************
	// Method:    slotRecSystemMessage
	// FullName:  IMSocketMessageInfo::slotRecSystemMessage
	// Access:    private 
	// Returns:   void 
	// Qualifier: 接收到系统消息
	// Parameter: MessageInfo msgInfo
	//************************************
	void slotRecSystemMessage(MessageInfo msgInfo);

	//************************************
	// Method:    slotRevServerMessage
	// FullName:  IMSocketMessageInfo::slotRevServerMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 收到服务器的消息  //图片，文本，文件等
	// Parameter: MessageInfo msgInfo
	//************************************
	void slotRevServerMessage(MessageInfo msgInfo);

	//************************************
	// Method:    slotSendUpdateMessage
	// FullName:  IMSocketMessageInfo::slotSendUpdateMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 收到消息状态变更
	// Parameter: QByteArray
	// Parameter: int
	//************************************
	void slotRevUpdateMessage(MessageInfo, int);

	//************************************
	// Method:    slotSendMessage
	// FullName:  IMSocketMessageInfo::slotSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送消息信号
	// Parameter: MessageInfo
	//************************************
	void slotSendMessage(MessageInfo);

	//************************************
	// Method:    slotDisConnectServerServer
	// FullName:  IMSocketMessageInfo::slotDisConnectServerServer
	// Access:    private 
	// Returns:   void
	// Qualifier: 与服务器断开连接信号
	//************************************
	void slotDisConnectServerServer();

	//************************************
	// Method:    slotReplySocketInfoFinished
	// FullName:  IMSocketMessageInfo::slotReplySocketInfoFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: 请求socket信息结束
	// Parameter: bool bResult
	// Parameter: QString strResult
	//************************************
	void slotReplySocketInfoFinished(bool bResult, QString strResult);

	//************************************
	// Method:    slotReConnectSocketInfoFinished
	// FullName:  IMSocketMessageInfo::slotReConnectSocketInfoFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: 重连socket
	// Parameter: bool bResult
	// Parameter: QByteArray result
	//************************************
	void slotReConnectSocketInfoFinished(bool bResult, QString result);

	//************************************
	// Method:    slotDownFileFinish
	// FullName:  IMSocketMessageInfo::slotDownFileFinish
	// Access:    private 
	// Returns:   void
	// Qualifier: 文件下载完毕
	// Parameter: bool bResult
	//************************************
	void slotDownFileFinish(bool bResult);
signals:

	//************************************
	// Method:    sigSendMessage
	// FullName:  IMSocketMessageInfo::sigSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送消息信号
	// Parameter: MessageInfo
	//************************************
	void sigSendMessage(MessageInfo);

	//************************************
	// Method:    sigRevSystemMessage
	// FullName:  IMSocketMessageInfo::sigRevSystemMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 接收到系统消息
	// Parameter: MessageInfo
	//************************************
	void sigRevSystemMessage(MessageInfo);

	//************************************
	// Method:    sigSendOtherDeviceMsg
	// FullName:  IMSocketMessageInfo::sigSendOtherDeviceMsg
	// Access:    private 
	// Returns:   void
	// Qualifier: 收到通过其他设备发送的消息
	// Parameter: MessageInfo
	//************************************
	void sigRevOtherDeviceMsg(MessageInfo);

	//************************************
	// Method:    sigRevMessage
	// FullName:  IMSocketMessageInfo::sigRevMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 接收到消息
	// Parameter: MessageInfo
	// Parameter: int
	//************************************
	void sigRevMsgInfo(MessageInfo, int);

	//************************************
	// Method:    sigRevUpdateMessage
	// FullName:  IMSocketMessageInfo::sigRevUpdateMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新消息状态
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void sigRevUpdateMessageState(MessageInfo msgInfo, int nState);

	//************************************
	// Method:    sigDisConnectServerServer
	// FullName:  IMSocketMessageInfo::sigDisConnectServerServer
	// Access:    private 
	// Returns:   void
	// Qualifier: 与服务器断开连接信号
	//************************************
	void sigDisConnectServerServer(QString msg);

	//************************************
	// Method:    sigGetSocketAddressErro
	// FullName:  IMSocketMessageInfo::sigGetSocketAddressErro
	// Access:    private 
	// Returns:   void
	// Qualifier: 获取socket信息失败
	//************************************
	void sigGetSocketAddressErro(QString errMsg);

	//************************************
	// Method:    sigConnectSocketSuccess
	// FullName:  IMSocketMessageInfo::sigConnectSocketSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: 连接socket成功
	//************************************
	void sigConnectSocketSuccess();

	//************************************
	// Method:    sigReConnectSuccess
	// FullName:  IMSocketMessageInfo::sigReConnectSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: 重连成功
	//************************************
	void sigReConnectSuccess();
private:
	IMSocketNetWorkShareLib *mSocketOpera;
	IMSocketDataBaseShareLib *mSocketDataBase; //数据库操作  
	int		nIMUserID;      //当前登陆的IM ID  
	ServerInfo mSocketInfo;
	RequestSocketInfo mRequestSocketInfo;        //记录请求socket信息
	QTimer		*mReConnectTimer;   //重连定时器
	bool mbReConnect;
};

#endif // IMSOCKETMESSAGEINFO_H
