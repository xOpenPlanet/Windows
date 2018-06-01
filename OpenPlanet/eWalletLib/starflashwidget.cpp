#include "starflashwidget.h"

StarFlashWidget::StarFlashWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.copyBtn, SIGNAL(clicked()), this, SLOT(slotClickCopy()));

	ui.refreshLabel->setPixmap(QPixmap(":/GroupChat/Resources/groupchat/refresh.png"));

	refreshGif = new QMovie;
	refreshGif->setFileName(":/GroupChat/Resources/groupchat/refresh.gif");
	refreshGif->setScaledSize(ui.refreshLabel->size());

	ui.refreshLabel->installEventFilter(this);
	ui.tipLabel->hide();
}

StarFlashWidget::~StarFlashWidget()
{

}

bool StarFlashWidget::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui.refreshLabel && event->type() == QEvent::MouseButtonPress)
	{
		ui.refreshLabel->setMovie(refreshGif);
		refreshGif->start();

		emit sigRefreshWallet();
	}

	return QWidget::eventFilter(obj, event);
}

void StarFlashWidget::paintEvent(QPaintEvent * event)
{
	if (!starImage.isNull())
	{
		QPainter *painter = new QPainter;
		painter->begin(this);
		painter->drawImage(0, 0, starImage);
		painter->end();
	}
	
	QWidget::paintEvent(event);
}


void StarFlashWidget::slotClickCopy()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(this->objectName());

	if (ui.tipLabel->isHidden())
	{
		ui.tipLabel->show();
		QTimer::singleShot(2000, ui.tipLabel, SLOT(hide()));
	}
}

void StarFlashWidget::setAccount(QString account)
{
	ui.accountLabel->setText(account);
}

void StarFlashWidget::setId(QString id)
{
	ui.idLabel->setText(QStringLiteral("ÐÇ¼ÊID ") + id);
}

void StarFlashWidget::setAddress(QString address)
{
	QString left = address.left(6);
	QString right = address.right(4);

	this->setObjectName(address);
	ui.addressLabel->setText(QStringLiteral("»ùµØID ") + left + "******" + right);
}

void StarFlashWidget::setStar(QString star)
{
	this->starImagePath = ":/star/Resources/walletStar/" + star + ".png";
	starImage.load(starImagePath);
	starImage = starImage.scaledToWidth(this->width()*2, Qt::SmoothTransformation);
	starImage = starImage.copy(this->width()/2, 0, this->width(), this->height());

	QPixmap background1(":/ewallet/Resources/ewallet/background1.png");
	background1 = background1.scaledToWidth(this->width() * 2, Qt::SmoothTransformation);
	background1 = background1.copy(this->width() / 2, 0, this->width(), this->height());

	QPixmap background2(":/ewallet/Resources/ewallet/background2.png");
	background2 = background2.scaledToWidth(this->width() * 2, Qt::SmoothTransformation);
	background2 = background2.copy(this->width() / 2, 0, this->width(), this->height());

	QPainter *painter = new QPainter;
	painter->begin(&starImage);
	painter->drawPixmap(0, 0, background1);
	painter->drawPixmap(0, 0, background2);
	painter->end();
}

void StarFlashWidget::addBuddysNum(int num)
{
	int sum = ui.buddysLabel->text().toInt() + num;
	ui.buddysLabel->setText(QString::number(sum));
}

void StarFlashWidget::addGroupsNum(int num)
{
	int sum = ui.groupsLabel->text().toInt() + num;
	ui.groupsLabel->setText(QString::number(sum));
}

QString StarFlashWidget::getId()
{
	QStringList list = ui.idLabel->text().split(" ");

	if (list.count() == 2)
	    return list.at(1);
	else
	{
		return "";
	}
}

void StarFlashWidget::stopRefreshGif()
{
	refreshGif->stop();

	ui.refreshLabel->setPixmap(QPixmap(":/GroupChat/Resources/groupchat/refresh.png"));
}


