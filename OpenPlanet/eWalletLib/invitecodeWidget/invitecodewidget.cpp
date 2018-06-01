#include "invitecodewidget.h"

InviteCodeWidget::InviteCodeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.imageLabel->setScaledContents(true);
	connect(ui.copyBtn, SIGNAL(clicked()), this, SLOT(slotCopyCode()));

	setImage();

	copyLabel = new QLabel();
	copyLabel->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
	copyLabel->setFixedSize(58, 22);
	//copyLabel->setAttribute(Qt::WA_TranslucentBackground);
	copyLabel->setText(QStringLiteral("¸´ÖÆ³É¹¦"));
	copyLabel->setFont(QFont("Microsoft YaHei"));
	copyLabel->setObjectName("copyLabel");
	copyLabel->setStyleSheet("QLabel#copyLabel"
		"{"
		"color: #44608a;"
		"border-image: url(:/ewallet/Resources/ewallet/copyTip.png);"
		"padding: 0px 2px 0px 2px;"
		"}");
	
	copyLabel->hide();
}

InviteCodeWidget::~InviteCodeWidget()
{
}

void InviteCodeWidget::setInviteCode(QString code)
{
	ui.codeLabel->setText(code);
}

void InviteCodeWidget::setImage()
{
	QRenCodeShareLib qr;
	QImage img = qr.GenerateQRcode("https://mobile.solarsource.cn/ospstore/openplanet.html");

	QPixmap map = QPixmap::fromImage(img);
	ui.imageLabel->setPixmap(map);
}

void InviteCodeWidget::slotCopyCode()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(ui.codeLabel->text());

	if (copyLabel->isHidden())
	{
		copyLabel->move(this->cursor().pos() + QPoint(15,15));
		copyLabel->show();
		QTimer::singleShot(2000, copyLabel, SLOT(hide()));
	}
}
