#include "changeintowidget.h"

ChangeIntoWidget::ChangeIntoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.codeLabel->setScaledContents(true);

	connect(ui.setNumBtn, SIGNAL(clicked(bool)), this, SLOT(slotSetNumWidget()));
}

ChangeIntoWidget::~ChangeIntoWidget()
{
}

void ChangeIntoWidget::setTurnInData(QString userID, QString address)
{
	this->userID = userID;
	this->address = address;

	slotSetImage("0");
}

void ChangeIntoWidget::slotSetImage(QString num)
{
	QVariantMap map;
	map.insert("type", "gathering");
	map.insert("userId", userID);
	map.insert("ethAddress", address);
	map.insert("money", num);

	QByteArray array = QJsonDocument::fromVariant(map).toJson();
	QString string = QString::fromUtf8(array);

	QRenCodeShareLib qr;
	QImage image = qr.GenerateQRcode(string);
	QPixmap pixmap = QPixmap::fromImage(image);

	ui.codeLabel->setPixmap(pixmap);
}

void ChangeIntoWidget::slotSetNumWidget()
{
	ChangeNumWidget *changeWidget = new ChangeNumWidget(this);
	connect(changeWidget, SIGNAL(sigChangeNum(QString)), this, SLOT(slotSetImage(QString)));
	changeWidget->show();
}