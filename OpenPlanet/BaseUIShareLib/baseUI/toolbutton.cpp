#include "toolbutton.h"
#include <qdebug.h>

ToolButton::ToolButton(QWidget *parent)
	: QToolButton(parent)
{
	num = 0;
}

ToolButton::~ToolButton()
{

}

void ToolButton::slotSetNum(int n)
{
	num = n;
	update();
}

int ToolButton::getNum()
{
	return num;
}


void ToolButton::paintEvent(QPaintEvent *e)
{
	QToolButton::paintEvent(e);

	if (num > 0)
	{
		QPainter *painter = new QPainter(this);

		QString unReadString;
		if (num > 99)
			unReadString = "99";
		else
			unReadString = QString::number(num);

		painter->setBrush(Qt::red);
		painter->setPen(Qt::NoPen);
		painter->setRenderHint(QPainter::Antialiasing, true);
		painter->drawEllipse(width() / 2, 4, 16, 16);
		painter->setPen(Qt::white);
		if (num >= 10)
			painter->setFont(QFont("Microsoft YaHei", 7, QFont::Bold));
		else
			painter->setFont(QFont("Microsoft YaHei", 8, QFont::Bold));
		painter->drawText(width() / 2, 4, 16, 16, Qt::AlignCenter, unReadString);

		painter->end();
	}
}