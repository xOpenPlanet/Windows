#include "grouplist.h"

GroupList::GroupList(QWidget *parent)
	: QListWidget(parent)
{
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(slotDoubleClickedItem(QListWidgetItem *)));
	connect(this, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(doClickedItem(QListWidgetItem *)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(slotListContextMenu(const QPoint&)));

	listMenu = new QMenu(this);
	ActiondeleteGroup = listMenu->addAction(QStringLiteral("退出群组"));
	//connect(ActionShowGroupInfo, SIGNAL(triggered(bool)), this, SLOT(slotShowGroupInfo()));
	//connect(ActiondeleteGroup, SIGNAL(triggered(bool)), this, SLOT(slotExitGroup()));
	// 给滚动条改变样式
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

GroupList::~GroupList()
{
	if (listMenu)
		delete listMenu;
}

void GroupList::enterEvent(QEvent * event)
{
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void GroupList::leaveEvent(QEvent * event)
{
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void GroupList::keyPressEvent(QKeyEvent * event)
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
				this->doClickedItem(item);
			}
			else
			{
				if (this->currentRow() != 0)
				{
					QListWidgetItem *item = this->item(this->currentRow() - 1);
					item->setSelected(true);
					this->setCurrentItem(item);
					this->doClickedItem(item);
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
				this->doClickedItem(item);
			}
			else
			{
				if (this->currentRow() != this->count() - 1)
				{
					QListWidgetItem *item = this->item(this->currentRow() + 1);
					item->setSelected(true);
					this->setCurrentItem(item);
					this->doClickedItem(item);
				}
			}
		}
	}

	if (event->key() == Qt::Key_Return)
	{
		QListWidgetItem *item = this->currentItem();
		if (item)
			this->slotDoubleClickedItem(item);
	}

	return QWidget::keyPressEvent(event);
}

void GroupList::slotDoubleClickedItem(QListWidgetItem *item)
{
	CFrientItemGroup *group = (CFrientItemGroup*)this->itemWidget(item);
	if (group == NULL)
	{
		//qDebug() << QStringLiteral("GroupList::slotDoubleClickedItem空指针");
		return;
	}
	QString strUserID = group->mNickName->objectName(); 

	emit sigGroupChat(OpenGroup, QVariant(strUserID));
}

void GroupList::doClickedItem(QListWidgetItem *item)
{
	CFrientItemGroup *buddy = (CFrientItemGroup*)this->itemWidget(item);
	if (buddy != NULL)
	{
		QString strUserID = buddy->mNickName->objectName();
		emit sigProfile(strUserID);
	}
}

void GroupList::slotListContextMenu(const QPoint& point)
{
	if (listMenu && this->currentRow() >= 0)
	{
		listMenu->exec(QCursor::pos());
	}
}

void GroupList::OnInsertGroupInfo(GroupInfo groupInfo)
{
	this->OnInsertGroup(groupInfo);
}

void GroupList::OnDeleteGroupInfo(QString groupID)
{
	for (int i = 0; i < this->count(); i++)
	{
		CFrientItemGroup *buddy = (CFrientItemGroup*)this->itemWidget(this->item(i));
		if (buddy != NULL)
		{
			if (buddy->mNickName->objectName() == groupID)
			{
				this->takeItem(i);
				return;
			}
		}
	}
}

void GroupList::OnInsertGroup(GroupInfo groupInfo,int nHeight)
{
	CFrientItemGroup *buddy = new CFrientItemGroup(this);
	buddy->resize(this->width(), nHeight);
	buddy->OnInitGroup(groupInfo.groupId);
	buddy->OnSetPicPath(groupInfo.groupLoacalHeadImage);
	buddy->OnSetNickNameText(groupInfo.groupName);
	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	//newItem->setSizeHint(QSize(this->width(),nHeight));
	newItem->setSizeHint(QSize(this->width(), 58));

	QString strTemp = groupInfo.groupId;
	newItem->setData(Qt::UserRole, strTemp);

	this->insertItem(this->count(), newItem); //将该newItem插入到后面
	this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

void GroupList::UpdateHeaderImage(QString userID, QPixmap pix)
{
	for (int i = 0; i < this->count(); i++)
	{
		CFrientItemGroup *buddy = (CFrientItemGroup*)this->itemWidget(this->item(i));
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

void GroupList::OnUpdateGroupInfo(GroupInfo groupInfo)
{
	for (int i = 0; i < this->count(); i++)
	{
		CFrientItemGroup *buddy = (CFrientItemGroup*)this->itemWidget(this->item(i));
		if (buddy != NULL)
		{
			if (buddy->mNickName->objectName() == groupInfo.groupId)
			{
				buddy->OnSetPicPath(groupInfo.groupLoacalHeadImage);
				buddy->OnSetNickNameText(groupInfo.groupName);
				return;
			}
		}
	}
}
