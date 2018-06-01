#include "scannetworksetwidget.h"
#include <QFile>
#include <QDebug>

ScanNetWorkSetWidget::ScanNetWorkSetWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);    // 添加阴影时使用

	OnInitStyleSheet();

	connect(ui.pushButtonConfirm,SIGNAL(clicked()),this,SLOT(slotConfirm()));
	connect(ui.radioButtonOn, SIGNAL(clicked(bool)), this, SLOT(slotPressRadioButtonON(bool)));
	connect(ui.radioButtonOff, SIGNAL(clicked(bool)), this, SLOT(slotPressRadioButtonOFF(bool)));

	ui.radioButtonOff->setChecked(true);

}

ScanNetWorkSetWidget::~ScanNetWorkSetWidget()
{

}

// Qualifier: 初始化样式表
void ScanNetWorkSetWidget::OnInitStyleSheet()
{
	//加载样式
	QFile file(":/Login/Resources/QSS/loginNetWorkSet.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

void ScanNetWorkSetWidget::slotConfirm()
{
	QString strAddress = ui.lineEditAddress->text();
	QString strPort = ui.lineEditPort->text();
	QString strAccount = ui.lineEditAccount->text();
	QString strPsw = ui.lineEditPsw->text();

	if (!strAddress.isEmpty() && !strPort.isEmpty())
	{
		
	}

}

void ScanNetWorkSetWidget::slotPressRadioButtonON(bool bCheck)
{
	EnableEdit(true);
}

void ScanNetWorkSetWidget::slotPressRadioButtonOFF(bool bCheck)
{
	EnableEdit(false);
}

void ScanNetWorkSetWidget::EnableEdit(bool bStatus)
{
	ui.lineEditAccount->setEnabled(bStatus);
	ui.lineEditAddress->setEnabled(bStatus);
	ui.lineEditPort->setEnabled(bStatus);
	ui.lineEditPsw->setEnabled(bStatus);
	ui.pushButtonConfirm->setEnabled(bStatus);
}