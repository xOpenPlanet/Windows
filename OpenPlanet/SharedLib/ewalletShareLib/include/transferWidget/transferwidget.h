#pragma once

#include <QWidget>
#include "passwordwidget.h"
#include "ui_transferwidget.h"

class TransferWidget : public QWidget
{
	Q_OBJECT

public:
	TransferWidget(QWidget *parent = Q_NULLPTR);
	~TransferWidget();

	void setAddress(QString);
	void setEnergySum(QString);
	void setPassWord(QString);
	

signals:
	void sigTransfer(QString otherID, QString toAddress, QString value);

private slots:
    void slotClickTransBtn();

	void slotTransfer();

	void slotClearText();

private:
	Ui::TransferWidget ui;

	QString password;
};
