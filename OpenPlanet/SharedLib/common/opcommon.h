#ifndef OPCOMMON_H
#define OPCOMMON_H

#include "QtCore/QString"
#include <QObject>

struct WalletInfo
{
	QString address;
	QString privkey;
	QString pubkey;
	QString fromInviteCode;  //谁邀请的邀请码
	QString inviteCode;      //邀请码
	QString inviteCodeUseCount; //邀请码用户账户
	QString userIdMd5;     //用户ID MD5
	QString planet;            //星球
};

struct AddressInfo
{
    QString userID;
    QString ethAddress;
    QString comPublicKey;
    QString ethPublicKey;
};

#endif // OPCOMMON_H