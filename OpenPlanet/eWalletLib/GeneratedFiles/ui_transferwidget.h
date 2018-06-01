/********************************************************************************
** Form generated from reading UI file 'transferwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERWIDGET_H
#define UI_TRANSFERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferWidget
{
public:
    QHBoxLayout *horizontalLayout_7;
    QWidget *midWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLineEdit *IDEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *addressEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *valueEdit;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLabel *turnOutLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *energyLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *transBtn;

    void setupUi(QWidget *TransferWidget)
    {
        if (TransferWidget->objectName().isEmpty())
            TransferWidget->setObjectName(QStringLiteral("TransferWidget"));
        TransferWidget->resize(877, 554);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        TransferWidget->setFont(font);
        TransferWidget->setStyleSheet(QLatin1String("QWidget#TransferWidget\n"
"{\n"
"background-color: #042439;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(TransferWidget);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, -1);
        midWidget = new QWidget(TransferWidget);
        midWidget->setObjectName(QStringLiteral("midWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(midWidget->sizePolicy().hasHeightForWidth());
        midWidget->setSizePolicy(sizePolicy);
        midWidget->setMinimumSize(QSize(500, 360));
        midWidget->setMaximumSize(QSize(500, 360));
        midWidget->setFont(font);
        midWidget->setStyleSheet(QLatin1String("QWidget#midWidget\n"
"{\n"
"border-radius: 4px;\n"
"background-color: #15447c;\n"
"}\n"
"QLabel\n"
"{\n"
"background-color: #15447c;\n"
"}\n"
"QLineEdit\n"
"{\n"
"border: 1px solid #6a82a5;\n"
"border-radius: 4px;\n"
"background-color: #15447c;\n"
"color: white;\n"
"padding-left: 4px;\n"
"line-height: 28px;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"border-color: white;\n"
"}"));
        verticalLayout = new QVBoxLayout(midWidget);
        verticalLayout->setSpacing(16);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(32, 32, 32, 32);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_1 = new QLabel(midWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setMinimumSize(QSize(90, 0));
        label_1->setFont(font);
        label_1->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout->addWidget(label_1);

        IDEdit = new QLineEdit(midWidget);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));
        IDEdit->setMinimumSize(QSize(0, 28));
        IDEdit->setMaximumSize(QSize(16777215, 16777215));
        IDEdit->setFont(font);
        IDEdit->setContextMenuPolicy(Qt::NoContextMenu);
        IDEdit->setStyleSheet(QStringLiteral(""));
        IDEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        IDEdit->setClearButtonEnabled(false);

        horizontalLayout->addWidget(IDEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(midWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(90, 0));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout_2->addWidget(label_2);

        addressEdit = new QLineEdit(midWidget);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        addressEdit->setMinimumSize(QSize(0, 28));
        addressEdit->setFont(font);
        addressEdit->setContextMenuPolicy(Qt::NoContextMenu);
        addressEdit->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(addressEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(midWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(90, 0));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout_3->addWidget(label_3);

        valueEdit = new QLineEdit(midWidget);
        valueEdit->setObjectName(QStringLiteral("valueEdit"));
        valueEdit->setMinimumSize(QSize(0, 28));
        valueEdit->setFont(font);
        valueEdit->setContextMenuPolicy(Qt::NoContextMenu);
        valueEdit->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(valueEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(midWidget);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setStyleSheet(QLatin1String("QFrame#line\n"
"{\n"
"color: #6a82a5;\n"
"border-left: none;\n"
"border-right: none;\n"
"border-bottom: none;\n"
"background-color: rgba(0,0,0, 0);\n"
"}"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(midWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        turnOutLabel = new QLabel(midWidget);
        turnOutLabel->setObjectName(QStringLiteral("turnOutLabel"));
        turnOutLabel->setFont(font);
        turnOutLabel->setStyleSheet(QLatin1String("QLabel#turnOutLabel\n"
"{\n"
"color: #6a82a5;\n"
"}"));
        turnOutLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(turnOutLabel);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(midWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QStringLiteral("color: #6a82a5;"));

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        energyLabel = new QLabel(midWidget);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));
        energyLabel->setFont(font);
        energyLabel->setStyleSheet(QStringLiteral("color: #face80;"));
        energyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(energyLabel);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        transBtn = new QPushButton(midWidget);
        transBtn->setObjectName(QStringLiteral("transBtn"));
        sizePolicy.setHeightForWidth(transBtn->sizePolicy().hasHeightForWidth());
        transBtn->setSizePolicy(sizePolicy);
        transBtn->setMinimumSize(QSize(141, 33));
        transBtn->setMaximumSize(QSize(141, 33));
        transBtn->setFont(font);
        transBtn->setCursor(QCursor(Qt::PointingHandCursor));
        transBtn->setStyleSheet(QLatin1String("QPushButton#transBtn\n"
"{\n"
"color: white;\n"
"background-color: #165da3;\n"
"border: none;\n"
"border-radius: 5px;\n"
"}\n"
"QPushButton#transBtn:hover\n"
"{\n"
"color: #0a182d;\n"
"}"));

        horizontalLayout_6->addWidget(transBtn);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_7->addWidget(midWidget);


        retranslateUi(TransferWidget);

        QMetaObject::connectSlotsByName(TransferWidget);
    } // setupUi

    void retranslateUi(QWidget *TransferWidget)
    {
        TransferWidget->setWindowTitle(QApplication::translate("TransferWidget", "TransferWidget", 0));
        label_1->setText(QApplication::translate("TransferWidget", "\346\216\245\346\224\266\346\230\237\351\231\205ID", 0));
        IDEdit->setInputMask(QString());
        IDEdit->setPlaceholderText(QApplication::translate("TransferWidget", "\350\257\267\350\276\223\345\205\245\345\257\271\346\226\271\350\264\246\345\217\267", 0));
        label_2->setText(QApplication::translate("TransferWidget", "\346\216\245\346\224\266\345\237\272\345\234\260ID", 0));
        addressEdit->setPlaceholderText(QApplication::translate("TransferWidget", "\350\257\267\350\276\223\345\205\245\345\257\271\346\226\271\351\222\261\345\214\205\345\234\260\345\235\200", 0));
        label_3->setText(QApplication::translate("TransferWidget", "\350\275\254\345\207\272\350\203\275\351\207\217", 0));
        valueEdit->setPlaceholderText(QApplication::translate("TransferWidget", "\350\257\267\350\276\223\345\205\245\350\203\275\351\207\217\346\225\260\351\207\217", 0));
        label_4->setText(QApplication::translate("TransferWidget", "\350\275\254\345\207\272\345\237\272\345\234\260ID", 0));
        turnOutLabel->setText(QString());
        label_5->setText(QApplication::translate("TransferWidget", "\350\203\275\351\207\217\344\275\231\351\242\235", 0));
        energyLabel->setText(QApplication::translate("TransferWidget", "0", 0));
        transBtn->setText(QApplication::translate("TransferWidget", "\350\203\275\351\207\217\344\272\244\346\215\242", 0));
    } // retranslateUi

};

namespace Ui {
    class TransferWidget: public Ui_TransferWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERWIDGET_H
