#include "readappconfig.h"
#include <QDomDocument>
#include <QDomElement>
#include <QFile>

ReadAppConfig::ReadAppConfig()
{

}

ReadAppConfig::~ReadAppConfig()
{

}

//读取配置文件信息，返回ConfigApp结构体
AppConfig ReadAppConfig::ReadConfig(QString configPath)
{
	AppConfig configApp;
	QDomDocument doc(QStringLiteral("appConfig"));
	QFile file(configPath);
	if (!file.open(QIODevice::ReadOnly))
	{
		return configApp;
	}
	if (!doc.setContent(&file))
	{
		file.close();
		return configApp;
	}
	file.close();
	QDomElement docElem = doc.documentElement();
	QDomNode n = docElem.firstChild();
	while (!n.isNull())
	{
		QDomElement e = n.toElement();
		if (!e.isNull())
		{
			if (e.tagName() == "server")
			{
				QDomNode nodeTemp = e.firstChild();
				while (!nodeTemp.isNull())
				{
					QDomElement elementTemp = nodeTemp.toElement();
					if (elementTemp.tagName() == QStringLiteral("websocket"))
					{
						if (elementTemp.attributeNode("Enable").value() == "true")
						{
							configApp.webSocketConfig.bEnable = true;
						}
						else
						{
							configApp.webSocketConfig.bEnable = false;
						}
						configApp.webSocketConfig.port = elementTemp.text().toInt();
					}
					else if (elementTemp.tagName() == QStringLiteral("http"))
					{
						if (elementTemp.attributeNode("Enable").value() == "true")
						{
							configApp.httpServerConfig.bEnable = true;
						}
						else
						{
							configApp.httpServerConfig.bEnable = false;
						}
						configApp.httpServerConfig.port = elementTemp.text().toInt();
					}
					nodeTemp = nodeTemp.nextSibling();
				}
			}
			else if (e.tagName() == "address")
			{
				QDomNode nodeTemp = e.firstChild();
				while (!nodeTemp.isNull())
				{
					QDomElement elementTemp = nodeTemp.toElement();
					if (elementTemp.tagName() == "MessageServerURL")
					{
						configApp.MessageServerAddress = elementTemp.text();
					}
					else if (elementTemp.tagName() == "BSServerURL")
					{
						configApp.strYWYHRequestURL = elementTemp.text() + "/user";
						configApp.OrganizationURL = elementTemp.text() + "/org";
					}
					else if (elementTemp.tagName() == "PanServerURL")
					{
						configApp.PanServerUploadURL = elementTemp.text() + QStringLiteral("/files/file/directupload");
						configApp.PanServerDownloadURL = elementTemp.text() + QStringLiteral("/files/");
					}
					nodeTemp = nodeTemp.nextSibling();
				}
			}
			else if (e.tagName() == "version")
			{
				QDomNode nodeTemp = e.firstChild();
				while (!nodeTemp.isNull())
				{
					QDomElement elementTemp = nodeTemp.toElement();
					if (elementTemp.tagName() == "number")
					{
						configApp.appVersion.versionID = elementTemp.text();
					}
					else if (elementTemp.tagName() == "appid")
					{
						configApp.appVersion.appID = elementTemp.text();
					}
					else if (elementTemp.tagName() == "name")
					{
						configApp.appVersion.appName = elementTemp.text();
					}
					else if (elementTemp.tagName() == "update")
					{
						configApp.appVersion.updateVersion = elementTemp.text();
					}
					else if (elementTemp.tagName() == "appname")
					{
						configApp.appVersion.appString = elementTemp.text();
					}
					nodeTemp = nodeTemp.nextSibling();
				}
			}
			else if (e.tagName() == "robotConfig")
			{
				QDomNode nodeTemp = e.firstChild();
				while (!nodeTemp.isNull())
				{
					QDomElement elementTemp = nodeTemp.toElement();
					if (elementTemp.tagName() == "robotConfigPath")
					{
						configApp.RobotConfigPath = elementTemp.text();
					}
					nodeTemp = nodeTemp.nextSibling();
				}
			}
			else if (e.tagName() == "ShareMemory")
			{
				QDomNode nodeTemp = e.firstChild();
				while (!nodeTemp.isNull())
				{
					QDomElement elementTemp = nodeTemp.toElement();
					if (elementTemp.tagName() == "shareMemoryName")
					{
						configApp.shareMemory = elementTemp.text();
					}
					nodeTemp = nodeTemp.nextSibling();
				}
			}
		}
		else
		{
			return configApp;
		}
		n = n.nextSibling();
	}
	return  configApp;
}