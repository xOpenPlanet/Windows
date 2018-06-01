#ifndef MESSAGELOG_H
#define MESSAGELOG_H

#include <qdesktopservices.h>
#include <QWidget>
#include <QCalendarWidget>
#include <QMessageBox>
#include <QEvent>
#include <QKeyEvent>
#include "qmath.h"
#include "shadow.h"
#include "childWidget/expresswidget.h"
#include "ui_messagelog.h"
#include "childWidget/zoomimg.h"
#include "qjsonobject.h"
#include "imbuddy.h"

class MessageLog : public QWidget
{
	Q_OBJECT

public:
	MessageLog(QWidget *parent = 0);
	~MessageLog();

	void loadPerLogByID(QString id);
	void loadGroupLogByID(QString id);

public slots:
    void show();

	void slotZoomImg(QString strfileName);
	void slotVideoPlay(QString mediaPath);
	void slotOpenFile(QString fileName);
	void slotOpenDir(QString fileDir);

protected:
	void changeEvent(QEvent * event);
	void moveEvent(QMoveEvent *event);
	void resizeEvent(QResizeEvent* event);
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

	bool eventFilter(QObject *obj, QEvent *e);//事件过滤器
private:
	Ui::MessageLog ui;

	Shadow *shadow;
	QPoint mouse;

	int pageAmount;
	int currentPage;

	ExpressWidget *mExpressWidget; //表情窗口
	QCalendarWidget *dateSelector;
	QString keyString;

	QString formatExpressToImgPath(const QString&);
	void showCurrentPageLog(bool isPer);

private slots:
    void maxOrRstrWindow();  //最大化/还原操作。

	void doClickContacts(bool);
	void doClickGroup(bool);

	void doClickPerItem(QListWidgetItem *);
	void doClickGroupItem(QListWidgetItem *);

	void toFirstPage();
	void toEndPage();
	void toLastPage();
	void toNextPage();

	void doShowDateSelector();
	void toDateLogPage(QDate);

	void doSearch();
	void doClearSearch();
};

#endif // MESSAGELOG_H
