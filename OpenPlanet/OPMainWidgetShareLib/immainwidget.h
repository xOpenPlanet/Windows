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
	// Qualifier: �����û���
	// Parameter: QString nickName
	//************************************
	void setNikeName(QString nickName);

	//************************************
	// Method:    setNikeName
	// FullName:  IMMainWidget::setNikeName
	// Access:    public 
	// Returns:   void
	// Qualifier: �����û�ͷ��
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
	// Qualifier: ����Ӧ�ð汾��
	// Parameter: QString version
	//************************************
	void setAppVersion(QString version);

	//************************************
	// Method:    setAppName
	// FullName:  IMMainWidget::setAppName
	// Access:    public 
	// Returns:   void
	// Qualifier: ����Ӧ�����ĳ�����
	// Parameter: QString name
	//************************************
	void setAppName(QString name);

	void StartMessageFlash(int type, QString imagePath);  //��ʼ����
	void StopMessageFlash();   //ֹͣ����

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
	// Qualifier: ����ͼ����Ӧ
	// Parameter: QSystemTrayIcon::ActivationReason reason
	//************************************
	void slotSysTrayIconClicked(QSystemTrayIcon::ActivationReason reason);

	//************************************
	// Method:    setMainWidgetStatusLabel
	// FullName:  IMMainWidget::setMainWidgetStatusLabel
	// Access:    private 
	// Returns:   void
	// Qualifier: ���������������״̬
	// Parameter: QString msg
	//************************************
	void slotSetMainWidgetStatusLabel(QString msg);

	void slotDealTrayIconFlash(QString buddyID);  //������Ϣ״̬��������
	void slotMessageRevFlashTime();  //ִ����������
	void slotShowAllClicked();     //�������������ͼ��ʱ����ʾ���е���Ϣ����

	//�����Ĳۡ�
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

	void CreateTrayIcon(QIcon icon);   //��������
	
signals:
	void sigExit();        //�˳����źš�
	void sigUserProfile();  //��ʾ������Ϣҳ����ź�

	void sigMenuItem(QString);

	void sigDormancyState(bool);   //�Ƿ������ź�

	void sigTrayOpenChat(int type, QVariant buddyID);
	
private:
	Ui::IMMainWidget ui;
	Shadow *shadow;  //������Ӱ��
	QPoint mouse;  //���ڴ����ƶ����ݴ����
	QAction *ActionCheckUpdate; //������
	QAction *ActionExit;        //�˳�
	QMenu *mTrayMenu;        //ϵͳ���̲˵�
	QSystemTrayIcon *mSysTrayIcon;
	QButtonGroup *buttonGroup;  //��ѡ��ť�顣
	AboutWidget *aboutWidget;  //���ڴ���.
	MenuWidget *menuWidget;

	QString mAppVersion;

	QString mMessageRevHeaderImg;
	int mMessageRevType;
	QTimer *mMessageRevFlashTime;  //����Ϣ����
	int mMessageRevFlashNum;
	bool mFlashingFlag;
};

#endif // IMMAINWIDGET_H
