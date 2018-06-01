/********************************************************************************
** Form generated from reading UI file 'changenumwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGENUMWIDGET_H
#define UI_CHANGENUMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeNumWidget
{
public:
    QWidget *backWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_1;
    QWidget *midWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *coinLabel;
    QLineEdit *lineEdit;
    QPushButton *enterBtn;

    void setupUi(QWidget *ChangeNumWidget)
    {
        if (ChangeNumWidget->objectName().isEmpty())
            ChangeNumWidget->setObjectName(QStringLiteral("ChangeNumWidget"));
        ChangeNumWidget->resize(300, 200);
        ChangeNumWidget->setStyleSheet(QLatin1String("QWidget#ChangeNumWidget\n"
"{\n"
"background-color: rgba(0,0,0,0);\n"
"}"));
        backWidget = new QWidget(ChangeNumWidget);
        backWidget->setObjectName(QStringLiteral("backWidget"));
        backWidget->setGeometry(QRect(0, 0, 300, 200));
        backWidget->setStyleSheet(QLatin1String("QWidget#backWidget\n"
"{\n"
"background-color: #15447c;\n"
"border: none;\n"
"border-radius: 15px;\n"
"}"));
        verticalLayout = new QVBoxLayout(backWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        label_1 = new QLabel(backWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy);
        label_1->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label_1->setFont(font);
        label_1->setStyleSheet(QLatin1String("QLabel#label_1\n"
"{\n"
"color: #6a82a5;\n"
"background-color: rgba(0,0,0, 0);\n"
"}"));
        label_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_1);

        midWidget = new QWidget(backWidget);
        midWidget->setObjectName(QStringLiteral("midWidget"));
        sizePolicy.setHeightForWidth(midWidget->sizePolicy().hasHeightForWidth());
        midWidget->setSizePolicy(sizePolicy);
        midWidget->setStyleSheet(QLatin1String("QWidget#midWidget\n"
"{\n"
"background-color: rgba(0,0,0, 0);\n"
"border: none;\n"
"border-bottom: 1px solid #6a82a5;\n"
"}"));
        horizontalLayout = new QHBoxLayout(midWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        coinLabel = new QLabel(midWidget);
        coinLabel->setObjectName(QStringLiteral("coinLabel"));
        coinLabel->setMinimumSize(QSize(40, 40));
        coinLabel->setMaximumSize(QSize(40, 40));
        coinLabel->setStyleSheet(QLatin1String("QLabel#coinLabel\n"
"{\n"
"background-color: rgba(0,0,0,0);\n"
"border-image: url(:/ewallet/Resources/ewallet/balance.png);\n"
"}"));

        horizontalLayout->addWidget(coinLabel);

        lineEdit = new QLineEdit(midWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        lineEdit->setFont(font1);
        lineEdit->setContextMenuPolicy(Qt::NoContextMenu);
        lineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"border: none;\n"
"color: white;\n"
"background-color: rgba(0,0,0, 0);\n"
"}"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addWidget(midWidget);

        enterBtn = new QPushButton(backWidget);
        enterBtn->setObjectName(QStringLiteral("enterBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(enterBtn->sizePolicy().hasHeightForWidth());
        enterBtn->setSizePolicy(sizePolicy2);
        enterBtn->setFont(font);
        enterBtn->setCursor(QCursor(Qt::PointingHandCursor));
        enterBtn->setStyleSheet(QLatin1String("QPushButton#enterBtn\n"
"{\n"
"color: white;\n"
"border: none;\n"
"background-color: #108ee9;\n"
"border-radius: 4px;\n"
"}"));

        verticalLayout->addWidget(enterBtn);


        retranslateUi(ChangeNumWidget);

        QMetaObject::connectSlotsByName(ChangeNumWidget);
    } // setupUi

    void retranslateUi(QWidget *ChangeNumWidget)
    {
        ChangeNumWidget->setWindowTitle(QApplication::translate("ChangeNumWidget", "ChangeNumWidget", 0));
        label_1->setText(QApplication::translate("ChangeNumWidget", "\344\272\244\346\215\242\346\225\260\351\207\217", 0));
        coinLabel->setText(QString());
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        enterBtn->setText(QApplication::translate("ChangeNumWidget", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ChangeNumWidget: public Ui_ChangeNumWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGENUMWIDGET_H
