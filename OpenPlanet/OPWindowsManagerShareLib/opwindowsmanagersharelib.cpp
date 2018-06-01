#include "opwindowsmanagersharelib.h"

OPDatebaseShareLib *gOPDataBaseOpera = NULL;

extern OPDataManager *gOPDataManager;

OPWindowsManagerShareLib::OPWindowsManagerShareLib(QObject *parent) : QObject(parent)
{
	mMainManager = NULL;
	recoveryWidget = NULL;
	cefView = NULL;
	//mLoginWidget = NULL;
}

OPWindowsManagerShareLib::~OPWindowsManagerShareLib()
{
	if (mMainManager)
	{
		mMainManager->deleteLater();
		mMainManager = NULL;
	}
}

// Qualifier: 启动登陆界面
void OPWindowsManagerShareLib::StartLoginWidget(QString strYWYHRequestURL, QString appID)
{
	m_pScanQR = new ScanQRLoginShareLib(this);
	connect(m_pScanQR, SIGNAL(sigCloseLoginWidget()), this, SLOT(slotCloseApp()));
	connect(m_pScanQR, SIGNAL(sigQRLoginSuccess(QVariantMap)), this, SIGNAL(sigLoginSuccess(QVariantMap)));
}

void OPWindowsManagerShareLib::slotCloseApp()
{
	if (m_pScanQR)
	{
		m_pScanQR->deleteLater();
		m_pScanQR = NULL;
	}
	emit sigExit();
}

void OPWindowsManagerShareLib::ChangeLoginWidget(QString msg)
{
	if (m_pScanQR)
	{
		m_pScanQR->showErro(msg);
	}
}

// Qualifier: 销毁登陆窗口
void OPWindowsManagerShareLib::DestroyLoginWidget()
{
	if (m_pScanQR)
	{
		m_pScanQR->deleteLater();
		m_pScanQR = NULL;
	}
}

//启动主界面
void OPWindowsManagerShareLib::StartIMMainWidget(UserInfo userInfo)
{
	if (mMainManager == NULL)
	{
		mMainManager = new OPMainManagerShareLib(this);
		connect(this, SIGNAL(sigUpdateMessageState(MessageInfo, int)), mMainManager, SIGNAL(sigUpdateMessageState(MessageInfo, int)));
		connect(this, SIGNAL(sigSetMainWidgetStatusLabel(QString)), mMainManager, SIGNAL(sigSetMainWidgetStatusLabel(QString)));
		connect(this, SIGNAL(sigUpdateUserInfo(UserInfo)), mMainManager, SLOT(slotInitMainWidget(UserInfo)));
		connect(this, SIGNAL(sigUpdateInfo(int, QVariant)), mMainManager, SLOT(slotUpdateInfo(int, QVariant)));
		connect(this, SIGNAL(sigUserQuitGroup(QString, QString)), mMainManager, SLOT(slotUserQuitGroup(QString, QString)));
		connect(this, SIGNAL(sigAddFriendSuccess(BuddyInfo)), mMainManager, SLOT(slotAddFriendSuccess(BuddyInfo)));
		connect(this, SIGNAL(sigAddSuccessGroup(GroupInfo)), mMainManager, SLOT(slotAddSuccessGroup(GroupInfo)));
		connect(this, SIGNAL(sigAddSuccessGroupUserInfo(QString, BuddyInfo)), mMainManager, SLOT(slotAddSuccessGroupUserInfo(QString, BuddyInfo)));
		connect(this, SIGNAL(sigDeleteGroup(QString)), mMainManager, SLOT(slotDeleteGroup(QString)));
		connect(this, SIGNAL(sigDeleteFriend(int, QVariant)), mMainManager, SLOT(slotDeleteBuddy(int, QVariant)));
		connect(this, SIGNAL(sigRevOtherDeviceMsg(MessageInfo)), mMainManager, SIGNAL(sigRevOtherDeviceMsg(MessageInfo)));
		connect(mMainManager, SIGNAL(sigExit()), this, SIGNAL(sigExit()));
	}
	mMainManager->startMainWidget(userInfo);
}

//销毁主界面
void OPWindowsManagerShareLib::DestroyIMMainWidget()
{
	if (mMainManager)
	{
		mMainManager->deleteLater();
		mMainManager = NULL;
	}
}

//联系人界面插入好友信息
void OPWindowsManagerShareLib::slotInsertBuddyInfo(BuddyInfo buddyInfo)
{
	if (gDataBaseOpera)
	{
		gDataBaseOpera->DBInsertBuddyInfo(buddyInfo);
	}
	if (mMainManager)
	{
		mMainManager->slotBuddysManager(BuddyInsert, QVariant::fromValue(buddyInfo));
	}
}

//插入群组信息
void OPWindowsManagerShareLib::slotInsertGroupInfo(GroupInfo groupInfo)
{
	if (gDataBaseOpera)
	{
		gDataBaseOpera->DBInsertGroupInfo(groupInfo);
	}
	if (mMainManager)
	{
		mMainManager->slotGroupsManager(GroupInsert, QVariant::fromValue(groupInfo));
	}
}

//接收到服务器消息
void OPWindowsManagerShareLib::RevServerMessageInfo(MessageInfo msgInfo)
{
	if (mMainManager)
	{
		mMainManager->RevServerMessage(msgInfo);
	}
}

void OPWindowsManagerShareLib::ReadWalletAddress()
{
	if (gOPDataBaseOpera == NULL)
		gOPDataBaseOpera = new OPDatebaseShareLib;

	UserInfo user = gDataManager->getUserInfo();

	QString strDBPath = "database//" + QString::number(user.nUserID) + "//ewallet.db";
	if (gOPDataBaseOpera->ConnectDB(strDBPath, "ewallet"))
	{
		QList<WalletInfo> list = gOPDataBaseOpera->DBGetWalletInfo();

		if (!list.isEmpty())  //本地存储的基地地址不为空，判断基地与钱包是否符合。
		{
			WalletInfo localWallet = list.first();   //数据库中只有一条记录。
			WalletInfo netWallet = gOPDataManager->getWalletInfo();
			netWallet.address = netWallet.address.toLower();
			localWallet.address = localWallet.address.toLower();
			if (!netWallet.address.startsWith("0x"))
				netWallet.address = "0x" + netWallet.address;

			if (localWallet.address == netWallet.address)
			{
				//合法，启动主界面.
				StartIMMainWidget(gDataManager->getUserInfo());
				mMainManager->setWalletInfo(netWallet);
				emit sigInitBuddyGroup();

				return;
			}
			else
			{
				IMessageBox::tip(recoveryWidget, QStringLiteral("登录失败"), QStringLiteral("基地地址与钱包不匹配！"));
			}
		}

		//如果不符或者本地记录为空，显示恢复钱包的界面。
		if (cefView == NULL)
		{
			cefView = new QCefView;
			cefView->hide();
			connect(cefView, SIGNAL(sigRecoveryResult(QString)), this, SLOT(slotRecoveryResult(QString)));
			cefView->InitCefUrl("file:///./html/wallet.html");
		}

		if (recoveryWidget == NULL)
		{
			recoveryWidget = new RecoveryWidget;
			connect(recoveryWidget, SIGNAL(sigClose()), this, SIGNAL(sigExit()));
			connect(recoveryWidget, SIGNAL(sigRecoveryWord(QString)), this, SLOT(slotRecoveryWallet(QString)));
			connect(recoveryWidget, SIGNAL(sigPrivateKey(QString)), this, SLOT(slotRecoveryWallet(QString)));
		}
		recoveryWidget->show();	
	}
}

void OPWindowsManagerShareLib::slotRecoveryWallet(QString string)
{
	if (cefView)
	{
		if (string.contains(" "))    //用空格隔开的是助记词。
		    cefView->ExecuteJavaScript(QString("recoveryFromWord(\"%1\")").arg(string));
		else
			cefView->ExecuteJavaScript(QString("recoveryFromKey(\"%1\")").arg(string));
	}
}

void OPWindowsManagerShareLib::slotRecoveryResult(QString json)
{	
	QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());
	QVariantMap map = doc.toVariant().toMap();
	QString result = map.value("result").toString();
	if (result == "true")
	{
		QString address = map.value("address").toString().toLower();
		QString priKey = map.value("privkey").toString();
		priKey = priKey.startsWith("0x") ? priKey : "0x" + priKey;

		WalletInfo wallet;
		wallet.address = address;

		WalletInfo netWallet = gOPDataManager->getWalletInfo();
		netWallet.address = netWallet.address.toLower();
		if (!netWallet.address.startsWith("0x"))
			netWallet.address = "0x" + netWallet.address;

		if (wallet.address == netWallet.address)
		{
			gOPDataBaseOpera->DBInsertWalletInfo(wallet);  //写入数据库。
			//将密钥加密后保存到本地。
			QString key = gDataManager->getUserInfo().strLoginPWD;
			gOPDataManager->encryption(priKey, key);
			recoveryWidget->close();
			//启动主界面.
			StartIMMainWidget(gDataManager->getUserInfo());
			mMainManager->setWalletInfo(netWallet);
			emit sigInitBuddyGroup();
		}
		else
		{
			IMessageBox::tip(recoveryWidget, QStringLiteral("恢复失败"), QStringLiteral("基地地址与钱包不匹配！"));
		}
	}
	else
	{
		IMessageBox::tip(recoveryWidget, QStringLiteral("恢复失败"), QStringLiteral("输入信息有误！"));
	}
}
