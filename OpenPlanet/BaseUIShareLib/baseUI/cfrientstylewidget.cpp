#include "cfrientstylewidget.h"
#include <QEventLoop>

CFrientStyleWidget::CFrientStyleWidget(QWidget *parent) : QWidget(parent)
{
    mHeadImage = NULL;
    mNickName = NULL;
    mAutoGraph = NULL;
    mMessageTime = NULL;
    mCloseBtn = NULL;
	mAddPerson = NULL;
    mMessageTime = NULL;
    mMessageNum = NULL;
	mAcceptBtn = NULL;
	// wxd add code - start
	mCreateGroupCheckBtn = NULL; 
	mCreateGroupRemoveBtn = NULL; 
	mCGCheckBtnIsChecked = false; 
	// wxd add code - end
	identity = NULL;
}

CFrientStyleWidget::~CFrientStyleWidget()
{
    if(mHeadImage != NULL)
       delete mHeadImage;
    mHeadImage = NULL;
    if(mNickName != NULL)
        delete mNickName;
    mNickName = NULL;
    if(mAutoGraph != NULL)
        delete mAutoGraph;
    mAutoGraph = NULL;
    if(mMessageTime != NULL)
        delete mMessageTime;
    mMessageTime = NULL;
    if(mCloseBtn != NULL)
        delete mCloseBtn;
    mCloseBtn = NULL;
	// wxd add code - start
	if (mCreateGroupCheckBtn != NULL)
		delete mCreateGroupCheckBtn; 
	mCreateGroupCheckBtn = NULL; 
	if (mCreateGroupRemoveBtn != NULL)
		delete mCreateGroupRemoveBtn; 
	mCreateGroupRemoveBtn = NULL; 
	// wxd add code - end
}

//消息好友列表样式
void CFrientStyleWidget::OnInitMessage(QString strUserID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mAutoGraph == NULL)
		mAutoGraph = new QLabel(this);
	if (mMessageTime == NULL)
		mMessageTime = new QLabel(this);
	if (mMessageNum == NULL)
		mMessageNum = new QLabel(this);
	if (mCloseBtn == NULL)
		mCloseBtn = new QPushButton(this);

    mNickName->setAttribute(Qt::WA_TranslucentBackground);
    mHeadImage->installEventFilter(this);

	mNickName->setStyleSheet("font: 75 12pt 微软雅黑;font-size:13px; color: #108ee9;");
    mAutoGraph->setStyleSheet("font: 75 10pt 微软雅黑;font-size:12px;color:#8A8A8A;");

    mHeadImage->setFixedSize(42,42);
    mHeadImage->move(8,8);
	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");

    mNickName->setObjectName(strUserID);
    mNickName->resize(QSize(154,20));
    mNickName->move(64,12);

    mAutoGraph->resize(QSize(200,20));
    mAutoGraph->move(64,35);

	mMessageTime->setFixedSize(50, 20);
    mMessageTime->move(230,12);
	mMessageTime->setStyleSheet("color: rgb(153, 153, 153);font: 12px '微软雅黑'; ");
	mMessageTime->setAlignment(Qt::AlignRight);

    mMessageNum->setFixedSize(20,20);
    mMessageNum->setStyleSheet("background-color:#FF7F24;border-radius:10px;font: 75 10pt 微软雅黑;font-size:10px;font-color::rgb(0, 0, 0);");
    mMessageNum->move(280,34);
    mMessageNum->setAlignment(Qt::AlignCenter); 

	mCloseBtn->setFixedSize(20, 20);
	mCloseBtn->move(310, 34);
	mCloseBtn->setObjectName(strUserID);
	mCloseBtn->setStyleSheet("QPushButton{border-image:url(:/Login/Resources/login/message_close_hove.png)0 0 0 0 stretch stretch;}"
		"QPushButton:hover{border-image:url(:/Login/Resources/login/message_close.png)0 0 0 0 stretch stretch;}");
	//mCloseBtn->setCursor(QCursor(Qt::PointingHandCursor)); 
	mCloseBtn->hide();     // 初始化为隐藏
	mCloseBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	mCloseBtn->setCursor(Qt::PointingHandCursor);
	connect(mCloseBtn, SIGNAL(clicked()), this, SLOT(doCurrentChatClose()));

	// 设置布局
	InitLayout(layout_type::message); 
	mItemListType = item_list_type::chat_list;
	//setStyleSheet(QString::fromUtf8("border:1px solid gray"));
}

//联系人好友列表样式
void CFrientStyleWidget::OnInitContacts(QString strUserID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mAutoGraph == NULL)
		mAutoGraph = new QLabel(this);

	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");

	mNickName->setStyleSheet("background-color:#FFFFFF;font: 75 12pt 微软雅黑;font-size:13px;font-color::rgb(0, 0, 0);");
    mNickName->setAttribute(Qt::WA_TranslucentBackground);
    //mHeadImage->installEventFilter(this);
	mAutoGraph->setStyleSheet("font: 75 10pt 微软雅黑;font-size:12px;color:#8A8A8A;");
	mAutoGraph->resize(QSize(200, 24));
	mAutoGraph->setMinimumHeight(24);
	mAutoGraph->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	mAutoGraph->move(64, 35);

    mHeadImage->setFixedSize(36,36);
    mHeadImage->move(11,11);
    mNickName->resize(QSize(150,25));
    mNickName->move(59,20);
    mNickName->setObjectName(strUserID);

	// 设置布局
	InitLayout(layout_type::contacts); 
	//setStyleSheet(QString::fromUtf8("border:1px solid gray"));
}

//联系人好友列表样式
void CFrientStyleWidget::OnInitGroup(QString strUserID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);

	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");

	mNickName->setStyleSheet("background-color:#FFFFFF;font: 75 12pt 微软雅黑;font-size:13px;font-color::rgb(0, 0, 0);");
	mNickName->setAttribute(Qt::WA_TranslucentBackground);
	//mHeadImage->installEventFilter(this);

	mHeadImage->setFixedSize(36, 36);
	mHeadImage->move(11, 11);
	mNickName->resize(QSize(150, 25));
	mNickName->move(59, 20);
	mNickName->setObjectName(strUserID);

	// 设置布局
	InitLayout(layout_type::group);
	//setStyleSheet(QString::fromUtf8("border:1px solid gray"));
}

void CFrientStyleWidget::OnInitDevice(QString strDeviceName)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);

	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");

	mNickName->setStyleSheet("background-color:#FFFFFF;font: 75 15pt 微软雅黑;font-size:13px;font-color::rgb(0, 0, 0);");
	mNickName->setAttribute(Qt::WA_TranslucentBackground);
	mHeadImage->resize(35, 35);
	mHeadImage->move(15, 6);
	mNickName->resize(QSize(220, 30));
	mNickName->move(59, 10);
	mNickName->setObjectName(strDeviceName);

	// 设置布局
	//InitLayout(layout_type::contacts);
}

QDateTime CFrientStyleWidget::getLastTime()
{
	QDateTime time(QDate(1970, 1, 1));  //预设一个较早的时间，如果读取不出就返回该时间。
	if (mMessageTime)
		time = time.fromString(mMessageTime->objectName(), Qt::TextDate);

	return time;
}

QString CFrientStyleWidget::getLoginUserID()
{
	if (mCloseBtn == NULL)
	{
		qDebug() << QStringLiteral("CFrientStyleWidget::getLoginUserID空指针");
		return "";
	}
	return mCloseBtn->objectName(); 
}

// 返回 CheckBtn状态
bool CFrientStyleWidget::getCGCheckBtnStatus()
{
	return mCGCheckBtnIsChecked; 
}

// 改变 CGContactsListItem上 CheckBtn的状态
void CFrientStyleWidget::changeCGCheckBtnStatus()
{
	mCGCheckBtnIsChecked = !mCGCheckBtnIsChecked; 
	if (mCGCheckBtnIsChecked)		// 选中状态下
		mCreateGroupCheckBtn->setStyleSheet("QLabel{border-image:url(:/addPerson/Resources/add/selected.png)0 0 0 0 stretch stretch;}");
	else							// 非选中状态下
		mCreateGroupCheckBtn->setStyleSheet("QLabel{border-image:url(:/addPerson/Resources/add/normal.png)0 0 0 0 stretch stretch;}");	
}

// 初始化 新建群聊 窗口时的好友列表 给item加上圆形的对号复选框
void CFrientStyleWidget::OnInitCreateGroupContactsList(QString strBuddyID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mCreateGroupCheckBtn == NULL)
		mCreateGroupCheckBtn = new QLabel(this);
	mNickName->setAttribute(Qt::WA_TranslucentBackground);
	mNickName->setStyleSheet("font: 75 16pt 微软雅黑;font-size:16px;font-color::rgb(0, 0, 0);");
	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(55, 55);
	mHeadImage->move(5, 5);
	mNickName->resize(QSize(150, 25));
	mNickName->move(70, 22);
	mCreateGroupCheckBtn->setFixedSize(24, 24);
	mCreateGroupCheckBtn->move(220, 25);
	this->setObjectName(strBuddyID); 
	//mCreateGroupCheckBtn->setObjectName(strBuddyID);
	mCreateGroupCheckBtn->setStyleSheet("QLabel{border-image:url(:/addPerson/Resources/add/normal.png)0 0 0 0 stretch stretch;}"); 
										//"QPushButton:press{border-image:url(:/addPerson/Resources/add/selected.png)0 0 0 0 stretch stretch;}");
	mCreateGroupCheckBtn->setCursor(QCursor(Qt::PointingHandCursor));
	//connect(this, SIGNAL(clicked()), this, SLOT(OnCGContactsListItemClicked()));
}

// 初始化 新建群聊 窗口时的群组成员列表 给item加上圆形的叉号复选框
void CFrientStyleWidget::OnInitCreateGroupMemberList(QString strBuddyID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	mCreateGroupRemoveBtn = new QPushButton(this); 

	mNickName->setAttribute(Qt::WA_TranslucentBackground);
	mNickName->setStyleSheet("font: 75 16pt 微软雅黑;font-size:16px;font-color::rgb(0, 0, 0);");
	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(55, 55);
	mHeadImage->move(5, 5);
	mNickName->resize(QSize(150, 25));
	mNickName->move(70, 22);
	mCreateGroupRemoveBtn->setFixedSize(20, 20);
	mCreateGroupRemoveBtn->move(220, 25);
	this->setObjectName(strBuddyID);
	mCreateGroupRemoveBtn->setStyleSheet("QPushButton{border-image:url(:/Login/Resources/login/message_close_hove.png)0 0 0 0 stretch stretch;}"
										 "QPushButton:hover{border-image:url(:/Login/Resources/login/message_close.png)0 0 0 0 stretch stretch;}");
	mCreateGroupRemoveBtn->setCursor(QCursor(Qt::PointingHandCursor));
	connect(mCreateGroupRemoveBtn, SIGNAL(clicked()), this, SLOT(OnCGRemoveBtnClicked()));
}



void CFrientStyleWidget::OnInitChat(QString strUserID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mMessageNum == NULL)
		mMessageNum = new QLabel(this);
	if (mCloseBtn == NULL)
		mCloseBtn = new QPushButton(this);
	
	mNickName->setMinimumSize(0,50);
	mNickName->setMaximumSize(500,50);
	mNickName->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	mNickName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    //mNickName->setAttribute(Qt::WA_TranslucentBackground);
	mNickName->setStyleSheet("font: 75 16pt 微软雅黑;font-size:14px;font-color::rgb(0, 0, 0);");
	mNickName->move(6, 0);

	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(42,42);
    mHeadImage->move(6,8);
	mHeadImage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

	mMessageNum->setFixedSize(20, 20);
	mMessageNum->setStyleSheet("background-color:#FF7F24;border-radius:10px;font: 75 10pt 微软雅黑;font-size:10px;font-color::rgb(0, 0, 0);");
	mMessageNum->move(145, 25);
	mMessageNum->setAlignment(Qt::AlignCenter);
	mMessageNum->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    mCloseBtn->setFixedSize(20,20);
    mCloseBtn->move(145,25);
	mCloseBtn->setObjectName(strUserID);
    mCloseBtn->setStyleSheet("QPushButton{border-image:url(:/Login/Resources/login/message_close_hove.png)0 0 0 0 stretch stretch;}"
                             "QPushButton:hover{border-image:url(:/Login/Resources/login/message_close.png)0 0 0 0 stretch stretch;}");
	//mCloseBtn->setCursor(QCursor(Qt::PointingHandCursor)); 
	mCloseBtn->hide();     // 初始化为隐藏
	mCloseBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	connect(mCloseBtn,SIGNAL(clicked()),this,SLOT(doCurrentChatClose())); 

	InitLayout(layout_type::chat); 
	mItemListType = item_list_type::chat_list;                      // 说明 本 widget所在Item的list的类型
	//setStyleSheet(QString::fromUtf8("border:1px solid gray"));    // 看布局时使用 
}

void CFrientStyleWidget::OnInitAddCreateList(QString strTitle)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mAutoGraph == NULL)
		mAutoGraph = new QLabel(this);

	mNickName->setAttribute(Qt::WA_TranslucentBackground);
	mNickName->setStyleSheet("font: 75 14pt 微软雅黑;font-size:16px;font-color::rgb(0, 0, 0);");
	mAutoGraph->setStyleSheet("font: 75 12pt 微软雅黑;font-size:16px;color:#8A8A8A;");
	
	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);"); 
	mHeadImage->setFixedSize(55, 55);
	mHeadImage->move(2, 2);

	mNickName->setObjectName(strTitle);
	mNickName->resize(QSize(245, 25));
	mNickName->move(70, 5);

	mAutoGraph->resize(QSize(245, 25));
	mAutoGraph->move(70, 30);
}

void CFrientStyleWidget::OnSetAddPersonButtonText(QString strText)
{
	if (mAddPerson)
	{
		mAddPerson->setText(strText);
	}
}

void CFrientStyleWidget::OnInitSearchBuddyList(QString strBuddyID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mAddPerson == NULL)
		mAddPerson = new QPushButton(this);

	mNickName->setAttribute(Qt::WA_TranslucentBackground);
	mNickName->setStyleSheet("font: 75 16pt 微软雅黑;font-size:16px;font-color::rgb(0, 0, 0);");
	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(55, 55);
	mHeadImage->move(2, 2);

	mNickName->setObjectName(strBuddyID);
	mNickName->resize(QSize(245, 30));
	mNickName->move(70, 5);

//	mAddPerson->setText("加为好友");
	mAddPerson->setStyleSheet("QPushButton{border: 0px;background-color:#48D1CC;}"
		"QPushButton:hover{border: 0px;background-color:#4876FF;}");
	mAddPerson->resize(QSize(70, 20));
	mAddPerson->move(70, 40);
	mAddPerson->setCursor(QCursor(Qt::PointingHandCursor));
	mAddPerson->setObjectName(strBuddyID);
	connect(mAddPerson,SIGNAL(clicked()),this,SLOT(doAddPerson()));
}

void CFrientStyleWidget::doAddPerson()
{
	if (mAddPerson == NULL)
	{
		qDebug() << QStringLiteral("CFrientStyleWidget::doAddPerson空指针");
		return;
	}
	emit sigAddPerson(mAddPerson->objectName());
}

void CFrientStyleWidget::OnInitMessageBoxList(QString strBuddyID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mAutoGraph == NULL)
		mAutoGraph = new QLabel(this);
	if (mMessageTime == NULL)
		mMessageTime = new QLabel(this);
	if (mMessageNum == NULL)
		mMessageNum = new QLabel(this);
	mNickName->setAttribute(Qt::WA_TranslucentBackground);
	//mHeadImage->installEventFilter(this);

	mNickName->setStyleSheet("font: 75 14pt 微软雅黑;font-size:16px;font-color::rgb(0, 0, 0);");
	mAutoGraph->setStyleSheet("font: 75 12pt 微软雅黑;font-size:16px;color:#8A8A8A;");
	
	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(42, 42);
	mHeadImage->move(2, 8);

	mNickName->setObjectName(strBuddyID);
	mNickName->resize(QSize(100, 25));
	mNickName->move(50, 5);

	mAutoGraph->resize(QSize(150, 25));
	mAutoGraph->move(50, 30);

	mMessageTime->resize(QSize(30, 20));
	mMessageTime->move(220, 8);

	mMessageNum->resize(20, 20);
	mMessageNum->setStyleSheet("background-color:#FF7F24;border-radius:10px;font: 75 14pt 微软雅黑;font-size:10px;font-color::rgb(0, 0, 0);");
	mMessageNum->move(230, 28);
	mMessageNum->setAlignment(Qt::AlignCenter);

}

void CFrientStyleWidget::doCurrentChatClose()
{
	if (mCloseBtn == NULL)
	{
		qDebug() << QStringLiteral("CFrientStyleWidget::doCurrentChatClose空指针");
		return;
	}
	emit sigCurrentChatClose(mCloseBtn->objectName());
}

// 发送信号到 CreateGroupWidget::doRmBuddyFromGroupMemberList 
void CFrientStyleWidget::OnCGRemoveBtnClicked()
{
	if (mCGCheckBtnIsChecked)
		mCGCheckBtnIsChecked = false; 
	//mCreateGroupCheckBtn->setStyleSheet("QPushButton{border-image:url(:/Login/Resources/login/create_group_item_unchecked.png)0 0 0 0 stretch stretch;}"); 
	emit sigRemoveBuddyFromCGMemberList(this->objectName());
}

void CFrientStyleWidget::OnInitLoginEdit(QString strIndex)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mCloseBtn == NULL)
		mCloseBtn = new QPushButton(this);
    mNickName->setAttribute(Qt::WA_TranslucentBackground);
    mNickName->setStyleSheet("font: 75 16pt 微软雅黑;font-size:16px;font-color::rgb(0, 0, 0);");
	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(30,30);
    mHeadImage->move(5,5);
    mNickName->resize(QSize(140,20));
    mNickName->move(50,10);
    mCloseBtn->setFixedSize(20,20);
    mCloseBtn->move(145,10);
    mCloseBtn->setStyleSheet("QPushButton{border-image:url(:/Login/Resources/login/message_close_hove.png)0 0 0 0 stretch stretch;}"
                             "QPushButton:hover{border-image:url(:/Login/Resources/login/message_close.png)0 0 0 0 stretch stretch;}");

    mCloseBtn->setObjectName(strIndex);
    connect(mCloseBtn,SIGNAL(clicked()),this,SLOT(doLoginEditClose()));
}

void CFrientStyleWidget::doLoginEditClose()
{
	if (mCloseBtn == NULL)
	{
		qDebug() << QStringLiteral("CFrientStyleWidget::doLoginEditClose空指针");
		return;
	}
	emit sigLoginEditClose(mCloseBtn->objectName());
}

//设置头像大小
void CFrientStyleWidget::OnSetHeadImageSize(int nWidth,int nHeight)
{
    if(mHeadImage == NULL ) return ;
    mHeadImage->setFixedSize(nWidth,nHeight);
}

//设置昵称名称
void CFrientStyleWidget::OnSetNickNameText(QString strText,QString styleSheet)
{
    if(mNickName == NULL ) return;
	if (!strText.isEmpty())
	{
		mStrNickName = strText;     // 保存原样字符串
		// 设置简略字符串(超长显示...)
		QString elide_text = getElideString(strText, (QWidget*)mNickName, mNickName->font()); 
		mNickName->setText(elide_text); 
		this->setToolTip(mStrNickName);
	}
    if(!styleSheet.isEmpty()) mNickName->setStyleSheet(styleSheet);
}

//设置签名/聊天信息内容
void CFrientStyleWidget::OnSetAutoGrapthText(QString strText,QString styleSheet)
{
    if(mAutoGraph == NULL ) return;
    if(!strText.isEmpty())
    {
        if(strText.length()>13)
        {
            QString strTemp = strText.mid(0,13);
            int n = strTemp.indexOf("\n");
            if(n < 0)
                mAutoGraph->setText(strTemp+"...");
            else
                mAutoGraph->setText("");
        }
        else
        {
            mAutoGraph->setText(strText);
        }
    }
    if(!styleSheet.isEmpty()) mAutoGraph->setStyleSheet(styleSheet);

}

//设置消息发送时间内容
void CFrientStyleWidget::OnSetMessageTime(QString strText,QString styleSheet)
{
    if(mMessageTime == NULL ) return;
    if(!strText.isEmpty())    mMessageTime->setText(strText);
    if(!styleSheet.isEmpty()) mMessageTime->setStyleSheet(styleSheet);
	//将创建时间写入消息项
	QString time = QDateTime::currentDateTime().toString();
	mMessageTime->setObjectName(time);
}
//added by wangqingjie
QString CFrientStyleWidget::OnGetMessageNum()
{
	if (mMessageNum)
	{
		return mMessageNum->text();
	}
	return "";
}
void CFrientStyleWidget::OnSetMessageNum(QString strNum)
{
    if(mMessageNum)
    {
		mMessageNum->setText(strNum);
		if (mMessageNum->text().isEmpty())
			mMessageNum->hide();
        else
		   mMessageNum->show();
    }

	emit sigNumChanged();
}

QString CFrientStyleWidget::OnGetHeaderImagePath()
{
	if (mHeadImage == NULL)
	{
		qDebug() << QStringLiteral("CFrientStyleWidget::OnGetHeaderImagePath空指针");
		return "";
	}
    return mHeadImage->objectName();
}

//设置头像路径
void CFrientStyleWidget::OnSetPicPath(QString strPath,int nType)
{
    if(mHeadImage)
    {
		QByteArray bytearray;
		QFile file(strPath);
		if (file.open(QIODevice::ReadOnly) && file.size() != 0)
		{
			bytearray = file.readAll();
		}
		file.close();
		QPixmap pix;
		if (!pix.loadFromData(bytearray) || bytearray == "")
		{
			if (nType == 0)
			{
				pix.load(":/PerChat/Resources/person/temp.png");
			}
			else
			{
				pix.load(":/GroupChat/Resources/groupchat/group.png");
			}
		}
        mHeadImage->setAutoFillBackground(true);
//		circleHeaderImage(pix);
		mHeadImage->setPixmap(pix);
        mHeadImage->setScaledContents(true);
        mHeadImage->setObjectName(strPath);
    }
}

void CFrientStyleWidget::OnSetPicPathByHttp(QString strPath, QString strDefaultImage)
{
	if (mHeadImage)
	{
		QNetworkAccessManager manager;
		QEventLoop loop;
		QNetworkReply *reply = manager.get(QNetworkRequest(strPath));
		QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
		//开启子事件循环
		loop.exec();
		QByteArray jpegData = reply->readAll();
		if (!jpegData.isEmpty())
		{
			QPixmap pixmap;
			pixmap.loadFromData(jpegData);
			mHeadImage->setAutoFillBackground(true);
			mHeadImage->setPixmap(pixmap);
			mHeadImage->setScaledContents(true);
		}
		else
		{
			mHeadImage->setAutoFillBackground(true);
			mHeadImage->setPixmap(QPixmap(strDefaultImage));
			mHeadImage->setScaledContents(true);
		}
	}
}

void CFrientStyleWidget::onSetIdentity(int mana)
{
	if (identity)
	{
		QPixmap map;
		if (mana == 9)
			map.load(":/GroupChat/Resources/groupchat/chairman.png");
		if (mana == 1)
			map.load(":/GroupChat/Resources/groupchat/manager.png");

		if (!map.isNull())
		{
			identity->setPixmap(map);
			mNickName->resize(QSize(90, 20));
		}
		else
		{
			identity->clear();
		}
	}
}

void CFrientStyleWidget::OnInitGroupUserList(QString strGroupUserID)
{
	if (identity == NULL)
		identity = new QLabel(this);
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	
    mNickName->setStyleSheet("background-color:#FFFFFF;font: 75 8pt 微软雅黑;font-size:14px;font-color::rgb(0, 0, 0);");
    mNickName->setAttribute(Qt::WA_TranslucentBackground);

	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    mHeadImage->setFixedSize(20,20);
    mHeadImage->move(5,5);
    mNickName->resize(QSize(150,20));
    mNickName->move(28,3);
    mNickName->setObjectName(strGroupUserID);

	identity->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	identity->setFixedSize(20, 20);
	identity->move(120, 4);
}

void CFrientStyleWidget::OnInitLogUserList(QString strGroupUserID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	mNickName->setStyleSheet("background-color:#FFFFFF;font: 75 8pt 微软雅黑;font-size:12px; color: #108ee9;");
	mNickName->setAttribute(Qt::WA_TranslucentBackground);

	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(20, 20);
	mHeadImage->move(5, 5);
	mNickName->resize(QSize(150, 20));
	mNickName->move(28, 2);
	mNickName->setObjectName(strGroupUserID);
}

void CFrientStyleWidget::onInitManagerUserList(QString strUserID, bool hasRead)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mAcceptBtn == NULL)
		mAcceptBtn = new QPushButton(this);

	mNickName->setMinimumSize(0, 50);
	mNickName->setMaximumSize(500, 50);
	mNickName->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	mNickName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	mNickName->setStyleSheet("font: 75 16pt 微软雅黑 ;font-weight:bold;font-size:16px;font-color::rgb(0, 0, 0);");
	mNickName->move(86, 8);
	mNickName->setObjectName(strUserID);

	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(54, 54);
	mHeadImage->move(18, 8);
	mHeadImage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	mAcceptBtn->setFixedSize(75, 28);
	mAcceptBtn->move(460, 21);
	mAcceptBtn->setObjectName("false");
	mAcceptBtn->setText("加为好友");
	mAcceptBtn->setFont(QFont("microsoft yahei", 10));
	mAcceptBtn->setCursor(QCursor(Qt::PointingHandCursor));
	mAcceptBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	connect(mAcceptBtn, SIGNAL(clicked()), this, SLOT(doClickAcceptBtn()));

	InitLayout(layout_type::manager);

	if (hasRead)
	{
		mAcceptBtn->setStyleSheet("border:none;color:grey;");
		mAcceptBtn->setText("已添加");
		mAcceptBtn->setCursor(QCursor(Qt::ArrowCursor));
		mAcceptBtn->setEnabled(false);
	}
}

void CFrientStyleWidget::onInitManagerApplyGroup(QString strUserID, QString group, bool hasRead)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mAcceptBtn == NULL)
		mAcceptBtn = new QPushButton(this);

	mNickName->setMinimumSize(400, 50);
	mNickName->setMaximumSize(500, 50);
	mNickName->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	mNickName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	mNickName->setStyleSheet("font: 75 16pt 微软雅黑;font-size:15px;font-color::rgb(0, 0, 0);");
	mNickName->move(86, 8);
	mNickName->setObjectName(strUserID);

	//设置头像的的底色为透明。
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(54, 54);
	mHeadImage->move(18, 8);
	mHeadImage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	mAcceptBtn->setFixedSize(75, 28);
	mAcceptBtn->move(460, 21);
	mAcceptBtn->setObjectName(group);
	mAcceptBtn->setText("同意");
	mAcceptBtn->setFont(QFont("microsoft yahei", 10));
	mAcceptBtn->setCursor(QCursor(Qt::PointingHandCursor));
	mAcceptBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	connect(mAcceptBtn, SIGNAL(clicked()), this, SLOT(doClickAcceptBtn()));

	InitLayout(layout_type::manager);

	if (hasRead)
	{
		mAcceptBtn->setStyleSheet("border:none;color:grey;");
		mAcceptBtn->setText("已同意");
		mAcceptBtn->setCursor(QCursor(Qt::ArrowCursor));
		mAcceptBtn->setEnabled(false);
	}
}

QString CFrientStyleWidget::GetNikeName()
{
	if (mNickName)
	{
		return mNickName->text();
	}
	return "";
}

//added by wangqingjie
QString CFrientStyleWidget::GetAutoGraph()
{
	if (mAutoGraph)
	{
		return mAutoGraph->text();
	}
	return "";
}

QString CFrientStyleWidget::GetStrTime()
{
	if (mMessageTime)
	{
		return mMessageTime->text();
	}
	return "";
}

//end added
// 初始化布局
void CFrientStyleWidget::InitLayout(int layoutType)
{
	switch (layoutType)
	{
	case layout_type::chat:
		initChatItemLayout(); 
		break; 
	case layout_type::group:
		initGroupItemLayout();
		break;
	case layout_type::message:
		initMessageItemLayout(); 
		break; 
	case layout_type::contacts: 
		initContactsItemLayout(); 
		break; 
	case layout_type::group_member:
		initGroupMemberItemLayout(); 
		break; 
	case layout_type::manager:
		initManagerItemLayout();
	default:
		break;
	}
}

// 聊天窗口右边的item 的布局风格
void CFrientStyleWidget::initChatItemLayout()
{
	// img 的布局
	QVBoxLayout* img_layout = new QVBoxLayout;
	{
		QHBoxLayout* img_layout_h = new QHBoxLayout;
		QWidget* img_left_spacer = new QWidget(this);
		QWidget* img_right_spacer = new QWidget(this);
		img_left_spacer->setFixedSize(6, mHeadImage->height());
		img_right_spacer->setFixedSize(6, mHeadImage->height());

		img_layout_h->addWidget(img_left_spacer);
		img_layout_h->addWidget(mHeadImage);
		img_layout_h->addWidget(img_right_spacer);
		removeLayoutSpacing(img_layout_h);

		QWidget* img_upon_spacer = new QWidget(this);
		QWidget* img_down_spacer = new QWidget(this);
		//img_upon_spacer->setFixedSize(mHeadImage->x() + mHeadImage->width() + 8, mHeadImage->height()); 
		img_upon_spacer->setFixedHeight(8);

		img_layout->addWidget(img_upon_spacer);
		img_layout->addLayout(img_layout_h);
		img_layout->addWidget(img_down_spacer);
		removeLayoutSpacing(img_layout);
	}

	// name 的布局
	QVBoxLayout* name_layout = new QVBoxLayout;
	{
		QWidget* name_upon_spacer = new QWidget(this);
		QWidget* name_down_spacer = new QWidget(this);
		name_layout->addWidget(name_upon_spacer);
		name_layout->addWidget(mNickName);
		name_layout->addWidget(name_down_spacer);
		removeLayoutSpacing(name_layout);
	}

	// close btn 的布局
	QVBoxLayout* btn_close_layout = new QVBoxLayout;
	{
		QHBoxLayout* btn_close_layout_h = new QHBoxLayout;
		QWidget* btn_left_spacer = new QWidget(this);
		QWidget* btn_right_spacer = new QWidget(this);
		btn_close_layout_h->addWidget(btn_left_spacer);
		btn_close_layout_h->addWidget(mMessageNum);
		btn_close_layout_h->addWidget(mCloseBtn);
		btn_close_layout_h->addWidget(btn_right_spacer);
		removeLayoutSpacing(btn_close_layout_h);

		QWidget* btn_upon_spacer = new QWidget(this);
		QWidget* btn_down_spacer = new QWidget(this);
		btn_close_layout->addWidget(btn_upon_spacer);
		btn_close_layout->addLayout(btn_close_layout_h);
		btn_close_layout->addWidget(btn_down_spacer);
		removeLayoutSpacing(btn_close_layout);
	}

	QHBoxLayout* this_layout = new QHBoxLayout;
	this_layout->addLayout(img_layout);
	this_layout->addLayout(name_layout);
	this_layout->addLayout(btn_close_layout);
	QSpacerItem *spacer = new QSpacerItem(6, 6);
	this_layout->addSpacerItem(spacer);
	removeLayoutSpacing(this_layout);

	this->setLayout(this_layout);
}

// 聊天窗口右边的item 的布局风格
void CFrientStyleWidget::initGroupItemLayout()
{
	if (!mHeadImage || !mNickName)
		return;

	QLabel* img = mHeadImage;
	QLabel* name = mNickName;

	// 中间一行的布局
	QHBoxLayout* mid_line_layout = new QHBoxLayout;
	QWidget* img_left_spacer = new QWidget(this);
	QWidget* img_right_spacer = new QWidget(this);

	img_left_spacer->setFixedSize(img->x(), img->height());
	img_right_spacer->setFixedSize(name->x() - img->x() - img->width(), img->height());

	// name 的竖直布局 (中间一行的布局的右半部份)
	QVBoxLayout* name_layout = new QVBoxLayout;
	{
		QWidget* name_upon_spacer = new QWidget(this);
		QWidget* name_down_spacer = new QWidget(this);
		name_upon_spacer->resize(name->width(), name->y() - img->y());
		name_upon_spacer->setFixedHeight(name->y() - img->y());
		name_layout->addWidget(name_upon_spacer);
		name_layout->addWidget(name);
		name_layout->addWidget(name_down_spacer);
		removeLayoutSpacing(name_layout);
	}

	mid_line_layout->addWidget(img_left_spacer);
	mid_line_layout->addWidget(img);
	mid_line_layout->addWidget(img_right_spacer);
	mid_line_layout->addLayout(name_layout);
	removeLayoutSpacing(mid_line_layout);

	// 第一行的空白部分(最上面一行)
	QWidget* top_line_spacer = new QWidget(this);
	top_line_spacer->setFixedHeight(img->y());

	// 第二行空白部分(最下面一行)
	QWidget* bot_line_spacer = new QWidget(this);
	bot_line_spacer->setFixedHeight(this->height() - img->y() - img->height());

	// 总的布局
	QVBoxLayout* this_layout = new QVBoxLayout;
	this_layout->addWidget(top_line_spacer);
	this_layout->addLayout(mid_line_layout);
	this_layout->addWidget(bot_line_spacer);
	removeLayoutSpacing(this_layout);

	this->setLayout(this_layout);
}

void CFrientStyleWidget::initManagerItemLayout()
{

}

// 消息一栏的item 的布局风格
void CFrientStyleWidget::initMessageItemLayout()
{
	QLabel* img = mHeadImage;
	QLabel* name = mNickName;
	QLabel* autog = mAutoGraph; 
	QLabel* time = mMessageTime; 
	QLabel* num = mMessageNum; 
	const int down_spacer_height = this->height() - img->y() - img->height(); 

	// img 部分的布局  总体 左边部分
	QVBoxLayout* img_layout = new QVBoxLayout;
	{
		QHBoxLayout* img_layout_h = new QHBoxLayout; 
		QWidget* img_left_spacer = new QWidget(this);
		QWidget* img_right_spacer = new QWidget(this);

		img_left_spacer->setFixedSize(img->x(), img->height());
		img_right_spacer->setFixedSize(name->x() - img->x() - img->width(), img->height());

		img_layout_h->addWidget(img_left_spacer); 
		img_layout_h->addWidget(img); 
		img_layout_h->addWidget(img_right_spacer); 
		removeLayoutSpacing(img_layout_h); 

		QWidget* img_upon_spacer = new QWidget(this); 
		QWidget* img_down_spacer = new QWidget(this); 

		img_upon_spacer->setFixedSize(name->x(),img->y()); 
		img_down_spacer->setFixedSize(name->x(), down_spacer_height); 
		
		img_layout->addWidget(img_upon_spacer); 
		img_layout->addLayout(img_layout_h); 
		img_layout->addWidget(img_down_spacer); 
		removeLayoutSpacing(img_layout); 
	}

	// name部分 总体 中间部分
	QVBoxLayout* name_layout = new QVBoxLayout;
	{
		QWidget* name_upon_spacer = new QWidget(this); 
		QWidget* name_down_spacer = new QWidget(this); 

		name_upon_spacer->setFixedHeight(img->y()); 
		name_down_spacer->setFixedHeight(down_spacer_height); 

		name_layout->addWidget(name_upon_spacer); 
		name_layout->addWidget(name); 
		name_layout->addWidget(autog); 
		name_layout->addWidget(name_down_spacer); 
		removeLayoutSpacing(name_layout); 
	}

	// time部分  总体 右边部分
	QVBoxLayout* time_layout = new QVBoxLayout;
	{
		QVBoxLayout* time_layout_v = new QVBoxLayout; 
		QWidget* btw_time_num_spacer = new QWidget(this);     // btw = between
		btw_time_num_spacer->resize(time->width(), 12);
		{
			QHBoxLayout* num_layout = new QHBoxLayout;
			QWidget* num_left_spacer = new QWidget(this);
			num_left_spacer->setFixedWidth(30);
			QWidget* num_right_spacer = new QWidget(this);

			num_layout->addWidget(num_left_spacer);
			num_layout->addWidget(num);
			num_layout->addWidget(mCloseBtn);
			num_layout->addWidget(num_right_spacer);
			removeLayoutSpacing(num_layout);
			
			time_layout_v->addWidget(time); 
			time_layout_v->addWidget(btw_time_num_spacer); 
			time_layout_v->addLayout(num_layout); 
			removeLayoutSpacing(time_layout); 
		}

		QHBoxLayout* time_layout_h = new QHBoxLayout; 
		QWidget* time_left_spacer = new QWidget(this); 
		QWidget* time_right_spacer = new QWidget(this); 

		time_left_spacer->setFixedWidth(12); 
		time_right_spacer->setFixedWidth(12); 

		time_layout_h->addWidget(time_left_spacer); 
		time_layout_h->addLayout(time_layout_v); 
		time_layout_h->addWidget(time_right_spacer); 
		removeLayoutSpacing(time_layout_h); 

		QWidget* time_upon_spacer = new QWidget(this); 
		QWidget* time_down_spacer = new	QWidget(this); 

		time_upon_spacer->setFixedSize(time->width() + 12 * 2 , img->y());
		time_down_spacer->setFixedSize(time_upon_spacer->width(), down_spacer_height); 

		time_layout->addWidget(time_upon_spacer); 
		time_layout->addLayout(time_layout_h); 
		time_layout->addWidget(time_down_spacer); 
		removeLayoutSpacing(time_layout); 
	}

	// 总的布局
	QHBoxLayout* this_layout = new QHBoxLayout; 
	this_layout->addLayout(img_layout); 
	this_layout->addLayout(name_layout); 
	this_layout->addLayout(time_layout); 
	removeLayoutSpacing(this_layout); 
	
	this->setLayout(this_layout); 
	//setStyleSheet("background-color:#FFFFFF"); 
	//setStyleSheet(QString::fromUtf8("border:1px solid gray"));
}

// 联系人, 群组的item 的布局风格
void CFrientStyleWidget::initContactsItemLayout()
{
	if (!mHeadImage || !mNickName)
		return; 

	QLabel* img = mHeadImage; 
	QLabel* name = mNickName; 

	// 中间一行的布局
	QHBoxLayout* mid_line_layout = new QHBoxLayout; 
	QWidget* img_left_spacer = new QWidget(this); 
	QWidget* img_right_spacer = new QWidget(this); 

	img_left_spacer->setFixedSize(img->x(), img->height()); 
	img_right_spacer->setFixedSize(name->x() - img->x() - img->width(), img->height());

	// name 的竖直布局 (中间一行的布局的右半部份)
	QVBoxLayout* name_layout = new QVBoxLayout; 
	{
		QWidget* name_down_spacer = new QWidget(this);
		
		name_layout->addWidget(name);
		name_layout->addWidget(mAutoGraph);
		removeLayoutSpacing(name_layout);
	}

	mid_line_layout->addWidget(img_left_spacer); 
	mid_line_layout->addWidget(img); 
	mid_line_layout->addWidget(img_right_spacer); 
	mid_line_layout->addLayout(name_layout); 
	removeLayoutSpacing(mid_line_layout); 

	// 第一行的空白部分(最上面一行)
	QWidget* top_line_spacer = new QWidget(this); 
	top_line_spacer->setFixedHeight(img->y()); 

	// 第二行空白部分(最下面一行)
	QWidget* bot_line_spacer = new QWidget(this); 
	bot_line_spacer->setFixedHeight(this->height() - img->y() - img->height()); 

	// 总的布局
	QVBoxLayout* this_layout = new QVBoxLayout; 
	this_layout->addWidget(top_line_spacer); 
	this_layout->addLayout(mid_line_layout); 
	this_layout->addWidget(bot_line_spacer); 
	removeLayoutSpacing(this_layout); 

	this->setLayout(this_layout); 
}

// 群组成员的item 的布局风格
void CFrientStyleWidget::initGroupMemberItemLayout() 
{
	
}

void CFrientStyleWidget::removeLayoutSpacing(QLayout* layout)
{
	layout->setSpacing(0); 
	layout->setMargin(0); 
}


// 获取适应控件长度的字符串, 超长显示...
QString CFrientStyleWidget::getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font)
{	
	QFontMetrics fm(str_font);
	int str_width = fm.width(src_str);

	int widget_width = child_widget->width();
	QString elide_str = child_widget->fontMetrics().elidedText(src_str, Qt::ElideRight, widget_width);
	int str_width2 = fm.width(elide_str);

	return elide_str;	
}

// 尺寸发生改变时  使nickname根据label长度变化
void CFrientStyleWidget::resizeEvent(QResizeEvent * event)
{
	QString strElideName = getElideString(mStrNickName, (QWidget*)mNickName, mNickName->font());
	mNickName->setText(strElideName); 
	QWidget::resizeEvent(event);
}


// 返回关闭按钮
QPushButton* CFrientStyleWidget::closeButton()
{
	return mCloseBtn; 
}


void CFrientStyleWidget::enterEvent(QEvent* event)
{
	if (item_list_type::chat_list == mItemListType)
	{
		if (mCloseBtn == NULL)
		{
			qDebug() << QStringLiteral("CFrientStyleWidget::enterEvent mCloseBtn空指针");
			return;
		}
		if (mMessageNum == NULL)
		{
			qDebug() << QStringLiteral("CFrientStyleWidget::enterEvent mMessageNum空指针");
			return;
		}
		mCloseBtn->show();
		mMessageNum->hide();
	}
}

void CFrientStyleWidget::leaveEvent(QEvent * event)
{
	if (item_list_type::chat_list == mItemListType)
	{
		if (mCloseBtn == NULL)
		{
			qDebug() << QStringLiteral("CFrientStyleWidget::leaveEvent mCloseBtn空指针");
			return;
		}
		if (mMessageNum == NULL)
		{
			qDebug() << QStringLiteral("CFrientStyleWidget::leaveEvent mMessageNum空指针");
			return;
		}
		mCloseBtn->hide();
		if (!OnGetMessageNum().isEmpty())
		    mMessageNum->show();
	}
}

void CFrientStyleWidget::doClickAcceptBtn()
{
	mAcceptBtn->setStyleSheet("border:none;color:grey;");
	if (mAcceptBtn->text() == "加为好友")
	    mAcceptBtn->setText("已添加");
	if (mAcceptBtn->text() == "同意")
		mAcceptBtn->setText("已同意");
	mAcceptBtn->setCursor(QCursor(Qt::ArrowCursor));
	mAcceptBtn->setEnabled(false);

	emit sigClickAcceptBtn();
}

void CFrientStyleWidget::onSetHeaderImage(QPixmap pixmap)
{
	mHeadImage->setPixmap(pixmap);
}

/*
void circleHeaderImage(QPixmap &headerImage)
{
	QImage mask(":/Login/Resources/login/circle.png");
	QImage image = headerImage.toImage();
	image = image.convertToFormat(QImage::Format_ARGB32);
	mask = mask.scaled(headerImage.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	
	QPainter *painter = new QPainter();
	painter->begin(&image);
	painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
	painter->drawImage(0, 0, mask);
	painter->end();

	headerImage = headerImage.fromImage(image);
}
*/
/*
void circleHeaderImage(QPixmap &headerImage)
{
	QImage mask(":/Login/Resources/login/circle.png");
	QImage image = headerImage.toImage();
	image = image.convertToFormat(QImage::Format_ARGB32);
	mask = mask.scaled(headerImage.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	mask = mask.convertToFormat(QImage::Format_ARGB32);
	QPainter *painter = new QPainter();
	painter->begin(&image);
	painter->setCompositionMode(QPainter::CompositionMode_DestinationOut);
	painter->drawImage(0, 0, mask);
	painter->end();
	headerImage = headerImage.fromImage(image);
}
*/
