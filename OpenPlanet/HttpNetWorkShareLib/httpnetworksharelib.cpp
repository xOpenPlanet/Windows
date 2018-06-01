#include "httpnetworksharelib.h"
#include <QTextCodec>
#include <QDir>

namespace HttpNetWork
{
	HttpNetWorkShareLib::HttpNetWorkShareLib(QObject *parent)
	: QObject(parent)
	{
		mReply = NULL;
		m_pTimer = NULL;
	}

	HttpNetWorkShareLib::~HttpNetWorkShareLib()
	{
		if (mReply != NULL)
		{
			if (!mReply->isFinished())
			{
				mReply->abort();
			}
			mReply->deleteLater();
		}
		if (m_pTimer)
		{
			if (m_pTimer->isActive())
			{
				m_pTimer->stop();
			}
			m_pTimer->deleteLater();
		}
	}

	void HttpNetWorkShareLib::getHttpRequest(QString strUrl, int time_out)
	{
		QUrl url(strUrl);
		QNetworkRequest request;
		request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/x-www-form-urlencoded"));
		request.setUrl(url); //地址信息
		if (strUrl.toLower().startsWith(QStringLiteral("https")))//https请求，需ssl支持(下载openssl拷贝libeay32.dll和ssleay32.dll文件至Qt bin目录或程序运行目录)
		{
			QSslConfiguration sslConfig;
			sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
			sslConfig.setProtocol(QSsl::TlsV1_1);
			request.setSslConfiguration(sslConfig);
		}
		QNetworkAccessManager *accessManager = new QNetworkAccessManager(this);
		m_pTimer = new QTimer;
		connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slotRequestTimeout()));//超时信号
		mReply = accessManager->get(request);
		connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotReplyFinished(QNetworkReply*)));
		m_pTimer->start(time_out);
	}

	void HttpNetWorkShareLib::slotReplyFinished(QNetworkReply*reply)
	{
		if (m_pTimer)
		{
			m_pTimer->stop();
		}
		if (reply->error() == QNetworkReply::NoError)
		{
			QByteArray resultContent = mReply->readAll();
			QTextCodec* pCodec = QTextCodec::codecForName("UTF-8");
			QString strResult = pCodec->toUnicode(resultContent);
			emit sigReplyFinished(true, strResult);
		}
		else
		{
			emit sigReplyFinished(false, QStringLiteral("relpay erro!"));
		}
		mReply->deleteLater();
		mReply = NULL;
	}
	//请求超时
	void HttpNetWorkShareLib::slotRequestTimeout()
	{
		m_pTimer->stop();//关闭定时器
		mReply->disconnect();
		mReply->abort();
		mReply->deleteLater();
		mReply = NULL;
		emit sigReplyFinished(false, QStringLiteral("timeout"));
	}


	/***************************************************文件下载类***************************************/
#include <QFileInfo>
#include <QDateTime>
	HttpDownLoadFile::HttpDownLoadFile(QObject *parent)
		: QObject(parent)
	{
		mReply = NULL;
	}

	HttpDownLoadFile::~HttpDownLoadFile()
	{
		
	}

	bool HttpDownLoadFile::StartDownLoadFile(QString strUrl, QString strFilePath)
	{
		QUrl url(strUrl);

		if (strFilePath.contains("/"))
		{
			int nLocal = strFilePath.lastIndexOf("/");
			QString strPath = strFilePath.mid(0, nLocal);
			QDir *dir = new QDir;
			if (!dir->exists(strPath))
			{
				if (!dir->mkpath(strPath))
				{
					qDebug() << QStringLiteral("图片文件夹创建失败!");
				}
			}
		}
		
		file = new QFile(strFilePath);
		if (file->open(QIODevice::WriteOnly))
		{
			accessManager = new QNetworkAccessManager(this);
			mReply = accessManager->get(QNetworkRequest(url));
			connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
			connect(mReply, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
			connect(mReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));
		}
		else
		{
			return false;
		}
		return true;
	}

	void HttpDownLoadFile::replyFinished(QNetworkReply* reply)
	{
		if (file)
		{
			file->flush();
			file->close();
			file = NULL;
			delete file;
		}
		if (reply->error() == QNetworkReply::NoError)
		{
			mReply->deleteLater();
			mReply = NULL;
			emit sigDownFinished(true);
		}
		else
		{
			reply->deleteLater();
			reply = NULL;
			emit sigDownFinished(false);
		}
	}

	void HttpDownLoadFile::onDownloadProgress(qint64 bytesSent, qint64 bytesTotal)
	{
		emit sigDownloadProgress(bytesSent, bytesTotal);
	}

	void HttpDownLoadFile::slotLoadorDownLoadCancle()
	{
		if (mReply != NULL)
		{
			if (!mReply->isFinished())
			{
				mReply->abort();
			}
			mReply->deleteLater();
		}
		if (file)
		{
			file->flush();
			file->close();
			file = NULL;
			delete file;
		}
		emit sigDownloadProgress(0, 0); 
	}

	void HttpDownLoadFile::onReadyRead()
	{
		if (file)
		{
			file->write(mReply->readAll());
			file->flush();
		}
	}

	/*************************************************文件上传类***************************************/
	HttpUpLoadFile::HttpUpLoadFile(QObject *parent)
		: QObject(parent)
	{
		mReply = NULL;
	}
	HttpUpLoadFile::~HttpUpLoadFile()
	{
		if (mReply != NULL)
		{
			if (!mReply->isFinished())
			{
				mReply->abort();
			}
			mReply->deleteLater();
		}
	}

	void HttpUpLoadFile::StartUpLoadFile(QString strUrl, QString filePath, QVariantMap paramMap)
	{
		QString crlf = "\r\n";
		qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
		QString b = QVariant(qrand()).toString() + QVariant(qrand()).toString() + QVariant(qrand()).toString();
		QString boundary = "---------------------------" + b;
		QString endBoundary = crlf + "--" + boundary + "--" + crlf;
		QString contentType = "multipart/form-data; boundary=" + boundary;
		boundary = "--" + boundary + crlf;
		QByteArray bond = boundary.toLatin1();
		QByteArray send;

		QVariantMap::iterator it; //遍历map
		for (it = paramMap.begin(); it != paramMap.end(); ++it)
		{
			send.append(bond);
			if (it == paramMap.begin())
				boundary = crlf + boundary;
			bond = boundary.toLatin1();
			QString keys = QString("Content-Disposition: form-data; name=\"%1\"").arg(it.key()) + crlf;

			send.append(keys.toLatin1());
			send.append(QString("Content-Transfer-Encoding: 8bit" + crlf).toLatin1());
			send.append(crlf.toLatin1());
			send.append(it.value().toString().toUtf8());
		}

		QFile upFile(filePath);
		QByteArray fdata;
		if (!upFile.open(QIODevice::ReadOnly))
		{
			qDebug() << QStringLiteral("Erro: StartUpLoadFile File Open erro!");
		}
		fdata = upFile.readAll();
		upFile.close();

		send.append(bond);
		send.append(QString("Content-Disposition: form-data; name=\"file\"; filename=\"" + upFile.fileName() + "\"" + crlf).toLatin1());
		send.append(QString("Content-Transfer-Encoding: 8bit" + crlf).toLatin1());
		send.append(crlf.toLatin1());
		send.append(fdata);
		send.append(endBoundary.toLatin1());

		QNetworkRequest request;
		strUrl.replace(":80", "");
		request.setUrl(strUrl); //地址信息
		if (strUrl.toLower().startsWith("https"))//https请求，需ssl支持(下载openssl拷贝libeay32.dll和ssleay32.dll文件至Qt bin目录或程序运行目录)
		{
			QSslConfiguration sslConfig;
			sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
			sslConfig.setProtocol(QSsl::TlsV1_1);
			request.setSslConfiguration(sslConfig);
		}
		request.setHeader(QNetworkRequest::ContentTypeHeader, contentType.toLatin1());
		request.setRawHeader("UploadType", "COMM");
		request.setHeader(QNetworkRequest::ContentLengthHeader, QVariant(send.size()).toString());

		QNetworkAccessManager *accessManager = new QNetworkAccessManager(this);
		mReply = accessManager->post(request, send);
		connect(accessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
		connect(mReply, SIGNAL(uploadProgress(qint64, qint64)), this, SLOT(OnUploadProgress(qint64, qint64)));
	}

	void HttpUpLoadFile::replyFinished(QNetworkReply* reply)
	{
		if (mReply->error() == QNetworkReply::NoError)
		{
			QByteArray resultContent = reply->readAll();
			emit sigUpLoadFinished(true,resultContent);
		}
		else
			emit sigUpLoadFinished(false, "");
		mReply->deleteLater();
		mReply = NULL;
	}

	void HttpUpLoadFile::OnUploadProgress(qint64 bytesSent, qint64 bytesTotal)
	{
		emit sigUpLoadProgress(bytesSent, bytesTotal);
	}

	void HttpUpLoadFile::slotLoadorDownLoadCancle()
	{
		if (mReply != NULL)
		{
			if (!mReply->isFinished())
			{
				mReply->abort();
			}
			mReply->deleteLater();
		}
		emit sigUpLoadProgress(0, 0);
	}
}

