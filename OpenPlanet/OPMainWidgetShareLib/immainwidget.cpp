#include "immainwidget.h"

IMMainWidget::IMMainWidget(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	ActionCheckUpdate = NULL; //检查更新
	ActionExit = NULL;        //退出
	mTrayMenu = NULL;         //系统托盘菜单
	mSysTrayIcon = NULL;
	aboutWidget = NULL;

	mMessageRevFlashTime = NULL;
	mMessageRevFlashNum = 0;
	mFlashingFlag = false;

	shadow = new Shadow();
	this->setWindowFlags(Qt::FramelessWindowHint);

	buttonGroup = new QButtonGroup(this);

	ui.titleBar->installEventFilter(this);
	ui.hearderLabel->installEventFilter(this);
	ui.nickNameLabel->installEventFilter(this);
	ui.contentStacked->installEventFilter(this);

	registerHandle();
	CreateTrayMenu();

	QFile file(":/qssWidget/Resources/qssWidget/immainwidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();

	//开放星球。
	ui.statusBar->hide();
	ui.robotsBtn->hide();
}

IMMainWidget::~IMMainWidget()
{
	if (ActionCheckUpdate)
		delete ActionCheckUpdate;
	if (ActionExit)
		delete ActionExit;
	if (mTrayMenu)
		delete mTrayMenu;
	if (mSysTrayIcon)
		delete mSysTrayIcon;
	if (shadow)
		delete shadow;
	if (buttonGroup)
		delete buttonGroup;

	StopMessageFlash();
}

void IMMainWidget::registerHandle()
{
	connect(ui.minBtn, SIGNAL(clicked(bool)), this, SLOT(showMinimized()));
	connect(ui.maxBtn, SIGNAL(clicked(bool)), this, SLOT(slotFullScreen()));
	connect(ui.closeBtn, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(ui.closeBtn, SIGNAL(clicked(bool)), shadow, SLOT(hide()));
	connect(buttonGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(slotCheckWidget(int, bool)));

	QList<AppButton> appList = ReadConfig().read();

	ui.messageBtn->setFixedSize(50, 46);
	ui.messageBtn->setToolTip(QStringLiteral("空间"));
	ui.contactsBtn->setFixedSize(50, 46);
	ui.contactsBtn->setToolTip(QStringLiteral("星际"));
	ui.robotsBtn->setFixedSize(50, 46);
	ui.walletBtn->setToolTip(QStringLiteral("基地"));
	ui.walletBtn->setFixedSize(50, 46);
	
	buttonGroup->addButton(ui.messageBtn, 1);
	buttonGroup->addButton(ui.contactsBtn, 2);
	buttonGroup->addButton(ui.walletBtn, 3);

	aboutWidget = new AboutWidget();
	aboutWidget->hide();

	menuWidget = new MenuWidget(this);
	menuWidget->hide();
	connect(menuWidget, SIGNAL(sigUserProfile()), this, SIGNAL(sigUserProfile()));
}

void IMMainWidget::setAppVersion(QString version)
{
	mAppVersion = version;
	if (aboutWidget)
	{
		aboutWidget->setNumber(mAppVersion);
	}
}

void IMMainWidget::setAppName(QString name)
{
	this->setWindowTitle(name);

	if (aboutWidget)
		aboutWidget->setName(name);
}


void IMMainWidget::show()
{
	QWidget::show();

	shadow->resize(width() + 20, height() + 20);
	shadow->move(x() - 10, y() - 10);
	shadow->show();
}

void IMMainWidget::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	QPen pen;
	pen.setColor(QColor(24, 50, 87));
	pen.setWidth(3);
	painter.setPen(pen);
	painter.drawLine(0, 0, this->width(), 0);
	painter.drawLine(0, 0, 0, this->height());
	painter.drawLine(this->width()-1, 0, this->width()-1, this->height());
	painter.drawLine(0, this->height()-1, this->width(), this->height()-1);
	painter.end();
	//pen.setColor(QColor(10, 24, 45));
}

void IMMainWidget::moveEvent(QMoveEvent *event)
{
	shadow->move(event->pos().x() - 10, event->pos().y() - 10);
}

void IMMainWidget::resizeEvent(QResizeEvent* event)
{
	shadow->resize(event->size().width() + 20, event->size().height() + 20);
}

void IMMainWidget::changeEvent(QEvent * event)
{
	if (event->type() == QEvent::WindowStateChange)
	{
		if (this->windowState() == Qt::WindowMaximized)
			shadow->hide();
		if (this->windowState() == Qt::WindowMinimized)
			shadow->hide();

		if (this->windowState() == Qt::WindowNoState)
			shadow->show();
	}

	QWidget::changeEvent(event);
}

void IMMainWidget::closeEvent(QCloseEvent * event)
{
	if (shadow)
	    shadow->hide();

	QWidget::closeEvent(event);
}

bool IMMainWidget::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	PMSG msg = (PMSG)message;

	if (msg->message == WM_ACTIVATE && msg->wParam == WA_ACTIVE)
	{ 
		InvalidateRect((HWND)this->winId(), nullptr, FALSE);
		return false;
	}

	if (msg->message == WM_NCHITTEST)
	{
		if (shadow->isHidden())
			return false;
		*result = 0;
		const LONG border_width = 4; //in pixels
		RECT winrect;
		GetWindowRect((HWND)winId(), &winrect);
		long x = GET_X_LPARAM(msg->lParam);
		long y = GET_Y_LPARAM(msg->lParam);

		bool resizeWidth = minimumWidth() != maximumWidth();
		bool resizeHeight = minimumHeight() != maximumHeight();
		if (resizeWidth)
		{
			//left border
			if (x >= winrect.left && x < winrect.left + border_width)
			{
				*result = HTLEFT;
			}
			//right border
			if (x < winrect.right && x >= winrect.right - border_width)
			{
				*result = HTRIGHT;
			}
		}
		if (resizeHeight)
		{
			//bottom border
			if (y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOM;
			}
			//top border
			if (y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOP;
			}
		}
		if (resizeWidth && resizeHeight)
		{
			//bottom left corner
			if (x >= winrect.left && x < winrect.left + border_width &&
				y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOMLEFT;
			}
			//bottom right corner
			if (x < winrect.right && x >= winrect.right - border_width &&
				y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOMRIGHT;
			}
			//top left corner
			if (x >= winrect.left && x < winrect.left + border_width &&
				y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOPLEFT;
			}
			//top right corner
			if (x < winrect.right && x >= winrect.right - border_width &&
				y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOPRIGHT;
			}
		}
		if (*result == 0)
			return false;
		return true;
	}
	else if (msg->message == WM_POWERBROADCAST)
	{
		if (msg->wParam == PBT_APMSUSPEND)         //系统休眠了
		{
			emit sigDormancyState(true);
		}
		else if (msg->wParam == PBT_APMRESUMESUSPEND) //系统唤醒了
		{
			emit sigDormancyState(false);
		}
		return false;
	}

	return QWidget::nativeEvent(eventType, message, result);
}

bool IMMainWidget::eventFilter(QObject *obj, QEvent *e)
{
	if ((obj == ui.hearderLabel || obj == ui.nickNameLabel) && e->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *mouseEvent = (QMouseEvent *)e;
		if (mouseEvent->button() == Qt::LeftButton)
		{
			QPoint globalPos = ui.hearderLabel->mapToGlobal(ui.hearderLabel->pos());
			emit sigUserProfile();
		}
	}
	if (obj == ui.contentStacked && e->type() == QEvent::MouseButtonPress)
	{
		if (menuWidget->isVisible())
			menuWidget->hide();
	}
	if (obj == ui.titleBar)
	{
		if (e->type() == QEvent::MouseButtonDblClick)
			this->slotFullScreen();

		if (shadow && shadow->isVisible())
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
	}

	return QObject::eventFilter(obj, e);
}

void IMMainWidget::slotFullScreen()
{
	if (this->isMaximized())
	{
		this->showNormal();
		ui.maxBtn->setStyleSheet("QPushButton#maxBtn{border-image:url(:/mainWidget/Resources/mainWidget/title_max.png);}");
		ui.maxBtn->setToolTip(QStringLiteral("最大化"));
	}
	else
	{
		this->showMaximized();
		ui.maxBtn->setStyleSheet("QPushButton#maxBtn{border-image:url(:/mainWidget/Resources/mainWidget/title_recover.png);}");
		ui.maxBtn->setToolTip(QStringLiteral("恢复"));
	}
}

void IMMainWidget::slotCheckWidget(int id, bool checked)
{
	if (checked)
	{
		if (ui.contentStacked->widget(id))
			ui.contentStacked->setCurrentIndex(id);
	}
}

//设置昵称
void IMMainWidget::setNikeName(QString nickName)
{
	ui.nickNameLabel->setText(nickName);
}

//设置头像
void IMMainWidget::setHeaderImage(QPixmap headerImage)
{
	ui.hearderLabel->setPixmap(headerImage);
}

void IMMainWidget::addWidget(QWidget *widget)
{
	ui.contentStacked->addWidget(widget);
}

void IMMainWidget::CreateTrayMenu()
{
	ActionCheckUpdate = new QAction(QStringLiteral("关于"), this);
	ActionCheckUpdate->setToolTip(QStringLiteral("关于"));
	ActionCheckUpdate->setIcon(QIcon(":menu/checkupdate.png"));
	connect(ActionCheckUpdate, SIGNAL(triggered()), aboutWidget, SLOT(show()));


	ActionExit = new QAction(QStringLiteral("退出"), this);
	ActionExit->setToolTip(QStringLiteral("退出"));
	ActionExit->setIcon(QIcon(":menu/checkupdate.png"));

	connect(ActionExit, SIGNAL(triggered()), this, SLOT(slotExit()));

	mTrayMenu = new QMenu((QWidget*)QApplication::desktop());
	mTrayMenu->addAction(ActionCheckUpdate);
	mTrayMenu->addSeparator();
	mTrayMenu->addAction(ActionExit);
	CreateTrayIcon(QIcon(":/Ico/Resources/logo/logo.ico"));
}

void IMMainWidget::CreateTrayIcon(QIcon icon)
{
	//判断系统是否支持系统托盘图标
	if (!QSystemTrayIcon::isSystemTrayAvailable())
		return;
	if (mSysTrayIcon == NULL)
	{
		mSysTrayIcon = new QSystemTrayIcon();
		mSysTrayIcon->setIcon(icon);
		mSysTrayIcon->setToolTip(QStringLiteral("开放星球"));
		mSysTrayIcon->setContextMenu(mTrayMenu);
		mSysTrayIcon->show();
		connect(mSysTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(slotSysTrayIconClicked(QSystemTrayIcon::ActivationReason)));
	}
}

/*处理托盘点击事件*/
void IMMainWidget::slotSysTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Trigger:    //单击托盘
	{
		if (mMessageRevFlashTime != NULL)
		{
			if (mMessageRevFlashTime->isActive())
			{
				mMessageRevFlashTime->stop();
				mSysTrayIcon->setIcon(QIcon(":/Login/Resources/login/system.ico"));
				mMessageRevFlashNum = 0;
				mFlashingFlag = false;

				QString fileName = mMessageRevHeaderImg.split("/").last();
				QString buddyID = fileName.split(".").first();
				emit sigTrayOpenChat(mMessageRevType, QVariant(buddyID));
			}
		}

		::SetWindowPos((HWND)this->winId(), HWND_TOP/*HWND_TOPMOST*/, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		if (this->isMinimized())
		{
			this->showNormal();
		}
		else if (this->isHidden())
		{
			this->show();
		}

		break;
	}
	case QSystemTrayIcon::DoubleClick:  //双击托盘
	{
		break;
	}
	case QSystemTrayIcon::Context:
		break;
	case QSystemTrayIcon::MiddleClick:
		break;
	default:
		break;
	}
}

void IMMainWidget::slotExit()
{
	if (ActionCheckUpdate)
		delete ActionCheckUpdate;
	if (ActionExit)
		delete ActionExit;
	if (mTrayMenu)
		delete mTrayMenu;
	if (mSysTrayIcon)
		delete mSysTrayIcon;
	if (shadow)
	{
		delete shadow;
		shadow = NULL;
	}
	if (buttonGroup)
		delete buttonGroup;

	this->close();
	emit sigExit();
}

void IMMainWidget::setCurrentWidget(int type)
{
	if (type == OpenPer || type == OpenGroup)
	{
		ui.messageBtn->setChecked(true);
		ui.contentStacked->setCurrentIndex(buttonGroup->checkedId());
	}
}


void IMMainWidget::slotSetMainWidgetStatusLabel(QString msg)
{
	ui.statusLabel->setText(msg);
}

void IMMainWidget::slotDealTrayIconFlash(QString buddyID)
{
	QString fileName = mMessageRevHeaderImg.split("/").last();
	QString name = fileName.split(".").first();

	if (buddyID == name || buddyID == "apply")   //apply.ico是验证消息的图标。
	{

		if (mMessageRevFlashTime)
		{
			if (mMessageRevFlashTime->isActive())
				mMessageRevFlashTime->stop();
			mSysTrayIcon->setIcon(QIcon(":/Login/Resources/login/system.ico"));
			mMessageRevFlashNum = 0;
			mFlashingFlag = false;//added by wangqingjie
		}
	}
}

void IMMainWidget::slotMessageRevFlashTime()
{
	if (mMessageRevFlashNum % 2 == 0)
	{
		QPixmap map;
		QFile file(mMessageRevHeaderImg);
		QByteArray array;
		if (file.open(QIODevice::ReadOnly))
		{
			array = file.readAll();
		}
		map.loadFromData(array);
		if (map.isNull())
			map.load(":/PerChat/Resources/person/temp.png");

		QIcon icon(map);

		mSysTrayIcon->setIcon(icon);
	}
	else
	{
		mSysTrayIcon->setIcon(QIcon());
	}
	mMessageRevFlashNum++;
}

void IMMainWidget::slotShowAllClicked()
{

}

void IMMainWidget::StartMessageFlash(int type, QString imagePath)
{
	this->mMessageRevType = type;
	this->mMessageRevHeaderImg = imagePath;

	mFlashingFlag = true;
	if (mMessageRevFlashTime == NULL)
	{
		mMessageRevFlashTime = new QTimer(this);
		connect(mMessageRevFlashTime, SIGNAL(timeout()), this, SLOT(slotMessageRevFlashTime()));
	}
	if (!mMessageRevFlashTime->isActive())
	{
		mMessageRevFlashTime->start(500);
	}
}

void IMMainWidget::StopMessageFlash()
{
	if (mMessageRevFlashTime != NULL)
	{
		if (mMessageRevFlashTime->isActive())
		{
			mMessageRevFlashTime->stop();
		}
		delete mMessageRevFlashTime;
		mMessageRevFlashTime = NULL;
		mMessageRevFlashNum = 0;
	}
}

void IMMainWidget::slotCountMessage(int num)
{
	qDebug() << num;
	ui.messageBtn->slotSetNum(num);
}


