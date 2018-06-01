#ifndef GROUPSEARCHWIDGET_H
#define GROUPSEARCHWIDGET_H

#include <QWidget>
#include "imbuddy.h"
#include "ui_groupsearchwidget.h"
#include "cfrientstylewidget.h"

class GroupSearchWidget : public QWidget
{
	Q_OBJECT

public:
	GroupSearchWidget(QWidget *parent = 0);
	~GroupSearchWidget();

	void setGroupID(QString);
	void getFocus();
	void clearAndHide();

private slots:
	void slotSearch(QString);
	void slotDBClickItem(QListWidgetItem *);

signals:
	void sigOpenSearchUser(QString);

private:
	Ui::GroupSearchWidget ui;

	QString currentID;
};

#endif // GROUPSEARCHWIDGET_H
