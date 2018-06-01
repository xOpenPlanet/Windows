#ifndef LOGINDATABASEOPERASHARELIB_H
#define LOGINDATABASEOPERASHARELIB_H

/*��½����������ݿ�*/

#include <QtCore/QString>
#include "sqllitesharelib.h"
#include "common.h"

class LoginDatabaseOperaShareLib
{
public:
	LoginDatabaseOperaShareLib();
	~LoginDatabaseOperaShareLib();

	//************************************
	// Method:    ConnectLoginDB
	// FullName:  LoginDatabaseOperaShareLib::ConnectLoginDB
	// Access:    public 
	// Returns:   bool
	// Qualifier: �������ݿ�
	// Parameter: QString strDBPath
	// Parameter: QString strDBName
	//************************************
	bool ConnectLoginDB(QString strDBPath, QString strDBName);

	// Qualifier: �ر����ݿ�
	void CloseDB();

	//************************************
	// Method:    InsertUserInfoDB
	// FullName:  LoginDatabaseOperaShareLib::InsertUserInfoDB
	// Access:    public 
	// Returns:   void
	// Qualifier: �����û���Ϣ���ݿ�
	// Parameter: QString strPwd
	// Parameter: bool bIsSavePwd
	// Parameter: bool bIsAutoLogin
	//************************************
	void InsertUserInfoDB(UserInfo userInfo);

	//************************************
	// Method:    GetDBAllUserInfoDB
	// FullName:  LoginDatabaseOperaShareLib::GetDBAllUserInfoDB
	// Access:    public 
	// Returns:   QList<UserInfo>
	// Qualifier: ��ȡ���ݿ��������û���Ϣ�б�
	//************************************
	QList<UserInfo> GetDBAllUserInfoDB();

	//************************************
	// Method:    DeleteUserInfoAtDB
	// FullName:  LoginDatabaseOperaShareLib::DeleteUserInfoAtDB
	// Access:    public 
	// Returns:   void
	// Qualifier: ɾ�����ݿ��е��û���Ϣ
	// Parameter: QString strUserID
	//************************************
	void DeleteUserInfoAtDB(QString strUserID);

	//************************************
	// Method:    InsertProxyInfoDB
	// FullName:  LoginDatabaseOperaShareLib::InsertProxyInfoDB
	// Access:    public 
	// Returns:   void
	// Qualifier: ���������Ϣ
	// Parameter: NetWorkProxyInfo networkModel
	//************************************
	void InsertProxyInfoDB(NetWorkProxyInfo networkModel);

	//************************************
	// Method:    UpdateProxyInfoDB
	// FullName:  LoginDatabaseOperaShareLib::UpdateProxyInfoDB
	// Access:    public 
	// Returns:   void
	// Qualifier: ���´�����Ϣ
	//************************************
	void DeleteProxyInfoDB();

	//************************************
	// Method:    GetNetWorkProxyInfoDB
	// FullName:  LoginDatabaseOperaShareLib::GetNetWorkProxyInfoDB
	// Access:    public 
	// Returns:   NetWorkProxyInfo
	// Qualifier: ��ȡ���ݿ��еĴ�����Ϣ
	//************************************
	NetWorkProxyInfo GetNetWorkProxyInfoDB();
private:
	SqlLiteShareLib *mSqlUtil;
};

#endif // LOGINDATABASEOPERASHARELIB_H
