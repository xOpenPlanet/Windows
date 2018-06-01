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

	void OnInitLoginEdit(QString userID);                 //��½�б�
	void OnSetNickNameText(QString strText, QString styleSheet = "");  //�����ǳ�����
	void OnSetPicPath(QString strPath, int nType = 0);     //����ͷ��·��
	QString getLoginUserID();         // ��¼�����е������б��item�е�mBtnClose��objectName�Ƕ�Ӧ��UserID

	QPushButton *mCloseBtn;
	QLabel  *mNickName;  //�ǳ�
	QString		 mStrNickName;				// mNickName��ԭ���ַ���

signals:
	void sigLoginEditClose(QString);

private slots:
    void slotLoginEditClose();

private:
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // ��ȡ src_str ������ child_widget�ؼ����ַ���(����...�ļ�����Ϣ)

private:
	QLabelHeader *mHeadImage;  //ͷ��
};

#endif // CFRIENTITEMLOGIN_H
