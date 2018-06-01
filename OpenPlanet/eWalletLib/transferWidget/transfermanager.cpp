#include "transfermanager.h"

TransferManager::TransferManager(QObject *parent)
	: QObject(parent)
{
	cefView = new QCefView;
	cefView->hide();
	connect(cefView, SIGNAL(sigTransactionData(QString)), this, SLOT(slotGetTransactionData(QString)));
	cefView->InitCefUrl("file:///./html/wallet.html");
}

TransferManager::~TransferManager()
{
}

void TransferManager::setPrivateKey(QString priKey)
{
	this->priKey = priKey;
}

void TransferManager::turnOut(QString userID, QString otherID, QString fromAddress, QString toAddress, QString value)
{
	this->userID = userID;
	this->otherID = otherID;
	this->fromAddress = fromAddress;
	this->toAddress = toAddress;
	this->value = value;

	OPRequestShareLib *request = new OPRequestShareLib;
	connect(request, SIGNAL(sigNonce(QString)), this, SLOT(slotGetNonce(QString)));
	request->getNonce(fromAddress);
}

void TransferManager::slotGetNonce(QString nonce)
{
	if (nonce == "error")
	{
		IMessageBox::tip(NULL, QStringLiteral("交易失败"), QStringLiteral("获取Nonce时出错"));
		this->deleteLater();
	}
	else
	{
		cefView->ExecuteJavaScript(QString("GeneralSignTransaction(%1,%2,%3,\"%4\",%5,\"%6\")")
			.arg(nonce.toInt()).arg(18000000000).arg(21000)
			.arg(toAddress).arg(value.toDouble())
			.arg(priKey));
	}
}

void TransferManager::slotGetTransactionData(QString data)
{
	qDebug() << "slotGetTransactionData";
	QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
	QVariantMap map = doc.toVariant().toMap();

	if (map.value("result").toString() == "true")
	{
		QString transaction = map.value("SignTransaction").toString();
		OPRequestShareLib *http = new OPRequestShareLib;
		connect(http, SIGNAL(sigTransfer(bool, QVariant)), this, SLOT(slotTransfer(bool, QVariant)));
		http->sendRawTransaction(userID, otherID, fromAddress, toAddress, value, transaction);
	}
	if (map.value("result").toString() == "false")
	{
		IMessageBox::tip(NULL, QStringLiteral("交易失败"), QStringLiteral("无效的私钥"));
		this->deleteLater();
	}
}

void TransferManager::slotTransfer(bool success, QVariant var)
{
	if (success)
	{
		QVariantMap map = var.toMap();
		map.insert("value", value);
		map.insert("time", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
		map.insert("turnInAddress", toAddress);
		map.insert("turnOutAddress", fromAddress);

		DetailsWidget *detailWidget = new DetailsWidget(NULL);
		detailWidget->setData(map);
		detailWidget->show();

		emit sigFinished();
	}
	else
	{
		IMessageBox::tip(NULL, QStringLiteral("交易失败"), var.toString());
	}

	this->deleteLater();
}


