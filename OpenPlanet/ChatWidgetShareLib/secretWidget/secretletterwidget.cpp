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

//����¼��Ĵ���
void SecretLetterWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //�����ƶ���ԭʼλ�á�
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
	//����ͨ������ֵ��������λ�Ƶľ��롣
	int x = event->pos().x() - mouse.x();
	int y = event->pos().y() - mouse.y();
	//�ƶ������塣
	this->move(this->x() + x, this->y() + y);
	return QWidget::mouseMoveEvent(event);
}

void SecretLetterWidget::slotClickedEnterBtn()
{
	QString password = ui.passwordEdit->text();
	QString text = ui.letterEdit->toPlainText();

	if (password.isEmpty() || text.isEmpty())
		IMessageBox::tip(this, QStringLiteral("ע��"), QStringLiteral("��������Ŷ�����Ϊ�գ�"));
	else
	{
		emit sigSecretLetter(password, text);
		this->close();
	}
}