/********************************************************************************
** Form generated from reading UI file 'secretletterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECRETLETTERWIDGET_H
#define UI_SECRETLETTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecretLetterWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *backWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *titleBarWidget;
    QLabel *label;
    QPushButton *closeBtn;
    QWidget *passwordWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_lock;
    QLineEdit *passwordEdit;
    QPlainTextEdit *letterEdit;
    QPushButton *enterBtn;

    void setupUi(QWidget *SecretLetterWidget)
    {
        if (SecretLetterWidget->objectName().isEmpty())
            SecretLetterWidget->setObjectName(QStringLiteral("SecretLetterWidget"));
        SecretLetterWidget->resize(300, 400);
        verticalLayout = new QVBoxLayout(SecretLetterWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        backWidget = new QWidget(SecretLetterWidget);
        backWidget->setObjectName(QStringLiteral("backWidget"));
        backWidget->setStyleSheet(QLatin1String("QWidget#backWidget\n"
"{\n"
"background-color: #08172c;\n"
"border-radius: 10px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(backWidget);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 10);
        titleBarWidget = new QWidget(backWidget);
        titleBarWidget->setObjectName(QStringLiteral("titleBarWidget"));
        titleBarWidget->setMinimumSize(QSize(0, 40));
        titleBarWidget->setStyleSheet(QStringLiteral(""));
        label = new QLabel(titleBarWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 10, 38, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: white;"));
        closeBtn = new QPushButton(titleBarWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(267, 7, 26, 26));
        closeBtn->setCursor(QCursor(Qt::PointingHandCursor));
        closeBtn->setStyleSheet(QLatin1String("QPushButton#closeBtn\n"
"{\n"
"border-image: url(:/Login/Resources/login/pclogin_title_close.png);\n"
"}\n"
"QPushButton#closeBtn:hover\n"
"{\n"
"border-image: url(:/Login/Resources/login/title_close_hover.png);\n"
"}"));

        verticalLayout_2->addWidget(titleBarWidget);

        passwordWidget = new QWidget(backWidget);
        passwordWidget->setObjectName(QStringLiteral("passwordWidget"));
        passwordWidget->setMinimumSize(QSize(0, 40));
        passwordWidget->setMaximumSize(QSize(16777215, 40));
        passwordWidget->setStyleSheet(QLatin1String("QWidget#passwordWidget\n"
"{\n"
"background-color: #162d4c;\n"
"border-radius: 5px;\n"
"margin-left: 10px;\n"
"margin-right: 10px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(passwordWidget);
        horizontalLayout->setSpacing(7);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(17, 7, 17, 7);
        label_lock = new QLabel(passwordWidget);
        label_lock->setObjectName(QStringLiteral("label_lock"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_lock->sizePolicy().hasHeightForWidth());
        label_lock->setSizePolicy(sizePolicy);
        label_lock->setMinimumSize(QSize(26, 26));
        label_lock->setMaximumSize(QSize(26, 26));
        label_lock->setStyleSheet(QStringLiteral("border-image: url(:/PerChat/Resources/person/lock.png);"));

        horizontalLayout->addWidget(label_lock);

        passwordEdit = new QLineEdit(passwordWidget);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        passwordEdit->setFont(font1);
        passwordEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"background-color: rgba(0,0,0, 0);\n"
"border: none;\n"
"color: white;\n"
"}"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(passwordEdit);


        verticalLayout_2->addWidget(passwordWidget);

        letterEdit = new QPlainTextEdit(backWidget);
        letterEdit->setObjectName(QStringLiteral("letterEdit"));
        letterEdit->setFont(font1);
        letterEdit->setStyleSheet(QLatin1String("QPlainTextEdit\n"
"{\n"
"margin-left: 10px;\n"
"margin-right: 10px;\n"
"padding: 5px;\n"
"border: none;\n"
"border-radius: 10px;\n"
"background-color: #0c1d37;\n"
"color: white;\n"
"}"));

        verticalLayout_2->addWidget(letterEdit);

        enterBtn = new QPushButton(backWidget);
        enterBtn->setObjectName(QStringLiteral("enterBtn"));
        enterBtn->setMinimumSize(QSize(0, 60));
        enterBtn->setFont(font1);
        enterBtn->setCursor(QCursor(Qt::PointingHandCursor));
        enterBtn->setStyleSheet(QLatin1String("QPushButton#enterBtn\n"
"{\n"
"color: white;\n"
"border: none;\n"
"background-color: #165da3;\n"
"border-radius: 4px;\n"
"\n"
"margin: 10 10 10 10;\n"
"}"));

        verticalLayout_2->addWidget(enterBtn);


        verticalLayout->addWidget(backWidget);


        retranslateUi(SecretLetterWidget);

        QMetaObject::connectSlotsByName(SecretLetterWidget);
    } // setupUi

    void retranslateUi(QWidget *SecretLetterWidget)
    {
        SecretLetterWidget->setWindowTitle(QApplication::translate("SecretLetterWidget", "SecretLetterWidget", 0));
        label->setText(QApplication::translate("SecretLetterWidget", "\345\257\206\344\277\241", 0));
        closeBtn->setText(QString());
        label_lock->setText(QString());
        passwordEdit->setPlaceholderText(QApplication::translate("SecretLetterWidget", "\350\276\223\345\205\245\345\257\206\347\240\201", 0));
        letterEdit->setPlainText(QString());
        letterEdit->setPlaceholderText(QApplication::translate("SecretLetterWidget", "\350\257\267\350\276\223\345\205\245\345\257\206\344\277\241\345\206\205\345\256\271", 0));
        enterBtn->setText(QApplication::translate("SecretLetterWidget", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class SecretLetterWidget: public Ui_SecretLetterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECRETLETTERWIDGET_H
