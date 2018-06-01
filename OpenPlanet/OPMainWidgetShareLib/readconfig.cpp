#include "readconfig.h"

ReadConfig::ReadConfig(QObject *parent)
	: QObject(parent)
{

}

ReadConfig::~ReadConfig()
{

}

QList<AppButton> ReadConfig::read()
{
	QList<AppButton> appList;
	//¶ÁÐ´×¢²á±íµÄ²Ù×÷¡£
	QDomDocument doc(QStringLiteral("xml"));
	QFile file(QApplication::applicationDirPath() + "/config/app.xml");
	if (file.open(QIODevice::ReadOnly))
	{
		if (doc.setContent(&file))
		{
			QDomElement docElem = doc.documentElement();
			QDomNode app = docElem.firstChild();
			while (!app.isNull())
			{
				QDomElement toolButton = app.toElement();
				if (!toolButton.isNull())
				{
					QDomNode node = toolButton.firstChild();
					AppButton appButton;
					while (!node.isNull())
					{
						QDomElement element = node.toElement();
						if (element.tagName() == "id")
							appButton.id = element.text().toInt();
						if (element.tagName() == "name")
							appButton.name = element.text();
						if (element.tagName() == "className")
							appButton.className = element.text();
						if (element.tagName() == "icon")
							appButton.icon = element.text();
						if (element.tagName() == "configPath")
							appButton.configPath = element.text();
						node = node.nextSibling();
					}
					appList.append(appButton);
				}

				app = app.nextSibling();
			}
		}
		file.close();
	}

	return appList;
}
