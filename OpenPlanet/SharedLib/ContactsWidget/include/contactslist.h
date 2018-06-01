#ifndef CONTACTSLIST_H
#define CONTACTSLIST_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QKeyEvent>
#include <QMenu>
#include <QDebug>
#include "imbuddy.h"
#include "imtranstype.h"
#include "cfrientitembuddy.h"

class ContactsList : public QListWidget
{
	Q_OBJECT

public:
	ContactsList(QWidget *parent = NULL);
	~ContactsList();

	//************************************
	// Method:    OnInsertContactsInfo
	// FullName:  ContactsList::OnInsertContactsInfo
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: BuddyInfo buddyInfo
	//************************************
	void OnInsertContactsInfo(BuddyInfo buddyInfo);

	//************************************
	// Method:    OnUpdateBuddyInfo
	// FullName:  ContactsList::OnUpdateBuddyInfo
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: BuddyInfo buddyInfo
	//************************************
	void OnUpdateBuddyInfo(BuddyInfo buddyInfo);

	//************************************
	// Method:    UpdateBuddyImage
	// FullName:  ContactsList::UpdateBuddyImage
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新好友头像
	// Parameter: QString userID
	// Parameter: QPixmap pix
	//************************************
	void UpdateBuddyImage(QString userID, QPixmap pix);

	void deleteFriend(QString userID);

protected:
	void keyPressEvent(QKeyEvent * event);
	void enterEvent(QEvent * event);
	void leaveEvent(QEvent * event);

private:
	//************************************
	// Method:    OnJudgeIsListTitle
	// FullName:  ContactsListWidget::OnJudgeIsListTitle
	// Access:    private 
	// Returns:   void
	// Qualifier: 判断是否是列表的标题
	// Parameter: QString strTitle
	//************************************
	bool OnJudgeIsListTitle(QString strTitle);

	//************************************
	// Method:    OnInsertContactsofIndex
	// FullName:  ContactsList::OnInsertContactsofIndex
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: BuddyInfo info
	// Parameter: int nIndex
	// Parameter: int nHeight
	//************************************
	void OnInsertContactsofIndex(BuddyInfo info, int nIndex, int nHeight = 62);

private slots:
	void doDoubleClickedItem(QListWidgetItem *item);
	void doClickedItem(QListWidgetItem *item);
	void doListContextMenu(const QPoint& point);
signals:
	//************************************
	// Method:    SendPerChat
	// FullName:  ContactsListWidget::SendPerChat
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送双击打开聊天框消息
	// Parameter: QString strBuddyID
	//************************************
	void sigPerChat(int type, QVariant strBuddyID);
	void sigProfile(QString strBuddyID);

private:
	QMenu *listMenu;
	QAction *ActionShowBuddyInfo;
	QAction *ActiondeleteBuddy;
};

#endif // CONTACTSLIST_H
