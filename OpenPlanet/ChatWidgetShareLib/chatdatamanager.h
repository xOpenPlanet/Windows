#ifndef CHATDATAMANAGER_H
#define CHATDATAMANAGER_H

#include <QObject>
#include "chatwidget.h"
#include "imtranstype.h"
#include "imperchat.h"
#include "groupwidget.h"
#include "imrequestbuddyinfo.h"
#include "messagelog/messagelog.h"

class ChatDataManager : public QObject
{
	Q_OBJECT

public:
	ChatDataManager(QObject *parent=NULL);
	~ChatDataManager();

	ChatWidget *getChatWidget();

public slots:
	//************************************
	// Method:    recvChat
	// FullName:  ChatDataManager::recvOpenChat
	// Access:    public 
	// Returns:   void
	// Qualifier: 
	// Parameter: int type
	// Parameter: QVariant message
	// Parameter: QVariant buddy
	//************************************
	void recvChat(int type, QVariant message, QVariant buddy = QVariant());

private slots:
    void slotClickedChat(QString);
	void slotCloseChat(QString);

	void slotParseGroupBuddyInfo(QString, QList<BuddyInfo>);

	void slotUpdateMessageState(MessageInfo, int);
	void slotShowPerLog(QString buddyID);
	void slotOpenGroupLog(QString groupID);
	void slotRevOtherDeviceMsg(MessageInfo);
private:
	IMPerChat *getPerChat(QString uesrID);
	GroupWidget *getGroupChat(QString groupID);

	//************************************
	// Method:    readHistoryMessage
	// FullName:  ChatDataManager::readHistoryMessage
	// Access:    private 
	// Returns:   void
	// Qualifier:
	//************************************
	void readHistoryMessage();

	//************************************
	// Method:    RecvFileMessage
	// FullName:  ChatDataManager::RecvFileMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 接收到文件消息
	// Parameter: MessageInfo msgInfo
	// Parameter: QString Avatar
	//************************************
	void RecvFileMessage(MessageInfo msgInfo, QString Avatar);

	// Qualifier: 处理接收到的个人消息
	void OnDealPerMessage(QVariant message, QVariant info);

	// Qualifier: 处理接收到的群组消息
	void OnDealGroupMessage(QVariant message, QVariant info);

	// Qualifier: 处理接收到的打开个人消息
	void  OnDealOpenPerMessage(QVariant message);

	// Qualifier: 处理接收到的打开群组消息
	void  OnDealOpenGroupMessage(QVariant message);

	// Qualifier: 处理接收到的更新好友消息
	void  OnDealBuddyUpdateMessage(QVariant message);

	// Qualifier: 处理接收到的更新群组消息
	void OnDealGroupUpdateMessage(QVariant message);

	// Qualifier: 处理接收到的退出群组消息
	void OnDealQuitGroupMessage(QVariant message);

	// Qualifier: 处理接收到的群组添加用户消息
	void OnDealGroupAddUserMessage(QVariant message);

signals:
	// Qualifier: 窗口最小化
	void sigWidgetMinSize();

	// Qualifier: 还原窗口
	void sigShowNormalWindow();

	void sigDealTrayIocnFlash(QString);

	void sigCountMessageNum(int);
private:
	ChatWidget *chatWidget;
	MessageList *messageList;
	QStackedWidget *stackedWidget;
	MessageLog *messageLog;
};

#endif // CHATDATAMANAGER_H
