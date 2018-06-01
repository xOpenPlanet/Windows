#include "opdatebasesharelib.h"

OPDatebaseShareLib::OPDatebaseShareLib()
{
	mSqlUtil = NULL;
}

OPDatebaseShareLib::~OPDatebaseShareLib()
{
	CloseDB();
}

//连接登陆数据库
bool OPDatebaseShareLib::ConnectDB(QString strDBPath, QString strDBName)
{
	if (mSqlUtil == NULL) mSqlUtil = new SqlLiteShareLib();
	if (mSqlUtil->CreateDataFile(strDBPath))
	{
		if (mSqlUtil->OnConnectDB(strDBPath, strDBName))
		{
			if (!mSqlUtil->isExistTable("EWALLET"))
			{
				QString strsql1 = "CREATE TABLE EWALLET (address varchar(100), privkey varchar(100), pubkey varchar(100))";
				mSqlUtil->ExecuSql(strsql1);
			}
			if (!mSqlUtil->isExistTable("ADDRESSLIST"))
			{
				QString strsql2 = "CREATE TABLE ADDRESSLIST (userID int, comPublicKey varchar(300), ethAddress varchar(100), ethPublicKey varchar(200))";
				mSqlUtil->ExecuSql(strsql2);
			}
			return true;
		}
		return false;
	}
	return false;
}

//关闭数据库
void OPDatebaseShareLib::CloseDB()
{
	if (mSqlUtil)
		mSqlUtil->CloseDataBase();
	delete mSqlUtil;
}

QList<WalletInfo> OPDatebaseShareLib::DBGetWalletInfo()
{
	QList<WalletInfo> walletList;

	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QString strSql = "select * from EWALLET";
		QSqlQuery resultQuery = mSqlUtil->ExecuQuery(strSql);

		while (resultQuery.next())
		{
			WalletInfo wallet;
			wallet.address = resultQuery.value("address").toString();
			wallet.privkey = resultQuery.value("privkey").toString();
			wallet.pubkey = resultQuery.value("pubkey").toString();

			walletList.append(wallet);
		}
	}

	return walletList;
}

void OPDatebaseShareLib::DBInsertWalletInfo(WalletInfo info)
{
	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QString strSql = QString("insert into EWALLET(address,privkey,pubkey) values('%1','%2','%3')")
			.arg(info.address).arg(info.privkey).arg(info.pubkey);

		mSqlUtil->ExecuSql(strSql);
	}
}

AddressInfo OPDatebaseShareLib::DBGetAddressInfo(QString userID)
{
	AddressInfo info;

	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QString strSql = "select * from ADDRESSLIST where userID=" + userID;
		QSqlQuery resultQuery = mSqlUtil->ExecuQuery(strSql);

		while (resultQuery.next())
		{
			info.userID = userID;
			info.comPublicKey = resultQuery.value("comPublicKey").toString();
			info.ethAddress = resultQuery.value("ethAddress").toString();
			info.ethPublicKey = resultQuery.value("ethPublicKey").toString();
		}
	}

	return info;
}

void OPDatebaseShareLib::DBInsertAddressInfo(AddressInfo info)
{
	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QString strSql = "delete from ADDRESSLIST where userID=" + info.userID;
		mSqlUtil->ExecuSql(strSql);
		strSql = QString("insert into ADDRESSLIST(userID,comPublicKey,ethAddress,ethPublicKey) values(%1,'%2','%3','%4')")
			.arg(info.userID).arg(info.comPublicKey).arg(info.ethAddress).arg(info.ethPublicKey);

		mSqlUtil->ExecuSql(strSql);
	}
}
