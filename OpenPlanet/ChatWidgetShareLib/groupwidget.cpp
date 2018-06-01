#include "groupwidget.h"
#include <QFileDialog>

GroupWidget::GroupWidget(QWidget *parent)
	: QWidget(parent),
	mChatHeaderImage(NULL)
{
	ui.setupUi(this);
	//������ʽ
	QFile file(":/GroupChat/Resources/QSS/groupchat.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();

	this->setAcceptDrops(true);//֧���Ϸ�
	ui.mTButtonGroupFile->setText("�ļ�");
	RegisterHandle();

	setChildWidgetFixedSize(); 
	initLayout(); 

	ui.mPButtonGroupSpace->hide();
	setAttribute(Qt::WA_DeleteOnClose, true);
}

GroupWidget::~GroupWidget()
{
	if (mGroupChatWidget)
	{
		delete mGroupChatWidget;
		mGroupChatWidget = NULL;
	}

	if (mChatHeaderImage)
		delete mChatHeaderImage;
}

void GroupWidget::RegisterHandle()
{
	mGroupChatWidget = new GroupChatWidget(this);
	ui.mGroupStackedWidget->addWidget(mGroupChatWidget);

	if (!mChatHeaderImage)
		mChatHeaderImage = new QLabelHeader(this); 
	mChatHeaderImage->hide(); 

	connect(mGroupChatWidget, SIGNAL(sigClose()), this, SLOT(slotGroupSendClose()));
	connect(mGroupChatWidget, SIGNAL(sigShowPerChat(QString)), this, SLOT(slotShowPerChat(QString)));
	connect(mGroupChatWidget, SIGNAL(sigGroupBuddyPerChat(QString)), this, SLOT(slotGroupBuddyPerChat(QString)));
	connect(mGroupChatWidget, SIGNAL(sigShowNormalWindow()), this, SLOT(slotShowNormalWindow()));
	connect(mGroupChatWidget, SIGNAL(sigShowWindowMinsize()), this, SLOT(slotClickedMinSize()));
	//�ռ�
	connect(ui.mPButtonGroupSpace, SIGNAL(clicked()), this, SLOT(slotClickedGroupSpace()));
	//�ļ�
	connect(ui.mTButtonGroupFile, SIGNAL(clicked()), this, SLOT(slotClickedGroupFile()));

	connect(this, SIGNAL(sigGroupFile()), mGroupChatWidget,SLOT(slotGroupFile()));
	connect(mGroupChatWidget, SIGNAL(sigBtnCloseWClicked()), this, SLOT(slotOnGroupChatBtnCloseWClicked())); 
	connect(mGroupChatWidget, SIGNAL(sigOpenMessageLog()), this, SLOT(slotOpenGroupLog()));

	connect(mGroupChatWidget, SIGNAL(sigKeyUpDown(QKeyEvent *)), this, SIGNAL(sigKeyUpDown(QKeyEvent *)));
}

void GroupWidget::slotOpenGroupLog()
{
	emit sigOpenGroupLog(objectName());
}

void GroupWidget::mousePressEvent(QMouseEvent *event)
{
	QRect rect;
	rect = QRect(ui.mGroupLabelBK->pos() + this->pos(), ui.mGroupLabelBK->size());
	mGroupChatWidget->ExpressHide(rect, event->pos());
	rect = QRect(ui.mLabelGroupNickChat->pos() + this->pos(), ui.mLabelGroupNickChat->size());
	mGroupChatWidget->ExpressHide(rect, event->pos());

	return QWidget::mousePressEvent(event);
}

void GroupWidget::OnSetGroupName(QString strGroupName, QString strGroupID)
{
	ui.mLabelGroupNickChat->setText(strGroupName);
	mGroupChatWidget->setNikeName(strGroupName);
	ui.mLabelGroupNickChat->setObjectName(strGroupID);

	QFont font;
	font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font.setPointSize(16);
	QFontMetrics fm(font);
	int str_width = fm.width(strGroupName);
	ui.mLabelGroupNickChat->setFixedSize(str_width + 8, ui.mLabelGroupNickChat->height());
	ui.mLabelGroupNickChat->setStyleSheet("background-color: #042439;color:#108ee9; ");
}

void GroupWidget::OnInsertGroupUserList(QString strGroupID)
{
	mGroupChatWidget->OnInsertGroupUserList(strGroupID);
}

void GroupWidget::OnInsertGroupUser(BuddyInfo info)
{
	mGroupChatWidget->OnInsertGroupUser(info);
}

void GroupWidget::slotShowPerChat(QString strBuddyID)
{
	emit sigShowPerChat(strBuddyID);
}

//�ر�
void GroupWidget::slotClickedClose()
{
	slotGroupSendClose();
}
//���
void GroupWidget::slotClickedMaxSize()
{

}
//��С��
void GroupWidget::slotClickedMinSize()
{
	emit sigGroupMinSize();
}
//����ռ�
void GroupWidget::slotClickedGroupSpace()
{
	OnCloseExpress();
}
//���Ⱥ�� ����
void GroupWidget::slotClickedGroupChat()
{
	OnCloseExpress();
}
//����ļ�
void GroupWidget::slotClickedGroupFile()
{
	OnCloseExpress();
	emit sigGroupFile();
}
//�������
void GroupWidget::slotClickedGroupNotice()
{
	OnCloseExpress();
}
//���ͼƬ
void GroupWidget::slotClickedGroupPic()
{
	OnCloseExpress();
}
//����
void GroupWidget::slotClickedGroupTalk()
{
	OnCloseExpress();
}
//����
void GroupWidget::slotClickedGroupMore()
{
	OnCloseExpress();
}

void GroupWidget::OnInitMessage(QString strFromUserID)
{
	mGroupChatWidget->InitMessageInfo(ui.mLabelGroupNickChat->objectName(), ui.mLabelGroupNickChat->objectName());
}

void GroupWidget::OnInsertRevMessage(MessageInfo message)
{
	mGroupChatWidget->OnRevMessage(message);
}

void GroupWidget::OnCloseExpress()
{
	if (mGroupChatWidget != NULL)
		mGroupChatWidget->OnCloseExpress();
}

void GroupWidget::slotGroupSendClose()
{
	emit sigGroupClose();
}

void GroupWidget::OnUpdateGroupBuddyHeaderImg(QString strBuddyID, QString strPath)
{
	if (mGroupChatWidget != NULL)
	{
		mGroupChatWidget->OnUpdateGroupBuddyHeaderImg(strBuddyID, strPath);
	}
}

void GroupWidget::UpdateMessageStateInfo(QByteArray msgID, int nState, int integral)
{
	if (mGroupChatWidget)
	{
		mGroupChatWidget->UpdateMessageStateInfo(msgID, nState, integral);
	}
}

void GroupWidget::OnInertSendMessageTextInfo(QString strMsg, QString strrAvatarLocal, MessageInfo msgInfo)
{
	if (mGroupChatWidget)
	{
		mGroupChatWidget->OnInertSendMessageTextInfo(strMsg, strrAvatarLocal, msgInfo);
	}
}


void GroupWidget::slotOnGroupChatBtnCloseWClicked()
{
	emit sigGroupWidgetBtnCloseWClicked(); 
}

// ��ʼ���ؼ��Ĺ̶��߶�
void GroupWidget::setChildWidgetFixedSize()
{
	QLabel* nick = ui.mLabelGroupNickChat;
	QToolButton* file = ui.mTButtonGroupFile;
	QLabel* back_top = ui.mGroupLabelBK;

	ui.mPButtonGroupSpace->setFixedSize(ui.mPButtonGroupSpace->size());
	file->setFixedSize(file->size());
	back_top->setFixedHeight(back_top->height()-25);

	mChatHeaderImage->setFixedSize(36, 36); 
}



// ��ʼ���ؼ�����
void GroupWidget::initLayout()
{
	// ���������Ϊ 3 ����  ��(top) ��(mid) ��(bot)
	// �� : �ǳ� ���ܰ�ť���رյȰ�ť�ȵȵĲ���
	// �� : stackedWidget
	QLabel* nick = ui.mLabelGroupNickChat;
	QToolButton* file = ui.mTButtonGroupFile; 
	QLabel* back_top = ui.mGroupLabelBK; 


	// ���沿��
	QVBoxLayout* top_part_layout = new QVBoxLayout;
	{
		// graphһ��
		QHBoxLayout* graph_layout = new QHBoxLayout;
		QWidget* btw_zone_graph_spacer = new QWidget(this);
		btw_zone_graph_spacer->setFixedWidth(6);
		graph_layout->addWidget(ui.mPButtonGroupSpace);
		graph_layout->addWidget(btw_zone_graph_spacer);
		removeLayoutSpacing(graph_layout);

		//���ܰ�ť��һ����
		QHBoxLayout* third_layout = new QHBoxLayout;
		QHBoxLayout* fund_btns_layout = new QHBoxLayout;
		fund_btns_layout->addWidget(file);
		removeLayoutSpacing(fund_btns_layout);

		third_layout->addLayout(fund_btns_layout);
		removeLayoutSpacing(third_layout);
		
		// ��һ�еĲ���  nick + mmc
		QHBoxLayout* first_layout = new QHBoxLayout;

		QHBoxLayout* nick_layout_h = new QHBoxLayout;
		QVBoxLayout* nick_layout = new QVBoxLayout;
		QWidget* nick_upon_spacer = new QWidget(this);
		QWidget* nick_left_spacer = new	QWidget(this); 
		QWidget* img_left_spacer = new QWidget(this);
		QWidget* between_nick_mmc_spacer = new QWidget(this);
		nick_upon_spacer->setFixedHeight(10);
		nick_left_spacer->setFixedWidth(5); 
		img_left_spacer->setFixedSize(12, nick->height());

		nick_layout_h->addWidget(img_left_spacer);
		nick_layout_h->addWidget(mChatHeaderImage);    // ͷ��
		nick_layout_h->addWidget(nick_left_spacer); 
		nick_layout_h->addWidget(nick);
		nick_layout_h->addLayout(graph_layout);
		QSpacerItem *spacer = new QSpacerItem(1, 1, QSizePolicy::Expanding);
		nick_layout_h->addSpacerItem(spacer);
		nick_layout_h->addLayout(third_layout);
		removeLayoutSpacing(nick_layout_h);

		//nick_layout->addWidget(nick_upon_spacer);
		nick_layout->addLayout(nick_layout_h);
		removeLayoutSpacing(nick_layout);

		first_layout->addLayout(nick_layout);
		first_layout->addWidget(between_nick_mmc_spacer);
		removeLayoutSpacing(first_layout);

		top_part_layout->addLayout(first_layout);
		//top_part_layout->addLayout(second_layout); 
		//top_part_layout->addLayout(third_layout);
		removeLayoutSpacing(top_part_layout);

		back_top->setLayout(top_part_layout); 
	}

	// �ܵĲ���
	QVBoxLayout* this_layout = new QVBoxLayout; 
	this_layout->addWidget(back_top); 
	this_layout->addWidget(ui.mGroupStackedWidget); 
	removeLayoutSpacing(this_layout); 

	this->setLayout(this_layout); 
	//setStyleSheet(QString::fromUtf8("border:1px solid gray"));
}

// Access: private
// ���� :  ������ layout�еĿؼ�֮��ļ�϶ȥ��
void GroupWidget::removeLayoutSpacing(QLayout* layout)
{
	layout->setSpacing(0);
	layout->setMargin(0);
}

void GroupWidget::slotGroupBuddyPerChat(QString strBuddyID)
{
	emit sigShowGroupBuddyPerChat(OpenPer, QVariant(strBuddyID));
}

void GroupWidget::OnSendScreenShotPic(QString strShotFileName)
{
	if (mGroupChatWidget != NULL)
	{
		mGroupChatWidget->OnSendScreenShotPic(strShotFileName);
	}
}

void GroupWidget::slotShowNormalWindow()
{
	emit sigShowNormalWindow();           //���ڻ�ԭ
}

void GroupWidget::scrollBottom()
{
	mGroupChatWidget->scrollBottom();
}

void GroupWidget::userQuitGroup(QString userID)
{
	mGroupChatWidget->userQuitGroup(userID);
}

//added by wangqingjie
void GroupWidget::dragEnterEvent(QDragEnterEvent *event)
{
	//ui.mTextEditPer->setReadOnly(true);//һ�����ļ����룬��Ϊֻ��
	//���Ϊ�ļ�����֧���Ϸ�
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}

//���û���������ļ��󣬾ͻᴥ��dropEvent�¼�
void GroupWidget::dropEvent(QDropEvent *event)
{
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty())
		return;

	//��ȡ�ļ���
	foreach(QUrl url, urls)
	{
		QString file_name = url.toLocalFile();
		mGroupChatWidget->slotSendFile(file_name);
	}

	//ui.mTextEditPer->setReadOnly(false);//�������ļ�֮����ȡ��ֻ��
}
//end added