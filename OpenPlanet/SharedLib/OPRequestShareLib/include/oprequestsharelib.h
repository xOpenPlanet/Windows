#ifndef OPREQUESTSHARELIB_H
#define OPREQUESTSHARELIB_H

#include <QObject>
#include <QJsonDocument>
#include <QDomDocument>
#include <QDir>
#include <QFile>
#include "httpnetworksharelib.h"

class OPRequestShareLib : public QObject
{
	Q_OBJECT
public:
	OPRequestShareLib();
	~OPRequestShareLib();

	void getIntegral(QString token);
	void getBalance(QString address);

	void getBaseBuddyInfo(QString token);

	void getNonce(QString address);
	void sendRawTransaction(QString fromID, QString toID,
		QString fromAddress, QString toAddress,
		QString value, QString transactionData);

signals:
	void sigIntegral(QString);
	void sigBalance(QString);

	void sigBaseBuddyInfo(QString);

	void sigNonce(QString);
	void sigTransfer(bool, QVariant);

private slots:
	void slotIntegralResult(bool, QString);
	void slotBalanceResult(bool, QString);

	void slotBaseBuddyInfo(bool, QString);

	void slotGetNonce(bool, QString);
	void slotTransfer(bool, QString);

private:
	void initConfig();

private:
	QString tcserver;
};

#endif // OPREQUESTSHARELIB_H
