#ifndef SCANNETWORKSETWIDGET_H
#define SCANNETWORKSETWIDGET_H

#include <QWidget>
#include "ui_scannetworksetwidget.h"

class ScanNetWorkSetWidget : public QWidget
{
	Q_OBJECT

public:
	ScanNetWorkSetWidget(QWidget *parent = 0);
	~ScanNetWorkSetWidget();

	// Qualifier: 初始化样式表
	void OnInitStyleSheet();

	void EnableEdit(bool bStatus);
	public slots:
	void slotPressRadioButtonON(bool bCheck);
	void slotPressRadioButtonOFF(bool bCheck);
	void slotConfirm();
private:
	Ui::ScanNetWorkSetWidget ui;
};

#endif // SCANNETWORKSETWIDGET_H
