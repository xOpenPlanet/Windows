#include <QtWidgets/QApplication>
#include <QResource>
#include <qsharedmemory.h>
#include "opobjectmanager.h"
#include "dependent.h"

int main(int argc, char *argv[])
{
	QApplication imchat(argc, argv);

	QResource::registerResource("resources.rcc");
	imchat.setQuitOnLastWindowClosed(false);
	OPObjectManager objectManager;
	objectManager.InitApp();
	AppConfig appConfig = objectManager.readAppConf(); //读取配置文件
	QSharedMemory *p_shareMem = new QSharedMemory(appConfig.shareMemory);
	int nIndex = 2;
	while (nIndex--)
	{
		if (p_shareMem->attach(QSharedMemory::ReadOnly))
		{
			p_shareMem->detach();
		}
	}
	if (p_shareMem->create(1))
	{
		objectManager.update();     //判断是否升级
		int nFlag = imchat.exec();

		if (p_shareMem->isAttached())
			p_shareMem->detach();
		delete p_shareMem;
		p_shareMem = NULL;
		return nFlag;
	}
	return 0;
}
