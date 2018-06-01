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
	// Qualifier: ���·���
	//************************************
	void update();

	//************************************
	// Method:    readAppConf
	// FullName:  IMObjectManager::readAppConf
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ȡ������Ϣ
	//************************************
	AppConfig readAppConf();

	//************************************
	// Method:    StartLoginWidget
	// FullName:  IMObjectManager::StartLoginWidget
	// Access:    public 
	// Returns:   void
	// Qualifier: ����LoginWidget
	//************************************
	void StartLoginWidget();

	//************************************
	// Method:    InitApp
	// FullName:  IMObjectManager::InitApp
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ʼ������
	//************************************
	void InitApp();
private:
	//************************************
	// Method:    OnInitWebSocketServer
	// FullName:  IMObjectManager::OnInitWebSocketServer
	// Access:    private 
	// Returns:   void
	// Qualifier: ��ʼ��websocket
	// Parameter: AppConfig appConf
	//************************************
	void OnInitWebSocketServer(AppConfig appConf);

	//************************************
	// Method:    OnInitHttpServer
	// FullName:  IMObjectManager::OnInitHttpServer
	// Access:    private 
	// Returns:   void
	// Qualifier: ��ʼ��HttpServer
	// Parameter: AppConfig appConf
	//************************************
	void OnInitHttpServer(AppConfig appConf);
	//************************************
	// Method:    RegisterMetaType
	// FullName:  IMObjectManager::RegisterMetaType
	// Access:    private 
	// Returns:   void
	// Qualifier: ע���ź�����
	//************************************
	void RegisterMetaType();

	//************************************
	// Method:    InitLog
	// FullName:  IMObjectManager::InitLog
	// Access:    private 
	// Returns:   void
	// Qualifier: ��ʼ����־��Ϣ
	//************************************
	void InitLog();

	//************************************
	// Method:    LogInfo
	// FullName:  IMObjectManager::LogInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ��־��Ϣ
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
	// Qualifier: ���������Ϣ
	//************************************
	void RequestPersonInfo();

	//************************************
	// Method:    RequestBuddyInfo
	// FullName:  IMObjectManager::RequestBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ���������Ϣ
	//************************************
	void RequestBuddyInfo();

	//************************************
	// Method:    RequestGroupInfo
	// FullName:  IMObjectManager::RequestGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ����Ⱥ����Ϣ
	//************************************
	void RequestGroupInfo();

	//************************************
	// Method:    ConnectSocketServer
	// FullName:  IMObjectManager::ConnectSocket
	// Access:    private 
	// Returns:   void
	// Qualifier: ����socket
	//************************************
	void ConnectSocketServer();

	//************************************
	// Method:    JudgetIsReuestBuddyInfo
	// FullName:  IMObjectManager::JudgetIsReuestBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: �ж��Ƿ����������Ϣ
	//************************************
	void InitBuddyInfo();

	//************************************
	// Method:    JudgeIsRequestGroupInfo
	// FullName:  IMObjectManager::JudgeIsRequestGroupInfo
	// Access:    private 
	// Returns:   bool
	// Qualifier: �ж��Ƿ�����Ⱥ����Ϣ
	//************************************
	void InitGroupInfo();

	//************************************
	// Method:    LoadBuddyInfo
	// FullName:  IMObjectManager::LoadBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ���غ�����Ϣ
	//************************************
	void LoadBuddyInfo();

	//************************************
	// Method:    LoadGroupInfo
	// FullName:  IMObjectManager::LoadGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ����Ⱥ����Ϣ
	//************************************
	void LoadGroupInfo();
private slots:
    //************************************
    // Method:    slotStart
    // FullName:  IMObjectManager::slotStart
    // Access:    private 
    // Returns:   void
    // Qualifier: ��������Ĳۡ�
    //************************************
    void slotStart();
	//************************************
	// Method:    slotLoginSuccess
	// FullName:  IMObjectManager::slotLoginSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: ��½�ɹ�
	// Parameter: UserInfo
	//************************************
	void slotLoginSuccess(UserInfo);

	//************************************
	// Method:    slotParsePersonInfo
	// FullName:  IMObjectManager::slotParsePersonInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ����������Ϣ�ɹ�
	// Parameter: bool bResult
	// Parameter: UserInfo userInfo
	//************************************
	void slotParsePersonInfo(bool bResult, UserInfo userInfo);

	//Qualifier: ���յ�ϵͳ��Ϣ
	void slotRevSystemMessage(MessageInfo);

	//Qualifier: ���յ���Ϣ
	void slotRevMsgInfo(MessageInfo,int);

	//Qualifier: ���յ���Ϣ
//	void slotRevUpdateMessageState(MessageInfo, int);

	//Qualifier: ��ȡsocket��Ϣʧ��
	void slotGetSocketAddressErro(QString);

	//Qualifier: ����socket�ɹ�
	void slotConnectSocketSuccess();

	//Qualifier:����socket�ɹ�
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
