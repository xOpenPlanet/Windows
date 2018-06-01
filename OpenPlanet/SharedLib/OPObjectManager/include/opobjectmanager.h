#ifndef OPOBJECTMANAGER_H
#define OPOBJECTMANAGER_H

#include <QObject>
#include "imrequestbuddyinfo.h"
#include "imsocketmessageinfo.h"
#include "opwindowsmanagersharelib.h"
#include "parsesystemmessage.h"
#include "updatesharelib.h"

class OPObjectManager : public QObject
{
	Q_OBJECT
public:
	OPObjectManager(QObject *parent = NULL);
	~OPObjectManager();

	// Qualifier: 更新方法
	void update();

	// Qualifier: 读取配置信息
	AppConfig readAppConf();

	// Qualifier: 启动LoginWidget
	void StartLoginWidget();

	// Qualifier: 初始化程序
	void InitApp();
private:
	// Qualifier: 注册信号类型
	void RegisterMetaType();

	// Qualifier: 初始化日志信息
	void InitLog();

	// Qualifier: 日志信息
	void LogInfo(QtMsgType type, const QMessageLogContext &context, const QString &msg);

	// Qualifier: 请求个人信息
	void RequestPersonInfo();

	// Qualifier: 请求好友信息
	void RequestBuddyInfo();

	// Qualifier: 请求群组信息
	void RequestGroupInfo();

	// Qualifier: 连接socket
	void ConnectSocketServer();

	// Qualifier: 判断是否请求好友信息
	void InitBuddyInfo();

	// Qualifier: 判断是否请求群组信息
	void InitGroupInfo();

	// Qualifier: 加载好友信息
	void LoadBuddyInfo();

	// Qualifier: 加载群组信息
	void LoadGroupInfo();

	// Qualifier: 解析从服务器返回给的个人信息
	UserInfo ParseUserInfoFromServer(QVariantMap varMap);

private slots:
	// Qualifier: 启动程序的槽。
	void slotStart();

	// Qualifier: 登陆成功
	void slotLoginSuccess(QVariantMap varMap);

	// Qualifier: 解析个人信息成功
	void slotParsePersonInfo(bool bResult, UserInfo userInfo);

	//Qualifier: 接收到系统消息
	void slotRevSystemMessage(MessageInfo);

	//Qualifier: 接收到消息
	void slotRevMsgInfo(MessageInfo, int);

	//Qualifier: 接收到消息
	//void slotRevUpdateMessageState(MessageInfo, int);

	//Qualifier: 获取socket信息失败
	void slotGetSocketAddressErro(QString);

	//Qualifier: 连接socket成功
	void slotConnectSocketSuccess();

	//Qualifier:重连socket成功
	void slotReConnectSuccess();

	void slotExit();

	//读取基地地址成功后，加载好友和群组信息。
	void slotInitBuddyGroup();

signals:
	void sigReConnectServerSuccess(QString msg);

	void sigUpdateBuddyInfo(BuddyInfo buddyInfo);

private:
	OPWindowsManagerShareLib *mWindowManager;
	ParseSystemMessage *sysMessage;
};

#endif // OPOBJECTMANAGER_H
