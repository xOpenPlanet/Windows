#include "recoverywidget.h"

RecoveryWidget::RecoveryWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);    // �����Ӱʱʹ��

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
			//ֻҪ��һ�����Ǵʲ��Ϸ���ֱ�ӱ����������
			if (word.isEmpty() || word.contains(" "))
			{
				IMessageBox::tip(this, QStringLiteral("ע��"), QStringLiteral("���Ǵ����벻�Ϸ���"));
				return;
			}

			if (arg.isEmpty())  //argΪ�գ�˵�����׸����Ǵʣ����ֱ�Ӹ�ֵ�����ӿո�
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
			IMessageBox::tip(this, QStringLiteral("ע��"), QStringLiteral("˽Կ����Ϊ�գ�"));
		else
		    emit sigPrivateKey(key);
	}
}

//����¼��Ĵ���
void RecoveryWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //�����ƶ���ԭʼλ�á�
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
	//����ͨ������ֵ��������λ�Ƶľ��롣
	int x = event->pos().x() - mouse.x();
	int y = event->pos().y() - mouse.y();
	//�ƶ������塣
	this->move(this->x() + x, this->y() + y);
	return QWidget::mouseMoveEvent(event);
}

