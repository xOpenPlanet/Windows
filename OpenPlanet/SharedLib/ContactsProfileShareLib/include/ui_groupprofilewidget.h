/********************************************************************************
** Form generated from reading UI file 'groupprofilewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPPROFILEWIDGET_H
#define UI_GROUPPROFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupProfileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *groupLabel;
    QLabel *numberLabel;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *indexBtn;
    QPushButton *memberBtn;
    QPushButton *settingsBtn;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *nameLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label1;
    QLabel *createrLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *phoneLabel;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;

    void setupUi(QWidget *GroupProfileWidget)
    {
        if (GroupProfileWidget->objectName().isEmpty())
            GroupProfileWidget->setObjectName(QStringLiteral("GroupProfileWidget"));
        GroupProfileWidget->resize(340, 510);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GroupProfileWidget->sizePolicy().hasHeightForWidth());
        GroupProfileWidget->setSizePolicy(sizePolicy);
        GroupProfileWidget->setMinimumSize(QSize(340, 510));
        verticalLayout = new QVBoxLayout(GroupProfileWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(GroupProfileWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 100));
        widget->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_7 = new QHBoxLayout(widget);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(20, 20, 20, 20);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupLabel = new QLabel(widget);
        groupLabel->setObjectName(QStringLiteral("groupLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        groupLabel->setFont(font);
        groupLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(groupLabel);

        numberLabel = new QLabel(widget);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        numberLabel->setFont(font1);
        numberLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(numberLabel);


        horizontalLayout_7->addLayout(verticalLayout_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(GroupProfileWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 50));
        widget_2->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setSpacing(25);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        indexBtn = new QPushButton(widget_2);
        indexBtn->setObjectName(QStringLiteral("indexBtn"));
        indexBtn->setMinimumSize(QSize(0, 30));
        indexBtn->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        indexBtn->setFont(font2);
        indexBtn->setCheckable(true);

        horizontalLayout_6->addWidget(indexBtn);

        memberBtn = new QPushButton(widget_2);
        memberBtn->setObjectName(QStringLiteral("memberBtn"));
        memberBtn->setMinimumSize(QSize(0, 30));
        memberBtn->setFont(font2);
        memberBtn->setCheckable(true);

        horizontalLayout_6->addWidget(memberBtn);

        settingsBtn = new QPushButton(widget_2);
        settingsBtn->setObjectName(QStringLiteral("settingsBtn"));
        settingsBtn->setMinimumSize(QSize(0, 30));
        settingsBtn->setFont(font2);
        settingsBtn->setCheckable(true);

        horizontalLayout_6->addWidget(settingsBtn);

        horizontalSpacer_2 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        stackedWidget = new QStackedWidget(GroupProfileWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        verticalLayout_3 = new QVBoxLayout(page1);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(80, 0, 20, 20);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(page1);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMaximumSize(QSize(70, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setBold(false);
        font3.setWeight(50);
        label_3->setFont(font3);

        horizontalLayout->addWidget(label_3);

        nameLabel = new QLabel(page1);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setFont(font3);

        horizontalLayout->addWidget(nameLabel);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label1 = new QLabel(page1);
        label1->setObjectName(QStringLiteral("label1"));
        sizePolicy1.setHeightForWidth(label1->sizePolicy().hasHeightForWidth());
        label1->setSizePolicy(sizePolicy1);
        label1->setMaximumSize(QSize(70, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label1->setFont(font4);

        horizontalLayout_5->addWidget(label1);

        createrLabel = new QLabel(page1);
        createrLabel->setObjectName(QStringLiteral("createrLabel"));
        createrLabel->setFont(font4);

        horizontalLayout_5->addWidget(createrLabel);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(page1);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMaximumSize(QSize(70, 16777215));
        label_7->setFont(font3);

        horizontalLayout_2->addWidget(label_7);

        timeLabel = new QLabel(page1);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setFont(font3);

        horizontalLayout_2->addWidget(timeLabel);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(page1);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMaximumSize(QSize(70, 16777215));
        label_5->setFont(font3);

        horizontalLayout_3->addWidget(label_5);

        phoneLabel = new QLabel(page1);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));
        phoneLabel->setFont(font3);

        horizontalLayout_3->addWidget(phoneLabel);


        verticalLayout_3->addLayout(horizontalLayout_3);

        widget_3 = new QWidget(page1);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(widget_3);

        stackedWidget->addWidget(page1);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(GroupProfileWidget);

        QMetaObject::connectSlotsByName(GroupProfileWidget);
    } // setupUi

    void retranslateUi(QWidget *GroupProfileWidget)
    {
        GroupProfileWidget->setWindowTitle(QApplication::translate("GroupProfileWidget", "GroupProfileWidget", 0));
        groupLabel->setText(QString());
        numberLabel->setText(QString());
        indexBtn->setText(QApplication::translate("GroupProfileWidget", "\351\246\226\351\241\265", 0));
        memberBtn->setText(QApplication::translate("GroupProfileWidget", "\346\210\220\345\221\230", 0));
        settingsBtn->setText(QApplication::translate("GroupProfileWidget", "\350\256\276\347\275\256", 0));
        label_3->setText(QApplication::translate("GroupProfileWidget", "\347\276\244\345\220\215\347\247\260", 0));
        nameLabel->setText(QString());
        label1->setText(QApplication::translate("GroupProfileWidget", "\345\210\233\345\273\272\350\200\205", 0));
        createrLabel->setText(QString());
        label_7->setText(QApplication::translate("GroupProfileWidget", "\345\210\233\345\273\272\346\227\266\351\227\264", 0));
        timeLabel->setText(QString());
        label_5->setText(QApplication::translate("GroupProfileWidget", "\347\276\244\344\270\273/\347\256\241\347\220\206\345\221\230", 0));
        phoneLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GroupProfileWidget: public Ui_GroupProfileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPPROFILEWIDGET_H
