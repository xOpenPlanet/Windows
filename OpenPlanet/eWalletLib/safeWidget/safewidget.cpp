#include "safewidget.h"

SafeWidget::SafeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.passwordPage->hide();
	ui.backupPage->hide();

	ui.backupItem->installEventFilter(this);

	connect(ui.enterBtn, SIGNAL(clicked(bool)), this, SLOT(slotEnterPassWord()));
	connect(ui.copyBtn, SIGNAL(clicked(bool)), this, SLOT(slotCopyPrivateKey()));
}

SafeWidget::~SafeWidget()
{
}

void SafeWidget::setPassWord(QString passWord)
{
	this->passWord = passWord;
}

void SafeWidget::setPrivateKey(QString key)
{
	this->privateKey = key;
}

bool SafeWidget::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == ui.backupItem && event->type() == QEvent::MouseButtonPress)
	{
		ui.backupPage->hide();
		ui.passwordPage->show();
	}

	return QWidget::eventFilter(obj, event);
}

void SafeWidget::slotEnterPassWord()
{
	if (!passWord.isEmpty())
	{
		QString text = ui.passwordEdit->text();
		if (text.isEmpty())
			ui.tipLabel->setText(QStringLiteral("密码为空"));
		else
		{
			QByteArray array = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Sha1);
			QString string = array.toHex();

			if (string.toLower() != passWord.toLower())
				ui.tipLabel->setText(QStringLiteral("密码不正确"));
			else
			{
				ui.passwordEdit->clear();
				ui.tipLabel->clear();
				ui.passwordPage->hide();
				ui.plainTextEdit->setPlainText(privateKey);
				ui.backupPage->show();
			}
		}
	}
}

void SafeWidget::slotCopyPrivateKey()
{
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setText(ui.plainTextEdit->toPlainText());

	ui.backupPage->hide();
}
