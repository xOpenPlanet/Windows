#include "cfriendlistwidgetbase.h"
#include <QDebug>

CFriendListWidgetBase::CFriendListWidgetBase(QWidget *parent) : QListWidget(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条关闭
}

void CFriendListWidgetBase::OnInsertMessage(QString strUserID,
                                            QString strPicPath,
                                            QString strNickName,
                                            QString strAutoGrapthText,
                                            QString strMessageTime,
                                            QString strMessageNum,
											int nType,
                                            int nHeight)
{
    CFrientStyleWidget *buddy = new CFrientStyleWidget();
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
    this->insertItem(0,newItem); //将该newItem插入到后面
    this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
	this->setCurrentRow(0);
	connect(buddy, SIGNAL(sigCurrentChatClose(QString)), this, SLOT(slotClickCloseBtn(QString)));
	connect(buddy, SIGNAL(sigNumChanged()), this, SLOT(slotCountMessageNum()));
	slotCountMessageNum();
}

void CFriendListWidgetBase::OnInsertContacts(QString strData,QString strUserID,QString strPicPath,QString strNickName, QString strSign, int nType ,int nHeight)
{
   CFrientStyleWidget *buddy = new CFrientStyleWidget();
   buddy->resize(this->width(), nHeight); 
   buddy->OnInitContacts(strUserID);
   buddy->OnSetPicPath(strPicPath, nType);
   buddy->OnSetNickNameText(strNickName);
   buddy->OnSetAutoGrapthText(strSign);
   QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
   //newItem->setSizeHint(QSize(this->width(),nHeight));
   newItem->setSizeHint(QSize(this->width(), 58));

   QString strTemp = strData + strUserID;
   newItem->setData(Qt::UserRole, strTemp);

   this->insertItem(this->count(),newItem); //将该newItem插入到后面
   this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void CFriendListWidgetBase::OnInsertGroup(QString strData, QString strUserID, QString strPicPath, QString strNickName, int nType, int nHeight)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->resize(this->width(), nHeight);
	buddy->OnInitGroup(strUserID);
	buddy->OnSetPicPath(strPicPath, nType);
	buddy->OnSetNickNameText(strNickName);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	//newItem->setSizeHint(QSize(this->width(),nHeight));
	newItem->setSizeHint(QSize(this->width(), 58));

	QString strTemp = strData + strUserID;
	newItem->setData(Qt::UserRole, strTemp);

	this->insertItem(this->count(), newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void CFriendListWidgetBase::OnInsertContactsofIndex(QString strData, QString strUserID, QString strPicPath, QString strNickName, QString strSign, int nIndex, int nHeight)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->resize(this->width(), nHeight);
	buddy->OnInitContacts(strUserID);
	buddy->OnSetPicPath(strPicPath);
	buddy->OnSetNickNameText(strNickName);
	buddy->OnSetAutoGrapthText(strSign);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	//newItem->setSizeHint(QSize(this->width(),nHeight));
	newItem->setSizeHint(QSize(this->width(), 58));

	QString strTemp = strData + strUserID;
	newItem->setData(Qt::UserRole, strTemp);

	this->insertItem(nIndex, newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void CFriendListWidgetBase::OnInsertGroupUserList(QString strUserID,QString strPicPath,QString strNickName, int mana, int nHeight)
{
    CFrientStyleWidget *buddy = new CFrientStyleWidget();
    buddy->OnInitGroupUserList(strUserID);
    buddy->OnSetPicPath(strPicPath);
    buddy->OnSetNickNameText(strNickName);
	buddy->onSetIdentity(mana);
    QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
    newItem->setSizeHint(QSize(this->width(),nHeight));
    this->insertItem(this->count(),newItem); //将该newItem插入到后面
    this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void CFriendListWidgetBase::OnInsertLogUserList(QString strUserID, QString strPicPath, QString strNickName, int ntype,int nHeight)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->OnInitLogUserList(strUserID);
	buddy->OnSetPicPath(strPicPath,ntype);
	buddy->OnSetNickNameText(strNickName);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	newItem->setSizeHint(QSize(this->width(), nHeight));
	this->insertItem(this->count(), newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void CFriendListWidgetBase::OnInsertManagerUserList(QString strUserID, QString strPicPath, QString strNickName, int nHeight, bool hasRead)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->onInitManagerUserList(strUserID, hasRead);
	buddy->OnSetPicPath(strPicPath);
	buddy->OnSetNickNameText(strNickName);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	newItem->setSizeHint(QSize(this->width(), nHeight));
	this->insertItem(0, newItem); //将该newItem插入到首项
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem

	connect(buddy, SIGNAL(sigClickAcceptBtn()), this, SLOT(slotClickAcceptBtn()));
}

void CFriendListWidgetBase::OnInsertManagerApplyGroup(QString groupID, QString strUserID, QString strPicPath, QString text, int nHeight, bool hasRead)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->onInitManagerApplyGroup(strUserID, groupID, hasRead);
	buddy->OnSetPicPath(strPicPath);
	buddy->OnSetNickNameText(text);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	newItem->setSizeHint(QSize(this->width(), nHeight));
	this->insertItem(0, newItem); //将该newItem插入到首项
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
	connect(buddy, SIGNAL(sigClickAcceptBtn()), this, SLOT(slotClickAcceptBtn()));
}

void CFriendListWidgetBase::OnInsertMessageBoxList(QString strTime,QString strMsg, QString strUserID, QString strPicPath, QString strNickName, int nHeight)
{
	int flag = 0;
	for (int i = 0; i < this->count();i++)
	{
		QListWidgetItem *buddy = this->item(i);
		CFrientStyleWidget *iterm = (CFrientStyleWidget*)this->itemWidget(buddy);
		if (iterm == NULL)
		{
			qDebug() << "CFriendListWidgetBase::OnInsertMessageBoxList空指针";
			return;
		}
		if (((iterm->mNickName->objectName()) == strUserID) && (strTime != iterm->GetStrTime()))//存在并且消息内容不一样
		{
			iterm->OnSetAutoGrapthText(strMsg);
			iterm->OnSetMessageTime(strTime);
			int num = iterm->OnGetMessageNum().toInt() + 1;
			QString uNreadNum = QString::number(num);
			iterm->OnSetMessageNum(uNreadNum);
			flag = 1;
			break;
		}
		if (strUserID == iterm->mNickName->objectName())//存在且消息内容相同则不做处理
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		CFrientStyleWidget *buddy = new CFrientStyleWidget();
		buddy->OnInitMessageBoxList(strUserID);
		buddy->OnSetMessageNum("1");//初始为1
		buddy->OnSetPicPath(strPicPath);
		buddy->OnSetNickNameText(strNickName);
		buddy->OnSetAutoGrapthText(strMsg);
		buddy->OnSetMessageTime(strTime);
		QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
		newItem->setSizeHint(QSize(this->width(), nHeight));
		this->insertItem(this->count(), newItem); //将该newItem插入到后面
		this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
		connect(buddy, SIGNAL(sigNumChanged()), this, SLOT(slotCountMessageNum()));
		slotCountMessageNum();
	}
	
}

void CFriendListWidgetBase::OnInsertAddCreateWidgetList(QString strAddID, QString strPicPath, QString strAddName, QString strNote, int nHeight)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->OnInitAddCreateList(strAddID);
	buddy->OnSetPicPath(strPicPath);
	buddy->OnSetNickNameText(strAddName);
	buddy->OnSetAutoGrapthText(strNote);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	newItem->setSizeHint(QSize(this->width(), nHeight));
	this->insertItem(this->count(), newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void CFriendListWidgetBase::OnInsertSearchBuddyList(QString strAddID, QString strPicPath, QString strAddName, int nHeight)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->OnInitSearchBuddyList(strAddID);
	buddy->OnSetPicPathByHttp(strPicPath);
	buddy->OnSetNickNameText(strAddName);
	buddy->OnSetAddPersonButtonText("加为好友");
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	newItem->setSizeHint(QSize(this->width(), nHeight));
	this->insertItem(this->count(), newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
	connect(buddy, SIGNAL(sigAddPerson(QString)), this, SLOT(doAddPerson(QString)));
}

void CFriendListWidgetBase::doAddPerson(QString strBuddyID)
{
	emit sigAddPerson(strBuddyID);
}

void CFriendListWidgetBase::slotOnMouseEnteredListWidgetItem(QListWidgetItem* item)
{
	CFrientStyleWidget* chat_item_widget = (CFrientStyleWidget*)this->itemWidget(item); 
	chat_item_widget->closeButton()->show(); 
}

void CFriendListWidgetBase::slotOnMouseLeavedListWidgetItem(QListWidgetItem* item)
{
	CFrientStyleWidget* chat_item_widget = (CFrientStyleWidget*)this->itemWidget(item);
	chat_item_widget->closeButton()->hide();
}

void CFriendListWidgetBase::slotClickAcceptBtn()
{
	CFrientStyleWidget *senderWidget = qobject_cast<CFrientStyleWidget*>(sender());
	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		QWidget *widget = this->itemWidget(item);
		CFrientStyleWidget *currentWidget = (CFrientStyleWidget *)widget;

		if (senderWidget == currentWidget)
		{
			this->setCurrentRow(i);
			emit sigClickAcceptBtn();
			break;
		}
	}
}

void CFriendListWidgetBase::slotClickCloseBtn(QString id)
{
	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		CFrientStyleWidget *widget = (CFrientStyleWidget *)this->itemWidget(item);

		if (widget == NULL)
		{
			qDebug() << "CFriendListWidgetBase::slotCountMessageNum空指针";
			return;
		}

		if (widget->closeButton())
		{
			if (widget->closeButton()->objectName() == id)
				this->takeItem(i);
			if (this->count() > 0 && !this->currentRow())
				this->setCurrentRow(0);
		}
	}

	emit sigChatClose(id);
}

void CFriendListWidgetBase::slotCountMessageNum()
{
	int num = 0;

	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		CFrientStyleWidget *widget = (CFrientStyleWidget *)this->itemWidget(item);

		if (widget == NULL)
		{
			qDebug() << "CFriendListWidgetBase::slotCountMessageNum空指针";
			return;
		}

		if (!widget->OnGetMessageNum().isEmpty())
			num += widget->OnGetMessageNum().toInt();
	}

	emit sigMessageNum(num);
}

void CFriendListWidgetBase::OnInsertSearchGroupList(QString strAddID, QString strPicPath, QString strAddName, int nHeight)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget();
	buddy->OnInitSearchBuddyList(strAddID);
	buddy->OnSetPicPathByHttp(strPicPath, ":/GroupChat/Resources/groupchat/group.png");
	buddy->OnSetNickNameText(strAddName);
	buddy->OnSetAddPersonButtonText("加入群组");
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	newItem->setSizeHint(QSize(this->width(), nHeight));
	this->insertItem(this->count(), newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
	connect(buddy, SIGNAL(sigAddPerson(QString)), this, SLOT(doAddPerson(QString)));
}
