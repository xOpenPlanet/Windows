/********************************************************************************
** Form generated from reading UI file 'invitecodewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVITECODEWIDGET_H
#define UI_INVITECODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InviteCodeWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_1;
    QLabel *codeLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *copyBtn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *imageLabel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;

    void setupUi(QWidget *InviteCodeWidget)
    {
        if (InviteCodeWidget->objectName().isEmpty())
            InviteCodeWidget->setObjectName(QStringLiteral("InviteCodeWidget"));
        InviteCodeWidget->resize(750, 462);
        InviteCodeWidget->setStyleSheet(QLatin1String("QWidget#InviteCodeWidget\n"
"{\n"
"background-color: #042439;\n"
"}"));
        horizontalLayout = new QHBoxLayout(InviteCodeWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mainWidget = new QWidget(InviteCodeWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setMaximumSize(QSize(330, 400));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget\n"
"{\n"
"background-color: #15447c;\n"
"border-radius: 10px;\n"
"}\n"
"QLabel\n"
"{\n"
"background-color: #15447c;\n"
"}"));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 30, -1, 30);
        label_1 = new QLabel(mainWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setMinimumSize(QSize(0, 40));
        label_1->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);
        label_1->setStyleSheet(QLatin1String("QLabel#label_1\n"
"{\n"
"color: #108ee9;\n"
"}"));
        label_1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_1);

        codeLabel = new QLabel(mainWidget);
        codeLabel->setObjectName(QStringLiteral("codeLabel"));
        codeLabel->setMinimumSize(QSize(0, 50));
        codeLabel->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        codeLabel->setFont(font1);
        codeLabel->setStyleSheet(QLatin1String("QLabel#codeLabel\n"
"{\n"
"color: #108ee9;\n"
"}"));
        codeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(codeLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        copyBtn = new QPushButton(mainWidget);
        copyBtn->setObjectName(QStringLiteral("copyBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(copyBtn->sizePolicy().hasHeightForWidth());
        copyBtn->setSizePolicy(sizePolicy);
        copyBtn->setMinimumSize(QSize(76, 32));
        copyBtn->setMaximumSize(QSize(76, 32));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        copyBtn->setFont(font2);
        copyBtn->setCursor(QCursor(Qt::PointingHandCursor));
        copyBtn->setStyleSheet(QLatin1String("QPushButton#copyBtn\n"
"{\n"
"color: white;\n"
"background-color: #165da3;\n"
"border: none;\n"
"border-radius: 6px;\n"
"}"));

        horizontalLayout_2->addWidget(copyBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        label_3 = new QLabel(mainWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        label_3->setFont(font3);
        label_3->setStyleSheet(QLatin1String("QLabel#label_3\n"
"{\n"
"color: #6a82a5;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        imageLabel = new QLabel(mainWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setMinimumSize(QSize(120, 120));
        imageLabel->setMaximumSize(QSize(120, 120));
        imageLabel->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"padding: 10px;"));

        horizontalLayout_3->addWidget(imageLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        label_5 = new QLabel(mainWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 30));
        label_5->setFont(font3);
        label_5->setStyleSheet(QLatin1String("QLabel#label_5\n"
"{\n"
"color: #6a82a5;\n"
"}"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);


        horizontalLayout->addWidget(mainWidget);


        retranslateUi(InviteCodeWidget);

        QMetaObject::connectSlotsByName(InviteCodeWidget);
    } // setupUi

    void retranslateUi(QWidget *InviteCodeWidget)
    {
        InviteCodeWidget->setWindowTitle(QApplication::translate("InviteCodeWidget", "InviteCodeWidget", 0));
        label_1->setText(QApplication::translate("InviteCodeWidget", "\346\202\250\347\232\204\351\202\200\350\257\267\347\240\201", 0));
        codeLabel->setText(QApplication::translate("InviteCodeWidget", "9QRKGE", 0));
        copyBtn->setText(QApplication::translate("InviteCodeWidget", "\345\244\215\345\210\266", 0));
        label_3->setText(QApplication::translate("InviteCodeWidget", "\346\257\217\351\202\200\350\257\267\344\270\200\344\275\215\345\245\275\345\217\213\346\263\250\345\206\214\345\220\216\357\274\214\346\202\250\345\260\206\350\216\267\345\217\2261000\351\223\266\351\222\273\345\245\226\345\212\261", 0));
        imageLabel->setText(QString());
        label_5->setText(QApplication::translate("InviteCodeWidget", "\346\211\253\347\240\201\344\270\213\350\275\275\345\274\200\346\224\276\346\230\237\347\220\203", 0));
    } // retranslateUi

};

namespace Ui {
    class InviteCodeWidget: public Ui_InviteCodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVITECODEWIDGET_H
