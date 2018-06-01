#include "creategroupwidget.h"

CreateGroupWidget::CreateGroupWidget(QWidget *parent)
	: BaseWindow(parent), 
	m_nHttpRequestType(http_request_type::not_mine_request)
{
	ui.setupUi(this);
	initTitleBar(); 
	initChildWidgetLayout(); 
	initContactsList(); 
	initClassMember(); 
	this->setWindowFlags(Qt::FramelessWindowHint);		// ȥ�������� �Ҳ����ƶ�
	this->setAttribute(Qt::WA_DeleteOnClose);			// �����ڹرոô���ʱ ֱ�� delete�ô��ڵĶ��� �� close()����������
	connect(ui.m_btnCancel, SIGNAL(clicked()), this, SLOT(OnCancelBtnClicked()));   // ȡ����ť��Ӧ
	connect(ui.m_btnConfirm, SIGNAL(clicked()), this, SLOT(OnConfirmBtnClicked())); // ȷ�ϰ�ť��Ӧ
	
}
CreateGroupWidget::~CreateGroupWidget()
{
	cleanList(ui.m_listContactsList); 
	cleanList(ui.m_listGroupMembers); 
}

// ��ʼ�������Ա
void CreateGroupWidget::initClassMember()
{
	m_stUserInfo = gDataManager->getUserInfo();
	m_stGroupInfo.createTime = ""; 
	m_stGroupInfo.createUserId = ""; 
	m_stGroupInfo.groupId = ""; 
	m_stGroupInfo.groupName = ""; 
	m_stGroupInfo.groupHttpHeadImage = ""; 
	m_stGroupInfo.groupLoacalHeadImage = ""; 
}

// ���һ��list
void CreateGroupWidget::cleanList(CFriendListWidgetBase* list)
{
	QListWidgetItem* cur_item = NULL;
	CFrientStyleWidget* buddy = NULL;
	for (unsigned int i = 0; i < list->count(); i++)
	{
		cur_item = list->item(i);
		if (cur_item)
		{
			list->removeItemWidget(cur_item); 
			delete cur_item; 
			--i; 
		}
	}
}

// ��ʼ��������
void CreateGroupWidget::initTitleBar()
{
	m_titleBar->setTitleIcon(":/Login/Resources/login/system.png");
	m_titleBar->setTitleContent(QStringLiteral("����Ⱥ��"), 10);
	m_titleBar->setBackgroundColor(78, 103, 165);
	m_titleBar->setTitleContentBKColor("color:white;");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

// ��ʼ���ӿؼ�
// ����:	1 ������1/5���ֵ�label�ı���ɫ����
//		2 ȥ������QListWidget�ı߿�
//		3 �ڿͻ����м䲿�ֻ�һ���ָ���
void CreateGroupWidget::initChildWidgetLayout()
{	
	// ���� ������1/5���ֵ�label�ı���ɫ
	ui.m_lbAboveBkColorLeft->setStyleSheet("background-color:#F0F8FF;");
	ui.m_lbAboveBkColorRight->setStyleSheet("background-color:#F0F8FF;");

	// ���� ȷ�� ȡ�� ��ť����ı���ɫ
	ui.m_lbBelowBkColorRight->setStyleSheet("QLabel#m_lbBelowBkColorRight{background-color:#F0F8FF}"); 
	
	// ȥ�� QListWidget�ı߿�
	ui.m_listContactsList->setFrameShape(QFrame::NoFrame);
	ui.m_listGroupMembers->setFrameShape(QFrame::NoFrame); 
	ui.m_listContactsList->setStyleSheet("QListWidget#m_listContactsList{background-color:#F0F8FF;}");
	ui.m_listGroupMembers->setStyleSheet("QListWidget#m_listGroupMembers{background-color:#F0F8FF;}");

	// �ڴ����м仭һ��ֱ��
	const int wnd_mid_x = 285; 
	QPainter painter(this);
	painter.setPen( QPen(QColor(0xF5,0xF5,0xDC)) ); // ���û�����ʽ
	painter.drawLine(wnd_mid_x, 0, wnd_mid_x, 410); // ��ֱ��

	// ��ʼ�� line text Ⱥ������
	ui.m_lineSearchText->setPlaceholderText(QString("����")); 
	ui.m_lineGroupName->setPlaceholderText(QString("Ⱥ������")); 
}

// ��ʼ�� ContactsList 
// �������б���뵽 ContactsList
void CreateGroupWidget::initContactsList()
{
	if (gDataBaseOpera)
	{
		QMap<QString, QList<BuddyInfo> > contacts_map = gDataBaseOpera->DB_GetBuddyInfo();
		QMap<QString, QList<BuddyInfo> >::iterator itor = contacts_map.begin();
		for (; itor != contacts_map.end(); ++itor)
		{
			// ���� buddy_label ��list item   buddy_label -- A B C.....
			QString buddys_label = itor.key();
			QListWidgetItem *newItem = new QListWidgetItem(buddys_label);
			newItem->setSizeHint(QSize(this->width(), 25));
			newItem->setData(Qt::UserRole, buddys_label);
			newItem->setFlags(Qt::ItemFlag::NoItemFlags);			// ����ǩ���������flag ��������item����
			ui.m_listContactsList->insertItem(ui.m_listContactsList->count(), newItem);         //�ӵ�QListWidget��

			// �� QList<BuddyInfo> �еĳ�Ա����֮���list item 
			// buddys Ϊָ�� QList<BuddyInfo>��ָ��
			QList<BuddyInfo>&  buddys = itor.value();
			for (int i = 0; i < buddys.size(); ++i)
			{
				int nFlags = 0;
				QString strAvatar = (buddys[i]).strLocalAvatar;
				QString strNickName = (buddys[i]).strNickName;
				QString strNote = (buddys[i]).strNote;
				QString strBuddyID = QString("%1").arg((buddys[i]).nUserId);

				if (!strNote.isEmpty())
				{
					insertBuddyToList(ui.m_listContactsList, buddys_label, strBuddyID, strAvatar, strNote);
					//ui.m_listContactsList->OnInsertContacts(itor.key(), strBuddyID, strAvatar, strNote); 
				}
				else
				{
					insertBuddyToList(ui.m_listContactsList, buddys_label, strBuddyID, strAvatar, strNickName);
					//ui.m_listContactsList->OnInsertContacts(itor.key(), strBuddyID, strAvatar, strNickName);
				}
			}
		}
	}
	// ���� m_listContactsList ��item����ʱ��� �źźͲ�
	connect(ui.m_listContactsList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnContactsListItemClicked(QListWidgetItem*)));
}


// ��list���һ�������� buddy�����item
void CreateGroupWidget::insertBuddyToList(CFriendListWidgetBase* list, QString str_data, QString str_buddy_id, QString str_pic_path, QString str_nick_name, int n_height)
{
	CFrientStyleWidget *buddy = new CFrientStyleWidget(); 
	if (ui.m_listContactsList == list)
	{
		buddy->OnInitCreateGroupContactsList(str_buddy_id);
	}		
	else if (ui.m_listGroupMembers == list)
	{
		buddy->OnInitCreateGroupMemberList(str_buddy_id);
		connect(buddy, SIGNAL(sigRemoveBuddyFromCGMemberList(QString)), this, SLOT(OnMemberListItemRemoveBtnClicked(QString)));
	}
		
	buddy->OnSetPicPath(str_pic_path);
	buddy->OnSetNickNameText(str_nick_name);

	QListWidgetItem *newItem = new QListWidgetItem(); //����һ��newItem
	newItem->setSizeHint(QSize(list->width(), n_height)); 
	newItem->setData(Qt::UserRole, str_buddy_id);

	list->insertItem(list->count(), newItem); //����newItem���뵽����
	list->setItemWidget(newItem, buddy); //��buddy������newItem
}

// list's item ������¼�
// �ı� �������item��CheckBtn��״̬
//	1 ״̬Ϊѡ�� -- ���һ��buddy��MemberList
//  2 ״̬Ϊδѡ�� -- ��MemberList�и���buddy->objectName()ɾ��һ��item
void CreateGroupWidget::OnContactsListItemClicked(QListWidgetItem* the_item)
{
	// ���itemʱ��ǩ(buddy_label)�Ļ� ֱ�ӷ��� �����κδ���
	if (the_item->flags() == Qt::ItemFlag::NoItemFlags)
		return; 

	CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.m_listContactsList->itemWidget(the_item);
	if (buddy == NULL)
	{
		qDebug() << "CreateGroupWidget::OnContactsListItemClicked��ָ��";
		return;
	}
	buddy->changeCGCheckBtnStatus(); 
	const bool btn_is_checked = true; 
	if (buddy->getCGCheckBtnStatus() == btn_is_checked)
	{
		doAddBuddyToGroupMemberList(buddy->objectName());
	}
	else
	{
		doRmBuddyInGroupMemberList(buddy->objectName()); 
	}
	
}

// MemberList's item �ϵ�remove��ť����¼�
void CreateGroupWidget::OnMemberListItemRemoveBtnClicked(const QString& buddy_id)
{
	doRmBuddyInGroupMemberList(buddy_id); 
	CFriendListWidgetBase* list = ui.m_listContactsList; 
	QListWidgetItem* cur_item = NULL;
	CFrientStyleWidget* buddy = NULL;
	for (int i = 0; i < list->count(); i++)
	{
		cur_item = list->item(i);
		if (cur_item)
			buddy = (CFrientStyleWidget*)list->itemWidget(cur_item);
		if (buddy)
		{
			if (buddy->objectName().compare(buddy_id) == 0)
			{
				buddy->changeCGCheckBtnStatus(); 
			}
		}
	}
}

// �� ui.m_listGroupMembers �����һ��item   ���� item.objectName() = buddy_id
void CreateGroupWidget::doAddBuddyToGroupMemberList(const QString& buddy_id)
{
	if (gDataBaseOpera)
	{
		QMap<QString, QList<BuddyInfo> > contacts_map = gDataBaseOpera->DB_GetBuddyInfo();
		QMap<QString, QList<BuddyInfo> >::iterator itor = contacts_map.begin();
		for (; itor != contacts_map.end(); ++itor)
		{
			// buddys_label -- A B C....
			QString buddys_label = itor.key();

			// buddys Ϊָ�� QList<BuddyInfo>��ָ��
			QList<BuddyInfo>&  buddys = itor.value();
			for (int i = 0; i < buddys.size(); ++i)
			{
				QString strBuddyID = QString("%1").arg((buddys[i]).nUserId);
				if (strBuddyID.compare(buddy_id) != 0)
					continue; 

				QString strAvatar = (buddys[i]).strLocalAvatar; 
				QString strNickName = (buddys[i]).strNickName; 
				QString strNote = (buddys[i]).strNote; 
				
				if (!strNote.isEmpty())
				{
					insertBuddyToList(ui.m_listGroupMembers, buddys_label, strBuddyID, strAvatar, strNote);
					//ui.m_listContactsList->OnInsertContacts(itor.key(), strBuddyID, strAvatar, strNote); 
				}
				else
				{
					insertBuddyToList(ui.m_listGroupMembers, buddys_label, strBuddyID, strAvatar, strNickName);
					//ui.m_listContactsList->OnInsertContacts(itor.key(), strBuddyID, strAvatar, strNickName);
				}
				m_lstBuddysInfo.append(buddys[i]);        // ����Ա��ӵ�QList<BuddyInfo>
			}
		}
	}
	updateGroupMembersCountLabel(); 
}

// �� ui.m_listGroupMembers ��ɾ��һ��item   ���� item.objectName() == buddy_id
void CreateGroupWidget::doRmBuddyInGroupMemberList(const QString& buddy_id)
{
	removeItemFromList(ui.m_listGroupMembers, buddy_id); 
	updateGroupMembersCountLabel(); 
	// �� QList<BuddyInfo> ��ɾ����Ӧbuddy_id����
	for (int i = 0; i < m_lstBuddysInfo.count(); ++i)
	{
		QString cur_buddy_id = QString::number(m_lstBuddysInfo.at(i).nUserId); 
		if (cur_buddy_id.compare(buddy_id) == 0)
		{
			m_lstBuddysInfo.removeAt(i); 
			return; 
		}
	}
}


// ��list��ɾ����Ӧbuddy_id��item
void CreateGroupWidget::removeItemFromList(CFriendListWidgetBase* list, const QString& buddy_id)
{
	QListWidgetItem* cur_item = NULL;
	CFrientStyleWidget* buddy = NULL;
	for (unsigned int i = 0; i < list->count(); i++)
	{
		cur_item = list->item(i);
		if (cur_item)
			buddy = (CFrientStyleWidget*)list->itemWidget(cur_item);
		if (buddy)
		{
			if (buddy->objectName().compare(buddy_id) == 0)
			{
				list->removeItemWidget(cur_item);
				delete cur_item;
				break;
			}
		}
	}
}

// ˢ���½�Ⱥ�ĵĳ�Ա����
// ÿ���������䶯ʱ ���øú���
void CreateGroupWidget::updateGroupMembersCountLabel()
{
	QString str_info_show(""); 
	QString str_count = QString::number(ui.m_listGroupMembers->count()); 
	if (str_count.compare("0")==0)
		str_info_show = "�빴ѡ��Ҫ��ӵ���ϵ��"; 
	else
		str_info_show = QString("�Ѿ�ѡ����") + str_count + QString("����ϵ��"); 
	ui.m_lbShowGroupMembersCount->setText(str_info_show); 
}

// ȡ����ť ����¼�
void CreateGroupWidget::OnCancelBtnClicked()
{
	this->close(); 
}

// ȷ����ť ����¼�
// �ж�Ⱥ���Ա���� �����С��1��(����������) ����Ⱥ��
void CreateGroupWidget::OnConfirmBtnClicked()
{
	if (ui.m_listGroupMembers->count() < 1)
		return; 
	QString str_group_name = ui.m_lineGroupName->text(); 
	if (str_group_name.isEmpty())
		str_group_name = "�ҵ�Ⱥ��"; 

	UserInfo user = gDataManager->getUserInfo();
	
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(OnGetHttpResult(bool, QString)));

	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/createGroup"
		+ QString("?userId=%1&passWord=%2&groupName=%3").arg(user.nUserID).arg(user.strUserPWD).arg(str_group_name);

	http->getHttpRequest(url);
}

// �õ�����Ⱥ���http���
void CreateGroupWidget::OnGetHttpResult(bool success, const QString& result)
{
	if (m_nHttpRequestType == http_request_type::not_mine_request)
		return; 
	switch (m_nHttpRequestType)
	{
	case http_request_type::create_group:
	{
		if (success)
		{
			// ����Ⱥ��ɹ�
			doParseGroupInfoFromJsonStr(result);			// ����json �õ�Ⱥ����Ϣ ���浽 m_stGroupInfo
			if (m_stGroupInfo.groupLoacalHeadImage.isEmpty()) // ��Ⱥ����Ϣ����Ĭ��Ⱥ��ͷ��
				m_stGroupInfo.groupLoacalHeadImage = ":/GroupChat/Resources/groupchat/group.png";
			doAddBuddysInMemberListToGroup(m_stGroupInfo.groupId);   // ����Ⱥ��ɹ��� ��Ⱥ����ӳ�Ա
			return; 
		}
		else
		{
			QMessageBox::information(this, QStringLiteral("ע��"), QStringLiteral("����Ⱥ��ʧ��"));
			return;
		}
		m_nHttpRequestType = http_request_type::not_mine_request;     // ���괦���ı� m_nHttpRequestType��ֵ ��ֹ���������http���Ҳ����case����
	}
		break;
	case http_request_type::add_buddys_to_group:
		if (success)
		{
			//�������ݿ�
			gDataBaseOpera->DBInsertGroupInfo(m_stGroupInfo);

			// �����ź�    ��Ⱥ����Ϣ��ӵ�Ⱥ���б�
			emit sigInsertGroupItemToGroupList(m_stGroupInfo);
			
			// ���ʹ���Ⱥ��ɹ����ź� �� IMChatClient
			emit sigCreateGroupSuccess(m_stGroupInfo.groupId); 

			this->close();
		}
		else
		{
			// ����Ⱥ��ʧ��
			QMessageBox::information(this, QStringLiteral("ע��"), QStringLiteral("����Ⱥ��ʧ��"));
			return;
		}
		m_nHttpRequestType = http_request_type::not_mine_request; 
		break; 
	default:
		m_nHttpRequestType = http_request_type::not_mine_request; 
		break; 
	}
}

// �� str_json ���� Ⱥ����Ϣ�� m_stGroupInfo
void CreateGroupWidget::doParseGroupInfoFromJsonStr(const QString& str_json)
{
	QString str_value(""); 
	QJsonParseError jsonError;
	QJsonDocument jsonDocument = QJsonDocument::fromJson(str_json.toUtf8(), &jsonError);
	if (jsonError.error == QJsonParseError::NoError)
	{
		if (jsonDocument.isObject())
		{
			QJsonObject obj = jsonDocument.object();

			if (obj["result"].toString() == "success")
			{
				QJsonValue groupValue = obj.take("group");    // group��Ӧ��ֵ�� map
				if (groupValue.isUndefined())
					return; 
				QVariant groupValueVar = groupValue.toVariant(); // �õ�groupValue��Ӧ��ֵ
				if (groupValue.isObject())
				{
					QVariantMap groupMap = groupValueVar.toMap();	// ��groupValue��ֵתΪmap
					m_stGroupInfo.groupId = groupMap["groupId"].toString(); 
					m_stGroupInfo.groupName = groupMap["groupName"].toString(); 
					m_stGroupInfo.createTime = groupMap["createTime"].toString();
					m_stGroupInfo.createUserId = groupMap["createUserId"].toString(); 
				}			
			}
		}
	}
}

// �� MemberList �е����г�Ա��ӵ��½���Ⱥ����
void CreateGroupWidget::doAddBuddysInMemberListToGroup(const QString& group_id)
{
	QString str_buddy_ids("");    // Ⱥ���Ա��userid(�Ե�¼�û���˵����buddy_id)  �� ':' ����
	QStringList buddy_ids = doGetBuddysIdInMemberList(); 
	for (int i = 0; i < buddy_ids.count(); i++)
	{
		str_buddy_ids += buddy_ids[i]; 
		if (i + 1 < buddy_ids.count())
			str_buddy_ids += ";";
	}
	if (str_buddy_ids.isEmpty())
		qDebug("Create group success, but no buddy add in."); 

	UserInfo user = gDataManager->getUserInfo();

	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(OnGetHttpResult(bool, QString)));

	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/addUserToGroup"
		+ QString("?userId=%1&passWord=%2&addUserId=%3&groupId=%4").arg(user.nUserID).arg(user.strUserPWD).arg(str_buddy_ids).arg(group_id);

	http->getHttpRequest(url);
}

QStringList CreateGroupWidget::doGetBuddysIdInMemberList()
{
	QStringList buddy_ids; 
	CFriendListWidgetBase* group_members = ui.m_listGroupMembers; 
	if (group_members)
	{
		QListWidgetItem* cur_member = NULL; 
		for (int i = 0; i < group_members->count(); i++)
		{
			cur_member = group_members->item(i); 
			if (cur_member)
			{
				// �� �½�itemʱ��buddy_id��Ϊ�û��Զ������ݱ����� item->setData(Qt::UserRole,buddy_id)
				QString buddy_id = cur_member->data(Qt::UserRole).toString(); 
				if (!buddy_id.isEmpty())
					buddy_ids.append(buddy_id); 
			}
		} // ���� group_members
	}
	return buddy_ids; 
}

/*
void CreateGroupWidget::paintEvent(QPaintEvent* event)
{
	//���ñ���ɫ;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(0xF0, 0xF8, 0xFF)));

	// ��������󻯻��߻�ԭ�󣬴��ڳ��ȱ��ˣ��������ĳ���Ӧ��һ��ı�;
	// �����ȥm_windowBorderWidth ������Ϊ���ڿ��������˲�ͬ��ȵı߿�;
	// ��������б߿�����Ҫ����m_windowBorderWidth��ֵ������m_windowBorderWidthĬ��Ϊ0;
	//if (this->width() != (this->parentWidget()->width() - m_windowBorderWidth))
	//{
	//	this->setFixedWidth(this->parentWidget()->width() - m_windowBorderWidth);
	//}
	QWidget::paintEvent(event);
}
*/

// ��������¼� 
// ����: ʹû�б������Ĵ��ڿ����ƶ�
/*
void CreateGroupWidget::mousePressEvent(QMouseEvent *mouse_event)
{
	m_ptLastMousePos = mouse_event->globalPos();
}
void CreateGroupWidget::mouseMoveEvent(QMouseEvent *mouse_event)
{
	int dx = mouse_event->globalX() - m_ptLastMousePos.x();
	int dy = mouse_event->globalY() - m_ptLastMousePos.y();
	m_ptLastMousePos = mouse_event->globalPos();
	move(x() + dx, y() + dy);
}
void CreateGroupWidget::mouseReleaseEvent(QMouseEvent *mouse_event)
{
	int dx = mouse_event->globalX() - m_ptLastMousePos.x();
	int dy = mouse_event->globalY() - m_ptLastMousePos.y();
	move(x() + dx, y() + dy);
}*/