#include "zoomimg.h"
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QFile>
#include <QMovie>
#include <QTextCodec>

ZoomImg::ZoomImg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	/*实现无边框可拖拽*/
	mMoveing = false;

	label = new QLabel(this);
	myButton = new QPushButton(this);
	myButton->setFixedSize(20, 20);
	myButton->setStyleSheet("QPushButton{border-image:url(:/PerChat/Resources/person/zoom-normal.png) 0 0 0 0 stretch stretch;}"
		"QPushButton:hover{border-image:url(:/PerChat/Resources/person/zoom-hover.png) 0 0 0 0 stretch stretch;}");
	connect(myButton, SIGNAL(clicked()),this, SLOT(close()));
	setWindowFlags(Qt::FramelessWindowHint);     //也是去掉标题栏的语句
	setAttribute(Qt::WA_DeleteOnClose, true);
}

ZoomImg::~ZoomImg()
{
	if (label)
		delete label;
	if (myButton)
		delete myButton;

}

void ZoomImg::mousePressEvent(QMouseEvent *event)
{
	mMoveing = true;
	mMovePosition = event->globalPos() - pos();
	return QWidget::mousePressEvent(event);
}

void ZoomImg::mouseMoveEvent(QMouseEvent *event)
{
	if (mMoveing && (event->buttons() && Qt::LeftButton)
		&& (event->globalPos() - mMovePosition).manhattanLength() > QApplication::startDragDistance())
	{
		move(event->globalPos() - mMovePosition);
		mMovePosition = event->globalPos() - pos();
	}
	return QWidget::mouseMoveEvent(event);
}

void ZoomImg::mouseReleaseEvent(QMouseEvent *event)
{
	mMoveing = false;
	return QWidget::mouseReleaseEvent(event);
}

QString ZoomImg::decodeURI(QString str)
{
	QByteArray array;
	for (int i = 0; i < str.length();) {
		if (0 == QString::compare(str.mid(i, 1), QString("%"))) {
			if ((i + 2) < str.length()) {
				array.append(str.mid(i + 1, 2).toShort(0, 16));
				i = i + 3;
			}
			else{
				array.append(str.mid(i, 1));
				i++;
			}
		}
		else{
			array.append(str.mid(i, 1));
			i++;
		}
	}
	QTextCodec *code = QTextCodec::codecForName("UTF-8");
	return code->toUnicode(array);
}

void ZoomImg::OpenImg(QString filePath)
{
	filePath = decodeURI(filePath);
	if (filePath != "")
	{
		QString str = filePath.mid(filePath.indexOf("."));

		QDesktopWidget *pDesk = QApplication::desktop();
		QByteArray arr;
		QFile file(filePath);
		if (file.open(QIODevice::ReadOnly))
		{
			arr = file.readAll();
		}
		file.close();

		QPixmap img;
		img.loadFromData(arr);

		int nheight = pDesk->height(), nwidth = pDesk->width();
		if (img.width() > nwidth && img.height() > nheight)
		{
			nheight = pDesk->height();
			nwidth = pDesk->width();
		}
		else if (img.width() > nwidth && img.height() < nheight)
		{
			nheight = img.height();
			nwidth = pDesk->width();
		}
		else if (img.width() < nwidth && img.height() > nheight)
		{
			nheight = pDesk->height();
			nwidth = img.width();
		}
		else{
			nheight = img.height();
			nwidth = img.width();
		}
		if (nwidth == 0 || nheight == 0)
		{
			nwidth = 480;
			nheight = 600;
		}
		this->label->resize(nwidth, nheight);
		this->resize(nwidth, nheight);
		this->label->setAutoFillBackground(true);

		if (str == ".gif")
		{
			QMovie *movie = new QMovie(filePath);
			this->label->setMovie(movie);
			movie->start();
		}
		else
		{
			this->label->setPixmap(img);
		}	
		this->label->setScaledContents(true);
		myButton->move(this->x() + this->width() - 20, this->y());
		myButton->show();
		this->show();
		this->move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);	
	}
}