#include "scanqrwidget.h"
#include <QPainter>
#include <QtMath>
#include <QFile>
#include "qrencodesharelib.h"

ScanQRWidget::ScanQRWidget(QWidget *parent)
: QWidget(parent), pShowQRWidget(NULL), pScanLoginWidget(NULL), pScanNetWorkSetWidget(NULL)
{
	ui.setupUi(this);
	//�����ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);    // �����Ӱʱʹ��
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

// Qualifier: ��ʼ����ʽ��
void ScanQRWidget::OnInitStyleSheet()
{
	//������ʽ
	QFile file(":/Login/Resources/QSS/login.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

// Qualifier: ��ʼ��
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

//�����û�
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

//����
void ScanQRWidget::slotClickSet()
{
	if (ui.stackedWidget->currentIndex() == 1)
		ui.stackedWidget->setCurrentIndex(0);
	else
	{
		ui.stackedWidget->setCurrentIndex(1);
	}
}

//�ر�
void ScanQRWidget::slotClickClose()
{
	emit sigCloseLoginWidget();
}

/*��ʾ��ά�봰��*/
void ScanQRWidget::showQrWidget()
{
	ThreadPoll *pThreadPoll = new ThreadPoll(this);
	connect(pThreadPoll, SIGNAL(finished()), pThreadPoll,SLOT(deleteLater()));
	connect(pThreadPoll, SIGNAL(sigCreateQR(QString)), this, SLOT(slotCreateQR(QString)));
	connect(pThreadPoll, SIGNAL(sigLoginSuccess(QVariantMap)), this, SIGNAL(sigQRLoginSuccess(QVariantMap)));
	pThreadPoll->start();
}

/*��ʾ�û�����
void ScanQRWidget::showUserWidget(UserInfo userInfo)
{
	mUserInfo = userInfo;
	ui.stackedWidget->setCurrentIndex(1);
	this->show();
}*/

/*������ά��*/
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