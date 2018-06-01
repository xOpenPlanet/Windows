#ifndef OPDATEBASESHARELIB_H
#define OPDATEBASESHARELIB_H

#include <QList>
#include <QString>
#include "sqllitesharelib.h"
#include "opcommon.h"

class OPDatebaseShareLib
{
public:
	OPDatebaseShareLib();
	~OPDatebaseShareLib();

	//************************************
	// Method:    ConnectLoginDB
	// FullName:  LoginDatabaseOperaShareLib::ConnectLoginDB
	// Access:    public 
	// Returns:   bool
	// Qualifier: 连接数据库
	// Parameter: QString strDBPath
	// Parameter: QString strDBName
	//************************************
	bool ConnectDB(QString strDBPath, QString strDBName);

	// Qualifier: 关闭数据库
	void CloseDB();

	QList<WalletInfo> DBGetWalletInfo();
	
	void DBInsertWalletInfo(WalletInfo);

	AddressInfo DBGetAddressInfo(QString userID);

	void DBInsertAddressInfo(AddressInfo);

private:
	SqlLiteShareLib *mSqlUtil;

};

#endif // OPDATEBASESHARELIB_H
