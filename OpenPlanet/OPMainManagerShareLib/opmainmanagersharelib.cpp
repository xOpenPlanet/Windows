#include "opmainmanagersharelib.h"
#include "imdownloadheaderimg.h"

OPMainManagerShareLib::OPMainManagerShareLib(QObject *parent)
: QObject(parent)
{
	mainWidget = NULL;
	contactsManager = NULL;
	chatManager = NULL;
	userProfileManager = NULL;
	walletManager = NULL;
}

OPMainManagerShareLib::~OPMainManagerShareLib()
{
	if (mainWidget)
	{
		mainWidget->deleteLater();
		mainWidget = NULL;
	}
	if (contactsManager)
	{
		contactsManager->deleteLater();
		contactsManager = NULL;
	}
	if (chatManager)
	{
		chatManager->deleteLater();
		chatManager = NULL;
	}
	if (userProfileManager)
	{
		userProfileManager->deleteLater();
		userProfileManager = NULL;
	}
	if (walletManager)
	{
		walletManager->deleteLater();
		walletManager = NULL;
	}
}

void OPMainManagerShareLib::startMainWidget(UserInfo userInfo)
{
	mainWidget = new IMMainWidget();
	connect(this, SIGNAL(sigSetMainWidgetStatusLabel(QString)), mainWidget, SLOT(slotSetMainWidgetStatusLabel(QString)));     //������Ϣ״̬
	connect(mainWidget, SIGNAL(sigDormancyState(bool)), this, SLOT(slotDormancyState(bool)));                                //��������״̬

	connect(mainWidget, SIGNAL(sigExit()), this, SIGNAL(sigExit()));     //������Ϣ״̬
	userProfileManager = new UserProfileDataManager();
	connect(mainWidget, SIGNAL(sigUserProfile()), userProfileManager, SLOT(slotProfileWidget()));
	
	chatManager = new ChatDataManager();
	connect(chatManager, SIGNAL(sigWidgetMinSize()), this, SLOT(slotWidgetMinSize()));
	connect(chatManager, SIGNAL(sigShowNormalWindow()), this, SLOT(slotShowNormalWindow()));
	connect(chatManager, SIGNAL(sigDealTrayIocnFlash(QString)), mainWidget, SLOT(slotDealTrayIconFlash(QString)));
	connect(chatManager, SIGNAL(sigCountMessageNum(int)), mainWidget, SLOT(slotCountMessage(int)));
	connect(mainWidget, SIGNAL(sigTrayOpenChat(int, QVariant)), chatManager, SLOT(recvChat(int, QVariant)));
	mainWidget->addWidget(chatManager->getChatWidget());
	mainWidget->setCurrentWidget(OpenPer);

	contactsManager = new ContactsDataManager();
	mainWidget->addWidget(contactsManager->getContactsWidget());

	connect(contactsManager, SIGNAL(sigOpenChat(int, QVariant)), this, SLOT(slotOpenChat(int, QVariant)));
	connect(contactsManager, SIGNAL(sigAddCreateGroup()), this, SLOT(slotAddCreateGroup()));
	connect(contactsManager, SIGNAL(sigAddPerson()), this, SLOT(slotAddPerson()));
	connect(this, SIGNAL(sigUpdateMessageState(MessageInfo, int)), chatManager, SLOT(slotUpdateMessageState(MessageInfo, int)));
	connect(this, SIGNAL(sigRevOtherDeviceMsg(MessageInfo)), chatManager, SLOT(slotRevOtherDeviceMsg(MessageInfo)));

	slotInitMainWidget(userInfo);
	mainWidget->setAppVersion(gDataManager->getAppConfigInfo().appVersion.versionID);
	mainWidget->setAppName(gDataManager->getAppConfigInfo().appVersion.appString);
	mainWidget->show();

	walletManager = new EWalletManager(NULL);
	walletManager->setUserInfo(userInfo);
	mainWidget->addWidget(walletManager->getWalletWidget());
}

//��С��
void OPMainManagerShareLib::slotWidgetMinSize()
{
	if (mainWidget)
	{
		mainWidget->showMinimized();
	}
}

//��ԭ����
void OPMainManagerShareLib::slotShowNormalWindow()
{
	if (mainWidget)
	{
		mainWidget->showNormal();
	}
}


void OPMainManagerShareLib::slotInitMainWidget(UserInfo userInfo)
{
	mainWidget->setNikeName(userInfo.strUserName);
	IMDownLoadHeaderImg *headerImage = new IMDownLoadHeaderImg;
	if (headerImage->IsImageFile(userInfo.strUserAvatarLocal))
	{
		mainWidget->setHeaderImage(headerImage->GetImagePix(userInfo.strUserAvatarLocal));  //���ñ���ͼ��
	}
	else
	{
		mainWidget->setHeaderImage(headerImage->GetImagePix(userInfo.strUserDefaultAvatar));//����Ĭ��ͼ��
	}
	connect(headerImage, SIGNAL(sigUpdateBuddyHeaderImage(int, QPixmap)), this, SLOT(slotUpdateUserHeaderImg(int, QPixmap)));
	headerImage->StartDownLoadUserInfoHeaderImage(userInfo);

	if (gDataManager)
	{
		AppConfig conf = gDataManager->getAppConfigInfo();
		QString msg = QStringLiteral("��������  ") + conf.appVersion.versionID;
		mainWidget->slotSetMainWidgetStatusLabel(msg);
	}
}

//���º���ͷ��
void OPMainManagerShareLib::slotUpdateBuddyHeaderImg(int nUserID, QPixmap pix)
{
	IMDownLoadHeaderImg *headerImage = qobject_cast<IMDownLoadHeaderImg*>(sender());
	if (contactsManager)
	{
		contactsManager->updateImage(BuddyUpdate, nUserID, pix);
	}
	if (headerImage)
	{
		headerImage->deleteLater();
	}
}

//����Ⱥ��ͷ��
void OPMainManagerShareLib::slotUpdateGroupHeaderImg(int nUserID, QPixmap pix)
{
	IMDownLoadHeaderImg *headerImage = qobject_cast<IMDownLoadHeaderImg*>(sender());
	if (contactsManager)
	{
		contactsManager->updateImage(GroupUpdate, nUserID, pix);
	}
	if (headerImage)
	{
		headerImage->deleteLater();
		headerImage = NULL;
	}
}

//�����û�ͷ��
void OPMainManagerShareLib::slotUpdateUserHeaderImg(int nUserID, QPixmap pix)
{
	IMDownLoadHeaderImg *headerImage = qobject_cast<IMDownLoadHeaderImg*>(sender());
	if (mainWidget)
	{
		mainWidget->setHeaderImage(pix);
	}
	if (headerImage)
	{
		headerImage->deleteLater();
		headerImage = NULL;
	}
}

void OPMainManagerShareLib::slotBuddysManager(int type, QVariant data)
{
	if (contactsManager)
	{
		IMDownLoadHeaderImg *headerImage = new IMDownLoadHeaderImg;
		contactsManager->recvBuddyData(type, data);
		BuddyInfo buddy = data.value<BuddyInfo>();
		//�ж��Ƿ�����ͷ��
		if (headerImage->IsImageFile(buddy.strLocalAvatar))
		{
			contactsManager->updateImage(BuddyUpdate, buddy.nUserId, headerImage->GetImagePix(buddy.strLocalAvatar));
		}
		else
		{
			contactsManager->updateImage(BuddyUpdate, buddy.nUserId, headerImage->GetImagePix(buddy.strDefaultAvatar));
			connect(headerImage, SIGNAL(sigUpdateBuddyHeaderImage(int, QPixmap)), this, SLOT(slotUpdateBuddyHeaderImg(int, QPixmap)));
			headerImage->StartDownLoadBuddyeHeaderImage(buddy);
		}
	}
	if (walletManager)   //walletWidget��Ⱥ��������ʾ�Ĺ��ܡ�
	{
		if (type == BuddyInsert)
			walletManager->addBuddysNum(1);
	}
}

//���º��ѡ�Ⱥ����Ϣ
void OPMainManagerShareLib::slotUpdateInfo(int type, QVariant var)
{
	if (type == BuddyUpdate)
		contactsManager->recvBuddyData(type, var);
	if (type == GroupUpdate)
		contactsManager->recvGroupData(type, var);
	chatManager->recvChat(type, var);
}

//�û��˳�Ⱥ��
void OPMainManagerShareLib::slotUserQuitGroup(QString groupID, QString buddyID)
{
	chatManager->recvChat(QuitGroup, QVariant(groupID), QVariant(buddyID));
}

//��Ӻ��ѳɹ�
void OPMainManagerShareLib::slotAddFriendSuccess(BuddyInfo buddyInfo)
{
	QVariant var = QVariant::fromValue(buddyInfo);
	contactsManager->recvBuddyData(BuddyInsert, var);
}

//����Ⱥ��ɹ�
void OPMainManagerShareLib::slotAddSuccessGroup(GroupInfo groupInfo)
{
	QVariant var = QVariant::fromValue(groupInfo);
	contactsManager->recvGroupData(GroupInsert, var);
}

//Ⱥ����ӳ�Ա�ɹ�
void OPMainManagerShareLib::slotAddSuccessGroupUserInfo(QString userID, BuddyInfo buddy)
{
	chatManager->recvChat(GroupAddUser, QVariant::fromValue(userID), QVariant::fromValue(buddy));
}

void OPMainManagerShareLib::slotGroupsManager(int type, QVariant data)
{
	if (contactsManager)
	{
		IMDownLoadHeaderImg *headerImage = new IMDownLoadHeaderImg;
		contactsManager->recvGroupData(type, data);
		GroupInfo groupInfo = data.value<GroupInfo>();
		//�ж��Ƿ�����ͷ��
		if (headerImage->IsImageFile(groupInfo.groupLoacalHeadImage))
		{
			contactsManager->updateImage(GroupUpdate, groupInfo.groupId.toInt(), headerImage->GetImagePix(groupInfo.groupLoacalHeadImage));
		}
		else
		{
			contactsManager->updateImage(GroupUpdate, groupInfo.groupId.toInt(), headerImage->GetImagePix(groupInfo.groupDefaultAvatar));
			connect(headerImage, SIGNAL(sigUpdateBuddyHeaderImage(int, QPixmap)), this, SLOT(slotUpdateGroupHeaderImg(int, QPixmap)));
			headerImage->StartDownLoadGroupHeaderImage(groupInfo);
		}
	}
	if (walletManager)   //walletWidget��Ⱥ��������ʾ�Ĺ��ܡ�
	{
		if (type == GroupInsert)
			walletManager->addGroupsNum(1);
	}
}

void OPMainManagerShareLib::RevServerMessage(MessageInfo msgInfo)
{
	if (chatManager)
	{
		if (msgInfo.MsgDeliverType == 0)
		{
			QString userID = QString::number(msgInfo.nFromUserID);
			BuddyInfo info = gDataBaseOpera->DBGetBuddyInfoByID(userID);
			
			if (info.nUserId == -1)
			{
				info = gDataBaseOpera->DBGetGroupUserFromID(userID);

				if (info.strNickName.isEmpty())
					return;
			}
			
			QVariant message, buddy;
			message.setValue(msgInfo);
			buddy.setValue(info);
			chatManager->recvChat(PerMessage, message, buddy);

			if (mainWidget->isHidden())
			{
				mainWidget->StartMessageFlash(OpenPer, info.strLocalAvatar);
			}
		}
		if (msgInfo.MsgDeliverType == 1)
		{
			QString groupID = QString::number(msgInfo.nToUserID);
			GroupInfo info = gDataBaseOpera->DBGetGroupFromID(groupID);
			if (info.groupId.isEmpty())
			{
				/*����Ⱥ����Ϣ*/
				return;
			}
			QVariant message, group;
			message.setValue(msgInfo);
			group.setValue(info);
			chatManager->recvChat(GroupMessage, message, group);

			if (mainWidget->isHidden())
			{
				mainWidget->StartMessageFlash(OpenGroup, info.groupLoacalHeadImage);
			}
		}
	}
}

void OPMainManagerShareLib::slotOpenChat(int type, QVariant userID)
{
	chatManager->recvChat(type, userID);
	//���õ�ǰҳ��
	mainWidget->setCurrentWidget(type);
}

void OPMainManagerShareLib::slotAddCreateGroup()
{
	//CreateGroupWidget * group_creater = new CreateGroupWidget;
	//connect(group_creater, SIGNAL(sigInsertGroupItemToGroupList(GroupInfo)), contactsManager, SLOT(slotInsertGroupInfo(GroupInfo)));
	//connect(group_creater, SIGNAL(sigCreateGroupSuccess(QString)), contactsManager, SLOT(doShowGroupChat(QString)));
	//group_creater->show();
}

void OPMainManagerShareLib::slotAddPerson()
{
	//IMAddPerson *mAddPersonWidget = new IMAddPerson();
	//mAddPersonWidget->show();
}

void OPMainManagerShareLib::setWalletInfo(WalletInfo info)
{
	walletManager->setWalletInfo(info);
}

//��������״̬,������ߣ���������������ѣ����¿�ʼ����
void OPMainManagerShareLib::slotDormancyState(bool bState)
{
	if (gSocketMessage)
	{
		gSocketMessage->setReConnectState(!bState);
	}
}

//ɾ��Ⱥ��
void OPMainManagerShareLib::slotDeleteGroup(QString groupID)
{
	if (mainWidget)
	{
		QVariant var = QVariant::fromValue(groupID);
		contactsManager->recvGroupData(GroupDelete, var);
	}
}

void OPMainManagerShareLib::slotDeleteBuddy(int type, QVariant userID)
{
	contactsManager->recvBuddyData(type, userID);
}

void OPMainManagerShareLib::slotDownloadStranger(bool success, QString result)
{
	if (success)
	{
		qDebug() << result;
	}
}
