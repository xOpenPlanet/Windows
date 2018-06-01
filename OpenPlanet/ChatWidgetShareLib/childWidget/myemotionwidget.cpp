#include "myemotionwidget.h"
#include <QLabel>
#include <QMovie>
#include <QDebug>
#include <QFile>
#include <QHeaderView>
#include "myemotionitemwidget.h"

MyEmotionWidget::MyEmotionWidget(QWidget *parent)
	: QTableWidget(parent)
    , m_preRow(0)
    , m_preColumn(0)
    , m_tableRow(0)
    , m_tableColumn(0)
	, m_maxRow(6)
	, m_emotionSize(QSize(0 , 0))
	, m_emotionMovieSize(QSize(0 , 0))
{
    loadStyleSheet();
	// ����Ⱥ��Ա�б�Ĵ�ֱ����������ʽ
	QFile scroolbar_style_qss(":/ScrollBar/Resources/QSS/scrollbarStyle.qss");
	scroolbar_style_qss.open(QFile::ReadOnly);
	this->verticalScrollBar()->setStyleSheet(scroolbar_style_qss.readAll());
}

MyEmotionWidget::~MyEmotionWidget()
{

}

void MyEmotionWidget::loadStyleSheet()
{
	/*
    QFile file(":/Resources/QSS/myemotion.css");
    file.open(QFile::ReadOnly);
    QString strSheet = file.readAll();
    QString styleSheet = this->styleSheet();
    styleSheet += strSheet;
    this->setStyleSheet(styleSheet);
	*/
}

void MyEmotionWidget::initTableWidget()
{
	this->setFocusPolicy(Qt::NoFocus);
	this->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->setRowCount(m_tableRow);
	this->setColumnCount(m_tableColumn);

	this->horizontalHeader()->setVisible(false);
	this->horizontalHeader()->setDefaultSectionSize(m_emotionSize.width());

	this->verticalHeader()->setVisible(false);
	this->verticalHeader()->setDefaultSectionSize(m_emotionSize.height());
	
	if (m_tableRow > m_maxRow)
	{
		this->setFixedHeight(m_emotionSize.height()*m_maxRow + 2);
		this->setFixedWidth(m_emotionSize.width()*m_tableColumn + 20);
	}
	else
	{
		this->setFixedHeight(m_emotionSize.height()*m_tableRow + 2);
		this->setFixedWidth(m_emotionSize.width()*m_tableColumn + 2);
	}
}

void MyEmotionWidget::setRowAndColumn(int row, int column)
{
	m_tableRow = row;
	m_tableColumn = column;
}

void MyEmotionWidget::setEmotionSize(QSize emotionSize)
{
	m_emotionSize = emotionSize;
}

void MyEmotionWidget::setEmotionMovieSize(QSize emotionMovieSize)
{
	m_emotionMovieSize = emotionMovieSize;
}

void MyEmotionWidget::setMaxRow(int maxRow)
{
	m_maxRow = maxRow;
}

void MyEmotionWidget::addEmotionItem(QString fileName , QString toolTip)
{
	int row = m_emotionList.size() / this->columnCount();
	int column = m_emotionList.size() % this->columnCount();

	QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;
	tableWidgetItem->setToolTip(toolTip);
	this->setItem(row, column, tableWidgetItem);

	MyEmotionItemWidget* emotionIcon = new MyEmotionItemWidget(fileName , m_emotionMovieSize);

	this->setCellWidget(row, column, emotionIcon);
	m_emotionList.push_back(fileName);
}

void MyEmotionWidget::showDynamicEmotion(QPoint cursorPos)
{
	QPoint point = cursorPos - this->pos(); 
	QTableWidgetItem* tableWidgetItem = this->itemAt(point);
	if (tableWidgetItem != NULL)
	{
		//�����ȡ����item��Ϊ��˵���˿�������ڵ�������tableWidget��ĳ��item�У�
		//�����������һ�������ƶ���һ������δ����item�ĵ�Ԫ������Ƴ�tableWidget����
		//��ͬһ��item���ƶ������κβ���;
		if (m_preRow != tableWidgetItem->row() || m_preColumn != tableWidgetItem->column())
		{
			QLabel* preEmotion = (QLabel*)this->cellWidget(m_preRow, m_preColumn);
			if (preEmotion != NULL)
			{
				QMovie* preMoive = preEmotion->movie();
				preMoive->jumpToFrame(0);
				preMoive->stop();
				preEmotion->setContentsMargins(3, 3, 3, 3);
			}

			QLabel* curEmotion = (QLabel*)this->cellWidget(tableWidgetItem->row(), tableWidgetItem->column());
			if (curEmotion != NULL)
			{
				curEmotion->setContentsMargins(4, 2, 2, 4);
				QMovie* curMoive = curEmotion->movie();
				curMoive->start();
				m_preRow = tableWidgetItem->row();
				m_preColumn = tableWidgetItem->column();
			}
		}
	}
	else
	{
		//�����ȡ����itemΪ��˵���˿�������ڵ�������tableWidget��items�У�
		//����������մ�һ����̬�����ƶ���һ������δ����item�ĵ�Ԫ������Ƴ�tableWidget����
		//�������һ�������λ�û�ȡ��item��ֹͣ���ڶ�̬��ʾ�ı��飬����m_preRow��m_preColumn��Ϊ-1��
		//�����´��ٴν��뵽�˷�֧�����ظ�����;
		QTableWidgetItem* tableWidgetItem = this->item(m_preRow, m_preColumn);
		if (tableWidgetItem != NULL)
		{
			QLabel* preEmotion = (QLabel*)this->cellWidget(m_preRow, m_preColumn);
			if (preEmotion != NULL)
			{
				preEmotion->setContentsMargins(3, 3, 3, 3);
				QMovie* preMoive = preEmotion->movie();
				preMoive->jumpToFrame(0);
				preMoive->stop();
				m_preRow = -1;
				m_preColumn = -1;
			}
		}
	}
}
