#include "perprofilewidget.h"

perProfileWidget::perProfileWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QPixmap mask(":/profile/Resources/profile/profileMask.png");
	this->setMask(mask.mask());

	connect(ui.copyAddressBtn, SIGNAL(clicked(bool)), this, SLOT(slotCopyAddress()));
	connect(ui.perChatBtn, SIGNAL(clicked(bool)), this, SLOT(slotPerChat()));

	/*
	QFile file(":/qssWidget/Resources/qssWidget/perprofilewidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
	*/
}

perProfileWidget::~perProfileWidget()
{

}

void perProfileWidget::setBuddy(BuddyInfo buddy, AddressInfo wallet)
{
	buddyID = QString::number(buddy.nUserId);

	//先清空。
	ui.nameLabel->clear();
	ui.sexLabel->clear();
	ui.signLabel->clear();
	ui.lianxinLabel->clear();
	ui.addressLabel->clear();

	QPixmap pix(buddy.strLocalAvatar);
	if (pix.isNull())
	{
		QByteArray bytearray = "";
		QFile file(buddy.strLocalAvatar);
		if (file.open(QIODevice::ReadOnly) && file.size() != 0)
		{
			bytearray = file.readAll();
		}
		file.close();
		if (!pix.loadFromData(bytearray) || bytearray == "")
		{
			pix.load(":/PerChat/Resources/person/temp.png");
		}
	}

	pix = pix.scaled(ui.headerLabel->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

	ui.headerLabel->setPixmap(pix);

	if (buddy.strSex == "F")
		ui.sexLabel->setPixmap(QPixmap(":/profile/Resources/profile/female.png"));
	if (buddy.strSex == "M")
		ui.sexLabel->setPixmap(QPixmap(":/profile/Resources/profile/male.png"));

	ui.signLabel->setText(buddy.strSign);
	ui.nameLabel->setText(buddy.strNickName);
	ui.lianxinLabel->setText(QString::number(buddy.nUserId));

	if (!wallet.ethAddress.isEmpty())
	{
		ui.addressLabel->setObjectName(wallet.ethAddress);
		ui.addressLabel->setText(wallet.ethAddress.left(6) + "******" + wallet.ethAddress.right(4));

		setStar("mars");
	}
}

void perProfileWidget::slotPerChat()
{
	emit sigPerChat(OpenPer, QVariant::fromValue(buddyID));
}

void perProfileWidget::slotCopyAddress()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(ui.addressLabel->objectName());
}

void perProfileWidget::setStar(QString star)
{
	//绘制星球球体。
	QPixmap background(":/ewallet/Resources/ewallet/background.png");
	background = background.scaled(ui.starLabel->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

	QString starPath = ":/star/Resources/walletStar/" + star + ".png";
	QPixmap starImage(starPath);
	starImage = starImage.scaledToWidth(ui.starLabel->width() * 2, Qt::SmoothTransformation);
	starImage = starImage.copy(ui.starLabel->width() / 2, ui.starLabel->height() / 4, ui.starLabel->width(), ui.starLabel->height());

	QPixmap background1(":/ewallet/Resources/ewallet/background1.png");
	background1 = background1.scaledToWidth(ui.starLabel->width() * 2, Qt::SmoothTransformation);
	background1 = background1.copy(ui.starLabel->width() / 2, 0, ui.starLabel->width(), ui.starLabel->height());

	QPixmap background2(":/ewallet/Resources/ewallet/background2.png");
	background2 = background2.scaledToWidth(ui.starLabel->width() * 2, Qt::SmoothTransformation);
	background2 = background2.copy(ui.starLabel->width() / 2, ui.starLabel->height() / 4, ui.starLabel->width(), ui.starLabel->height());

	QPainter *painter = new QPainter;
	painter->begin(&background);
	painter->drawPixmap(0, 0, starImage);
	painter->drawPixmap(0, 0, background1);
	painter->drawPixmap(0, 0, background2);
	painter->end();
	
	ui.starLabel->setPixmap(background);
}

