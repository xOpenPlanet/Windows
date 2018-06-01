#ifndef EWALLETMANAGER_H
#define EWALLETMANAGER_H

#include <QObject>
#include "ewalletwidget.h"
#include "starflashwidget.h"
#include "changeintoWidget/changeintowidget.h"
#include "invitecodeWidget/invitecodewidget.h"
#include "transferWidget/transferwidget.h"
#include "transferWidget/transfermanager.h"
#include "opcommon.h"
#include "Common.h"
#include "oprequestsharelib.h"
#include "opdatamanager.h"

class EWalletManager : public QObject
{
	Q_OBJECT

public:
	EWalletManager(QObject *parent);
	~EWalletManager();

	EWalletWidget *getWalletWidget();

	void setUserInfo(UserInfo);
	void setWalletInfo(WalletInfo);

	void addBuddysNum(int);
	void addGroupsNum(int);

private slots:
    void slotRefresh();
    void slotSetIntegral(QString);
    void slotSetBalance(QString);

    void slotTransfer(QString otherID, QString toAddress, QString value);

private:
	QString stringToThousandth(QString string, int keep = 0);

private:
	UserInfo userInfo;
	WalletInfo walletInfo;

	EWalletWidget *walletWidget;
	StarFlashWidget *starWidget;

	InviteCodeWidget *inviteWidget;
	ChangeIntoWidget *intoWidget;
	TransferWidget *transWidget;
	SafeWidget *safeWidget;

	TransferManager *trans;
};

#endif // EWALLETMANAGER_H
