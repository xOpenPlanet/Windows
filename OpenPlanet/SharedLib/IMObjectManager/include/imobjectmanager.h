#ifndef IMOBJECTMANAGER_H
#define IMOBJECTMANAGER_H

#include <QObject>
#include "imrequestbuddyinfo.h"
#include "imsocketmessageinfo.h"
#include "imwindowsmanagersharelib.h"
#include "parsesystemmessage.h"
#include "updatesharelib.h"
#include "imwebsocketsharelib.h"
#include "imhttpserversharelib.h"

class IMObjectManager : public QObject
{
	Q_OBJECT
public:
	IMObjectManager(QObject *parent = NULL);
	~IMObjectManager();

	//************************************
	// Method:    update
	// FullName:  IMObjectManager::update
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新方法
	//************************************
	void update();

	//************************************
	// Method:    readAppConf
	// FullName:  IMObjectManager::readAppConf
	// Access:    public 
	// Returns:   void
	// Qualifier: 读取配置信息
	//************************************
	AppConfig readAppConf();

	//************************************
	// Method:    StartLoginWidget
	// FullName:  IMObjectManager::StartLoginWidget
	// Access:    public 
	// Returns:   void
	// Qualifier: 启动LoginWidget
	//************************************
	void StartLoginWidget();

	//************************************
	// Method:    InitApp
	// FullName:  IMObjectManager::InitApp
	// Access:    public 
	// Returns:   void
	// Qualifier: 初始化程序
	//************************************
	void InitApp();
private:
	//************************************
	// Method:    OnInitWebSocketServer
	// FullName:  IMObjectManager::OnInitWebSocketServer
	// Access:    private 
	// Returns:   void
	// Qualifier: 初始化websocket
	// Parameter: AppConfig appConf
	//************************************
	void OnInitWebSocketServer(AppConfig appConf);

	//************************************
	// Method:    OnInitHttpServer
	// FullName:  IMObjectManager::OnInitHttpServer
	// Access:    private 
	// Returns:   void
	// Qualifier: 初始化HttpServer
	// Parameter: AppConfig appConf
	//************************************
	void OnInitHttpServer(AppConfig appConf);
	//************************************
	// Method:    RegisterMetaType
	// FullName:  IMObjectManager::RegisterMetaType
	// Access:    private 
	// Returns:   void
	// Qualifier: 注册信号类型
	//************************************
	void RegisterMetaType();

	//************************************
	// Method:    InitLog
	// FullName:  IMObjectManager::InitLog
	// Access:    private 
	// Returns:   void
	// Qualifier: 初始化日志信息
	//************************************
	void InitLog();

	//************************************
	// Method:    LogInfo
	// FullName:  IMObjectManager::LogInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 日志信息
	// Parameter: QtMsgType type
	// Parameter: const QMessageLogContext & context
	// Parameter: const QString & msg
	//************************************
	void LogInfo(QtMsgType type, const QMessageLogContext &context, const QString &msg);

	//************************************
	// Method:    RequestPersonInfo
	// FullName:  IMObjectManager::RequestPersonInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 请求个人信息
	//************************************
	void RequestPersonInfo();

	//************************************
	// Method:    RequestBuddyInfo
	// FullName:  IMObjectManager::RequestBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 请求好友信息
	//************************************
	void RequestBuddyInfo();

	//************************************
	// Method:    RequestGroupInfo
	// FullName:  IMObjectManager::RequestGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 请求群组信息
	//************************************
	void RequestGroupInfo();

	//************************************
	// Method:    ConnectSocketServer
	// FullName:  IMObjectManager::ConnectSocket
	// Access:    private 
	// Returns:   void
	// Qualifier: 连接socket
	//************************************
	void ConnectSocketServer();

	//************************************
	// Method:    JudgetIsReuestBuddyInfo
	// FullName:  IMObjectManager::JudgetIsReuestBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 判断是否请求好友信息
	//************************************
	void InitBuddyInfo();

	//************************************
	// Method:    JudgeIsRequestGroupInfo
	// FullName:  IMObjectManager::JudgeIsRequestGroupInfo
	// Access:    private 
	// Returns:   bool
	// Qualifier: 判断是否请求群组信息
	//************************************
	void InitGroupInfo();

	//************************************
	// Method:    LoadBuddyInfo
	// FullName:  IMObjectManager::LoadBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 加载好友信息
	//************************************
	void LoadBuddyInfo();

	//************************************
	// Method:    LoadGroupInfo
	// FullName:  IMObjectManager::LoadGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 加载群组信息
	//************************************
	void LoadGroupInfo();
private slots:
    //************************************
    // Method:    slotStart
    // FullName:  IMObjectManager::slotStart
    // Access:    private 
    // Returns:   void
    // Qualifier: 启动程序的槽。
    //************************************
    void slotStart();
	//************************************
	// Method:    slotLoginSuccess
	// FullName:  IMObjectManager::slotLoginSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: 登陆成功
	// Parameter: UserInfo
	//************************************
	void slotLoginSuccess(UserInfo);

	//************************************
	// Method:    slotParsePersonInfo
	// FullName:  IMObjectManager::slotParsePersonInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 解析个人信息成功
	// Parameter: bool bResult
	// Parameter: UserInfo userInfo
	//************************************
	void slotParsePersonInfo(bool bResult, UserInfo userInfo);

	//Qualifier: 接收到系统消息
	void slotRevSystemMessage(MessageInfo);

	//Qualifier: 接收到消息
	void slotRevMsgInfo(MessageInfo,int);

	//Qualifier: 接收到消息
//	void slotRevUpdateMessageState(MessageInfo, int);

	//Qualifier: 获取socket信息失败
	void slotGetSocketAddressErro(QString);

	//Qualifier: 连接socket成功
	void slotConnectSocketSuccess();

	//Qualifier:重连socket成功
	void slotReConnectSuccess();

	void slotExit();
signals:
	void sigReConnectServerSuccess(QString msg);

	void sigUpdateBuddyInfo(BuddyInfo buddyInfo);
private:
	IMWindowsManagerShareLib *mWindowManager;

	IMWebSocketShareLib* m_pWebSocket;

	IMHttpServerShareLib *m_pHttpServer;
};

#endif // IMOBJECTMANAGER_H
