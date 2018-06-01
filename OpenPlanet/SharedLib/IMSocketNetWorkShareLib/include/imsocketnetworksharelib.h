#ifndef IMSOCKETNETWORKSHARELIB_H
#define IMSOCKETNETWORKSHARELIB_H

/*IM socket通信*/
#include <QObject>
#include "socketnetworksharelib.h"
#include "imsocketdatabasesharelib.h"
#include <QTimer>
#include <QDataStream>

typedef unsigned char BYTE;
#define TIMER_HEARTBEAT 10000

class IMSocketNetWorkShareLib : public QObject
{
	Q_OBJECT
public:
	IMSocketNetWorkShareLib(QObject *parent = 0);
	~IMSocketNetWorkShareLib();

	//************************************
	// Method:    OnConnectSocket
	// FullName:  JFMessageManager::OnConnectSocket
	// Access:    public 
	// Returns:   void
	// Qualifier: 连接socket
	//************************************
	bool OnConnectSocket(QString strServerIP, QString strServerPort,  QString strToken,QString strLastMessage);

	//************************************
	// Method:    SendMessage
	// FullName:  IMSocketNetWorkShareLib::SendMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: 发送消息
	// Parameter: int nFromUserID       谁发的
	// Parameter: int nToUserID         发给谁
	// Parameter: int nDeliverType      投递类型 群组还是个人
	// Parameter: short MessageChildType    消息子类型 文本消息 图片消息
	// Parameter: QString strMsg       消息内容
	//************************************
	MessageInfo SendMessage(int nFromUserID, int nToUserID, int nDeliverType, short MessageChildType, int nMessageState, QString strMsg);

	//************************************
	// Method:    OnInsertMessage
	// FullName:  IMSocketNetWorkShareLib::OnInsertMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 往Map中插入信息
	// Parameter: MessageInfo messageInfo
	// Parameter: int nUserID
	//************************************
	void OnInsertMessage(MessageInfo messageInfo, int nUserID);

	//************************************
	// Method:    SetIMUserID
	// FullName:  IMNetWorkShared::SetIMUserID
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置当前登录的IMUserID
	// Parameter: int nIMID
	//************************************
	void SetIMUserID(int nIMID){ nIMUserID = nIMID; }

	//************************************
	// Method:    SetMessageState
	// FullName:  IMSocketNetWorkShareLib::SetMessageState
	// Access:    private 
	// Returns:   void
	// Qualifier: 设置消息状态
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void SetMessageState(QByteArray msgID, int nState);

	//************************************
	// Method:    ChangeMessageInfo
	// FullName:  IMSocketNetWorkShareLib::ChangeMessageInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 更改消息内容
	// Parameter: QByteArray msgID
	// Parameter: QString strMsg
	//************************************
	void ChangeMessageInfo(QByteArray msgID,QString strMsg);

	QList<QByteArray> SetPerMessageRead(int nUserID);

	QList<QByteArray> SetGroupMessageRead(int nGroupID);

	//Qualifier: 设置重连状态
	void setReConnectState(bool bState);
private:
	//************************************
	// Method:    sendTocken
	// FullName:  IMSocketNetWorkShareLib::sendTocken
	// Access:    public 
	// Returns:   void
	// Qualifier: 发送token值
	// Parameter: QString strToken
	//************************************
	void sendTocken(QString strMessageLastTime, QString strToken);

	//************************************
	// Method:    StartHeartBeat
	// FullName:  IMSocketNetWorkShareLib::StartHeartBeat
	// Access:    private 
	// Returns:   void
	// Qualifier: 心跳检测
	//************************************
	void StartHeartBeat();

	//************************************
	// Method:    StopHeartBeat
	// FullName:  IMSocketNetWorkShareLib::StopHeartBeat
	// Access:    private 
	// Returns:   void
	// Qualifier: 停止心跳
	//************************************
	void StopHeartBeat();

	//************************************
	// Method:    StartMonitorServerHeartTimer
	// FullName:  IMSocketNetWorkShareLib::StartMonitorServerHeartTimer
	// Access:    private 
	// Returns:   void
	// Qualifier: 启动检测心跳包定时器
	//************************************
	void StartMonitorServerHeartTimer();

	//************************************
	// Method:    StopMonitorServerHeartTimer
	// FullName:  IMSocketNetWorkShareLib::StopMonitorServerHeartTimer
	// Access:    private 
	// Returns:   void
	// Qualifier: 停止检测心跳包
	//************************************
	void StopMonitorServerHeartTimer();

	//************************************
	// Method:    OnDealServerHeart
	// FullName:  IMSocketNetWorkShareLib::OnDealServerHeart
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理来自服务器的心跳
	//************************************
	void OnDealServerHeart();

	//************************************
	// Method:    onDealMessageInfo
	// FullName:  IMSocketNetWorkShareLib::onDealMessageInfo
	// Access:    private 
	// Returns:   void
	// Qualifier:处理消息信息
	// Parameter: QByteArray byteArray
	//************************************
	void onDealMessageInfo(QByteArray byteArray);

	//************************************
	// Method:    onDealReceiptMessage
	// FullName:  IMSocketNetWorkShareLib::onDealReceiptMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理回执消息
	// Parameter: QByteArray buff
	//************************************
	void onDealReceiptMessage(QByteArray buff);

	//************************************
	// Method:    onDealSystemMessage
	// FullName:  IMSocketNetWorkShareLib::onDealSystemMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理系统消息
	// Parameter: MessageInfo msgInfo
	//************************************
	void onDealRevSystemMessage(MessageInfo msgInfo);

	//************************************
	// Method:    onDealOtherMessage
	// FullName:  IMSocketNetWorkShareLib::onDealOtherMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理接收到的其他消息（文本，图像，文件等）
	// Parameter: MessageInfo msgInfo
	//************************************
	void onDealRevOtherMessage(MessageInfo msgInfo);

	//************************************
	// Method:    OnJudgeMessageRepet
	// FullName:  IMSocketNetWorkShareLib::OnJudgeMessageRepet
	// Access:    private 
	// Returns:   bool
	// Qualifier: 判断重复消息
	// Parameter: QByteArray strMsgID
	//************************************
	bool OnJudgeMessageRepet(QByteArray strMsgID);

	//************************************
	// Method:    CreateMsgID
	// FullName:  IMSocketNetWorkShareLib::CreateMsgID
	// Access:    private 
	// Returns:   QT_NAMESPACE::QByteArray
	// Qualifier: 生成msgID
	// Parameter: int nFromID
	// Parameter: int nToId
	// Parameter: unsigned long long msgTime
	// Parameter: int nMsgOrder
	// Parameter: BYTE msgPost
	//************************************
	QByteArray CreateMsgID(int nFromID, int nToId, unsigned long long msgTime, int nMsgOrder, BYTE msgPost);

	//************************************
	// Method:    SendReceiptMessage
	// FullName:  IMSocketNetWorkShareLib::SendReceiptMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送回执消息
	// Parameter: QByteArray ReceiptMessage
	//************************************
	void SendReceiptMessage(QByteArray ReceiptMessage);

	void OnStart();

	void OnStop();

	//************************************
	// Method:    SendQByteArrayMsg
	// FullName:  IMSocketNetWorkShareLib::SendQByteArrayMsg
	// Access:    private 
	// Returns:   void
	// Qualifier:发送数据
	// Parameter: MessageInfo messageInfo
	//************************************
	void SendQByteArrayMsg(MessageInfo messageInfo);

	//************************************
	// Method:    DBUpdateMessageStateInfo
	// FullName:  IMNetWorkShared::DBUpdateMessageStateInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新消息数据库中的消息状态
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void DBUpdateMessageStateInfo(QByteArray msgID, int nState);

	// Qualifier: 更改MSGINFO
	void SetMessageInfo(QByteArray msgID,MessageInfo messageInfo);
private slots:
	//************************************
	// Method:    slotRevServerMsg
	// FullName:  IMSocketNetWorkShareLib::slotRevServerMsg
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理接收到的数据
	// Parameter: QByteArray
	//************************************
	void slotRevServerMsg(QByteArray);

	//************************************
	// Method:    slotDisConnectServer
	// FullName:  IMSocketNetWorkShareLib::slotDisConnectServer
	// Access:    private 
	// Returns:   void
	// Qualifier: 与服务器断开连接
	//************************************
	void slotDisConnectServer();

	//************************************
	// Method:    slotSendToken
	// FullName:  IMSocketNetWorkShareLib::slotSendToken
	// Access:    private 
	// Returns:   void
	// Qualifier: 定时器发送token
	//************************************
	void slotSendToken();

	//************************************
	// Method:    slotMonitorServerHeart
	// FullName:  IMSocketNetWorkShareLib::slotMonitorServerHeart
	// Access:    private 
	// Returns:   void
	// Qualifier: 比对收到的心跳包时间
	//************************************
	void slotMonitorServerHeart();

	//************************************
	// Method:    SendHeartData
	// FullName:  IMSocketNetWorkShareLib::SendHeartData
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送心跳
	//************************************
	void slotSendHeartData();

	//************************************
	// Method:    onJudgetSendMsgState
	// FullName:  IMSocketNetWorkShareLib::onJudgetSendMsgState
	// Access:    private 
	// Returns:   void
	// Qualifier: 判断发送消息状态
	//************************************
	void slotJudgetSendMsgState();
signals:
	//************************************
	// Method:    sigSendUpdateMessage
	// FullName:  IMSocketNetWorkShareLib::sigSendUpdateMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 通知消息变更状态
	// Parameter: QByteArray
	// Parameter: int
	//************************************
	void sigSendUpdateMessage(MessageInfo, int);   

	//************************************
	// Method:    sigRecSystemMessage
	// FullName:  IMSocketNetWorkShareLib::sigRecSystemMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 系统消息信号
	// Parameter: MessageInfo msgInfo
	//************************************
	void sigRecSystemMessage(MessageInfo msgInfo);

	//************************************
	// Method:    sigRevServerMessage
	// FullName:  IMSocketNetWorkShareLib::sigRevServerMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理接收到的服务器消息
	// Parameter: MessageInfo msg
	//************************************
	void sigRevServerMessage(MessageInfo msg);

	//************************************
	// Method:    sigSendMessage
	// FullName:  IMSocketNetWorkShareLib::sigSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送消息信号
	// Parameter: MessageInfo
	//************************************
	void sigSendMessage(MessageInfo);              //发送消息的信号

	//************************************
	// Method:    sigDisConnectServerServer
	// FullName:  IMSocketNetWorkShareLib::sigDisConnectServerServer
	// Access:    private 
	// Returns:   void
	// Qualifier: 与服务器断开连接信号
	//************************************
	void sigDisConnectServerServer();
private:
	SocketNetWorkShareLib *mSocketClient;      //网络操作
	QTimer *mHeartTime;
	QTimer	*mMonitorServerHeart;  //检测心跳定时器
	qlonglong   mServerHeartTime;        //收到服务器端的心跳时间
	QString mServerToken;   //token值
	QByteArray  mSocketMessage;         //记录上次发送的
	QMap<QString, QList<MessageInfo> > mMapMessageInfo;   //第一个参数为和谁聊天，第二个参数为消息聊表
	QTimer      *timer_send;
	int		nIMUserID;      //当前登陆的IM ID  
	bool mbReConnect;
};

#endif // IMSOCKETNETWORKSHARELIB_H
