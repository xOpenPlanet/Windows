/********************************************************************************
** Form generated from reading UI file 'aboutwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWIDGET_H
#define UI_ABOUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *closeBtn;
    QLabel *nameLabel;
    QLabel *numberLabel;
    QLabel *label_5;

    void setupUi(QWidget *AboutWidget)
    {
        if (AboutWidget->objectName().isEmpty())
            AboutWidget->setObjectName(QStringLiteral("AboutWidget"));
        AboutWidget->resize(293, 181);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        AboutWidget->setFont(font);
        label = new QLabel(AboutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(100, 100));
        label->setMaximumSize(QSize(120, 120));
        label_2 = new QLabel(AboutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 291, 30));
        label_2->setFont(font);
        label_3 = new QLabel(AboutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 5, 101, 19));
        closeBtn = new QPushButton(AboutWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(262, 1, 28, 28));
        sizePolicy.setHeightForWidth(closeBtn->sizePolicy().hasHeightForWidth());
        closeBtn->setSizePolicy(sizePolicy);
        closeBtn->setMinimumSize(QSize(28, 28));
        closeBtn->setMaximumSize(QSize(28, 28));
        nameLabel = new QLabel(AboutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(150, 40, 131, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        nameLabel->setFont(font1);
        numberLabel = new QLabel(AboutWidget);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));
        numberLabel->setGeometry(QRect(150, 80, 101, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        numberLabel->setFont(font2);
        label_5 = new QLabel(AboutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 30, 291, 141));
        label_5->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        closeBtn->raise();
        nameLabel->raise();
        numberLabel->raise();

        retranslateUi(AboutWidget);

        QMetaObject::connectSlotsByName(AboutWidget);
    } // setupUi

    void retranslateUi(QWidget *AboutWidget)
    {
        AboutWidget->setWindowTitle(QApplication::translate("AboutWidget", "\345\205\263\344\272\216", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("AboutWidget", "\345\205\263\344\272\216", 0));
        closeBtn->setText(QString());
        nameLabel->setText(QString());
        numberLabel->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutWidget: public Ui_AboutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIDGET_H
