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

	//Qualifier: ����ͷ��
	void setHeaderImage(QString strHeaderPath);

	//Qualifier: �����˻�
	void setNikeName(QString strNikeName);
private:
	// Qualifier: ��ʼ����ʽ��
	void OnInitStyleSheet();

public slots:
	//��½��ť���
	void slotClickLogin();

signals:
	void sigTest();

private:
	Ui::ScanLoginWidget ui;
};

#endif // SCANLOGINWIDGET_H
