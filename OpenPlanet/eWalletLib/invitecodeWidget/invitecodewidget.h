#pragma once

#include <QWidget>
#include <qclipboard.h>
#include <QTimer>
#include "qrencodesharelib.h"
#include "ui_invitecodewidget.h"

class InviteCodeWidget : public QWidget
{
	Q_OBJECT

public:
	InviteCodeWidget(QWidget *parent = Q_NULLPTR);
	~InviteCodeWidget();

	void setInviteCode(QString);
	void setImage();

	private slots:
	void slotCopyCode();

private:
	Ui::InviteCodeWidget ui;

	QLabel *copyLabel;
};
