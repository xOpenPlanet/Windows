#include "basewindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QFile>

BaseWindow::BaseWindow(QWidget *parent)
: QWidget(parent)
{
	// FramelessWindowHint�������ô���ȥ���߿�;
	// WindowMinimizeButtonHint ���������ڴ�����С��ʱ��������������ڿ�����ʾ��ԭ����;
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	// ���ô��ڱ���͸��;
	setAttribute(Qt::WA_TranslucentBackground);
	// �رմ���ʱ�ͷ���Դ;
	//setAttribute(Qt::WA_DeleteOnClose);
	// ��ʼ��������;
	initTitleBar();
}

BaseWindow::~BaseWindow()
{

}

void BaseWindow::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);

	connect(m_titleBar, SIGNAL(sigButtonMinClicked()), this, SLOT(onButtonMinClicked()));
	connect(m_titleBar, SIGNAL(sigButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
	connect(m_titleBar, SIGNAL(sigButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
	connect(m_titleBar, SIGNAL(sigButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));

}

void BaseWindow::paintEvent(QPaintEvent* event)
{
	//���ñ���ɫ;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(237, 237, 237)));

	return QWidget::paintEvent(event);
}

void BaseWindow::loadStyleSheet(const QString &sheetName)
{
	QFile file(":/MyMessageBox/Resources/MyMessageBox/" + sheetName + ".css");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
		this->setStyleSheet(styleSheet);
	}
}

void BaseWindow::onButtonMinClicked()
{
	showMinimized();
}

void BaseWindow::onButtonRestoreClicked()
{
	QPoint windowPos;
	QSize windowSize;
	m_titleBar->getRestoreInfo(windowPos, windowSize);
	this->setGeometry(QRect(windowPos, windowSize));
	emit sigWindowsMax();
}

void BaseWindow::onButtonMaxClicked()
{
	m_titleBar->saveRestoreInfo(this->pos(), QSize(this->width(), this->height()));
	QRect desktopRect = QApplication::desktop()->availableGeometry();
	QRect FactRect = QRect(desktopRect.x() - 3, desktopRect.y() - 3, desktopRect.width() + 6, desktopRect.height() + 6);
	setGeometry(FactRect);

	emit sigWindowsMax();
}

void BaseWindow::onButtonCloseClicked()
{
	close();
}