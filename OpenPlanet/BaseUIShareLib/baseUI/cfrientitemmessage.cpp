#include "cfrientitemmessage.h"

CFrientItemMessage::CFrientItemMessage(QWidget *parent)
	: QWidget(parent)
{
	mHeadImage = NULL;
	mNickName = NULL;
	mAutoGraph = NULL;
	mMessageTime = NULL;
	mMessageNum = NULL;
	mCloseBtn = NULL;
}

CFrientItemMessage::~CFrientItemMessage()
{

}

void CFrientItemMessage::OnInitMessage(QString strUserID)
{
	QFont font;
	font.setFamily("Microsoft YaHei");

	if (mHeadImage == NULL)
	{
		mHeadImage = new QLabelHeader(this); 
		mHeadImage->installEventFilter(this);
		//设置头像的的底色为透明。
		mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
		mHeadImage->setFixedSize(42, 42);
		mHeadImage->move(8, 8);
	}
		
	if (mNickName == NULL)
	{
		mNickName = new QLabel(this);
		mNickName->setAttribute(Qt::WA_TranslucentBackground);
		mNickName->setStyleSheet("color:#108ee9;");
		mNickName->resize(QSize(154, 20));
		mNickName->move(64, 12);

		font.setPointSize(12);
		mNickName->setFont(font);
	}
		
	if (mAutoGraph == NULL)
	{
		mAutoGraph = new QLabel(this);
		mAutoGraph->setStyleSheet("color:#44608a;");
		mAutoGraph->resize(QSize(200, 20));
		mAutoGraph->move(64, 35);

		font.setPointSize(10);
		mAutoGraph->setFont(font);
	}
		
	if (mMessageTime == NULL)
	{
		mMessageTime = new QLabel(this);
		mMessageTime->setFixedSize(50, 20);
		mMessageTime->move(230, 12);
		mMessageTime->setStyleSheet("color: #108ee9;");
		mMessageTime->setAlignment(Qt::AlignRight);

		font.setPointSize(9);
		mMessageTime->setFont(font);
	}
		
	if (mMessageNum == NULL)
	{
		mMessageNum = new QLabel(this);
		mMessageNum->setFixedSize(20, 20);
		mMessageNum->setStyleSheet("background-color:#FF7F24;border-radius:10px;font: 75 10pt 微软雅黑;font-size:10px;font-color::rgb(0, 0, 0);");
		mMessageNum->move(280, 34);
		mMessageNum->setAlignment(Qt::AlignCenter);
	}
		
	if (mCloseBtn == NULL)
	{
		mCloseBtn = new QPushButton(this);
		mCloseBtn->setFixedSize(20, 20);
		mCloseBtn->move(310, 34);
		mCloseBtn->setStyleSheet("QPushButton{border-image:url(':/Login/Resources/login/message_close_hove.png')0 0 0 0 stretch stretch;}"
			"QPushButton:hover{border-image:url(':/Login/Resources/login/message_close.png')0 0 0 0 stretch stretch;}");
		mCloseBtn->hide();     // 初始化为隐藏
		mCloseBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
		mCloseBtn->setCursor(Qt::PointingHandCursor);

		connect(mCloseBtn, SIGNAL(clicked()), this, SLOT(slotCurrentChatClose()));
	}

	mNickName->setObjectName(strUserID); 
	mCloseBtn->setObjectName(strUserID);

	// 设置布局
	initMessageItemLayout();
}

void CFrientItemMessage::slotCurrentChatClose()
{
	if (mCloseBtn == NULL)
	{
		//qDebug() << QStringLiteral("CFrientStyleWidget::doCurrentChatClose空指针");
		return;
	}
	emit sigCurrentChatClose(mCloseBtn->objectName());
}

void CFrientItemMessage::initMessageItemLayout()
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

		img_upon_spacer->setFixedSize(name->x(), img->y());
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

		time_upon_spacer->setFixedSize(time->width() + 12 * 2, img->y());
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

void CFrientItemMessage::removeLayoutSpacing(QLayout* layout)
{
	layout->setSpacing(0);
	layout->setMargin(0);
}

void CFrientItemMessage::OnSetPicPath(QString strPath, int nType /*= 0*/)
{
	if (mHeadImage)
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

void CFrientItemMessage::OnSetNickNameText(QString strText, QString styleSheet /*= ""*/)
{
	if (mNickName == NULL) return;
	if (!strText.isEmpty())
	{
		mStrNickName = strText;     // 保存原样字符串
		// 设置简略字符串(超长显示...)
		QString elide_text = getElideString(strText, (QWidget*)mNickName, mNickName->font());
		mNickName->setText(elide_text);
		this->setToolTip(mStrNickName);
	}
	if (!styleSheet.isEmpty()) mNickName->setStyleSheet(styleSheet);
}

QString CFrientItemMessage::getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font)
{
	QFontMetrics fm(str_font);
	int str_width = fm.width(src_str);

	int widget_width = child_widget->width();
	QString elide_str = child_widget->fontMetrics().elidedText(src_str, Qt::ElideRight, widget_width);
	int str_width2 = fm.width(elide_str);

	return elide_str;
}

void CFrientItemMessage::OnSetAutoGrapthText(QString strText, QString styleSheet /*= ""*/)
{
	if (mAutoGraph == NULL) return;
	if (!strText.isEmpty())
	{
		if (strText.length() > 13)
		{
			QString strTemp = strText.mid(0, 13);
			int n = strTemp.indexOf("\n");
			if (n < 0)
				mAutoGraph->setText(strTemp + "...");
			else
				mAutoGraph->setText("");
		}
		else
		{
			mAutoGraph->setText(strText);
		}
	}
	if (!styleSheet.isEmpty()) mAutoGraph->setStyleSheet(styleSheet);
}

void CFrientItemMessage::OnSetMessageTime(QString strText, QString styleSheet /*= ""*/)
{
	if (mMessageTime == NULL) return;
	if (!strText.isEmpty())    mMessageTime->setText(strText);
	if (!styleSheet.isEmpty()) mMessageTime->setStyleSheet(styleSheet);
	//将创建时间写入消息项
	QString time = QDateTime::currentDateTime().toString();
	mMessageTime->setObjectName(time);
}

void CFrientItemMessage::OnSetMessageNum(QString strNum)
{
	if (mMessageNum)
	{
		mMessageNum->setText(strNum);
		emit sigChangeMessageNum();
		if (mMessageNum->text().isEmpty())
			mMessageNum->hide();
		else
			mMessageNum->show();
	}
}

QDateTime CFrientItemMessage::getLastTime()
{
	QDateTime time(QDate(1970, 1, 1));  //预设一个较早的时间，如果读取不出就返回该时间。
	if (mMessageTime)
		time = time.fromString(mMessageTime->objectName(), Qt::TextDate);

	return time;
}

QString CFrientItemMessage::GetNikeName()
{
	if (mNickName)
	{
		return mNickName->text();
	}
	return "";
}

int CFrientItemMessage::getMessageNum()
{
	if (mMessageNum)
	{
		if (mMessageNum->text().isEmpty())
			return 0;
		else
			return mMessageNum->text().toInt();
	}

	return 0;
}

void CFrientItemMessage::enterEvent(QEvent * event)
{
	mCloseBtn->show();
	mMessageNum->hide();
}

void CFrientItemMessage::leaveEvent(QEvent * event)
{
	mCloseBtn->hide();

	if (getMessageNum() > 0)
	    mMessageNum->show();
}
