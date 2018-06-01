#include "scanshowqrwidget.h"
#include <QFile>
#include <QPixmap>

ScanShowQRWidget::ScanShowQRWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	OnInitStyleSheet();
}

ScanShowQRWidget::~ScanShowQRWidget()
{

}

// Qualifier: 初始化样式表
void ScanShowQRWidget::OnInitStyleSheet()
{
	//加载样式
	QFile file(":/Login/Resources/QSS/loginScanShowQR.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

void ScanShowQRWidget::showQR(QImage img)
{
	if (!img.isNull())
	{
		ui.labelQR->setAutoFillBackground(true);
		ui.labelQR->setPixmap(QPixmap::fromImage(img));
		ui.labelQR->setScaledContents(true);
	}
}

void ScanShowQRWidget::showErro(QString errorMsg)
{
	ui.labelTip->setStyleSheet("color:red");
	ui.labelTip->setText(errorMsg);
}