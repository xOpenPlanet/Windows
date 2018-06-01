#include "ewalletwidget.h"

EWalletWidget::EWalletWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initGif();

	ui.turnInWidget->installEventFilter(this);
	ui.turnOutWidget->installEventFilter(this);
	ui.codeWidget->installEventFilter(this);
	ui.safeWidget->installEventFilter(this);

	intoWidget = new ChangeIntoWidget;
	transferWidget = new TransferWidget;
	inviteCodeWidget = new InviteCodeWidget;
	safeWidget = new SafeWidget;

	ui.stackedWidget->addWidget(intoWidget);
	ui.stackedWidget->addWidget(transferWidget);
	ui.stackedWidget->addWidget(inviteCodeWidget);
	ui.stackedWidget->addWidget(safeWidget);

	ui.stackedWidget->setCurrentIndex(0);
}

EWalletWidget::~EWalletWidget()
{
}

void EWalletWidget::initGif()
{
	ui.gifLabel->installEventFilter(this);

	gifState = FRONT;

	QMovie *gif = new QMovie;
	gif->setFileName(":/ewallet/Resources/ewallet/pwc_z.gif");
	gif->setScaledSize(ui.gifLabel->size());
	ui.gifLabel->setMovie(gif);
	gif->start();

	QMovie *silverDiamondGif = new QMovie;
	silverDiamondGif->setFileName(":/ewallet/Resources/ewallet/silverDiamond.gif");
	silverDiamondGif->setScaledSize(ui.silverDiamondLabel->size());
	ui.silverDiamondLabel->setMovie(silverDiamondGif);
	silverDiamondGif->start();

	QMovie *blackDiamondGif = new QMovie;
	blackDiamondGif->setFileName(":/ewallet/Resources/ewallet/blackDiamond.gif");
	blackDiamondGif->setScaledSize(ui.blackDiamondLabel->size());
	ui.blackDiamondLabel->setMovie(blackDiamondGif);
	blackDiamondGif->start();
}

bool EWalletWidget::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui.gifLabel && event->type() == QEvent::MouseButtonPress)
	{
		if (gifState == FRONT)
		{
			gifState = FRONTOBACK;

			QMovie *gif = new QMovie;
			gif->setFileName(":/ewallet/Resources/ewallet/frontoback.gif");
			gif->setScaledSize(ui.gifLabel->size());
			ui.gifLabel->setMovie(gif);
			gif->start();
			connect(gif, SIGNAL(finished()), this, SLOT(slotGifToBack()));
		}
		if (gifState == BACK)
		{
			gifState = BACKTOFRONT;

			QMovie *gif = new QMovie;
			gif->setFileName(":/ewallet/Resources/ewallet/backtofront.gif");
			gif->setScaledSize(ui.gifLabel->size());
			ui.gifLabel->setMovie(gif);
			gif->start();
			connect(gif, SIGNAL(finished()), this, SLOT(slotGifToFront()));
		}
	}

	if (obj == ui.codeWidget && event->type() == QEvent::MouseButtonPress)
		ui.stackedWidget->setCurrentWidget(inviteCodeWidget);
	if (obj == ui.turnOutWidget && event->type() == QEvent::MouseButtonPress)
		ui.stackedWidget->setCurrentWidget(transferWidget);
	if (obj == ui.turnInWidget && event->type() == QEvent::MouseButtonPress)
		ui.stackedWidget->setCurrentWidget(intoWidget);
	if (obj == ui.safeWidget && event->type() == QEvent::MouseButtonPress)
		ui.stackedWidget->setCurrentWidget(safeWidget);

	return QWidget::eventFilter(obj, event);
}

void EWalletWidget::slotGifToBack()
{
	gifState = BACK;
	QMovie *gif = new QMovie;
	gif->setFileName(":/ewallet/Resources/ewallet/pwc_f.gif");
	gif->setScaledSize(ui.gifLabel->size());
	ui.gifLabel->setMovie(gif);
	gif->start();
}

void EWalletWidget::slotGifToFront()
{
	gifState = FRONT;
	QMovie *gif = new QMovie;
	gif->setFileName(":/ewallet/Resources/ewallet/pwc_z.gif");
	gif->setScaledSize(ui.gifLabel->size());
	ui.gifLabel->setMovie(gif);
	gif->start();
}

StarFlashWidget * EWalletWidget::getStarWidget()
{
	return ui.starWidget;
}

ChangeIntoWidget * EWalletWidget::getIntoWidget()
{
	return intoWidget;
}

TransferWidget * EWalletWidget::getTransWidget()
{
	return transferWidget;
}

InviteCodeWidget * EWalletWidget::getInviteWidget()
{
	return inviteCodeWidget;
}

SafeWidget * EWalletWidget::getSafeWidget()
{
	return safeWidget;
}

void EWalletWidget::setEnergySum(QString energy)
{
	ui.energyLabel->setText(energy);
}

void EWalletWidget::setIntegral(QString integral)
{
	ui.silverCountLabel->setText(integral);
}






