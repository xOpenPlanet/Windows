/********************************************************************************
** Form generated from reading UI file 'immainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMMAINWIDGET_H
#define UI_IMMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qlabelheader.h>
#include "toolbutton.h"

QT_BEGIN_NAMESPACE

class Ui_IMMainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleBar;
    QHBoxLayout *horizontalLayout_2;
    QWidget *leftWidget;
    QLabel *label;
    QWidget *midWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    ToolButton *messageBtn;
    ToolButton *contactsBtn;
    ToolButton *robotsBtn;
    ToolButton *walletBtn;
    QWidget *rightWidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QLabelHeader *hearderLabel;
    QLabel *nickNameLabel;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_7;
    QFrame *line_2;
    QPushButton *minBtn;
    QPushButton *maxBtn;
    QPushButton *closeBtn;
    QStackedWidget *contentStacked;
    QWidget *page;
    QWidget *statusBar;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;

    void setupUi(QWidget *IMMainWidget)
    {
        if (IMMainWidget->objectName().isEmpty())
            IMMainWidget->setObjectName(QStringLiteral("IMMainWidget"));
        IMMainWidget->resize(900, 630);
        IMMainWidget->setMinimumSize(QSize(900, 630));
        verticalLayout = new QVBoxLayout(IMMainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        titleBar = new QWidget(IMMainWidget);
        titleBar->setObjectName(QStringLiteral("titleBar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleBar->sizePolicy().hasHeightForWidth());
        titleBar->setSizePolicy(sizePolicy);
        titleBar->setMinimumSize(QSize(0, 56));
        titleBar->setMaximumSize(QSize(16777215, 56));
        horizontalLayout_2 = new QHBoxLayout(titleBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        leftWidget = new QWidget(titleBar);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftWidget->sizePolicy().hasHeightForWidth());
        leftWidget->setSizePolicy(sizePolicy1);
        leftWidget->setMinimumSize(QSize(200, 0));
        label = new QLabel(leftWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(12, 12, 128, 32));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(leftWidget);

        midWidget = new QWidget(titleBar);
        midWidget->setObjectName(QStringLiteral("midWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(midWidget->sizePolicy().hasHeightForWidth());
        midWidget->setSizePolicy(sizePolicy3);
        midWidget->setMinimumSize(QSize(0, 0));
        midWidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_4 = new QHBoxLayout(midWidget);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        messageBtn = new ToolButton(midWidget);
        messageBtn->setObjectName(QStringLiteral("messageBtn"));
        sizePolicy3.setHeightForWidth(messageBtn->sizePolicy().hasHeightForWidth());
        messageBtn->setSizePolicy(sizePolicy3);
        messageBtn->setCursor(QCursor(Qt::PointingHandCursor));
        messageBtn->setCheckable(true);
        messageBtn->setChecked(false);

        horizontalLayout_4->addWidget(messageBtn);

        contactsBtn = new ToolButton(midWidget);
        contactsBtn->setObjectName(QStringLiteral("contactsBtn"));
        sizePolicy3.setHeightForWidth(contactsBtn->sizePolicy().hasHeightForWidth());
        contactsBtn->setSizePolicy(sizePolicy3);
        contactsBtn->setCursor(QCursor(Qt::PointingHandCursor));
        contactsBtn->setCheckable(true);

        horizontalLayout_4->addWidget(contactsBtn);

        robotsBtn = new ToolButton(midWidget);
        robotsBtn->setObjectName(QStringLiteral("robotsBtn"));
        sizePolicy3.setHeightForWidth(robotsBtn->sizePolicy().hasHeightForWidth());
        robotsBtn->setSizePolicy(sizePolicy3);
        robotsBtn->setCursor(QCursor(Qt::PointingHandCursor));
        robotsBtn->setCheckable(true);

        horizontalLayout_4->addWidget(robotsBtn);

        walletBtn = new ToolButton(midWidget);
        walletBtn->setObjectName(QStringLiteral("walletBtn"));
        sizePolicy3.setHeightForWidth(walletBtn->sizePolicy().hasHeightForWidth());
        walletBtn->setSizePolicy(sizePolicy3);
        walletBtn->setCursor(QCursor(Qt::PointingHandCursor));
        walletBtn->setCheckable(true);

        horizontalLayout_4->addWidget(walletBtn);


        horizontalLayout_2->addWidget(midWidget);

        rightWidget = new QWidget(titleBar);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        sizePolicy3.setHeightForWidth(rightWidget->sizePolicy().hasHeightForWidth());
        rightWidget->setSizePolicy(sizePolicy3);
        rightWidget->setMinimumSize(QSize(320, 0));
        rightWidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_5 = new QHBoxLayout(rightWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(rightWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_8 = new QHBoxLayout(widget_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer_4 = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        hearderLabel = new QLabelHeader(widget_2);
        hearderLabel->setObjectName(QStringLiteral("hearderLabel"));
        sizePolicy2.setHeightForWidth(hearderLabel->sizePolicy().hasHeightForWidth());
        hearderLabel->setSizePolicy(sizePolicy2);
        hearderLabel->setMinimumSize(QSize(36, 36));
        hearderLabel->setMaximumSize(QSize(36, 36));
        hearderLabel->setCursor(QCursor(Qt::PointingHandCursor));
        hearderLabel->setScaledContents(true);

        horizontalLayout_8->addWidget(hearderLabel);

        nickNameLabel = new QLabel(widget_2);
        nickNameLabel->setObjectName(QStringLiteral("nickNameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        nickNameLabel->setFont(font);
        nickNameLabel->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_8->addWidget(nickNameLabel);


        horizontalLayout_5->addWidget(widget_2);

        widget_3 = new QWidget(rightWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_7 = new QHBoxLayout(widget_3);
        horizontalLayout_7->setSpacing(8);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, -1, -1);
        line_2 = new QFrame(widget_3);
        line_2->setObjectName(QStringLiteral("line_2"));
        sizePolicy2.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy2);
        line_2->setMinimumSize(QSize(20, 20));
        line_2->setMaximumSize(QSize(20, 20));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);

        horizontalLayout_7->addWidget(line_2);

        minBtn = new QPushButton(widget_3);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        sizePolicy2.setHeightForWidth(minBtn->sizePolicy().hasHeightForWidth());
        minBtn->setSizePolicy(sizePolicy2);
        minBtn->setMinimumSize(QSize(16, 16));
        minBtn->setMaximumSize(QSize(16, 16));
        minBtn->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(minBtn);

        maxBtn = new QPushButton(widget_3);
        maxBtn->setObjectName(QStringLiteral("maxBtn"));
        sizePolicy2.setHeightForWidth(maxBtn->sizePolicy().hasHeightForWidth());
        maxBtn->setSizePolicy(sizePolicy2);
        maxBtn->setMinimumSize(QSize(16, 16));
        maxBtn->setMaximumSize(QSize(16, 16));
        maxBtn->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(maxBtn);

        closeBtn = new QPushButton(widget_3);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        sizePolicy2.setHeightForWidth(closeBtn->sizePolicy().hasHeightForWidth());
        closeBtn->setSizePolicy(sizePolicy2);
        closeBtn->setMinimumSize(QSize(16, 16));
        closeBtn->setMaximumSize(QSize(16, 16));
        closeBtn->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(closeBtn);


        horizontalLayout_5->addWidget(widget_3);


        horizontalLayout_2->addWidget(rightWidget);


        verticalLayout->addWidget(titleBar);

        contentStacked = new QStackedWidget(IMMainWidget);
        contentStacked->setObjectName(QStringLiteral("contentStacked"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        contentStacked->addWidget(page);

        verticalLayout->addWidget(contentStacked);

        statusBar = new QWidget(IMMainWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy4);
        statusBar->setMinimumSize(QSize(0, 42));
        statusBar->setMaximumSize(QSize(16777215, 42));
        verticalLayout_2 = new QVBoxLayout(statusBar);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(statusBar);
        line->setObjectName(QStringLiteral("line"));
        sizePolicy4.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy4);
        line->setMinimumSize(QSize(0, 1));
        line->setMaximumSize(QSize(16777215, 1));
        line->setFrameShadow(QFrame::Raised);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_2->addWidget(line);

        statusWidget = new QWidget(statusBar);
        statusWidget->setObjectName(QStringLiteral("statusWidget"));
        sizePolicy3.setHeightForWidth(statusWidget->sizePolicy().hasHeightForWidth());
        statusWidget->setSizePolicy(sizePolicy3);
        statusWidget->setMinimumSize(QSize(0, 40));
        statusWidget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_6 = new QHBoxLayout(statusWidget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, 0, 0);
        statusLabel = new QLabel(statusWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(statusLabel->sizePolicy().hasHeightForWidth());
        statusLabel->setSizePolicy(sizePolicy5);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        statusLabel->setFont(font1);

        horizontalLayout_6->addWidget(statusLabel);

        horizontalSpacer_3 = new QSpacerItem(466, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        widget_4 = new QWidget(statusWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(200, 0));
        horizontalLayout_9 = new QHBoxLayout(widget_4);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(155, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy6);
        pushButton->setMinimumSize(QSize(44, 0));

        horizontalLayout_9->addWidget(pushButton);


        horizontalLayout_6->addWidget(widget_4);


        verticalLayout_2->addWidget(statusWidget);


        verticalLayout->addWidget(statusBar);


        retranslateUi(IMMainWidget);

        QMetaObject::connectSlotsByName(IMMainWidget);
    } // setupUi

    void retranslateUi(QWidget *IMMainWidget)
    {
        IMMainWidget->setWindowTitle(QString());
        label->setText(QString());
#ifndef QT_NO_TOOLTIP
        messageBtn->setToolTip(QApplication::translate("IMMainWidget", "\344\277\241\346\201\257", 0));
#endif // QT_NO_TOOLTIP
        messageBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        contactsBtn->setToolTip(QApplication::translate("IMMainWidget", "\350\201\224\347\263\273\344\272\272", 0));
#endif // QT_NO_TOOLTIP
        contactsBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        robotsBtn->setToolTip(QApplication::translate("IMMainWidget", "\346\234\272\345\231\250\344\272\272", 0));
#endif // QT_NO_TOOLTIP
        robotsBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        walletBtn->setToolTip(QApplication::translate("IMMainWidget", "\350\256\276\345\244\207", 0));
#endif // QT_NO_TOOLTIP
        walletBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        hearderLabel->setToolTip(QApplication::translate("IMMainWidget", "\344\277\256\346\224\271\350\265\204\346\226\231", 0));
#endif // QT_NO_TOOLTIP
        hearderLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        nickNameLabel->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        nickNameLabel->setText(QApplication::translate("IMMainWidget", "\345\271\263\345\217\260\347\240\224\345\217\221\351\203\250", 0));
#ifndef QT_NO_TOOLTIP
        minBtn->setToolTip(QApplication::translate("IMMainWidget", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        minBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        maxBtn->setToolTip(QApplication::translate("IMMainWidget", "\346\234\200\345\244\247\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        maxBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        closeBtn->setToolTip(QApplication::translate("IMMainWidget", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        closeBtn->setText(QString());
        statusLabel->setText(QApplication::translate("IMMainWidget", "\347\211\210\346\235\203\346\211\200\346\234\211 \302\251 \346\231\256\350\201\224\350\275\257\344\273\266\350\202\241\344\273\275\346\234\211\351\231\220\345\205\254\345\217\270", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IMMainWidget: public Ui_IMMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMMAINWIDGET_H
