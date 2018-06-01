/********************************************************************************
** Form generated from reading UI file 'userprofilewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROFILEWIDGET_H
#define UI_USERPROFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserProfileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *noteLabel;
    QLabel *signLabel;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *accountLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLabel *lianxinLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *phoneLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *mailLabel;

    void setupUi(QWidget *UserProfileWidget)
    {
        if (UserProfileWidget->objectName().isEmpty())
            UserProfileWidget->setObjectName(QStringLiteral("UserProfileWidget"));
        UserProfileWidget->resize(340, 600);
        verticalLayout = new QVBoxLayout(UserProfileWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        headerLabel = new QLabel(UserProfileWidget);
        headerLabel->setObjectName(QStringLiteral("headerLabel"));
        headerLabel->setMinimumSize(QSize(0, 340));
        headerLabel->setMaximumSize(QSize(16777215, 340));
        headerLabel->setScaledContents(false);

        verticalLayout->addWidget(headerLabel);

        widget = new QWidget(UserProfileWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 100));
        widget->setMaximumSize(QSize(16777215, 100));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 22, 0, 22);
        noteLabel = new QLabel(widget);
        noteLabel->setObjectName(QStringLiteral("noteLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        noteLabel->setFont(font);
        noteLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(noteLabel);

        signLabel = new QLabel(widget);
        signLabel->setObjectName(QStringLiteral("signLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        signLabel->setFont(font1);
        signLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(signLabel);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(UserProfileWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(90, 0, 20, 20);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(50, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font2);

        horizontalLayout_5->addWidget(label);

        accountLabel = new QLabel(widget_2);
        accountLabel->setObjectName(QStringLiteral("accountLabel"));
        accountLabel->setFont(font2);

        horizontalLayout_5->addWidget(accountLabel);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(50, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setBold(false);
        font3.setWeight(50);
        label_3->setFont(font3);

        horizontalLayout->addWidget(label_3);

        nameLabel = new QLabel(widget_2);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font3);

        horizontalLayout->addWidget(nameLabel);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMaximumSize(QSize(50, 16777215));
        label_7->setFont(font3);

        horizontalLayout_2->addWidget(label_7);

        lianxinLabel = new QLabel(widget_2);
        lianxinLabel->setObjectName(QStringLiteral("lianxinLabel"));
        lianxinLabel->setFont(font3);

        horizontalLayout_2->addWidget(lianxinLabel);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(50, 16777215));
        label_5->setFont(font3);

        horizontalLayout_3->addWidget(label_5);

        phoneLabel = new QLabel(widget_2);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));
        phoneLabel->setFont(font3);

        horizontalLayout_3->addWidget(phoneLabel);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMaximumSize(QSize(50, 16777215));
        label_6->setFont(font3);

        horizontalLayout_4->addWidget(label_6);

        mailLabel = new QLabel(widget_2);
        mailLabel->setObjectName(QStringLiteral("mailLabel"));
        mailLabel->setFont(font3);

        horizontalLayout_4->addWidget(mailLabel);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(widget_2);


        retranslateUi(UserProfileWidget);

        QMetaObject::connectSlotsByName(UserProfileWidget);
    } // setupUi

    void retranslateUi(QWidget *UserProfileWidget)
    {
        UserProfileWidget->setWindowTitle(QApplication::translate("UserProfileWidget", "UserProfileWidget", 0));
        headerLabel->setText(QString());
        noteLabel->setText(QString());
        signLabel->setText(QString());
        label->setText(QApplication::translate("UserProfileWidget", "\350\264\246\345\217\267", 0));
        accountLabel->setText(QString());
        label_3->setText(QApplication::translate("UserProfileWidget", "\346\230\265\347\247\260", 0));
        nameLabel->setText(QString());
        label_7->setText(QApplication::translate("UserProfileWidget", "ID", 0));
        lianxinLabel->setText(QString());
        label_5->setText(QApplication::translate("UserProfileWidget", "\347\224\265\350\257\235", 0));
        phoneLabel->setText(QString());
        label_6->setText(QApplication::translate("UserProfileWidget", "\351\202\256\347\256\261", 0));
        mailLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserProfileWidget: public Ui_UserProfileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILEWIDGET_H
