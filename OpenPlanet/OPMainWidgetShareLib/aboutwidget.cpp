#include "aboutwidget.h"

AboutWidget::AboutWidget(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	connect(ui.closeBtn, SIGNAL(clicked(bool)), this, SLOT(close()));

	QFile file(":/qssWidget/Resources/qssWidget/aboutwidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

AboutWidget::~AboutWidget()
{

}

void AboutWidget::setName(QString name)
{
	ui.nameLabel->setText(name);
}


void AboutWidget::setNumber(QString number)
{
	ui.numberLabel->setText(number);
}

//����¼��Ĵ���
void AboutWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //�����ƶ���ԭʼλ�á�
	return QWidget::mousePressEvent(event);
}
void AboutWidget::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void AboutWidget::mouseMoveEvent(QMouseEvent *event)
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

