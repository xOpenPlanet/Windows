#include "scanqrwidget.h"
#include <QPainter>
#include <QtMath>
#include <QFile>
#include "qrencodesharelib.h"

ScanQRWidget::ScanQRWidget(QWidget *parent)
: QWidget(parent), pShowQRWidget(NULL), pScanLoginWidget(NULL), pScanNetWorkSetWidget(NULL)
{
	ui.setupUi(this);
	//设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);    // 添加阴影时使用
	OnInitStyleSheet();
	OnInit();
}

ScanQRWidget::~ScanQRWidget()
{
	if (pShowQRWidget)
	{
		pShowQRWidget->deleteLater();
		pShowQRWidget = NULL;
	}
	if (pScanLoginWidget)
	{
		pScanLoginWidget->deleteLater();
		pScanLoginWidget = NULL;
	}
}

void ScanQRWidget::mousePressEvent(QMouseEvent *event)
{
	mMoveing = true;
	mMovePosition = event->globalPos() - pos();
	return QWidget::mousePressEvent(event);
}

void ScanQRWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (mMoveing && (event->buttons() && Qt::LeftButton)
		&& (event->globalPos() - mMovePosition).manhattanLength() > QApplication::startDragDistance())
	{
		move(event->globalPos() - mMovePosition);
		mMovePosition = event->globalPos() - pos();
	}
	return QWidget::mouseMoveEvent(event);
}

void ScanQRWidget::mouseReleaseEvent(QMouseEvent *event)
{
	mMoveing = false;
	return QWidget::mouseReleaseEvent(event);
}

// Qualifier: 初始化样式表
void ScanQRWidget::OnInitStyleSheet()
{
	//加载样式
	QFile file(":/Login/Resources/QSS/login.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

// Qualifier: 初始化
void ScanQRWidget::OnInit()
{
	//connect(ui.pushButtonSetUser,SIGNAL(clicked()),this,SLOT(slotClickSetUser()));
	connect(ui.pushButtonSet, SIGNAL(clicked()), this, SLOT(slotClickSet()));
	connect(ui.pushButtonClose, SIGNAL(clicked()), this, SLOT(slotClickClose()));

	if (pShowQRWidget == NULL)
	{
		pShowQRWidget = new ScanShowQRWidget;
	}
	ui.stackedWidget->addWidget(pShowQRWidget);

	/*if (pScanLoginWidget == NULL)
	{
		pScanLoginWidget = new ScanLoginWidget;
		connect(pScanLoginWidget, SIGNAL(sigTest()), this, SIGNAL(sigClickedLogin()));
	}
	ui.stackedWidget->addWidget(pScanLoginWidget);*/

	if (pScanNetWorkSetWidget == NULL)
	{
		pScanNetWorkSetWidget = new ScanNetWorkSetWidget;
	}
	ui.stackedWidget->addWidget(pScanNetWorkSetWidget);
}

//设置用户
void ScanQRWidget::slotClickSetUser()
{
	/*if (mUserInfo.nUserID != -1)
	{
		ui.stackedWidget->setCurrentIndex(1);
	}
	else
	{*/
		ui.stackedWidget->setCurrentIndex(0);
	//}
}

//设置
void ScanQRWidget::slotClickSet()
{
	if (ui.stackedWidget->currentIndex() == 1)
		ui.stackedWidget->setCurrentIndex(0);
	else
	{
		ui.stackedWidget->setCurrentIndex(1);
	}
}

//关闭
void ScanQRWidget::slotClickClose()
{
	emit sigCloseLoginWidget();
}

/*显示二维码窗口*/
void ScanQRWidget::showQrWidget()
{
	ThreadPoll *pThreadPoll = new ThreadPoll(this);
	connect(pThreadPoll, SIGNAL(finished()), pThreadPoll,SLOT(deleteLater()));
	connect(pThreadPoll, SIGNAL(sigCreateQR(QString)), this, SLOT(slotCreateQR(QString)));
	connect(pThreadPoll, SIGNAL(sigLoginSuccess(QVariantMap)), this, SIGNAL(sigQRLoginSuccess(QVariantMap)));
	pThreadPoll->start();
}

/*显示用户窗口
void ScanQRWidget::showUserWidget(UserInfo userInfo)
{
	mUserInfo = userInfo;
	ui.stackedWidget->setCurrentIndex(1);
	this->show();
}*/

/*创建二维码*/
void ScanQRWidget::slotCreateQR(QString strContent)
{
	QRenCodeShareLib qr;
	QImage img = qr.GenerateQRcode(strContent);
	if (pShowQRWidget)
	{
		pShowQRWidget->showQR(img);
	}
	this->show();
}

void ScanQRWidget::showErro(QString strMsg)
{
	if (pShowQRWidget)
	{
		pShowQRWidget->showErro(strMsg);
		showQrWidget();
	}
}