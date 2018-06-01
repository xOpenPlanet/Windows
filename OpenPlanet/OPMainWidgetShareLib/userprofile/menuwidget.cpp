#include "menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);

	this->setFocusPolicy(Qt::ClickFocus);

	connect(ui.profileBtn, SIGNAL(clicked(bool)), this, SIGNAL(sigUserProfile()));

	QFile file(":/qssWidget/Resources/qssWidget/menuwidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

MenuWidget::~MenuWidget()
{
}

void MenuWidget::focusOutEvent(QFocusEvent *e)
{
	QWidget::focusOutEvent(e);
	this->hide();
}

void MenuWidget::setUserInfo(QString nickName, QString sign)
{
	ui.profileBtn->setText(nickName);
	ui.signLabel->setText(sign);
}

void MenuWidget::slotClickedBtn()
{
	emit sigClickedMenuItem(QStringLiteral("Ç®°ü"));
}
