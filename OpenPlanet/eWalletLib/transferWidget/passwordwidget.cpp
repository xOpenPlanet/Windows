#include "passwordwidget.h"

PasswordWidget::PasswordWidget(QString password, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::Tool);
	setWindowModality(Qt::WindowModal);
	setAttribute(Qt::WA_DeleteOnClose);
	setAttribute(Qt::WA_TranslucentBackground);

	this->password = password;

	connect(ui.enterBtn, SIGNAL(clicked(bool)), this, SLOT(slotClickedEnterBtn()));
	connect(ui.closeBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
}

PasswordWidget::~PasswordWidget()
{
}

//鼠标事件的处理。
void PasswordWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //设置移动的原始位置。
	return QWidget::mousePressEvent(event);
}
void PasswordWidget::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void PasswordWidget::mouseMoveEvent(QMouseEvent *event)
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

void PasswordWidget::slotClickedEnterBtn()
{
	QString text = ui.lineEdit->text();
	if (text.isEmpty())
	{
		IMessageBox::tip(NULL, QStringLiteral("注意"), QStringLiteral("密码不能为空！"));
	}
	else
	{
		QByteArray array = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha1);
		QString string = array.toHex();

		if (string.toLower() != password.toLower())
			IMessageBox::tip(NULL, QStringLiteral("注意"), QStringLiteral("密码错误！"));
		else
		{
			emit sigPasswordTrue();
			close();
		}
	}
}
