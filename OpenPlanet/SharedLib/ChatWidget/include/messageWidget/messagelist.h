#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QKeyEvent>
#include "cfrientitemmessage.h"
#include "imbuddy.h"
#include "imusermessage.h"
#include <QDebug>

class MessageList : public QListWidget
{
	Q_OBJECT

public:
	MessageList(QWidget *parent);
	~MessageList();

	MessageListInfo OnInsertPerToPerMessage(MessageInfo, BuddyInfo);

	MessageListInfo OnInsertPerToGroupMessage(MessageInfo, GroupInfo);

	MessageListInfo OnClickPerMessage(MessageInfo, BuddyInfo);

	MessageListInfo OnClickGroupMessage(MessageInfo, GroupInfo);

	void OnInsertMessage(QString strUserID, QString strPicPath, QString strNickName, QString strAutoGrapthText, QString strMessageTime, QString strMessageNum, int nType = 0, int nHeight = 64);

	void OnUpdateMessage(bool isGroup, QVariant var);

	int getMessageUnreadNum();

protected:
	void keyPressEvent(QKeyEvent * event);
	void enterEvent(QEvent * event);
	void leaveEvent(QEvent * event);

signals:
	void sigDoubleClickItem(QString);
	
	void sigCloseChat(QString);

	void sigDealTrayIocnFlash(QString);

	void sigMessageNum(int);

	//void 

private slots:
	void doDoubleClickedItem(QListWidgetItem *item);

	void slotCountMessageNum();

	void slotKeyUpDown(QKeyEvent *);
};

#endif // MESSAGELIST_H
