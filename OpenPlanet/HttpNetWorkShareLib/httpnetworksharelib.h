#ifndef HTTPNETWORKSHARELIB_H
#define HTTPNETWORKSHARELIB_H

/*Http�������
  ����pos����get�����ϴ�������
*/

#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QSslConfiguration>
#include <QFile>
#include <QTimer>


namespace HttpNetWork
{
	/*Http������*/
	class HttpNetWorkShareLib : public QObject
	{
		Q_OBJECT
	public:
		HttpNetWorkShareLib(QObject *parent = NULL);
		~HttpNetWorkShareLib();

		//************************************
		// Method:    getHttpRequest
		// FullName:  HttpNetWorkShareLib::getHttpRequest
		// Access:    public 
		// Returns:   void
		// Qualifier: get����
		// Parameter: QString strUrl url
		// Parameter: int time_out   ��ʱʱ��
		//************************************
		void getHttpRequest(QString strUrl, int time_out = 20000);
		private slots:
		//************************************
		// Method:    slotReplyFinished
		// FullName:  HttpNetWorkShareLib::slotReplyFinished
		// Access:    private 
		// Returns:   void
		// Qualifier: �������
		// Parameter: QNetworkReply * reply
		//************************************
		void slotReplyFinished(QNetworkReply*reply);

		//************************************
		// Method:    slotRequestTimeout
		// FullName:  HttpNetWorkShareLib::slotRequestTimeout
		// Access:    private 
		// Returns:   void
		// Qualifier: ����ʱ
		//************************************
		void slotRequestTimeout();
	signals:
		//************************************
		// Method:    sigReplyFinished
		// FullName:  HttpNetWorkShareLib::sigReplyFinished
		// Access:    private 
		// Returns:   void
		// Qualifier: ������������ź�
		// Parameter: bool bResult
		// Parameter: QString strResult
		//************************************
		void sigReplyFinished(bool bResult, QString strResult);
	private:
		QNetworkReply *mReply;
		QTimer* m_pTimer;
	};

	/*Http������*/
	class HttpDownLoadFile : public QObject
	{
		Q_OBJECT
	public:
		HttpDownLoadFile(QObject *parent = 0);
		~HttpDownLoadFile();

		//************************************
		// Method:    StartDownLoadFile
		// FullName:  HttpDownLoadFile::StartDownLoadFile
		// Access:    public 
		// Returns:   bool
		// Qualifier: ��ʼ�����ļ�
		// Parameter: QString strUrl 
		// Parameter: QString strFilePath  �ļ�·��
		//************************************
		bool StartDownLoadFile(QString strUrl, QString strFilePath);

		public slots:
		//************************************
		// Method:    replyFinished
		// FullName:  HttpDownLoadFile::replyFinished
		// Access:    public 
		// Returns:   void
		// Qualifier: �������
		// Parameter: QNetworkReply * reply
		//************************************
		void replyFinished(QNetworkReply*reply);
		//************************************
		// Method:    onDownloadProgress
		// FullName:  HttpDownLoadFile::onDownloadProgress
		// Access:    public 
		// Returns:   void
		// Qualifier: ���ؽ�����
		// Parameter: qint64 bytesSent
		// Parameter: qint64 bytesTotal
		//************************************
		void onDownloadProgress(qint64 bytesSent, qint64 bytesTotal);

		//************************************
		// Method:    onReadyRead
		// FullName:  HttpDownLoadFile::onReadyRead
		// Access:    public 
		// Returns:   void
		// Qualifier: ��д�ļ�
		//************************************
		void onReadyRead();

		//************************************
		// Method:    slotLoadorDownLoadCancle
		// FullName:  HttpNetWork::HttpDownLoadFile::slotLoadorDownLoadCancle
		// Access:    public 
		// Returns:   void
		// Qualifier: ����ȡ��
		//************************************
		void slotLoadorDownLoadCancle();

	public:

		void setData(QVariant var) { mUserData = var; }

		QVariant getData() { return mUserData; }

	signals:
		void sigDownFinished(bool);
		void sigDownloadProgress(qint64 bytesSent, qint64 bytesTotal);

	private:
		QNetworkAccessManager *accessManager;
		QNetworkRequest request;
		QNetworkReply *mReply;
		QFile *file;
		QVariant mUserData;  //�û�����
	};

	/*Http�ϴ���*/
	class HttpUpLoadFile : public QObject
	{
		Q_OBJECT
	public:
		HttpUpLoadFile(QObject *parent = 0);
		~HttpUpLoadFile();

		//************************************
		// Method:    StartUpLoadFile
		// FullName:  HttpNetWork::HttpUpLoadFile::StartUpLoadFile
		// Access:    public 
		// Returns:   void
		// Qualifier: ��ʼ�ϴ�
		// Parameter: QString strUrl
		// Parameter: QString filePath
		// Parameter: QVariantMap paramMap
		//************************************
		void StartUpLoadFile(QString strUrl, QString filePath, QVariantMap paramMap);

		void setData(QVariant var) { mUserData = var; }

		QVariant getData() { return mUserData; }
	public slots :
		void replyFinished(QNetworkReply*);
		void OnUploadProgress(qint64 bytesSent, qint64 bytesTotal);
		void slotLoadorDownLoadCancle();
	signals:
		void sigUpLoadFinished(bool bResult,QByteArray byteArray);
		void sigUpLoadProgress(qint64 bytesSent, qint64 bytesTotal);

	private:
		QNetworkAccessManager *accessManager;
		QNetworkRequest request;
		QNetworkReply *mReply;
		QVariant mUserData;  //�û�����
	};
}
#endif // HTTPNETWORKSHARELIB_H
