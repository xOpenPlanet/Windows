#include "imdatamanagersharelib.h"

IMDataManagerShareLib::IMDataManagerShareLib()
{

}

IMDataManagerShareLib::~IMDataManagerShareLib()
{

}

void IMDataManagerShareLib::setUserInfo(UserInfo userInfo)
{ 
	mUserInfo = userInfo; 
}

void IMDataManagerShareLib::updateUserInfo(UserInfo userInfo)
{
	mUserInfo.strUserAvatarHttp = userInfo.strUserAvatarHttp;
	mUserInfo.strNote = userInfo.strNote;        //�û�
	mUserInfo.strSex = userInfo.strSex;        //�û��Ա�
	mUserInfo.strEmil = userInfo.strEmil;       //����
	mUserInfo.strPhone = userInfo.strPhone;     //�绰
	mUserInfo.strSign = userInfo.strSign;      //ǩ��
	mUserInfo.strUserNickName = userInfo.strUserNickName;
	mUserInfo.strUserName = userInfo.strUserNickName;
}