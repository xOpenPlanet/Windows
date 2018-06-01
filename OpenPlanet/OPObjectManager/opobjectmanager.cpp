#include "opobjectmanager.h"
#include "readappconfig.h"
#include "opdatamanager.h"

IMDataBaseOperaInfo *gDataBaseOpera = NULL;
IMDataManagerShareLib *gDataManager = NULL;
IMSocketMessageInfo *gSocketMessage = NULL;

OPDataManager  *gOPDataManager = NULL;

bool gbIsInitCef = false;

CefRefPtr<QCefAppInfo> OnInitCef()
{
	HINSTANCE hInstance = ::GetModuleHandle(NULL);
	CefMainArgs main_args(hInstance);

	CefRefPtr<QCefAppInfo> app = new QCefAppInfo;

	int exit_code = CefExecuteProcess(main_args, app.get(), NULL);
	if (exit_code >= 0){
		exit(exit_code);
	}

	CefSettings settings;
	CefSettingsTraits::init(&settings);
	settings.multi_threaded_message_loop = true;
	settings.single_process = true;
	CefInitialize(main_args, settings, app.get(), NULL);
	gbIsInitCef = true;
	return app;
}

OPObjectManager::OPObjectManager(QObject *parent)
: QObject(parent)
{
	if (gDataBaseOpera == NULL)
		gDataBaseOpera = new IMDataBaseOperaInfo;
	mWindowManager = NULL;
	sysMessage = NULL;
}

OPObjectManager::~OPObjectManager()
{
	if (gDataManager)
	{
		delete gDataManager;
		gDataManager = NULL;
	}
	if (gDataBaseOpera)
	{
	//	gDataBaseOpera->DisConnectDB();
		delete gDataBaseOpera;
		gDataBaseOpera = NULL;
	}
	if (gSocketMessage)
	{
		gSocketMessage->deleteLater();
		gSocketMessage = NULL;
	}
	if (gOPDataManager)
	{
		delete gOPDataManager;
		gOPDataManager = NULL;
	}
	if (mWindowManager)
	{
		mWindowManager->deleteLater();
		mWindowManager = NULL;
	}
	if (sysMessage)
	{
		sysMessage->deleteLater();
		sysMessage = NULL;
	}
}

//��ʼ��
void OPObjectManager::InitApp()
{
	//	InitLog();  //��ʼ����־��Ϣ
	RegisterMetaType(); //ע���ź�����
	gDataManager = new IMDataManagerShareLib;

	if (mWindowManager == NULL)
	{
		mWindowManager = new OPWindowsManagerShareLib;
	}
	if (sysMessage == NULL)
	{
		sysMessage = new ParseSystemMessage;
	}
	connect(sysMessage, SIGNAL(sigUpdateUserInfo(UserInfo)), mWindowManager, SIGNAL(sigUpdateUserInfo(UserInfo)));
	connect(sysMessage, SIGNAL(sigUpdateInfo(int, QVariant)), mWindowManager, SIGNAL(sigUpdateInfo(int, QVariant)));
	connect(sysMessage, SIGNAL(sigUserQuitGroup(QString, QString)), mWindowManager, SIGNAL(sigUserQuitGroup(QString, QString)));
	connect(sysMessage, SIGNAL(sigAddFriendSuccess(BuddyInfo)), mWindowManager, SIGNAL(sigAddFriendSuccess(BuddyInfo)));
	connect(sysMessage, SIGNAL(sigAddSuccessGroup(GroupInfo)), mWindowManager, SIGNAL(sigAddSuccessGroup(GroupInfo)));
	connect(sysMessage, SIGNAL(sigAddSuccessGroupUserInfo(QString, BuddyInfo)), mWindowManager, SIGNAL(sigAddSuccessGroupUserInfo(QString, BuddyInfo)));
	connect(sysMessage, SIGNAL(sigDeleteGroup(QString)), mWindowManager, SIGNAL(sigDeleteGroup(QString)));
	connect(sysMessage, SIGNAL(sigDeleteFriend(int, QVariant)), mWindowManager, SIGNAL(sigDeleteFriend(int, QVariant)));
}

//��ʼ����־��Ϣ
void OPObjectManager::InitLog()
{
#ifdef QT_NO_DEBUG
#else
	//QDir::setCurrent(QApplication::applicationDirPath());
	//qInstallMessageHandler(LogInfo);  //��־ģ��
#endif
}

/*��¼��־*/
void OPObjectManager::LogInfo(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QString text;
	switch (type)
	{
	case QtDebugMsg:
		text = QString("Debug:");
		break;
	case QtWarningMsg:
		text = QString("Warning:");
		break;
	case QtCriticalMsg:
		text = QString("Critical:");
		break;
	case QtFatalMsg:
		text = QString("Fatal:");
		break;
	}

	QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
	QString current_date = QString("(%1)").arg(current_date_time);
	QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);
	QString fileDate = QDateTime::currentDateTime().toString("yyyy_MM_dd");
	QString strFileName = QString("log/%1.txt").arg(fileDate);


	if (!QFile::exists(strFileName))//�ļ������ڣ��򴴽�
	{
		QDir fileDir = QFileInfo(strFileName).absoluteDir();
		QString strFileDir = QFileInfo(strFileName).absolutePath();
		if (!fileDir.exists()) //·�������ڣ�����·��
		{
			fileDir.mkpath(strFileDir);
		}
	}
	QFile logFile(strFileName);
	if (!logFile.open(QIODevice::WriteOnly | QIODevice::Append))//δ�ɹ���
	{
		return;
	}
	QTextStream text_stream(&logFile);
	text_stream << message << "\r\n";
	logFile.flush();
	logFile.close();
}

//ע���ź�����
void OPObjectManager::RegisterMetaType()
{
	qRegisterMetaType<UserInfo>("UserInfo");
	qRegisterMetaType<BuddyInfo>("BuddyInfo");
}

//��ȡ�����ļ�
AppConfig OPObjectManager::readAppConf()
{
	ReadAppConfig conf;
	AppConfig appConf = conf.ReadConfig("config/config.xml");
	if (gDataManager)
	{
		gDataManager->setAppConfigInfo(appConf);
	}
	return appConf;
}

//������½����
void OPObjectManager::StartLoginWidget()
{
	connect(mWindowManager, SIGNAL(sigLoginSuccess(QVariantMap)), this, SLOT(slotLoginSuccess(QVariantMap)));
	connect(mWindowManager, SIGNAL(sigExit()), this, SLOT(slotExit()));
	connect(mWindowManager, SIGNAL(sigInitBuddyGroup()), this, SLOT(slotInitBuddyGroup()));
	connect(this, SIGNAL(sigReConnectServerSuccess(QString)), mWindowManager, SIGNAL(sigSetMainWidgetStatusLabel(QString)));

	if (gDataManager)
	{
		AppConfig conf = gDataManager->getAppConfigInfo();
		mWindowManager->StartLoginWidget(conf.strYWYHRequestURL, conf.appVersion.appID);
	}
}

//��½�ɹ�
void OPObjectManager::slotLoginSuccess(QVariantMap varMap)
{
	UserInfo userInfo = ParseUserInfoFromServer(varMap);

	if (gDataManager)
	{
		gDataManager->setUserInfo(userInfo);
	};

	slotParsePersonInfo(true, userInfo);
}

UserInfo OPObjectManager::ParseUserInfoFromServer(QVariantMap varMap)
{
	UserInfo userInfo;
	QVariantMap mapVar = varMap["userInfo"].toMap();
	userInfo.strUserPWD = mapVar["imPassword"].toString();
	userInfo.nUserID = mapVar["imUserId"].toInt();
	userInfo.strUserNickName = mapVar["nickName"].toString();
	userInfo.strLoginPWD = mapVar["password"].toString();
	userInfo.strSex = mapVar["sex"].toString();
	userInfo.strAccountName = mapVar["userId"].toString();
	userInfo.strUserName = mapVar["userName"].toString();
	userInfo.strUserDefaultAvatar = ":/PerChat/Resources/person/temp.png";
	QString path;
	QDir dir;
	userInfo.strUserAvatarLocal = dir.currentPath() + "/resource/header/" + mapVar["imUserId"].toString() + ".jpg";
	userInfo.strUserAvatarHttp = mapVar["avatar"].toString();

	/*����Ǯ����Ϣ*/
	if (gOPDataManager == NULL)
	{
		gOPDataManager = new OPDataManager;
	}

	gOPDataManager->setAccessToken(varMap["access_token"].toString());
	gOPDataManager->setRefreshToken(varMap["refresh_token"].toString());
	WalletInfo wallet;
	wallet.address = mapVar["ethAddress"].toString();
	wallet.pubkey = mapVar["ethPublicKey"].toString();
	wallet.fromInviteCode = mapVar["fromInviteCode"].toString();
	wallet.inviteCode = mapVar["inviteCode"].toString();
	wallet.inviteCodeUseCount = mapVar["inviteCodeUseCount"].toString();
	wallet.userIdMd5 = mapVar["userIdMd5"].toString();
	wallet.planet = mapVar["planet"].toString();
	gOPDataManager->setWalletInfo(wallet);
	return userInfo;
}

//���������Ϣ
void OPObjectManager::RequestPersonInfo()
{
	IMRequestBuddyInfo *requestPerson = new IMRequestBuddyInfo;
	connect(requestPerson, SIGNAL(sigRequestPersonInfoSuccess(bool, UserInfo)), this, SLOT(slotParsePersonInfo(bool, UserInfo)));
	if (gDataManager)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		AppConfig appConf = gDataManager->getAppConfigInfo();
		requestPerson->RequestPersonInfo(appConf.MessageServerAddress, QString::number(userInfo.nUserID));
	}
}

//���������Ϣ����
void OPObjectManager::slotParsePersonInfo(bool bResult, UserInfo userInfo)
{
	if (bResult)
	{
		if (gDataManager)
		{
			gDataManager->updateUserInfo(userInfo);
		}
		/*����socket����*/
		ConnectSocketServer();
	}
	else
	{
		if (mWindowManager)
		{
			mWindowManager->ChangeLoginWidget(QStringLiteral("���������Ϣʧ��!"));
		}
	}
}

//���������Ϣ
void OPObjectManager::RequestBuddyInfo()
{
	IMRequestBuddyInfo *requestBuddy = new IMRequestBuddyInfo;
	connect(requestBuddy, SIGNAL(sigParseBuddyInfo(BuddyInfo)), mWindowManager, SLOT(slotInsertBuddyInfo(BuddyInfo)));
	if (gDataManager)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		AppConfig appConf = gDataManager->getAppConfigInfo();
		requestBuddy->RequestBuddyInfo(appConf.MessageServerAddress, QString::number(userInfo.nUserID), userInfo.strUserPWD, appConf.appVersion.appID);
	}
}

//����Ⱥ����Ϣ
void OPObjectManager::RequestGroupInfo()
{
	IMRequestBuddyInfo *requestBuddy = new IMRequestBuddyInfo;
	connect(requestBuddy, SIGNAL(sigParseGroupInfo(GroupInfo)), mWindowManager, SLOT(slotInsertGroupInfo(GroupInfo)));
	if (gDataManager)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		AppConfig appConf = gDataManager->getAppConfigInfo();
		requestBuddy->RequestGroupInfo(appConf.MessageServerAddress, QString::number(userInfo.nUserID), userInfo.strUserPWD, appConf.appVersion.appID);
	}
}

//����socket����
void OPObjectManager::ConnectSocketServer()
{
	if (gSocketMessage == NULL)
	{
		gSocketMessage = new IMSocketMessageInfo(this);
		connect(gSocketMessage, SIGNAL(sigRevSystemMessage(MessageInfo)), this, SLOT(slotRevSystemMessage(MessageInfo)));  //���յ�ϵͳ��Ϣ
		connect(gSocketMessage, SIGNAL(sigRevOtherDeviceMsg(MessageInfo)), mWindowManager, SIGNAL(sigRevOtherDeviceMsg(MessageInfo)));  //�յ�ͨ�������豸���͵���Ϣ
		connect(gSocketMessage, SIGNAL(sigRevMsgInfo(MessageInfo, int)), this, SLOT(slotRevMsgInfo(MessageInfo, int)));  //���յ���Ϣ
		connect(gSocketMessage, SIGNAL(sigRevUpdateMessageState(MessageInfo, int)), mWindowManager, SIGNAL(sigUpdateMessageState(MessageInfo, int)));  //���յ���Ϣ
		connect(gSocketMessage, SIGNAL(sigDisConnectServerServer(QString)), mWindowManager, SIGNAL(sigSetMainWidgetStatusLabel(QString)));  //��������Ͽ������ź�
		connect(gSocketMessage, SIGNAL(sigGetSocketAddressErro(QString)), this, SLOT(slotGetSocketAddressErro(QString)));  //��ȡsocket��Ϣʧ��
		connect(gSocketMessage, SIGNAL(sigConnectSocketSuccess()), this, SLOT(slotConnectSocketSuccess()));  //����socket�ɹ�
		connect(gSocketMessage, SIGNAL(sigReConnectSuccess()), this, SLOT(slotReConnectSuccess()));  //����socket�ɹ�
	}
	if (gDataManager)
	{
		AppConfig conf = gDataManager->getAppConfigInfo();
		UserInfo userInfo = gDataManager->getUserInfo();
		gSocketMessage->RequestSocketUrl(conf.MessageServerAddress, QString::number(userInfo.nUserID), userInfo.strUserPWD);
	}
}

//Qualifier: ���յ�ϵͳ��Ϣ
void OPObjectManager::slotRevSystemMessage(MessageInfo msgInfo)
{
	sysMessage->ParseSysMessage(msgInfo);
}

//Qualifier: ���յ���Ϣ
void OPObjectManager::slotRevMsgInfo(MessageInfo msgInfo, int)
{
	if (mWindowManager)
	{
		mWindowManager->RevServerMessageInfo(msgInfo);
	}
}

//Qualifier: ��ȡsocket��Ϣʧ��
void OPObjectManager::slotGetSocketAddressErro(QString msg)
{
	if (mWindowManager)
	{
		mWindowManager->ChangeLoginWidget(msg);
	}
}

//Qualifier: ����socket�ɹ�
void OPObjectManager::slotConnectSocketSuccess()
{
	//�������ݿ�
	if (gDataBaseOpera == NULL)
		gDataBaseOpera = new IMDataBaseOperaInfo;
	if (gDataManager)
	{
		UserInfo userInfo = gDataManager->getUserInfo();
		QString strDBPath = "database//" + QString::number(userInfo.nUserID) + "//database.db";
		gDataBaseOpera->ConnectDB(strDBPath, "IMChatClient");
		gSocketMessage->SetIMUserID(userInfo.nUserID);
		if (mWindowManager)
		{
			//���ٵ�¼���ڡ�
			mWindowManager->DestroyLoginWidget();
			//��ʼ��cef��
			OnInitCef();
			//������ݿ����л��ص�ַ�����������棬����Ҫ���û��ָ�Ǯ����
			mWindowManager->ReadWalletAddress();
		}
	}
}

//Qualifier:����socket�ɹ�
void OPObjectManager::slotReConnectSuccess()
{
	//��ȡ�汾��
	if (gDataManager)
	{
		AppConfig conf = gDataManager->getAppConfigInfo();
		QString msg = QStringLiteral("��������  ") + conf.appVersion.versionID;
		emit sigReConnectServerSuccess(msg);
	}
}

//�ж��Ƿ����������Ϣ
void OPObjectManager::InitBuddyInfo()
{
	if (gDataBaseOpera)
	{
		if (gDataBaseOpera->DBJudgeBuddyIsEmpty())
		{
			RequestBuddyInfo();/*���������Ϣ*/
		}
		else      //�������ݿ���Ϣ
		{
			LoadBuddyInfo();
		}
	}
}

//���غ�����Ϣ
void OPObjectManager::LoadBuddyInfo()
{
	if (mWindowManager)
	{
		QList<BuddyInfo> listBuddyInfo = gDataBaseOpera->DBGetBuddyInfo();
		IMRequestBuddyInfo *requestBuddy = new IMRequestBuddyInfo;
		connect(requestBuddy, SIGNAL(sigParseBuddyInfo(BuddyInfo)), mWindowManager, SLOT(slotInsertBuddyInfo(BuddyInfo)));
		requestBuddy->RequestBuddyInfo(listBuddyInfo);
	}
}

//�ж��Ƿ�����Ⱥ����Ϣ
void OPObjectManager::InitGroupInfo()
{
	if (gDataBaseOpera)
	{
		if (gDataBaseOpera->DBJudgetGroupIsEmpty())
		{
			RequestGroupInfo();/*����Ⱥ����Ϣ*/
		}
		else      //�������ݿ���Ϣ
		{
			LoadGroupInfo();
		}
	}
}

void OPObjectManager::LoadGroupInfo()
{
	if (mWindowManager)
	{
		QList<GroupInfo> listGroupInfo = gDataBaseOpera->DBGetAllGroupInfo();
		IMRequestBuddyInfo *requestGroup = new IMRequestBuddyInfo;
		connect(requestGroup, SIGNAL(sigParseGroupInfo(GroupInfo)), mWindowManager, SLOT(slotInsertGroupInfo(GroupInfo)));
		requestGroup->RequestGroupInfo(listGroupInfo);
	}
}

void OPObjectManager::slotExit()
{
	if (gbIsInitCef)
	{
		CefShutdown();
	}
	if (mWindowManager)
	{
		mWindowManager->deleteLater();
		mWindowManager = NULL;
	}

	if (gDataBaseOpera)
	{
	//	gDataBaseOpera->DisConnectDB();
		delete gDataBaseOpera;
		gDataBaseOpera = NULL;
	}

	if (gDataManager)
	{
		delete gDataManager;
		gDataManager = NULL;
	}

	if (gSocketMessage)
	{
		gSocketMessage->deleteLater();
		gSocketMessage = NULL;
	}

	exit(0);
}

void OPObjectManager::update()
{
	UpdateShareLib *updateShareLib = new UpdateShareLib;
	connect(updateShareLib, SIGNAL(sigAlreadyLatest()), this, SLOT(slotStart()));
	updateShareLib->onUpdate();
}

void OPObjectManager::slotStart()
{
	StartLoginWidget();
}

void OPObjectManager::slotInitBuddyGroup()
{
	InitBuddyInfo();  //�ж��Ƿ���غ�����Ϣ
	InitGroupInfo();/*����Ⱥ����Ϣ*/
}

