/********************************************************************************
** Form generated from reading UI file 'passwordwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDWIDGET_H
#define UI_PASSWORDWIDGET_H

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

class Ui_PasswordWidget
{
public:
    QWidget *backWidget;
    QVBoxLayout *verticalLayout;
    QWidget *topWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *topLabel;
    QPushButton *closeBtn;
    QWidget *midWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *enterBtn;

    void setupUi(QWidget *PasswordWidget)
    {
        if (PasswordWidget->objectName().isEmpty())
            PasswordWidget->setObjectName(QStringLiteral("PasswordWidget"));
        PasswordWidget->resize(300, 200);
        backWidget = new QWidget(PasswordWidget);
        backWidget->setObjectName(QStringLiteral("backWidget"));
        backWidget->setGeometry(QRect(0, 0, 300, 200));
        backWidget->setMinimumSize(QSize(300, 200));
        backWidget->setMaximumSize(QSize(300, 200));
        backWidget->setStyleSheet(QLatin1String("QWidget#backWidget\n"
"{\n"
"background-color: rgb(24,50,87);\n"
"border: none;\n"
"border-radius: 15px;\n"
"}"));
        verticalLayout = new QVBoxLayout(backWidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        topWidget = new QWidget(backWidget);
        topWidget->setObjectName(QStringLiteral("topWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topWidget->sizePolicy().hasHeightForWidth());
        topWidget->setSizePolicy(sizePolicy);
        topWidget->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0);"));
        horizontalLayout_2 = new QHBoxLayout(topWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        topLabel = new QLabel(topWidget);
        topLabel->setObjectName(QStringLiteral("topLabel"));
        sizePolicy.setHeightForWidth(topLabel->sizePolicy().hasHeightForWidth());
        topLabel->setSizePolicy(sizePolicy);
        topLabel->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        topLabel->setFont(font);
        topLabel->setStyleSheet(QLatin1String("QLabel#topLabel\n"
"{\n"
"color: #6a82a5;\n"
"background-color: rgba(0,0,0, 0);\n"
"}"));
        topLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(topLabel);

        closeBtn = new QPushButton(topWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(26, 26));
        closeBtn->setMaximumSize(QSize(26, 26));
        closeBtn->setCursor(QCursor(Qt::PointingHandCursor));
        closeBtn->setStyleSheet(QLatin1String("QPushButton#closeBtn\n"
"{\n"
"border-image: url(:/Login/Resources/login/pclogin_title_close.png);\n"
"}\n"
"QPushButton#closeBtn:hover\n"
"{\n"
"border-image: url(:/Login/Resources/login/title_close_hover.png);\n"
"}"));

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout->addWidget(topWidget);

        midWidget = new QWidget(backWidget);
        midWidget->setObjectName(QStringLiteral("midWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(midWidget->sizePolicy().hasHeightForWidth());
        midWidget->setSizePolicy(sizePolicy1);
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
        lineEdit = new QLineEdit(midWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
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
        lineEdit->setEchoMode(QLineEdit::Password);
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
"background-color: #165da3;\n"
"border-radius: 4px;\n"
"}"));

        verticalLayout->addWidget(enterBtn);


        retranslateUi(PasswordWidget);

        QMetaObject::connectSlotsByName(PasswordWidget);
    } // setupUi

    void retranslateUi(QWidget *PasswordWidget)
    {
        PasswordWidget->setWindowTitle(QApplication::translate("PasswordWidget", "PasswordWidget", 0));
        topLabel->setText(QApplication::translate("PasswordWidget", "\350\257\267\350\276\223\345\205\245\345\237\272\345\234\260\345\257\206\347\240\201", 0));
        closeBtn->setText(QString());
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        enterBtn->setText(QApplication::translate("PasswordWidget", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class PasswordWidget: public Ui_PasswordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDWIDGET_H
