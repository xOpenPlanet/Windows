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
	// Qualifier: �������ݿ�
	// Parameter: QString strDBPath
	// Parameter: QString strDBName
	//************************************
	bool ConnectDB(QString strDBPath, QString strDBName);

	// Qualifier: �ر����ݿ�
	void CloseDB();

	QList<WalletInfo> DBGetWalletInfo();
	
	void DBInsertWalletInfo(WalletInfo);

	AddressInfo DBGetAddressInfo(QString userID);

	void DBInsertAddressInfo(AddressInfo);

private:
	SqlLiteShareLib *mSqlUtil;

};

#endif // OPDATEBASESHARELIB_H
