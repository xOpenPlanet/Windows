#include "changeavatarwidget.h"
#include <qdebug.h>

ChangeAvatarWidget::ChangeAvatarWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	setContentsMargins(6, 6, 6, 6);

	changed = false;
	isUploading = false;

	picMask = NULL;
	picMask = new QLabel(this);
	picMask->setAttribute(Qt::WA_TransparentForMouseEvents);
	picMask->setStyleSheet("border-image: url(:/profile/Resources/profile/picMask.png)");
	picMask->move(50, 60);
	picMask->resize(ui.scrollArea->size());

	ui.scrollArea->installEventFilter(this);
	ui.scrollAreaWidgetContents->installEventFilter(this);

	connect(ui.closeBtn, SIGNAL(clicked(bool)), this, SLOT(slotCancel()));
	connect(ui.uploadBtn, SIGNAL(clicked(bool)), this, SLOT(slotUploadImage()));
	connect(ui.confirmBtn, SIGNAL(clicked(bool)), this, SLOT(slotConfirmImage()));
	connect(ui.cancelBtn, SIGNAL(clicked(bool)), this, SLOT(slotCancel()));

	QFile file(":/qssWidget/Resources/qssWidget/changeavatarwidget.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	setStyleSheet(styleSheet);
	file.close();
}

ChangeAvatarWidget::~ChangeAvatarWidget()
{

}

//����¼��Ĵ���3
void ChangeAvatarWidget::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //�����ƶ���ԭʼλ�á�
	return QWidget::mousePressEvent(event);
}
void ChangeAvatarWidget::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void ChangeAvatarWidget::mouseMoveEvent(QMouseEvent *event)
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


//������Ӱ
void ChangeAvatarWidget::paintEvent(QPaintEvent * event)
{
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addRect(10, 10, this->width() - 20, this->height() - 20);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.fillPath(path, QBrush(Qt::white));

	QColor color(0, 0, 0, 50);//, 50);
	for (int i = 0; i < 10; i++)
	{
		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		path.addRect(10 - i, 10 - i, this->width() - (10 - i) * 2, this->height() - (10 - i) * 2);
		color.setAlpha(220 - qSqrt(i) * 67);
		painter.setPen(color);
		painter.drawPath(path);
	}
}


bool ChangeAvatarWidget::eventFilter(QObject *obj, QEvent *e)
{	
	if (obj == ui.scrollArea)
	{
		if (e->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent *event = (QMouseEvent *)e;
			if (event->button() == Qt::LeftButton)
			{
				point = event->pos();
			}
		}
		if (e->type() == QEvent::MouseMove)
		{
			QMouseEvent *event = (QMouseEvent *)e;

			QPoint curPoint = event->pos();

			int vDiffer = (curPoint.y() - point.y()) * 2;
			int hDiffer = (curPoint.x() - point.x()) * 2;

			QScrollBar *vBar = ui.scrollArea->verticalScrollBar();
			QScrollBar *hBar = ui.scrollArea->horizontalScrollBar();
			int vPos = vBar->value() + vDiffer;
			int hPos = hBar->value() + hDiffer;

			if (vPos > vBar->maximum())
				vPos = vBar->maximum();
			if (vPos < 0)
				vPos = 0;
			if (hPos > hBar->maximum())
				hPos = hBar->maximum();
			if (hPos < 0)
				hPos = 0;

			vBar->setValue(vPos);
			hBar->setValue(hPos);

			point = curPoint; //�����µ�λ�á�
			changed = true;   //����Ϊ���¡�
		}

		return true;
	}

	if (obj == ui.scrollAreaWidgetContents && e->type() == QEvent::Wheel)
	{
		QWheelEvent *event = (QWheelEvent *)e;
		if (event->delta() > 0)
		{
			if (++times >= 5)   //���Ŵ���1.5����
				times = 5;
			double large = (10 + times) / (double)10;
			QPixmap pix = originImg.scaledToWidth(originImg.width()*large, Qt::SmoothTransformation);
			ui.headerLabel->setFixedSize(pix.size());
			ui.headerLabel->setPixmap(pix);
		}
		else
		{
			int tmpTimes = times - 1 <= -5 ? -5 : times - 1;  //��С��С��0.5����
			double little = (10 + tmpTimes) / (double)10;
			QPixmap pix = originImg.scaledToWidth(originImg.width()*little, Qt::SmoothTransformation);
			//ֻ�е���С���ͼ�񣬳ߴ���ڵ���չʾ����Ž�����С��
			if (pix.width() >= ui.scrollArea->width() && pix.height() >= ui.scrollArea->height())
			{
				ui.headerLabel->setFixedSize(pix.size());
				ui.headerLabel->setPixmap(pix);

				if (--times < -5)
					times = -5;
			}
		}

		changed = true;
		return true;
	}


	return QWidget::eventFilter(obj, e);
}

void ChangeAvatarWidget::setAvatar(QString headerPath)
{
	QByteArray bytearray = "";
	QFile file(headerPath);
	if (file.open(QIODevice::ReadOnly) && file.size() != 0)
	{
		bytearray = file.readAll();
	}
	file.close();
	QPixmap image;
	if (!image.loadFromData(bytearray) || bytearray == "")
	{
		image.load(":/PerChat/Resources/person/temp.png");
	}

	int xDiffer = image.width() - ui.scrollArea->width();
	int yDiffer = image.height() - ui.scrollArea->height();

	if (xDiffer <= yDiffer && xDiffer < 0)
		image = image.scaledToWidth(ui.scrollArea->width(), Qt::SmoothTransformation);
	if (yDiffer < xDiffer && yDiffer < 0)
		image = image.scaledToHeight(ui.scrollArea->height(), Qt::SmoothTransformation);

	ui.headerLabel->setFixedSize(image.size());
	ui.headerLabel->setPixmap(image);
	ui.headerLabel->setAutoFillBackground(true);
	ui.headerLabel->setScaledContents(true);

	//��¼ԭʼ�ߴ磬��ʼ�����ű�����
	originImg = image;
	times = 0;
}

void ChangeAvatarWidget::slotCancel()
{
	this->hide();

	setAvatar(userInfo.strUserAvatarLocal);
}

void ChangeAvatarWidget::slotUploadImage()
{
	QString filePath = QFileDialog::getOpenFileName(this, "ѡ����Ƭ", ".", "ͼƬ�ļ�(*.jpg *.png *.bmp)");
	if (!filePath.isEmpty())
	{
		setAvatar(filePath);
		changed = true;
	}
}

void ChangeAvatarWidget::slotConfirmImage()
{
	if (!changed)
	{
		this->hide();
		return;
	}
		
	if (isUploading)
	{
		IMessageBox::tip(this, QStringLiteral("�Ե�"), QStringLiteral("ͷ�������ϴ���!"));
		return;
	}

	isUploading = true;

	QPixmap::grabWidget(ui.scrollArea).save("header.png", "PNG");

	emit sigUploadHeaderImage("header.png");
}

void ChangeAvatarWidget::upPicFileFinished(bool success)
{
	if (success)
	{
		//ɾ��ԭͷ������ͷ���滻��
		QFile::remove(userInfo.strUserAvatarLocal);
		QFile::copy("header.png", userInfo.strUserAvatarLocal);
		QFile::remove("header.png");

		//���ر����档
		this->hide();

		changed = false;
		isUploading = false;
	}
	else
	{
		IMessageBox::tip(this, QStringLiteral("��Ǹ"), QStringLiteral("�ϴ�ͷ��ʧ��!"));
		isUploading = false;
	}
}

void ChangeAvatarWidget::setUserInfo(UserInfo info)
{
	this->userInfo = info;
	setAvatar(userInfo.strUserAvatarLocal);
}
