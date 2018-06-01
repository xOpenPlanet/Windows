#ifndef CFRIENTITEMMESSAGE_H
#define CFRIENTITEMMESSAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QFile>
#include <QDateTime>
#include "qlabelheader.h"

class CFrientItemMessage : public QWidget
{
	Q_OBJECT

public:
	CFrientItemMessage(QWidget *parent);
	~CFrientItemMessage();

	void OnInitMessage(QString);                   //��Ϣ�����б���ʽ
	void OnSetPicPath(QString strPath, int nType = 0);     //����ͷ��·��
	void OnSetNickNameText(QString strText, QString styleSheet = "");  //�����ǳ�����
	void OnSetAutoGrapthText(QString strText, QString styleSheet = ""); //����ǩ��/������Ϣ����
	void OnSetMessageTime(QString strText, QString styleSheet = ""); //������Ϣ����ʱ������
	void OnSetMessageNum(QString strNum);

	int getMessageNum();
	QDateTime getLastTime();   //����Ϣ�б���ȡ����ͨ��ʱ�䡣
	QString GetNikeName();  //��ȡNikeName

	QLabel  *mNickName;  //�ǳ�
	QPushButton *mCloseBtn;
	QString		 mStrNickName;				// mNickName��ԭ���ַ���

signals:
	void sigCurrentChatClose(QString);

	void sigChangeMessageNum();

private slots:
	void slotCurrentChatClose();

private:
	void initMessageItemLayout();				// ��Ϣһ����item �Ĳ��ַ��
	void removeLayoutSpacing(QLayout* layout);  // ȥ��layout�Ŀؼ�֮��ļ�϶
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // ��ȡ src_str ������ child_widget�ؼ����ַ���(����...�ļ�����Ϣ)

	void enterEvent(QEvent * event);         // ��������¼�
	void leaveEvent(QEvent * event);         // ����Ƴ��¼� 

private:
	QLabelHeader *mHeadImage;  //ͷ��
	QLabel  *mAutoGraph; //ǩ��/�����¼
	QLabel  *mMessageTime; // ��Ϣ����ʱ��
	QLabel  *mMessageNum;   //��Ϣ��Ŀ
};

#endif // CFRIENTITEMMESSAGE_H
