#include "contactsdatamanager.h"

extern OPDatebaseShareLib *gOPDataBaseOpera;
extern OPDataManager  *gOPDataManager;

ContactsDataManager::ContactsDataManager(QObject *parent)
	: QObject(parent)
{
	widget = new ContactsWidget();
	contactsList = new ContactsList();
	groupList = new GroupList();
	perWidget = widget->getPerProfile();
	groupWidget = widget->getGroupProfile();

	widget->addWidget(contactsList);
	widget->addWidget(groupList);

	connect(widget, SIGNAL(sigAddCreateGroup()), this, SIGNAL(sigAddCreateGroup()));
	connect(widget, SIGNAL(sigAddPerson()), this, SIGNAL(sigAddPerson()));

	connect(perWidget, SIGNAL(sigPerChat(int, QVariant)), this, SIGNAL(sigOpenChat(int, QVariant)));
	connect(contactsList, SIGNAL(sigPerChat(int, QVariant)), this, SIGNAL(sigOpenChat(int, QVariant)));
	connect(contactsList, SIGNAL(sigProfile(QString)), this, SLOT(slotPerProfile(QString)));

	connect(groupWidget, SIGNAL(sigGroupChat(int, QVariant)), this, SIGNAL(sigOpenChat(int, QVariant)));
	connect(groupList, SIGNAL(sigGroupChat(int, QVariant)), this, SIGNAL(sigOpenChat(int, QVariant)));
	connect(groupList, SIGNAL(sigProfile(QString)), this, SLOT(slotGroupProfile(QString)));
	
	OPRequestShareLib *request = new OPRequestShareLib;
	connect(request, SIGNAL(sigBaseBuddyInfo(QString)), this, SLOT(slotAddressInfo(QString)));
	request->getBaseBuddyInfo(gOPDataManager->getAccessToken());
}

ContactsDataManager::~ContactsDataManager()
{

}

ContactsWidget * ContactsDataManager::getContactsWidget()
{
	return this->widget;
}

void ContactsDataManager::recvBuddyData(int type, QVariant data)
{
	switch (type)
	{
	case BuddyInsert:
	{
		BuddyInfo buddy = data.value<BuddyInfo>();
		contactsList->OnInsertContactsInfo(buddy);
		break;
	}
	case BuddyUpdate:
	{
		BuddyInfo buddy = data.value<BuddyInfo>();
		contactsList->OnUpdateBuddyInfo(buddy);
	}
	case BuddyDelete:
	{
		QString userID = data.toString();
		contactsList->deleteFriend(userID);
	}
	default:
		break;
	}
}

void ContactsDataManager::recvGroupData(int type, QVariant data)
{
	switch (type)
	{
	case GroupInsert:
	{
		GroupInfo group = data.value<GroupInfo>();
		groupList->OnInsertGroupInfo(group);
		break;
	}
	case GroupUpdate:
	{
						GroupInfo group = data.value<GroupInfo>();
						groupList->OnUpdateGroupInfo(group);
						break;
	}
	case GroupDelete:
	{
		QString groupID = data.value<QString>();
		groupList->OnDeleteGroupInfo(groupID);
		break;
	}
	default:
		break;
	}
}

void ContactsDataManager::updateImage(int type,int nIMuserID, QPixmap pix)
{
	switch (type)
	{
		case BuddyUpdate:
		{
			if (contactsList)
			{
				contactsList->UpdateBuddyImage(QString::number(nIMuserID),pix);
			}
		}
		break;
		case GroupUpdate:
		{
			if (groupList)
			{
				groupList->UpdateHeaderImage(QString::number(nIMuserID), pix);
			}
		}
		break;
	default:
		break;
	}
}

void ContactsDataManager::slotPerProfile(QString userID)
{
	groupWidget->hide();
	perWidget->show();
	BuddyInfo buddy = gDataBaseOpera->DBGetBuddyInfoByID(userID);
	AddressInfo wallet = gOPDataBaseOpera->DBGetAddressInfo(userID);
	perWidget->setBuddy(buddy, wallet);
}

void ContactsDataManager::slotGroupProfile(QString groupID)
{
	perWidget->hide();
	groupWidget->show();

	groupWidget->setGroup(groupID);
}

void ContactsDataManager::slotAddressInfo(QString result)
{
	QJsonDocument json = QJsonDocument::fromJson(result.toUtf8());
	QVariantMap map = json.toVariant().toMap();

	if (map.value("result").toString() == "success")
	{
		QList<QVariant> list = map.value("addressList").toList();
		for each (QVariant var in list)
		{
			QMap<QString, QVariant> buddy = var.toMap();
			AddressInfo info;
			info.userID = QString::number(buddy.value("imUserId").toInt());
			info.comPublicKey = buddy.value("comPublicKey").toString();
			info.ethAddress = buddy.value("ethAddress").toString();
			info.ethPublicKey = buddy.value("ethPublicKey").toString();

			gOPDataBaseOpera->DBInsertAddressInfo(info);
		}
	}
}


