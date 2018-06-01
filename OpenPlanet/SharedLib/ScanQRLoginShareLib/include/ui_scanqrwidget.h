/********************************************************************************
** Form generated from reading UI file 'scanqrwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANQRWIDGET_H
#define UI_SCANQRWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScanQRWidget
{
public:
    QStackedWidget *stackedWidget;
    QLabel *label;
    QLabel *labelTitle;
    QPushButton *pushButtonSet;
    QPushButton *pushButtonClose;

    void setupUi(QWidget *ScanQRWidget)
    {
        if (ScanQRWidget->objectName().isEmpty())
            ScanQRWidget->setObjectName(QStringLiteral("ScanQRWidget"));
        ScanQRWidget->resize(280, 340);
        QFont font;
        font.setPointSize(14);
        ScanQRWidget->setFont(font);
        ScanQRWidget->setStyleSheet(QStringLiteral(""));
        stackedWidget = new QStackedWidget(ScanQRWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 40, 260, 290));
        label = new QLabel(ScanQRWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 280, 340));
        labelTitle = new QLabel(ScanQRWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(11, 11, 69, 24));
        labelTitle->setMinimumSize(QSize(0, 24));
        labelTitle->setMaximumSize(QSize(16777215, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        labelTitle->setFont(font1);
        pushButtonSet = new QPushButton(ScanQRWidget);
        pushButtonSet->setObjectName(QStringLiteral("pushButtonSet"));
        pushButtonSet->setGeometry(QRect(226, 11, 24, 24));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonSet->sizePolicy().hasHeightForWidth());
        pushButtonSet->setSizePolicy(sizePolicy);
        pushButtonSet->setMinimumSize(QSize(24, 24));
        pushButtonSet->setMaximumSize(QSize(24, 24));
        pushButtonSet->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonSet->setAutoFillBackground(false);
        pushButtonClose = new QPushButton(ScanQRWidget);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(250, 11, 24, 24));
        sizePolicy.setHeightForWidth(pushButtonClose->sizePolicy().hasHeightForWidth());
        pushButtonClose->setSizePolicy(sizePolicy);
        pushButtonClose->setMinimumSize(QSize(24, 24));
        pushButtonClose->setMaximumSize(QSize(24, 24));
        pushButtonClose->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonClose->setAutoFillBackground(false);
        label->raise();
        stackedWidget->raise();
        labelTitle->raise();
        pushButtonClose->raise();
        pushButtonSet->raise();

        retranslateUi(ScanQRWidget);

        QMetaObject::connectSlotsByName(ScanQRWidget);
    } // setupUi

    void retranslateUi(QWidget *ScanQRWidget)
    {
        ScanQRWidget->setWindowTitle(QApplication::translate("ScanQRWidget", "ScanQRWidget", 0));
        label->setText(QString());
        labelTitle->setText(QApplication::translate("ScanQRWidget", " \345\274\200\346\224\276\346\230\237\347\220\203", 0));
        pushButtonSet->setText(QString());
        pushButtonClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScanQRWidget: public Ui_ScanQRWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANQRWIDGET_H
