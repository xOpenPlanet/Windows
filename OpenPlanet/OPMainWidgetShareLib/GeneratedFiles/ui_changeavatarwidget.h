/********************************************************************************
** Form generated from reading UI file 'changeavatarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEAVATARWIDGET_H
#define UI_CHANGEAVATARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeAvatarWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *iconLabel;
    QLabel *titleLabel;
    QPushButton *closeBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QLabel *headerLabel;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *uploadBtn;
    QPushButton *confirmBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *ChangeAvatarWidget)
    {
        if (ChangeAvatarWidget->objectName().isEmpty())
            ChangeAvatarWidget->setObjectName(QStringLiteral("ChangeAvatarWidget"));
        ChangeAvatarWidget->resize(300, 350);
        ChangeAvatarWidget->setMinimumSize(QSize(300, 350));
        ChangeAvatarWidget->setMaximumSize(QSize(300, 350));
        verticalLayout = new QVBoxLayout(ChangeAvatarWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(ChangeAvatarWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 30));
        widget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 0, 0, 0);
        iconLabel = new QLabel(widget);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(iconLabel->sizePolicy().hasHeightForWidth());
        iconLabel->setSizePolicy(sizePolicy1);
        iconLabel->setMinimumSize(QSize(26, 26));
        iconLabel->setMaximumSize(QSize(26, 26));

        horizontalLayout->addWidget(iconLabel);

        titleLabel = new QLabel(widget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        titleLabel->setFont(font);

        horizontalLayout->addWidget(titleLabel);

        closeBtn = new QPushButton(widget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        sizePolicy1.setHeightForWidth(closeBtn->sizePolicy().hasHeightForWidth());
        closeBtn->setSizePolicy(sizePolicy1);
        closeBtn->setMinimumSize(QSize(28, 28));
        closeBtn->setMaximumSize(QSize(28, 28));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(ChangeAvatarWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(10000, 10000));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(6);
        widget_2->setFont(font1);
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(200, 200));
        scrollArea->setMaximumSize(QSize(200, 200));
        scrollArea->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1000, 1000));
        scrollAreaWidgetContents->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        headerLabel = new QLabel(scrollAreaWidgetContents);
        headerLabel->setObjectName(QStringLiteral("headerLabel"));
        sizePolicy1.setHeightForWidth(headerLabel->sizePolicy().hasHeightForWidth());
        headerLabel->setSizePolicy(sizePolicy1);
        headerLabel->setMinimumSize(QSize(1000, 1000));
        headerLabel->setScaledContents(true);

        horizontalLayout_3->addWidget(headerLabel);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(scrollArea);


        verticalLayout->addWidget(widget_2);

        widget_4 = new QWidget(ChangeAvatarWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 60));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 44, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        uploadBtn = new QPushButton(widget_4);
        uploadBtn->setObjectName(QStringLiteral("uploadBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(uploadBtn->sizePolicy().hasHeightForWidth());
        uploadBtn->setSizePolicy(sizePolicy2);
        uploadBtn->setMinimumSize(QSize(60, 26));
        uploadBtn->setMaximumSize(QSize(16777215, 26));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        uploadBtn->setFont(font2);

        horizontalLayout_2->addWidget(uploadBtn);

        confirmBtn = new QPushButton(widget_4);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(confirmBtn->sizePolicy().hasHeightForWidth());
        confirmBtn->setSizePolicy(sizePolicy3);
        confirmBtn->setMinimumSize(QSize(60, 0));
        confirmBtn->setMaximumSize(QSize(60, 26));
        confirmBtn->setFont(font2);

        horizontalLayout_2->addWidget(confirmBtn);

        cancelBtn = new QPushButton(widget_4);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        sizePolicy3.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy3);
        cancelBtn->setMinimumSize(QSize(60, 26));
        cancelBtn->setMaximumSize(QSize(70, 26));
        cancelBtn->setFont(font2);

        horizontalLayout_2->addWidget(cancelBtn);


        verticalLayout->addWidget(widget_4);


        retranslateUi(ChangeAvatarWidget);

        QMetaObject::connectSlotsByName(ChangeAvatarWidget);
    } // setupUi

    void retranslateUi(QWidget *ChangeAvatarWidget)
    {
        ChangeAvatarWidget->setWindowTitle(QApplication::translate("ChangeAvatarWidget", "\346\233\264\346\215\242\345\244\264\345\203\217", 0));
        iconLabel->setText(QString());
        titleLabel->setText(QApplication::translate("ChangeAvatarWidget", "\346\233\264\346\215\242\345\244\264\345\203\217", 0));
        closeBtn->setText(QString());
        headerLabel->setText(QString());
        uploadBtn->setText(QApplication::translate("ChangeAvatarWidget", "\344\270\212\344\274\240\347\205\247\347\211\207", 0));
        confirmBtn->setText(QApplication::translate("ChangeAvatarWidget", "\347\241\256\345\256\232", 0));
        cancelBtn->setText(QApplication::translate("ChangeAvatarWidget", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangeAvatarWidget: public Ui_ChangeAvatarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEAVATARWIDGET_H
