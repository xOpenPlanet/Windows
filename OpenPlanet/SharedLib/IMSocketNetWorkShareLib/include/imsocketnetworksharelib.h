#ifndef IMSOCKETNETWORKSHARELIB_H
#define IMSOCKETNETWORKSHARELIB_H

/*IM socketͨ��*/
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
	// Qualifier: ����socket
	//************************************
	bool OnConnectSocket(QString strServerIP, QString strServerPort,  QString strToken,QString strLastMessage);

	//************************************
	// Method:    SendMessage
	// FullName:  IMSocketNetWorkShareLib::SendMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: ������Ϣ
	// Parameter: int nFromUserID       ˭����
	// Parameter: int nToUserID         ����˭
	// Parameter: int nDeliverType      Ͷ������ Ⱥ�黹�Ǹ���
	// Parameter: short MessageChildType    ��Ϣ������ �ı���Ϣ ͼƬ��Ϣ
	// Parameter: QString strMsg       ��Ϣ����
	//************************************
	MessageInfo SendMessage(int nFromUserID, int nToUserID, int nDeliverType, short MessageChildType, int nMessageState, QString strMsg);

	//************************************
	// Method:    OnInsertMessage
	// FullName:  IMSocketNetWorkShareLib::OnInsertMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ��Map�в�����Ϣ
	// Parameter: MessageInfo messageInfo
	// Parameter: int nUserID
	//************************************
	void OnInsertMessage(MessageInfo messageInfo, int nUserID);

	//************************************
	// Method:    SetIMUserID
	// FullName:  IMNetWorkShared::SetIMUserID
	// Access:    public 
	// Returns:   void
	// Qualifier: ���õ�ǰ��¼��IMUserID
	// Parameter: int nIMID
	//************************************
	void SetIMUserID(int nIMID){ nIMUserID = nIMID; }

	//************************************
	// Method:    SetMessageState
	// FullName:  IMSocketNetWorkShareLib::SetMessageState
	// Access:    private 
	// Returns:   void
	// Qualifier: ������Ϣ״̬
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void SetMessageState(QByteArray msgID, int nState);

	//************************************
	// Method:    ChangeMessageInfo
	// FullName:  IMSocketNetWorkShareLib::ChangeMessageInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ������Ϣ����
	// Parameter: QByteArray msgID
	// Parameter: QString strMsg
	//************************************
	void ChangeMessageInfo(QByteArray msgID,QString strMsg);

	QList<QByteArray> SetPerMessageRead(int nUserID);

	QList<QByteArray> SetGroupMessageRead(int nGroupID);

	//Qualifier: ��������״̬
	void setReConnectState(bool bState);
private:
	//************************************
	// Method:    sendTocken
	// FullName:  IMSocketNetWorkShareLib::sendTocken
	// Access:    public 
	// Returns:   void
	// Qualifier: ����tokenֵ
	// Parameter: QString strToken
	//************************************
	void sendTocken(QString strMessageLastTime, QString strToken);

	//************************************
	// Method:    StartHeartBeat
	// FullName:  IMSocketNetWorkShareLib::StartHeartBeat
	// Access:    private 
	// Returns:   void
	// Qualifier: �������
	//************************************
	void StartHeartBeat();

	//************************************
	// Method:    StopHeartBeat
	// FullName:  IMSocketNetWorkShareLib::StopHeartBeat
	// Access:    private 
	// Returns:   void
	// Qualifier: ֹͣ����
	//************************************
	void StopHeartBeat();

	//************************************
	// Method:    StartMonitorServerHeartTimer
	// FullName:  IMSocketNetWorkShareLib::StartMonitorServerHeartTimer
	// Access:    private 
	// Returns:   void
	// Qualifier: ���������������ʱ��
	//************************************
	void StartMonitorServerHeartTimer();

	//************************************
	// Method:    StopMonitorServerHeartTimer
	// FullName:  IMSocketNetWorkShareLib::StopMonitorServerHeartTimer
	// Access:    private 
	// Returns:   void
	// Qualifier: ֹͣ���������
	//************************************
	void StopMonitorServerHeartTimer();

	//************************************
	// Method:    OnDealServerHeart
	// FullName:  IMSocketNetWorkShareLib::OnDealServerHeart
	// Access:    private 
	// Returns:   void
	// Qualifier: �������Է�����������
	//************************************
	void OnDealServerHeart();

	//************************************
	// Method:    onDealMessageInfo
	// FullName:  IMSocketNetWorkShareLib::onDealMessageInfo
	// Access:    private 
	// Returns:   void
	// Qualifier:������Ϣ��Ϣ
	// Parameter: QByteArray byteArray
	//************************************
	void onDealMessageInfo(QByteArray byteArray);

	//************************************
	// Method:    onDealReceiptMessage
	// FullName:  IMSocketNetWorkShareLib::onDealReceiptMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: �����ִ��Ϣ
	// Parameter: QByteArray buff
	//************************************
	void onDealReceiptMessage(QByteArray buff);

	//************************************
	// Method:    onDealSystemMessage
	// FullName:  IMSocketNetWorkShareLib::onDealSystemMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ����ϵͳ��Ϣ
	// Parameter: MessageInfo msgInfo
	//************************************
	void onDealRevSystemMessage(MessageInfo msgInfo);

	//************************************
	// Method:    onDealOtherMessage
	// FullName:  IMSocketNetWorkShareLib::onDealOtherMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ������յ���������Ϣ���ı���ͼ���ļ��ȣ�
	// Parameter: MessageInfo msgInfo
	//************************************
	void onDealRevOtherMessage(MessageInfo msgInfo);

	//************************************
	// Method:    OnJudgeMessageRepet
	// FullName:  IMSocketNetWorkShareLib::OnJudgeMessageRepet
	// Access:    private 
	// Returns:   bool
	// Qualifier: �ж��ظ���Ϣ
	// Parameter: QByteArray strMsgID
	//************************************
	bool OnJudgeMessageRepet(QByteArray strMsgID);

	//************************************
	// Method:    CreateMsgID
	// FullName:  IMSocketNetWorkShareLib::CreateMsgID
	// Access:    private 
	// Returns:   QT_NAMESPACE::QByteArray
	// Qualifier: ����msgID
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
	// Qualifier: ���ͻ�ִ��Ϣ
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
	// Qualifier:��������
	// Parameter: MessageInfo messageInfo
	//************************************
	void SendQByteArrayMsg(MessageInfo messageInfo);

	//************************************
	// Method:    DBUpdateMessageStateInfo
	// FullName:  IMNetWorkShared::DBUpdateMessageStateInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ������Ϣ���ݿ��е���Ϣ״̬
	// Parameter: QByteArray msgID
	// Parameter: int nState
	//************************************
	void DBUpdateMessageStateInfo(QByteArray msgID, int nState);

	// Qualifier: ����MSGINFO
	void SetMessageInfo(QByteArray msgID,MessageInfo messageInfo);
private slots:
	//************************************
	// Method:    slotRevServerMsg
	// FullName:  IMSocketNetWorkShareLib::slotRevServerMsg
	// Access:    private 
	// Returns:   void
	// Qualifier: ������յ�������
	// Parameter: QByteArray
	//************************************
	void slotRevServerMsg(QByteArray);

	//************************************
	// Method:    slotDisConnectServer
	// FullName:  IMSocketNetWorkShareLib::slotDisConnectServer
	// Access:    private 
	// Returns:   void
	// Qualifier: ��������Ͽ�����
	//************************************
	void slotDisConnectServer();

	//************************************
	// Method:    slotSendToken
	// FullName:  IMSocketNetWorkShareLib::slotSendToken
	// Access:    private 
	// Returns:   void
	// Qualifier: ��ʱ������token
	//************************************
	void slotSendToken();

	//************************************
	// Method:    slotMonitorServerHeart
	// FullName:  IMSocketNetWorkShareLib::slotMonitorServerHeart
	// Access:    private 
	// Returns:   void
	// Qualifier: �ȶ��յ���������ʱ��
	//************************************
	void slotMonitorServerHeart();

	//************************************
	// Method:    SendHeartData
	// FullName:  IMSocketNetWorkShareLib::SendHeartData
	// Access:    private 
	// Returns:   void
	// Qualifier: ��������
	//************************************
	void slotSendHeartData();

	//************************************
	// Method:    onJudgetSendMsgState
	// FullName:  IMSocketNetWorkShareLib::onJudgetSendMsgState
	// Access:    private 
	// Returns:   void
	// Qualifier: �жϷ�����Ϣ״̬
	//************************************
	void slotJudgetSendMsgState();
signals:
	//************************************
	// Method:    sigSendUpdateMessage
	// FullName:  IMSocketNetWorkShareLib::sigSendUpdateMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ֪ͨ��Ϣ���״̬
	// Parameter: QByteArray
	// Parameter: int
	//************************************
	void sigSendUpdateMessage(MessageInfo, int);   

	//************************************
	// Method:    sigRecSystemMessage
	// FullName:  IMSocketNetWorkShareLib::sigRecSystemMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ϵͳ��Ϣ�ź�
	// Parameter: MessageInfo msgInfo
	//************************************
	void sigRecSystemMessage(MessageInfo msgInfo);

	//************************************
	// Method:    sigRevServerMessage
	// FullName:  IMSocketNetWorkShareLib::sigRevServerMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ������յ��ķ�������Ϣ
	// Parameter: MessageInfo msg
	//************************************
	void sigRevServerMessage(MessageInfo msg);

	//************************************
	// Method:    sigSendMessage
	// FullName:  IMSocketNetWorkShareLib::sigSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ������Ϣ�ź�
	// Parameter: MessageInfo
	//************************************
	void sigSendMessage(MessageInfo);              //������Ϣ���ź�

	//************************************
	// Method:    sigDisConnectServerServer
	// FullName:  IMSocketNetWorkShareLib::sigDisConnectServerServer
	// Access:    private 
	// Returns:   void
	// Qualifier: ��������Ͽ������ź�
	//************************************
	void sigDisConnectServerServer();
private:
	SocketNetWorkShareLib *mSocketClient;      //�������
	QTimer *mHeartTime;
	QTimer	*mMonitorServerHeart;  //���������ʱ��
	qlonglong   mServerHeartTime;        //�յ��������˵�����ʱ��
	QString mServerToken;   //tokenֵ
	QByteArray  mSocketMessage;         //��¼�ϴη��͵�
	QMap<QString, QList<MessageInfo> > mMapMessageInfo;   //��һ������Ϊ��˭���죬�ڶ�������Ϊ��Ϣ�ı�
	QTimer      *timer_send;
	int		nIMUserID;      //��ǰ��½��IM ID  
	bool mbReConnect;
};

#endif // IMSOCKETNETWORKSHARELIB_H
