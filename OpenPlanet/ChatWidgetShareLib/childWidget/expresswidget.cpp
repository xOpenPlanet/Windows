#include "expresswidget.h"
#include "ui_expresswidget.h"
#include <QVBoxLayout>
#include <QDebug>

ExpressWidget::ExpressWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpressWidget),
	m_row(7), 
	m_column(12)
{
    ui->setupUi(this);

    m_smallEmotionWidget = NULL;
    m_normalEmotionWidget = NULL;
    InsertExControl();
    InitExpressWindow();
    InitExpressEmotion();
    this->setMouseTracking(true);
    this->hide();
    installEventFilter(this);
    connect(m_normalEmotionWidget,SIGNAL(cellClicked(int,int)),this,SLOT(slotGetNormalRowColumn(int,int)));
}

ExpressWidget::~ExpressWidget()
{
    if(m_smallEmotionWidget != NULL)
        delete m_smallEmotionWidget;
    m_smallEmotionWidget = NULL;

    if(m_normalEmotionWidget != NULL)
        delete m_normalEmotionWidget ;
    m_normalEmotionWidget = NULL;

    mMapExControl.clear();
    delete ui;
}

void ExpressWidget::InitExpressWindow()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
	this->setStyleSheet("background-color: white;");
}

void ExpressWidget::InitExpressEmotion()
{
    // ��ʼ��С�����;
    m_smallEmotionWidget = new MyEmotionWidget;
    m_smallEmotionWidget->setRowAndColumn(4, 4);
    m_smallEmotionWidget->setEmotionSize(QSize(32, 32));
    m_smallEmotionWidget->setEmotionMovieSize(QSize(24, 24));
    m_smallEmotionWidget->setMaxRow(4);
    m_smallEmotionWidget->initTableWidget();
    QString path = ":expression\\%1.gif";
    for (int i = 0; i < 10; i++)
    {
        m_smallEmotionWidget->addEmotionItem(path.arg(i + 1), "");
    }

    // ��ʼ�����������;
    m_normalEmotionWidget = new MyEmotionWidget;
    m_normalEmotionWidget->setRowAndColumn(m_row, m_column);
    m_normalEmotionWidget->setEmotionSize(QSize(32, 32));
    m_normalEmotionWidget->setEmotionMovieSize(QSize(24, 24));
    m_normalEmotionWidget->setMaxRow(6);
    m_normalEmotionWidget->initTableWidget();
    QMap<QString,QString>::iterator it;
    for(it = mMapExControl.begin(); it != mMapExControl.end(); ++it)
    {
        m_normalEmotionWidget->addEmotionItem(QString("./html")+it.key(), it.value());
    }
    QVBoxLayout* vLayout = new QVBoxLayout;
	vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->addWidget(m_smallEmotionWidget);
    vLayout->addWidget(m_normalEmotionWidget);
    this->setLayout(vLayout);
}

void ExpressWidget::InsertExControl()
{
	mMapExControl.insert("/expression/1.gif", "[΢Ц]");
	mMapExControl.insert("/expression/2.gif", "[Ʋ��]");
	mMapExControl.insert("/expression/3.gif", "[ɫ]");
	mMapExControl.insert("/expression/4.gif", "[����]");
	mMapExControl.insert("/expression/5.gif", "[����]");
	mMapExControl.insert("/expression/6.gif", "[����]");
	mMapExControl.insert("/expression/7.gif", "[����]");
	mMapExControl.insert("/expression/8.gif", "[˯]");
	mMapExControl.insert("/expression/9.gif", "[���]");
	mMapExControl.insert("/expression/10.gif", "[����]");
	mMapExControl.insert("/expression/11.gif", "[��ŭ]");
	mMapExControl.insert("/expression/12.gif", "[��Ƥ]");
	mMapExControl.insert("/expression/13.gif", "[����]");
	mMapExControl.insert("/expression/14.gif", "[����]");
	mMapExControl.insert("/expression/15.gif", "[�ѹ�]");
	mMapExControl.insert("/expression/16.gif", "[��]");
	mMapExControl.insert("/expression/17.gif", "[�亹]");
	mMapExControl.insert("/expression/18.gif", "[ץ��]");
	mMapExControl.insert("/expression/19.gif", "[��]");
	mMapExControl.insert("/expression/20.gif", "[͵Ц]");
	mMapExControl.insert("/expression/21.gif", "[����]");
	mMapExControl.insert("/expression/22.gif", "[�ɰ�]");
	mMapExControl.insert("/expression/23.gif", "[����]");
	mMapExControl.insert("/expression/24.gif", "[����]");
	mMapExControl.insert("/expression/25.gif", "[��]");
	mMapExControl.insert("/expression/26.gif", "[����]");
	mMapExControl.insert("/expression/27.gif", "[����]");
	mMapExControl.insert("/expression/28.gif", "[��Ц]");
	mMapExControl.insert("/expression/29.gif", "[���]");
	mMapExControl.insert("/expression/30.gif", "[�ܶ�]");
	mMapExControl.insert("/expression/31.gif", "[����]");
	mMapExControl.insert("/expression/32.gif", "[��]");
	mMapExControl.insert("/expression/33.gif", "[��]");
	mMapExControl.insert("/expression/34.gif", "[��ͷ]");
	mMapExControl.insert("/expression/35.gif", "[˥]");
	mMapExControl.insert("/expression/36.gif", "[����]");
	mMapExControl.insert("/expression/37.gif", "[�ô�]");
	mMapExControl.insert("/expression/38.gif", "[�ټ�]");
	mMapExControl.insert("/expression/39.gif", "[�ٱ�]");
	mMapExControl.insert("/expression/40.gif", "[����]");
	mMapExControl.insert("/expression/41.gif", "[�ܴ���]");
	mMapExControl.insert("/expression/42.gif", "[��Ц]");
	mMapExControl.insert("/expression/43.gif", "[��ߺ�]");
	mMapExControl.insert("/expression/44.gif", "[�Һߺ�]");
	mMapExControl.insert("/expression/45.gif", "[��Ƿ]");
	mMapExControl.insert("/expression/46.gif", "[����]");
	mMapExControl.insert("/expression/47.gif", "[ί��]");
	mMapExControl.insert("/expression/48.gif", "[�����]");
	mMapExControl.insert("/expression/49.gif", "[����]");
	mMapExControl.insert("/expression/50.gif", "[����]");
	mMapExControl.insert("/expression/51.gif", "[��]");
	mMapExControl.insert("/expression/52.gif", "[����]");
	mMapExControl.insert("/expression/53.gif", "[�˵�]");
	mMapExControl.insert("/expression/54.gif", "[����]");
	mMapExControl.insert("/expression/55.gif", "[ơ��]");
	mMapExControl.insert("/expression/56.gif", "[ƹ����]");
	mMapExControl.insert("/expression/57.gif", "[����]");
	mMapExControl.insert("/expression/58.gif", "[��]");
	mMapExControl.insert("/expression/59.gif", "[õ��]");
	mMapExControl.insert("/expression/60.gif", "[��л]");
	mMapExControl.insert("/expression/61.gif", "[ʾ��]");
	mMapExControl.insert("/expression/62.gif", "[����]");
	mMapExControl.insert("/expression/63.gif", "[����]");
	mMapExControl.insert("/expression/64.gif", "[����]");
	mMapExControl.insert("/expression/65.gif", "[����]");
	mMapExControl.insert("/expression/66.gif", "[ը��]");
	mMapExControl.insert("/expression/67.gif", "[��]");
	mMapExControl.insert("/expression/68.gif", "[Ʈ��]");
	mMapExControl.insert("/expression/69.gif", "[���]");
	mMapExControl.insert("/expression/70.gif", "[����]");
	mMapExControl.insert("/expression/71.gif", "[̫��]");
	mMapExControl.insert("/expression/72.gif", "[����]");
	mMapExControl.insert("/expression/73.gif", "[ӵ��]");
	mMapExControl.insert("/expression/74.gif", "[ǿ]");
	mMapExControl.insert("/expression/75.gif", "[��]");
	mMapExControl.insert("/expression/76.gif", "[����]");
	mMapExControl.insert("/expression/77.gif", "[��ȭ]");
	mMapExControl.insert("/expression/78.gif", "[����]");
	mMapExControl.insert("/expression/79.gif", "[ȭͷ]");
	mMapExControl.insert("/expression/80.gif", "[�]");
	mMapExControl.insert("/expression/81.gif", "[����]");
	mMapExControl.insert("/expression/82.gif", "[NO]");
	mMapExControl.insert("/expression/83.gif", "[OK]");
	mMapExControl.insert("/expression/ee_6.png", "[����]");
	mMapExControl.insert("/expression/ee_32.png", "[����]");
	mMapExControl.insert("/expression/ee_41.png", "[����]");
	mMapExControl.insert("/expression/ee_80.png", "[ʤ��]");
}

void ExpressWidget::showSmallEmotion(QPoint point)
{
    m_normalEmotionWidget->setVisible(false);
    this->setFixedSize(QSize(m_smallEmotionWidget->width(), m_smallEmotionWidget->height()));
	move(point);
    show();
}

void ExpressWidget::showNormalEmotion(QPoint point)
{
    m_smallEmotionWidget->setVisible(false);
    this->setFixedSize(QSize(m_normalEmotionWidget->width(), m_normalEmotionWidget->height()));
    //move(point);  wxd note
    //show();
}

bool ExpressWidget::eventFilter(QObject *obj, QEvent *e)
{
    if(QEvent::WindowDeactivate == e->type())//����ͣ��
    {
         //hide();//���߹رմ���
    }
    return QWidget::eventFilter(obj , e);
}

void ExpressWidget::slotGetNormalRowColumn(int row, int column)
{
    int nTemp = (column+1) + row*m_column;
    QString strPath = GetExControlImgPath(nTemp-1);
	emit sigExpressImagePath(strPath);
}

//��ȡ����·��
QString ExpressWidget::GetExControlImgPath(int nIndex)
{
    QMap<QString,QString>::iterator it = mMapExControl.begin();
    return (it+nIndex).key();    // ����gif��ַ
    //return (it+nIndex).value();  // ���� [] gif�����ַ���
}

// ���ݱ���·�� ���ر���������  [xx]
QString ExpressWidget::GetDescriptionByImagePath(QString strImgPath)
{
	if (strImgPath.isEmpty())
		return ""; 
	QMap<QString,QString>::iterator imgs_it = mMapExControl.find(strImgPath); 
	if (imgs_it != mMapExControl.end())
	{
		return imgs_it.value(); 
	}
	return ""; 
}

// ���ݱ��������ַ��ر����·��
QString ExpressWidget::GetImagePathByDescription(QString strImgDescription)
{
	if (strImgDescription.isEmpty())
		return ""; 
	QMap<QString, QString>::iterator imgs_it = mMapExControl.begin();
	while (imgs_it != mMapExControl.end())
	{
		if (imgs_it.value() == strImgDescription)
			return imgs_it.key(); 
		++imgs_it; 
	}
	return ""; 
}

