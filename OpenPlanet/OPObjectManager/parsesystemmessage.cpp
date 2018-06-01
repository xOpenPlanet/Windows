#include "parsesystemmessage.h"
#include "imtranstype.h"
#include "httpnetworksharelib.h"
#include <QJsonParseError>
#include <QJsonDocument>
#include <QDir>
#include <QApplication>
#include <QJsonObject>
#include <QDebug>
#include "define.h"

ParseSystemMessage::ParseSystemMessage(QObject *parent)
	: QObject(parent)
{

}

ParseSystemMessage::~ParseSystemMessage()
{

}

QString ParseSystemMessage::GetExeDir()
{
	QString path;
	QDir dir;
	return dir.currentPath();
}

void ParseSystemMessage::ParseSysMessage(MessageInfo messageInfo)
{
	QString strMessage = messageInfo.strMsg;
	QJsonParseError jsonError;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(strMessage.toUtf8(), &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QVariantMap result = jsonDocument.toVariant().toMap();
			if (result["CMD"].toString() == "applyAddFriend")                //������Ӻ�����Ϣ
			{
				int userID = result["friendUserId"].toInt();
				//if (!gDataBaseOpera->DBJudgeFriendIsHaveByID(QString::number(userID)))
					//emit sigApplyFriend(QString::number(userID));
			}
			else if (result["CMD"].toString() == "applyAddGroup")                //�������Ⱥ��
			{
				//GroupInfo groupInfo = gDataBaseOpera->DBGetGroupFromID(QString::number(result["groupId"].toInt()));
				//QString applyID = result["userId"].toString();
				//if (!gDataBaseOpera->DBJudgeGroupIsHaveBuddy(groupInfo.groupId, applyID))
					//emit sigApplyAddGroup(applyID, groupInfo.groupId);
			}
			else if (result["CMD"].toString() == "updateUser")             //�����û���Ϣ
			{
				OnDealUpDateUser(messageInfo,result["user"].toMap());
			}
			else if (result["CMD"].toString() == "updateGroup")          //����Ⱥ����Ϣ
			{
				OnDealUpdateGroupInfo(result);
			}
			else if (result["CMD"].toString() == "addFriend")
			{
				OnDealAddFriend(result);
			}
			else if (result["CMD"].toString() == "addUserToGroup")   //�������Ⱥ��ͬ��
			{
				OnDealAddUserToGroup(result);
			}
			else if (result["CMD"].toString() == "userQuitGroup")
			{
				OnDealUserQuitGroup(result);
			}
			else if (result["CMD"].toString() == "dissolveGroup")                //��ɢȺ��
			{
				OnDealDisSolveGroup(result);
			}
			else if (result["CMD"].toString() == "deleteFriend")
			{
				gDataBaseOpera->DBDeleteBuddyInfoByID(result["friendUserId"].toString());
				emit sigDeleteFriend(BuddyDelete, result["friendUserId"]);
			}
		}
	}
}

//���º�����Ϣ
void ParseSystemMessage::OnDealUpDateUser(MessageInfo msgInfo, QVariantMap mapResult)
{
	BuddyInfo buddyInfo;
	buddyInfo.strHttpAvatar = mapResult["avatar"].toString();
	buddyInfo.strEmail = mapResult["email"].toString();
	buddyInfo.strMobilePhone = mapResult["mobilePhone"].toString();
	buddyInfo.strNickName = mapResult["nickName"].toString();
	buddyInfo.strPingYin = mAlphabeticalSort.GetChineseSpell(buddyInfo.strNickName);
	buddyInfo.strNote = mapResult["note"].toString();
	buddyInfo.strPhone = mapResult["phone"].toString();
	buddyInfo.strSex = mapResult["sex"].toString();
	buddyInfo.strSign = mapResult["sign"].toString();
	buddyInfo.nUserId = mapResult["userId"].toInt();
	buddyInfo.strUserName = mapResult["userName"].toString();
	buddyInfo.nUserType = mapResult["userType"].toInt();
	buddyInfo.strLocalAvatar = GetExeDir() + "/resource/header/" + mapResult["userId"].toString() + ".jpg";
	if (buddyInfo.strSex == "F")//Ĭ��ͷ��
	{
		buddyInfo.strDefaultAvatar = QString(":/IMChatClient/Resources/imchatclient/female.png");
	}
	else
	{
		buddyInfo.strDefaultAvatar = QString(":/PerChat/Resources/person/temp.png");
	}
	QFile::remove(buddyInfo.strLocalAvatar);
	buddyInfo.BuddyType = 1;

	if (gDataManager)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		if (gDataBaseOpera)
		{
			if (gDataBaseOpera->DBJudgeBuddyIsHaveByID((QString::number(buddyInfo.nUserId))))
			{
				gDataBaseOpera->DBInsertBuddyInfo(buddyInfo);
			}
			if (gDataBaseOpera->DBJudgeGroupIsHaveBuddy(QString::number(msgInfo.nToUserID), QString::number(buddyInfo.nUserId)))
			{
				gDataBaseOpera->DBInsertGroupBuddyInfo(QString::number(msgInfo.nToUserID), buddyInfo);
			}
		}
		if (buddyInfo.nUserId == userInfo.nUserID)
		{
			userInfo.strUserNickName = mapResult["nickName"].toString();
			userInfo.strUserName = mapResult["nickName"].toString();
			userInfo.strUserAvatarHttp = mapResult["avatar"].toString();
			userInfo.strSex = mapResult["sex"].toString();
			userInfo.strNote = mapResult["note"].toString();
			userInfo.strEmil = mapResult["email"].toString();
			userInfo.strSign = mapResult["sign"].toString();
			userInfo.strPhone = mapResult["phone"].toString();
			userInfo.strUserAvatarLocal = GetExeDir() + "/resource/header/" + mapResult["userId"].toString() + ".jpg";
			QFile::remove(userInfo.strUserAvatarLocal);
			gDataManager->setUserInfo(userInfo);  //
			emit sigUpdateUserInfo(userInfo);        //�����û���Ϣ
		}
		/*��ʼ���غ���ͷ��*/
		IMDownLoadHeaderImg *headerImage = new IMDownLoadHeaderImg;
		connect(headerImage, SIGNAL(sigUpdateBuddyHeaderImage(int, QPixmap)), this, SLOT(slotUpdateBuddyHeaderImage(int, QPixmap)));
		headerImage->StartDownLoadBuddyeHeaderImage(buddyInfo);
	}
}

//���º���ͷ��
void ParseSystemMessage::slotUpdateBuddyHeaderImage(int buddyID, QPixmap pix)
{
	IMDownLoadHeaderImg *headerImage = qobject_cast<IMDownLoadHeaderImg*>(sender());
	BuddyInfo buddyInfo = gDataBaseOpera->DBGetBuddyInfoByID(QString::number(buddyID));
	emit sigUpdateInfo(BuddyUpdate, QVariant::fromValue(buddyInfo));
	if (headerImage)
	{
		headerImage->deleteLater();
		headerImage = NULL;
	}
}

//����Ⱥ����Ϣ
void ParseSystemMessage::OnDealUpdateGroupInfo(QVariantMap mapResult)
{
	GroupInfo groupInfo;
	groupInfo.groupHttpHeadImage = mapResult["avatar"].toString();
	groupInfo.groupId = mapResult["groupId"].toString();
	groupInfo.groupName = mapResult["groupName"].toString();
	groupInfo.groupLoacalHeadImage = QStringLiteral("resource/header/groupheader/") + groupInfo.groupId + ".jpg";
	groupInfo.groupDefaultAvatar = ":/GroupChat/Resources/groupchat/group.png";
	
	QFile::remove(groupInfo.groupLoacalHeadImage);

	if (gDataBaseOpera)
	{
		GroupInfo oldGroupInfo = gDataBaseOpera->DBGetGroupFromID(groupInfo.groupId);
		groupInfo.createUserId = oldGroupInfo.createUserId;
		gDataBaseOpera->DBInsertGroupInfo(groupInfo);
	}

	IMDownLoadHeaderImg *headerImage = new IMDownLoadHeaderImg;
	connect(headerImage, SIGNAL(sigUpdateBuddyHeaderImage(int, QPixmap)), this, SLOT(slotUpdateGroupHeaderImage(int, QPixmap)));
	headerImage->StartDownLoadGroupHeaderImage(groupInfo);
}

//����Ⱥ��ͷ��
void ParseSystemMessage::slotUpdateGroupHeaderImage(int buddyID, QPixmap pix)
{
	IMDownLoadHeaderImg *headerImage = qobject_cast<IMDownLoadHeaderImg*>(sender());
	if (gDataBaseOpera)
	{
		GroupInfo groupInfo = gDataBaseOpera->DBGetGroupFromID(QString::number(buddyID));
		emit sigUpdateInfo(GroupUpdate, QVariant::fromValue(groupInfo));
	}
	if (headerImage)
	{
		headerImage->deleteLater();
		headerImage = NULL;
	}
}

//�����û��˳�Ⱥ��
void ParseSystemMessage::OnDealUserQuitGroup(QVariantMap mapResult)
{
	QString groupID = QString::number(mapResult["groupId"].toInt());
	QString userID = QString::number(mapResult["groupUserId"].toInt());
	if (gDataBaseOpera)
	{
		gDataBaseOpera->DBDeleteGroupUserByID(groupID, userID);
	}
	emit sigUserQuitGroup(groupID, userID);
}

//������Ӻ��ѳɹ�
void ParseSystemMessage::OnDealAddFriend(QVariantMap result)
{
	QString strBuddyID = result["friendUserId"].toString();
	if (!gDataBaseOpera->DBJudgeFriendIsHaveByID(strBuddyID))
	{
		HttpNetWork::HttpNetWorkShareLib *PersonInfo = new HttpNetWork::HttpNetWorkShareLib();
		connect(PersonInfo, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotRequestPersonInfoFinished(bool, QString)));
		AppConfig configInfo = gDataManager->getAppConfigInfo();
		QString strRequest = configInfo.MessageServerAddress + HTTP_GETBUDDYINFOBYID + strBuddyID;
		PersonInfo->getHttpRequest(strRequest);
	}
}

void ParseSystemMessage::slotRequestPersonInfoFinished(bool bResult,QString result)
{
	if (bResult)
	{
		QJsonParseError jsonError;
		BuddyInfo buddyInfo;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(result.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (jsonDocument.isObject())
			{
				QVariantMap result = jsonDocument.toVariant().toMap();
				if (result["result"].toString() == "success")
				{
					QVariantMap usrInfo = result["user"].toMap();
					if (!usrInfo.isEmpty())
					{
						QString strPinYin;
						buddyInfo.strHttpAvatar = usrInfo["avatar"].toString();
						buddyInfo.strEmail = usrInfo["email"].toString();
						buddyInfo.strMobilePhone = usrInfo["mobilePhone"].toString();
						buddyInfo.strNickName = usrInfo["nickName"].toString();
						buddyInfo.strNote = usrInfo["note"].toString();
						buddyInfo.strPhone = usrInfo["phone"].toString();
						buddyInfo.strSex = usrInfo["sex"].toString();
						buddyInfo.strSign = usrInfo["sign"].toString();
						buddyInfo.nUserId = usrInfo["userId"].toInt();
						buddyInfo.strUserName = usrInfo["userName"].toString();
						buddyInfo.nUserType = usrInfo["userType"].toInt();
						buddyInfo.BuddyType = 1;
						buddyInfo.strLocalAvatar = GetExeDir() + "/resource/header/" + usrInfo["userId"].toString() + ".jpg";
						if (buddyInfo.strSex == "F")//Ĭ��ͷ��
						{
							buddyInfo.strDefaultAvatar = QString(":/IMChatClient/Resources/imchatclient/female.png");
						}
						else
						{
							buddyInfo.strDefaultAvatar = QString(":/PerChat/Resources/person/temp.png");
						}
						//�������ƻ�ȡ����ĸ
						if (!buddyInfo.strNote.isEmpty())
							strPinYin = mAlphabeticalSort.GetChineseSpell(buddyInfo.strNote);
						else
							strPinYin = mAlphabeticalSort.GetChineseSpell(buddyInfo.strNickName);
						buddyInfo.strPingYin = strPinYin;
						if (gDataBaseOpera)
						{
							gDataBaseOpera->DBInsertBuddyInfo(buddyInfo);
						}
					}
				}
			}
		}
		emit sigAddFriendSuccess(buddyInfo);
	}
}

void ParseSystemMessage::slotRequestGroupInfoFinished(bool bResult, QString result)
{
	if (bResult)
	{
		QJsonParseError jsonError;
		GroupInfo groupInfo;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(result.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (jsonDocument.isObject())
			{
				QVariantMap result = jsonDocument.toVariant().toMap();
				if (result["result"].toString() == "success")
				{
					QVariantMap resultInfo = result["group"].toMap();
					groupInfo.groupHttpHeadImage = resultInfo["avatar"].toString();
					groupInfo.createTime = resultInfo["createTime"].toString();
					groupInfo.createUserId = resultInfo["createUserId"].toString();
					groupInfo.groupId = resultInfo["groupId"].toString();
					groupInfo.groupLoacalHeadImage = ":/GroupChat/Resources/groupchat/group.png";
					groupInfo.groupDefaultAvatar = QStringLiteral(":/GroupChat/Resources/groupchat/group.png");
					groupInfo.groupName = resultInfo["groupName"].toString();
					gDataBaseOpera->DBInsertGroupInfo(groupInfo);
				}
			}
		}
		emit sigAddSuccessGroup(groupInfo);
	}
}

//�������Ⱥ��ͬ��
void ParseSystemMessage::OnDealAddUserToGroup(QVariantMap result)
{
	QString strGroupID = result["groupId"].toString();
	QString groupUserID = result["groupUserId"].toString();

	UserInfo userInfo = gDataManager->getUserInfo();
	//�ж�����ϵ�userId�Ƿ��ǵ�¼�û�
	if (groupUserID == QString::number(userInfo.nUserID))
	{
		if (!gDataBaseOpera->DBJudgeGroupIsHaveByID(groupUserID))
		{
			HttpNetWork::HttpNetWorkShareLib *PersonInfo = new HttpNetWork::HttpNetWorkShareLib();
			connect(PersonInfo, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotRequestGroupInfoFinished(bool, QString)));
			UserInfo userInfo = gDataManager->getUserInfo();
			AppConfig appConf = gDataManager->getAppConfigInfo();
			QString strResult = appConf.MessageServerAddress + HTTP_GETGROUPINFOBYGROUPID + QString("?userId=") + QString::number(userInfo.nUserID) + "&passWord=" + userInfo.strUserPWD + "&groupId=" + strGroupID;
			PersonInfo->getHttpRequest(strResult);
		}
	}
	else
	{
		//�����Ⱥ�Ĳ����û������жϱ����Ƿ������Ⱥ�����������Ⱥ���Ż����Ⱥ��Ա��
		QString localGroupName = gDataBaseOpera->DBGetGroupFromID(strGroupID).groupName;
		//��localGroupName��Ϊ�գ������������Ⱥ��
		if (!localGroupName.isEmpty())
		{
			BuddyInfo buddy = gDataBaseOpera->DBGetGroupUserFromID(groupUserID);
			if (buddy.nUserId == groupUserID.toInt())
			{
				gDataBaseOpera->DBInsertGroupBuddyInfo(strGroupID, buddy);
				emit sigAddSuccessGroupUserInfo(strGroupID, buddy);  /*Ⱥ����ӳ�Ա�ɹ�*/
				return;
			}
			/*Ⱥ����ӳ�Ա�ɹ� ����Ⱥ����Ϣ*/
			HttpNetWork::HttpNetWorkShareLib *PersonInfo = new HttpNetWork::HttpNetWorkShareLib();
			connect(PersonInfo, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotRecvAddGroupUser(bool, QString)));
			AppConfig configInfo = gDataManager->getAppConfigInfo();
			QString strRequest = configInfo.MessageServerAddress + HTTP_GETBUDDYINFOBYID + groupUserID;
			PersonInfo->setObjectName(strGroupID);
			PersonInfo->getHttpRequest(strRequest);
		}
	}
}

void ParseSystemMessage::slotRecvAddGroupUser(bool success, QString data)
{
	if (success)
	{
		HttpNetWork::HttpNetWorkShareLib *act = qobject_cast<HttpNetWork::HttpNetWorkShareLib*>(sender());
		QString addGroupID = act->objectName();

		QJsonDocument document = QJsonDocument::fromJson(data.toUtf8());
		QJsonObject object = document.object().take("user").toObject();

		BuddyInfo info;
		info.strHttpAvatar = object.take("avatar").toString();
		info.strNickName = object.take("nickName").toString();
		info.strMobilePhone = object.take("nickName").toString();
		info.strPhone = object.take("phone").toString();
		info.strUserName = object.take("userName").toString();
		info.strSign = object.take("sign").toString();
		info.strSex = object.take("sex").toString();
		info.nUserId = object.take("userId").toInt();
		info.nUserType = object.take("userType").toInt();
		info.BuddyType = 0;
		info.strDefaultAvatar = QString(":/PerChat/Resources/person/temp.png");
		QString strPath = QApplication::applicationDirPath();
		info.strLocalAvatar = strPath + "/resource/header/" + QString::number(info.nUserId) + ".jpg";
		gDataBaseOpera->DBInsertGroupBuddyInfo(addGroupID, info);


		emit sigAddSuccessGroupUserInfo(addGroupID, info);
	}
}

//��ɢȺ��
void ParseSystemMessage::OnDealDisSolveGroup(QVariantMap result)
{
	QString groupID = result["groupId"].toString();
	if (gDataBaseOpera)
	{
		gDataBaseOpera->DBDeleteGroupInfoByID(groupID);
	}
	emit sigDeleteGroup(groupID);
}