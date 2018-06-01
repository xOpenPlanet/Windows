/********************************************************************************
** Form generated from reading UI file 'scannetworksetwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANNETWORKSETWIDGET_H
#define UI_SCANNETWORKSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScanNetWorkSetWidget
{
public:
    QLabel *labelTitle;
    QLabel *labelUse;
    QLabel *labelAddress;
    QLabel *labelPort;
    QLabel *labelAccount;
    QLabel *labelPsw;
    QRadioButton *radioButtonOff;
    QRadioButton *radioButtonOn;
    QLineEdit *lineEditAddress;
    QLineEdit *lineEditPort;
    QLineEdit *lineEditAccount;
    QLineEdit *lineEditPsw;
    QPushButton *pushButtonConfirm;

    void setupUi(QWidget *ScanNetWorkSetWidget)
    {
        if (ScanNetWorkSetWidget->objectName().isEmpty())
            ScanNetWorkSetWidget->setObjectName(QStringLiteral("ScanNetWorkSetWidget"));
        ScanNetWorkSetWidget->resize(260, 290);
        labelTitle = new QLabel(ScanNetWorkSetWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(80, 10, 96, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        labelTitle->setFont(font);
        labelUse = new QLabel(ScanNetWorkSetWidget);
        labelUse->setObjectName(QStringLiteral("labelUse"));
        labelUse->setGeometry(QRect(20, 40, 61, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        labelUse->setFont(font1);
        labelAddress = new QLabel(ScanNetWorkSetWidget);
        labelAddress->setObjectName(QStringLiteral("labelAddress"));
        labelAddress->setGeometry(QRect(20, 80, 54, 24));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        labelAddress->setFont(font2);
        labelPort = new QLabel(ScanNetWorkSetWidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));
        labelPort->setGeometry(QRect(20, 120, 54, 24));
        labelPort->setFont(font2);
        labelAccount = new QLabel(ScanNetWorkSetWidget);
        labelAccount->setObjectName(QStringLiteral("labelAccount"));
        labelAccount->setGeometry(QRect(20, 160, 54, 24));
        labelAccount->setFont(font2);
        labelPsw = new QLabel(ScanNetWorkSetWidget);
        labelPsw->setObjectName(QStringLiteral("labelPsw"));
        labelPsw->setGeometry(QRect(20, 200, 54, 24));
        labelPsw->setFont(font2);
        radioButtonOff = new QRadioButton(ScanNetWorkSetWidget);
        radioButtonOff->setObjectName(QStringLiteral("radioButtonOff"));
        radioButtonOff->setGeometry(QRect(110, 44, 61, 16));
        radioButtonOff->setFont(font2);
        radioButtonOn = new QRadioButton(ScanNetWorkSetWidget);
        radioButtonOn->setObjectName(QStringLiteral("radioButtonOn"));
        radioButtonOn->setGeometry(QRect(180, 44, 51, 16));
        radioButtonOn->setFont(font2);
        lineEditAddress = new QLineEdit(ScanNetWorkSetWidget);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        lineEditAddress->setGeometry(QRect(60, 80, 180, 24));
        lineEditAddress->setFont(font2);
        lineEditPort = new QLineEdit(ScanNetWorkSetWidget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));
        lineEditPort->setGeometry(QRect(60, 120, 180, 24));
        lineEditPort->setFont(font2);
        lineEditAccount = new QLineEdit(ScanNetWorkSetWidget);
        lineEditAccount->setObjectName(QStringLiteral("lineEditAccount"));
        lineEditAccount->setGeometry(QRect(60, 160, 180, 24));
        lineEditAccount->setFont(font2);
        lineEditPsw = new QLineEdit(ScanNetWorkSetWidget);
        lineEditPsw->setObjectName(QStringLiteral("lineEditPsw"));
        lineEditPsw->setGeometry(QRect(60, 200, 180, 24));
        lineEditPsw->setFont(font2);
        pushButtonConfirm = new QPushButton(ScanNetWorkSetWidget);
        pushButtonConfirm->setObjectName(QStringLiteral("pushButtonConfirm"));
        pushButtonConfirm->setGeometry(QRect(90, 240, 85, 29));
        pushButtonConfirm->setFont(font);
        pushButtonConfirm->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(ScanNetWorkSetWidget);

        QMetaObject::connectSlotsByName(ScanNetWorkSetWidget);
    } // setupUi

    void retranslateUi(QWidget *ScanNetWorkSetWidget)
    {
        ScanNetWorkSetWidget->setWindowTitle(QApplication::translate("ScanNetWorkSetWidget", "ScanNetWorkSetWidget", 0));
        labelTitle->setText(QApplication::translate("ScanNetWorkSetWidget", "\347\275\221\347\273\234\344\273\243\347\220\206\350\256\276\347\275\256", 0));
        labelUse->setText(QApplication::translate("ScanNetWorkSetWidget", "\344\275\277\347\224\250\344\273\243\347\220\206", 0));
        labelAddress->setText(QApplication::translate("ScanNetWorkSetWidget", "\345\234\260\345\235\200", 0));
        labelPort->setText(QApplication::translate("ScanNetWorkSetWidget", "\347\253\257\345\217\243", 0));
        labelAccount->setText(QApplication::translate("ScanNetWorkSetWidget", "\350\264\246\345\217\267", 0));
        labelPsw->setText(QApplication::translate("ScanNetWorkSetWidget", "\345\257\206\347\240\201", 0));
        radioButtonOff->setText(QApplication::translate("ScanNetWorkSetWidget", "\345\205\263\351\227\255", 0));
        radioButtonOn->setText(QApplication::translate("ScanNetWorkSetWidget", "\345\274\200\345\220\257", 0));
        pushButtonConfirm->setText(QApplication::translate("ScanNetWorkSetWidget", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ScanNetWorkSetWidget: public Ui_ScanNetWorkSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANNETWORKSETWIDGET_H
