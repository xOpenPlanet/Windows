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

	void OnInitContacts(QString);                  //��ϵ�˺����б���ʽ
	void OnSetPicPath(QString strPath);     //����ͷ��·��

	void UpdateHeaderImage(QPixmap pix);

	void OnSetNickNameText(QString strText, QString styleSheet = "");  //�����ǳ�����
	void OnSetAutoGrapthText(QString strText, QString styleSheet = ""); //����ǩ��/������Ϣ����

	QLabel  *mNickName;  //�ǳ�
	QString		 mStrNickName;				// mNickName��ԭ���ַ���

private:
	void initContactsItemLayout();				// ��ϵ�˵�item �Ĳ��ַ��
	void removeLayoutSpacing(QLayout* layout);  // ȥ��layout�Ŀؼ�֮��ļ�϶
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // ��ȡ src_str ������ child_widget�ؼ����ַ���(����...�ļ�����Ϣ)
private:
	QLabelHeader *mHeadImage;  //ͷ��
	QLabel  *mAutoGraph; //ǩ��/�����¼
};

#endif // CFRIENTITEMBUDDY_H
