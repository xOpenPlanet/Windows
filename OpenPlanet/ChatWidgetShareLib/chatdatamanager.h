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
	// Qualifier: ���յ��ļ���Ϣ
	// Parameter: MessageInfo msgInfo
	// Parameter: QString Avatar
	//************************************
	void RecvFileMessage(MessageInfo msgInfo, QString Avatar);

	// Qualifier: ������յ��ĸ�����Ϣ
	void OnDealPerMessage(QVariant message, QVariant info);

	// Qualifier: ������յ���Ⱥ����Ϣ
	void OnDealGroupMessage(QVariant message, QVariant info);

	// Qualifier: ������յ��Ĵ򿪸�����Ϣ
	void  OnDealOpenPerMessage(QVariant message);

	// Qualifier: ������յ��Ĵ�Ⱥ����Ϣ
	void  OnDealOpenGroupMessage(QVariant message);

	// Qualifier: ������յ��ĸ��º�����Ϣ
	void  OnDealBuddyUpdateMessage(QVariant message);

	// Qualifier: ������յ��ĸ���Ⱥ����Ϣ
	void OnDealGroupUpdateMessage(QVariant message);

	// Qualifier: ������յ����˳�Ⱥ����Ϣ
	void OnDealQuitGroupMessage(QVariant message);

	// Qualifier: ������յ���Ⱥ������û���Ϣ
	void OnDealGroupAddUserMessage(QVariant message);

signals:
	// Qualifier: ������С��
	void sigWidgetMinSize();

	// Qualifier: ��ԭ����
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
