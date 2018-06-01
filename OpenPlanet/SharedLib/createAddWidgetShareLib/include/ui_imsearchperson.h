/********************************************************************************
** Form generated from reading UI file 'imsearchperson.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMSEARCHPERSON_H
#define UI_IMSEARCHPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "cfriendlistwidgetbase.h"

QT_BEGIN_NAMESPACE

class Ui_IMSearchPerson
{
public:
    QLineEdit *mlineEditSearchPerson;
    QPushButton *mPButtonSearchPerson;
    QLabel *mLabelSearchPerson;
    CFriendListWidgetBase *mListWidgetSearchPerson;

    void setupUi(QWidget *IMSearchPerson)
    {
        if (IMSearchPerson->objectName().isEmpty())
            IMSearchPerson->setObjectName(QStringLiteral("IMSearchPerson"));
        IMSearchPerson->resize(700, 385);
        mlineEditSearchPerson = new QLineEdit(IMSearchPerson);
        mlineEditSearchPerson->setObjectName(QStringLiteral("mlineEditSearchPerson"));
        mlineEditSearchPerson->setGeometry(QRect(20, 15, 381, 30));
        mPButtonSearchPerson = new QPushButton(IMSearchPerson);
        mPButtonSearchPerson->setObjectName(QStringLiteral("mPButtonSearchPerson"));
        mPButtonSearchPerson->setGeometry(QRect(410, 10, 91, 41));
        mPButtonSearchPerson->setCursor(QCursor(Qt::PointingHandCursor));
        mLabelSearchPerson = new QLabel(IMSearchPerson);
        mLabelSearchPerson->setObjectName(QStringLiteral("mLabelSearchPerson"));
        mLabelSearchPerson->setGeometry(QRect(0, 0, 700, 60));
        mListWidgetSearchPerson = new CFriendListWidgetBase(IMSearchPerson);
        mListWidgetSearchPerson->setObjectName(QStringLiteral("mListWidgetSearchPerson"));
        mListWidgetSearchPerson->setGeometry(QRect(0, 60, 700, 325));
        mLabelSearchPerson->raise();
        mlineEditSearchPerson->raise();
        mPButtonSearchPerson->raise();
        mListWidgetSearchPerson->raise();

        retranslateUi(IMSearchPerson);

        QMetaObject::connectSlotsByName(IMSearchPerson);
    } // setupUi

    void retranslateUi(QWidget *IMSearchPerson)
    {
        IMSearchPerson->setWindowTitle(QApplication::translate("IMSearchPerson", "IMSearchPerson", 0));
        mPButtonSearchPerson->setText(QString());
        mLabelSearchPerson->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IMSearchPerson: public Ui_IMSearchPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMSEARCHPERSON_H
