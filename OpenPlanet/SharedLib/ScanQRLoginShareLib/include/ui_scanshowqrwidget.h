/********************************************************************************
** Form generated from reading UI file 'scanshowqrwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANSHOWQRWIDGET_H
#define UI_SCANSHOWQRWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScanShowQRWidget
{
public:
    QLabel *labelQR;
    QLabel *labelTip;
    QLabel *label1;
    QLabel *labelTip_2;

    void setupUi(QWidget *ScanShowQRWidget)
    {
        if (ScanShowQRWidget->objectName().isEmpty())
            ScanShowQRWidget->setObjectName(QStringLiteral("ScanShowQRWidget"));
        ScanShowQRWidget->resize(260, 290);
        labelQR = new QLabel(ScanShowQRWidget);
        labelQR->setObjectName(QStringLiteral("labelQR"));
        labelQR->setGeometry(QRect(50, 40, 160, 160));
        labelTip = new QLabel(ScanShowQRWidget);
        labelTip->setObjectName(QStringLiteral("labelTip"));
        labelTip->setGeometry(QRect(10, 250, 240, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        labelTip->setFont(font);
        labelTip->setAlignment(Qt::AlignCenter);
        label1 = new QLabel(ScanShowQRWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(40, 30, 180, 180));
        labelTip_2 = new QLabel(ScanShowQRWidget);
        labelTip_2->setObjectName(QStringLiteral("labelTip_2"));
        labelTip_2->setGeometry(QRect(50, 210, 161, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        labelTip_2->setFont(font1);
        labelTip_2->setAlignment(Qt::AlignCenter);
        label1->raise();
        labelTip->raise();
        labelQR->raise();
        labelTip_2->raise();

        retranslateUi(ScanShowQRWidget);

        QMetaObject::connectSlotsByName(ScanShowQRWidget);
    } // setupUi

    void retranslateUi(QWidget *ScanShowQRWidget)
    {
        ScanShowQRWidget->setWindowTitle(QApplication::translate("ScanShowQRWidget", "ScanShowQRWidget", 0));
        labelQR->setText(QString());
        labelTip->setText(QApplication::translate("ScanShowQRWidget", "\350\257\267\344\275\277\347\224\250\345\274\200\346\224\276\346\230\237\347\220\203\346\211\253\346\217\217\344\270\212\346\226\271\344\272\214\347\273\264\347\240\201\347\231\273\345\275\225", 0));
        label1->setText(QString());
        labelTip_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScanShowQRWidget: public Ui_ScanShowQRWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANSHOWQRWIDGET_H
