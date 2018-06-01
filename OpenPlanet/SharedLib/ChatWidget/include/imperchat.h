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
	// Qualifier: 关闭表情
	//************************************
	void OnCloseExpress();

	//************************************
	// Method:    OnSetNikeName
	// FullName:  IMPerChat::OnSetNikeName
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置昵称
	// Parameter: QString
	// Parameter: QString
	//************************************
	void OnSetNikeName(QString strText, QString strBuddyID);

	//************************************
	// Method:    OnSetAutoGraph
	// FullName:  IMPerChat::OnSetAutoGraph
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置签名
	// Parameter: QString
	//************************************
	void OnSetAutoGraph(QString strText);

	//************************************
	// Method:    OnClearMessageInfo
	// FullName:  IMPerChat::OnClearMessageInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: 清空webview内容
	//************************************
	void OnClearMessageInfo();

	//************************************
	// Method:    OnInertSendMessageTextInfo
	// FullName:  IMPerChat::OnInertSendMessageTextInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: 发送消息 展示
	// Parameter: QString strMsg
	// Parameter: QString strHeadImage
	//************************************
	void OnInertSendMessageTextInfo(QString strMsg, QString strHeadImage, MessageInfo msgInfo);

	//************************************
	// Method:    OnInsertRecMessageTextInfo
	// FullName:  IMPerChat::OnInsertRecMessageTextInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: 接收消息展示
	// Parameter: QString strMsg
	// Parameter: QString strHeadImage
	//************************************
	void OnInsertRecMessageTextInfo(QString strMsg, QString strHeadImage, QString msgID, int score);
	void OnInsertRecVideoInfo(QString strMsg, QString strHeadImage, QString msgID, int score);

	void UpdateMessageStateInfo(QByteArray msgID, int nState, int score);

	// wxd add code - start
	void OnSetChatHeaderImage(QString strHeaderImg);  // 设置聊天窗口的头像
	void HideChatHeaderImage();    // 隐藏聊天窗口的头像
	// wxd add code - end
	void OnRecvFileMessage(MessageInfo messageInfo, QString strHeadImage, QString fileLocalPath);
	void OnRecvImgMessage(MessageInfo messageInfo, QString strHeadImage);
	//added by fanwenxing
	void OnRecVdoMessage(MessageInfo messageInfo, QString strHeadImage);
	//added by wangqingjie
	void OnRecvTaskMessage(MessageInfo messageInfo, QString strHeadImage);  //接收任务消息

	void OnRecvFormMessage(MessageInfo messageInfo, QString strHeaderPath); // 接收到表单消息

	//added by wangqingjie
	void SendDragFile(QString);

	void OnSendScreenShotPic(QString strShotFileName);  //发送截图

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
	// Qualifier: 注册事件
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
	QString formatSendMessageFromImgPathToImgDescription(const QString& strSendMessage);	// 将 用户发送的信息字符串中的 头像的路径替换为[xx]形式
	QString formatMessageFromImgDescriptionToImgPath(const QString& strMessage);			// 将 包含[xx]表情形式的信息字符串 转换为 表情的路径形式的字符串
private slots:
	//************************************
	// Method:    doExpressNormalImagePath
	// FullName:  IMPerChat::doExpressNormalImagePath
	// Access:    private 
	// Returns:   void
	// Qualifier: 选择表情 返回图片路径
	// Parameter: QString strImgPath
	//************************************
	void doExpressNormalImagePath(QString strImgPath);

	//************************************
	// Method:    doClickedSetFont
	// FullName:  IMPerChat::doClickedSetFont
	// Access:    private 
	// Returns:   void
	// Qualifier: 选择字体
	//************************************
	void doClickedSetFont();   
	//************************************
	// Method:    doSelectExpress
	// FullName:  IMPerChat::doSelectExpress
	// Access:    private 
	// Returns:   void
	// Qualifier: 选择表情
	//************************************
	void doSelectExpress();    
	//************************************
	// Method:    doSendMessage
	// FullName:  IMPerChat::doSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送消息
	//************************************
	void doSendMessage();        
	//************************************
	// Method:    doClickedShake
	// FullName:  IMPerChat::doClickedShake
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击发送窗口抖动
	//************************************
	void doClickedShake();     
	//************************************
	// Method:    doClickedVoiceChat
	// FullName:  IMPerChat::doClickedVoiceChat
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击发送语音
	//************************************
	void doClickedVoiceChat();  
	//************************************
	// Method:    doClickedPicture
	// FullName:  IMPerChat::doClickedPicture
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击发送图片
	//************************************
	void doClickedPicture();    
	//************************************
	// Method:    doClickedCutPicture
	// FullName:  IMPerChat::doClickedCutPicture
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击截图
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
	// Qualifier: 发送隐藏窗口信号
	//************************************
	void sigHideWidget();

	//************************************
	// Method:    SendWidgetMinSize
	// FullName:  IMPerChat::SendWidgetMinSize
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送窗口最小化
	//************************************
	void sigWidgetMinSize();

	// wxd add code - start
	void sigBtnCloseWClicked();      // 发送左边的按钮点击事件
	// wxd add coed - end
	void sigCancle();

	void sigKeyUpDown(QKeyEvent *);

	void sigOpenChatWindows(QString strToUserID);
	void sigShowNormalWindow();           //窗口还原
	void sigOpenPerLog(QString);
private:
	Ui::IMPerChat ui;
	ExpressWidget *mExpressWidget; //表情窗口
	QRect rectExpressWidget;          //表情窗口的位置

	QLabelHeader*    mChatHeaderImage;   // 聊天窗口的头像，单聊天时显示  wxd add 
	bool	   mbExpress_widget_is_showing;   // 表情窗口的状态  是否正在显示

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
