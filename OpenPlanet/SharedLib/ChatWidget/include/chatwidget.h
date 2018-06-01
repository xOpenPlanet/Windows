#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include "ui_chatwidget.h"

class ChatWidget : public QWidget
{
	Q_OBJECT

public:
	ChatWidget(QWidget *parent = 0);
	~ChatWidget();

	MessageList *getMessageList();
	QStackedWidget *getStackedWidget();

protected:
	bool eventFilter(QObject *obj, QEvent *e);

private slots:
    void slotMinSizeWidget();

private:
	Ui::ChatWidget ui;
};

#endif // CHATWIDGET_H
