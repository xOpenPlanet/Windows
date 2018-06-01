/********************************************************************************
** Form generated from reading UI file 'qcefview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCEFVIEW_H
#define UI_QCEFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QCefViewClass
{
public:

    void setupUi(QWidget *QCefViewClass)
    {
        if (QCefViewClass->objectName().isEmpty())
            QCefViewClass->setObjectName(QStringLiteral("QCefViewClass"));
        QCefViewClass->resize(816, 518);

        retranslateUi(QCefViewClass);

        QMetaObject::connectSlotsByName(QCefViewClass);
    } // setupUi

    void retranslateUi(QWidget *QCefViewClass)
    {
        QCefViewClass->setWindowTitle(QApplication::translate("QCefViewClass", "QCefView", 0));
    } // retranslateUi

};

namespace Ui {
    class QCefViewClass: public Ui_QCefViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCEFVIEW_H
