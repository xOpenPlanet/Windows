#ifndef IMREQUESTBUDDYINFO_H
#define IMREQUESTBUDDYINFO_H

/*请求好友信息*/
#include <QObject>
#include "imbuddy.h"
#include "common.h"
#include "alphabeticalsortsharedlib.h"

class IMRequestBuddyInfo : public QObject
{
	Q_OBJECT
public:
	IMRequestBuddyInfo(QObject *parent = NULL);
	~IMRequestBuddyInfo();

	//************************************
	// Method:    RequestBuddyInfo
	// FullName:  IMRequestBuddyInfo::RequestBuddyInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 请求好友信息
	//************************************
	void RequestBuddyInfo(QString strUrl, QString strIMUserID, QString strPwd,QString appID);

	void RequestBuddyInfo(QList<BuddyInfo>);

	//************************************
	// Method:    RequestGroupInfo
	// FullName:  IMRequestBuddyInfo::RequestGroupInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 请求群组信息
	//************************************
	void RequestGroupInfo(QString strUrl, QString strIMUserID, QString strPwd, QString appID);
	void RequestGroupInfo(QList<GroupInfo>);

	//************************************
	// Method:    RequestGroupBuddyInfo
	// FullName:  IMRequestBuddyInfo::RequestGroupBuddyInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 请求好友群组成员信息
	//************************************
	void RequestGroupBuddyInfo(QString strUrl, QString strIMUserID, QString strPwd, QString groupID);

	//************************************
	// Method:    RequestPersonInfo
	// FullName:  IMRequestBuddyInfo::RequestPersonInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 请求个人信息
	//************************************
	void RequestPersonInfo(QString strUrl, QString strUserID);

private slots:
	//************************************
	// Method:    slotRequestPersonInfoFinished
	// FullName:  IMRequestBuddyInfo::slotRequestPersonInfoFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: 请求个人信息结束
	// Parameter: bool bResult
	// Parameter: QString strResult
	//************************************
	void slotRequestPersonInfoFinished(bool bResult, QString strResult);
signals:
	//************************************
	// Method:    sigParseBuddyInfo
	// FullName:  IMRequestBuddyInfo::sigParseBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 解析完一个好友信息发信号
	// Parameter: BuddyInfo
	//************************************
	void sigParseBuddyInfo(BuddyInfo);

	//************************************
	// Method:    sigParseGroupInfo
	// FullName:  IMRequestBuddyInfo::sigParseGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 解析完一个群组信息发信号
	// Parameter: GroupInfo
	//************************************
	void sigParseGroupInfo(GroupInfo);

	//************************************
	// Method:    sigParseGroupBuddyInfo
	// FullName:  IMRequestBuddyInfo::sigParseGroupBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 解析群组成员信号
	// Parameter: QString strGroupID
	// Parameter: BuddyInfo buddyInfo
	//************************************
	void sigParseGroupBuddyInfo(QString strGroupID,QList<BuddyInfo> listbuddyInfo);

	//************************************
	// Method:    sigRequestPersonInfoSuccess
	// FullName:  IMRequestBuddyInfo::sigRequestPersonInfoSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: 请求个人信息成功
	// Parameter: UserInfo
	//************************************
	void sigRequestPersonInfoSuccess(bool,UserInfo);

	void sigInsertGroupBuddyInfo(QString,BuddyInfo);
private:
	//************************************
	// Method:    SwitchRequestBuddyInfo
	// FullName:  IMRequestBuddyInfo::SwitchRequestBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 拼接请求好友URL
	// Parameter: QString url
	// Parameter: QString AccountName
	// Parameter: QString PassWord
	//************************************
	QString SwitchRequestBuddyInfo(QString url, QString AccountName, QString PassWord, QString appID);

	//************************************
	// Method:    StitchGroupBuddyParameter
	// FullName:  IMRequestBuddyInfo::StitchGroupBuddyParameter
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: 拼接请求群组成员URL
	// Parameter: QString url
	// Parameter: QString AccountName
	// Parameter: QString PassWord
	// Parameter: QString strGroupID
	//************************************
	QString StitchGroupBuddyParameter(QString url, QString AccountName, QString PassWord, QString strGroupID);

	//************************************
	// Method:    GetExeDir
	// FullName:  IMRequestBuddyInfo::GetExeDir
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: 返回程序当前运行路径
	//************************************
	QString GetExeDir();
private:
	AlphabeticalSortSharedLib mAlphabeticalSort;   //根据汉字返回首字母拼音
};

#endif // IMREQUESTBUDDYINFO_H
