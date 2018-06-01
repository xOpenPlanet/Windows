#include "threadpoll.h"
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTimer>
#include <QJsonParseError>
#include <QJsonObject>
#include "common.h"
#include "define.h"

ThreadPoll::ThreadPoll(QObject *parent)
	: QThread(parent)
{
	mClientID = "a6f23fbb-0a1d-4e10-be7e-89181cdf089c";
	mbScanQr = false;
}

ThreadPoll::~ThreadPoll()
{

}

void ThreadPoll::RequestCodeID()
{
	QString strUrl = HTTP_GETSCANQRCODE + mClientID;
	QByteArray byteArray = RequestUrl(strUrl);
	mCodeID = ParseCodeID(byteArray);
}

void ThreadPoll::RequestCodeStatus()
{
	QString strUrl = HTTP_GETSCANQRSTATUS + mCodeID;
	QByteArray byteArray = RequestUrl(strUrl);
	ParseCodeStatus(byteArray);
}

QString ThreadPoll::GenerateQRJson()
{
	QJsonObject json;
	json.insert("type", "opLogin");
	json.insert("client_id", mClientID);
	json.insert("code", mCodeID);
	QString strJSON = QString(QJsonDocument(json).toJson());
	return strJSON;
}

QString ThreadPoll::ParseCodeID(QByteArray byteArray)
{
	QString codeID="";
	QJsonParseError jsonError;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(byteArray, &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QVariantMap result = jsonDocument.toVariant().toMap();
			if (result["result"].toString() == "success")
			{
				codeID = result["code"].toString();
			}
		}
	}
	return codeID;
}

void ThreadPoll::ParseCodeStatus(QByteArray byteArray)
{
	QJsonParseError jsonError;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(byteArray, &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QVariantMap result = jsonDocument.toVariant().toMap();
			if (result["result"].toString() == "success")
			{
				if (result["status"].toInt() == 0)         //二维码过期
				{
					mCodeID = "";
				}
				else if (result["status"].toInt() == 1)     //未扫码
				{
					mbScanQr = false;
				}
				else if (result["status"].toInt() == 2)    //扫码
				{
					resultMap = result;
					mbScanQr = true;
				}
			}
		}
	}
}

QByteArray ThreadPoll::RequestUrl(QString strUrl)
{
	QNetworkAccessManager m_qnam;
	const QUrl url = QUrl::fromUserInput(strUrl);
	QNetworkRequest qnr(url);
	QNetworkReply* reply = m_qnam.get(qnr); //m_qnam是QNetworkAccessManager对象
	QTimer timer;
	QEventLoop eventLoop;
	connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
	QObject::connect(&timer, SIGNAL(timeout()), &eventLoop, SLOT(quit()));
	timer.start(5000);
	eventLoop.exec();

	if (timer.isActive()){
		timer.stop();
	}

	QByteArray replyData = reply->readAll();
	reply->deleteLater();
	reply = nullptr;
	return replyData;
}

void ThreadPoll::run()
{
	while (1)
	{
		if (mCodeID.isEmpty())
		{
			RequestCodeID();
		}
		if (!mCodeID.isEmpty())
		{
			QString strQRJson = GenerateQRJson();
			emit sigCreateQR(strQRJson);
			RequestCodeStatus();
		}
		if (mbScanQr)
		{
			emit sigLoginSuccess(resultMap);
			break;
		}
		msleep(100);
	}
}
