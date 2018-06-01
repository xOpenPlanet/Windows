#ifndef THREADREFRESHGROUPUSERLIST_H
#define THREADREFRESHGROUPUSERLIST_H

#include <QMetaType>
#include <QThread>
#include "IMRequestBuddyInfo.h"
#include "stdafx.h"

class ThreadRefreshGroupUserList : public QThread
{
	Q_OBJECT

public:
	ThreadRefreshGroupUserList(QObject *parent);
	~ThreadRefreshGroupUserList();

	void setGroupMemberInfo(QString groupID, QString result);

protected:
	virtual void run() Q_DECL_OVERRIDE;

signals:
	void sigRefreshGroupUserList();
	void sigParseGroupBuddyInfo(QString, QList<BuddyInfo>);
private:
	QString strGroupID;
	QString strResult;
	IMRequestBuddyInfo *request;
};

#endif // THREADREFRESHGROUPUSERLIST_H
