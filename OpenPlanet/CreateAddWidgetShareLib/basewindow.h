#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include "mytitlebar.h"

class BaseWindow : public QWidget
{
	Q_OBJECT

public:
	BaseWindow(QWidget *parent = 0);
	~BaseWindow();
	void loadStyleSheet(const QString &sheetName);

protected:
	void paintEvent(QPaintEvent *event);

signals:
	void sigWindowsMax();

private:
	void initTitleBar();
	private slots:
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;
};

#endif // BASEWINDOW_H
