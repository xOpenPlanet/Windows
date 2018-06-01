#ifndef HTTPNETWORKSHARELIB_H
#define HTTPNETWORKSHARELIB_H

/*Http请求类库
  包含pos请求，get请求，上传，下载
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
	/*Http请求类*/
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
		// Qualifier: get请求
		// Parameter: QString strUrl url
		// Parameter: int time_out   超时时间
		//************************************
		void getHttpRequest(QString strUrl, int time_out = 20000);
		private slots:
		//************************************
		// Method:    slotReplyFinished
		// FullName:  HttpNetWorkShareLib::slotReplyFinished
		// Access:    private 
		// Returns:   void
		// Qualifier: 请求结束
		// Parameter: QNetworkReply * reply
		//************************************
		void slotReplyFinished(QNetworkReply*reply);

		//************************************
		// Method:    slotRequestTimeout
		// FullName:  HttpNetWorkShareLib::slotRequestTimeout
		// Access:    private 
		// Returns:   void
		// Qualifier: 请求超时
		//************************************
		void slotRequestTimeout();
	signals:
		//************************************
		// Method:    sigReplyFinished
		// FullName:  HttpNetWorkShareLib::sigReplyFinished
		// Access:    private 
		// Returns:   void
		// Qualifier: 发送请求结束信号
		// Parameter: bool bResult
		// Parameter: QString strResult
		//************************************
		void sigReplyFinished(bool bResult, QString strResult);
	private:
		QNetworkReply *mReply;
		QTimer* m_pTimer;
	};

	/*Http下载类*/
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
		// Qualifier: 开始下载文件
		// Parameter: QString strUrl 
		// Parameter: QString strFilePath  文件路径
		//************************************
		bool StartDownLoadFile(QString strUrl, QString strFilePath);

		public slots:
		//************************************
		// Method:    replyFinished
		// FullName:  HttpDownLoadFile::replyFinished
		// Access:    public 
		// Returns:   void
		// Qualifier: 请求结束
		// Parameter: QNetworkReply * reply
		//************************************
		void replyFinished(QNetworkReply*reply);
		//************************************
		// Method:    onDownloadProgress
		// FullName:  HttpDownLoadFile::onDownloadProgress
		// Access:    public 
		// Returns:   void
		// Qualifier: 下载进度条
		// Parameter: qint64 bytesSent
		// Parameter: qint64 bytesTotal
		//************************************
		void onDownloadProgress(qint64 bytesSent, qint64 bytesTotal);

		//************************************
		// Method:    onReadyRead
		// FullName:  HttpDownLoadFile::onReadyRead
		// Access:    public 
		// Returns:   void
		// Qualifier: 读写文件
		//************************************
		void onReadyRead();

		//************************************
		// Method:    slotLoadorDownLoadCancle
		// FullName:  HttpNetWork::HttpDownLoadFile::slotLoadorDownLoadCancle
		// Access:    public 
		// Returns:   void
		// Qualifier: 下载取消
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
		QVariant mUserData;  //用户数据
	};

	/*Http上传类*/
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
		// Qualifier: 开始上传
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
		QVariant mUserData;  //用户数据
	};
}
#endif // HTTPNETWORKSHARELIB_H
