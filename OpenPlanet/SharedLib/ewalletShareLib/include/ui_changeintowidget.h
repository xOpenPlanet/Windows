/********************************************************************************
** Form generated from reading UI file 'changeintowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINTOWIDGET_H
#define UI_CHANGEINTOWIDGET_H

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

QT_BEGIN_NAMESPACE

class Ui_ChangeIntoWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_1;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *codeLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *setNumBtn;
    QFrame *line;
    QWidget *recordWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *changeLabel;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextBtn;

    void setupUi(QWidget *ChangeIntoWidget)
    {
        if (ChangeIntoWidget->objectName().isEmpty())
            ChangeIntoWidget->setObjectName(QStringLiteral("ChangeIntoWidget"));
        ChangeIntoWidget->resize(751, 506);
        ChangeIntoWidget->setStyleSheet(QLatin1String("QWidget#ChangeIntoWidget\n"
"{\n"
"background-color: #042439;\n"
"}"));
        horizontalLayout = new QHBoxLayout(ChangeIntoWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mainWidget = new QWidget(ChangeIntoWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setMaximumSize(QSize(330, 400));
        mainWidget->setStyleSheet(QLatin1String("QWidget#mainWidget\n"
"{\n"
"background-color: #183257;\n"
"border-radius: 10px;\n"
"}\n"
"QLabel\n"
"{\n"
"background-color: #183257;\n"
"}"));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(15, 10, 15, 10);
        label_1 = new QLabel(mainWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setMinimumSize(QSize(0, 40));
        label_1->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_1->setFont(font);
        label_1->setStyleSheet(QLatin1String("QLabel#label_1\n"
"{\n"
"color: #6a82a5;\n"
"border: none;\n"
"}"));
        label_1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_1);

        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        codeLabel = new QLabel(mainWidget);
        codeLabel->setObjectName(QStringLiteral("codeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(codeLabel->sizePolicy().hasHeightForWidth());
        codeLabel->setSizePolicy(sizePolicy);
        codeLabel->setMinimumSize(QSize(190, 190));
        codeLabel->setMaximumSize(QSize(190, 190));
        codeLabel->setStyleSheet(QLatin1String("QLabel#codeLabel\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"padding: 10px;\n"
"}"));

        horizontalLayout_3->addWidget(codeLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        setNumBtn = new QPushButton(mainWidget);
        setNumBtn->setObjectName(QStringLiteral("setNumBtn"));
        setNumBtn->setMinimumSize(QSize(0, 60));
        setNumBtn->setMaximumSize(QSize(16777215, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        setNumBtn->setFont(font1);
        setNumBtn->setCursor(QCursor(Qt::PointingHandCursor));
        setNumBtn->setStyleSheet(QLatin1String("QPushButton#setNumBtn\n"
"{\n"
"background-color: #183257;\n"
"color: #108ee9;\n"
"border: none;\n"
"}"));

        verticalLayout->addWidget(setNumBtn);

        line = new QFrame(mainWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setStyleSheet(QLatin1String("QFrame#line\n"
"{\n"
"color: #6a82a5;\n"
"}"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

        recordWidget = new QWidget(mainWidget);
        recordWidget->setObjectName(QStringLiteral("recordWidget"));
        recordWidget->setMinimumSize(QSize(0, 60));
        recordWidget->setCursor(QCursor(Qt::PointingHandCursor));
        recordWidget->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color: #183257;\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(recordWidget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        changeLabel = new QLabel(recordWidget);
        changeLabel->setObjectName(QStringLiteral("changeLabel"));
        changeLabel->setMinimumSize(QSize(32, 32));
        changeLabel->setMaximumSize(QSize(32, 32));
        changeLabel->setStyleSheet(QLatin1String("QLabel#changeLabel\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/change.png);\n"
"}"));

        horizontalLayout_2->addWidget(changeLabel);

        label_5 = new QLabel(recordWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(13);
        label_5->setFont(font2);
        label_5->setStyleSheet(QLatin1String("QLabel#label_5\n"
"{\n"
"color: #6a82a5;\n"
"}"));

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        nextBtn = new QPushButton(recordWidget);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));
        nextBtn->setMinimumSize(QSize(28, 28));
        nextBtn->setMaximumSize(QSize(28, 28));
        nextBtn->setStyleSheet(QLatin1String("QPushButton#nextBtn\n"
"{\n"
"border-image: url(:/ewallet/Resources/ewallet/more.png);\n"
"}"));

        horizontalLayout_2->addWidget(nextBtn);


        verticalLayout->addWidget(recordWidget);


        horizontalLayout->addWidget(mainWidget);


        retranslateUi(ChangeIntoWidget);

        QMetaObject::connectSlotsByName(ChangeIntoWidget);
    } // setupUi

    void retranslateUi(QWidget *ChangeIntoWidget)
    {
        ChangeIntoWidget->setWindowTitle(QApplication::translate("ChangeIntoWidget", "ChangeIntoWidget", 0));
        label_1->setText(QApplication::translate("ChangeIntoWidget", "\346\211\253\346\217\217\344\272\214\347\273\264\347\240\201\350\277\233\350\241\214\350\203\275\351\207\217\344\272\244\346\215\242", 0));
        codeLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        setNumBtn->setToolTip(QApplication::translate("ChangeIntoWidget", "\350\256\276\347\275\256\344\272\244\346\230\223\346\225\260\351\207\217", 0));
#endif // QT_NO_TOOLTIP
        setNumBtn->setText(QApplication::translate("ChangeIntoWidget", "\350\256\276\347\275\256\344\272\244\346\230\223\346\225\260\351\207\217", 0));
#ifndef QT_NO_TOOLTIP
        recordWidget->setToolTip(QApplication::translate("ChangeIntoWidget", "\344\272\244\346\215\242\350\256\260\345\275\225", 0));
#endif // QT_NO_TOOLTIP
        changeLabel->setText(QString());
        label_5->setText(QApplication::translate("ChangeIntoWidget", "\344\272\244\346\215\242\350\256\260\345\275\225", 0));
        nextBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangeIntoWidget: public Ui_ChangeIntoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINTOWIDGET_H
