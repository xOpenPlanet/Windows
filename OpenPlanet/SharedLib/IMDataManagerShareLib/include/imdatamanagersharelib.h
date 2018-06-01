#ifndef IMDATAMANAGERSHARELIB_H
#define IMDATAMANAGERSHARELIB_H

/*���������ݴ���*/
#include "common.h"

class IMDataManagerShareLib
{
public:
	IMDataManagerShareLib();
	~IMDataManagerShareLib();

	//************************************
	// Method:    setAppConfigInfo
	// FullName:  IMDataManagerShareLib::setAppConfigInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ����App �����ļ���Ϣ
	// Parameter: AppConfig conf
	//************************************
	void setAppConfigInfo(AppConfig conf) { mAppConf = conf; }

	//************************************
	// Method:    getAppConfigInfo
	// FullName:  IMDataManagerShareLib::getAppConfigInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ȡApp�����ļ���Ϣ
	//************************************
	AppConfig getAppConfigInfo() { return mAppConf; }

	//************************************
	// Method:    setUserInfo
	// FullName:  IMDataManagerShareLib::setUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: ���õ�ǰ�û�
	// Parameter: UserInfo userInfo
	//************************************
	void setUserInfo(UserInfo userInfo);

	//************************************
	// Method:    updateUserInfo
	// FullName:  IMDataManagerShareLib::updateUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: �����û���Ϣ
	//************************************
	void updateUserInfo(UserInfo userInfo);

	//************************************
	// Method:    getUserInfo
	// FullName:  IMDataManagerShareLib::getUserInfo
	// Access:    public 
	// Returns:   UserInfo
	// Qualifier: ��ȡ�û���Ϣ
	//************************************
	UserInfo getUserInfo() { return mUserInfo; }
private:
	AppConfig mAppConf;
	UserInfo mUserInfo;

};

#endif // IMDATAMANAGERSHARELIB_H
