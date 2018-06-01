#include "secretletterwidget.h"

SecretLetterWidget::SecretLetterWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Tool);
	setWindowModality(Qt::WindowModal);
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_TranslucentBackground);

	connect(ui.enterBtn, SIGNAL(clicked(bool)), this, SLOT(slotClickedEnterBtn()));
	connect(ui.closeBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

SecretLetterWidget::~SecretLetterWidget()
{
}

//鼠标事件的处理。
void SecretLetterWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //设置移动的原始位置。
	return QWidget::mousePressEvent(event);
}
void SecretLetterWidget::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void SecretLetterWidget::mouseMoveEvent(QMouseEvent *event)
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

void SecretLetterWidget::slotClickedEnterBtn()
{
	QString password = ui.passwordEdit->text();
	QString text = ui.letterEdit->toPlainText();

	if (password.isEmpty() || text.isEmpty())
		IMessageBox::tip(this, QStringLiteral("注意"), QStringLiteral("密码和密信都不能为空！"));
	else
	{
		emit sigSecretLetter(password, text);
		this->close();
	}
}