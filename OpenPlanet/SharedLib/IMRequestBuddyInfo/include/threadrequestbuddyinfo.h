#ifndef THREADREQUESTBUDDYINFO_H
#define THREADREQUESTBUDDYINFO_H

#include <QThread>
#include "alphabeticalsortsharedlib.h"
#include "imbuddy.h"
/*�������,���������߳�*/

class ThreadRequestBuddyInfo : public QThread
{
	Q_OBJECT

public:
	ThreadRequestBuddyInfo(QObject *parent=0);
	~ThreadRequestBuddyInfo();

	//************************************
	// Method:    setUrl
	// FullName:  ThreadRequestBuddyInfo::setUrl
	// Access:    public 
	// Returns:   void
	// Qualifier: ����URL
	// Parameter: QString url
	//************************************
	void setUrl(QString url){ mUrl = url; }

	void setBuddyList(QList<BuddyInfo> listBuddy) { mListBuddy = listBuddy; }

private:
	//************************************
	// Method:    ParseBuddyInfo
	// FullName:  ThreadRequestBuddyInfo::ParseBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ����������Ϣ
	// Parameter: QByteArray byteArray
	//************************************
	void ParseBuddyInfo(QByteArray byteArray);

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
	void sigParseBuddyInfo(BuddyInfo);
protected:
	virtual void run();
private:
	QString mUrl;
	QList<BuddyInfo> mListBuddy;
	AlphabeticalSortSharedLib mAlphabeticalSort;   //���ݺ��ַ�������ĸƴ��
};

#endif // THREADREQUESTBUDDYINFO_H
