/********************************************************************************
** Form generated from reading UI file 'safewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAFEWIDGET_H
#define UI_SAFEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SafeWidget
{
public:
    QHBoxLayout *horizontalLayout_7;
    QWidget *midWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout;
    QWidget *backupItem;
    QHBoxLayout *horizontalLayout_2;
    QLabel *keyLabel;
    QLabel *label_1;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QWidget *rightWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *passwordPage;
    QVBoxLayout *verticalLayout_3;
    QLabel *label1;
    QLineEdit *passwordEdit;
    QLabel *tipLabel;
    QPushButton *enterBtn;
    QWidget *backupPage;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *copyBtn;

    void setupUi(QWidget *SafeWidget)
    {
        if (SafeWidget->objectName().isEmpty())
            SafeWidget->setObjectName(QStringLiteral("SafeWidget"));
        SafeWidget->resize(815, 523);
        SafeWidget->setStyleSheet(QLatin1String("QWidget#SafeWidget\n"
"{\n"
"background-color: #042439;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(SafeWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        midWidget = new QWidget(SafeWidget);
        midWidget->setObjectName(QStringLiteral("midWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(midWidget->sizePolicy().hasHeightForWidth());
        midWidget->setSizePolicy(sizePolicy);
        midWidget->setMinimumSize(QSize(500, 360));
        midWidget->setMaximumSize(QSize(500, 360));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        midWidget->setFont(font);
        midWidget->setStyleSheet(QLatin1String("QWidget#midWidget\n"
"{\n"
"border-radius: 4px;\n"
"background-color: #183457;\n"
"}\n"
"QLabel\n"
"{\n"
"background-color: #183457;\n"
"}\n"
"QLineEdit\n"
"{\n"
"border: 1px solid #6a82a5;\n"
"border-radius: 4px;\n"
"background-color: #183457;\n"
"color: white;\n"
"padding-left: 4px;\n"
"line-height: 28px;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"border-color: white;\n"
"}"));
        horizontalLayout = new QHBoxLayout(midWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        leftWidget = new QWidget(midWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(200, 0));
        leftWidget->setMaximumSize(QSize(200, 16777215));
        leftWidget->setStyleSheet(QLatin1String("QWidget#leftWidget\n"
"{\n"
"background-color: #09192d;\n"
"}"));
        verticalLayout = new QVBoxLayout(leftWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 1, 0);
        backupItem = new QWidget(leftWidget);
        backupItem->setObjectName(QStringLiteral("backupItem"));
        backupItem->setMinimumSize(QSize(0, 35));
        backupItem->setCursor(QCursor(Qt::PointingHandCursor));
        backupItem->setStyleSheet(QLatin1String("QWidget#backupItem\n"
"{\n"
"background-color: #183457;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(backupItem);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        keyLabel = new QLabel(backupItem);
        keyLabel->setObjectName(QStringLiteral("keyLabel"));
        keyLabel->setMinimumSize(QSize(22, 22));
        keyLabel->setMaximumSize(QSize(22, 22));
        keyLabel->setStyleSheet(QLatin1String("QLabel#keyLabel\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/privateKey.png);\n"
"}"));

        horizontalLayout_2->addWidget(keyLabel);

        label_1 = new QLabel(backupItem);
        label_1->setObjectName(QStringLiteral("label_1"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_1->setFont(font1);
        label_1->setStyleSheet(QLatin1String("QLabel#label_1\n"
"{\n"
"color: #4c6889;\n"
"}"));

        horizontalLayout_2->addWidget(label_1);

        label_4 = new QLabel(backupItem);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(22, 22));
        label_4->setMaximumSize(QSize(22, 22));
        label_4->setStyleSheet(QLatin1String("QLabel#label_4\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/more.png);\n"
"}"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addWidget(backupItem);

        verticalSpacer = new QSpacerItem(20, 318, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(leftWidget);

        rightWidget = new QWidget(midWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        rightWidget->setStyleSheet(QLatin1String("QWidget#rightWidget\n"
"{\n"
"background-color: #183457;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(rightWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        passwordPage = new QWidget(rightWidget);
        passwordPage->setObjectName(QStringLiteral("passwordPage"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(passwordPage->sizePolicy().hasHeightForWidth());
        passwordPage->setSizePolicy(sizePolicy1);
        passwordPage->setMinimumSize(QSize(0, 150));
        passwordPage->setMaximumSize(QSize(16777215, 150));
        passwordPage->setStyleSheet(QLatin1String("QWidget#passwordPage\n"
"{\n"
"background-color: #183457;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(passwordPage);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(40, 0, 40, 0);
        label1 = new QLabel(passwordPage);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setMinimumSize(QSize(0, 40));
        label1->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label1->setFont(font2);
        label1->setStyleSheet(QLatin1String("QLabel#label1\n"
"{\n"
"color: #4c6889;\n"
"}"));
        label1->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label1);

        passwordEdit = new QLineEdit(passwordPage);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setMinimumSize(QSize(0, 28));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        passwordEdit->setFont(font3);
        passwordEdit->setStyleSheet(QStringLiteral(""));
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(passwordEdit);

        tipLabel = new QLabel(passwordPage);
        tipLabel->setObjectName(QStringLiteral("tipLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tipLabel->sizePolicy().hasHeightForWidth());
        tipLabel->setSizePolicy(sizePolicy2);
        tipLabel->setMaximumSize(QSize(16777215, 12));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        tipLabel->setFont(font4);
        tipLabel->setStyleSheet(QLatin1String("QLabel#tipLabel\n"
"{\n"
"color: #e4ba7b;\n"
"}"));

        verticalLayout_3->addWidget(tipLabel);

        enterBtn = new QPushButton(passwordPage);
        enterBtn->setObjectName(QStringLiteral("enterBtn"));
        sizePolicy1.setHeightForWidth(enterBtn->sizePolicy().hasHeightForWidth());
        enterBtn->setSizePolicy(sizePolicy1);
        enterBtn->setMinimumSize(QSize(0, 28));
        enterBtn->setMaximumSize(QSize(16777215, 16777215));
        enterBtn->setFont(font3);
        enterBtn->setCursor(QCursor(Qt::PointingHandCursor));
        enterBtn->setStyleSheet(QLatin1String("QPushButton#enterBtn\n"
"{\n"
"color: white;\n"
"border: none;\n"
"background-color: #108ee9;\n"
"border-radius: 4px;\n"
"}"));

        verticalLayout_3->addWidget(enterBtn);


        verticalLayout_2->addWidget(passwordPage);

        backupPage = new QWidget(rightWidget);
        backupPage->setObjectName(QStringLiteral("backupPage"));
        backupPage->setMinimumSize(QSize(0, 200));
        backupPage->setMaximumSize(QSize(16777215, 200));
        backupPage->setStyleSheet(QLatin1String("QWidget#backupPage\n"
"{\n"
"background-color: #183457;\n"
"}\n"
"QLabel\n"
"{\n"
"background-color: #183457;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(backupPage);
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(40, 0, 40, 0);
        label_3 = new QLabel(backupPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setFont(font2);
        label_3->setStyleSheet(QLatin1String("QLabel#label_3\n"
"{\n"
"color: #4c6889;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        label_2 = new QLabel(backupPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("QLabel#label_2\n"
"{\n"
"color: #e4ba7b;\n"
"}"));

        verticalLayout_4->addWidget(label_2);

        plainTextEdit = new QPlainTextEdit(backupPage);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(0, 0));
        plainTextEdit->setMaximumSize(QSize(16777215, 16777215));
        plainTextEdit->setFont(font3);
        plainTextEdit->setStyleSheet(QLatin1String("QPlainTextEdit\n"
"{\n"
"background-color: #09192d;\n"
"color: #4c6889;\n"
"border: none;\n"
"}"));
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setReadOnly(true);

        verticalLayout_4->addWidget(plainTextEdit);

        copyBtn = new QPushButton(backupPage);
        copyBtn->setObjectName(QStringLiteral("copyBtn"));
        copyBtn->setMinimumSize(QSize(0, 28));
        copyBtn->setMaximumSize(QSize(16777215, 28));
        copyBtn->setFont(font3);
        copyBtn->setCursor(QCursor(Qt::PointingHandCursor));
        copyBtn->setStyleSheet(QLatin1String("QPushButton#copyBtn\n"
"{\n"
"color: white;\n"
"border: none;\n"
"background-color: #108ee9;\n"
"border-radius: 4px;\n"
"}"));

        verticalLayout_4->addWidget(copyBtn);


        verticalLayout_2->addWidget(backupPage);


        horizontalLayout->addWidget(rightWidget);


        horizontalLayout_7->addWidget(midWidget);


        retranslateUi(SafeWidget);

        QMetaObject::connectSlotsByName(SafeWidget);
    } // setupUi

    void retranslateUi(QWidget *SafeWidget)
    {
        SafeWidget->setWindowTitle(QApplication::translate("SafeWidget", "SafeWidget", 0));
        keyLabel->setText(QString());
        label_1->setText(QApplication::translate("SafeWidget", "\345\244\207\344\273\275\345\237\272\345\234\260\351\227\250\347\246\201\347\247\201\351\222\245", 0));
        label_4->setText(QString());
        label1->setText(QApplication::translate("SafeWidget", "\350\257\267\350\276\223\345\205\245\345\237\272\345\234\260\345\257\206\347\240\201", 0));
        passwordEdit->setText(QString());
        tipLabel->setText(QString());
        enterBtn->setText(QApplication::translate("SafeWidget", "\347\241\256\345\256\232", 0));
        label_3->setText(QApplication::translate("SafeWidget", "\345\244\207\344\273\275\347\247\201\351\222\245", 0));
        label_2->setText(QApplication::translate("SafeWidget", "\345\256\211\345\205\250\350\255\246\345\221\212\357\274\232\347\247\201\351\222\245\346\234\252\347\273\217\345\212\240\345\257\206\357\274\214\345\257\274\345\207\272\345\255\230\345\234\250\n"
"\351\243\216\351\231\251\357\274\214\345\273\272\350\256\256\344\275\277\347\224\250\345\212\251\350\256\260\350\257\215\350\277\233\350\241\214\345\244\207\344\273\275", 0));
        plainTextEdit->setPlainText(QString());
        copyBtn->setText(QApplication::translate("SafeWidget", "\345\244\215\345\210\266", 0));
    } // retranslateUi

};

namespace Ui {
    class SafeWidget: public Ui_SafeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAFEWIDGET_H
