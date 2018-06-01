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
	// 设置群成员列表的垂直滚动条的样式
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
		//如果获取到的item不为空说明此刻鼠标所在的区域在tableWidget的某个item中，
		//并且如果鼠标从一个表情移动到一个其他未设置item的单元格或者移出tableWidget区域
		//在同一个item中移动则不做任何操作;
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
		//如果获取到的item为空说明此刻鼠标所在的区域不在tableWidget的items中，
		//并且如果鼠标刚从一个动态表情移动到一个其他未设置item的单元格或者移出tableWidget区域，
		//则根据上一个表情的位置获取到item并停止正在动态显示的表情，并将m_preRow、m_preColumn置为-1，
		//以免下次再次进入到此分支进行重复操作;
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
