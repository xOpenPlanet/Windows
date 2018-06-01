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
	mUserInfo.strNote = userInfo.strNote;        //用户
	mUserInfo.strSex = userInfo.strSex;        //用户性别
	mUserInfo.strEmil = userInfo.strEmil;       //邮箱
	mUserInfo.strPhone = userInfo.strPhone;     //电话
	mUserInfo.strSign = userInfo.strSign;      //签名
	mUserInfo.strUserNickName = userInfo.strUserNickName;
	mUserInfo.strUserName = userInfo.strUserNickName;
}