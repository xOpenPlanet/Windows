/********************************************************************************
** Form generated from reading UI file 'scanloginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANLOGINWIDGET_H
#define UI_SCANLOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "..\SharedLib\BaseUI\include\qlabelheader.h"

QT_BEGIN_NAMESPACE

class Ui_ScanLoginWidget
{
public:
    QLabelHeader *labelHeader;
    QLabel *labelNikeName;
    QLabel *labelChangeUser;
    QPushButton *pushButtonLogin;

    void setupUi(QWidget *ScanLoginWidget)
    {
        if (ScanLoginWidget->objectName().isEmpty())
            ScanLoginWidget->setObjectName(QStringLiteral("ScanLoginWidget"));
        ScanLoginWidget->resize(330, 306);
        labelHeader = new QLabelHeader(ScanLoginWidget);
        labelHeader->setObjectName(QStringLiteral("labelHeader"));
        labelHeader->setGeometry(QRect(100, 20, 160, 130));
        labelNikeName = new QLabel(ScanLoginWidget);
        labelNikeName->setObjectName(QStringLiteral("labelNikeName"));
        labelNikeName->setGeometry(QRect(90, 170, 160, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        labelNikeName->setFont(font);
        labelNikeName->setAlignment(Qt::AlignCenter);
        labelChangeUser = new QLabel(ScanLoginWidget);
        labelChangeUser->setObjectName(QStringLiteral("labelChangeUser"));
        labelChangeUser->setGeometry(QRect(90, 210, 160, 24));
        labelChangeUser->setFont(font);
        labelChangeUser->setCursor(QCursor(Qt::PointingHandCursor));
        labelChangeUser->setAlignment(Qt::AlignCenter);
        pushButtonLogin = new QPushButton(ScanLoginWidget);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(35, 250, 261, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        pushButtonLogin->setFont(font1);
        pushButtonLogin->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(ScanLoginWidget);

        QMetaObject::connectSlotsByName(ScanLoginWidget);
    } // setupUi

    void retranslateUi(QWidget *ScanLoginWidget)
    {
        ScanLoginWidget->setWindowTitle(QApplication::translate("ScanLoginWidget", "ScanLoginWidget", 0));
        labelHeader->setText(QString());
        labelNikeName->setText(QApplication::translate("ScanLoginWidget", "\351\230\277\347\216\233\345\260\274\345\245\275", 0));
        labelChangeUser->setText(QApplication::translate("ScanLoginWidget", "\345\210\207\346\215\242\350\264\246\346\210\267", 0));
        pushButtonLogin->setText(QApplication::translate("ScanLoginWidget", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class ScanLoginWidget: public Ui_ScanLoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANLOGINWIDGET_H
