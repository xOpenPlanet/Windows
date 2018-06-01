#include "contactslist.h"

ContactsList::ContactsList(QWidget *parent)
: QListWidget(parent)
{
	connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(doDoubleClickedItem(QListWidgetItem *)));
	connect(this, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(doClickedItem(QListWidgetItem *)));
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(doListContextMenu(const QPoint&)));

	listMenu = new QMenu(this);					//右键显示的菜单
	ActiondeleteBuddy = listMenu->addAction(QStringLiteral("删除好友"));

	//connect(ActiondeleteBuddy, SIGNAL(triggered(bool)), this, SLOT(doDeleteBuddy()));
	QFile scroolbar_style_qss(":/ScrollBar/Resources/QSS/scrollbarStyle.qss");
	scroolbar_style_qss.open(QFile::ReadOnly);
	this->verticalScrollBar()->setStyleSheet(scroolbar_style_qss.readAll());
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setMouseTracking(true);

	//加载样式
	QFile file(":/Contacts/Resources/QSS/listWidgetStyle.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

ContactsList::~ContactsList()
{
	if (listMenu)
		delete listMenu;
}
void ContactsList::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Up)
	{
		if (this->count() > 0)
		{
			QListWidgetItem *item = NULL;
			for (int i = this->count() - 1; i >= 0; i--)
			{
				if (this->currentRow() < 0 && this->item(i)->flags() != Qt::NoItemFlags)
				{
					item = this->item(i);
					break;
				}
				
				if (this->currentRow() > i && this->item(i)->flags() != Qt::NoItemFlags)
				{
					item = this->item(i);
					break;
				}
			}
			if (item)
			{
				item->setSelected(true);
				this->setCurrentItem(item);
				this->doClickedItem(item);
			}
		}
	}
	if (event->key() == Qt::Key_Down)
	{
		if (this->count() > 0)
		{
			QListWidgetItem *item = NULL;
			for (int i = 0; i < this->count(); i++)
			{
				if (this->currentRow() < 0 && this->item(i)->flags() != Qt::NoItemFlags)
				{
					item = this->item(i);
					break;
				}

				if (this->currentRow() < i && this->item(i)->flags() != Qt::NoItemFlags)
				{
					item = this->item(i);
					break;
				}
			}
			if (item)
			{
				item->setSelected(true);
				this->setCurrentItem(item);
				this->doClickedItem(item);
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

void ContactsList::enterEvent(QEvent * event)
{
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void ContactsList::leaveEvent(QEvent * event)
{
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void ContactsList::doDoubleClickedItem(QListWidgetItem *item)
{
	CFrientItemBuddy *buddy = (CFrientItemBuddy*)this->itemWidget(item);
	if (buddy != NULL)
	{
		QString strUserID = buddy->mNickName->objectName();
		emit sigPerChat(OpenPer, QVariant(strUserID));
	}
}

void ContactsList::doClickedItem(QListWidgetItem *item)
{
	CFrientItemBuddy *buddy = (CFrientItemBuddy*)this->itemWidget(item);
	if (buddy != NULL)
	{
		QString strUserID = buddy->mNickName->objectName();
		emit sigProfile(strUserID);
	}
}

void ContactsList::doListContextMenu(const QPoint& point)
{
	if (listMenu)
	{
		int nIndex = this->currentRow();
		if (nIndex >= 0)
		{
			QListWidgetItem *item = this->item(nIndex);
			if (!OnJudgeIsListTitle(item->data(Qt::UserRole).toString()))
			{
				listMenu->exec(QCursor::pos());
			}
		}
	}
}

bool ContactsList::OnJudgeIsListTitle(QString strTitle)
{
	if (strTitle == "A" || strTitle == "B" || strTitle == "C" || strTitle == "D" ||
		strTitle == "E" || strTitle == "F" || strTitle == "G" || strTitle == "H" ||
		strTitle == "I" || strTitle == "J" || strTitle == "K" || strTitle == "L" ||
		strTitle == "M" || strTitle == "N" || strTitle == "O" || strTitle == "P" ||
		strTitle == "Q" || strTitle == "R" || strTitle == "S" || strTitle == "T" ||
		strTitle == "U" || strTitle == "V" || strTitle == "W" || strTitle == "X" ||
		strTitle == "Y " || strTitle == "Z")
	{
		return true;
	}
	return false;
}

void ContactsList::OnInsertContactsInfo(BuddyInfo buddyInfo)
{
	bool has = false;  //判断联系人列表是否已有新联系人字母的标志变量。
	int letter = (int)buddyInfo.strPingYin.at(0).toLatin1();  //新联系人的ascii码值，用于比较字母顺序。
	int place = -1;    //如果当前列表没有新联系人的字母，使用该变量保存新联系人字母要插入的位置。

	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		if (item->data(Qt::UserRole).toString() == buddyInfo.strPingYin)
		{
			QString strBuddyID = QString("%1").arg(buddyInfo.nUserId);
			QString strName;
			if (!buddyInfo.strNote.isEmpty())
			{
				strName = buddyInfo.strNote;
			}
			else
				strName = buddyInfo.strNickName;
			this->OnInsertContactsofIndex(buddyInfo, (i + 1));
			has = true;
			break;
		}
		else
		{
			QListWidgetItem *curitem = this->item(i);
			int curLetter = curitem->data(Qt::UserRole).toString().at(0).toLatin1();
			if (letter > curLetter)
				place = i;
		}
	}

	if (has == false)   //插入新字母，新联系人。
	{
		//先插入字母。
		QListWidgetItem *newItem = new QListWidgetItem(buddyInfo.strPingYin);    //创建一个Item
		newItem->setSizeHint(QSize(this->width(), 25));//设置宽度、高度
		newItem->setFlags(Qt::NoItemFlags);
		newItem->setData(Qt::UserRole, buddyInfo.strPingYin);
		this->insertItem(place+1, newItem);         //加到QListWidget中
		//再插入联系人。
		QString strBuddyID = QString("%1").arg(buddyInfo.nUserId);
		QString strName;
		if (!buddyInfo.strNote.isEmpty())
		{
			strName = buddyInfo.strNote;
		}
		else
			strName = buddyInfo.strNickName;
		this->OnInsertContactsofIndex(buddyInfo, (place + 2));
	}
}

void ContactsList::OnInsertContactsofIndex(BuddyInfo info, int nIndex, int nHeight /*= 62*/)
{
	CFrientItemBuddy *buddy = new CFrientItemBuddy(this);
	buddy->resize(this->width(), nHeight);
	buddy->OnInitContacts(QString::number(info.nUserId));
	buddy->OnSetPicPath(info.strLocalAvatar);
	buddy->OnSetNickNameText(info.strNickName);
	buddy->OnSetAutoGrapthText(info.strSign);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	//newItem->setSizeHint(QSize(this->width(),nHeight));
	newItem->setSizeHint(QSize(this->width(), 58));

	QString strTemp = info.strPingYin + QString::number(info.nUserId);
	newItem->setData(Qt::UserRole, strTemp);

	this->insertItem(nIndex, newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void ContactsList::UpdateBuddyImage(QString userID, QPixmap pix)
{
	for (int i = 0; i < this->count(); i++)
	{
		CFrientItemBuddy *buddy = (CFrientItemBuddy*)this->itemWidget(this->item(i));
		if (buddy != NULL)
		{
			if (buddy->mNickName->objectName() == userID)
			{
				buddy->UpdateHeaderImage(pix);
				return;
			}
		}
	}
}

void ContactsList::OnUpdateBuddyInfo(BuddyInfo buddyInfo)
{
	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		if (item->flags() == Qt::NoItemFlags)
			continue;

		CFrientItemBuddy *widget = (CFrientItemBuddy *)this->itemWidget(item);
		if (widget == NULL)
		{
			qDebug() << "ContactsList::OnUpdateBuddyInfo空指针";
			return;
		}
		if (widget->mNickName->objectName().toInt() == buddyInfo.nUserId)
		{
			//先删除后添加。
			this->takeItem(i);
			QListWidgetItem *lastItem = this->item(i - 1);
			//如果是该拼音下最后一个好友，就删除拼音，以下是判断逻辑。
			if (i == this->count())  //如果是好友列表最后一个位置（已删除一项的原因，index等于count()）。
			{
				//判断前一项是不是拼音，如果是，删除前面的拼音项。
				if (lastItem->flags() == Qt::NoItemFlags)
					this->takeItem(i - 1);
			}
			else                              //如果在好友列表中间位置。
			{
				//判断前一项跟后一项是不是拼音，如果是，删除前面的拼音项。
				QListWidgetItem *nextItem = this->item(i);
				if (lastItem->flags() == Qt::NoItemFlags && nextItem->flags() == Qt::NoItemFlags)
					this->takeItem(i - 1);
			}

			widget->OnSetPicPath(buddyInfo.strLocalAvatar);
			//添加
			OnInsertContactsInfo(buddyInfo);

			break;
		}
	}
}

void ContactsList::deleteFriend(QString userID)
{
	for (int i = 0; i < this->count(); i++)
	{
		QListWidgetItem *item = this->item(i);
		if (item->flags() == Qt::NoItemFlags)
			continue;

		CFrientItemBuddy *widget = (CFrientItemBuddy *)this->itemWidget(item);
		if (widget == NULL)
		{
			qDebug() << "ContactsList::OnUpdateBuddyInfo空指针";
			return;
		}
		if (widget->mNickName->objectName() == userID)
		{
			//删除。
			this->takeItem(i);
			QListWidgetItem *lastItem = this->item(i - 1);
			//如果是该拼音下最后一个好友，就删除拼音，以下是判断逻辑。
			if (i == this->count())  //如果是好友列表最后一个位置（已删除一项的原因，index等于count()）。
			{
				//判断前一项是不是拼音，如果是，删除前面的拼音项。
				if (lastItem->flags() == Qt::NoItemFlags)
					this->takeItem(i - 1);
			}
			else                              //如果在好友列表中间位置。
			{
				//判断前一项跟后一项是不是拼音，如果是，删除前面的拼音项。
				QListWidgetItem *nextItem = this->item(i);
				if (lastItem->flags() == Qt::NoItemFlags && nextItem->flags() == Qt::NoItemFlags)
					this->takeItem(i - 1);
			}

			break;
		}
	}
}
