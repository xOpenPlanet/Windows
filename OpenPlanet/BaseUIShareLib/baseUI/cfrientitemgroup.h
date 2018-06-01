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

	void OnInitGroup(QString strUserID);           //Ⱥ���б���ʽ��
	void OnSetPicPath(QString strPath);     //����ͷ��·��
	void OnSetNickNameText(QString strText, QString styleSheet = "");  //�����ǳ�����

	QLabel  *mNickName;  //�ǳ�
	QString		 mStrNickName;				// mNickName��ԭ���ַ���

private:
	void initGroupItemLayout();                 // Ⱥ��Ĳ��ַ��
	void removeLayoutSpacing(QLayout* layout);  // ȥ��layout�Ŀؼ�֮��ļ�϶
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // ��ȡ src_str ������ child_widget�ؼ����ַ���(����...�ļ�����Ϣ)

private:
	QLabelHeader *mHeadImage;  //ͷ��
};

#endif // CFRIENTITEMGROUP_H
