/********************************************************************************
** Form generated from reading UI file 'perprofilewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERPROFILEWIDGET_H
#define UI_PERPROFILEWIDGET_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qlabelheader.h"

QT_BEGIN_NAMESPACE

class Ui_perProfileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QLabelHeader *headerLabel;
    QLabel *starLabel;
    QWidget *nickWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nameLabel;
    QLabel *sexLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *signLabel;
    QWidget *spaceWidget;
    QWidget *midwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLabel *lianxinLabel;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *addressLabel;
    QPushButton *copyAddressBtn;
    QWidget *bottomWidget;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *perChatBtn;

    void setupUi(QWidget *perProfileWidget)
    {
        if (perProfileWidget->objectName().isEmpty())
            perProfileWidget->setObjectName(QStringLiteral("perProfileWidget"));
        perProfileWidget->resize(340, 510);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(perProfileWidget->sizePolicy().hasHeightForWidth());
        perProfileWidget->setSizePolicy(sizePolicy);
        perProfileWidget->setMinimumSize(QSize(340, 510));
        perProfileWidget->setMaximumSize(QSize(16777215, 16777215));
        perProfileWidget->setStyleSheet(QLatin1String("QWidget#perProfileWidget\n"
"{\n"
"background-color: #0b1d37;\n"
"}"));
        verticalLayout = new QVBoxLayout(perProfileWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topWidget = new QWidget(perProfileWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topWidget->sizePolicy().hasHeightForWidth());
        topWidget->setSizePolicy(sizePolicy1);
        topWidget->setMinimumSize(QSize(0, 240));
        topWidget->setMaximumSize(QSize(16777215, 240));
        topWidget->setStyleSheet(QStringLiteral(""));
        headerLabel = new QLabelHeader(topWidget);
        headerLabel->setObjectName(QStringLiteral("headerLabel"));
        headerLabel->setGeometry(QRect(20, 105, 60, 60));
        headerLabel->setMinimumSize(QSize(60, 60));
        headerLabel->setMaximumSize(QSize(60, 60));
        headerLabel->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0);\n"
""));
        starLabel = new QLabel(topWidget);
        starLabel->setObjectName(QStringLiteral("starLabel"));
        starLabel->setGeometry(QRect(0, 0, 340, 135));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(starLabel->sizePolicy().hasHeightForWidth());
        starLabel->setSizePolicy(sizePolicy2);
        starLabel->setMinimumSize(QSize(0, 135));
        starLabel->setMaximumSize(QSize(16777215, 135));
        starLabel->setStyleSheet(QStringLiteral(""));
        starLabel->setScaledContents(true);
        nickWidget = new QWidget(topWidget);
        nickWidget->setObjectName(QStringLiteral("nickWidget"));
        nickWidget->setGeometry(QRect(0, 135, 340, 105));
        nickWidget->setStyleSheet(QStringLiteral("background-color: #173156;"));
        verticalLayout_2 = new QVBoxLayout(nickWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(25, 5, 25, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(nickWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 36));
        label->setStyleSheet(QStringLiteral("border-image: url(:/Mine/Resources/mine/space.png);"));

        horizontalLayout_3->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        nameLabel = new QLabel(nickWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setMinimumSize(QSize(0, 28));
        nameLabel->setMaximumSize(QSize(16777215, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        nameLabel->setFont(font);
        nameLabel->setStyleSheet(QStringLiteral("color: #108fe9;"));

        horizontalLayout_4->addWidget(nameLabel);

        sexLabel = new QLabel(nickWidget);
        sexLabel->setObjectName(QStringLiteral("sexLabel"));
        sexLabel->setMinimumSize(QSize(20, 20));
        sexLabel->setMaximumSize(QSize(20, 20));
        sexLabel->setScaledContents(true);

        horizontalLayout_4->addWidget(sexLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        signLabel = new QLabel(nickWidget);
        signLabel->setObjectName(QStringLiteral("signLabel"));
        signLabel->setMinimumSize(QSize(0, 28));
        signLabel->setMaximumSize(QSize(16777215, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        signLabel->setFont(font1);
        signLabel->setStyleSheet(QStringLiteral("color: #6a82a5;"));
        signLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(signLabel);

        starLabel->raise();
        nickWidget->raise();
        headerLabel->raise();

        verticalLayout->addWidget(topWidget);

        spaceWidget = new QWidget(perProfileWidget);
        spaceWidget->setObjectName(QStringLiteral("spaceWidget"));
        sizePolicy1.setHeightForWidth(spaceWidget->sizePolicy().hasHeightForWidth());
        spaceWidget->setSizePolicy(sizePolicy1);
        spaceWidget->setMinimumSize(QSize(0, 10));
        spaceWidget->setMaximumSize(QSize(16777215, 10));
        spaceWidget->setStyleSheet(QStringLiteral("background-color: #0b1d37;"));

        verticalLayout->addWidget(spaceWidget);

        midwidget = new QWidget(perProfileWidget);
        midwidget->setObjectName(QStringLiteral("midwidget"));
        sizePolicy1.setHeightForWidth(midwidget->sizePolicy().hasHeightForWidth());
        midwidget->setSizePolicy(sizePolicy1);
        midwidget->setMinimumSize(QSize(0, 90));
        midwidget->setMaximumSize(QSize(16777215, 90));
        midwidget->setStyleSheet(QLatin1String("QWidget#midwidget\n"
"{\n"
"background-color: #173156;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(midwidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(25, 0, 25, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(midwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setMinimumSize(QSize(90, 0));
        label_7->setMaximumSize(QSize(50, 16777215));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout->addWidget(label_7);

        lianxinLabel = new QLabel(midwidget);
        lianxinLabel->setObjectName(QStringLiteral("lianxinLabel"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        lianxinLabel->setFont(font2);
        lianxinLabel->setStyleSheet(QStringLiteral("color: #108fe9;"));

        horizontalLayout->addWidget(lianxinLabel);


        verticalLayout_4->addLayout(horizontalLayout);

        line = new QFrame(midwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QStringLiteral("color: #6a82a5;"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_4->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(midwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMinimumSize(QSize(90, 0));
        label_6->setMaximumSize(QSize(50, 16777215));
        label_6->setFont(font);
        label_6->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout_2->addWidget(label_6);

        addressLabel = new QLabel(midwidget);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));
        addressLabel->setFont(font2);
        addressLabel->setStyleSheet(QStringLiteral("color: #108fe9;"));

        horizontalLayout_2->addWidget(addressLabel);

        copyAddressBtn = new QPushButton(midwidget);
        copyAddressBtn->setObjectName(QStringLiteral("copyAddressBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(copyAddressBtn->sizePolicy().hasHeightForWidth());
        copyAddressBtn->setSizePolicy(sizePolicy4);
        copyAddressBtn->setMinimumSize(QSize(16, 16));
        copyAddressBtn->setMaximumSize(QSize(16, 16));
        copyAddressBtn->setCursor(QCursor(Qt::PointingHandCursor));
        copyAddressBtn->setStyleSheet(QLatin1String("QPushButton#copyAddressBtn\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/copy.png);\n"
"}\n"
"\n"
""));

        horizontalLayout_2->addWidget(copyAddressBtn);


        verticalLayout_4->addLayout(horizontalLayout_2);

        line->raise();

        verticalLayout->addWidget(midwidget);

        bottomWidget = new QWidget(perProfileWidget);
        bottomWidget->setObjectName(QStringLiteral("bottomWidget"));
        sizePolicy1.setHeightForWidth(bottomWidget->sizePolicy().hasHeightForWidth());
        bottomWidget->setSizePolicy(sizePolicy1);
        bottomWidget->setMaximumSize(QSize(16777215, 200));
        bottomWidget->setStyleSheet(QLatin1String("QWidget#bottomWidget\n"
"{\n"
"background-color: #0b1d37;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(bottomWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(25, -1, 25, 20);
        verticalSpacer_2 = new QSpacerItem(20, 117, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        perChatBtn = new QPushButton(bottomWidget);
        perChatBtn->setObjectName(QStringLiteral("perChatBtn"));
        perChatBtn->setMinimumSize(QSize(0, 40));
        perChatBtn->setFont(font);
        perChatBtn->setCursor(QCursor(Qt::PointingHandCursor));
        perChatBtn->setStyleSheet(QLatin1String("QPushButton#perChatBtn\n"
"{\n"
"background-color: #108ee9;\n"
"border: none;\n"
"border-radius: 18px;\n"
"color: white;\n"
"}"));

        verticalLayout_3->addWidget(perChatBtn);


        verticalLayout->addWidget(bottomWidget);


        retranslateUi(perProfileWidget);

        QMetaObject::connectSlotsByName(perProfileWidget);
    } // setupUi

    void retranslateUi(QWidget *perProfileWidget)
    {
        perProfileWidget->setWindowTitle(QApplication::translate("perProfileWidget", "perProfileWidget", 0));
#ifndef QT_NO_TOOLTIP
        headerLabel->setToolTip(QApplication::translate("perProfileWidget", "\345\245\275\345\217\213\345\244\264\345\203\217", 0));
#endif // QT_NO_TOOLTIP
        headerLabel->setText(QString());
        starLabel->setText(QString());
        label->setText(QString());
        nameLabel->setText(QApplication::translate("perProfileWidget", "song12", 0));
        sexLabel->setText(QString());
        signLabel->setText(QApplication::translate("perProfileWidget", "\345\220\203\351\245\255\344\272\206\346\262\241", 0));
        label_7->setText(QApplication::translate("perProfileWidget", "\346\230\237\351\231\205ID", 0));
        lianxinLabel->setText(QApplication::translate("perProfileWidget", "192201", 0));
        label_6->setText(QApplication::translate("perProfileWidget", "\345\237\272\345\234\260ID", 0));
        addressLabel->setText(QApplication::translate("perProfileWidget", "0xdstdwqfwqdf", 0));
#ifndef QT_NO_TOOLTIP
        copyAddressBtn->setToolTip(QApplication::translate("perProfileWidget", "\345\244\215\345\210\266", 0));
#endif // QT_NO_TOOLTIP
        copyAddressBtn->setText(QString());
        perChatBtn->setText(QApplication::translate("perProfileWidget", "\345\217\221\351\200\201\346\266\210\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class perProfileWidget: public Ui_perProfileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERPROFILEWIDGET_H
