#pragma once

#include <QObject>
#include "qcefview.h"
#include "opdatamanager.h"
#include "oprequestsharelib.h"
#include "messagebox.h"
#include "detailswidget.h"

class TransferManager : public QObject
{
	Q_OBJECT

public:
	TransferManager(QObject *parent = NULL);
	~TransferManager();

	void setPrivateKey(QString);

	void turnOut(QString userID, QString otherID, QString fromAddress, QString toAddress, QString value);

private slots:
	void slotGetNonce(QString);
	
	void slotGetTransactionData(QString);

	void slotTransfer(bool, QVariant);

signals:
	void sigFinished();

private:
	QCefView *cefView;

	QString userID;
	QString otherID;
	QString fromAddress;
	QString toAddress;
	QString value;

	QString priKey;
};
