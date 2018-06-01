#include "transferwidget.h"

TransferWidget::TransferWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.transBtn, SIGNAL(clicked(bool)), this, SLOT(slotClickTransBtn()));

	ui.valueEdit->setValidator(new QDoubleValidator(0, 10000, 8, this));
}

TransferWidget::~TransferWidget()
{
}

void TransferWidget::setAddress(QString address)
{
	QString left = address.left(6);
	QString right = address.right(4);
	ui.turnOutLabel->setText(left + "******" + right);
}

void TransferWidget::setEnergySum(QString energy)
{
	ui.energyLabel->setText(energy);
}

void TransferWidget::setPassWord(QString password)
{
	this->password = password;
}

void TransferWidget::slotClickTransBtn()
{
	QString otherID = ui.IDEdit->text();
	QString toAddress = ui.addressEdit->text();
	QString value = ui.valueEdit->text();

	if (otherID.isEmpty() || toAddress.isEmpty() || value.isEmpty())
		IMessageBox::tip(NULL, QStringLiteral("注意"), QStringLiteral("输入不能为空"));
	else
	{
		PasswordWidget *password = new PasswordWidget(this->password, this);
		connect(password, SIGNAL(sigPasswordTrue()), this, SLOT(slotTransfer()));
		password->show();
	}
	
}

void TransferWidget::slotTransfer()
{
	QString otherID = ui.IDEdit->text();
	QString toAddress = ui.addressEdit->text();
	QString value = ui.valueEdit->text();

	emit sigTransfer(otherID, toAddress, value);
}

void TransferWidget::slotClearText()
{
	ui.IDEdit->clear();
	ui.addressEdit->clear();
	ui.valueEdit->clear();
}




