#include "updatesharelib.h"

UpdateShareLib::UpdateShareLib()
{

}

UpdateShareLib::~UpdateShareLib()
{

}

void UpdateShareLib::onUpdate()
{
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotUpdateApp(bool, QString)));
	QString url = gDataManager->getAppConfigInfo().strYWYHRequestURL
		+ QString("/appUpgrade?appId=winUpdateInf&deviceType=win");
	http->getHttpRequest(url);
}

void UpdateShareLib::slotUpdateApp(bool success, QString result)
{
	if (success)
	{
		QString updateURL = "";
		QJsonParseError jsonError;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(result.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (jsonDocument.isObject())
			{
				QVariantMap result = jsonDocument.toVariant().toMap();
				if (result["result"].toString() == "success")
				{
					/*判断下当前版本号及更新文件路径*/
					QVariantMap appUpgrade = result["appUpgrade"].toMap();
					if (!appUpgrade.isEmpty())
					{
						QVariantMap winUpgrade = appUpgrade["win"].toMap();
						QVariantMap appFile = winUpgrade["appFile"].toMap();
						/*取出版本号*/
						QString strServerVersion = appFile["version"].toString();

						std::string v1 = gDataManager->getAppConfigInfo().appVersion.updateVersion.toStdString();
						int nResult = VersionCompare(v1, strServerVersion.toStdString());
						if (nResult == -1 || v1 == "")
						{
							updateURL = appFile["path"].toString();;
						}
					}
				}
			}
		}

		if (!updateURL.isEmpty())   //需要升级升级程序。
		{
			HttpNetWork::HttpDownLoadFile *http = new HttpNetWork::HttpDownLoadFile;
			connect(http, SIGNAL(sigDownFinished(bool)), this, SLOT(slotDownloadUpdate(bool)));
			QString file = "./updateApp.zip";
			http->setData(QVariant(file));
			http->StartDownLoadFile(updateURL, file);
		}
		else             //升级程序不需要升级，检测是否需要升级主程序。
		{
			HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
			connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotUpdateMain(bool, QString)));
			QString url = gDataManager->getAppConfigInfo().strYWYHRequestURL + QString("/appUpgrade?appId=%1&deviceType=win").arg(gDataManager->getAppConfigInfo().appVersion.appID);
			http->getHttpRequest(url);
		}
	}
	else
	{
		QMessageBox::information(NULL, QStringLiteral("注意"), QStringLiteral("连接服务器失败，程序无法启动"));
		qApp->exit();
	}
}

void UpdateShareLib::slotDownloadUpdate(bool success)
{
	if (success)
	{
		static wchar_t szbuf[260];
		::GetModuleFileNameW(NULL, szbuf, 260);
		::PathRemoveFileSpecW(szbuf);

		std::wstring path;
		path.append(szbuf);
		if (path.at(path.size() - 1) != L'\\')
		{
			path.append(L"\\");
		}

		qDebug() << QStringLiteral("下载完成,开始解压!");
		HttpNetWork::HttpDownLoadFile *download = qobject_cast<HttpNetWork::HttpDownLoadFile *>(sender());
		QString fileName = download->getData().toString();
		QString strDir = QString::fromStdWString(path);

		if (ZipUtil::UnzipFile(fileName.toStdWString(), strDir.toStdWString()))
		{
			QFile::remove(fileName);//刪除文件
			HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
			connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotUpdateMain(bool, QString)));
			QString url = gDataManager->getAppConfigInfo().strYWYHRequestURL + QString("/appUpgrade?appId=%1&deviceType=win").arg(gDataManager->getAppConfigInfo().appVersion.appID);
			http->getHttpRequest(url);
		}
	}
	else
	{
		QMessageBox::information(NULL, QStringLiteral("注意"), QStringLiteral("升级程序包下载失败，程序无法启动"));
		qApp->exit();
	}
}

void UpdateShareLib::slotUpdateMain(bool success, QString result)
{
	if (success)
	{
		QJsonParseError jsonError;
		QJsonDocument jsonDocument = QJsonDocument::fromJson(result.toUtf8(), &jsonError);
		if (jsonError.error == QJsonParseError::NoError)
		{
			if (jsonDocument.isObject())
			{
				QVariantMap result = jsonDocument.toVariant().toMap();
				if (result["result"].toString() == "success")
				{
					/*判断下当前版本号及更新文件路径*/
					QVariantMap appUpgrade = result["appUpgrade"].toMap();
					if (!appUpgrade.isEmpty())
					{
						QVariantMap winUpgrade = appUpgrade["win"].toMap();
						QVariantMap appFile = winUpgrade["appFile"].toMap();
						/*取出版本号*/
						QString strServerVersion = appFile["version"].toString();

						std::string v1 = gDataManager->getAppConfigInfo().appVersion.versionID.toStdString();
						int nResult = VersionCompare(v1, strServerVersion.toStdString());
						if (nResult == -1)  //需要升级。
						{
							QStringList arguments;
							arguments.append(strServerVersion);
							arguments.append(appFile["path"].toString());
							arguments.append(appFile["des"].toString());
							arguments.append(QApplication::applicationName());

							LoginDatabaseOperaShareLib *database = new LoginDatabaseOperaShareLib;
							database->ConnectLoginDB("database//common.db", "Login");
							NetWorkProxyInfo proxy = database->GetNetWorkProxyInfoDB();
							arguments.append(QString::number(proxy.proxyModel));
							arguments.append(proxy.strUserName);
							arguments.append(proxy.strUserPwd);
							arguments.append(proxy.strAddress);
							arguments.append(proxy.strPort);
							delete database;

							//传入程序名。
							arguments.append(gDataManager->getAppConfigInfo().appVersion.appName);

							QString strUpdatePath = QApplication::applicationDirPath() + "/" + "update.exe";

							LPCWSTR path = reinterpret_cast<const wchar_t *>(strUpdatePath.utf16());
							QString arg;
							for (int i = 0; i < arguments.count(); i++)
							{
								QString argument;
								if (arguments[i].isEmpty())
									argument = "\"\"";
								else
									argument = arguments[i];

								if (i == 0)
									arg += argument;
								else
									arg += " " + argument;
							}

							LPCWSTR str = reinterpret_cast<const wchar_t *>(arg.utf16());
							ShellExecute(0, L"open", path, str, NULL, SW_SHOW);
						}
						else    //不需要升级。
						{
							emit sigAlreadyLatest();
						}
					}
				}
			}
		}
	}
	else
	{
		QMessageBox::information(NULL, QStringLiteral("注意"), QStringLiteral("连接服务器失败，程序无法启动"));
		qApp->exit();
	}
}

/*提供版本比对*/
int UpdateShareLib::VersionCompare(std::string v1, std::string v2)
{
	int vnum1 = 0, vnum2 = 0;
	for (int i = 0, j = 0; (i < v1.length() || j < v2.length());)
	{
		while (i < v1.length() && v1[i] != '.')
		{
			vnum1 = vnum1 * 10 + (v1[i] - '0');
			i++;
		}
		while (j < v2.length() && v2[j] != '.')
		{
			vnum2 = vnum2 * 10 + (v2[j] - '0');
			j++;
		}
		if (vnum1 > vnum2)
			return 1;
		if (vnum2 > vnum1)
			return -1;      //代表需要升级。
		vnum1 = vnum2 = 0;
		i++;
		j++;
	}
	return 0;
}