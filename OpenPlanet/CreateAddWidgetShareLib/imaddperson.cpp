#include "imaddperson.h"
#include <QFile>


IMAddPerson::IMAddPerson(QWidget *parent)
	: BaseWindow(parent)
{
	ui.setupUi(this);
	initTitleBar(); 

	//加载样式
	QFile file(":/addPerson/Resources/QSS/addcreate.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();

	ui.mPButtonFindPerson->setStyleSheet("border-image:url(:/addPerson/Resources/add/nav_btnbg.png) 0 0 0 0 stretch stretch;");

	connect(ui.mPButtonFindPerson, SIGNAL(clicked()), this, SLOT(doClickSearchPerson()));
	connect(ui.mPButtonFindGroup, SIGNAL(clicked()), this, SLOT(doClickSearchGroup()));
	connect(ui.mPButtonFindAppNo, SIGNAL(clicked()), this, SLOT(doClickSearchAppNo()));

	mSearchPerson = new IMSearchPerson(this);
	ui.stackedWidget->addWidget(mSearchPerson);

	mSearchGroup = new IMSearchGroup(this);
	ui.stackedWidget->addWidget(mSearchGroup);

	connect(m_titleBar, SIGNAL(sigButtonCloseClicked()), this, SLOT(doClickClose()));
}

IMAddPerson::~IMAddPerson()
{
	if (mSearchPerson != NULL)
	{
		mSearchPerson->close();
	}
}

void IMAddPerson::initTitleBar()
{
	m_titleBar->setTitleIcon(":/Login/Resources/login/system.png");
	m_titleBar->setTitleContent(QStringLiteral("添加朋友"),10);
	m_titleBar->setBackgroundColor(78, 103, 165);
	m_titleBar->setTitleContentBKColor("color:white;");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void IMAddPerson::doClickSearchPerson()
{
	ui.mPButtonFindPerson->setStyleSheet("border-image:url(:/addPerson/Resources/add/nav_btnbg.png) 0 0 0 0 stretch stretch;background - color:#4876FF;");
	ui.mPButtonFindGroup->setStyleSheet("border-image:url() 0 0 0 0 stretch stretch;");
	ui.mPButtonFindAppNo->setStyleSheet("border-image:url() 0 0 0 0 stretch stretch;");
	ui.stackedWidget->setCurrentIndex(0);
}

void IMAddPerson::doClickSearchGroup()
{
	ui.mPButtonFindGroup->setStyleSheet("border-image:url(:/addPerson/Resources/add/nav_btnbg.png) 0 0 0 0 stretch stretch;background - color:#4876FF;");
	ui.mPButtonFindPerson->setStyleSheet("border-image:url() 0 0 0 0 stretch stretch;");
	ui.mPButtonFindAppNo->setStyleSheet("border-image:url() 0 0 0 0 stretch stretch;");
	ui.stackedWidget->setCurrentIndex(1);
}

void IMAddPerson::doClickSearchAppNo()
{
	ui.mPButtonFindAppNo->setStyleSheet("border-image:url(:/addPerson/Resources/add/nav_btnbg.png) 0 0 0 0 stretch stretch;");
	ui.mPButtonFindPerson->setStyleSheet("border-image:url() 0 0 0 0 stretch stretch;");
	ui.mPButtonFindGroup->setStyleSheet("border-image:url() 0 0 0 0 stretch stretch;");
}

void IMAddPerson::doClickClose()
{
	if (mSearchPerson != NULL)
	{
		mSearchPerson->ClearList();
	}
}