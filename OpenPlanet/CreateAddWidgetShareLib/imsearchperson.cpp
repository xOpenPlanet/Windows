#include "imsearchperson.h"

IMSearchPerson::IMSearchPerson(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.mPButtonSearchPerson->setText("查找");
	connect(ui.mPButtonSearchPerson, SIGNAL(clicked()), this, SLOT(doClickSearch()));
	connect(ui.mListWidgetSearchPerson, SIGNAL(sigAddPerson(QString)), this, SLOT(doAddPerson(QString)));
	connect(ui.mlineEditSearchPerson, SIGNAL(returnPressed()), this, SLOT(doClickSearch()));
}

IMSearchPerson::~IMSearchPerson()
{
	
}

void IMSearchPerson::doClickSearch()
{
	ui.mListWidgetSearchPerson->clear();
	QString strData = ui.mlineEditSearchPerson->text();
	if (!strData.isEmpty())
	{
		OnSearchPerson(strData);
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("查找好友"), QStringLiteral("输入搜索内容为空!"));
	}
}

void IMSearchPerson::OnSearchPerson(QString strData)
{
	mStrSaveSearchContent = strData;

	UserInfo userInfo = gDataManager->getUserInfo();

	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(doHttpSearchPersonResultInfo(bool, QString)));

	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/user/search"
		+ QString("?userId=%1&passWord=%2&keyWord=%3").arg(userInfo.nUserID).arg(userInfo.strUserPWD).arg(strData);

	http->getHttpRequest(url);
}

void IMSearchPerson::doHttpSearchPersonResultInfo(bool bState, QString strResult)
{
	if (bState)
	{
		ParseSearchPersonResult(strResult);
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("查找好友"), QStringLiteral("查找好友失败!"));
	}
}

void IMSearchPerson::ParseSearchPersonResult(QString strResult)
{
	int nTemp = 0;
	UserInfo userInfo = gDataManager->getUserInfo();
	QString strID = QString("%1").arg(userInfo.nUserID);
	QJsonParseError jsonError;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(strResult.toUtf8(), &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QJsonObject obj = jsonDocument.object();
			if (obj["result"].toString() == "success")
			{
				QVariant strTemp;
				QJsonValue userInfoValue;
				foreach(QString key, obj.keys())
				{
					userInfoValue = obj.take(key);
					strTemp = userInfoValue.toVariant();
					if (userInfoValue.isArray())
					{
						QVariantList userInfoList = strTemp.toList();
						for (int i = 0; i < userInfoList.size(); i++)
						{
							QVariantMap listData = userInfoList.at(i).toMap();
							QString strHttpAvatar = listData["avatar"].toString();
							QString strBuddyID = listData["userId"].toString();
							QString strNickName = listData["nickName"].toString();
							if (strBuddyID == strID)
							{
								continue;
							}
							if (mStrSaveSearchContent == strBuddyID)
							{
								QString strTemp = QString("%1(%2)").arg(strNickName).arg(strBuddyID);
								ui.mListWidgetSearchPerson->OnInsertSearchBuddyList(strBuddyID, strHttpAvatar, strTemp);
								nTemp++;
							}
							else if(mStrSaveSearchContent == strNickName)
							{
								ui.mListWidgetSearchPerson->OnInsertSearchBuddyList(strBuddyID, strHttpAvatar, strNickName);
								nTemp++;
							}
						}
					}
				}
			}
			else
			{
				QMessageBox::information(this, QStringLiteral("查找"), QStringLiteral("解析好友信息失败!"));
			}
		}
	}
	if (nTemp == 0)
	{
		QMessageBox::information(this, QStringLiteral("查找"), QStringLiteral("没有找到符合搜索条件的用户!"));
	}
}

void IMSearchPerson::doAddPerson(QString strBuddyID)
{
	/*首先判断是否有好友*/
	if (gDataManager)
	{
		if (!gDataBaseOpera->DBJudgeBuddyIsHaveByID(strBuddyID))
		{
			UserInfo userInfo = gDataManager->getUserInfo();

			HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
			connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(doHttpAddPersonResultInfo(bool, QString)));

			QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/user/applyAddFriend"
				+ QString("?userId=%1&passWord=%2&friendUserId=%3").arg(userInfo.nUserID).arg(userInfo.strUserPWD).arg(strBuddyID);

			http->getHttpRequest(url);
		}
		else
		{
			QMessageBox::information(this, QStringLiteral("请求好友"), QStringLiteral("已经加入该好友!"));
		}
	}
}

void IMSearchPerson::doHttpAddPersonResultInfo(bool bResult,QString strResult)
{
	QJsonParseError jsonError;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(strResult.toUtf8(), &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QJsonObject obj = jsonDocument.object();
			if (obj["result"].toString() == "success")
			{
				QMessageBox::information(this, QStringLiteral("请求好友"), QStringLiteral("请求好友成功!"));
				return;
			}
		}
	}
	QMessageBox::information(this, QStringLiteral("请求好友"), QStringLiteral("请求好友失败!"));
}

void IMSearchPerson::ClearList()
{
	ui.mListWidgetSearchPerson->clear();
	ui.mlineEditSearchPerson->clear();
}