#include "changenumwidget.h"

ChangeNumWidget::ChangeNumWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	setWindowModality(Qt::WindowModal);
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_TranslucentBackground);

	connect(ui.enterBtn, SIGNAL(clicked(bool)), this, SLOT(slotSetChangeNum()));

	ui.lineEdit->setValidator(new QDoubleValidator(0, 10000, 2, this));
}

ChangeNumWidget::~ChangeNumWidget()
{
}

//����¼��Ĵ���
void ChangeNumWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //�����ƶ���ԭʼλ�á�
	return QWidget::mousePressEvent(event);
}
void ChangeNumWidget::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void ChangeNumWidget::mouseMoveEvent(QMouseEvent *event)
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

void ChangeNumWidget::slotSetChangeNum()
{
	this->close();

	if (ui.lineEdit->text().isEmpty())
		emit sigChangeNum("0");
	else
	    emit sigChangeNum(ui.lineEdit->text());
}
