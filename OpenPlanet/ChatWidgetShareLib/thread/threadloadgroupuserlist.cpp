#include "threadloadgroupuserlist.h"
#include <QDebug>

ThreadLoadGroupUserList::ThreadLoadGroupUserList(QObject *parent)
: QThread(parent)
{
	singleCount = 40; //Ĭ��ÿ�μ���40����Ա��
}

ThreadLoadGroupUserList::~ThreadLoadGroupUserList()
{
	requestInterruption();
	quit();
	wait();
}

void ThreadLoadGroupUserList::SetListBuddyInfo(QList<BuddyInfo> tempList)
{
	listBuddyInfo = tempList;
}

void ThreadLoadGroupUserList::run()
{
	for (int i = 0; i < singleCount; i++)
	{
		if (listBuddyInfo.isEmpty())
			break;
		else
		{
			if (!isInterruptionRequested())
			{
				msleep(100);
				emit sigLoadGroupUserList(listBuddyInfo.first());
				listBuddyInfo.pop_front();
			}
			else
				break;
		}
	}
}
