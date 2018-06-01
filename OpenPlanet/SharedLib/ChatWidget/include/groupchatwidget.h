#ifndef GROUPCHATWIDGET_H
#define GROUPCHATWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QDebug>
#include <QScrollBar>
#include <QMovie>
#include <qmenu.h>
#include <qclipboard.h>
#include <qmimedata.h>
#include <qmessagebox.h>
#include <tchar.h>
#include <QJsonDocument>
#include "imusermessage.h"
#include "stdafx.h"
#include "ui_groupchatwidget.h"
#include "imdownloadheaderimg.h"
#include "IMRequestBuddyInfo.h"
#include "childWidget/expresswidget.h"
#include "childWidget/groupsearchwidget.h"

#include "thread/threadloadgroupuserlist.h"

class GroupChatWidget : public QWidget
{
	Q_OBJECT

public:
	GroupChatWidget(QWidget *parent = 0);
	~GroupChatWidget();
	void OnCloseExpress();
	void ExpressHide(QRect rect, QPoint pos);
	void OnInsertGroupUserList(QString strGroupID);
	void OnInsertGroupUser(BuddyInfo info);
	void InitMessageInfo(QString strCurrentID, QString strUserID);
	void OnRevMessage(MessageInfo messageInfo);
	void OnUpdateGroupBuddyHeaderImg(QString strBuddyID, QString strPath);
	void UpdateMessageStateInfo(QByteArray msgID, int nState, int integral);
	void OnInertSendMessageTextInfo(QString strMsg, QString strHeadImage, MessageInfo msgInfo);

	void OnRecvGroupFile(MessageInfo, QString);
	//added by wangqingjie
	void OnInsertRecvFileMessage(MessageInfo msgInfo, QString strNickName);
	void InsertSendFileMessage(MessageInfo msgInfo);//

	void OnSendScreenShotPic(QString strShotFileName);
	//added by fanwenxing
	void scrollBottom();
	void userQuitGroup(QString userID);


	void setNikeName(QString strNikeName){ mNikeName = strNikeName; }
protected:
	void resizeEvent(QResizeEvent * event);
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private:
	void RegisterHandle();
	bool eventFilter(QObject *obj, QEvent *e);//�¼�������
	void showEvent(QShowEvent *event);

	void mousePressEvent(QMouseEvent *event);
	void OnInsertGroupUserItem(QString strUserID, QString strPicPath, QString strNickName, int mana, int nHeight=30);

	void OnInsertRecMessageTextInfo(QString strMsg, QString strHeadImage, int score);
	QString GetBuddyHeaderImage(QString strGroupID, QString strBuddyID);
	void OnClearMessageInfo();

	// wxd add code - start
	void OnInsertRecvMessageTextInfo(QString strMsg, QString strHeadImage, QString strNickName,QString strMsgId, int score);//changed by wqj 
	void setChildWidgetFixedSize();
	void initLayout();
	void removeLayoutSpacing(QLayout* layout);
	void updateGroupMemberCount(int member_count);      // ����Ⱥ���Ա����(Ⱥ��Ա�б������Label)
	QString formatSendMessageFromImgPathToImgDescription(const QString& strSendMessage);   // ����������� <img src='xxx'/> ��ʽ���ַ���ת��Ϊ ����������� [xx]  eg: [΢Ц]
	QString formatMessageFromImgDescriptionToImgPath(const QString& strMessage);
	// wxd add code - end
	//added by fanwenxing
	void OnInsertRecVideoInfo(QString strMsg, QString strHeadImage, QString strNickName, QString strMsgId, int score);

	void SendPicture(QString fileName);
private slots:
	void slotClickedClose();
	void slotClickedCutPic();
	void slotClickedExpress();
	void slotClickedFont();
	void slotClickedPicture();
	void slotClickedSend();
	void slotClickedShake();
	void slotClickedVoiceChat();
	void slotExpressNormalImagePath(QString strPath);
	void slotClickedDoubleItem(QListWidgetItem *item);

	void slotOnBtnCloseWClicked(); 
	void slotGroupFile();
	void doUpLoadFileProgress(qint64 sendnum, qint64 total);
	void slotDownLoadFileProgress(qint64, qint64);

	void slotUpPicReplyFinished(bool result, QByteArray strResult);

	void slotStartGroupUserThread();    //����groupuser���̵߳ķ�����
	void slotGroupUserInfoLoad(int); //Ⱥ���Ա����������ʱ���߳�ִ�м��ط�����
	void slotThreadLoadGroupUserInfo(BuddyInfo buddyInfo);   //ͨ���̼߳���Ⱥ��Ա��
	void slotReLoadGroupUserList();

	void slotUpdateGroupBuddyImage(int, QPixmap);

	void slotCefDrags(QStringList list);

	void slotParseGroupBuddyInfo(QString, QList<BuddyInfo>);
public slots:
	void slotUpFileReplyFinished(bool, QByteArray);
	void slotGetFile(QString msgID);
	bool slotSaveFile(QString msgID);
	void slotRequestHttpFileResult(bool result);
	void slotOpenDocument(QString msgID);
	void slotOpenGroupFile(QString msgID);
	void slotZoomImg(QString strFileName);
	void slotVideoPlay(QString mediaPath);
	void slotCancleLoadorDownLoad();
	void slotSendFile(QString strFileName);
	void slotSendFileByID(QString msgID);
	
signals:
	void sigClose();

	void sigShowPerChat(QString strUserID);
	// wxd add code - start
	void sigBtnCloseWClicked();
	// wxd add code - end
	void sigKeyUpDown(QKeyEvent *);

	void sigGroupBuddyPerChat(QString strUserID);
	//added by wangqingjie for cancle
	void sigCancle();

	void sigShowWindowMinsize();           //������С��

	void sigShowNormalWindow();           //���ڻ�ԭ
	void sigOpenMessageLog();    //����Ϣ��¼���ź�

private slots:
	void slotContextMenuRequested(const QPoint &pos);
	void slotSetManager();
	void slotCancelManager();
	void slotAddFriend();
	void slotHttpAddPersonResultInfo(bool bResult, QString strResult);

	void slotShowOrHideSearch(bool);
	void slotOpenSearchUser(QString);

	void slotDebug(bool, QString);
private:
	Ui::GroupChatWidget ui;
	ExpressWidget *mExpressWidget; //���鴰��
	QRect rectExpressWidget;          //���鴰�ڵ�λ��
	QString mCurrentID; 

	QMovie *movie;   //ˢ�°�ť��gif��
	
	//int mGroupMemberCount;     // Ⱥ��Ա���� wxd add
	bool mbExpress_widget_is_showing;    // ���鴰��״̬   �Ƿ�������ʾ

	ThreadLoadGroupUserList *thread;

	//added by fanwenxing
	bool copying;
	GroupSearchWidget *searchWidget;
	QLabel *sendTip;

	QWidget* cut_line;
	bool drag;

	QString mNikeName;
};

#endif // GROUPCHATWIDGET_H
