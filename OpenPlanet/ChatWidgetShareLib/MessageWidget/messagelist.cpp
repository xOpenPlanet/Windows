#include "messagelist.h"

MessageList::MessageList(QWidget *parent)
	: QListWidget(parent)
{
	connect(this, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(doDoubleClickedItem(QListWidgetItem *)));

	QFile scroolbar_style_qss(":/ScrollBar/Resources/QSS/scrollbarStyle.qss");
	scroolbar_style_qss.open(QFile::ReadOnly);
	this->verticalScrollBar()->setStyleSheet(scroolbar_style_qss.readAll());
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setMouseTracking(true);
}

MessageList::~MessageList()
{

}

MessageListInfo MessageList::OnInsertPerToPerMessage(MessageInfo messageinfo, BuddyInfo buddyInfo)
{
	MessageListInfo messageListInfo;

	//首先生成信息时间。
	QString strtemp = QString("%1").arg(messageinfo.ClientTime);
	if (strtemp.length() == 13)
		messageinfo.ClientTime = messageinfo.ClientTime / 1000;
	QDateTime dt = QDateTime::fromTime_t(messageinfo.ClientTime);
	QString strTime = dt.toString("hh:mm:ss");

	//根据消息类型设置显示的内容。
	if (messageinfo.MessageChildType == 1) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[图片]");
	if (messageinfo.MessageChildType == 3) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[视频]");
	if (messageinfo.MessageChildType == 5) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[文件]");

	//首先判断列表中是否存在
	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		CFrientItemMessage *buddy = (CFrientItemMessage*)this->itemWidget(item);
		if (buddy != NULL)
		{
			if (buddy->mNickName->objectName().toInt() == buddyInfo.nUserId)
			{
				//更新。
				buddy->OnSetPicPath(buddyInfo.strLocalAvatar, 0);
				
				buddy->OnSetMessageTime(strTime);

				if (item->isSelected() && this->isVisible())
				{
					buddy->OnSetMessageNum("");
				}
				else
				{
					int unReadNum = buddy->getMessageNum() + 1;
					buddy->OnSetMessageNum(QString::number(unReadNum));
				}

				if (buddyInfo.strNote.isEmpty())
					buddy->OnSetNickNameText(buddyInfo.strNickName);
				else
					buddy->OnSetNickNameText(buddyInfo.strNote);

				if (messageinfo.strMsg.isEmpty())
					item->setSelected(true);
				else
					buddy->OnSetAutoGrapthText(messageinfo.strMsg);

				/*
				this->takeItem(i);
				QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
				newItem->setSizeHint(QSize(this->width(), 58));
				this->insertItem(0, newItem); //将该newItem插入到后面
				this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
				*/

				messageListInfo.nBudyyID = buddyInfo.nUserId;
				messageListInfo.strLastMessage = messageinfo.strMsg;
				messageListInfo.nLastTime = messageinfo.ClientTime;
				messageListInfo.strBuddyName = buddyInfo.strNickName;
				messageListInfo.strBuddyHeaderImage = buddyInfo.strLocalAvatar;
				messageListInfo.messageType = messageinfo.MessageChildType;
				messageListInfo.nUnReadNum = buddy->getMessageNum();
				messageListInfo.isGroup = 0;

				return messageListInfo;
			}
		}
	}

	if (this->count() >= 30)
	{
		QListWidgetItem *item = this->item(0);
		CFrientItemMessage *widget = (CFrientItemMessage *)this->itemWidget(item);
		for (int j = 1; j < this->count(); j++)
		{
			QListWidgetItem *currentItem = this->item(j);
			CFrientItemMessage *currentWidget = (CFrientItemMessage *)this->itemWidget(currentItem);
			if (widget->getLastTime() > currentWidget->getLastTime())
			{
				item = currentItem;
				widget = currentWidget;
			}
		}

		QString deleteID = widget->mNickName->objectName();
		this->takeItem(this->row(item));
	}

	QString strNick = buddyInfo.strNote.isEmpty() ? buddyInfo.strNickName : buddyInfo.strNote;

	this->OnInsertMessage(QString::number(buddyInfo.nUserId),
		buddyInfo.strLocalAvatar,
		strNick,
		messageinfo.strMsg, strTime, "1");

	messageListInfo.nBudyyID = buddyInfo.nUserId;
	messageListInfo.strLastMessage = messageinfo.strMsg;
	messageListInfo.nLastTime = messageinfo.ClientTime;
	messageListInfo.strBuddyName = buddyInfo.strNickName;
	messageListInfo.strBuddyHeaderImage = buddyInfo.strLocalAvatar;
	messageListInfo.messageType = messageinfo.MessageChildType;
	messageListInfo.nUnReadNum = 1;
	messageListInfo.isGroup = 0;

	return messageListInfo;
}

MessageListInfo MessageList::OnInsertPerToGroupMessage(MessageInfo messageinfo, GroupInfo groupInfo)
{
	MessageListInfo messageListInfo;

	QString strtemp = QString("%1").arg(messageinfo.ClientTime);
	if (strtemp.length() == 13)
		messageinfo.ClientTime = messageinfo.ClientTime / 1000;
	QDateTime dt = QDateTime::fromTime_t(messageinfo.ClientTime);
	QString strTime = dt.toString("hh:mm:ss");

	if (messageinfo.MessageChildType == 1) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[图片]");
	if (messageinfo.MessageChildType == 3) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[视频]");
	if (messageinfo.MessageChildType == 5) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[文件]");

	//首先判断列表中是否存在
	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		CFrientItemMessage *buddy = (CFrientItemMessage*)this->itemWidget(item);
		if (buddy != NULL)
		{
			if (buddy->mNickName->objectName() == groupInfo.groupId)
			{
				//buddy->OnInitMessage(groupInfo.groupId);
				buddy->OnSetPicPath(groupInfo.groupLoacalHeadImage, 1);
				buddy->OnSetNickNameText(groupInfo.groupName);
				buddy->OnSetMessageTime(strTime);

				if (item->isSelected() && this->isVisible())
				{
					buddy->OnSetMessageNum("");
				}
				else
				{
					int unReadNum = buddy->getMessageNum() + 1;
					buddy->OnSetMessageNum(QString::number(unReadNum));
				}

				if (messageinfo.strMsg.isEmpty())
					item->setSelected(true);
				else
					buddy->OnSetAutoGrapthText(messageinfo.strMsg);

				messageListInfo.nBudyyID = groupInfo.groupId.toInt();
				messageListInfo.strLastMessage = messageinfo.strMsg;
				messageListInfo.nLastTime = messageinfo.ClientTime;
				messageListInfo.strBuddyName = groupInfo.groupName;
				messageListInfo.strBuddyHeaderImage = groupInfo.groupLoacalHeadImage;
				messageListInfo.messageType = messageinfo.MessageChildType;
				messageListInfo.nUnReadNum = buddy->getMessageNum();
				messageListInfo.isGroup = 1;

				return messageListInfo;
			}
		}
	}
	
	this->OnInsertMessage(groupInfo.groupId,
		groupInfo.groupLoacalHeadImage,
		groupInfo.groupName,
		messageinfo.strMsg, strTime, "1", 1);

	//插入新的
	messageListInfo.nBudyyID = groupInfo.groupId.toInt();
	messageListInfo.strLastMessage = messageinfo.strMsg;
	messageListInfo.nLastTime = messageinfo.ClientTime;
	messageListInfo.strBuddyName = groupInfo.groupName;
	messageListInfo.strBuddyHeaderImage = groupInfo.groupLoacalHeadImage;
	messageListInfo.messageType = messageinfo.MessageChildType;
	messageListInfo.nUnReadNum = 1;
	messageListInfo.isGroup = 1;

	return messageListInfo;
}

MessageListInfo MessageList::OnClickPerMessage(MessageInfo messageinfo, BuddyInfo buddyInfo)
{
	//首先生成信息时间。
	QString strtemp = QString("%1").arg(messageinfo.ClientTime);
	if (strtemp.length() == 13)
		messageinfo.ClientTime = messageinfo.ClientTime / 1000;
	QDateTime dt = QDateTime::fromTime_t(messageinfo.ClientTime);
	QString strTime = dt.toString("hh:mm:ss");

	//根据消息类型设置显示的内容。
	if (messageinfo.MessageChildType == 1) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[图片]");
	if (messageinfo.MessageChildType == 3) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[视频]");
	if (messageinfo.MessageChildType == 5) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[文件]");

	MessageListInfo messageListInfo;
	messageListInfo.nBudyyID = buddyInfo.nUserId;
	messageListInfo.strLastMessage = messageinfo.strMsg;
	messageListInfo.nLastTime = messageinfo.ClientTime;
	messageListInfo.strBuddyName = buddyInfo.strNickName;
	messageListInfo.strBuddyHeaderImage = buddyInfo.strLocalAvatar;
	messageListInfo.messageType = messageinfo.MessageChildType;
	messageListInfo.nUnReadNum = 0;
	messageListInfo.isGroup = 0;

	//首先判断列表中是否存在
	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		CFrientItemMessage *buddy = (CFrientItemMessage*)this->itemWidget(item);
		if (buddy != NULL)
		{
			if (buddy->mNickName->objectName().toInt() == buddyInfo.nUserId)
			{
				item->setSelected(true);
				buddy->OnSetMessageNum("");
				return messageListInfo;
			}
				
		}
	}

	if (this->count() >= 30)
	{
		QListWidgetItem *item = this->item(0);
		CFrientItemMessage *widget = (CFrientItemMessage *)this->itemWidget(item);
		for (int j = 1; j < this->count(); j++)
		{
			QListWidgetItem *currentItem = this->item(j);
			CFrientItemMessage *currentWidget = (CFrientItemMessage *)this->itemWidget(currentItem);
			if (widget->getLastTime() > currentWidget->getLastTime())
			{
				item = currentItem;
				widget = currentWidget;
			}
		}

		QString deleteID = widget->mNickName->objectName();
		this->takeItem(this->row(item));
	}

	QString strNick = buddyInfo.strNote.isEmpty() ? buddyInfo.strNickName : buddyInfo.strNote;

	this->OnInsertMessage(QString::number(buddyInfo.nUserId),
		buddyInfo.strLocalAvatar,
		strNick,
		messageinfo.strMsg, strTime, "");

	return messageListInfo;
}

MessageListInfo MessageList::OnClickGroupMessage(MessageInfo messageinfo, GroupInfo groupInfo)
{
	QString strtemp = QString("%1").arg(messageinfo.ClientTime);
	if (strtemp.length() == 13)
		messageinfo.ClientTime = messageinfo.ClientTime / 1000;
	QDateTime dt = QDateTime::fromTime_t(messageinfo.ClientTime);
	QString strTime = dt.toString("hh:mm:ss");

	if (messageinfo.MessageChildType == 1) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[图片]");
	if (messageinfo.MessageChildType == 3) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[视频]");
	if (messageinfo.MessageChildType == 5) //1图片3视频5文件。
		messageinfo.strMsg = QStringLiteral("[文件]");

	MessageListInfo messageListInfo;
	messageListInfo.nBudyyID = groupInfo.groupId.toInt();
	messageListInfo.strLastMessage = messageinfo.strMsg;
	messageListInfo.nLastTime = messageinfo.ClientTime;
	messageListInfo.strBuddyName = groupInfo.groupName;
	messageListInfo.strBuddyHeaderImage = groupInfo.groupLoacalHeadImage;
	messageListInfo.messageType = messageinfo.MessageChildType;
	messageListInfo.nUnReadNum = 0;
	messageListInfo.isGroup = 1;

	//首先判断列表中是否存在
	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		CFrientItemMessage *buddy = (CFrientItemMessage*)this->itemWidget(item);
		if (buddy != NULL)
		{
			if (buddy->mNickName->objectName() == groupInfo.groupId)
			{
				item->setSelected(true);
				buddy->OnSetMessageNum("");
				return messageListInfo;
			}	
		}
	}

	if (this->count() >= 30)
	{
		QListWidgetItem *item = this->item(0);
		CFrientItemMessage *widget = (CFrientItemMessage *)this->itemWidget(item);
		for (int j = 1; j < this->count(); j++)
		{
			QListWidgetItem *currentItem = this->item(j);
			CFrientItemMessage *currentWidget = (CFrientItemMessage *)this->itemWidget(currentItem);
			if (widget->getLastTime() > currentWidget->getLastTime())
			{
				item = currentItem;
				widget = currentWidget;
			}
		}

		QString deleteID = widget->mNickName->objectName();
		this->takeItem(this->row(item));
	}

	this->OnInsertMessage(groupInfo.groupId,
		groupInfo.groupLoacalHeadImage,
		groupInfo.groupName,
		messageinfo.strMsg, strTime, "", 1);

	return messageListInfo;
}

void MessageList::OnInsertMessage(QString strUserID,
	QString strPicPath,
	QString strNickName,
	QString strAutoGrapthText,
	QString strMessageTime,
	QString strMessageNum,
	int nType,
	int nHeight)
{
	CFrientItemMessage *buddy = new CFrientItemMessage(this);
	buddy->resize(this->width(), nHeight);
	buddy->OnInitMessage(strUserID);
	buddy->OnSetPicPath(strPicPath, nType);
	buddy->OnSetNickNameText(strNickName);
	buddy->OnSetAutoGrapthText(strAutoGrapthText);
	buddy->OnSetMessageTime(strMessageTime);
	buddy->OnSetMessageNum(strMessageNum);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	//newItem->setSizeHint(QSize(this->width(),nHeight));
	newItem->setSizeHint(QSize(this->width(), 58));
	this->insertItem(0, newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
	if (strAutoGrapthText.isEmpty())
	    this->setCurrentRow(0);
	
	connect(buddy, SIGNAL(sigCurrentChatClose(QString)), this, SIGNAL(sigCloseChat(QString)));
	connect(buddy, SIGNAL(sigChangeMessageNum()), this, SLOT(slotCountMessageNum()));
	connect(buddy, SIGNAL(sigCurrentChatClose(QString)), this, SLOT(slotCountMessageNum()));

	slotCountMessageNum();
}

void MessageList::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Up)
	{
		if (this->count() > 0)
		{
			if (this->currentRow() < 0)
			{
				QListWidgetItem *item = this->item(0);
				item->setSelected(true);
				this->setCurrentItem(item);
				this->doDoubleClickedItem(item);
			}
			else
			{
				if (this->currentRow() != 0)
				{
					QListWidgetItem *item = this->item(this->currentRow() - 1);
					item->setSelected(true);
					this->setCurrentItem(item);
					this->doDoubleClickedItem(item);
				}
			}
		}
	}
	if (event->key() == Qt::Key_Down)
	{
		if (this->count() > 0)
		{
			if (this->currentRow() < 0)
			{
				QListWidgetItem *item = this->item(0);
				item->setSelected(true);
				this->setCurrentItem(item);
				this->doDoubleClickedItem(item);
			}
			else
			{
				if (this->currentRow() != this->count() - 1)
				{
					QListWidgetItem *item = this->item(this->currentRow() + 1);
					item->setSelected(true);
					this->setCurrentItem(item);
					this->doDoubleClickedItem(item);
				}
			}
		}
	}

	if (event->key() == Qt::Key_Return)
	{
		QListWidgetItem *item = this->currentItem();
		if (item)
			this->doDoubleClickedItem(item);
	}

	return QWidget::keyPressEvent(event);
}

void MessageList::enterEvent(QEvent * event)
{
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void MessageList::leaveEvent(QEvent * event)
{
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MessageList::doDoubleClickedItem(QListWidgetItem *item)
{
	int nCurrentItem = this->currentRow();
	MessageInfo info;
	CFrientItemMessage *buddy = (CFrientItemMessage*)this->itemWidget(item);
	if (buddy == NULL)
	{
		return;
	}
	QString strUserID = buddy->mNickName->objectName();
	buddy->OnSetMessageNum("");
	QString strNikeName = buddy->GetNikeName();

	emit sigDoubleClickItem(strUserID);
	emit sigDealTrayIocnFlash(strUserID);
}

void MessageList::OnUpdateMessage(bool isGroup, QVariant var)
{
	if (isGroup)
	{
		GroupInfo groupInfo = var.value<GroupInfo>();
		for (int i = 0; i < this->count(); i++)
		{
			CFrientItemMessage *message = (CFrientItemMessage *)this->itemWidget(this->item(i));
			if (message->mNickName->objectName() == groupInfo.groupId)
			{
				message->OnSetPicPath(groupInfo.groupLoacalHeadImage, isGroup);
				message->OnSetNickNameText(groupInfo.groupName);
			}
		}
	}
	else
	{
		BuddyInfo buddyInfo = var.value<BuddyInfo>();
		for (int i = 0; i < this->count(); i++)
		{
			CFrientItemMessage *message = (CFrientItemMessage *)this->itemWidget(this->item(i));
			if (message->mNickName->objectName() == QString::number(buddyInfo.nUserId))
			{
				message->OnSetPicPath(buddyInfo.strLocalAvatar, isGroup);
				if (buddyInfo.strNote.isEmpty())
					message->OnSetNickNameText(buddyInfo.strNickName);
				else
					message->OnSetNickNameText(buddyInfo.strNote);
			}
		}
	}
}

void MessageList::slotCountMessageNum()
{
	getMessageUnreadNum();
}

int MessageList::getMessageUnreadNum()
{
	int count = 0;

	for (int i = 0; i < this->count(); i++)
	{
		CFrientItemMessage *message = (CFrientItemMessage *)this->itemWidget(this->item(i));
		if (message)
			count += message->getMessageNum();
	}

	emit sigMessageNum(count);

	return count;
}

void MessageList::slotKeyUpDown(QKeyEvent *event)
{
	this->keyPressEvent(event);
}

