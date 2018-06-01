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
	this->setWindowFlags(Qt::FramelessWindowHint);		// 去掉标题栏 且不能移动
	this->setAttribute(Qt::WA_DeleteOnClose);			// 设置在关闭该窗口时 直接 delete该窗口的对象 即 close()走析构函数
	connect(ui.m_btnCancel, SIGNAL(clicked()), this, SLOT(OnCancelBtnClicked()));   // 取消按钮响应
	connect(ui.m_btnConfirm, SIGNAL(clicked()), this, SLOT(OnConfirmBtnClicked())); // 确认按钮响应
	
}
CreateGroupWidget::~CreateGroupWidget()
{
	cleanList(ui.m_listContactsList); 
	cleanList(ui.m_listGroupMembers); 
}

// 初始化本类成员
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

// 清空一个list
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

// 初始化标题栏
void CreateGroupWidget::initTitleBar()
{
	m_titleBar->setTitleIcon(":/Login/Resources/login/system.png");
	m_titleBar->setTitleContent(QStringLiteral("创建群组"), 10);
	m_titleBar->setBackgroundColor(78, 103, 165);
	m_titleBar->setTitleContentBKColor("color:white;");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

// 初始化子控件
// 功能:	1 窗口上1/5部分的label的背景色设置
//		2 去掉两个QListWidget的边框
//		3 在客户区中间部分画一条分割线
void CreateGroupWidget::initChildWidgetLayout()
{	
	// 设置 窗口上1/5部分的label的背景色
	ui.m_lbAboveBkColorLeft->setStyleSheet("background-color:#F0F8FF;");
	ui.m_lbAboveBkColorRight->setStyleSheet("background-color:#F0F8FF;");

	// 设置 确定 取消 按钮后面的背景色
	ui.m_lbBelowBkColorRight->setStyleSheet("QLabel#m_lbBelowBkColorRight{background-color:#F0F8FF}"); 
	
	// 去掉 QListWidget的边框
	ui.m_listContactsList->setFrameShape(QFrame::NoFrame);
	ui.m_listGroupMembers->setFrameShape(QFrame::NoFrame); 
	ui.m_listContactsList->setStyleSheet("QListWidget#m_listContactsList{background-color:#F0F8FF;}");
	ui.m_listGroupMembers->setStyleSheet("QListWidget#m_listGroupMembers{background-color:#F0F8FF;}");

	// 在窗口中间画一条直线
	const int wnd_mid_x = 285; 
	QPainter painter(this);
	painter.setPen( QPen(QColor(0xF5,0xF5,0xDC)) ); // 设置画笔形式
	painter.drawLine(wnd_mid_x, 0, wnd_mid_x, 410); // 画直线

	// 初始化 line text 群聊名称
	ui.m_lineSearchText->setPlaceholderText(QString("搜索")); 
	ui.m_lineGroupName->setPlaceholderText(QString("群聊名称")); 
}

// 初始化 ContactsList 
// 将好友列表插入到 ContactsList
void CreateGroupWidget::initContactsList()
{
	if (gDataBaseOpera)
	{
		QMap<QString, QList<BuddyInfo> > contacts_map = gDataBaseOpera->DB_GetBuddyInfo();
		QMap<QString, QList<BuddyInfo> >::iterator itor = contacts_map.begin();
		for (; itor != contacts_map.end(); ++itor)
		{
			// 创建 buddy_label 的list item   buddy_label -- A B C.....
			QString buddys_label = itor.key();
			QListWidgetItem *newItem = new QListWidgetItem(buddys_label);
			newItem->setSizeHint(QSize(this->width(), 25));
			newItem->setData(Qt::UserRole, buddys_label);
			newItem->setFlags(Qt::ItemFlag::NoItemFlags);			// 给标签设置特殊的flag 供与正常item区别
			ui.m_listContactsList->insertItem(ui.m_listContactsList->count(), newItem);         //加到QListWidget中

			// 将 QList<BuddyInfo> 中的成员加入之后的list item 
			// buddys 为指向 QList<BuddyInfo>的指针
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
	// 关联 m_listContactsList 的item单击时间的 信号和槽
	connect(ui.m_listContactsList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnContactsListItemClicked(QListWidgetItem*)));
}


// 向list添加一个被赋予 buddy对象的item
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

	QListWidgetItem *newItem = new QListWidgetItem(); //创建一个newItem
	newItem->setSizeHint(QSize(list->width(), n_height)); 
	newItem->setData(Qt::UserRole, str_buddy_id);

	list->insertItem(list->count(), newItem); //将该newItem插入到后面
	list->setItemWidget(newItem, buddy); //将buddy赋给该newItem
}

// list's item 被点击事件
// 改变 被点击的item的CheckBtn的状态
//	1 状态为选中 -- 添加一个buddy到MemberList
//  2 状态为未选中 -- 从MemberList中根据buddy->objectName()删除一个item
void CreateGroupWidget::OnContactsListItemClicked(QListWidgetItem* the_item)
{
	// 如果item时标签(buddy_label)的话 直接返回 不做任何处理
	if (the_item->flags() == Qt::ItemFlag::NoItemFlags)
		return; 

	CFrientStyleWidget *buddy = (CFrientStyleWidget*)ui.m_listContactsList->itemWidget(the_item);
	if (buddy == NULL)
	{
		qDebug() << "CreateGroupWidget::OnContactsListItemClicked空指针";
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

// MemberList's item 上的remove按钮点击事件
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

// 向 ui.m_listGroupMembers 中添加一个item   设置 item.objectName() = buddy_id
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

			// buddys 为指向 QList<BuddyInfo>的指针
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
				m_lstBuddysInfo.append(buddys[i]);        // 将成员添加到QList<BuddyInfo>
			}
		}
	}
	updateGroupMembersCountLabel(); 
}

// 从 ui.m_listGroupMembers 中删除一个item   根据 item.objectName() == buddy_id
void CreateGroupWidget::doRmBuddyInGroupMemberList(const QString& buddy_id)
{
	removeItemFromList(ui.m_listGroupMembers, buddy_id); 
	updateGroupMembersCountLabel(); 
	// 从 QList<BuddyInfo> 中删除对应buddy_id的项
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


// 从list中删除对应buddy_id的item
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

// 刷新新建群聊的成员人数
// 每次有人数变动时 调用该函数
void CreateGroupWidget::updateGroupMembersCountLabel()
{
	QString str_info_show(""); 
	QString str_count = QString::number(ui.m_listGroupMembers->count()); 
	if (str_count.compare("0")==0)
		str_info_show = "请勾选需要添加的联系人"; 
	else
		str_info_show = QString("已经选择了") + str_count + QString("个联系人"); 
	ui.m_lbShowGroupMembersCount->setText(str_info_show); 
}

// 取消按钮 点击事件
void CreateGroupWidget::OnCancelBtnClicked()
{
	this->close(); 
}

// 确定按钮 点击事件
// 判断群组成员人数 如果不小于1人(不包含本人) 创建群组
void CreateGroupWidget::OnConfirmBtnClicked()
{
	if (ui.m_listGroupMembers->count() < 1)
		return; 
	QString str_group_name = ui.m_lineGroupName->text(); 
	if (str_group_name.isEmpty())
		str_group_name = "我的群聊"; 

	UserInfo user = gDataManager->getUserInfo();
	
	HttpNetWork::HttpNetWorkShareLib *http = new HttpNetWork::HttpNetWorkShareLib;
	connect(http, SIGNAL(sigReplyFinished(bool, QString)), this, SLOT(OnGetHttpResult(bool, QString)));

	QString url = gDataManager->getAppConfigInfo().MessageServerAddress + "/IMServer/group/createGroup"
		+ QString("?userId=%1&passWord=%2&groupName=%3").arg(user.nUserID).arg(user.strUserPWD).arg(str_group_name);

	http->getHttpRequest(url);
}

// 拿到创建群组的http结果
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
			// 创建群组成功
			doParseGroupInfoFromJsonStr(result);			// 解析json 得到群组信息 保存到 m_stGroupInfo
			if (m_stGroupInfo.groupLoacalHeadImage.isEmpty()) // 给群组信息加上默认群组头像
				m_stGroupInfo.groupLoacalHeadImage = ":/GroupChat/Resources/groupchat/group.png";
			doAddBuddysInMemberListToGroup(m_stGroupInfo.groupId);   // 创建群组成功后 向群组添加成员
			return; 
		}
		else
		{
			QMessageBox::information(this, QStringLiteral("注意"), QStringLiteral("创建群组失败"));
			return;
		}
		m_nHttpRequestType = http_request_type::not_mine_request;     // 做完处理后改变 m_nHttpRequestType的值 防止其他请求的http结果也被该case处理
	}
		break;
	case http_request_type::add_buddys_to_group:
		if (success)
		{
			//更新数据库
			gDataBaseOpera->DBInsertGroupInfo(m_stGroupInfo);

			// 发送信号    将群组信息添加到群组列表
			emit sigInsertGroupItemToGroupList(m_stGroupInfo);
			
			// 发送创建群组成功的信号 到 IMChatClient
			emit sigCreateGroupSuccess(m_stGroupInfo.groupId); 

			this->close();
		}
		else
		{
			// 创建群组失败
			QMessageBox::information(this, QStringLiteral("注意"), QStringLiteral("创建群组失败"));
			return;
		}
		m_nHttpRequestType = http_request_type::not_mine_request; 
		break; 
	default:
		m_nHttpRequestType = http_request_type::not_mine_request; 
		break; 
	}
}

// 从 str_json 解析 群组信息到 m_stGroupInfo
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
				QJsonValue groupValue = obj.take("group");    // group对应的值是 map
				if (groupValue.isUndefined())
					return; 
				QVariant groupValueVar = groupValue.toVariant(); // 拿到groupValue对应的值
				if (groupValue.isObject())
				{
					QVariantMap groupMap = groupValueVar.toMap();	// 将groupValue的值转为map
					m_stGroupInfo.groupId = groupMap["groupId"].toString(); 
					m_stGroupInfo.groupName = groupMap["groupName"].toString(); 
					m_stGroupInfo.createTime = groupMap["createTime"].toString();
					m_stGroupInfo.createUserId = groupMap["createUserId"].toString(); 
				}			
			}
		}
	}
}

// 将 MemberList 中的所有成员添加到新建的群组中
void CreateGroupWidget::doAddBuddysInMemberListToGroup(const QString& group_id)
{
	QString str_buddy_ids("");    // 群组成员的userid(对登录用户来说即是buddy_id)  用 ':' 隔开
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
				// 在 新建item时将buddy_id作为用户自定义数据保存在 item->setData(Qt::UserRole,buddy_id)
				QString buddy_id = cur_member->data(Qt::UserRole).toString(); 
				if (!buddy_id.isEmpty())
					buddy_ids.append(buddy_id); 
			}
		} // 遍历 group_members
	}
	return buddy_ids; 
}

/*
void CreateGroupWidget::paintEvent(QPaintEvent* event)
{
	//设置背景色;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(0xF0, 0xF8, 0xFF)));

	// 当窗口最大化或者还原后，窗口长度变了，标题栏的长度应当一起改变;
	// 这里减去m_windowBorderWidth ，是因为窗口可能设置了不同宽度的边框;
	// 如果窗口有边框则需要设置m_windowBorderWidth的值，否则m_windowBorderWidth默认为0;
	//if (this->width() != (this->parentWidget()->width() - m_windowBorderWidth))
	//{
	//	this->setFixedWidth(this->parentWidget()->width() - m_windowBorderWidth);
	//}
	QWidget::paintEvent(event);
}
*/

// 三个鼠标事件 
// 功能: 使没有标题栏的窗口可以移动
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