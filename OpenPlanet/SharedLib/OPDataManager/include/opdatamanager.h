#ifndef OPDATAMANAGER_H
#define OPDATAMANAGER_H

#include <QObject>
#include <QFile>
#include "TAesClass.h"
#include "opcommon.h"

class OPDataManager
{
public:
	OPDataManager();
	~OPDataManager();

	void setWalletInfo(WalletInfo wallet) { mWallet = wallet; }

	WalletInfo getWalletInfo(){ return mWallet; }

	void setAccessToken(QString accessToken){ mAccesstoken = accessToken; }

	QString getAccessToken(){ return mAccesstoken; }

	void setRefreshToken(QString refreshToken){ mRefreshtoken = refreshToken; }

	QString getRefreshToken(){ return mRefreshtoken; }

	//加密方法。
	void encryption(QString text, QString key, QString path = "key");
	//解密方法。
	QString Decryption(QString key, QString path = "key");
private:
	WalletInfo mWallet;
	QString mAccesstoken;
	QString mRefreshtoken;
};

#endif // OPDATAMANAGER_H
