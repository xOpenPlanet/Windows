#include "scanloginwidget.h"
#include <QFile>

ScanLoginWidget::ScanLoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//�����ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);    // �����Ӱʱʹ��

	connect(ui.pushButtonLogin,SIGNAL(clicked()),this,SLOT(slotClickLogin()));

	OnInitStyleSheet();
}

ScanLoginWidget::~ScanLoginWidget()
{

}

// Qualifier: ��ʼ����ʽ��
void ScanLoginWidget::OnInitStyleSheet()
{
	//������ʽ
	QFile file(":/Login/Resources/QSS/loginScan.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

//Qualifier: ����ͷ��
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

//Qualifier: �����ǳ�
void ScanLoginWidget::setNikeName(QString strNikeName)
{
	ui.labelNikeName->setText(strNikeName);
}

//Qualifier: �����½��ť
void ScanLoginWidget::slotClickLogin()
{
	emit sigTest();
}