#ifndef CFRIENTITEMBUDDY_H
#define CFRIENTITEMBUDDY_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QFile>
#include "qlabelheader.h"

class CFrientItemBuddy : public QWidget
{
	Q_OBJECT

public:
	CFrientItemBuddy(QWidget *parent);
	~CFrientItemBuddy();

	void OnInitContacts(QString);                  //联系人好友列表样式
	void OnSetPicPath(QString strPath);     //设置头像路径

	void UpdateHeaderImage(QPixmap pix);

	void OnSetNickNameText(QString strText, QString styleSheet = "");  //设置昵称名称
	void OnSetAutoGrapthText(QString strText, QString styleSheet = ""); //设置签名/聊天信息内容

	QLabel  *mNickName;  //昵称
	QString		 mStrNickName;				// mNickName的原样字符串

private:
	void initContactsItemLayout();				// 联系人的item 的布局风格
	void removeLayoutSpacing(QLayout* layout);  // 去掉layout的控件之间的间隙
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // 获取 src_str 适配于 child_widget控件的字符串(加上...的简略信息)
private:
	QLabelHeader *mHeadImage;  //头像
	QLabel  *mAutoGraph; //签名/聊天记录
};

#endif // CFRIENTITEMBUDDY_H
