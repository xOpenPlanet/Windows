#ifndef THREADREQUESTGROUPBUDDYINFO_H
#define THREADREQUESTGROUPBUDDYINFO_H

#include <QThread>
#include "imbuddy.h"
/*����Ⱥ���Ա��Ϣ*/

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
	// Qualifier: ����URL
	// Parameter: QString url
	//************************************
	void setUrl(QString url){ mUrl = url; }

private:
	//************************************
	// Method:    ParseGroupBuddyInfo
	// FullName:  ThreadRequestGroupBuddyInfo::ParseGroupBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ����Ⱥ�������Ϣ
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
	// Qualifier: ��������ź�
	// Parameter: QList<BuddyInfo>
	//************************************
	void sigParseGroupBuddyInfo(QString,QList<BuddyInfo>);
protected:
	virtual void run();
private:
	QString mUrl;
};

#endif // THREADREQUESTGROUPBUDDYINFO_H
