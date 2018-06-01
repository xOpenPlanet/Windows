#ifndef IMDOWNLOADHEADERIMG_H
#define IMDOWNLOADHEADERIMG_H

/*�ļ�������*/
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
	// Qualifier: �����û�ͷ��
	// Parameter: UserInfo userInfo
	//************************************
	void StartDownLoadUserInfoHeaderImage(UserInfo userInfo);

	//************************************
	// Method:    StartDownLoadImage
	// FullName:  IMDownLoadHeaderImg::StartDownLoadImage
	// Access:    public 
	// Returns:   void
	// Qualifier: ���غ���ͷ���źŷ���QPixMap
	// Parameter: QString strUrl
	// Parameter: QString strLocalPath
	//************************************
	void StartDownLoadBuddyeHeaderImage(BuddyInfo buddyInfo);


	//************************************
	// Method:    StartDownLoadGroupHeaderImage
	// FullName:  IMDownLoadHeaderImg::StartDownLoadGroupHeaderImage
	// Access:    public 
	// Returns:   void
	// Qualifier: ��ʼ����Ⱥ��ͷ��
	// Parameter: GroupInfo groupInfo
	//************************************
	void StartDownLoadGroupHeaderImage(GroupInfo groupInfo);

	//************************************
	// Method:    GetImagePix
	// FullName:  IMDownLoadHeaderImg::GetImagePix
	// Access:    private 
	// Returns:   QT_NAMESPACE::QPixmap
	// Qualifier: ����·��������QPixmap
	// Parameter: QString strPath
	//************************************
	QPixmap GetImagePix(QString strPath);

	//************************************
	// Method:    IsImageFile
	// FullName:  IMDownLoadHeaderImg::IsImageFile
	// Access:    public 
	// Returns:   bool
	// Qualifier: �ж��Ƿ��б���ͼƬ
	// Parameter: QString localPath
	//************************************
	bool IsImageFile(QString localPath);

private slots:
	
	//************************************
	// Method:    slotDownUserPicFinished
	// FullName:  IMDownLoadHeaderImg::slotDownUserPicFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: �����û�ͷ�����
	// Parameter: bool bResult
	//************************************
	void slotDownUserPicFinished(bool bResult);

	//************************************
	// Method:    slotDownBuddyPicFinished
	// FullName:  IMDownLoadHeaderImg::slotDownPicFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: ���غ���ͼƬ����
	//************************************
	void slotDownBuddyPicFinished(bool bResult);

	//************************************
	// Method:    slotDownGroupPicFinished
	// FullName:  IMDownLoadHeaderImg::slotDownGroupPicFinished
	// Access:    private 
	// Returns:   void
	// Qualifier: ����Ⱥ��ͼƬ����
	// Parameter: bool bResult
	//************************************
	void slotDownGroupPicFinished(bool bResult);

signals:
	//************************************
	// Method:    sigUpdateBuddyHeaderImage
	// FullName:  IMDownLoadHeaderImg::sigUpdateBuddyHeaderImage
	// Access:    private 
	// Returns:   void
	// Qualifier: ���͸���ͷ���ź�
	// Parameter: int nIMUserID
	// Parameter: QPixmap pix
	//************************************
	void sigUpdateBuddyHeaderImage(int nIMUserID, QPixmap pix);
private:
};

#endif // IMDOWNLOADHEADERIMG_H
