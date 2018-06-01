#include "scanloginwidget.h"
#include <QFile>

ScanLoginWidget::ScanLoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);    // 添加阴影时使用

	connect(ui.pushButtonLogin,SIGNAL(clicked()),this,SLOT(slotClickLogin()));

	OnInitStyleSheet();
}

ScanLoginWidget::~ScanLoginWidget()
{

}

// Qualifier: 初始化样式表
void ScanLoginWidget::OnInitStyleSheet()
{
	//加载样式
	QFile file(":/Login/Resources/QSS/loginScan.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

//Qualifier: 设置头像
void ScanLoginWidget::setHeaderImage(QString strHeaderPath)
{
	QFile file(strHeaderPath);
	if (file.size() == 0 || !file.exists())
	{
		strHeaderPath = QStringLiteral(":/PerChat/Resources/person/temp.png");
	}
	file.setFileName(strHeaderPath);
	if (file.open(QIODevice::ReadOnly))
	{
		QByteArray byteArray = file.readAll();
		QPixmap pix;
		pix.loadFromData(byteArray);

		ui.labelHeader->setAutoFillBackground(true);
		ui.labelHeader->setPixmap(pix);
		ui.labelHeader->setScaledContents(true);
	}
	file.close();
}

//Qualifier: 设置昵称
void ScanLoginWidget::setNikeName(QString strNikeName)
{
	ui.labelNikeName->setText(strNikeName);
}

//Qualifier: 点击登陆按钮
void ScanLoginWidget::slotClickLogin()
{
	emit sigTest();
}