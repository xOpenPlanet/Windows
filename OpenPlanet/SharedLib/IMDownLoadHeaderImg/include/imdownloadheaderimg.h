#ifndef IMDOWNLOADHEADERIMG_H
#define IMDOWNLOADHEADERIMG_H

/*文件下载类*/
#include <QObject>
#include <QPixmap>
#include "httpnetworksharelib.h"
#include "imbuddy.h"
#include "common.h"

class IMDownLoadHeaderImg : public QObject
{
	Q_OBJECT
public:
	IMDownLoadHeaderImg(QObject *parent = NULL);
	~IMDownLoadHeaderImg();

	//************************************
	// Method:    StartDownLoadUserInfoHeaderImage
	// FullName:  IMDownLoadHeaderImg::StartDownLoadUserInfoHeaderImage
	// Access:    public 
	// Returns:   void
	// Qualifier: 下载用户头像
	// Parameter: UserInfo userInfo
	//************************************
	void StartDownLoadUserInfoHeaderImage(UserInfo userInfo);

	//************************************
	// Method:    StartDownLoadImage
	// FullName:  IMDownLoadHeaderImg::StartDownLoadImage
	// Access:    public 
	// Returns:   void
	// Qualifier: 下载好友头像，信号返回QPixMap
	// Parameter: QString strUrl
	// Parameter: QString strLocalPath
	//************************************
	void StartDownLoadBuddyeHeaderImage(BuddyInfo buddyInfo);


	//************************************
	// Method:    StartDownLoadGroupHeaderImage
	// FullName:  IMDownLoadHeaderImg::StartDownLoadGroupHeaderImage
	// Access:    public 
	// Returns:   void
	// Qualifier: 开始下载群组头像
	// Parameter: GroupInfo groupInfo
	//************************************
	void StartDownLoadGroupHeaderImage(GroupInfo groupInfo);

	//************************************
	// Method:    GetImagePix
	// FullName:  IMDownLoadHeaderImg::GetImagePix
	// Access:    private 
	// Returns:   QT_NAMESPACE::QPixmap
	// Qualifier: 传入路径，返回QPixmap
	// Parameter: QString strPath
	//************************************
	QPixmap GetImagePix(QString strPath);

	//************************************
	// Method:    IsImageFile
	// FullName:  IMDownLoadHeaderImg::IsImageFile
	// Access:    public 
	// Returns:   bool
	// Qualifier: 判断是否有本地图片
	// Parameter: QString localPath
	//************************************
	bool IsImageFile(QString localPath);

private slots:
	
	//************************************
	// Method:    slotDownUserPicFinished
	// FullName:  IMDownLoadHeaderImg::slotDownUserPicFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: 下载用户头像结束
	// Parameter: bool bResult
	//************************************
	void slotDownUserPicFinished(bool bResult);

	//************************************
	// Method:    slotDownBuddyPicFinished
	// FullName:  IMDownLoadHeaderImg::slotDownPicFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: 下载好友图片结束
	//************************************
	void slotDownBuddyPicFinished(bool bResult);

	//************************************
	// Method:    slotDownGroupPicFinished
	// FullName:  IMDownLoadHeaderImg::slotDownGroupPicFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: 下载群组图片结束
	// Parameter: bool bResult
	//************************************
	void slotDownGroupPicFinished(bool bResult);

signals:
	//************************************
	// Method:    sigUpdateBuddyHeaderImage
	// FullName:  IMDownLoadHeaderImg::sigUpdateBuddyHeaderImage
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送更新头像信号
	// Parameter: int nIMUserID
	// Parameter: QPixmap pix
	//************************************
	void sigUpdateBuddyHeaderImage(int nIMUserID, QPixmap pix);
private:
};

#endif // IMDOWNLOADHEADERIMG_H
