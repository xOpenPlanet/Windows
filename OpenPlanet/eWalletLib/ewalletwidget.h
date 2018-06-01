#pragma once

#include <QWidget>
#include <QMovie>
#include <QDebug>
#include "ui_ewalletwidget.h"
#include "starflashwidget.h"
#include "changeintoWidget/changeintowidget.h"
#include "transferWidget/transferwidget.h"
#include "invitecodeWidget/invitecodewidget.h"
#include "safeWidget/safewidget.h"

enum STATE
{
	FRONT, BACK, BACKTOFRONT, FRONTOBACK
};

class EWalletWidget : public QWidget
{
	Q_OBJECT

public:
	EWalletWidget(QWidget *parent = Q_NULLPTR);
	~EWalletWidget();

	StarFlashWidget *getStarWidget();
	ChangeIntoWidget *getIntoWidget();
	TransferWidget *getTransWidget();
	InviteCodeWidget *getInviteWidget();
	SafeWidget *getSafeWidget();

	void setEnergySum(QString);
	void setIntegral(QString);

protected:
	bool eventFilter(QObject *obj, QEvent *event);

private slots:
	void slotGifToBack();
	void slotGifToFront();

private:
	void initGif();

private:
	Ui::EWalletWidget ui;

	int gifState;

	ChangeIntoWidget *intoWidget;
	TransferWidget *transferWidget;
	InviteCodeWidget *inviteCodeWidget;

	SafeWidget *safeWidget;
};
