#ifndef SOCKETNETWORKSHARELIB_H
#define SOCKETNETWORKSHARELIB_H

#include <QObject>
#include <QByteArray>
#include <QtNetwork/QTcpSocket>

/*通用版socket*/

class SocketNetWorkShareLib : public QObject
{
	Q_OBJECT
public:
	explicit SocketNetWorkShareLib(QObject *parent = 0);
	~SocketNetWorkShareLib();

	//************************************
	// Method:    ConnectServer
	// FullName:  SocketNetWorkShareLib::ConnectServer
	// Access:    public 
	// Returns:   bool
	// Qualifier: 连接服务器
	// Parameter: QString strIP
	// Parameter: int nPort
	//************************************
	bool ConnectServer(QString strIP, int nPort);

	//************************************
	// Method:    DisConnectSocket
	// FullName:  SocketNetWorkShareLib::DisConnectSocket
	// Access:    public 
	// Returns:   void
	// Qualifier: 断开socket连接
	//************************************
	void DisConnectSocket();    

	//************************************
	// Method:    SendMessage
	// FullName:  JFSocketManager::SendMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: 发送消息
	// Parameter: QByteArray byteArray
	//************************************
	void SendMsg(QByteArray byteArray);  

private slots:
	//************************************
	// Method:    ReceiveServerData
	// FullName:  JFSocketManager::ReceiveServerData
	// Access:    public 
	// Returns:   void
	// Qualifier: 处理接受到数据
	//************************************
	void slotReceiveServerData();

	//************************************
	// Method:    slotSocketErro
	// FullName:  SocketNetWorkShareLib::slotSocketErro
	// Access:    private 
	// Returns:   void
	// Qualifier: socket错误
	// Parameter: QAbstractSocket::SocketError
	//************************************
	void slotSocketErro(QAbstractSocket::SocketError);

signals:
	//************************************
	// Method:    sigSendReadData
	// FullName:  SocketNetWorkShareLib::sigSendReadData
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送服务器过来得数据
	// Parameter: QByteArray
	//************************************
	void sigSendReadData(QByteArray);

	//************************************
	// Method:    sigDisConnectServer
	// FullName:  SocketNetWorkShareLib::sigDisConnectServer
	// Access:    private 
	// Returns:   void
	// Qualifier: 与服务器断开连接
	//************************************
	void sigDisConnectServer();
private:
	QTcpSocket *mSocketClient;
};

#endif // SOCKETNETWORKSHARELIB_H
