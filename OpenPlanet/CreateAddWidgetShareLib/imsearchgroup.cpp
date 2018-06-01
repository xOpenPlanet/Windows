#include "imsearchgroup.h"

IMSearchGroup::IMSearchGroup(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.mPButtonSearchGroup->setText("查找");

	connect(ui.mPButtonSearchGroup, SIGNAL(clicked()), this, SLOT(doClickSearchGroup()));
	connect(ui.mlineEditSearchGroup, SIGNAL(returnPressed()), this, SLOT(doClickSearchGroup()));
	connect(ui.mListWidgetSearchGroup, SIGNAL(sigAddPerson(QString)), this, SLOT(doAddGroup(QString)));
}

IMSearchGroup::~IMSearchGroup()
{

}

void IMSearchGroup::doClickSearchGroup()
{
	ui.mListWidgetSearchGroup->clear();
	QString strData = ui.mlineEditSearchGroup->text();
	if (!strData.isEmpty())
	{
		OnSearchGroup(strData);
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("查找群组"), QStringLiteral("输入搜索内容为空!"));
	}
}

void IMSearchGroup::OnSearchGroup(QString strData)
{
	mStrSaveSearchContent = strData;

	UserInfo userInfo = gDataManager->getUserInfo();

	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(doHttpSearchGroupResultInfo(bool, QString)));

	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/search"
		+ QString("?userId=%1&passWord=%2&keyWord=%3").arg(userInfo.nUserID).arg(userInfo.strUserPWD).arg(strData);

	http->getHttpRequest(url);
}

void IMSearchGroup::doHttpSearchGroupResultInfo(bool bState, QString strResult)
{
	if (bState)
	{
		ParseSearchGroupResult(strResult);
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("查找群组"), QStringLiteral("查找群组失败!"));
	}
}

void IMSearchGroup::ParseSearchGroupResult(QString strResult)
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
							GroupInfo groupInfo;
							QVariantMap listData = userInfoList.at(i).toMap();
							QString strCreateTime = listData["createTime"].toString();
							QString strUserID = listData["createUserId"].toString();
							QString strGroupID = listData["groupId"].toString();
							QString strGroupName = listData["groupName"].toString();
							QString strHttpAvatar = listData["avatar"].toString();
							if (mStrSaveSearchContent == strGroupID)
							{
								QString strTemp = QString("%1(%2)").arg(strGroupName).arg(strGroupID);
								ui.mListWidgetSearchGroup->OnInsertSearchGroupList(strGroupID, strHttpAvatar, strTemp);
							}
							else if (mStrSaveSearchContent == strGroupName)
							{
								ui.mListWidgetSearchGroup->OnInsertSearchGroupList(strGroupID, strHttpAvatar, strGroupName);
							}
						}
					}
				}
			}
			else
			{
				QMessageBox::information(this, QStringLiteral("查找群组"), QStringLiteral("解析群组信息失败!"));
			}
		}
		else
			QMessageBox::information(this, QStringLiteral("查找群组"), QStringLiteral("解析群组信息失败!"));
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("查找群组"), QStringLiteral("解析群组信息失败!"));
	}
}

void IMSearchGroup::doAddGroup(QString strGroupID)
{
	if (gDataBaseOpera)
	{
		if (!gDataBaseOpera->DBJudgeGroupIsHaveByID(strGroupID))
		{
			UserInfo userInfo = gDataManager->getUserInfo();

			HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
			connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(doHttpAddGroupResultInfo(bool, QString)));

			QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/applyAddGroup"
				+ QString("?userId=%1&passWord=%2&groupId=%3").arg(strGroupID).arg(userInfo.nUserID).arg(userInfo.strUserPWD);

			http->getHttpRequest(url);
		}
		else
		{
			QMessageBox::information(this, QStringLiteral("请求群组"), QStringLiteral("已经加入该群组!"));
		}
	}
}

void IMSearchGroup::doHttpAddGroupResultInfo(bool bResult,QString strResult)
{
	if (bResult)
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
					QMessageBox::information(this, QStringLiteral("请求群组"), QStringLiteral("请求群组成功!"));
					return;
				}
			}
		}
	}
	QMessageBox::information(this, QStringLiteral("请求群组"), QStringLiteral("请求群组失败!"));
}