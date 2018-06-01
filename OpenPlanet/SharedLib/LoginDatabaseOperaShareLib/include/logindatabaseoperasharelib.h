#ifndef LOGINDATABASEOPERASHARELIB_H
#define LOGINDATABASEOPERASHARELIB_H

/*登陆界面操作数据库*/

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
	// Qualifier: 连接数据库
	// Parameter: QString strDBPath
	// Parameter: QString strDBName
	//************************************
	bool ConnectLoginDB(QString strDBPath, QString strDBName);

	// Qualifier: 关闭数据库
	void CloseDB();

	//************************************
	// Method:    InsertUserInfoDB
	// FullName:  LoginDatabaseOperaShareLib::InsertUserInfoDB
	// Access:    public 
	// Returns:   void
	// Qualifier: 插入用户信息数据库
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
	// Qualifier: 获取数据库中所有用户信息列表
	//************************************
	QList<UserInfo> GetDBAllUserInfoDB();

	//************************************
	// Method:    DeleteUserInfoAtDB
	// FullName:  LoginDatabaseOperaShareLib::DeleteUserInfoAtDB
	// Access:    public 
	// Returns:   void
	// Qualifier: 删除数据库中的用户信息
	// Parameter: QString strUserID
	//************************************
	void DeleteUserInfoAtDB(QString strUserID);

	//************************************
	// Method:    InsertProxyInfoDB
	// FullName:  LoginDatabaseOperaShareLib::InsertProxyInfoDB
	// Access:    public 
	// Returns:   void
	// Qualifier: 插入代理信息
	// Parameter: NetWorkProxyInfo networkModel
	//************************************
	void InsertProxyInfoDB(NetWorkProxyInfo networkModel);

	//************************************
	// Method:    UpdateProxyInfoDB
	// FullName:  LoginDatabaseOperaShareLib::UpdateProxyInfoDB
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新代理信息
	//************************************
	void DeleteProxyInfoDB();

	//************************************
	// Method:    GetNetWorkProxyInfoDB
	// FullName:  LoginDatabaseOperaShareLib::GetNetWorkProxyInfoDB
	// Access:    public 
	// Returns:   NetWorkProxyInfo
	// Qualifier: 获取数据库中的代理信息
	//************************************
	NetWorkProxyInfo GetNetWorkProxyInfoDB();
private:
	SqlLiteShareLib *mSqlUtil;
};

#endif // LOGINDATABASEOPERASHARELIB_H
