#include "groupsearchwidget.h"
#include <qdebug.h>

GroupSearchWidget::GroupSearchWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.lineEdit, SIGNAL(textChanged(QString)), this, SLOT(slotSearch(QString)));
	connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(slotDBClickItem(QListWidgetItem *)));

	QFile file(":/qssWidget/Resources/qssWidget/groupsearchwidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

GroupSearchWidget::~GroupSearchWidget()
{

}

void GroupSearchWidget::setGroupID(QString groupID)
{
	currentID = groupID;
}

void GroupSearchWidget::getFocus()
{
	ui.lineEdit->setFocus();
}

void GroupSearchWidget::clearAndHide()
{
	ui.lineEdit->clear();
	this->hide();
}

void GroupSearchWidget::slotSearch(QString key)
{
	ui.listWidget->clear();
	this->resize(this->width(), this->minimumHeight());

	if (key.isEmpty())
		return;
	/*
	QList<BuddyInfo> buddyList = gDataManager->DB_searchGroupUser(currentID.toInt(), key);
	if (buddyList.count() == 0)
	{
		QListWidgetItem *item = new QListWidgetItem;
		item->setText("搜索结果为空……");
		item->setTextAlignment(Qt::AlignCenter);
		item->setFlags(Qt::NoItemFlags);
		item->setSizeHint(QSize(this->width() - 4, 30));
		ui.listWidget->addItem(item);
		this->resize(this->width(), this->height() + 30);
	}
	else
	{
		for (int i = 0; i < buddyList.count(); i++)
		{
			BuddyInfo buddyInfo = buddyList.at(i);

			CFrientStyleWidget *buddy = new CFrientStyleWidget();
			buddy->OnInitGroupUserList(QString::number(buddyInfo.nUserId));
			buddy->OnSetPicPath(buddyInfo.strLocalAvatar);
			if (buddyInfo.strNote.isEmpty())
				buddy->OnSetNickNameText(buddyInfo.strNickName);
			else
				buddy->OnSetNickNameText(buddyInfo.strNote);
			QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
			newItem->setSizeHint(QSize(this->width() - 4, 30));
			ui.listWidget->insertItem(ui.listWidget->count(), newItem); //将该newItem插入到后面
			ui.listWidget->setItemWidget(newItem, buddy); //将buddy赋给该newItem

			this->resize(this->width(), this->height() + 30);
		}
	}
	*/
	this->resize(this->width(), this->height() + 3);
}

void GroupSearchWidget::slotDBClickItem(QListWidgetItem *item)
{
	CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.listWidget->itemWidget(item);
	if (buddy == NULL)
	{
		qDebug() << "GroupSearchWidget::slotDBClickItem空指针";
		return;
	}
	QString strUserID = buddy->mNickName->objectName();

	emit sigOpenSearchUser(strUserID);
}