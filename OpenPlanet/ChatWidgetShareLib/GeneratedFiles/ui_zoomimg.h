/********************************************************************************
** Form generated from reading UI file 'zoomimg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZOOMIMG_H
#define UI_ZOOMIMG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zoomImg
{
public:

    void setupUi(QWidget *zoomImg)
    {
        if (zoomImg->objectName().isEmpty())
            zoomImg->setObjectName(QStringLiteral("zoomImg"));
        zoomImg->resize(400, 300);

        retranslateUi(zoomImg);

        QMetaObject::connectSlotsByName(zoomImg);
    } // setupUi

    void retranslateUi(QWidget *zoomImg)
    {
        zoomImg->setWindowTitle(QApplication::translate("zoomImg", "\345\233\276\347\211\207", 0));
    } // retranslateUi

};

namespace Ui {
    class zoomImg: public Ui_zoomImg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZOOMIMG_H
