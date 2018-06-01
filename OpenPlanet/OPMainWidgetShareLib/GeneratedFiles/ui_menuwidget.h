/********************************************************************************
** Form generated from reading UI file 'menuwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGET_H
#define UI_MENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *profileBtn;
    QLabel *signLabel;
    QFrame *line;
    QWidget *btnWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *setBtn;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QFrame *line_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *MenuWidget)
    {
        if (MenuWidget->objectName().isEmpty())
            MenuWidget->setObjectName(QStringLiteral("MenuWidget"));
        MenuWidget->resize(164, 240);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        MenuWidget->setFont(font);
        verticalLayout_3 = new QVBoxLayout(MenuWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MenuWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        profileBtn = new QPushButton(widget);
        profileBtn->setObjectName(QStringLiteral("profileBtn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        profileBtn->setFont(font1);
        profileBtn->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(profileBtn);

        signLabel = new QLabel(widget);
        signLabel->setObjectName(QStringLiteral("signLabel"));
        signLabel->setFont(font);

        verticalLayout_2->addWidget(signLabel);


        verticalLayout_3->addWidget(widget);

        line = new QFrame(MenuWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_3->addWidget(line);

        btnWidget = new QWidget(MenuWidget);
        btnWidget->setObjectName(QStringLiteral("btnWidget"));
        btnWidget->setFont(font);
        verticalLayout = new QVBoxLayout(btnWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        setBtn = new QPushButton(btnWidget);
        setBtn->setObjectName(QStringLiteral("setBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(setBtn->sizePolicy().hasHeightForWidth());
        setBtn->setSizePolicy(sizePolicy);
        setBtn->setFont(font);

        verticalLayout->addWidget(setBtn);

        pushButton_2 = new QPushButton(btnWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font);

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(btnWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font);

        verticalLayout->addWidget(pushButton_4);

        line_2 = new QFrame(btnWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line_2);

        pushButton_5 = new QPushButton(btnWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(btnWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font);

        verticalLayout->addWidget(pushButton_6);


        verticalLayout_3->addWidget(btnWidget);


        retranslateUi(MenuWidget);

        QMetaObject::connectSlotsByName(MenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MenuWidget)
    {
        MenuWidget->setWindowTitle(QApplication::translate("MenuWidget", "MenuWidget", 0));
        profileBtn->setText(QApplication::translate("MenuWidget", "\345\260\217\346\275\230", 0));
        signLabel->setText(QApplication::translate("MenuWidget", "\345\220\233\345\255\220\344\270\215\347\253\213\344\272\216\345\215\261\345\242\231\344\271\213\344\270\213", 0));
        setBtn->setText(QApplication::translate("MenuWidget", "\350\256\276\347\275\256", 0));
        pushButton_2->setText(QApplication::translate("MenuWidget", "\346\215\242\350\202\244", 0));
        pushButton_4->setText(QApplication::translate("MenuWidget", "\346\266\210\346\201\257\347\256\241\347\220\206", 0));
        pushButton_5->setText(QApplication::translate("MenuWidget", "\345\210\207\346\215\242\345\270\220\345\217\267", 0));
        pushButton_6->setText(QApplication::translate("MenuWidget", "\351\200\200\345\207\272\345\270\220\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuWidget: public Ui_MenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
