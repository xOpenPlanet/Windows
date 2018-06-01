#ifndef EXPRESSWIDGET_H
#define EXPRESSWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include "myemotionwidget.h"
#include <QMap>
#include <QScrollBar>
#include <QFile>

#ifdef Q_OS_WIN
#pragma execution_character_set("utf-8")
#endif // Q_OS_WIN

/*************表情窗体****************/

namespace Ui {
class ExpressWidget;
}

class ExpressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExpressWidget(QWidget *parent = 0);
    ~ExpressWidget();

    void showNormalEmotion(QPoint point);   //展示鼠标点击

    void showSmallEmotion(QPoint point);    //展示鼠标移动

    QString GetExControlImgPath(int nIndex);   //获取表情路径

	// wxd add code - start 
	QString GetDescriptionByImagePath(QString strImgPath);    // 根据表情路径 返回表情描述字
	QString GetImagePathByDescription(QString strImgDescription);   // 根据表情描述字返回表情的路径
	// wxd add code - end
private:
    void InitExpressWindow();
    void InitExpressEmotion();
    void InsertExControl();
    bool eventFilter(QObject *obj, QEvent *e);//事件过滤器

private slots:
void slotGetNormalRowColumn(int, int);  //获取当前点击的行列
signals:
	void sigExpressImagePath(QString);     //发送当前选择图片的位置
private:
    Ui::ExpressWidget *ui;
    bool m_isNeedHide;
    MyEmotionWidget* m_normalEmotionWidget;  //鼠标点击样式
    MyEmotionWidget* m_smallEmotionWidget;   //鼠标移动样式

    QMap<QString,QString> mMapExControl;     //表情名称对照表

	int     m_row;			// 表情窗口的行数
	int     m_column;       // 表情窗口的列数
};

#endif // EXPRESSWIDGET_H
