#include "userinfowidget.h"

UserInfoWidget::UserInfoWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setContentsMargins(6, 6, 6, 6);

	ui.titleWidget->installEventFilter(this);

	connect(ui.minBtn, SIGNAL(clicked(bool)), this, SLOT(showMinimized()));
	connect(ui.quitBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(ui.saveBtn, SIGNAL(clicked(bool)), this, SLOT(slotUserInfo()));
	connect(ui.closeBtn, SIGNAL(clicked(bool)), this, SLOT(close()));

	QFile file(":/qssWidget/Resources/qssWidget/userinfowidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

UserInfoWidget::~UserInfoWidget()
{
}

//绘制阴影
void UserInfoWidget::paintEvent(QPaintEvent * event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(6, 6, this->width() - 12, this->height() - 12);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);//, 50);
	for (int i = 0; i < 6; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(6 - i, 6 - i, this->width() - (6 - i) * 2, this->height() - (6 - i) * 2);
		color.setAlpha(110 - qSqrt(i) * 40);
		painter.setPen(color);
		painter.drawPath(path);
	}
}

bool UserInfoWidget::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == ui.titleWidget)
	{
		if (e->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			mouse = event->pos();   //设置移动的原始位置。
		}
		if (e->type() == QEvent::MouseMove)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			if (mouse.x() >= 0)
			{
				//首先通过做差值，获得鼠标位移的距离。
				int x = event->pos().x() - mouse.x();
				int y = event->pos().y() - mouse.y();
				//移动本窗体。
				this->move(this->x() + x, this->y() + y);
			}
		}
		if (e->type() == QEvent::MouseButtonRelease)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			mouse.setX(-1);
		}
	}

	return QWidget::eventFilter(obj, e);
}

void UserInfoWidget::setUserInfo(UserInfo userInfo)
{
	ui.nickNameEdit->setText(userInfo.strUserNickName);
	ui.signTextEdit->setPlainText(userInfo.strSign);
	ui.phoneEdit->setText(userInfo.strPhone);
	ui.mailEdit->setText(userInfo.strEmil);
	if (userInfo.strSex == "M")
		ui.sexComboBox->setCurrentText(QStringLiteral("男"));
	if (userInfo.strSex == "F")
		ui.sexComboBox->setCurrentText(QStringLiteral("女"));
}

void UserInfoWidget::slotUserInfo()
{
	UserInfo userInfo;
	userInfo.strUserNickName = ui.nickNameEdit->text();
	userInfo.strSign = ui.signTextEdit->toPlainText();
	userInfo.strPhone = ui.phoneEdit->text();
	userInfo.strEmil = ui.mailEdit->text();

	if (ui.sexComboBox->currentText() == QStringLiteral("男"))
		userInfo.strSex = "M";
	if (ui.sexComboBox->currentText() == QStringLiteral("女"))
		userInfo.strSex = "F";

	emit sigUserInfo(userInfo);
	this->close();
}
