#include "contactslist.h"

ContactsList::ContactsList(QWidget *parent)
: QListWidget(parent)
{
	connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(doDoubleClickedItem(QListWidgetItem *)));
	connect(this, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(doClickedItem(QListWidgetItem *)));
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(doListContextMenu(const QPoint&)));

	listMenu = new QMenu(this);					//�Ҽ���ʾ�Ĳ˵�
	ActiondeleteBuddy = listMenu->addAction(QStringLiteral("ɾ������"));

	//connect(ActiondeleteBuddy, SIGNAL(triggered(bool)), this, SLOT(doDeleteBuddy()));
	QFile scroolbar_style_qss(":/ScrollBar/Resources/QSS/scrollbarStyle.qss");
	scroolbar_style_qss.open(QFile::ReadOnly);
	this->verticalScrollBar()->setStyleSheet(scroolbar_style_qss.readAll());
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setMouseTracking(true);

	//������ʽ
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
	bool has = false;  //�ж���ϵ���б��Ƿ���������ϵ����ĸ�ı�־������
	int letter = (int)buddyInfo.strPingYin.at(0).toLatin1();  //����ϵ�˵�ascii��ֵ�����ڱȽ���ĸ˳��
	int place = -1;    //�����ǰ�б�û������ϵ�˵���ĸ��ʹ�øñ�����������ϵ����ĸҪ�����λ�á�

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

	if (has == false)   //��������ĸ������ϵ�ˡ�
	{
		//�Ȳ�����ĸ��
		QListWidgetItem *newItem = new QListWidgetItem(buddyInfo.strPingYin);    //����һ��Item
		newItem->setSizeHint(QSize(this->width(), 25));//���ÿ�ȡ��߶�
		newItem->setFlags(Qt::NoItemFlags);
		newItem->setData(Qt::UserRole, buddyInfo.strPingYin);
		this->insertItem(place+1, newItem);         //�ӵ�QListWidget��
		//�ٲ�����ϵ�ˡ�
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
	QListWidgetItem *newItem = new QListWidgetItem(); //����һ��newItem
	//newItem->setSizeHint(QSize(this->width(),nHeight));
	newItem->setSizeHint(QSize(this->width(), 58));

	QString strTemp = info.strPingYin + QString::number(info.nUserId);
	newItem->setData(Qt::UserRole, strTemp);

	this->insertItem(nIndex, newItem); //����newItem���뵽����
	this->setItemWidget(newItem, buddy); //��buddy������newItem
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
			qDebug() << "ContactsList::OnUpdateBuddyInfo��ָ��";
			return;
		}
		if (widget->mNickName->objectName().toInt() == buddyInfo.nUserId)
		{
			//��ɾ������ӡ�
			this->takeItem(i);
			QListWidgetItem *lastItem = this->item(i - 1);
			//����Ǹ�ƴ�������һ�����ѣ���ɾ��ƴ�����������ж��߼���
			if (i == this->count())  //����Ǻ����б����һ��λ�ã���ɾ��һ���ԭ��index����count()����
			{
				//�ж�ǰһ���ǲ���ƴ��������ǣ�ɾ��ǰ���ƴ���
				if (lastItem->flags() == Qt::NoItemFlags)
					this->takeItem(i - 1);
			}
			else                              //����ں����б��м�λ�á�
			{
				//�ж�ǰһ�����һ���ǲ���ƴ��������ǣ�ɾ��ǰ���ƴ���
				QListWidgetItem *nextItem = this->item(i);
				if (lastItem->flags() == Qt::NoItemFlags && nextItem->flags() == Qt::NoItemFlags)
					this->takeItem(i - 1);
			}

			widget->OnSetPicPath(buddyInfo.strLocalAvatar);
			//���
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
			qDebug() << "ContactsList::OnUpdateBuddyInfo��ָ��";
			return;
		}
		if (widget->mNickName->objectName() == userID)
		{
			//ɾ����
			this->takeItem(i);
			QListWidgetItem *lastItem = this->item(i - 1);
			//����Ǹ�ƴ�������һ�����ѣ���ɾ��ƴ�����������ж��߼���
			if (i == this->count())  //����Ǻ����б����һ��λ�ã���ɾ��һ���ԭ��index����count()����
			{
				//�ж�ǰһ���ǲ���ƴ��������ǣ�ɾ��ǰ���ƴ���
				if (lastItem->flags() == Qt::NoItemFlags)
					this->takeItem(i - 1);
			}
			else                              //����ں����б��м�λ�á�
			{
				//�ж�ǰһ�����һ���ǲ���ƴ��������ǣ�ɾ��ǰ���ƴ���
				QListWidgetItem *nextItem = this->item(i);
				if (lastItem->flags() == Qt::NoItemFlags && nextItem->flags() == Qt::NoItemFlags)
					this->takeItem(i - 1);
			}

			break;
		}
	}
}
