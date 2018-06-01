#include "userprofilewidget.h"

UserProfileWidget::UserProfileWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	//this->setWindowFlags(Qt::Tool);
	this->setWindowTitle(QStringLiteral("��������"));
	QPixmap mask(":/profile/Resources/profile/profileMask.png");
	this->setMask(mask.mask());

	closeBtn = new QPushButton(this);
	closeBtn->setStyleSheet("QPushButton{border-image: url(:/profile/Resources/profile/close.png);}");
	closeBtn->setCursor(Qt::PointingHandCursor);
	closeBtn->setToolTip(QStringLiteral("�ر�"));
	closeBtn->resize(24, 24);
	closeBtn->move(310, 10);
	headerBtn = new QPushButton(this);
	headerBtn->setStyleSheet("QPushButton{border-image: url(:/profile/Resources/profile/header.png);}");
	headerBtn->setCursor(Qt::PointingHandCursor);
	headerBtn->setToolTip(QStringLiteral("�޸�ͷ��"));
	headerBtn->resize(24, 24);
	headerBtn->move(280, 10);
	editBtn = new QPushButton(this);
	editBtn->setObjectName("editBtn");
	editBtn->setStyleSheet("QPushButton#editBtn{border-image: url(:/profile/Resources/profile/edit.png);}"
		"QPushButton#editBtn:hover{border-image: url(:/profile/Resources/profile/edit_hover.png);}");
	editBtn->setToolTip(QStringLiteral("�޸�����"));
	editBtn->resize(52, 52);
	editBtn->move(275, 313);
	connect(closeBtn, SIGNAL(clicked(bool)), this, SLOT(hide()));
	connect(headerBtn, SIGNAL(clicked(bool)), this, SIGNAL(sigOpenAvatarWidget()));
	connect(editBtn, SIGNAL(clicked(bool)), this, SIGNAL(sigOpenUserInfoWidget()));

	ui.headerLabel->installEventFilter(this);

	QFile file(":/qssWidget/Resources/qssWidget/userprofilewidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

UserProfileWidget::~UserProfileWidget()
{

}

bool UserProfileWidget::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == ui.headerLabel)
	{
		if (e->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			mouse = event->pos();   //�����ƶ���ԭʼλ�á�
		}
		if (e->type() == QEvent::MouseMove)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			if (mouse.x() >= 0)
			{
				//����ͨ������ֵ��������λ�Ƶľ��롣
				int x = event->pos().x() - mouse.x();
				int y = event->pos().y() - mouse.y();
				//�ƶ������塣
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

void UserProfileWidget::setUserInfo(UserInfo userInfo)
{
	QFile file(userInfo.strUserAvatarLocal);
	QPixmap pix;
	if (file.open(QIODevice::ReadOnly))
	{
		QByteArray byteArray = file.readAll();
		file.close();
		pix.loadFromData(byteArray);
	}

	if (pix.isNull())
		pix.load(":/PerChat/Resources/person/temp.png");

	this->setHeaderImage(pix);
	ui.noteLabel->setText(userInfo.strUserNickName);
	ui.signLabel->setText(userInfo.strSign);
	ui.accountLabel->setText(userInfo.strAccountName);
	ui.nameLabel->setText(userInfo.strUserNickName);
	ui.lianxinLabel->setText(QString::number(userInfo.nUserID));
	ui.phoneLabel->setText(userInfo.strPhone);
	ui.mailLabel->setText(userInfo.strEmil);
}

void UserProfileWidget::setHeaderImage(QPixmap pix)
{
	pix = pix.scaled(ui.headerLabel->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

	ui.headerLabel->setPixmap(pix);
}
