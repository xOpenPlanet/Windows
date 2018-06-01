// creategroupwidget.h
// ����Ⱥ�� - ͷ�ļ�
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
		not_mine_request = 0,   // ���Ǳ���������http����
		create_group = 1,       // ����Ⱥ��
		add_buddys_to_group     // �򴴽��õ�Ⱥ����ӳ�Ա
	};

public:
	CreateGroupWidget(QWidget *parent = 0);
	~CreateGroupWidget(); 

private:
	void		initTitleBar();								// ��ʼ��������
	void		initChildWidgetLayout();					// ��ʼ���ӿؼ��Ĳ���
	void		initContactsList();							// ��ʼ�������б�ؼ� 
	void		initClassMember();							// ��ʼ�� �����Ա
	void		cleanList(CFriendListWidgetBase* list);		// ���һ��list  delete��item��Ӧ��widget
	void		insertBuddyToList(CFriendListWidgetBase* list, QString str_data, QString str_buddy_id, QString str_pic_path, QString str_nick_name, int n_height=70);  // �� ui.m_listContactsList ����һ��������Ϣ��item
	void		removeItemFromList(CFriendListWidgetBase* list, const QString& buddy_id);   // ��list��ɾ����Ӧbuddy_id��item
	void		updateGroupMembersCountLabel();									// ˢ���½�Ⱥ�ĵĳ�Ա����
	void		doAddBuddyToGroupMemberList(const QString& buddy_id);			// �� Ⱥ�ĳ�Աlist ���һ�����ѵ�item
	void		doRmBuddyInGroupMemberList(const QString& buddy_id);			// �� Ⱥ�ĳ�Աlist �Ƴ�һ�����ѵ�item
	void		doAddBuddysInMemberListToGroup(const QString& group_id);		// �� MemberList �е�buddys���뵽�´�����Ⱥ��
	QStringList	doGetBuddysIdInMemberList();									// ���� MemberList ����ȡ��item�� userID
	void		doParseGroupInfoFromJsonStr(const QString& str_json);			// �� str_json ���� Ⱥ����Ϣ�� m_stGroupInfo
	private slots:
	void		OnContactsListItemClicked(QListWidgetItem* the_item);			// ContactsList �� item ������¼�
	void		OnMemberListItemRemoveBtnClicked(const QString& buddy_id);		// MemberList �� item �ϵĹرհ�ť����¼�
	void		OnCancelBtnClicked();											// ȡ����ť����¼�
	void		OnConfirmBtnClicked();											// ȷ����ť����¼�
	void		OnGetHttpResult(bool success, const QString& result);			// ��ȡ ���� ����Ⱥ���http���� ��Ľ��
signals: 
	void		sigInsertGroupItemToGroupList(GroupInfo group_info);			// ���ͽ��½�Ⱥ�����Ϣ��ӵ�Ⱥ���б���ź� ��IMChatClient::doAddCreateGroup()�й���
	void		sigCreateGroupSuccess(QString group_id);						// ����Ⱥ��ɹ����͸��ź�, IMChatClient��������Ӧ����(�½�/����һ��group �� chat)
private:
	Ui::CreateGroupWidget ui;
	UserInfo			m_stUserInfo;			// ��½���û���Ϣ
	GroupInfo			m_stGroupInfo;			// ������Ⱥ����Ϣ
//	bool				m_bWaitForCGHttpResult; // �ǲ��ǵȴ� CreateGroup��http���	
	bool				m_bWaitForAddBuddysToGroupHttpResult;   // �ȴ� ��Ⱥ����ӳ�Ա ��http���
	QList<BuddyInfo>	m_lstBuddysInfo;		// Ⱥ��ĳ�Ա(buddy)����ϢBuddyInfo
	int					m_nHttpRequestType;		// �ȴ���http�����Ӧ��http��������
};

#endif // CREATEGROUPWIDGET_H
