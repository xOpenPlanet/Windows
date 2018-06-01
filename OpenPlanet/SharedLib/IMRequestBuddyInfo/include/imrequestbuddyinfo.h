#ifndef IMREQUESTBUDDYINFO_H
#define IMREQUESTBUDDYINFO_H

/*���������Ϣ*/
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
	// Qualifier: ���������Ϣ
	//************************************
	void RequestBuddyInfo(QString strUrl, QString strIMUserID, QString strPwd,QString appID);

	void RequestBuddyInfo(QList<BuddyInfo>);

	//************************************
	// Method:    RequestGroupInfo
	// FullName:  IMRequestBuddyInfo::RequestGroupInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ����Ⱥ����Ϣ
	//************************************
	void RequestGroupInfo(QString strUrl, QString strIMUserID, QString strPwd, QString appID);
	void RequestGroupInfo(QList<GroupInfo>);

	//************************************
	// Method:    RequestGroupBuddyInfo
	// FullName:  IMRequestBuddyInfo::RequestGroupBuddyInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: �������Ⱥ���Ա��Ϣ
	//************************************
	void RequestGroupBuddyInfo(QString strUrl, QString strIMUserID, QString strPwd, QString groupID);

	//************************************
	// Method:    RequestPersonInfo
	// FullName:  IMRequestBuddyInfo::RequestPersonInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ���������Ϣ
	//************************************
	void RequestPersonInfo(QString strUrl, QString strUserID);

private slots:
	//************************************
	// Method:    slotRequestPersonInfoFinished
	// FullName:  IMRequestBuddyInfo::slotRequestPersonInfoFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: ���������Ϣ����
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
	// Qualifier: ������һ��������Ϣ���ź�
	// Parameter: BuddyInfo
	//************************************
	void sigParseBuddyInfo(BuddyInfo);

	//************************************
	// Method:    sigParseGroupInfo
	// FullName:  IMRequestBuddyInfo::sigParseGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ������һ��Ⱥ����Ϣ���ź�
	// Parameter: GroupInfo
	//************************************
	void sigParseGroupInfo(GroupInfo);

	//************************************
	// Method:    sigParseGroupBuddyInfo
	// FullName:  IMRequestBuddyInfo::sigParseGroupBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: ����Ⱥ���Ա�ź�
	// Parameter: QString strGroupID
	// Parameter: BuddyInfo buddyInfo
	//************************************
	void sigParseGroupBuddyInfo(QString strGroupID,QList<BuddyInfo> listbuddyInfo);

	//************************************
	// Method:    sigRequestPersonInfoSuccess
	// FullName:  IMRequestBuddyInfo::sigRequestPersonInfoSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: ���������Ϣ�ɹ�
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
	// Qualifier: ƴ���������URL
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
	// Qualifier: ƴ������Ⱥ���ԱURL
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
	// Qualifier: ���س���ǰ����·��
	//************************************
	QString GetExeDir();
private:
	AlphabeticalSortSharedLib mAlphabeticalSort;   //���ݺ��ַ�������ĸƴ��
};

#endif // IMREQUESTBUDDYINFO_H
