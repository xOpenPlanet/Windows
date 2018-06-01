/********************************************************************************
** Form generated from reading UI file 'ewalletwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EWALLETWIDGET_H
#define UI_EWALLETWIDGET_H

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
#include "starflashwidget.h"

QT_BEGIN_NAMESPACE

class Ui_EWalletWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout;
    StarFlashWidget *starWidget;
    QWidget *tradeWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *gifLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *energyLabel;
    QWidget *turnWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *turnOutWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_7;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QWidget *turnInWidget;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_6;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QWidget *profileWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_14;
    QSpacerItem *verticalSpacer;
    QWidget *silverDiamondWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *silverDiamondLabel;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_5;
    QLabel *silverCountLabel;
    QSpacerItem *verticalSpacer_2;
    QWidget *blackDiamondWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *blackDiamondLabel;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *joinBtn;
    QSpacerItem *verticalSpacer_3;
    QWidget *codeWidget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_21;
    QSpacerItem *verticalSpacer_5;
    QWidget *safeWidget;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_22;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_23;
    QSpacerItem *verticalSpacer_4;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *EWalletWidget)
    {
        if (EWalletWidget->objectName().isEmpty())
            EWalletWidget->setObjectName(QStringLiteral("EWalletWidget"));
        EWalletWidget->resize(996, 659);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        EWalletWidget->setFont(font);
        EWalletWidget->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(EWalletWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftWidget = new QWidget(EWalletWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(280, 0));
        leftWidget->setMaximumSize(QSize(280, 16777215));
        leftWidget->setStyleSheet(QLatin1String("QWidget#leftWidget\n"
"{\n"
"background-color: #09192d;\n"
"}"));
        verticalLayout = new QVBoxLayout(leftWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        starWidget = new StarFlashWidget(leftWidget);
        starWidget->setObjectName(QStringLiteral("starWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(starWidget->sizePolicy().hasHeightForWidth());
        starWidget->setSizePolicy(sizePolicy);
        starWidget->setMinimumSize(QSize(0, 140));
        starWidget->setMaximumSize(QSize(16777215, 140));

        verticalLayout->addWidget(starWidget);

        tradeWidget = new QWidget(leftWidget);
        tradeWidget->setObjectName(QStringLiteral("tradeWidget"));
        sizePolicy.setHeightForWidth(tradeWidget->sizePolicy().hasHeightForWidth());
        tradeWidget->setSizePolicy(sizePolicy);
        tradeWidget->setMinimumSize(QSize(0, 76));
        tradeWidget->setMaximumSize(QSize(16777215, 76));
        tradeWidget->setStyleSheet(QLatin1String("QWidget#tradeWidget\n"
"{\n"
"background-color: #183457;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(tradeWidget);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(8, 8, 8, 8);
        gifLabel = new QLabel(tradeWidget);
        gifLabel->setObjectName(QStringLiteral("gifLabel"));
        gifLabel->setMinimumSize(QSize(60, 60));
        gifLabel->setMaximumSize(QSize(60, 60));
        gifLabel->setCursor(QCursor(Qt::PointingHandCursor));
        gifLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(gifLabel);

        widget = new QWidget(tradeWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("QWidget#label_2\n"
"{\n"
"color: #e4ba7b;\n"
"}"));

        verticalLayout_2->addWidget(label_2);

        energyLabel = new QLabel(widget);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));
        sizePolicy1.setHeightForWidth(energyLabel->sizePolicy().hasHeightForWidth());
        energyLabel->setSizePolicy(sizePolicy1);
        energyLabel->setFont(font1);
        energyLabel->setStyleSheet(QLatin1String("QWidget#energyLabel\n"
"{\n"
"color: #e4ba7b;\n"
"}"));
        energyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(energyLabel);


        horizontalLayout_2->addWidget(widget);


        verticalLayout->addWidget(tradeWidget);

        turnWidget = new QWidget(leftWidget);
        turnWidget->setObjectName(QStringLiteral("turnWidget"));
        sizePolicy.setHeightForWidth(turnWidget->sizePolicy().hasHeightForWidth());
        turnWidget->setSizePolicy(sizePolicy);
        turnWidget->setMinimumSize(QSize(0, 46));
        turnWidget->setMaximumSize(QSize(16777215, 46));
        turnWidget->setCursor(QCursor(Qt::PointingHandCursor));
        turnWidget->setStyleSheet(QLatin1String("QWidget#turnWidget\n"
"{\n"
"background-color: #183457;\n"
"border:none;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(turnWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        turnOutWidget = new QWidget(turnWidget);
        turnOutWidget->setObjectName(QStringLiteral("turnOutWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(turnOutWidget->sizePolicy().hasHeightForWidth());
        turnOutWidget->setSizePolicy(sizePolicy2);
        turnOutWidget->setStyleSheet(QLatin1String("QWidget#turnOutWidget\n"
"{\n"
"border: none;\n"
"border-top: 1px solid #4c6889;\n"
"border-bottom: 1px solid #4c6889;\n"
"margin-left: 10px;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(turnOutWidget);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalSpacer_11 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        label_7 = new QLabel(turnOutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(30, 30));
        label_7->setMaximumSize(QSize(30, 30));
        label_7->setStyleSheet(QLatin1String("QLabel#label_7\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/walletTurnOut.png);\n"
"}"));
        label_7->setScaledContents(true);

        horizontalLayout_4->addWidget(label_7);

        label_8 = new QLabel(turnOutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        label_8->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        label_8->setFont(font2);
        label_8->setStyleSheet(QLatin1String("QWidget#label_8\n"
"{\n"
"color: #e4ba7b;\n"
"}"));

        horizontalLayout_4->addWidget(label_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        line = new QFrame(turnOutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QLatin1String("QFrame#line\n"
"{\n"
"margin-top: 10px;\n"
"margin-bottom: 10px;\n"
"color: #4c6889;\n"
"}"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_4->addWidget(line);


        horizontalLayout_3->addWidget(turnOutWidget);

        turnInWidget = new QWidget(turnWidget);
        turnInWidget->setObjectName(QStringLiteral("turnInWidget"));
        sizePolicy2.setHeightForWidth(turnInWidget->sizePolicy().hasHeightForWidth());
        turnInWidget->setSizePolicy(sizePolicy2);
        turnInWidget->setStyleSheet(QLatin1String("QWidget#turnInWidget\n"
"{\n"
"border: none;\n"
"border-top: 1px solid #4c6889;\n"
"border-bottom: 1px solid #4c6889;\n"
"margin-right: 10px;\n"
"}"));
        horizontalLayout_9 = new QHBoxLayout(turnInWidget);
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        label_6 = new QLabel(turnInWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(30, 30));
        label_6->setMaximumSize(QSize(30, 30));
        label_6->setStyleSheet(QLatin1String("QLabel#label_6\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/walletTurnIn.png);\n"
"}"));
        label_6->setScaledContents(true);

        horizontalLayout_9->addWidget(label_6);

        label_9 = new QLabel(turnInWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setFont(font2);
        label_9->setStyleSheet(QLatin1String("QWidget#label_9\n"
"{\n"
"color: #e4ba7b;\n"
"}"));

        horizontalLayout_9->addWidget(label_9);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);


        horizontalLayout_3->addWidget(turnInWidget);


        verticalLayout->addWidget(turnWidget);

        profileWidget = new QWidget(leftWidget);
        profileWidget->setObjectName(QStringLiteral("profileWidget"));
        sizePolicy.setHeightForWidth(profileWidget->sizePolicy().hasHeightForWidth());
        profileWidget->setSizePolicy(sizePolicy);
        profileWidget->setMinimumSize(QSize(0, 46));
        profileWidget->setMaximumSize(QSize(16777215, 46));
        profileWidget->setCursor(QCursor(Qt::PointingHandCursor));
        profileWidget->setStyleSheet(QLatin1String("QWidget#profileWidget\n"
"{\n"
"background-color: #183457;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(profileWidget);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 5, 5, 5);
        label_12 = new QLabel(profileWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(24, 24));
        label_12->setMaximumSize(QSize(24, 24));
        label_12->setStyleSheet(QLatin1String("QLabel#label_12\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/profile.png);\n"
"}"));

        horizontalLayout_5->addWidget(label_12);

        label_13 = new QLabel(profileWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy3.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy3);
        label_13->setFont(font2);
        label_13->setStyleSheet(QLatin1String("QLabel#label_13\n"
"{\n"
"color: #4c6889;\n"
"}"));

        horizontalLayout_5->addWidget(label_13);

        horizontalSpacer_3 = new QSpacerItem(107, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_14 = new QLabel(profileWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(24, 24));
        label_14->setMaximumSize(QSize(24, 24));
        label_14->setStyleSheet(QLatin1String("QLabel#label_14\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/more.png);\n"
"}"));

        horizontalLayout_5->addWidget(label_14);


        verticalLayout->addWidget(profileWidget);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        silverDiamondWidget = new QWidget(leftWidget);
        silverDiamondWidget->setObjectName(QStringLiteral("silverDiamondWidget"));
        sizePolicy.setHeightForWidth(silverDiamondWidget->sizePolicy().hasHeightForWidth());
        silverDiamondWidget->setSizePolicy(sizePolicy);
        silverDiamondWidget->setMinimumSize(QSize(0, 56));
        silverDiamondWidget->setMaximumSize(QSize(16777215, 56));
        silverDiamondWidget->setStyleSheet(QLatin1String("QWidget#silverDiamondWidget\n"
"{\n"
"background-color: #183457;\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(silverDiamondWidget);
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, 5, 10, 5);
        silverDiamondLabel = new QLabel(silverDiamondWidget);
        silverDiamondLabel->setObjectName(QStringLiteral("silverDiamondLabel"));
        silverDiamondLabel->setMinimumSize(QSize(46, 46));
        silverDiamondLabel->setMaximumSize(QSize(46, 46));
        silverDiamondLabel->setStyleSheet(QStringLiteral(""));
        silverDiamondLabel->setPixmap(QPixmap(QString::fromUtf8(":/ewallet/Resources/ewallet/silverDiamond.png")));
        silverDiamondLabel->setScaledContents(true);

        horizontalLayout_6->addWidget(silverDiamondLabel);

        label_17 = new QLabel(silverDiamondWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy3.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy3);
        label_17->setFont(font2);
        label_17->setStyleSheet(QLatin1String("QLabel#label_17\n"
"{\n"
"color: #4c6889;\n"
"}"));

        horizontalLayout_6->addWidget(label_17);

        horizontalSpacer_5 = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        silverCountLabel = new QLabel(silverDiamondWidget);
        silverCountLabel->setObjectName(QStringLiteral("silverCountLabel"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        silverCountLabel->setFont(font3);
        silverCountLabel->setStyleSheet(QLatin1String("QLabel#silverCountLabel\n"
"{\n"
"color: #1277c2;\n"
"}"));

        horizontalLayout_6->addWidget(silverCountLabel);


        verticalLayout->addWidget(silverDiamondWidget);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        blackDiamondWidget = new QWidget(leftWidget);
        blackDiamondWidget->setObjectName(QStringLiteral("blackDiamondWidget"));
        sizePolicy.setHeightForWidth(blackDiamondWidget->sizePolicy().hasHeightForWidth());
        blackDiamondWidget->setSizePolicy(sizePolicy);
        blackDiamondWidget->setMinimumSize(QSize(0, 56));
        blackDiamondWidget->setMaximumSize(QSize(16777215, 56));
        blackDiamondWidget->setStyleSheet(QLatin1String("QWidget#blackDiamondWidget\n"
"{\n"
"background-color: #183457;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(blackDiamondWidget);
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(5, 5, 10, 5);
        blackDiamondLabel = new QLabel(blackDiamondWidget);
        blackDiamondLabel->setObjectName(QStringLiteral("blackDiamondLabel"));
        blackDiamondLabel->setMinimumSize(QSize(46, 46));
        blackDiamondLabel->setMaximumSize(QSize(46, 46));
        blackDiamondLabel->setStyleSheet(QStringLiteral(""));
        blackDiamondLabel->setPixmap(QPixmap(QString::fromUtf8(":/ewallet/Resources/ewallet/blackDiamond.png")));
        blackDiamondLabel->setScaledContents(true);

        horizontalLayout_7->addWidget(blackDiamondLabel);

        label_20 = new QLabel(blackDiamondWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        sizePolicy3.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy3);
        label_20->setFont(font2);
        label_20->setStyleSheet(QLatin1String("QLabel#label_20\n"
"{\n"
"color: #4c6889;\n"
"}"));

        horizontalLayout_7->addWidget(label_20);

        horizontalSpacer_6 = new QSpacerItem(136, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        joinBtn = new QPushButton(blackDiamondWidget);
        joinBtn->setObjectName(QStringLiteral("joinBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(joinBtn->sizePolicy().hasHeightForWidth());
        joinBtn->setSizePolicy(sizePolicy4);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        joinBtn->setFont(font4);
        joinBtn->setCursor(QCursor(Qt::PointingHandCursor));
        joinBtn->setStyleSheet(QLatin1String("QPushButton#joinBtn\n"
"{\n"
"border: none;\n"
"color: #1277c2;\n"
"}"));

        horizontalLayout_7->addWidget(joinBtn);


        verticalLayout->addWidget(blackDiamondWidget);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_3);

        codeWidget = new QWidget(leftWidget);
        codeWidget->setObjectName(QStringLiteral("codeWidget"));
        codeWidget->setMinimumSize(QSize(0, 46));
        codeWidget->setMaximumSize(QSize(16777215, 46));
        codeWidget->setCursor(QCursor(Qt::PointingHandCursor));
        codeWidget->setStyleSheet(QLatin1String("QWidget#codeWidget\n"
"{\n"
"background-color: #183457;\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(codeWidget);
        horizontalLayout_8->setSpacing(5);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(10, 5, 5, 5);
        label_16 = new QLabel(codeWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(24, 24));
        label_16->setMaximumSize(QSize(24, 24));
        label_16->setStyleSheet(QLatin1String("QLabel#label_16\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/code.png);\n"
"}"));

        horizontalLayout_8->addWidget(label_16);

        label_18 = new QLabel(codeWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy3.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy3);
        label_18->setFont(font2);
        label_18->setStyleSheet(QLatin1String("QLabel#label_18\n"
"{\n"
"color: #4c6889;\n"
"}"));

        horizontalLayout_8->addWidget(label_18);

        horizontalSpacer_7 = new QSpacerItem(145, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        label_21 = new QLabel(codeWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(24, 24));
        label_21->setMaximumSize(QSize(24, 24));
        label_21->setStyleSheet(QLatin1String("QLabel#label_21\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/more.png);\n"
"}"));

        horizontalLayout_8->addWidget(label_21);


        verticalLayout->addWidget(codeWidget);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        safeWidget = new QWidget(leftWidget);
        safeWidget->setObjectName(QStringLiteral("safeWidget"));
        safeWidget->setMinimumSize(QSize(0, 46));
        safeWidget->setMaximumSize(QSize(16777215, 46));
        safeWidget->setCursor(QCursor(Qt::PointingHandCursor));
        safeWidget->setStyleSheet(QLatin1String("QWidget#safeWidget\n"
"{\n"
"background-color: #183457;\n"
"}"));
        horizontalLayout_10 = new QHBoxLayout(safeWidget);
        horizontalLayout_10->setSpacing(5);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(10, 5, 5, 5);
        label_22 = new QLabel(safeWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(24, 24));
        label_22->setMaximumSize(QSize(24, 24));
        label_22->setStyleSheet(QLatin1String("QLabel#label_22\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/safe.png);\n"
"}"));

        horizontalLayout_10->addWidget(label_22);

        label_19 = new QLabel(safeWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy3.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy3);
        label_19->setFont(font2);
        label_19->setStyleSheet(QLatin1String("QLabel#label_19\n"
"{\n"
"color: #4c6889;\n"
"}"));

        horizontalLayout_10->addWidget(label_19);

        horizontalSpacer_12 = new QSpacerItem(147, 19, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);

        label_23 = new QLabel(safeWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(24, 24));
        label_23->setMaximumSize(QSize(24, 24));
        label_23->setStyleSheet(QLatin1String("QLabel#label_23\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/more.png);\n"
"}"));

        horizontalLayout_10->addWidget(label_23);


        verticalLayout->addWidget(safeWidget);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout->addWidget(leftWidget);

        stackedWidget = new QStackedWidget(EWalletWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: #042439;"));

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(EWalletWidget);

        QMetaObject::connectSlotsByName(EWalletWidget);
    } // setupUi

    void retranslateUi(QWidget *EWalletWidget)
    {
        EWalletWidget->setWindowTitle(QApplication::translate("EWalletWidget", "EWalletWidget", 0));
        gifLabel->setText(QString());
        label_2->setText(QApplication::translate("EWalletWidget", "\350\203\275\351\207\217", 0));
        energyLabel->setText(QApplication::translate("EWalletWidget", "0", 0));
        label_7->setText(QString());
        label_8->setText(QApplication::translate("EWalletWidget", "\350\275\254\345\207\272", 0));
        label_6->setText(QString());
        label_9->setText(QApplication::translate("EWalletWidget", "\350\275\254\345\205\245", 0));
        label_12->setText(QString());
        label_13->setText(QApplication::translate("EWalletWidget", "\344\272\244\346\230\223\346\230\216\347\273\206", 0));
        label_14->setText(QString());
        silverDiamondLabel->setText(QString());
        label_17->setText(QApplication::translate("EWalletWidget", "\351\223\266\351\222\273", 0));
        silverCountLabel->setText(QApplication::translate("EWalletWidget", "0", 0));
        blackDiamondLabel->setText(QString());
        label_20->setText(QApplication::translate("EWalletWidget", "\351\273\221\351\222\273", 0));
        joinBtn->setText(QApplication::translate("EWalletWidget", "\345\212\240\345\205\245IPCom\346\230\237\351\231\205\351\200\232\350\256\257\347\237\277\346\261\240", 0));
        label_16->setText(QString());
        label_18->setText(QApplication::translate("EWalletWidget", "\351\202\200\350\257\267\347\240\201", 0));
        label_21->setText(QString());
        label_22->setText(QString());
        label_19->setText(QApplication::translate("EWalletWidget", "\345\256\211\345\205\250\345\212\240\345\233\272", 0));
        label_23->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EWalletWidget: public Ui_EWalletWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EWALLETWIDGET_H
