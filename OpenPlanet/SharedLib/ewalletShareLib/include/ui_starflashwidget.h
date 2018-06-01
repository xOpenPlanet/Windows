/********************************************************************************
** Form generated from reading UI file 'starflashwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARFLASHWIDGET_H
#define UI_STARFLASHWIDGET_H

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

class Ui_StarFlashWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *accountLabel;
    QLabel *refreshLabel;
    QWidget *topWidget;
    QVBoxLayout *verticalLayout_6;
    QLabel *idLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *addressLabel;
    QPushButton *copyBtn;
    QLabel *tipLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *buddysLabel;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *groupsLabel;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *StarFlashWidget)
    {
        if (StarFlashWidget->objectName().isEmpty())
            StarFlashWidget->setObjectName(QStringLiteral("StarFlashWidget"));
        StarFlashWidget->resize(280, 140);
        StarFlashWidget->setMinimumSize(QSize(0, 140));
        StarFlashWidget->setMaximumSize(QSize(16777215, 140));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        StarFlashWidget->setFont(font);
        StarFlashWidget->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color: white;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(StarFlashWidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, 5, 5, 8);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        accountLabel = new QLabel(StarFlashWidget);
        accountLabel->setObjectName(QStringLiteral("accountLabel"));
        accountLabel->setMinimumSize(QSize(0, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        accountLabel->setFont(font1);
        accountLabel->setStyleSheet(QLatin1String("QLabel#accountLabel\n"
"{\n"
"color: #1277c2;\n"
"}"));

        horizontalLayout_3->addWidget(accountLabel);

        refreshLabel = new QLabel(StarFlashWidget);
        refreshLabel->setObjectName(QStringLiteral("refreshLabel"));
        refreshLabel->setMinimumSize(QSize(30, 30));
        refreshLabel->setMaximumSize(QSize(30, 30));
        refreshLabel->setCursor(QCursor(Qt::PointingHandCursor));
        refreshLabel->setStyleSheet(QStringLiteral(""));
        refreshLabel->setScaledContents(true);

        horizontalLayout_3->addWidget(refreshLabel);


        verticalLayout_5->addLayout(horizontalLayout_3);

        topWidget = new QWidget(StarFlashWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topWidget->sizePolicy().hasHeightForWidth());
        topWidget->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(topWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        idLabel = new QLabel(topWidget);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        idLabel->setFont(font2);
        idLabel->setStyleSheet(QLatin1String("QLabel#idLabel\n"
"{\n"
"color: #44608a;\n"
"}"));
        idLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_6->addWidget(idLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addressLabel = new QLabel(topWidget);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));
        addressLabel->setMinimumSize(QSize(0, 24));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        addressLabel->setFont(font3);
        addressLabel->setStyleSheet(QLatin1String("QLabel#addressLabel\n"
"{\n"
"color: #44608a;\n"
"}"));
        addressLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(addressLabel);

        copyBtn = new QPushButton(topWidget);
        copyBtn->setObjectName(QStringLiteral("copyBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(copyBtn->sizePolicy().hasHeightForWidth());
        copyBtn->setSizePolicy(sizePolicy1);
        copyBtn->setMinimumSize(QSize(16, 16));
        copyBtn->setMaximumSize(QSize(16, 16));
        copyBtn->setCursor(QCursor(Qt::PointingHandCursor));
        copyBtn->setStyleSheet(QLatin1String("QPushButton#copyBtn\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/copy.png);\n"
"}\n"
"\n"
""));

        horizontalLayout->addWidget(copyBtn);

        tipLabel = new QLabel(topWidget);
        tipLabel->setObjectName(QStringLiteral("tipLabel"));
        tipLabel->setMinimumSize(QSize(0, 0));
        tipLabel->setMaximumSize(QSize(16777215, 22));
        tipLabel->setFont(font3);
        tipLabel->setStyleSheet(QLatin1String("QLabel#tipLabel\n"
"{\n"
"color: #44608a;\n"
"background-color: white;\n"
"border-radius: 4px;\n"
"padding: 0px 2px 0px 2px;\n"
"margin-left: 6px;\n"
"}\n"
""));

        horizontalLayout->addWidget(tipLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout);


        verticalLayout_5->addWidget(topWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        buddysLabel = new QLabel(StarFlashWidget);
        buddysLabel->setObjectName(QStringLiteral("buddysLabel"));
        buddysLabel->setFont(font2);
        buddysLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(buddysLabel);

        label_2 = new QLabel(StarFlashWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupsLabel = new QLabel(StarFlashWidget);
        groupsLabel->setObjectName(QStringLiteral("groupsLabel"));
        groupsLabel->setFont(font2);
        groupsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(groupsLabel);

        label_4 = new QLabel(StarFlashWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(StarFlashWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(StarFlashWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font3);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_7 = new QLabel(StarFlashWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(StarFlashWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_8);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_2);


        retranslateUi(StarFlashWidget);

        QMetaObject::connectSlotsByName(StarFlashWidget);
    } // setupUi

    void retranslateUi(QWidget *StarFlashWidget)
    {
        StarFlashWidget->setWindowTitle(QApplication::translate("StarFlashWidget", "StarFlashWidget", 0));
        accountLabel->setText(QApplication::translate("StarFlashWidget", "164953236", 0));
#ifndef QT_NO_TOOLTIP
        refreshLabel->setToolTip(QApplication::translate("StarFlashWidget", "\345\210\267\346\226\260", 0));
#endif // QT_NO_TOOLTIP
        refreshLabel->setText(QString());
        idLabel->setText(QApplication::translate("StarFlashWidget", "\346\230\237\351\231\205ID 190024", 0));
        addressLabel->setText(QApplication::translate("StarFlashWidget", "\345\237\272\345\234\260ID ", 0));
#ifndef QT_NO_TOOLTIP
        copyBtn->setToolTip(QApplication::translate("StarFlashWidget", "\345\244\215\345\210\266", 0));
#endif // QT_NO_TOOLTIP
        copyBtn->setText(QString());
        tipLabel->setText(QApplication::translate("StarFlashWidget", "\345\244\215\345\210\266\346\210\220\345\212\237", 0));
        buddysLabel->setText(QApplication::translate("StarFlashWidget", "0", 0));
        label_2->setText(QApplication::translate("StarFlashWidget", "\345\245\275\345\217\213", 0));
        groupsLabel->setText(QApplication::translate("StarFlashWidget", "0", 0));
        label_4->setText(QApplication::translate("StarFlashWidget", "\351\203\250\350\220\275", 0));
        label_5->setText(QApplication::translate("StarFlashWidget", "0", 0));
        label_6->setText(QApplication::translate("StarFlashWidget", "\351\202\200\350\257\267", 0));
        label_7->setText(QApplication::translate("StarFlashWidget", "0", 0));
        label_8->setText(QApplication::translate("StarFlashWidget", "\345\272\224\347\224\250", 0));
    } // retranslateUi

};

namespace Ui {
    class StarFlashWidget: public Ui_StarFlashWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARFLASHWIDGET_H
