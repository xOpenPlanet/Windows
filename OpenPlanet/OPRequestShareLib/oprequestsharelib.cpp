#include "oprequestsharelib.h"

OPRequestShareLib::OPRequestShareLib()
{
	initConfig();
}

OPRequestShareLib::~OPRequestShareLib()
{

}

void OPRequestShareLib::initConfig()
{
	QDomDocument doc(QStringLiteral("config"));
	QFile file("./config/walletConfig.xml");
	if (file.open(QIODevice::ReadOnly))
	{
		if (doc.setContent(&file))
		{
			QDomElement docElem = doc.documentElement();
			QDomNode n = docElem.firstChild();
			while (!n.isNull())
			{
				QDomElement e = n.toElement();
				if (!e.isNull())
				{
					if (e.tagName() == "tcserver")
					{
						tcserver = e.text();
					}
				}

				n = n.nextSibling();
			}
		}
		file.close();
	}
}

void OPRequestShareLib::getIntegral(QString token)
{
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib();
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotIntegralResult(bool, QString)));
	QString strRequest = tcserver + "/integral/integralTotal?access_token=" + token;
	http->getHttpRequest(strRequest);
}

void OPRequestShareLib::slotIntegralResult(bool success, QString result)
{
	if (success)
	{
		QJsonDocument doc = QJsonDocument::fromJson(result.toUtf8());
		QVariantMap map = doc.toVariant().toMap();
		int integralTotal = map.value("integralTotal").toInt();

		emit sigIntegral(QString::number(integralTotal));
	}
}

void OPRequestShareLib::getBalance(QString address)
{
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib();
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotBalanceResult(bool, QString)));
	QString strRequest = tcserver + "/eth/ethGetBalance?ethAddress=" + address;
	http->getHttpRequest(strRequest);
}

void OPRequestShareLib::slotBalanceResult(bool success, QString result)
{
	if (success)
	{
		QJsonDocument doc = QJsonDocument::fromJson(result.toUtf8());
		QVariantMap map = doc.toVariant().toMap();
		double num = map.value("balance").toDouble();
		QString balance;
		if (num == 0)
			balance = "0";
		else
		{;
		    long double b = (long double)num / (long double)1000000000000000000;
			balance = QString::number((double)b, 'f', 8);
		}

		emit sigBalance(balance);
	}
}

void OPRequestShareLib::getBaseBuddyInfo(QString token)
{
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib();
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotBaseBuddyInfo(bool, QString)));
	QString strRequest = tcserver + "/user/friendAddressList?access_token=" + token;
	http->getHttpRequest(strRequest);
}

void OPRequestShareLib::slotBaseBuddyInfo(bool success, QString result)
{
	if (success)
	{
		emit sigBaseBuddyInfo(result);
	}
}

void OPRequestShareLib::getNonce(QString address)
{
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib();
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotGetNonce(bool, QString)));
	QString strRequest = tcserver + "/eth/ethGetTransactionCount?ethAddress=" + address;
	http->getHttpRequest(strRequest);
}

void OPRequestShareLib::slotGetNonce(bool success, QString result)
{
	if (success)
	{
		QJsonDocument doc = QJsonDocument::fromJson(result.toUtf8());
		QVariantMap map = doc.toVariant().toMap();
		if (map.value("result").toString() == "success")
		{
			int num = map.value("transactionCount").toInt();

			emit sigNonce(QString::number(num));
			return;
		}
	}

	emit sigNonce("error");
}

void OPRequestShareLib::sendRawTransaction(QString fromID, QString toID, QString fromAddress, QString toAddress, QString value, QString transactionData)
{
	qDebug() << "sendRawTransaction";
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib();
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(slotTransfer(bool, QString)));
	QString strRequest = tcserver + "/eth/ethSendRawTransaction?" +
		QString("fromUserId=%1&toUserId=%2&fromEthAddress=%3&toEthAddress=%4&value=%5&signedTransactionData=%6")
		.arg(fromID).arg(toID).arg(fromAddress).arg(toAddress).arg(value).arg(transactionData);
	http->getHttpRequest(strRequest);
}

void OPRequestShareLib::slotTransfer(bool success, QString result)
{
	qDebug() << "slotTransfer";
	QString error = QStringLiteral("ÍøÂçÁ¬½ÓÊ§°Ü!");

	if (success)
	{
		QJsonDocument doc = QJsonDocument::fromJson(result.toUtf8());
		QVariantMap map = doc.toVariant().toMap();

		if (map.value("result").toString() == "success")
		{
			emit sigTransfer(true, QVariant(map));
			return;
		}
		else
			error = QStringLiteral("·þÎñÆ÷·µ»Ø´íÎó£¡");

	}

	emit sigTransfer(false, QVariant(error));
}


