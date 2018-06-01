#ifndef CFRIENTITEMGROUP_H
#define CFRIENTITEMGROUP_H

#include <QWidget>
#include <QLabel>
#include "qlabelheader.h"
#include <QLayout>
#include <QFile>

class CFrientItemGroup : public QWidget
{
	Q_OBJECT

public:
	CFrientItemGroup(QWidget *parent);
	~CFrientItemGroup();

	void UpdateHeaderImage(QPixmap pix);

	void OnInitGroup(QString strUserID);           //群组列表样式。
	void OnSetPicPath(QString strPath);     //设置头像路径
	void OnSetNickNameText(QString strText, QString styleSheet = "");  //设置昵称名称

	QLabel  *mNickName;  //昵称
	QString		 mStrNickName;				// mNickName的原样字符串

private:
	void initGroupItemLayout();                 // 群组的布局风格
	void removeLayoutSpacing(QLayout* layout);  // 去掉layout的控件之间的间隙
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // 获取 src_str 适配于 child_widget控件的字符串(加上...的简略信息)

private:
	QLabelHeader *mHeadImage;  //头像
};

#endif // CFRIENTITEMGROUP_H
