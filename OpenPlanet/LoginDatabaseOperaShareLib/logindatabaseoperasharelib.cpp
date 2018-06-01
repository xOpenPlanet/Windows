#include "logindatabaseoperasharelib.h"
#include <QDateTime>

LoginDatabaseOperaShareLib::LoginDatabaseOperaShareLib()
{
	mSqlUtil = NULL;
}

LoginDatabaseOperaShareLib::~LoginDatabaseOperaShareLib()
{
	CloseDB();
}

//���ӵ�½���ݿ�
bool LoginDatabaseOperaShareLib::ConnectLoginDB(QString strDBPath, QString strDBName)
{
	if (mSqlUtil == NULL) mSqlUtil = new SqlLiteShareLib();
	if (mSqlUtil->CreateDataFile(strDBPath))
	{
		bool bErro = false;
//#ifdef _DEBUG
		bErro = mSqlUtil->OnConnectDB(strDBPath, strDBName);
//#else
	//	bErro = mSqlUtil->OnConnectDB(strDBPath, strDBName, SQLITE_PASSWORD);
//#endif // _DEBUG
		if (bErro)
		{
			if (!mSqlUtil->isExistTable("USERINFO"))
			{
				//�����û���
				QString strSql = "create table USERINFO(userID int primary key,NickName varchar(30),PassWord varchar(30),AvatarHttp varchar(100),AvatarLocal varchar(100),UserName varchar(30),Note varchar(30),Sex varchar(10),IsAutoLogin int,updateTime varchar(30),IsOnline int,IsLastLoginUser int,strUserID varchar(30));";   // IsOnline �Ƿ��Ѿ���¼, IsLastLoginUser �Ƿ�����һ�ε�¼���û�   �����������Զ���½ʱ
				mSqlUtil->ExecuSql(strSql);
			}
			else
			{
				QString strSql = QString::fromLocal8Bit("select * from sqlite_master where name='USERINFO' and sql like '%strUserID%'");
				QSqlQuery query = mSqlUtil->ExecuQuery(strSql);
				if (!query.next())
				{
					strSql = QString("ALTER TABLE USERINFO ADD COLUMN strUserID varchar");
					mSqlUtil->ExecuSql(strSql);
				}
			}
			return true;
		}
	}
	return false;
}

//�ر����ݿ�
void LoginDatabaseOperaShareLib::CloseDB()
{
	if (mSqlUtil)
		mSqlUtil->CloseDataBase();
	delete mSqlUtil;
}

//�����û���Ϣ
void LoginDatabaseOperaShareLib::InsertUserInfoDB(UserInfo userInfo)
{
	if (userInfo.bIsSavaPWD)
	{
		QString UserID = QString("%1").arg(userInfo.nUserID);
		QDateTime time = QDateTime::currentDateTime();//��ȡϵͳ���ڵ�ʱ��
		QString strTimer = time.toString("yyyy-MM-dd hh:mm:ss"); //������ʾ��ʽ
		QString strSql = QString("delete from USERINFO where userID = '%1'").arg(userInfo.nUserID);
		mSqlUtil->ExecuSql(strSql);

		/*���������û�*/
		strSql = QString("update USERINFO set IsOnline=0,IsLastLoginUser=0");
		mSqlUtil->ExecuSql(strSql);

		strSql = QString("insert into USERINFO(userID,NickName,PassWord,AvatarHttp,AvatarLocal,UserName,"
			"Note,Sex,IsAutoLogin,updateTime,IsOnline,IsLastLoginUser,strUserID) values(%1,'%2','%3','%4',"
			"'%5','%6','%7','%8',%9,'%10',1,1,'%11')").arg(userInfo.nUserID).arg(userInfo.strUserNickName).arg(userInfo.strLoginPWD)
			.arg(userInfo.strUserAvatarHttp).arg(userInfo.strUserAvatarLocal).arg(userInfo.strUserName).arg(userInfo.strNote).arg(userInfo.strSex).arg(userInfo.bIsAutoLogin).arg(strTimer)
			.arg(userInfo.strAccountName);
		mSqlUtil->ExecuSql(strSql);
	}
}


/*��ȡ���ݿ������е��û���Ϣ*/
QList<UserInfo> LoginDatabaseOperaShareLib::GetDBAllUserInfoDB()
{
	QList<UserInfo> vUserInfo;
	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QString strSql = "select * from USERINFO";
		QSqlQuery resultQuery = mSqlUtil->ExecuQuery(strSql);
		while (resultQuery.next())
		{
			UserInfo userInfo;
			userInfo.nUserID = resultQuery.value("userID").toInt();
			userInfo.strUserPWD = resultQuery.value("PassWord").toString();
			userInfo.strUserAvatarHttp = resultQuery.value("AvatarHttp").toString();
			userInfo.strUserAvatarLocal = resultQuery.value("AvatarLocal").toString();
			userInfo.strUserNickName = resultQuery.value("NickName").toString();
			userInfo.strUserName = resultQuery.value("UserName").toString();;
			userInfo.strNote = resultQuery.value("Note").toString();
			userInfo.strSex = resultQuery.value("Sex").toString();
			userInfo.bIsAutoLogin = resultQuery.value("IsAutoLogin").toBool();
			userInfo.bIsOnline = resultQuery.value("IsOnline").toBool();         
			userInfo.bIsLastLoginUser = resultQuery.value("IsLastLoginUser").toBool();    
			userInfo.strAccountName = resultQuery.value("strUserID").toString();
			vUserInfo.insert(vUserInfo.end(), userInfo);
		}
	}
	return vUserInfo;
}

//ɾ�����ݿ��е��û���Ϣ
void LoginDatabaseOperaShareLib::DeleteUserInfoAtDB(QString strUserID)
{
	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QString strSql = QString("delete from USERINFO where userID = '%1'").arg(strUserID);
		mSqlUtil->ExecuSql(strSql);
	}
}

void LoginDatabaseOperaShareLib::InsertProxyInfoDB(NetWorkProxyInfo networkModel)
{
	/*�����жϱ��Ƿ����*/
	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QString strSql;
		if (!mSqlUtil->isExistTable("ProxyInfo"))
		{
			/*������*/
			//�����û���
			strSql = "create table ProxyInfo(ProxyType int primary key,Address varchar(100),Port int,UserName varchar(100),PassWord varchar(100),LoginTimeIndex int);";
			mSqlUtil->ExecuSql(strSql);
		}
		/*��ձ�����*/
		strSql = QString("delete from ProxyInfo");
		mSqlUtil->ExecuSql(strSql);
		/*���������Ϣ*/
		strSql = QString("insert into ProxyInfo(ProxyType,Address,Port,UserName,PassWord,LoginTimeIndex) values(%1,'%2',%3,'%4','%5',%6)").arg(networkModel.proxyModel)
			.arg(networkModel.strAddress).arg(networkModel.strPort.toInt()).arg(networkModel.strUserName).arg(networkModel.strUserPwd).arg(1);
		mSqlUtil->ExecuSql(strSql);
	}
}

void LoginDatabaseOperaShareLib::DeleteProxyInfoDB()
{
	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QString strSql = QString("delete from ProxyInfo");
		mSqlUtil->ExecuSql(strSql);
	}
}

NetWorkProxyInfo LoginDatabaseOperaShareLib::GetNetWorkProxyInfoDB()
{
	NetWorkProxyInfo netWorkProxy;
	QString strSql = QString("select * from ProxyInfo");
	if (mSqlUtil != NULL && mSqlUtil->IsOpen())
	{
		QSqlQuery resultQuery = mSqlUtil->ExecuQuery(strSql);
		while (resultQuery.next())
		{
			netWorkProxy.proxyModel = resultQuery.value("ProxyType").toInt();
			netWorkProxy.strAddress = resultQuery.value("Address").toString();
			netWorkProxy.strPort = resultQuery.value("Port").toString();
			netWorkProxy.strUserName = resultQuery.value("UserName").toString();
			netWorkProxy.strUserPwd = resultQuery.value("PassWord").toString();
			netWorkProxy.nIndex = resultQuery.value("LoginTimeIndex").toInt();
		}
	}
	return netWorkProxy;
}