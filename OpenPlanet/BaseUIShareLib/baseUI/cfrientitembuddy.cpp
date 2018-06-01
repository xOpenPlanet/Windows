#include "cfrientitembuddy.h"

CFrientItemBuddy::CFrientItemBuddy(QWidget *parent)
	: QWidget(parent)
{
	mHeadImage = NULL;
	mNickName = NULL;
	mAutoGraph = NULL;
}

CFrientItemBuddy::~CFrientItemBuddy()
{

}

void CFrientItemBuddy::OnInitContacts(QString strUserID)
{
	QFont font;
	font.setFamily("Microsoft YaHei");

	if (mHeadImage == NULL)
	{
		mHeadImage = new QLabelHeader(this);
		//设置头像的的底色为透明。
		mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
		mHeadImage->setFixedSize(36, 36);
		mHeadImage->move(11, 11);
	}
		
	if (mNickName == NULL)
	{
		mNickName = new QLabel(this);
		mNickName->setStyleSheet("color:#108ee9;");
		mNickName->setAttribute(Qt::WA_TranslucentBackground);
		mNickName->setFixedSize(QSize(150, 25));
		mNickName->move(59, 20);

		font.setPointSize(12);
		mNickName->setFont(font);
	}

	if (mAutoGraph == NULL)
	{
		mAutoGraph = new QLabel(this);
		mAutoGraph->setStyleSheet("color:#44608a;");
		mAutoGraph->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
		mAutoGraph->resize(QSize(200, 24));
		mAutoGraph->setMinimumHeight(24);
		mAutoGraph->move(64, 35);

		font.setPointSize(8);
		mAutoGraph->setFont(font);
	}

	mNickName->setObjectName(strUserID);

	// 设置布局
	initContactsItemLayout();
}

void CFrientItemBuddy::initContactsItemLayout()
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

void CFrientItemBuddy::removeLayoutSpacing(QLayout* layout)
{
	layout->setSpacing(0);
	layout->setMargin(0);
}

void CFrientItemBuddy::OnSetPicPath(QString strPath)
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
		pix.loadFromData(bytearray);
		
		if (pix.isNull())
			pix.load(":/PerChat/Resources/person/temp.png");

		mHeadImage->setAutoFillBackground(true);
		mHeadImage->setPixmap(pix);
		mHeadImage->setScaledContents(true);
		mHeadImage->setObjectName(strPath);
	}
}

void CFrientItemBuddy::UpdateHeaderImage(QPixmap pix)
{
	if (mHeadImage)
	{
		mHeadImage->setAutoFillBackground(true);
		mHeadImage->setPixmap(pix);
		mHeadImage->setScaledContents(true);
	}
}

void CFrientItemBuddy::OnSetNickNameText(QString strText, QString styleSheet /*= ""*/)
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

QString CFrientItemBuddy::getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font)
{
	QFontMetrics fm(str_font);
	int str_width = fm.width(src_str);

	int widget_width = child_widget->width();
	QString elide_str = child_widget->fontMetrics().elidedText(src_str, Qt::ElideRight, widget_width);
	int str_width2 = fm.width(elide_str);

	return elide_str;
}

void CFrientItemBuddy::OnSetAutoGrapthText(QString strText, QString styleSheet /*= ""*/)
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
