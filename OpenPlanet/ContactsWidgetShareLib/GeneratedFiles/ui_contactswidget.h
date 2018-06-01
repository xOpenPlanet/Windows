/********************************************************************************
** Form generated from reading UI file 'contactswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTSWIDGET_H
#define UI_CONTACTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "groupprofilewidget.h"
#include "perprofilewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ContactsWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *tabsWidget;
    QVBoxLayout *verticalLayout;
    QWidget *searchWidget;
    QWidget *searchLineWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *searchLineEdit;
    QPushButton *searchBtn;
    QStackedWidget *contactsStackedWidget;
    QHBoxLayout *buttonsLayout;
    QFrame *separateLine;
    QWidget *dataWidget;
    QHBoxLayout *horizontalLayout;
    perProfileWidget *perWidget;
    GroupProfileWidget *groupWidget;

    void setupUi(QWidget *ContactsWidget)
    {
        if (ContactsWidget->objectName().isEmpty())
            ContactsWidget->setObjectName(QStringLiteral("ContactsWidget"));
        ContactsWidget->resize(882, 583);
        horizontalLayout_2 = new QHBoxLayout(ContactsWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabsWidget = new QWidget(ContactsWidget);
        tabsWidget->setObjectName(QStringLiteral("tabsWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabsWidget->sizePolicy().hasHeightForWidth());
        tabsWidget->setSizePolicy(sizePolicy);
        tabsWidget->setMinimumSize(QSize(200, 0));
        verticalLayout = new QVBoxLayout(tabsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        searchWidget = new QWidget(tabsWidget);
        searchWidget->setObjectName(QStringLiteral("searchWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(searchWidget->sizePolicy().hasHeightForWidth());
        searchWidget->setSizePolicy(sizePolicy1);
        searchWidget->setMinimumSize(QSize(0, 42));
        searchWidget->setMaximumSize(QSize(16777215, 42));
        searchLineWidget = new QWidget(searchWidget);
        searchLineWidget->setObjectName(QStringLiteral("searchLineWidget"));
        searchLineWidget->setGeometry(QRect(20, 10, 23, 22));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(searchLineWidget->sizePolicy().hasHeightForWidth());
        searchLineWidget->setSizePolicy(sizePolicy2);
        searchLineWidget->setMinimumSize(QSize(23, 22));
        searchLineWidget->setMaximumSize(QSize(1000, 22));
        horizontalLayout_3 = new QHBoxLayout(searchLineWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchLineEdit = new QLineEdit(searchLineWidget);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(searchLineEdit->sizePolicy().hasHeightForWidth());
        searchLineEdit->setSizePolicy(sizePolicy3);
        searchLineEdit->setMinimumSize(QSize(1, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        searchLineEdit->setFont(font);

        horizontalLayout_3->addWidget(searchLineEdit);

        searchBtn = new QPushButton(searchLineWidget);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(searchBtn->sizePolicy().hasHeightForWidth());
        searchBtn->setSizePolicy(sizePolicy4);
        searchBtn->setMinimumSize(QSize(22, 22));
        searchBtn->setMaximumSize(QSize(22, 22));
        searchBtn->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(searchBtn);


        verticalLayout->addWidget(searchWidget);

        contactsStackedWidget = new QStackedWidget(tabsWidget);
        contactsStackedWidget->setObjectName(QStringLiteral("contactsStackedWidget"));
        contactsStackedWidget->setStyleSheet(QStringLiteral("W"));

        verticalLayout->addWidget(contactsStackedWidget);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setSpacing(0);
        buttonsLayout->setObjectName(QStringLiteral("buttonsLayout"));

        verticalLayout->addLayout(buttonsLayout);


        horizontalLayout_2->addWidget(tabsWidget);

        separateLine = new QFrame(ContactsWidget);
        separateLine->setObjectName(QStringLiteral("separateLine"));
        separateLine->setMinimumSize(QSize(2, 0));
        separateLine->setMaximumSize(QSize(2, 16777215));
        separateLine->setCursor(QCursor(Qt::SizeHorCursor));
        separateLine->setFrameShadow(QFrame::Raised);
        separateLine->setLineWidth(0);
        separateLine->setFrameShape(QFrame::VLine);

        horizontalLayout_2->addWidget(separateLine);

        dataWidget = new QWidget(ContactsWidget);
        dataWidget->setObjectName(QStringLiteral("dataWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(dataWidget->sizePolicy().hasHeightForWidth());
        dataWidget->setSizePolicy(sizePolicy5);
        horizontalLayout = new QHBoxLayout(dataWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        perWidget = new perProfileWidget(dataWidget);
        perWidget->setObjectName(QStringLiteral("perWidget"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(perWidget->sizePolicy().hasHeightForWidth());
        perWidget->setSizePolicy(sizePolicy6);
        perWidget->setMinimumSize(QSize(340, 510));
        perWidget->setMaximumSize(QSize(340, 510));

        horizontalLayout->addWidget(perWidget);

        groupWidget = new GroupProfileWidget(dataWidget);
        groupWidget->setObjectName(QStringLiteral("groupWidget"));
        groupWidget->setMinimumSize(QSize(340, 510));
        groupWidget->setMaximumSize(QSize(340, 510));

        horizontalLayout->addWidget(groupWidget);


        horizontalLayout_2->addWidget(dataWidget);


        retranslateUi(ContactsWidget);

        QMetaObject::connectSlotsByName(ContactsWidget);
    } // setupUi

    void retranslateUi(QWidget *ContactsWidget)
    {
        ContactsWidget->setWindowTitle(QApplication::translate("ContactsWidget", "ContactsWidget", 0));
#ifndef QT_NO_TOOLTIP
        searchLineWidget->setToolTip(QApplication::translate("ContactsWidget", "\346\220\234\347\264\242", 0));
#endif // QT_NO_TOOLTIP
        searchLineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        searchBtn->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        searchBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContactsWidget: public Ui_ContactsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTSWIDGET_H
