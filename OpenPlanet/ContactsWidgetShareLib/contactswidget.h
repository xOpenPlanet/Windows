#ifndef CONTACTSWIDGET_H
#define CONTACTSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QMenu>
#include "perprofilewidget.h"
#include "groupprofilewidget.h"
#include "ui_contactswidget.h"

class ContactsWidget : public QWidget
{
	Q_OBJECT

public:
	ContactsWidget(QWidget *parent = 0);
	~ContactsWidget();

	void addWidget(QWidget *);

	perProfileWidget *getPerProfile();
	GroupProfileWidget *getGroupProfile();

protected:
	bool eventFilter(QObject *obj, QEvent *e);

private slots:
    void slotSwitchTabs(int id, bool checked);
	//************************************
	// Method:    slotClickSearch
	// FullName:  IMMainWidget::slotClickSearch
	// Access:    private 
	// Returns:   void
	// Qualifier:
	//************************************
	void slotClickSearch();
	//************************************
	// Method:    slotAddBtnClicked
	// FullName:  ContactsWidget::slotAddBtnClicked
	// Access:    private 
	// Returns:   void
	// Qualifier:
	//************************************
	void slotAddBtnClicked();

signals:
	void sigAddCreateGroup();
	void sigAddPerson();

private:
	Ui::ContactsWidget ui;

	QButtonGroup *buttons;

	QMenu *mAddMenu;
	QAction *mCreateGroup;
	QAction *mAddPerson;
};

#endif // CONTACTSWIDGET_H
