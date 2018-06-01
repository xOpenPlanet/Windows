#ifndef GROUPLIST_H
#define GROUPLIST_H

#include <QMenu>
#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QKeyEvent>
#include <QDebug>
#include "cfrientitemgroup.h"
#include "imbuddy.h"
#include "imtranstype.h"

class GroupList : public QListWidget
{
	Q_OBJECT

public:
	GroupList(QWidget *parent=NULL);
	~GroupList();

	void OnInsertGroupInfo(GroupInfo groupInfo);

	void UpdateHeaderImage(QString userID, QPixmap pix);

	void OnUpdateGroupInfo(GroupInfo groupInfo);

	//删除好友
	void OnDeleteGroupInfo(QString groupID);

protected:
	void keyPressEvent(QKeyEvent * event);
	void enterEvent(QEvent * event);
	void leaveEvent(QEvent * event);

private slots:
	//************************************
	// Method:    doDoubleClickedItem
	// FullName:  GroupListWidget::doDoubleClickedItem
	// Access:    private 
	// Returns:   void
	// Qualifier: 双击点击列表
	// Parameter: QListWidgetItem * item
	//************************************
	void slotDoubleClickedItem(QListWidgetItem *item);
	void doClickedItem(QListWidgetItem *item);

	void slotListContextMenu(const QPoint& point);
signals:
	//************************************
	// Method:    sigGroupChatClick
	// FullName:  GroupListWidget::sigGroupChatClick
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击群组
	// Parameter: QString strGroupID
	//************************************
	void sigGroupChat(int type, QVariant strGroupID);
	void sigProfile(QString strBuddyID);

private:
	void OnInsertGroup(GroupInfo groupInfo,int nHeight = 62);
private:
	QMenu *listMenu;
	QAction *ActionShowGroupInfo;
	QAction *ActiondeleteGroup;
};


#endif // GROUPLIST_H
