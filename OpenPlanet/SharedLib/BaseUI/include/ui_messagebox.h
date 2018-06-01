/********************************************************************************
** Form generated from reading UI file 'messagebox.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEBOX_H
#define UI_MESSAGEBOX_H

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

class Ui_IMessageBox
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *icoLabel;
    QLabel *titleLabel;
    QPushButton *closeBtn;
    QWidget *contentWidget;
    QVBoxLayout *verticalLayout;
    QLabel *tipLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *enterBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *IMessageBox)
    {
        if (IMessageBox->objectName().isEmpty())
            IMessageBox->setObjectName(QStringLiteral("IMessageBox"));
        IMessageBox->resize(388, 153);
        IMessageBox->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(IMessageBox);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(IMessageBox);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleWidget->sizePolicy().hasHeightForWidth());
        titleWidget->setSizePolicy(sizePolicy);
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget\n"
"{\n"
"background-color: #042439; \n"
"\n"
"}"));
        horizontalLayout = new QHBoxLayout(titleWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        icoLabel = new QLabel(titleWidget);
        icoLabel->setObjectName(QStringLiteral("icoLabel"));
        icoLabel->setMinimumSize(QSize(24, 24));
        icoLabel->setMaximumSize(QSize(24, 24));
        icoLabel->setStyleSheet(QLatin1String("QLabel#icoLabel\n"
"{\n"
"border-image: url(:/Ico/Resources/logo/logo.ico);\n"
"}"));

        horizontalLayout->addWidget(icoLabel);

        titleLabel = new QLabel(titleWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QLatin1String("QLabel#titleLabel\n"
"{\n"
"color: #108ee9;\n"
"}"));

        horizontalLayout->addWidget(titleLabel);

        closeBtn = new QPushButton(titleWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(closeBtn->sizePolicy().hasHeightForWidth());
        closeBtn->setSizePolicy(sizePolicy1);
        closeBtn->setMinimumSize(QSize(24, 24));
        closeBtn->setMaximumSize(QSize(24, 24));
        closeBtn->setCursor(QCursor(Qt::PointingHandCursor));
        closeBtn->setStyleSheet(QLatin1String("QPushButton#closeBtn\n"
"{\n"
"border-image: url(:/Login/Resources/login/pclogin_title_close.png);\n"
"}\n"
"QPushButton#closeBtn:hover\n"
"{\n"
"border-image: url(:/Login/Resources/login/title_close_hover.png);\n"
"}"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout_2->addWidget(titleWidget);

        contentWidget = new QWidget(IMessageBox);
        contentWidget->setObjectName(QStringLiteral("contentWidget"));
        contentWidget->setStyleSheet(QLatin1String("QWidget#contentWidget\n"
"{\n"
"background-color: #153e70;\n"
"}"));
        verticalLayout = new QVBoxLayout(contentWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        tipLabel = new QLabel(contentWidget);
        tipLabel->setObjectName(QStringLiteral("tipLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tipLabel->sizePolicy().hasHeightForWidth());
        tipLabel->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        tipLabel->setFont(font1);
        tipLabel->setStyleSheet(QLatin1String("QLabel#tipLabel\n"
"{\n"
"color: #108ee9;\n"
"}"));
        tipLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(tipLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        enterBtn = new QPushButton(contentWidget);
        enterBtn->setObjectName(QStringLiteral("enterBtn"));
        sizePolicy1.setHeightForWidth(enterBtn->sizePolicy().hasHeightForWidth());
        enterBtn->setSizePolicy(sizePolicy1);
        enterBtn->setMinimumSize(QSize(76, 24));
        enterBtn->setFont(font1);
        enterBtn->setCursor(QCursor(Qt::PointingHandCursor));
        enterBtn->setStyleSheet(QLatin1String("QPushButton#enterBtn\n"
"{\n"
"background-color: #165ca3;\n"
"color: white;\n"
"border: none;\n"
"border-radius: 4px;\n"
"}\n"
"QPushButton#enterBtn:hover\n"
"{\n"
"color: #163e70;\n"
"}"));

        horizontalLayout_2->addWidget(enterBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(contentWidget);


        retranslateUi(IMessageBox);

        QMetaObject::connectSlotsByName(IMessageBox);
    } // setupUi

    void retranslateUi(QWidget *IMessageBox)
    {
        IMessageBox->setWindowTitle(QApplication::translate("IMessageBox", "MessageBox", 0));
        icoLabel->setText(QString());
        titleLabel->setText(QApplication::translate("IMessageBox", "\345\274\200\346\224\276\346\230\237\347\220\203", 0));
        closeBtn->setText(QString());
        tipLabel->setText(QApplication::translate("IMessageBox", "  \345\257\206\347\240\201\350\276\223\345\205\245\344\270\215\346\255\243\347\241\256\357\274\201", 0));
        enterBtn->setText(QApplication::translate("IMessageBox", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class IMessageBox: public Ui_IMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEBOX_H
