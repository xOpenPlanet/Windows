/********************************************************************************
** Form generated from reading UI file 'detailswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILSWIDGET_H
#define UI_DETAILSWIDGET_H

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

class Ui_DetailsWidget
{
public:
    QWidget *backWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *titleLabel;
    QPushButton *closeBtn;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label1;
    QLabel *valueLabel;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *IDWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QPlainTextEdit *IDEdit;
    QWidget *timeWidget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLineEdit *timeLine;
    QWidget *turnOutWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QPlainTextEdit *turnOutEdit;
    QWidget *turnInWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QPlainTextEdit *turnInEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *enterBtn;

    void setupUi(QWidget *DetailsWidget)
    {
        if (DetailsWidget->objectName().isEmpty())
            DetailsWidget->setObjectName(QStringLiteral("DetailsWidget"));
        DetailsWidget->resize(520, 440);
        DetailsWidget->setStyleSheet(QLatin1String("QWidget#DetailsWidget\n"
"{\n"
"background-color: \n"
"}"));
        backWidget = new QWidget(DetailsWidget);
        backWidget->setObjectName(QStringLiteral("backWidget"));
        backWidget->setGeometry(QRect(0, 0, 520, 440));
        backWidget->setMinimumSize(QSize(520, 440));
        backWidget->setMaximumSize(QSize(520, 440));
        backWidget->setStyleSheet(QLatin1String("QWidget#backWidget\n"
"{\n"
"background-color: rgb(24,50,87);\n"
"border: 1px solid rgb(9,25,45);\n"
"border-radius: 15px;\n"
"}\n"
"QPlainTextEdit\n"
"{\n"
"background-color: rgba(0,0,0, 0);\n"
"border: none;\n"
"color: #6a82a5;\n"
"padding: -4px;\n"
"}"));
        verticalLayout = new QVBoxLayout(backWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        titleLabel = new QLabel(backWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy);
        titleLabel->setMinimumSize(QSize(0, 26));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QLatin1String("QLabel#titleLabel\n"
"{\n"
"color: #6a82a5;\n"
"}"));

        horizontalLayout->addWidget(titleLabel);

        closeBtn = new QPushButton(backWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(26, 26));
        closeBtn->setMaximumSize(QSize(26, 26));
        closeBtn->setStyleSheet(QLatin1String("QPushButton#closeBtn\n"
"{\n"
"border-image: url(:/Login/Resources/login/pclogin_title_close.png);\n"
"}\n"
"QPushButton#closeBtn:hover\n"
"{\n"
"border-image: url(:/Login/Resources/login/title_close_hover.png);\n"
"}"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addLayout(horizontalLayout);

        mainWidget = new QWidget(backWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(mainWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(30, 0, 30, 30);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(mainWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(13);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("border: none;\n"
"color: #6a82a5;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ewallet/Resources/ewallet/transSuccess.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label1 = new QLabel(mainWidget);
        label1->setObjectName(QStringLiteral("label1"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(22);
        label1->setFont(font2);
        label1->setStyleSheet(QStringLiteral("color: #f7931e;"));

        horizontalLayout_3->addWidget(label1);

        valueLabel = new QLabel(mainWidget);
        valueLabel->setObjectName(QStringLiteral("valueLabel"));
        valueLabel->setFont(font2);
        valueLabel->setStyleSheet(QStringLiteral("color: #f7931e;"));

        horizontalLayout_3->addWidget(valueLabel);

        label_3 = new QLabel(mainWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        IDWidget = new QWidget(mainWidget);
        IDWidget->setObjectName(QStringLiteral("IDWidget"));
        IDWidget->setMinimumSize(QSize(0, 60));
        IDWidget->setMaximumSize(QSize(16777215, 60));
        IDWidget->setStyleSheet(QLatin1String("QWidget#IDWidget\n"
"{\n"
"border: none;\n"
"border-top: 1px solid #6a82a5;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(IDWidget);
        horizontalLayout_5->setSpacing(20);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 8, 0, 8);
        label = new QLabel(IDWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("color: #6a82a5;"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_5->addWidget(label);

        IDEdit = new QPlainTextEdit(IDWidget);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(11);
        IDEdit->setFont(font4);
        IDEdit->setStyleSheet(QStringLiteral(""));
        IDEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(IDEdit);


        verticalLayout_2->addWidget(IDWidget);

        timeWidget = new QWidget(mainWidget);
        timeWidget->setObjectName(QStringLiteral("timeWidget"));
        timeWidget->setMinimumSize(QSize(0, 46));
        timeWidget->setMaximumSize(QSize(16777215, 46));
        timeWidget->setStyleSheet(QLatin1String("QWidget#timeWidget\n"
"{\n"
"border: none;\n"
"border-top: 1px solid #6a82a5;\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(timeWidget);
        horizontalLayout_8->setSpacing(20);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 8, 0, 8);
        label_2 = new QLabel(timeWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setFont(font3);
        label_2->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout_8->addWidget(label_2);

        timeLine = new QLineEdit(timeWidget);
        timeLine->setObjectName(QStringLiteral("timeLine"));
        sizePolicy1.setHeightForWidth(timeLine->sizePolicy().hasHeightForWidth());
        timeLine->setSizePolicy(sizePolicy1);
        timeLine->setFont(font4);
        timeLine->setStyleSheet(QLatin1String("color: #6a82a5;\n"
"background-color: rgba(0,0,0, 0);\n"
"border: none;"));
        timeLine->setReadOnly(true);

        horizontalLayout_8->addWidget(timeLine);


        verticalLayout_2->addWidget(timeWidget);

        turnOutWidget = new QWidget(mainWidget);
        turnOutWidget->setObjectName(QStringLiteral("turnOutWidget"));
        turnOutWidget->setMinimumSize(QSize(0, 60));
        turnOutWidget->setMaximumSize(QSize(16777215, 60));
        turnOutWidget->setStyleSheet(QLatin1String("QWidget#turnOutWidget\n"
"{\n"
"border: none;\n"
"border-top: 1px solid #6a82a5;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(turnOutWidget);
        horizontalLayout_7->setSpacing(20);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 8, 0, 8);
        label_4 = new QLabel(turnOutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setFont(font3);
        label_4->setStyleSheet(QStringLiteral("color: #6a82a5;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(label_4);

        turnOutEdit = new QPlainTextEdit(turnOutWidget);
        turnOutEdit->setObjectName(QStringLiteral("turnOutEdit"));
        turnOutEdit->setFont(font4);
        turnOutEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(turnOutEdit);


        verticalLayout_2->addWidget(turnOutWidget);

        turnInWidget = new QWidget(mainWidget);
        turnInWidget->setObjectName(QStringLiteral("turnInWidget"));
        turnInWidget->setMinimumSize(QSize(0, 60));
        turnInWidget->setMaximumSize(QSize(16777215, 60));
        turnInWidget->setStyleSheet(QLatin1String("QWidget#turnInWidget\n"
"{\n"
"border: none;\n"
"border-top: 1px solid #6a82a5;\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(turnInWidget);
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 8, 0, 8);
        label_5 = new QLabel(turnInWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setFont(font3);
        label_5->setStyleSheet(QStringLiteral("color: #6a82a5;"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_6->addWidget(label_5);

        turnInEdit = new QPlainTextEdit(turnInWidget);
        turnInEdit->setObjectName(QStringLiteral("turnInEdit"));
        turnInEdit->setFont(font4);
        turnInEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(turnInEdit);


        verticalLayout_2->addWidget(turnInWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        enterBtn = new QPushButton(mainWidget);
        enterBtn->setObjectName(QStringLiteral("enterBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(enterBtn->sizePolicy().hasHeightForWidth());
        enterBtn->setSizePolicy(sizePolicy2);
        enterBtn->setMinimumSize(QSize(0, 34));
        enterBtn->setFont(font);
        enterBtn->setCursor(QCursor(Qt::PointingHandCursor));
        enterBtn->setStyleSheet(QLatin1String("QPushButton#enterBtn\n"
"{\n"
"background-color: #165da3;\n"
"color: white;\n"
"border: none;\n"
"border-radius: 10px;\n"
"}"));

        horizontalLayout_4->addWidget(enterBtn);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(mainWidget);


        retranslateUi(DetailsWidget);

        QMetaObject::connectSlotsByName(DetailsWidget);
    } // setupUi

    void retranslateUi(QWidget *DetailsWidget)
    {
        DetailsWidget->setWindowTitle(QApplication::translate("DetailsWidget", "DetailsWidget", 0));
        titleLabel->setText(QApplication::translate("DetailsWidget", "\344\272\244\346\230\223\350\257\246\346\203\205", 0));
        closeBtn->setText(QString());
        pushButton->setText(QApplication::translate("DetailsWidget", "  \344\272\244\346\230\223\346\210\220\345\212\237", 0));
        label1->setText(QApplication::translate("DetailsWidget", "-", 0));
        valueLabel->setText(QApplication::translate("DetailsWidget", "0", 0));
        label_3->setText(QApplication::translate("DetailsWidget", "\350\203\275\351\207\217", 0));
        label->setText(QApplication::translate("DetailsWidget", "\344\272\244\346\230\223ID", 0));
        IDEdit->setPlainText(QString());
        label_2->setText(QApplication::translate("DetailsWidget", "\344\272\244\346\230\223\346\227\266\351\227\264", 0));
        timeLine->setText(QString());
        label_4->setText(QApplication::translate("DetailsWidget", "\350\275\254\345\207\272\350\264\246\346\210\267", 0));
        turnOutEdit->setPlainText(QString());
        label_5->setText(QApplication::translate("DetailsWidget", "\346\216\245\346\224\266\350\264\246\346\210\267", 0));
        turnInEdit->setPlainText(QString());
        enterBtn->setText(QApplication::translate("DetailsWidget", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class DetailsWidget: public Ui_DetailsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILSWIDGET_H
