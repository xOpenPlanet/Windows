#include "qlabelheader.h"
#include <QPainter>

QLabelHeader::QLabelHeader(QWidget *parent)
	: QLabel(parent)
{

}

QLabelHeader::~QLabelHeader()
{

}

void QLabelHeader::paintEvent(QPaintEvent *e)
{
	if (NULL != pixmap())
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
		QPainterPath path;
		int round = qMin(width(), height());
		path.addEllipse(0, 0, round, round);
		painter.setClipPath(path);
		painter.drawPixmap(-1, -1, width() + 2, height() + 2, *pixmap());
	}
	else
	{
		QLabel::paintEvent(e);
	}
}