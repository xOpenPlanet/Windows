#ifndef THREADREQUESTBUDDYINFO_H
#define THREADREQUESTBUDDYINFO_H

#include <QThread>
#include "alphabeticalsortsharedlib.h"
#include "imbuddy.h"
/*请求好友,解析好友线程*/

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
	// Qualifier: 设置URL
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
	// Qualifier: 解析好友信息
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
	// Qualifier: 解析完成信号
	// Parameter: QList<BuddyInfo>
	//************************************
	void sigParseBuddyInfo(BuddyInfo);
protected:
	virtual void run();
private:
	QString mUrl;
	QList<BuddyInfo> mListBuddy;
	AlphabeticalSortSharedLib mAlphabeticalSort;   //根据汉字返回首字母拼音
};

#endif // THREADREQUESTBUDDYINFO_H
