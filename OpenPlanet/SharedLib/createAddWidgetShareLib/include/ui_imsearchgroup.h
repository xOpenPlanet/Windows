/********************************************************************************
** Form generated from reading UI file 'imsearchgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMSEARCHGROUP_H
#define UI_IMSEARCHGROUP_H

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

class Ui_IMSearchGroup
{
public:
    CFriendListWidgetBase *mListWidgetSearchGroup;
    QLineEdit *mlineEditSearchGroup;
    QPushButton *mPButtonSearchGroup;
    QLabel *mLabelSearchGroup;

    void setupUi(QWidget *IMSearchGroup)
    {
        if (IMSearchGroup->objectName().isEmpty())
            IMSearchGroup->setObjectName(QStringLiteral("IMSearchGroup"));
        IMSearchGroup->resize(700, 385);
        mListWidgetSearchGroup = new CFriendListWidgetBase(IMSearchGroup);
        mListWidgetSearchGroup->setObjectName(QStringLiteral("mListWidgetSearchGroup"));
        mListWidgetSearchGroup->setGeometry(QRect(0, 60, 700, 325));
        mlineEditSearchGroup = new QLineEdit(IMSearchGroup);
        mlineEditSearchGroup->setObjectName(QStringLiteral("mlineEditSearchGroup"));
        mlineEditSearchGroup->setGeometry(QRect(20, 15, 381, 30));
        mPButtonSearchGroup = new QPushButton(IMSearchGroup);
        mPButtonSearchGroup->setObjectName(QStringLiteral("mPButtonSearchGroup"));
        mPButtonSearchGroup->setGeometry(QRect(410, 10, 91, 41));
        mPButtonSearchGroup->setCursor(QCursor(Qt::PointingHandCursor));
        mLabelSearchGroup = new QLabel(IMSearchGroup);
        mLabelSearchGroup->setObjectName(QStringLiteral("mLabelSearchGroup"));
        mLabelSearchGroup->setGeometry(QRect(0, 0, 700, 60));
        mLabelSearchGroup->raise();
        mListWidgetSearchGroup->raise();
        mlineEditSearchGroup->raise();
        mPButtonSearchGroup->raise();

        retranslateUi(IMSearchGroup);

        QMetaObject::connectSlotsByName(IMSearchGroup);
    } // setupUi

    void retranslateUi(QWidget *IMSearchGroup)
    {
        IMSearchGroup->setWindowTitle(QApplication::translate("IMSearchGroup", "IMSearchGroup", 0));
        mPButtonSearchGroup->setText(QString());
        mLabelSearchGroup->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IMSearchGroup: public Ui_IMSearchGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMSEARCHGROUP_H
