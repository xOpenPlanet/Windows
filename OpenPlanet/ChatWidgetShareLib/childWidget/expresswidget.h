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

/*************���鴰��****************/

namespace Ui {
class ExpressWidget;
}

class ExpressWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExpressWidget(QWidget *parent = 0);
    ~ExpressWidget();

    void showNormalEmotion(QPoint point);   //չʾ�����

    void showSmallEmotion(QPoint point);    //չʾ����ƶ�

    QString GetExControlImgPath(int nIndex);   //��ȡ����·��

	// wxd add code - start 
	QString GetDescriptionByImagePath(QString strImgPath);    // ���ݱ���·�� ���ر���������
	QString GetImagePathByDescription(QString strImgDescription);   // ���ݱ��������ַ��ر����·��
	// wxd add code - end
private:
    void InitExpressWindow();
    void InitExpressEmotion();
    void InsertExControl();
    bool eventFilter(QObject *obj, QEvent *e);//�¼�������

private slots:
void slotGetNormalRowColumn(int, int);  //��ȡ��ǰ���������
signals:
	void sigExpressImagePath(QString);     //���͵�ǰѡ��ͼƬ��λ��
private:
    Ui::ExpressWidget *ui;
    bool m_isNeedHide;
    MyEmotionWidget* m_normalEmotionWidget;  //�������ʽ
    MyEmotionWidget* m_smallEmotionWidget;   //����ƶ���ʽ

    QMap<QString,QString> mMapExControl;     //�������ƶ��ձ�

	int     m_row;			// ���鴰�ڵ�����
	int     m_column;       // ���鴰�ڵ�����
};

#endif // EXPRESSWIDGET_H
