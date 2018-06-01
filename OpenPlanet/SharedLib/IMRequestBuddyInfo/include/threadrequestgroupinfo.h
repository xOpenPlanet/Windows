#ifndef THREADREQUESTGROUPINFO_H
#define THREADREQUESTGROUPINFO_H

#include <QThread>
#include "imbuddy.h"

class ThreadRequestGroupInfo : public QThread
{
	Q_OBJECT

public:
	ThreadRequestGroupInfo(QObject *parent = 0);
	~ThreadRequestGroupInfo();

	//************************************
	// Method:    setUrl
	// FullName:  ThreadRequestBuddyInfo::setUrl
	// Access:    public 
	// Returns:   void
	// Qualifier: ����URL
	// Parameter: QString url
	//************************************
	void setUrl(QString url){ mUrl = url; }

	//************************************
	// Method:    setGroupInfoList
	// FullName:  ThreadRequestGroupInfo::setGroupInfoList
	// Access:    public 
	// Returns:   void
	// Qualifier: ����GroupInfo
	// Parameter: QList<GroupInfo> listGroupInfo
	//************************************
	void setGroupInfoList(QList<GroupInfo> listGroupInfo) { mListGroupInfo = listGroupInfo; }
private:
	//************************************
	// Method:    ParseGroupInfo
	// FullName:  ThreadRequestBuddyInfo::ParseGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ����Ⱥ����Ϣ
	// Parameter: QByteArray byteArray
	//************************************
	void ParseGroupInfo(QByteArray byteArray);

	QString GetExeDir();
signals:
	//************************************
	// Method:    sigParseGroupInfo
	// FullName:  ThreadRequestBuddyInfo::sigParseGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ��������ź�
	// Parameter: GroupInfo
	//************************************
	void sigParseGroupInfo(GroupInfo);
protected:
	virtual void run();

private:
	QString mUrl;
	QList<GroupInfo> mListGroupInfo;
};

#endif // THREADREQUESTGROUPINFO_H
