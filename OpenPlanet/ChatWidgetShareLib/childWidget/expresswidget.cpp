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
    // 初始化小表情框;
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

    // 初始化正常表情框;
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
	mMapExControl.insert("/expression/1.gif", "[微笑]");
	mMapExControl.insert("/expression/2.gif", "[撇嘴]");
	mMapExControl.insert("/expression/3.gif", "[色]");
	mMapExControl.insert("/expression/4.gif", "[发呆]");
	mMapExControl.insert("/expression/5.gif", "[得意]");
	mMapExControl.insert("/expression/6.gif", "[害羞]");
	mMapExControl.insert("/expression/7.gif", "[闭嘴]");
	mMapExControl.insert("/expression/8.gif", "[睡]");
	mMapExControl.insert("/expression/9.gif", "[大哭]");
	mMapExControl.insert("/expression/10.gif", "[尴尬]");
	mMapExControl.insert("/expression/11.gif", "[发怒]");
	mMapExControl.insert("/expression/12.gif", "[调皮]");
	mMapExControl.insert("/expression/13.gif", "[呲牙]");
	mMapExControl.insert("/expression/14.gif", "[惊讶]");
	mMapExControl.insert("/expression/15.gif", "[难过]");
	mMapExControl.insert("/expression/16.gif", "[酷]");
	mMapExControl.insert("/expression/17.gif", "[冷汗]");
	mMapExControl.insert("/expression/18.gif", "[抓狂]");
	mMapExControl.insert("/expression/19.gif", "[吐]");
	mMapExControl.insert("/expression/20.gif", "[偷笑]");
	mMapExControl.insert("/expression/21.gif", "[白眼]");
	mMapExControl.insert("/expression/22.gif", "[可爱]");
	mMapExControl.insert("/expression/23.gif", "[傲慢]");
	mMapExControl.insert("/expression/24.gif", "[饥饿]");
	mMapExControl.insert("/expression/25.gif", "[困]");
	mMapExControl.insert("/expression/26.gif", "[惊恐]");
	mMapExControl.insert("/expression/27.gif", "[流汗]");
	mMapExControl.insert("/expression/28.gif", "[憨笑]");
	mMapExControl.insert("/expression/29.gif", "[大兵]");
	mMapExControl.insert("/expression/30.gif", "[奋斗]");
	mMapExControl.insert("/expression/31.gif", "[疑问]");
	mMapExControl.insert("/expression/32.gif", "[嘘]");
	mMapExControl.insert("/expression/33.gif", "[晕]");
	mMapExControl.insert("/expression/34.gif", "[猪头]");
	mMapExControl.insert("/expression/35.gif", "[衰]");
	mMapExControl.insert("/expression/36.gif", "[骷髅]");
	mMapExControl.insert("/expression/37.gif", "[敲打]");
	mMapExControl.insert("/expression/38.gif", "[再见]");
	mMapExControl.insert("/expression/39.gif", "[抠鼻]");
	mMapExControl.insert("/expression/40.gif", "[鼓掌]");
	mMapExControl.insert("/expression/41.gif", "[糗大了]");
	mMapExControl.insert("/expression/42.gif", "[坏笑]");
	mMapExControl.insert("/expression/43.gif", "[左哼哼]");
	mMapExControl.insert("/expression/44.gif", "[右哼哼]");
	mMapExControl.insert("/expression/45.gif", "[哈欠]");
	mMapExControl.insert("/expression/46.gif", "[鄙视]");
	mMapExControl.insert("/expression/47.gif", "[委屈]");
	mMapExControl.insert("/expression/48.gif", "[快哭了]");
	mMapExControl.insert("/expression/49.gif", "[阴险]");
	mMapExControl.insert("/expression/50.gif", "[亲亲]");
	mMapExControl.insert("/expression/51.gif", "[吓]");
	mMapExControl.insert("/expression/52.gif", "[可怜]");
	mMapExControl.insert("/expression/53.gif", "[菜刀]");
	mMapExControl.insert("/expression/54.gif", "[西瓜]");
	mMapExControl.insert("/expression/55.gif", "[啤酒]");
	mMapExControl.insert("/expression/56.gif", "[乒乓球]");
	mMapExControl.insert("/expression/57.gif", "[咖啡]");
	mMapExControl.insert("/expression/58.gif", "[饭]");
	mMapExControl.insert("/expression/59.gif", "[玫瑰]");
	mMapExControl.insert("/expression/60.gif", "[凋谢]");
	mMapExControl.insert("/expression/61.gif", "[示爱]");
	mMapExControl.insert("/expression/62.gif", "[爱心]");
	mMapExControl.insert("/expression/63.gif", "[心碎]");
	mMapExControl.insert("/expression/64.gif", "[蛋糕]");
	mMapExControl.insert("/expression/65.gif", "[闪电]");
	mMapExControl.insert("/expression/66.gif", "[炸弹]");
	mMapExControl.insert("/expression/67.gif", "[刀]");
	mMapExControl.insert("/expression/68.gif", "[飘虫]");
	mMapExControl.insert("/expression/69.gif", "[便便]");
	mMapExControl.insert("/expression/70.gif", "[月亮]");
	mMapExControl.insert("/expression/71.gif", "[太阳]");
	mMapExControl.insert("/expression/72.gif", "[礼物]");
	mMapExControl.insert("/expression/73.gif", "[拥抱]");
	mMapExControl.insert("/expression/74.gif", "[强]");
	mMapExControl.insert("/expression/75.gif", "[弱]");
	mMapExControl.insert("/expression/76.gif", "[握手]");
	mMapExControl.insert("/expression/77.gif", "[抱拳]");
	mMapExControl.insert("/expression/78.gif", "[勾引]");
	mMapExControl.insert("/expression/79.gif", "[拳头]");
	mMapExControl.insert("/expression/80.gif", "[差劲]");
	mMapExControl.insert("/expression/81.gif", "[爱你]");
	mMapExControl.insert("/expression/82.gif", "[NO]");
	mMapExControl.insert("/expression/83.gif", "[OK]");
	mMapExControl.insert("/expression/ee_6.png", "[流泪]");
	mMapExControl.insert("/expression/ee_32.png", "[咒骂]");
	mMapExControl.insert("/expression/ee_41.png", "[擦汗]");
	mMapExControl.insert("/expression/ee_80.png", "[胜利]");
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
    if(QEvent::WindowDeactivate == e->type())//窗口停用
    {
         //hide();//或者关闭窗口
    }
    return QWidget::eventFilter(obj , e);
}

void ExpressWidget::slotGetNormalRowColumn(int row, int column)
{
    int nTemp = (column+1) + row*m_column;
    QString strPath = GetExControlImgPath(nTemp-1);
	emit sigExpressImagePath(strPath);
}

//获取表情路径
QString ExpressWidget::GetExControlImgPath(int nIndex)
{
    QMap<QString,QString>::iterator it = mMapExControl.begin();
    return (it+nIndex).key();    // 返回gif地址
    //return (it+nIndex).value();  // 返回 [] gif描述字符串
}

// 根据表情路径 返回表情描述字  [xx]
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

// 根据表情描述字返回表情的路径
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

