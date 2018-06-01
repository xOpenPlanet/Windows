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

//�����б���Ϣ�б� ��д

class CFriendListWidgetBase : public QListWidget
{
    Q_OBJECT


public:
    explicit CFriendListWidgetBase(QWidget *parent = 0);

    //�����Ϣ�б�   height��Ϊ 64
	void OnInsertMessage(QString strUserID, QString strPicPath, QString strNickName, QString strAutoGrapthText, QString strMessageTime, QString strMessageNum, int nType=0,int nHeight = 64);

    //�����ϵ��
    //strFlags:A B C D ...
    //strPicPath:ͷ��·��
    //strNickName: �ǳ�
    //nHeight item�߶� Ĭ��Ϊ 62
	void OnInsertContacts(QString strData, QString strUserID, QString strPicPath, QString strNickName, QString strSign, int nType=0 , int nHeight = 62);
	void OnInsertGroup(QString strData, QString strUserID, QString strPicPath, QString strNickName, int nType = 0, int nHeight = 62);

	void OnInsertContactsofIndex(QString strData, QString strUserID, QString strPicPath, QString strNickName, QString strSign, int nIndex, int nHeight = 62);

    //************************************
    // Method:    OnInsertGroupUserList
    // FullName:  CFriendListWidgetBase::OnInsertGroupUserList
    // Access:    public 
    // Returns:   void
    // Qualifier: ����Ⱥ���û�
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
	// Qualifier: ��Ϣ��¼�����û�
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
	// Qualifier: ��֤���Ѳ����û�
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
	// Qualifier: ������Ϣ����
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
	// Qualifier: �������
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
	// Qualifier: ����Ⱥ���б�
	// Parameter: QString strAddID
	// Parameter: QString strPicPath
	// Parameter: QString strAddName
	// Parameter: int nHeight Ĭ�� 62
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
	void slotOnMouseEnteredListWidgetItem(QListWidgetItem* item);       // ������ĳitem   ��ʾclose_btn
	void slotOnMouseLeavedListWidgetItem(QListWidgetItem* item);		// ����Ƴ�ĳitem   ����close_btn
    // wxd add code - end
	void slotClickAcceptBtn();

	void slotClickCloseBtn(QString);
	void slotCountMessageNum();
signals:
	void sigAddPerson(QString strBuddyID);

	// wxd add code - start
	void sigMouseEnteredItem(QListWidgetItem* item);    // ������ĳitem 
	void sigMouseLeavedItem(QListWidgetItem* item);     // ����Ƴ�ĳitem

	void sigClickAcceptBtn();
	// wxd add code - end

	void sigChatClose(QString);
	void sigMessageNum(int);

private:
    //������ϵ�˱�ǩ�Ƿ����,������ڣ����ز�������������򷵻�-1
    int SearchContactItem(QString strFlags);

private:
	int m_type;      // ��ǰlist������
};

#endif // CFRIENDLISTWIDGETBASE_H
