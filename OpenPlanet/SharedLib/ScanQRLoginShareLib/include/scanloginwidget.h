#ifndef SCANLOGINWIDGET_H
#define SCANLOGINWIDGET_H

#include <QWidget>
#include "ui_scanloginwidget.h"

class ScanLoginWidget : public QWidget
{
	Q_OBJECT

public:
	ScanLoginWidget(QWidget *parent = 0);
	~ScanLoginWidget();

	//Qualifier: 设置头像
	void setHeaderImage(QString strHeaderPath);

	//Qualifier: 设置账户
	void setNikeName(QString strNikeName);
private:
	// Qualifier: 初始化样式表
	void OnInitStyleSheet();

public slots:
	//登陆按钮点击
	void slotClickLogin();

signals:
	void sigTest();

private:
	Ui::ScanLoginWidget ui;
};

#endif // SCANLOGINWIDGET_H
