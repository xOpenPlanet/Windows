#include "messagebox.h"

IMessageBox::IMessageBox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setContentsMargins(6, 6, 6, 6);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Tool);
	setWindowModality(Qt::WindowModal);
	setAttribute(Qt::WA_TranslucentBackground);
	setAttribute(Qt::WA_DeleteOnClose);

	connect(ui.closeBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(ui.enterBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

IMessageBox::~IMessageBox()
{
}

void IMessageBox::tip(QWidget *parent, QString title, QString text)
{
	IMessageBox *box = new IMessageBox(parent);
	box->init(title, text);
	box->show();
}

void IMessageBox::init(QString title, QString text)
{
	ui.titleLabel->setText(title);
	ui.tipLabel->setText(text);
}

//����¼��Ĵ���
void IMessageBox::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //�����ƶ���ԭʼλ�á�
	return QWidget::mousePressEvent(event);
}
void IMessageBox::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void IMessageBox::mouseMoveEvent(QMouseEvent *event)
{
	if (mouse.x() < 0)
		return;
	//����ͨ������ֵ��������λ�Ƶľ��롣
	int x = event->pos().x() - mouse.x();
	int y = event->pos().y() - mouse.y();
	//�ƶ������塣
	this->move(this->x() + x, this->y() + y);
	return QWidget::mouseMoveEvent(event);
}

//������Ӱ
void IMessageBox::paintEvent(QPaintEvent * event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(10, 10, this->width() - 20, this->height() - 20);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);//, 50);
	for (int i = 0; i < 10; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(10 - i, 10 - i, this->width() - (10 - i) * 2, this->height() - (10 - i) * 2);
		color.setAlpha(220 - qSqrt(i) * 67);
		painter.setPen(color);
		painter.drawPath(path);
	}
}
