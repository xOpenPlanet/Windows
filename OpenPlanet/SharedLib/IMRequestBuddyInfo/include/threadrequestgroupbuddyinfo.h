#ifndef THREADREQUESTGROUPBUDDYINFO_H
#define THREADREQUESTGROUPBUDDYINFO_H

#include <QThread>
#include "imbuddy.h"
/*解析群组成员信息*/

class ThreadRequestGroupBuddyInfo : public QThread
{
	Q_OBJECT

public:
	ThreadRequestGroupBuddyInfo(QObject *parent = 0);
	~ThreadRequestGroupBuddyInfo();

	//************************************
	// Method:    setUrl
	// FullName:  ThreadRequestBuddyInfo::setUrl
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置URL
	// Parameter: QString url
	//************************************
	void setUrl(QString url){ mUrl = url; }

private:
	//************************************
	// Method:    ParseGroupBuddyInfo
	// FullName:  ThreadRequestGroupBuddyInfo::ParseGroupBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 解析群组好友信息
	// Parameter: QByteArray byteArray
	//************************************
	void ParseGroupBuddyInfo(QByteArray byteArray);

	QString GetExeDir();

signals:
	//************************************
	// Method:    sigParseBuddyFinish
	// FullName:  ThreadRequestBuddyInfo::sigParseBuddyFinish
	// Access:    private 
	// Returns:   void
	// Qualifier: 解析完成信号
	// Parameter: QList<BuddyInfo>
	//************************************
	void sigParseGroupBuddyInfo(QString,QList<BuddyInfo>);
protected:
	virtual void run();
private:
	QString mUrl;
};

#endif // THREADREQUESTGROUPBUDDYINFO_H
