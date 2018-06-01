/********************************************************************************
** Form generated from reading UI file 'userinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOWIDGET_H
#define UI_USERINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfoWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *iconLabel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *minBtn;
    QPushButton *quitBtn;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nickNameEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPlainTextEdit *signTextEdit;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *sexComboBox;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *phoneEdit;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *mailEdit;
    QWidget *widget6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveBtn;
    QPushButton *closeBtn;

    void setupUi(QWidget *UserInfoWidget)
    {
        if (UserInfoWidget->objectName().isEmpty())
            UserInfoWidget->setObjectName(QStringLiteral("UserInfoWidget"));
        UserInfoWidget->resize(300, 423);
        UserInfoWidget->setMinimumSize(QSize(300, 423));
        UserInfoWidget->setMaximumSize(QSize(300, 423));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        UserInfoWidget->setFont(font);
        verticalLayout = new QVBoxLayout(UserInfoWidget);
        verticalLayout->setSpacing(12);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 12);
        titleWidget = new QWidget(UserInfoWidget);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleWidget->sizePolicy().hasHeightForWidth());
        titleWidget->setSizePolicy(sizePolicy);
        titleWidget->setMinimumSize(QSize(0, 30));
        titleWidget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_7 = new QHBoxLayout(titleWidget);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(6, 0, 0, 0);
        iconLabel = new QLabel(titleWidget);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(iconLabel->sizePolicy().hasHeightForWidth());
        iconLabel->setSizePolicy(sizePolicy1);
        iconLabel->setMinimumSize(QSize(26, 26));
        iconLabel->setMaximumSize(QSize(26, 26));

        horizontalLayout_7->addWidget(iconLabel);

        horizontalSpacer_4 = new QSpacerItem(6, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        label_6 = new QLabel(titleWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_7->addWidget(label_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        minBtn = new QPushButton(titleWidget);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        minBtn->setMinimumSize(QSize(30, 30));
        minBtn->setMaximumSize(QSize(30, 30));

        horizontalLayout_7->addWidget(minBtn);

        quitBtn = new QPushButton(titleWidget);
        quitBtn->setObjectName(QStringLiteral("quitBtn"));
        quitBtn->setMinimumSize(QSize(30, 30));
        quitBtn->setMaximumSize(QSize(30, 30));

        horizontalLayout_7->addWidget(quitBtn);


        verticalLayout->addWidget(titleWidget);

        widget1 = new QWidget(UserInfoWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        sizePolicy.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(12, -1, 12, -1);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nickNameEdit = new QLineEdit(widget1);
        nickNameEdit->setObjectName(QStringLiteral("nickNameEdit"));

        horizontalLayout->addWidget(nickNameEdit);


        verticalLayout->addWidget(widget1);

        widget2 = new QWidget(UserInfoWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        sizePolicy.setHeightForWidth(widget2->sizePolicy().hasHeightForWidth());
        widget2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, -1, 12, -1);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        signTextEdit = new QPlainTextEdit(widget2);
        signTextEdit->setObjectName(QStringLiteral("signTextEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(signTextEdit->sizePolicy().hasHeightForWidth());
        signTextEdit->setSizePolicy(sizePolicy2);
        signTextEdit->setMinimumSize(QSize(0, 80));
        signTextEdit->setMaximumSize(QSize(16777215, 80));

        horizontalLayout_2->addWidget(signTextEdit);


        verticalLayout->addWidget(widget2);

        widget5 = new QWidget(UserInfoWidget);
        widget5->setObjectName(QStringLiteral("widget5"));
        sizePolicy.setHeightForWidth(widget5->sizePolicy().hasHeightForWidth());
        widget5->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(widget5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(12, -1, 12, -1);
        label_3 = new QLabel(widget5);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(label_3);

        sexComboBox = new QComboBox(widget5);
        sexComboBox->setObjectName(QStringLiteral("sexComboBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sexComboBox->sizePolicy().hasHeightForWidth());
        sexComboBox->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(sexComboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget5);

        widget4 = new QWidget(UserInfoWidget);
        widget4->setObjectName(QStringLiteral("widget4"));
        sizePolicy.setHeightForWidth(widget4->sizePolicy().hasHeightForWidth());
        widget4->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(widget4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(12, -1, 12, -1);
        label_4 = new QLabel(widget4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        phoneEdit = new QLineEdit(widget4);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        horizontalLayout_4->addWidget(phoneEdit);


        verticalLayout->addWidget(widget4);

        widget3 = new QWidget(UserInfoWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        sizePolicy.setHeightForWidth(widget3->sizePolicy().hasHeightForWidth());
        widget3->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(widget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(12, -1, 12, -1);
        label_5 = new QLabel(widget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        mailEdit = new QLineEdit(widget3);
        mailEdit->setObjectName(QStringLiteral("mailEdit"));

        horizontalLayout_5->addWidget(mailEdit);


        verticalLayout->addWidget(widget3);

        widget6 = new QWidget(UserInfoWidget);
        widget6->setObjectName(QStringLiteral("widget6"));
        sizePolicy.setHeightForWidth(widget6->sizePolicy().hasHeightForWidth());
        widget6->setSizePolicy(sizePolicy);
        horizontalLayout_6 = new QHBoxLayout(widget6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(12, 20, 12, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        saveBtn = new QPushButton(widget6);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setMinimumSize(QSize(75, 25));

        horizontalLayout_6->addWidget(saveBtn);

        closeBtn = new QPushButton(widget6);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(75, 25));

        horizontalLayout_6->addWidget(closeBtn);


        verticalLayout->addWidget(widget6);


        retranslateUi(UserInfoWidget);

        QMetaObject::connectSlotsByName(UserInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *UserInfoWidget)
    {
        UserInfoWidget->setWindowTitle(QApplication::translate("UserInfoWidget", "\347\274\226\350\276\221\350\265\204\346\226\231", 0));
        iconLabel->setText(QString());
        label_6->setText(QApplication::translate("UserInfoWidget", "\347\274\226\350\276\221\350\265\204\346\226\231", 0));
        minBtn->setText(QString());
        quitBtn->setText(QString());
        label->setText(QApplication::translate("UserInfoWidget", "\346\230\265  \347\247\260", 0));
        label_2->setText(QApplication::translate("UserInfoWidget", "\347\255\276  \345\220\215", 0));
        label_3->setText(QApplication::translate("UserInfoWidget", "\346\200\247  \345\210\253", 0));
        sexComboBox->clear();
        sexComboBox->insertItems(0, QStringList()
         << QApplication::translate("UserInfoWidget", "\347\224\267", 0)
         << QApplication::translate("UserInfoWidget", "\345\245\263", 0)
        );
        label_4->setText(QApplication::translate("UserInfoWidget", "\346\211\213  \346\234\272", 0));
        label_5->setText(QApplication::translate("UserInfoWidget", "\351\202\256  \347\256\261", 0));
        saveBtn->setText(QApplication::translate("UserInfoWidget", "\344\277\235\345\255\230", 0));
        closeBtn->setText(QApplication::translate("UserInfoWidget", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class UserInfoWidget: public Ui_UserInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOWIDGET_H
