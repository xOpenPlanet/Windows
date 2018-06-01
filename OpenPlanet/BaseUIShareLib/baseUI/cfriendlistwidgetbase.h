#ifndef CFRIENDLISTWIDGETBASE_H
#define CFRIENDLISTWIDGETBASE_H

#include <QWidget>
#include <QListWidget>
#include <iostream>
#include <map>
#include <set>
#include "cfrientstylewidget.h"
#include <QMouseEvent>

//using namespace std;

//好友列表及消息列表 重写

class CFriendListWidgetBase : public QListWidget
{
    Q_OBJECT


public:
    explicit CFriendListWidgetBase(QWidget *parent = 0);

    //添加消息列表   height设为 64
	void OnInsertMessage(QString strUserID, QString strPicPath, QString strNickName, QString strAutoGrapthText, QString strMessageTime, QString strMessageNum, int nType=0,int nHeight = 64);

    //添加联系人
    //strFlags:A B C D ...
    //strPicPath:头像路径
    //strNickName: 昵称
    //nHeight item高度 默认为 62
	void OnInsertContacts(QString strData, QString strUserID, QString strPicPath, QString strNickName, QString strSign, int nType=0 , int nHeight = 62);
	void OnInsertGroup(QString strData, QString strUserID, QString strPicPath, QString strNickName, int nType = 0, int nHeight = 62);

	void OnInsertContactsofIndex(QString strData, QString strUserID, QString strPicPath, QString strNickName, QString strSign, int nIndex, int nHeight = 62);

    //************************************
    // Method:    OnInsertGroupUserList
    // FullName:  CFriendListWidgetBase::OnInsertGroupUserList
    // Access:    public 
    // Returns:   void
    // Qualifier: 插入群组用户
    // Parameter: QString strUserID
    // Parameter: QString strPicPath
    // Parameter: QString strNickName
    // Parameter: int nHeight
    //************************************
    void OnInsertGroupUserList(QString strUserID,QString strPicPath,QString strNickName, int mana, int nHeight=30);
	//************************************
	// Method:    OnInsertLogUserList
	// FullName:  CFriendListWidgetBase::OnInsertLogUserList
	// Access:    public 
	// Returns:   void
	// Qualifier: 消息记录插入用户
	// Parameter: QString strUserID
	// Parameter: QString strPicPath
	// Parameter: QString strNickName
	// Parameter: int nHeight
	//************************************
	void OnInsertLogUserList(QString strUserID, QString strPicPath, QString strNickName, int ntype,int nHeight = 30);
	//************************************
	// Method:    OnInsertManagerUserList
	// FullName:  CFriendListWidgetBase::OnInsertManagerUserList
	// Access:    public 
	// Returns:   void
	// Qualifier: 验证好友插入用户
	// Parameter: QString strUserID
	// Parameter: QString strPicPath
	// Parameter: QString strNickName
	// Parameter: int nHeight
	//************************************
	void OnInsertManagerUserList(QString strUserID, QString strPicPath, QString strNickName, int nHeight, bool hasAccept = false);
	void OnInsertManagerApplyGroup(QString groupID, QString strUserID, QString strPicPath, QString text, int nHeight, bool hasAccpet = false);
	//************************************
	// Method:    OnInsertMessageBoxList
	// FullName:  CFriendListWidgetBase::OnInsertMessageBoxList
	// Access:    public 
	// Returns:   void
	// Qualifier: 插入消息盒子
	// Parameter: QString strUserID
	// Parameter: QString strPicPath
	// Parameter: QString strNickName
	// Parameter: int nHeight
	//************************************
	//void OnInsertMessageBoxList(QString strUserID, QString strPicPath, QString strNickName, int nHeight = 50);
	void OnInsertMessageBoxList(QString strTime,QString strMsg,QString strUserID, QString strPicPath, QString strNickName, int nHeight = 64);
	//************************************
	// Method:    OnInsertAddCreateWidgetList
	// FullName:  CFriendListWidgetBase::OnInsertAddCreateWidgetList
	// Access:    public 
	// Returns:   void
	// Qualifier: 添加朋友
	// Parameter: QString strAddID
	// Parameter: QString strPicPath
	// Parameter: QString strAddName
	// Parameter: QString strNote
	// Parameter: int nHeight
	//************************************
	void OnInsertAddCreateWidgetList(QString strAddID,QString strPicPath,QString strAddName,QString strNote,int nHeight = 70);

	void OnInsertSearchBuddyList(QString strAddID, QString strPicPath, QString strAddName, int nHeight = 70);
	//************************************
	// Method:    OnInsertSearchGroupList
	// FullName:  CFriendListWidgetBase::OnInsertSearchGroupList
	// Access:    public 
	// Returns:   void
	// Qualifier: 插入群组列表
	// Parameter: QString strAddID
	// Parameter: QString strPicPath
	// Parameter: QString strAddName
	// Parameter: int nHeight 默认 62
	//************************************
	void OnInsertSearchGroupList(QString strAddID, QString strPicPath, QString strAddName, int nHeight = 62);

protected: 
	// wxd add code - start
	//void focusInEvent(QFocusEvent* event); 
	//void mouseMoveEvent(QMouseEvent* event); 
	// wxd add code - end

private slots:
	void doAddPerson(QString strBuddyID);

    // wxd add code - start
	//void slotOnItemEntered(QListWidgetItem* item); 
	void slotOnMouseEnteredListWidgetItem(QListWidgetItem* item);       // 鼠标进入某item   显示close_btn
	void slotOnMouseLeavedListWidgetItem(QListWidgetItem* item);		// 鼠标移出某item   隐藏close_btn
    // wxd add code - end
	void slotClickAcceptBtn();

	void slotClickCloseBtn(QString);
	void slotCountMessageNum();
signals:
	void sigAddPerson(QString strBuddyID);

	// wxd add code - start
	void sigMouseEnteredItem(QListWidgetItem* item);    // 鼠标进入某item 
	void sigMouseLeavedItem(QListWidgetItem* item);     // 鼠标移出某item

	void sigClickAcceptBtn();
	// wxd add code - end

	void sigChatClose(QString);
	void sigMessageNum(int);

private:
    //查找联系人标签是否存在,如果存在，返回插入的行数，否则返回-1
    int SearchContactItem(QString strFlags);

private:
	int m_type;      // 当前list的类型
};

#endif // CFRIENDLISTWIDGETBASE_H
