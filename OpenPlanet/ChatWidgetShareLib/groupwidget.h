#ifndef GROUPWIDGET_H
#define GROUPWIDGET_H

#include <QWidget>
#include <QFile>
#include "ui_groupwidget.h"
#include "groupchatwidget.h"
#include "imtranstype.h"

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

class GroupWidget : public QWidget
{
	Q_OBJECT

public:
	GroupWidget(QWidget *parent = 0);
	~GroupWidget();

	void OnSetGroupName(QString strGroupName, QString strGroupID);

	void OnInsertGroupUserList(QString strGroupID);

	void OnInsertGroupUser(BuddyInfo info);

	void OnCloseExpress();

	void OnInsertRevMessage(MessageInfo message);

	void OnUpdateGroupBuddyHeaderImg(QString strBuddyID, QString strPath);

	void UpdateMessageStateInfo(QByteArray msgID, int nState, int integral);

	void OnInertSendMessageTextInfo(QString strMsg, QString strrAvatarLocal, MessageInfo msgInfo);
	// wxd add code - end

	void OnSendScreenShotPic(QString strShotFileName);
	//added by fanwenxing
	void scrollBottom();
	void userQuitGroup(QString userID);

public slots:
	void OnInitMessage(QString strFromUserID = "");

protected:
	//added by wangqingjie
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);

private:
	void RegisterHandle();
	void mousePressEvent(QMouseEvent *event);

	// wxd add code - start
	void setChildWidgetFixedSize();
	void initLayout();
	void removeLayoutSpacing(QLayout* layout); 
	// wxd add code - end

private slots:
	void slotClickedClose();
	void slotClickedMaxSize();
	void slotClickedMinSize();
	void slotClickedGroupSpace();
	void slotClickedGroupChat();
	void slotClickedGroupFile();
	void slotClickedGroupNotice();
	void slotClickedGroupPic();
	void slotClickedGroupTalk();
	void slotClickedGroupMore();
	void slotGroupSendClose();
	void slotShowPerChat(QString strBuddyID);
	// wxd add code - start
	void slotOnGroupChatBtnCloseWClicked(); 
	// wxd add coed - end

	void slotGroupBuddyPerChat(QString strBuddyID);

	void slotShowNormalWindow();

	void slotOpenGroupLog();
signals:
	void sigGroupClose();
	void sigGroupMinSize(); 

	void sigShowPerChat(QString strBuddyID);
	// wxd add code - start
	void sigGroupWidgetBtnCloseWClicked();
	void sigGroupFile();
	//end added
	void sigKeyUpDown(QKeyEvent *);

	void sigShowGroupBuddyPerChat(int type, QVariant strBuddyID);

	void sigShowNormalWindow();
	void sigOpenGroupLog(QString);
	
private:
	Ui::GroupWidget ui;
	GroupChatWidget *mGroupChatWidget;

	QLabelHeader*   mChatHeaderImage;
};

#endif // GROUPWIDGET_H
