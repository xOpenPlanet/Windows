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

//����¼��Ĵ���
void PasswordWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //�����ƶ���ԭʼλ�á�
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
	//����ͨ������ֵ��������λ�Ƶľ��롣
	int x = event->pos().x() - mouse.x();
	int y = event->pos().y() - mouse.y();
	//�ƶ������塣
	this->move(this->x() + x, this->y() + y);
	return QWidget::mouseMoveEvent(event);
}

void PasswordWidget::slotClickedEnterBtn()
{
	QString text = ui.lineEdit->text();
	if (text.isEmpty())
	{
		IMessageBox::tip(NULL, QStringLiteral("ע��"), QStringLiteral("���벻��Ϊ�գ�"));
	}
	else
	{
		QByteArray array = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha1);
		QString string = array.toHex();

		if (string.toLower() != password.toLower())
			IMessageBox::tip(NULL, QStringLiteral("ע��"), QStringLiteral("�������"));
		else
		{
			emit sigPasswordTrue();
			close();
		}
	}
}
