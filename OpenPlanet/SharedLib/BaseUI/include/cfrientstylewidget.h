#ifndef CFRIENTSTYLEWIDGET_H
#define CFRIENTSTYLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDir>
#include <QEvent>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QBitmap>
#include <QSpacerItem>
#include <QDateTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "qlabelheader.h"

#ifdef Q_OS_WIN
#pragma execution_character_set("utf-8")
#endif

#ifndef Max
#define Max(a,b)  (a) > (b) ? (a) : (b) 
#endif  // Max

//好友列表样式

class CFrientStyleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CFrientStyleWidget(QWidget *parent = 0);
    ~CFrientStyleWidget();

	enum layout_type
	{
		contacts = 0,		// 联系人, 群组的item 的布局风格
		group,              // 群组的布局风格
		message,			// 消息一栏的item 的布局风格
		chat,				// 聊天窗口左边的item 的布局风格
		group_member, 		// 群组成员的item 的布局风格
		manager             // 验证消息管理器的布局风格
	};

	enum item_list_type
	{
		chat_list = 1       // 聊天窗口左边的list
	};
signals:
    void sigLoginEditClose(QString);
	void sigCurrentChatClose(QString);
	void sigAddPerson(QString);
	// wxd add code - start
	void sigRemoveBuddyFromCGMemberList(QString);		// CG - CreateGroup  发送 mCreateGroupRemoveBtn 被点击的信号
	// wxd add code - end
	void sigNumChanged();
public slots:
    void doLoginEditClose();
    void doCurrentChatClose(); 
	void doAddPerson();
	// wxd add code - start  
	void OnCGRemoveBtnClicked();				// CG - CreateGroup   更改 ContactsList对应的item的CheckBtn的pic 从MemberList移除掉对应的item
	// wxd add code - end 
public:
    void OnSetHeadImageSize(int nWidth = 40,int nHeight = 40);  //设置头像大小
    void OnSetNickNameText(QString strText,QString styleSheet="");  //设置昵称名称
    void OnSetAutoGrapthText(QString strText,QString styleSheet=""); //设置签名/聊天信息内容
    void OnSetMessageTime(QString strText,QString styleSheet=""); //设置消息发送时间内容
	void OnSetPicPath(QString strPath, int nType = 0);     //设置头像路径
	void onSetHeaderImage(QPixmap);
	void onSetIdentity(int mana);     //设置身份，9是群主，1是管理员，0是普通成员。
    void OnInitMessage(QString);                   //消息好友列表样式
    void OnInitContacts(QString);                  //联系人好友列表样式
	void OnInitGroup(QString strUserID);           //群组列表样式。
    void OnInitLoginEdit(QString);                 //登陆列表
    void OnInitChat(QString strUserID);			   // 初始化聊天窗口
    void OnSetMessageNum(QString strNum);
	QString OnGetMessageNum();//added by wangqingjie
    QString OnGetHeaderImagePath();
    void OnInitGroupUserList(QString strGroupUserID); 
	void OnInitLogUserList(QString strGroupUserID);
	void onInitManagerUserList(QString strUserID, bool hasRead = false);
	void onInitManagerApplyGroup(QString strUserID, QString group, bool hasRead = false);
	void OnInitMessageBoxList(QString strBuddyID);
	void OnInitSearchBuddyList(QString strBuddyID);

	void OnSetPicPathByHttp(QString strPath, QString strDefaultImage = ":/PerChat/Resources/person/temp.png");

	void OnSetAddPersonButtonText(QString strText);

	QString GetNikeName();  //获取NikeName
	QString GetAutoGraph();//获取mAutoGraph内容
	QString GetStrTime();//获取时间
	// wxd add code -- start
	QPushButton* closeButton();       // 返回关闭按钮的对象指针
	QString getLoginUserID();         // 登录窗口中的下拉列表的item中的mBtnClose的objectName是对应的UserID
	bool getCGCheckBtnStatus();										// CG - CreateGroup
	void changeCGCheckBtnStatus();									// 改变 CGContactsListItem上 CheckBtn的状态
	void OnInitCreateGroupContactsList(QString strBuddyID);         // 初始化 新建群聊 窗口时的好友列表 给item加上圆形的对号复选框
	void OnInitCreateGroupMemberList(QString strBuddyID);			// 初始化 新建群聊 窗口时的群组成员列表 给item加上圆形的叉号复选框
	// wxd add code -- end

	//************************************
	// Method:    OnInitAddCreateList
	// FullName:  CFrientStyleWidget::OnInitAddCreateList
	// Access:    public 
	// Returns:   void
	// Qualifier: 添加朋友列表
	// Parameter: QString strTitle
	//************************************
	void OnInitAddCreateList(QString strTitle);

	void OnInitDevice(QString strDeviceName); //初始化设备

	QDateTime getLastTime();   //（消息列表）获取最后的通信时间。
protected: 
	// wxd add code - start
	void resizeEvent(QResizeEvent * event);  // 窗口改变大小的事件函数   在里面重绘   mCompanyName的label 
	void enterEvent(QEvent * event);         // 鼠标移入事件
	void leaveEvent(QEvent * event);         // 鼠标移出事件 
	// wxd add code - end
private:
	// wxd add code - start
	void InitLayout(int layout_type);           // 初始化布局
	void initChatItemLayout();					// 聊天窗口左边的item 的布局风格
	void initGroupItemLayout();                 // 群组的布局风格
	void initManagerItemLayout();               // 验证消息管理器的布局风格
	void initMessageItemLayout();				// 消息一栏的item 的布局风格
	void initContactsItemLayout();				// 联系人的item 的布局风格
	void initGroupMemberItemLayout();			// 群组成员的item 的布局风格
	void removeLayoutSpacing(QLayout* layout);  // 去掉layout的控件之间的间隙
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // 获取 src_str 适配于 child_widget控件的字符串(加上...的简略信息)
	// wxd add code - end
private slots:
	void doClickAcceptBtn();
signals:
	void sigClickAcceptBtn();
	
private:
	QLabelHeader *mHeadImage;  //头像
    QLabel  *mAutoGraph; //签名/聊天记录
	QLabel  *mMessageNum;   //消息数目
    QLabel  *mMessageTime; // 消息发送时间
    QString mstrPicPath;   //头像路径
	//  wxd add code - start 2017/4/10
	bool	mCGCheckBtnIsChecked; // CG - CreateGroup    标识 mCreateGroupCheckBtn 是否已经被选中
	int     mItemListType;     // 本widget所在item的list的类型
	//  wxd add code - end
	//added by fanwenxing
	QLabel *identity;    //群成员列表项中的身份图标。
public:
    QPushButton *mCloseBtn; 
    QLabel  *mNickName;  //昵称
	QPushButton *mAddPerson; //添加好友
	QPushButton *mAcceptBtn;  //同意按钮;
	// wxd add code - start
	QLabel		*mCreateGroupCheckBtn;		// contacts
	QPushButton *mCreateGroupRemoveBtn; 
	QString		 mStrNickName;				// mNickName的原样字符串
	// wxd add code - end
};

void circleHeaderImage(QPixmap &headerImage);

#endif // CFRIENTSTYLEWIDGET_H
