// creategroupwidget.h
// 创建群聊 - 头文件
// made by: wxd 
// time:	2017-4-7
// meno:	

#ifndef CREATEGROUPWIDGET_H
#define CREATEGROUPWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include "httpnetworksharelib.h"
#include "ui_creategroupwidget.h"
#include "basewindow.h"
#include "cfriendlistwidgetbase.h"
#include "imbuddy.h"
#include "common.h"
#include "stdafx.h"


class CreateGroupWidget : public BaseWindow
{
	Q_OBJECT

	enum http_request_type
	{
		not_mine_request = 0,   // 不是本类做出的http请求
		create_group = 1,       // 创建群组
		add_buddys_to_group     // 向创建好的群组添加成员
	};

public:
	CreateGroupWidget(QWidget *parent = 0);
	~CreateGroupWidget(); 

private:
	void		initTitleBar();								// 初始化标题栏
	void		initChildWidgetLayout();					// 初始化子控件的布局
	void		initContactsList();							// 初始化好友列表控件 
	void		initClassMember();							// 初始化 本类成员
	void		cleanList(CFriendListWidgetBase* list);		// 清空一个list  delete其item对应的widget
	void		insertBuddyToList(CFriendListWidgetBase* list, QString str_data, QString str_buddy_id, QString str_pic_path, QString str_nick_name, int n_height=70);  // 向 ui.m_listContactsList 插入一个好友信息的item
	void		removeItemFromList(CFriendListWidgetBase* list, const QString& buddy_id);   // 从list中删除对应buddy_id的item
	void		updateGroupMembersCountLabel();									// 刷新新建群聊的成员人数
	void		doAddBuddyToGroupMemberList(const QString& buddy_id);			// 向 群聊成员list 添加一个好友的item
	void		doRmBuddyInGroupMemberList(const QString& buddy_id);			// 从 群聊成员list 移除一个好友的item
	void		doAddBuddysInMemberListToGroup(const QString& group_id);		// 将 MemberList 中的buddys加入到新创建的群组
	QStringList	doGetBuddysIdInMemberList();									// 遍历 MemberList 并获取各item的 userID
	void		doParseGroupInfoFromJsonStr(const QString& str_json);			// 从 str_json 解析 群组信息到 m_stGroupInfo
	private slots:
	void		OnContactsListItemClicked(QListWidgetItem* the_item);			// ContactsList 中 item 被点击事件
	void		OnMemberListItemRemoveBtnClicked(const QString& buddy_id);		// MemberList 中 item 上的关闭按钮点击事件
	void		OnCancelBtnClicked();											// 取消按钮点击事件
	void		OnConfirmBtnClicked();											// 确定按钮点击事件
	void		OnGetHttpResult(bool success, const QString& result);			// 获取 发送 创建群组的http请求 后的结果
signals: 
	void		sigInsertGroupItemToGroupList(GroupInfo group_info);			// 发送将新建群组的信息添加到群组列表的信号 在IMChatClient::doAddCreateGroup()中关联
	void		sigCreateGroupSuccess(QString group_id);						// 创建群组成功后发送该信号, IMChatClient捕获并作相应处理(新建/插入一个group 的 chat)
private:
	Ui::CreateGroupWidget ui;
	UserInfo			m_stUserInfo;			// 登陆的用户信息
	GroupInfo			m_stGroupInfo;			// 建立的群组信息
//	bool				m_bWaitForCGHttpResult; // 是不是等待 CreateGroup的http结果	
	bool				m_bWaitForAddBuddysToGroupHttpResult;   // 等待 向群组添加成员 的http结果
	QList<BuddyInfo>	m_lstBuddysInfo;		// 群组的成员(buddy)的信息BuddyInfo
	int					m_nHttpRequestType;		// 等待的http结果对应的http请求类型
};

#endif // CREATEGROUPWIDGET_H
