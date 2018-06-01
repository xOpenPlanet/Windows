#include "chatdatamanager.h"


ChatDataManager::ChatDataManager(QObject *parent)
	: QObject(parent)
{
	messageLog = NULL;
	chatWidget = new ChatWidget();
	messageList = chatWidget->getMessageList();
	readHistoryMessage();
	stackedWidget = chatWidget->getStackedWidget();

	connect(messageList, SIGNAL(sigDoubleClickItem(QString)), this, SLOT(slotClickedChat(QString)));
	connect(messageList, SIGNAL(sigCloseChat(QString)), this, SLOT(slotCloseChat(QString)));
	connect(messageList, SIGNAL(sigDealTrayIocnFlash(QString)), this, SIGNAL(sigDealTrayIocnFlash(QString)));
	connect(messageList, SIGNAL(sigMessageNum(int)), this, SIGNAL(sigCountMessageNum(int)));
}

ChatDataManager::~ChatDataManager()
{

}

ChatWidget * ChatDataManager::getChatWidget()
{
	return chatWidget;
}

void ChatDataManager::recvChat(int type, QVariant message, QVariant info)
{
	switch (type)
	{
	case PerMessage:
		OnDealPerMessage(message,info);
		break;
	case GroupMessage:
		OnDealGroupMessage(message, info);
		break;
	case OpenPer:
		OnDealOpenPerMessage(message);
		break;
	case OpenGroup:
		OnDealOpenGroupMessage(message);
		break;
	case BuddyUpdate:
		OnDealBuddyUpdateMessage(message);
		break;
	case GroupUpdate:
		OnDealGroupUpdateMessage(message);
		break;
	case QuitGroup:
		OnDealQuitGroupMessage(message);
		break;
	case GroupAddUser:
		OnDealGroupAddUserMessage(message);
		break;
	default:
		break;
	}
}

// Qualifier: 处理接收到的个人消息
void ChatDataManager::OnDealPerMessage(QVariant message, QVariant info)
{
	MessageInfo messageInfo = message.value<MessageInfo>();
	BuddyInfo buddyInfo = info.value<BuddyInfo>();
	MessageListInfo listInfo = messageList->OnInsertPerToPerMessage(messageInfo, buddyInfo);
	gDataBaseOpera->DBInsertPerMessageListInfo(listInfo);
	IMPerChat *perChat = NULL;
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		QString widgetID = widget->objectName();
		if (widgetID.toInt() == buddyInfo.nUserId)
			perChat = (IMPerChat *)widget;
	}

	if (perChat)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		/*判断是不是当前窗口，如果是当前窗口，需要设置消息已读*/
		QWidget *currentWidget = stackedWidget->currentWidget();
		if (currentWidget)
		{
			if ((IMPerChat *)currentWidget == perChat)
			{
				QList<QByteArray> msgIDList = gSocketMessage->SetPerMessageRead(messageInfo.nFromUserID);
				for (int i = 0; i < msgIDList.size(); i++)
				{
					gSocketMessage->SetMessageState(msgIDList[i], MESSAGE_STATE_READ);
					gSocketMessage->SendMessageReadMessage(userInfo.nUserID, messageInfo.nFromUserID, 0, QString(msgIDList[i]));
				}
			}
		}

		switch (messageInfo.MessageChildType)
		{
		case 0: // 文字消息
			perChat->OnInsertRecMessageTextInfo(messageInfo.strMsg, buddyInfo.strLocalAvatar, QString(messageInfo.msgID), messageInfo.integral);
			break;
		case 1: // 图片消息
			perChat->OnRecvImgMessage(messageInfo, buddyInfo.strLocalAvatar);
			break;
		case 3: //视频消息
			perChat->OnRecVdoMessage(messageInfo, buddyInfo.strLocalAvatar);
			break;
		case 5://文件消息
			if (gDataBaseOpera)
			{
				QString strLocalFilePath = gDataBaseOpera->DBGetFileInfoLocalPath(messageInfo.msgID);
				perChat->OnRecvFileMessage(messageInfo, buddyInfo.strLocalAvatar, strLocalFilePath);
			}
			break;
		case 62:      //任务消息
			perChat->OnRecvTaskMessage(messageInfo, buddyInfo.strLocalAvatar);
			break;
		default:
			break;
		}
	}
}

// Qualifier: 处理接收到的群组消息
void ChatDataManager::OnDealGroupMessage(QVariant message, QVariant info)
{
	MessageInfo messageInfo = message.value<MessageInfo>();
	GroupInfo groupInfo = info.value<GroupInfo>();
	MessageListInfo listInfo = messageList->OnInsertPerToGroupMessage(messageInfo, groupInfo);
	gDataBaseOpera->DBInsertGroupMessageListInfo(listInfo);
	GroupWidget *groupChat = NULL;
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		QString widgetID = widget->objectName();
		if (widgetID == groupInfo.groupId)
			groupChat = (GroupWidget *)widget;
	}
	if (groupChat)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		/*判断是不是当前窗口，如果是当前窗口，需要设置消息已读*/
		QWidget *currentWidget = stackedWidget->currentWidget();
		if (currentWidget)
		{
			if ((GroupWidget *)currentWidget == groupChat)
			{
				QList<QByteArray> msgIDList = gSocketMessage->SetPerMessageRead(messageInfo.nFromUserID);
				for (int i = 0; i < msgIDList.size(); i++)
				{
					gSocketMessage->SetMessageState(msgIDList[i], MESSAGE_STATE_READ);
					gSocketMessage->SendMessageReadMessage(userInfo.nUserID, messageInfo.nFromUserID, 1, QString(msgIDList[i]));
				}
			}
		}
		groupChat->OnInsertRevMessage(messageInfo);
	}
}

// Qualifier: 处理接收到的打开个人消息
void ChatDataManager::OnDealOpenPerMessage(QVariant message)
{
	MessageInfo messageInfo;
	messageInfo.ClientTime = QDateTime::currentMSecsSinceEpoch();
	messageInfo.MessageChildType = 0;
	messageInfo.strMsg = "";
	BuddyInfo buddyInfo = gDataBaseOpera->DBGetBuddyInfoByID(message.toString());
	//从群组中打开个人聊天界面的情况
	if (buddyInfo.strNickName.isEmpty())
		buddyInfo = gDataBaseOpera->DBGetGroupUserFromID(message.toString());

	MessageListInfo listInfo = messageList->OnClickPerMessage(messageInfo, buddyInfo);
	gDataBaseOpera->DBInsertPerMessageListInfo(listInfo);
	IMPerChat *perChat = getPerChat(QString::number(buddyInfo.nUserId));
	stackedWidget->setCurrentWidget(perChat);

	emit sigDealTrayIocnFlash(QString::number(buddyInfo.nUserId));
}

// Qualifier: 处理接收到的打开群组消息
void ChatDataManager::OnDealOpenGroupMessage(QVariant message)
{
	MessageInfo messageInfo;
	messageInfo.ClientTime = QDateTime::currentMSecsSinceEpoch();
	messageInfo.MessageChildType = 0;
	messageInfo.strMsg = "";
	GroupInfo groupInfo = gDataBaseOpera->DBGetGroupFromID(message.toString());
	MessageListInfo listInfo = messageList->OnClickGroupMessage(messageInfo, groupInfo);
	gDataBaseOpera->DBInsertGroupMessageListInfo(listInfo);
	GroupWidget *groupWidget = getGroupChat(groupInfo.groupId);
	stackedWidget->setCurrentWidget(groupWidget);

	emit sigDealTrayIocnFlash(groupInfo.groupId);
}

// Qualifier: 处理接收到的更新好友消息
void ChatDataManager::OnDealBuddyUpdateMessage(QVariant message)
{
	messageList->OnUpdateMessage(false, message);
	BuddyInfo buddyInfo = message.value<BuddyInfo>();
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		if (widget)
		{
			if (widget->objectName() == QString::number(buddyInfo.nUserId))
			{
				IMPerChat *perChat = (IMPerChat *)widget;
				if (buddyInfo.strNote.isEmpty())
					perChat->OnSetNikeName(buddyInfo.strNickName, QString::number(buddyInfo.nUserId));
				else
					perChat->OnSetNikeName(buddyInfo.strNote, QString::number(buddyInfo.nUserId));
				break;
			}
		}
	}
}

// Qualifier: 处理接收到的更新群组消息
void ChatDataManager::OnDealGroupUpdateMessage(QVariant message)
{
	messageList->OnUpdateMessage(true, message);
	GroupInfo groupInfo = message.value<GroupInfo>();
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		if (widget)
		{
			if (widget->objectName() == groupInfo.groupId)
			{
				GroupWidget *groupChat = (GroupWidget *)widget;

				groupChat->OnSetGroupName(groupInfo.groupName, groupInfo.groupId);
				break;
			}
		}
	}
}

// Qualifier: 处理接收到的退出群组消息
void ChatDataManager::OnDealQuitGroupMessage(QVariant message)
{
	QString groupID = message.toString();
	QString userID = message.toString();
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		if (widget)
		{
			if (widget->objectName() == groupID)
			{
				GroupWidget *groupChat = (GroupWidget *)widget;

				groupChat->userQuitGroup(userID);
				break;
			}
		}
	}
}

// Qualifier: 处理接收到的群组添加用户消息
void ChatDataManager::OnDealGroupAddUserMessage(QVariant message)
{
	QString groupID = message.toString();
	BuddyInfo buddyInfo = message.value<BuddyInfo>();
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		if (widget)
		{
			if (widget->objectName() == groupID)
			{
				GroupWidget *groupChat = (GroupWidget *)widget;
				groupChat->OnInsertGroupUser(buddyInfo);
				break;
			}
		}
	}
}

IMPerChat * ChatDataManager::getPerChat(QString uesrID)
{
	IMPerChat *perChat = NULL;
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		if (widget)
		{
			QString widgetID = widget->objectName();
			if (widgetID == uesrID)
				perChat = (IMPerChat *)widget;
		}
	}

	if (perChat == NULL)
	{
		perChat = new IMPerChat();
		connect(perChat, SIGNAL(sigOpenPerLog(QString)), this, SLOT(slotShowPerLog(QString)));
		connect(perChat, SIGNAL(sigWidgetMinSize()), this, SIGNAL(sigWidgetMinSize()));
		connect(perChat, SIGNAL(sigShowNormalWindow()), this, SIGNAL(sigShowNormalWindow()));
		connect(perChat, SIGNAL(sigKeyUpDown(QKeyEvent *)), messageList, SLOT(slotKeyUpDown(QKeyEvent *)));
		
		BuddyInfo buddy = gDataBaseOpera->DBGetBuddyInfoByID(uesrID);
		if (buddy.strNickName.isEmpty())
			buddy = gDataBaseOpera->DBGetGroupUserFromID(uesrID);

		if (buddy.strNote.isEmpty())
			perChat->OnSetNikeName(buddy.strNickName, uesrID);
		else
			perChat->OnSetNikeName(buddy.strNote, uesrID);
		perChat->setObjectName(uesrID);
		QTimer::singleShot(100, perChat, SLOT(InitMessageInfo()));
		stackedWidget->addWidget(perChat);
	}

	return perChat;
}

GroupWidget * ChatDataManager::getGroupChat(QString groupID)
{
	GroupWidget *groupChat = NULL;
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		if (widget)
		{
			QString widgetID = widget->objectName();
			if (widgetID == groupID)
				groupChat = (GroupWidget *)widget;
		}
	}

	if (groupChat == NULL)
	{
		groupChat = new GroupWidget();
		connect(groupChat, SIGNAL(sigShowGroupBuddyPerChat(int, QVariant)), this, SLOT(recvChat(int, QVariant)));
		connect(groupChat, SIGNAL(sigOpenGroupLog(QString)), this, SLOT(slotOpenGroupLog(QString)));
		connect(groupChat, SIGNAL(sigGroupMinSize()), this, SIGNAL(sigWidgetMinSize()));
		connect(groupChat, SIGNAL(sigShowNormalWindow()), this, SIGNAL(sigShowNormalWindow()));
		connect(groupChat, SIGNAL(sigKeyUpDown(QKeyEvent *)), messageList, SLOT(slotKeyUpDown(QKeyEvent *)));

		GroupInfo groupInfo = gDataBaseOpera->DBGetGroupFromID(groupID);
		groupChat->OnSetGroupName(groupInfo.groupName, groupID);
		groupChat->setObjectName(groupID);
		QTimer::singleShot(100, groupChat, SLOT(OnInitMessage()));
		groupChat->OnInitMessage(groupID);
		stackedWidget->addWidget(groupChat);
		//如果群组成员没有下载，就下载群组成员。
		if (gDataBaseOpera->DBJudgetGroupBuddyIsEmpty(groupID))
		{
			IMRequestBuddyInfo *request = new IMRequestBuddyInfo();
			UserInfo userInfo = gDataManager->getUserInfo();
			QString url = gDataManager->getAppConfigInfo().MessageServerAddress;
			connect(request, SIGNAL(sigParseGroupBuddyInfo(QString, QList<BuddyInfo>)), this, SLOT(slotParseGroupBuddyInfo(QString, QList<BuddyInfo>)));
			request->RequestGroupBuddyInfo(url, QString::number(userInfo.nUserID), userInfo.strUserPWD, groupID);
		}
		else
			groupChat->OnInsertGroupUserList(groupID);
	}

	return groupChat;
}

void ChatDataManager::slotClickedChat(QString userID)
{
	for (int i = 0; i < stackedWidget->count(); i++)
	{
		QWidget *widget = stackedWidget->widget(i);
		if (widget)
		{
			QString widgetID = widget->objectName();
			if (widgetID == userID)
			{
				stackedWidget->setCurrentWidget(widget);
				return;
			}
		}
	}

	UserInfo userInfo = gDataManager->getUserInfo();

	//没有该聊天界面，创建。
	if (gDataBaseOpera->DBJudgeGroupIsHaveByID(userID))  //是群组
	{
		GroupWidget *groupWidget = getGroupChat(userID);
		if (groupWidget)
		{
			stackedWidget->setCurrentWidget(groupWidget);
			QList<QByteArray> msgIDList = gSocketMessage->SetGroupMessageRead(userID.toInt());
			for (int i = 0; i < msgIDList.size(); i++)
			{
				gSocketMessage->SetMessageState(msgIDList[i], MESSAGE_STATE_READ);
				gSocketMessage->SendMessageReadMessage(userInfo.nUserID, userID.toInt(), 1, QString(msgIDList[i]));
			}
		}
	}
	else
	{
		IMPerChat *perWidget = getPerChat(userID);
		if (perWidget)
		{
			stackedWidget->setCurrentWidget(perWidget);
		}
		QList<QByteArray> msgIDList = gSocketMessage->SetPerMessageRead(userID.toInt());

		for (int i = 0; i < msgIDList.size(); i++)
		{
			gSocketMessage->SetMessageState(msgIDList[i], MESSAGE_STATE_READ);
			gSocketMessage->SendMessageReadMessage(userInfo.nUserID, userID.toInt(), 0, QString(msgIDList[i]));
		}
	}

	/*更改数据库状态*/
	gDataBaseOpera->DBUpdateMessageListInfo(userID.toInt());

	QTimer::singleShot(500, messageList, SLOT(setFocus()));
}

void ChatDataManager::slotCloseChat(QString userID)
{
	for (int i = 0; i < messageList->count(); i++)
	{
		QWidget *item = messageList->itemWidget(messageList->item(i));
		if (item)
		{
			CFrientItemMessage *message = (CFrientItemMessage *)item;
			if (message)
			{
				if (message->mNickName->objectName() == userID)
				{
					messageList->takeItem(i);
					for (int j = 0; j < stackedWidget->count(); j++)
					{
						QWidget *widget = stackedWidget->widget(j);
						if (widget)
						{
							if (widget->objectName() == userID)
							{
								widget->deleteLater();
								stackedWidget->removeWidget(widget);
							}
						}
					}
					gDataBaseOpera->DBDeleteMessageByID(userID);
					break;
				}
			}
		}
	}
}

void ChatDataManager::slotParseGroupBuddyInfo(QString groupID, QList<BuddyInfo> list)
{
	for (int i = 0; i < list.count(); i++)
		gDataBaseOpera->DBInsertGroupBuddyInfo(groupID, list.at(i));

	for (int j = 0; j < stackedWidget->count(); j++)
	{
		QWidget *widget = stackedWidget->widget(j);
		if (widget)
		{
			QString widgetID = widget->objectName();
			if (widgetID == groupID)
			{
				GroupWidget *groupWidget = (GroupWidget *)widget;
				groupWidget->OnInsertGroupUserList(groupID);
			}
		}
	}
}

void ChatDataManager::slotUpdateMessageState(MessageInfo msgInfo, int nState)
{
	switch (msgInfo.MsgDeliverType)
	{
	case 0:
	{
			  IMPerChat *perChat = NULL;
			  for (int i = 0; i < stackedWidget->count(); i++)
			  {
				  QWidget *widget = stackedWidget->widget(i);
				  if (widget)
				  {
					  QString widgetID = widget->objectName();
					  if (widgetID.toInt() == msgInfo.nToUserID)
					  {
						  perChat = (IMPerChat *)widget;
						  if (perChat)
						  {
							  perChat->UpdateMessageStateInfo(msgInfo.msgID, nState, msgInfo.integral);
							  if (nState == MESSAGE_STATE_RECEIVE)
							  {
								  qDebug() << "MESSAGE_STATE_RECEIVE " << msgInfo.integral;
							  }
							  else if (nState == MESSAGE_STATE_READ)
							  {
								  qDebug() << "MESSAGE_STATE_READ " << msgInfo.integral;
							  }
						  }
						  break;
					  }
				  }
			  }
	}
		break;
	case 1:
	{
			  GroupWidget *groupChat = NULL;
			  for (int i = 0; i < stackedWidget->count(); i++)
			  {
				  QWidget *widget = stackedWidget->widget(i);
				  if (widget)
				  {
					  QString widgetID = widget->objectName();
					  if (widgetID == QString::number(msgInfo.nToUserID))
					  {
						  groupChat = (GroupWidget *)widget;
						  if (groupChat)
						  {
							  groupChat->UpdateMessageStateInfo(msgInfo.msgID, nState, msgInfo.integral);
						  }
						  break;
					  }
				  }
			  }
	}
		break;
	default:
		break;
	}
}

void ChatDataManager::readHistoryMessage()
{
	QList<MessageListInfo> listInfo = gDataBaseOpera->DBGetALLMessageListInfo();

	for (int i = 0; i < listInfo.size(); i++)
	{
		QString strEndMsg;
		QDateTime dt = QDateTime::fromTime_t(listInfo[i].nLastTime);
		QString strTime = dt.toString("hh:mm:ss");
		if (dt.daysTo(QDateTime::currentDateTime()) >= 2)
			strTime = dt.toString("M-d");

		QString strUnReadNum = "";
		if (listInfo[i].nUnReadNum == 0)
		{
			strUnReadNum = "";
		}
		else
		{
			strUnReadNum = QString("%1").arg(listInfo[i].nUnReadNum);
		}
		listInfo[i].strLastMessage.replace("\n", "");
		messageList->OnInsertMessage(QString("%1").arg(listInfo[i].nBudyyID),
			listInfo[i].strBuddyHeaderImage,
			listInfo[i].strBuddyName,
			listInfo[i].strLastMessage, strTime, QString("%1").arg(strUnReadNum), listInfo[i].isGroup);
	}

	QTimer::singleShot(500, messageList, SLOT(slotCountMessageNum()));
}

void ChatDataManager::slotShowPerLog(QString buddyID)
{
	if (messageLog == NULL)
	{
		messageLog = new MessageLog();
	}
	messageLog->loadPerLogByID(buddyID);
}

void ChatDataManager::slotOpenGroupLog(QString groupID)
{
	if (messageLog == NULL)
	{
		//增加消息记录对话框。
		messageLog = new MessageLog();
	}
	messageLog->loadGroupLogByID(groupID);
}

void ChatDataManager::slotRevOtherDeviceMsg(MessageInfo msgInfo)
{
	/*消息列表插入消息*/
	if (messageList)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		QWidget *widget = NULL;
		for (int i = 0; i < stackedWidget->count(); i++)
		{
			QWidget *page = stackedWidget->widget(i);
			if (page->objectName().toInt() == msgInfo.nToUserID)
			{
				widget = page;
				break;
			}
		}

		if (msgInfo.MsgDeliverType == 0)
		{
			BuddyInfo buddyInfo = gDataBaseOpera->DBGetBuddyInfoByID(QString::number(msgInfo.nToUserID));
			if (buddyInfo.nUserId == -1)
			{
				buddyInfo = gDataBaseOpera->DBGetGroupUserFromID(QString::number(msgInfo.nToUserID));

				if (buddyInfo.strNickName.isEmpty())
					return;
			}

			messageList->OnInsertPerToPerMessage(msgInfo, buddyInfo);
			if (widget)
			{
				IMPerChat *perChat = (IMPerChat*)widget;
				perChat->OnInertSendMessageTextInfo(msgInfo.strMsg, userInfo.strUserAvatarLocal, msgInfo);
			}
		}
		else if (msgInfo.MsgDeliverType == 1)
		{
			GroupInfo groupInfo = gDataBaseOpera->DBGetGroupFromID(QString::number(msgInfo.nToUserID));
			messageList->OnInsertPerToGroupMessage(msgInfo, groupInfo);
			if (widget)
			{
				GroupWidget *groupWidget = (GroupWidget*)widget;
				groupWidget->OnInertSendMessageTextInfo(msgInfo.strMsg, userInfo.strUserAvatarLocal, msgInfo);
			}
		}
	}
}