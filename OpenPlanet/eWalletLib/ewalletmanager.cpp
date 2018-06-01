#include "ewalletmanager.h"

extern OPDataManager  *gOPDataManager;

EWalletManager::EWalletManager(QObject *parent)
	: QObject(parent)
{
	walletWidget = new EWalletWidget;
	
	intoWidget = walletWidget->getIntoWidget();
	inviteWidget = walletWidget->getInviteWidget();
	safeWidget = walletWidget->getSafeWidget();

	starWidget = walletWidget->getStarWidget();
	connect(starWidget, SIGNAL(sigRefreshWallet()), this, SLOT(slotRefresh()));

	transWidget = walletWidget->getTransWidget();
	connect(transWidget, SIGNAL(sigTransfer(QString, QString, QString)),
		this, SLOT(slotTransfer(QString, QString, QString)));

	trans = new TransferManager;
	connect(trans, SIGNAL(sigFinished()), this, SLOT(slotRefresh()));
	connect(trans, SIGNAL(sigFinished()), transWidget, SLOT(slotClearText()));
}

EWalletManager::~EWalletManager()
{

}

EWalletWidget * EWalletManager::getWalletWidget()
{
	return walletWidget;
}

void EWalletManager::addBuddysNum(int num)
{
	starWidget->addBuddysNum(num);
}

void EWalletManager::addGroupsNum(int num)
{
	starWidget->addGroupsNum(num);
}

void EWalletManager::setUserInfo(UserInfo info)
{
	this->userInfo = info;

	starWidget->setAccount(userInfo.strUserNickName);
	starWidget->setId(QString::number(userInfo.nUserID));
	safeWidget->setPassWord(userInfo.strLoginPWD);
	transWidget->setPassWord(userInfo.strLoginPWD);

	safeWidget->setPrivateKey(gOPDataManager->Decryption(userInfo.strLoginPWD));
	trans->setPrivateKey(gOPDataManager->Decryption(userInfo.strLoginPWD));
}

void EWalletManager::setWalletInfo(WalletInfo info)
{
	this->walletInfo = info;

	starWidget->setAddress(walletInfo.address);
	starWidget->setStar(walletInfo.planet);
	transWidget->setAddress(walletInfo.address);
	inviteWidget->setInviteCode(walletInfo.inviteCode);
	intoWidget->setTurnInData(QString::number(userInfo.nUserID), walletInfo.address);

	slotRefresh();
}

void EWalletManager::slotRefresh()
{
	//获取银钻。
	OPRequestShareLib *requestSilver = new OPRequestShareLib;
	connect(requestSilver, SIGNAL(sigIntegral(QString)), this, SLOT(slotSetIntegral(QString)));
	requestSilver->getIntegral(gOPDataManager->getAccessToken());

	//获取能量。
	OPRequestShareLib *request = new OPRequestShareLib;
	connect(request, SIGNAL(sigBalance(QString)), this, SLOT(slotSetBalance(QString)));
	request->getBalance(walletInfo.address);
}


void EWalletManager::slotSetIntegral(QString integral)
{
	integral = stringToThousandth(integral);
	walletWidget->setIntegral(integral);

	starWidget->stopRefreshGif();
}

void EWalletManager::slotSetBalance(QString balance)
{
	balance = stringToThousandth(balance, 8);
	walletWidget->setEnergySum(balance);
	transWidget->setEnergySum(balance);

	starWidget->stopRefreshGif();
}

QString EWalletManager::stringToThousandth(QString string, int keep /*= 0*/)
{
	//根据保留的位数，进行补0。
	if (keep > 0)  //需要补0操作。
	{
		int count = 0;
		if (string.contains("."))   //含小数点，只补缺少的0。
			count = keep - string.split(".").last().length();
		else                        //不含小数点，直接补固定数量的0。
		{
			string += ".";
			count = keep;
		}
		//补0操作。
		for (int i = 0; i < count; i++)
			string += "0";
	}

	//进行千分位操作，先获取整数部分。
	QString number = string.split(".").first();   //整数部分。
	QString result;  //保存结果的字符串。
	int num = 0;
	for (int i = number.count(); i > 0; i--)
	{
		result = number.at(i - 1) + result;
		num++;
		if (num == 3 && i != 1)
		{
			result = "," + result;
			num = 0;
		}
	}

	if (keep > 0)
	    result += "." + string.split(".").last();

	return result;
}

void EWalletManager::slotTransfer(QString otherID, QString toAddress, QString value)
{
	trans->turnOut(QString::number(userInfo.nUserID), otherID,
		walletInfo.address, toAddress, value);
}



