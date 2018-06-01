#include "chatwidget.h"


ChatWidget::ChatWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.separateLine->installEventFilter(this);

	QFile file(":/qssWidget/Resources/qssWidget/chatwidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

ChatWidget::~ChatWidget()
{

}

MessageList * ChatWidget::getMessageList()
{
	return ui.messageWidget;
}

QStackedWidget * ChatWidget::getStackedWidget()
{
	return ui.chatStackedWidget;
}


void ChatWidget::slotMinSizeWidget()
{
	if (this->windowState() != Qt::WindowMinimized)
	{
		setWindowState(Qt::WindowMinimized);
	}
}

bool ChatWidget::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == ui.separateLine)
	{
		if (e->type() == QEvent::MouseMove)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			int w = ui.messageWidget->width() + event->x();
			if (w > 350)
				w = 350;
			if (w < 150)
				w = 150;
			ui.messageWidget->setFixedWidth(w);
		}
	}

	return QWidget::eventFilter(obj, e);
}
