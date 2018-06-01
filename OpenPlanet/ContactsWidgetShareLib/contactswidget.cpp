#include "contactswidget.h"

ContactsWidget::ContactsWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	buttons = new QButtonGroup(this);

	QPushButton *buddyButtn = new QPushButton();
	buddyButtn->setObjectName("buddy");
	buddyButtn->setCheckable(true);
	buddyButtn->setFixedHeight(40);
	buddyButtn->setAutoExclusive(true);
	buddyButtn->setChecked(true);
	QPushButton *groupButton = new QPushButton();
	groupButton->setObjectName("group");
	groupButton->setCheckable(true);
	groupButton->setFixedHeight(40);
	groupButton->setAutoExclusive(true);
	QPushButton *addButton = new QPushButton;
	addButton->setObjectName("add");
	addButton->setCursor(Qt::PointingHandCursor);
	addButton->setFixedSize(40, 40);

	ui.buttonsLayout->addWidget(buddyButtn);
	ui.buttonsLayout->addWidget(groupButton);
	ui.buttonsLayout->addWidget(addButton);

	buttons->addButton(buddyButtn, 0);
	buttons->addButton(groupButton, 1);

	mCreateGroup = new QAction(QStringLiteral("创建群组"), this);
	mCreateGroup->setIcon(QIcon(":/GroupChat/Resources/groupchat/group_chat.png"));
	connect(mCreateGroup, SIGNAL(triggered()), this, SIGNAL(sigAddCreateGroup()));

	mAddPerson = new QAction(QStringLiteral("添加朋友"), this);
	mAddPerson->setIcon(QIcon(":/Login/Resources/login/switch_single_normal.png"));
	connect(mAddPerson, SIGNAL(triggered()), this, SIGNAL(sigAddPerson()));

	mAddMenu = new QMenu((QWidget*)QApplication::desktop());
	mAddMenu->addAction(mCreateGroup);
	mAddMenu->addAction(mAddPerson);

	connect(buttons, SIGNAL(buttonToggled(int, bool)), this, SLOT(slotSwitchTabs(int, bool)));
	connect(ui.searchBtn, SIGNAL(clicked(bool)), this, SLOT(slotClickSearch()));
	connect(addButton, SIGNAL(clicked(bool)), this, SLOT(slotAddBtnClicked()));

	ui.separateLine->installEventFilter(this);

	ui.perWidget->hide();
	ui.groupWidget->hide();

	QFile file(":/qssWidget/Resources/qssWidget/contactswidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

ContactsWidget::~ContactsWidget()
{

}

void ContactsWidget::slotSwitchTabs(int id, bool checked)
{
	if (checked)
	    ui.contactsStackedWidget->setCurrentIndex(id);
}

void ContactsWidget::addWidget(QWidget *widget)
{
	widget->resize(ui.contactsStackedWidget->size());
	ui.contactsStackedWidget->addWidget(widget);

}

perProfileWidget * ContactsWidget::getPerProfile()
{
	return ui.perWidget;
}

GroupProfileWidget * ContactsWidget::getGroupProfile()
{
	return ui.groupWidget;
}

bool ContactsWidget::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == ui.separateLine)
	{
		if (e->type() == QEvent::MouseMove)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			int w = ui.tabsWidget->width() + event->x();
			if (w > 350)
				w = 350;
			if (w < 150)
				w = 150;
			ui.tabsWidget->setFixedWidth(w);
		}
	}

	return QWidget::eventFilter(obj, e);
}

void ContactsWidget::slotClickSearch()
{
	QPropertyAnimation *animation = new QPropertyAnimation(ui.searchLineWidget, "geometry");
	animation->setDuration(200);

	if (ui.searchLineWidget->width() == ui.searchLineWidget->minimumWidth())
	{
		ui.searchBtn->setStyleSheet("border-image: url(:/mainWidget/Resources/mainWidget/title_search_close.png);");
		QRect endGmy = ui.searchLineWidget->geometry();
		endGmy.setWidth(ui.searchWidget->width() - 40);
		animation->setStartValue(ui.searchLineWidget->geometry());
		animation->setEndValue(endGmy);
	}

	else
	{
		ui.searchBtn->setStyleSheet("border-image: url(:/mainWidget/Resources/mainWidget/title_search_open.png);");
		animation->setStartValue(ui.searchLineWidget->geometry());
		QRect endGmy = ui.searchLineWidget->geometry();
		endGmy.setWidth(ui.searchLineWidget->minimumWidth());
		animation->setEndValue(endGmy);
	}

	animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void ContactsWidget::slotAddBtnClicked()
{
	if (mAddMenu != NULL)
	{
		mAddMenu->exec(QCursor::pos());
	}
}
