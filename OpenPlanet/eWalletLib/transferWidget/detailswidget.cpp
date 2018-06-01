#include "detailswidget.h"

DetailsWidget::DetailsWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Tool);
	setWindowModality(Qt::WindowModal);
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_TranslucentBackground);

	connect(ui.closeBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(ui.enterBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

DetailsWidget::~DetailsWidget()
{
}

//鼠标事件的处理。
void DetailsWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //设置移动的原始位置。
	return QWidget::mousePressEvent(event);
}
void DetailsWidget::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void DetailsWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (mouse.x() < 0)
		return;
	//首先通过做差值，获得鼠标位移的距离。
	int x = event->pos().x() - mouse.x();
	int y = event->pos().y() - mouse.y();
	//移动本窗体。
	this->move(this->x() + x, this->y() + y);
	return QWidget::mouseMoveEvent(event);
}

void DetailsWidget::setData(QVariantMap map)
{
	ui.valueLabel->setText(map.value("value").toString());
	ui.IDEdit->setPlainText(map.value("transactionHash").toString());
	ui.timeLine->setText(map.value("time").toString());
	ui.turnOutEdit->setPlainText(map.value("turnOutAddress").toString());
	ui.turnInEdit->setPlainText(map.value("turnInAddress").toString());
}
