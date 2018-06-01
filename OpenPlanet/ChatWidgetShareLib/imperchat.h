#ifndef IMPERCHAT_H
#define IMPERCHAT_H

#include <QWidget>
#include <QFile>
#include <QKeyEvent>
#include <QDir>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QMainWindow>
#include <QDrag>
#include <QTextEdit>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QList>
#include <QJsonDocument>
#include <qclipboard.h>
#include <tchar.h>
#include "ui_imperchat.h"
#include "qlabelheader.h"
#include "imusermessage.h"
#include "common.h"
#include "stdafx.h"
#include "childWidget/filetypeex.h"
#include "childWidget/zoomimg.h"
#include "childWidget/expresswidget.h"
#include "cfrientstylewidget.h"

#include "secretWidget/secretletterwidget.h"

class IMPerChat : public QWidget
{
	Q_OBJECT

public:
	IMPerChat(QWidget *parent = 0);
	~IMPerChat();


	//************************************
	// Method:    OnCloseExpress
	// FullName:  IMPerChat::OnCloseExpress
	// Access:    protected 
	// Returns:   void
	// Qualifier: �رձ���
	//************************************
	void OnCloseExpress();

	//************************************
	// Method:    OnSetNikeName
	// FullName:  IMPerChat::OnSetNikeName
	// Access:    public 
	// Returns:   void
	// Qualifier: �����ǳ�
	// Parameter: QString
	// Parameter: QString
	//************************************
	void OnSetNikeName(QString strText, QString strBuddyID);

	//************************************
	// Method:    OnSetAutoGraph
	// FullName:  IMPerChat::OnSetAutoGraph
	// Access:    public 
	// Returns:   void
	// Qualifier: ����ǩ��
	// Parameter: QString
	//************************************
	void OnSetAutoGraph(QString strText);

	//************************************
	// Method:    OnClearMessageInfo
	// FullName:  IMPerChat::OnClearMessageInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: ���webview����
	//************************************
	void OnClearMessageInfo();

	//************************************
	// Method:    OnInertSendMessageTextInfo
	// FullName:  IMPerChat::OnInertSendMessageTextInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: ������Ϣ չʾ
	// Parameter: QString strMsg
	// Parameter: QString strHeadImage
	//************************************
	void OnInertSendMessageTextInfo(QString strMsg, QString strHeadImage, MessageInfo msgInfo);

	//************************************
	// Method:    OnInsertRecMessageTextInfo
	// FullName:  IMPerChat::OnInsertRecMessageTextInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: ������Ϣչʾ
	// Parameter: QString strMsg
	// Parameter: QString strHeadImage
	//************************************
	void OnInsertRecMessageTextInfo(QString strMsg, QString strHeadImage, QString msgID, int score);
	void OnInsertRecVideoInfo(QString strMsg, QString strHeadImage, QString msgID, int score);

	void UpdateMessageStateInfo(QByteArray msgID, int nState, int score);

	// wxd add code - start
	void OnSetChatHeaderImage(QString strHeaderImg);  // �������촰�ڵ�ͷ��
	void HideChatHeaderImage();    // �������촰�ڵ�ͷ��
	// wxd add code - end
	void OnRecvFileMessage(MessageInfo messageInfo, QString strHeadImage, QString fileLocalPath);
	void OnRecvImgMessage(MessageInfo messageInfo, QString strHeadImage);
	//added by fanwenxing
	void OnRecVdoMessage(MessageInfo messageInfo, QString strHeadImage);
	//added by wangqingjie
	void OnRecvTaskMessage(MessageInfo messageInfo, QString strHeadImage);  //����������Ϣ

	void OnRecvFormMessage(MessageInfo messageInfo, QString strHeaderPath); // ���յ�����Ϣ

	//added by wangqingjie
	void SendDragFile(QString);

	void OnSendScreenShotPic(QString strShotFileName);  //���ͽ�ͼ

	void SendPicture(QString fileName);
public slots:
    void InitMessageInfo(QString strUserID = "");
    void slotOpenDocument(QString msgID);
	void slotOpenFile(QString msgID);
	void slotGetFile(QString msgID);
	void slotRequestHttpFileResult(bool);
	bool slotSaveFile(QString msgID);
	void slotZoomImg(QString strFilePath);
	void slotCancleLoadorDownLoad();
	void slotSendFileByID(QString);
	void slotUpPicReplyFinished(bool result, QByteArray strResult);
	void slotVideoPlay(QString mediaPath);
	void slotOpenPerLog();
protected:
	//************************************
	// Method:    RegisterHandle
	// FullName:  IMPerChat::RegisterHandle
	// Access:    protected 
	// Returns:   void
	// Qualifier: ע���¼�
	//************************************
	void RegisterHandle();

	void showEvent(QShowEvent *event);

	bool eventFilter(QObject *obj, QEvent *e);

	virtual void mousePressEvent(QMouseEvent *event);
	void ExpressHide(QRect, QPoint);

	void OnDealRecvImgMessage(MessageInfo messageInfo, QString strHeadImage);
	
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);

	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private: 
	QString formatSendMessageFromImgPathToImgDescription(const QString& strSendMessage);	// �� �û����͵���Ϣ�ַ����е� ͷ���·���滻Ϊ[xx]��ʽ
	QString formatMessageFromImgDescriptionToImgPath(const QString& strMessage);			// �� ����[xx]������ʽ����Ϣ�ַ��� ת��Ϊ �����·����ʽ���ַ���
private slots:
	//************************************
	// Method:    doExpressNormalImagePath
	// FullName:  IMPerChat::doExpressNormalImagePath
	// Access:    private 
	// Returns:   void
	// Qualifier: ѡ����� ����ͼƬ·��
	// Parameter: QString strImgPath
	//************************************
	void doExpressNormalImagePath(QString strImgPath);

	//************************************
	// Method:    doClickedSetFont
	// FullName:  IMPerChat::doClickedSetFont
	// Access:    private 
	// Returns:   void
	// Qualifier: ѡ������
	//************************************
	void doClickedSetFont();   
	//************************************
	// Method:    doSelectExpress
	// FullName:  IMPerChat::doSelectExpress
	// Access:    private 
	// Returns:   void
	// Qualifier: ѡ�����
	//************************************
	void doSelectExpress();    
	//************************************
	// Method:    doSendMessage
	// FullName:  IMPerChat::doSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: ������Ϣ
	//************************************
	void doSendMessage();        
	//************************************
	// Method:    doClickedShake
	// FullName:  IMPerChat::doClickedShake
	// Access:    private 
	// Returns:   void
	// Qualifier: ������ʹ��ڶ���
	//************************************
	void doClickedShake();     
	//************************************
	// Method:    doClickedVoiceChat
	// FullName:  IMPerChat::doClickedVoiceChat
	// Access:    private 
	// Returns:   void
	// Qualifier: �����������
	//************************************
	void doClickedVoiceChat();  
	//************************************
	// Method:    doClickedPicture
	// FullName:  IMPerChat::doClickedPicture
	// Access:    private 
	// Returns:   void
	// Qualifier: �������ͼƬ
	//************************************
	void doClickedPicture();    
	//************************************
	// Method:    doClickedCutPicture
	// FullName:  IMPerChat::doClickedCutPicture
	// Access:    private 
	// Returns:   void
	// Qualifier: �����ͼ
	//************************************
	void doClickedCutPicture(); 

	void slotUpFileReplyFinished(bool, QByteArray);
	void doUpLoadFileProgress(qint64, qint64);
	void slotDownLoadFileProgress(qint64,qint64);

	//added by fanwenxing
	void slotCefDrags(QStringList);

	void slotClickedSendLetter();
	void slotSecretLetter(QString password, QString text);
signals:
	//************************************
	// Method:    SendHideWidget
	// FullName:  IMPerChat::SendHideWidget
	// Access:    private 
	// Returns:   void
	// Qualifier: �������ش����ź�
	//************************************
	void sigHideWidget();

	//************************************
	// Method:    SendWidgetMinSize
	// FullName:  IMPerChat::SendWidgetMinSize
	// Access:    private 
	// Returns:   void
	// Qualifier: ���ʹ�����С��
	//************************************
	void sigWidgetMinSize();

	// wxd add code - start
	void sigBtnCloseWClicked();      // ������ߵİ�ť����¼�
	// wxd add coed - end
	void sigCancle();

	void sigKeyUpDown(QKeyEvent *);

	void sigOpenChatWindows(QString strToUserID);
	void sigShowNormalWindow();           //���ڻ�ԭ
	void sigOpenPerLog(QString);
private:
	Ui::IMPerChat ui;
	ExpressWidget *mExpressWidget; //���鴰��
	QRect rectExpressWidget;          //���鴰�ڵ�λ��

	QLabelHeader*    mChatHeaderImage;   // ���촰�ڵ�ͷ�񣬵�����ʱ��ʾ  wxd add 
	bool	   mbExpress_widget_is_showing;   // ���鴰�ڵ�״̬  �Ƿ�������ʾ

	//added by wangqingjie
	QString mMsgID;
	QString mUpFileName;

	//added by fanwenxing
	bool copying;
	QLabel *sendTip;

	QWidget* cut_line;
	bool drag;
};

#endif // IMPERCHAT_H
