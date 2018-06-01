#ifndef CFRIENTITEMLOGIN_H
#define CFRIENTITEMLOGIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include "qlabelheader.h"

class CFrientItemLogin : public QWidget
{
	Q_OBJECT

public:
	CFrientItemLogin(QWidget *parent);
	~CFrientItemLogin();

	void OnInitLoginEdit(QString userID);                 //登陆列表
	void OnSetNickNameText(QString strText, QString styleSheet = "");  //设置昵称名称
	void OnSetPicPath(QString strPath, int nType = 0);     //设置头像路径
	QString getLoginUserID();         // 登录窗口中的下拉列表的item中的mBtnClose的objectName是对应的UserID

	QPushButton *mCloseBtn;
	QLabel  *mNickName;  //昵称
	QString		 mStrNickName;				// mNickName的原样字符串

signals:
	void sigLoginEditClose(QString);

private slots:
    void slotLoginEditClose();

private:
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // 获取 src_str 适配于 child_widget控件的字符串(加上...的简略信息)

private:
	QLabelHeader *mHeadImage;  //头像
};

#endif // CFRIENTITEMLOGIN_H
