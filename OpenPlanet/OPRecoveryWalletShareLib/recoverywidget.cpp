#include "recoverywidget.h"

RecoveryWidget::RecoveryWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);    // 添加阴影时使用

	connect(ui.closeBtn, SIGNAL(clicked()), this, SIGNAL(sigClose()));
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.wordBtn, SIGNAL(toggled(bool)), this, SLOT(slotSwitchStackedWidget()));
	connect(ui.privateKeyBtn, SIGNAL(toggled(bool)), this, SLOT(slotSwitchStackedWidget()));
	connect(ui.enterBtn, SIGNAL(clicked()), this, SLOT(slotClickedBtn()));
}

RecoveryWidget::~RecoveryWidget()
{
}

void RecoveryWidget::slotSwitchStackedWidget()
{
	if (ui.wordBtn->isChecked())
		ui.stackedWidget->setCurrentWidget(ui.wordPage);
	if (ui.privateKeyBtn->isChecked())
		ui.stackedWidget->setCurrentWidget(ui.prikeyPage);
}

void RecoveryWidget::slotClickedBtn()
{
	if (ui.wordBtn->isChecked())
	{
		QStringList wordList;
		wordList.append(ui.lineEdit_1->text());
		wordList.append(ui.lineEdit_2->text());
		wordList.append(ui.lineEdit_3->text());
		wordList.append(ui.lineEdit_4->text());
		wordList.append(ui.lineEdit_5->text());
		wordList.append(ui.lineEdit_6->text());
		wordList.append(ui.lineEdit_7->text());
		wordList.append(ui.lineEdit_8->text());
		wordList.append(ui.lineEdit_9->text());
		wordList.append(ui.lineEdit_10->text());
		wordList.append(ui.lineEdit_11->text());
		wordList.append(ui.lineEdit_12->text());

		QString arg;

		for each (QString word in wordList)
		{
			//只要有一个助记词不合法，直接报错结束处理。
			if (word.isEmpty() || word.contains(" "))
			{
				IMessageBox::tip(this, QStringLiteral("注意"), QStringLiteral("助记词输入不合法！"));
				return;
			}

			if (arg.isEmpty())  //arg为空，说明是首个助记词，因此直接赋值，不加空格。
				arg = word;
			else
				arg += " " + word;
		}

		emit sigRecoveryWord(arg);
	}

	if (ui.privateKeyBtn->isChecked())
	{
		QString key = ui.prikeyEdit->toPlainText();
		key.remove(" ");

		if (key.isEmpty())
			IMessageBox::tip(this, QStringLiteral("注意"), QStringLiteral("私钥不能为空！"));
		else
		    emit sigPrivateKey(key);
	}
}

//鼠标事件的处理。
void RecoveryWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //设置移动的原始位置。
	return QWidget::mousePressEvent(event);
}
void RecoveryWidget::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void RecoveryWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (mouse.x() < 0)
		return;
	//首先通过做差值，获得鼠标位移的距离。
	int x = event->pos().x() - mouse.x();
	int y = event->pos().y() - mouse.y();
	//移动本窗体。
	this->move(this->x() + x, this->y() + y);
	return QWidget::mouseMoveEvent(event);
}

