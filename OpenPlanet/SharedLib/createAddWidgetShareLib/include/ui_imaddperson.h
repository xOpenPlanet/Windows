/********************************************************************************
** Form generated from reading UI file 'imaddperson.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMADDPERSON_H
#define UI_IMADDPERSON_H

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

class Ui_IMAddPerson
{
public:
    QLabel *mLabelBK;
    QPushButton *mPButtonFindPerson;
    QPushButton *mPButtonFindGroup;
    QPushButton *mPButtonFindAppNo;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *IMAddPerson)
    {
        if (IMAddPerson->objectName().isEmpty())
            IMAddPerson->setObjectName(QStringLiteral("IMAddPerson"));
        IMAddPerson->resize(700, 450);
        mLabelBK = new QLabel(IMAddPerson);
        mLabelBK->setObjectName(QStringLiteral("mLabelBK"));
        mLabelBK->setGeometry(QRect(0, 30, 700, 35));
        mPButtonFindPerson = new QPushButton(IMAddPerson);
        mPButtonFindPerson->setObjectName(QStringLiteral("mPButtonFindPerson"));
        mPButtonFindPerson->setGeometry(QRect(200, 30, 95, 35));
        mPButtonFindPerson->setCursor(QCursor(Qt::PointingHandCursor));
        mPButtonFindGroup = new QPushButton(IMAddPerson);
        mPButtonFindGroup->setObjectName(QStringLiteral("mPButtonFindGroup"));
        mPButtonFindGroup->setGeometry(QRect(295, 30, 95, 35));
        mPButtonFindGroup->setCursor(QCursor(Qt::PointingHandCursor));
        mPButtonFindAppNo = new QPushButton(IMAddPerson);
        mPButtonFindAppNo->setObjectName(QStringLiteral("mPButtonFindAppNo"));
        mPButtonFindAppNo->setGeometry(QRect(420, 30, 95, 35));
        mPButtonFindAppNo->setCursor(QCursor(Qt::PointingHandCursor));
        stackedWidget = new QStackedWidget(IMAddPerson);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 65, 700, 385));

        retranslateUi(IMAddPerson);

        QMetaObject::connectSlotsByName(IMAddPerson);
    } // setupUi

    void retranslateUi(QWidget *IMAddPerson)
    {
        IMAddPerson->setWindowTitle(QApplication::translate("IMAddPerson", "IMAddPerson", 0));
        mLabelBK->setText(QString());
        mPButtonFindPerson->setText(QApplication::translate("IMAddPerson", "\346\211\276\344\272\272", 0));
        mPButtonFindGroup->setText(QApplication::translate("IMAddPerson", "\346\211\276\347\276\244", 0));
        mPButtonFindAppNo->setText(QApplication::translate("IMAddPerson", "\345\272\224\347\224\250\345\217\267\346\234\215\345\212\241\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class IMAddPerson: public Ui_IMAddPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMADDPERSON_H
