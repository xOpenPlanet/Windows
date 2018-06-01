#ifndef CFRIENTSTYLEWIDGET_H
#define CFRIENTSTYLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDir>
#include <QEvent>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QBitmap>
#include <QSpacerItem>
#include <QDateTime>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "qlabelheader.h"

#ifdef Q_OS_WIN
#pragma execution_character_set("utf-8")
#endif

#ifndef Max
#define Max(a,b)  (a) > (b) ? (a) : (b) 
#endif  // Max

//�����б���ʽ

class CFrientStyleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CFrientStyleWidget(QWidget *parent = 0);
    ~CFrientStyleWidget();

	enum layout_type
	{
		contacts = 0,		// ��ϵ��, Ⱥ���item �Ĳ��ַ��
		group,              // Ⱥ��Ĳ��ַ��
		message,			// ��Ϣһ����item �Ĳ��ַ��
		chat,				// ���촰����ߵ�item �Ĳ��ַ��
		group_member, 		// Ⱥ���Ա��item �Ĳ��ַ��
		manager             // ��֤��Ϣ�������Ĳ��ַ��
	};

	enum item_list_type
	{
		chat_list = 1       // ���촰����ߵ�list
	};
signals:
    void sigLoginEditClose(QString);
	void sigCurrentChatClose(QString);
	void sigAddPerson(QString);
	// wxd add code - start
	void sigRemoveBuddyFromCGMemberList(QString);		// CG - CreateGroup  ���� mCreateGroupRemoveBtn ��������ź�
	// wxd add code - end
	void sigNumChanged();
public slots:
    void doLoginEditClose();
    void doCurrentChatClose(); 
	void doAddPerson();
	// wxd add code - start  
	void OnCGRemoveBtnClicked();				// CG - CreateGroup   ���� ContactsList��Ӧ��item��CheckBtn��pic ��MemberList�Ƴ�����Ӧ��item
	// wxd add code - end 
public:
    void OnSetHeadImageSize(int nWidth = 40,int nHeight = 40);  //����ͷ���С
    void OnSetNickNameText(QString strText,QString styleSheet="");  //�����ǳ�����
    void OnSetAutoGrapthText(QString strText,QString styleSheet=""); //����ǩ��/������Ϣ����
    void OnSetMessageTime(QString strText,QString styleSheet=""); //������Ϣ����ʱ������
	void OnSetPicPath(QString strPath, int nType = 0);     //����ͷ��·��
	void onSetHeaderImage(QPixmap);
	void onSetIdentity(int mana);     //������ݣ�9��Ⱥ����1�ǹ���Ա��0����ͨ��Ա��
    void OnInitMessage(QString);                   //��Ϣ�����б���ʽ
    void OnInitContacts(QString);                  //��ϵ�˺����б���ʽ
	void OnInitGroup(QString strUserID);           //Ⱥ���б���ʽ��
    void OnInitLoginEdit(QString);                 //��½�б�
    void OnInitChat(QString strUserID);			   // ��ʼ�����촰��
    void OnSetMessageNum(QString strNum);
	QString OnGetMessageNum();//added by wangqingjie
    QString OnGetHeaderImagePath();
    void OnInitGroupUserList(QString strGroupUserID); 
	void OnInitLogUserList(QString strGroupUserID);
	void onInitManagerUserList(QString strUserID, bool hasRead = false);
	void onInitManagerApplyGroup(QString strUserID, QString group, bool hasRead = false);
	void OnInitMessageBoxList(QString strBuddyID);
	void OnInitSearchBuddyList(QString strBuddyID);

	void OnSetPicPathByHttp(QString strPath, QString strDefaultImage = ":/PerChat/Resources/person/temp.png");

	void OnSetAddPersonButtonText(QString strText);

	QString GetNikeName();  //��ȡNikeName
	QString GetAutoGraph();//��ȡmAutoGraph����
	QString GetStrTime();//��ȡʱ��
	// wxd add code -- start
	QPushButton* closeButton();       // ���عرհ�ť�Ķ���ָ��
	QString getLoginUserID();         // ��¼�����е������б��item�е�mBtnClose��objectName�Ƕ�Ӧ��UserID
	bool getCGCheckBtnStatus();										// CG - CreateGroup
	void changeCGCheckBtnStatus();									// �ı� CGContactsListItem�� CheckBtn��״̬
	void OnInitCreateGroupContactsList(QString strBuddyID);         // ��ʼ�� �½�Ⱥ�� ����ʱ�ĺ����б� ��item����Բ�εĶԺŸ�ѡ��
	void OnInitCreateGroupMemberList(QString strBuddyID);			// ��ʼ�� �½�Ⱥ�� ����ʱ��Ⱥ���Ա�б� ��item����Բ�εĲ�Ÿ�ѡ��
	// wxd add code -- end

	//************************************
	// Method:    OnInitAddCreateList
	// FullName:  CFrientStyleWidget::OnInitAddCreateList
	// Access:    public 
	// Returns:   void
	// Qualifier: ��������б�
	// Parameter: QString strTitle
	//************************************
	void OnInitAddCreateList(QString strTitle);

	void OnInitDevice(QString strDeviceName); //��ʼ���豸

	QDateTime getLastTime();   //����Ϣ�б���ȡ����ͨ��ʱ�䡣
protected: 
	// wxd add code - start
	void resizeEvent(QResizeEvent * event);  // ���ڸı��С���¼�����   �������ػ�   mCompanyName��label 
	void enterEvent(QEvent * event);         // ��������¼�
	void leaveEvent(QEvent * event);         // ����Ƴ��¼� 
	// wxd add code - end
private:
	// wxd add code - start
	void InitLayout(int layout_type);           // ��ʼ������
	void initChatItemLayout();					// ���촰����ߵ�item �Ĳ��ַ��
	void initGroupItemLayout();                 // Ⱥ��Ĳ��ַ��
	void initManagerItemLayout();               // ��֤��Ϣ�������Ĳ��ַ��
	void initMessageItemLayout();				// ��Ϣһ����item �Ĳ��ַ��
	void initContactsItemLayout();				// ��ϵ�˵�item �Ĳ��ַ��
	void initGroupMemberItemLayout();			// Ⱥ���Ա��item �Ĳ��ַ��
	void removeLayoutSpacing(QLayout* layout);  // ȥ��layout�Ŀؼ�֮��ļ�϶
	QString getElideString(const QString& src_str, const QWidget* child_widget, const QFont& str_font);   // ��ȡ src_str ������ child_widget�ؼ����ַ���(����...�ļ�����Ϣ)
	// wxd add code - end
private slots:
	void doClickAcceptBtn();
signals:
	void sigClickAcceptBtn();
	
private:
	QLabelHeader *mHeadImage;  //ͷ��
    QLabel  *mAutoGraph; //ǩ��/�����¼
	QLabel  *mMessageNum;   //��Ϣ��Ŀ
    QLabel  *mMessageTime; // ��Ϣ����ʱ��
    QString mstrPicPath;   //ͷ��·��
	//  wxd add code - start 2017/4/10
	bool	mCGCheckBtnIsChecked; // CG - CreateGroup    ��ʶ mCreateGroupCheckBtn �Ƿ��Ѿ���ѡ��
	int     mItemListType;     // ��widget����item��list������
	//  wxd add code - end
	//added by fanwenxing
	QLabel *identity;    //Ⱥ��Ա�б����е����ͼ�ꡣ
public:
    QPushButton *mCloseBtn; 
    QLabel  *mNickName;  //�ǳ�
	QPushButton *mAddPerson; //��Ӻ���
	QPushButton *mAcceptBtn;  //ͬ�ⰴť;
	// wxd add code - start
	QLabel		*mCreateGroupCheckBtn;		// contacts
	QPushButton *mCreateGroupRemoveBtn; 
	QString		 mStrNickName;				// mNickName��ԭ���ַ���
	// wxd add code - end
};

void circleHeaderImage(QPixmap &headerImage);

#endif // CFRIENTSTYLEWIDGET_H
