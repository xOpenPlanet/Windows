#ifndef IMMAINWIDGET_H
#define IMMAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTimer>
#include "imtranstype.h"
#include "shadow.h"
#include "ui_immainwidget.h"
#include "readconfig.h"
#include "aboutwidget.h"
#include "userprofile/menuwidget.h"

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#endif  // GET_X_LPARAM
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))
#endif  // GET_Y_LPARAM

class IMMainWidget : public QWidget
{
	Q_OBJECT

public:
	IMMainWidget(QWidget *parent = 0);
	~IMMainWidget();

	//************************************
	// Method:    setNikeName
	// FullName:  IMMainWidget::setNikeName
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置用户名
	// Parameter: QString nickName
	//************************************
	void setNikeName(QString nickName);

	//************************************
	// Method:    setNikeName
	// FullName:  IMMainWidget::setNikeName
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置用户头像
	// Parameter: QString nickName
	//************************************
	void setHeaderImage(QPixmap headerImage);

	//************************************
	// Method:    addWidget
	// FullName:  IMMainWidget::addWidget
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: QWidget *
	//************************************
	void addWidget(QWidget *);

	//************************************
	// Method:    setCurrentWidget
	// FullName:  IMMainWidget::setCurrentWidget
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: int
	//************************************
	void setCurrentWidget(int);

	//************************************
	// Method:    setAppVersion
	// FullName:  IMMainWidget::setAppVersion
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置应用版本号
	// Parameter: QString version
	//************************************
	void setAppVersion(QString version);

	//************************************
	// Method:    setAppName
	// FullName:  IMMainWidget::setAppName
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置应用中文程序名
	// Parameter: QString name
	//************************************
	void setAppName(QString name);

	void StartMessageFlash(int type, QString imagePath);  //开始闪动
	void StopMessageFlash();   //停止闪动

protected:
	void paintEvent(QPaintEvent * event);
	void moveEvent(QMoveEvent *event);
	void resizeEvent(QResizeEvent* event);
	void changeEvent(QEvent * event);
	void closeEvent(QCloseEvent * event);
	bool eventFilter(QObject *obj, QEvent *e);
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);

public slots:
    //************************************
    // Method:    show
    // FullName:  IMMainWidget::show
    // Access:    public 
    // Returns:   void
    // Qualifier:
    //************************************
    void show();
    //************************************
    // Method:    slotExit
    // FullName:  IMMainWidget::slotExit
    // Access:    private 
    // Returns:   void
    // Qualifier:
    //************************************
    void slotExit();
	//************************************
	// Method:    slotFullScreen
	// FullName:  IMMainWidget::slotFullScreen
	// Access:    private 
	// Returns:   void
	// Qualifier:
	//************************************
	void slotFullScreen();
	//************************************
	// Method:    slotCheckWidget
	// FullName:  IMMainWidget::slotCheckWidget
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: int
	// Parameter: bool 
	//************************************
	void slotCheckWidget(int, bool);

	//************************************
	// Method:    slotSysTrayIconClicked
	// FullName:  IMMainWidget::slotSysTrayIconClicked
	// Access:    private 
	// Returns:   void
	// Qualifier: 托盘图标响应
	// Parameter: QSystemTrayIcon::ActivationReason reason
	//************************************
	void slotSysTrayIconClicked(QSystemTrayIcon::ActivationReason reason);

	//************************************
	// Method:    setMainWidgetStatusLabel
	// FullName:  IMMainWidget::setMainWidgetStatusLabel
	// Access:    private 
	// Returns:   void
	// Qualifier: 设置与服务器连接状态
	// Parameter: QString msg
	//************************************
	void slotSetMainWidgetStatusLabel(QString msg);

	void slotDealTrayIconFlash(QString buddyID);  //根据消息状态处理闪动
	void slotMessageRevFlashTime();  //执行闪动操作
	void slotShowAllClicked();     //点击闪动的托盘图标时，显示所有的消息窗。

	//计数的槽。
	void slotCountMessage(int num);

private:
	//************************************
	// Method:    registerHandle
	// FullName:  IMMainWidget::registerHandle
	// Access:    private 
	// Returns:   void
	// Qualifier:
	//************************************
	void registerHandle();

	void CreateTrayMenu();

	void CreateTrayIcon(QIcon icon);   //创建托盘
	
signals:
	void sigExit();        //退出的信号。
	void sigUserProfile();  //显示个人信息页面的信号

	void sigMenuItem(QString);

	void sigDormancyState(bool);   //是否休眠信号

	void sigTrayOpenChat(int type, QVariant buddyID);
	
private:
	Ui::IMMainWidget ui;
	Shadow *shadow;  //窗口阴影。
	QPoint mouse;  //用于窗口移动的暂存变量
	QAction *ActionCheckUpdate; //检查更新
	QAction *ActionExit;        //退出
	QMenu *mTrayMenu;        //系统托盘菜单
	QSystemTrayIcon *mSysTrayIcon;
	QButtonGroup *buttonGroup;  //单选按钮组。
	AboutWidget *aboutWidget;  //关于窗口.
	MenuWidget *menuWidget;

	QString mAppVersion;

	QString mMessageRevHeaderImg;
	int mMessageRevType;
	QTimer *mMessageRevFlashTime;  //来消息闪动
	int mMessageRevFlashNum;
	bool mFlashingFlag;
};

#endif // IMMAINWIDGET_H
