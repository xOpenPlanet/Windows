#include "cfrientitemlogin.h"

CFrientItemLogin::CFrientItemLogin(QWidget *parent)
{
	mHeadImage = NULL;
	mNickName = NULL;
	mCloseBtn = NULL;
}

CFrientItemLogin::~CFrientItemLogin()
{

}

void CFrientItemLogin::OnInitLoginEdit(QString userID)
{
	if (mHeadImage == NULL)
		mHeadImage = new QLabelHeader(this);
	if (mNickName == NULL)
		mNickName = new QLabel(this);
	if (mCloseBtn == NULL)
		mCloseBtn = new QPushButton(this);
	mNickName->setAttribute(Qt::WA_TranslucentBackground);
	mNickName->setStyleSheet("font: 75 16pt Î¢ÈíÑÅºÚ;font-size:16px;font-color::rgb(0, 0, 0);");
	//ÉèÖÃÍ·ÏñµÄµÄµ×É«ÎªÍ¸Ã÷¡£
	mHeadImage->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
	mHeadImage->setFixedSize(30, 30);
	mHeadImage->move(5, 5);
	mNickName->resize(QSize(140, 20));
	mNickName->move(50, 10);
	mCloseBtn->setFixedSize(20, 20);
	mCloseBtn->move(145, 10);
	mCloseBtn->setStyleSheet("QPushButton{border-image:url(:/Login/Resources/login/message_close_hove.png)0 0 0 0 stretch stretch;}"
		"QPushButton:hover{border-image:url(:/Login/Resources/login/message_close.png)0 0 0 0 stretch stretch;}");

	mCloseBtn->setObjectName(userID);
	connect(mCloseBtn, SIGNAL(clicked()), this, SLOT(slotLoginEditClose()));
}

void CFrientItemLogin::slotLoginEditClose()
{
	if (mCloseBtn == NULL)
	{
		//qDebug() << QStringLiteral("CFrientStyleWidget::doLoginEditClose¿ÕÖ¸Õë");
		return;
	}
	emit sigLoginEditClose(mCloseBtn->objectName());
}

void CFrientItemLogin::OnSetNickNameText(QString strText, QString styleSheet /*= ""*/)
{
	if (mNickName == NULL) return;
	if (!strText.isEmpty())
	{
		mStrNickName = strText;     // ±£´æÔ­Ñù×Ö·û´®
		// ÉèÖÃ¼òÂÔ×Ö·û´®(³¬³¤ÏÔÊ¾...)
		QString elide_text = getElideString(strText, (QWidget*)mNickName, mNickName->font());
		mNickName->setText(elide_text);
		this->setToolTip(mStrNickName);
	}
	if (!styleSheet.isEmpty()) mNickName->setStyleSheet(styleSheet);
}

QString CFrientItemLogin::getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font)
{
	QFontMetrics fm(str_font);
	int str_width = fm.width(src_str);

	int widget_width = child_widget->width();
	QString elide_str = child_widget->fontMetrics().elidedText(src_str, Qt::ElideRight, widget_width);
	int str_width2 = fm.width(elide_str);

	return elide_str;
}

void CFrientItemLogin::OnSetPicPath(QString strPath, int nType /*= 0*/)
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

QString CFrientItemLogin::getLoginUserID()
{
	if (mCloseBtn == NULL)
	{
		//qDebug() << QStringLiteral("CFrientStyleWidget::getLoginUserID¿ÕÖ¸Õë");
		return "";
	}
	return mCloseBtn->objectName();
}
