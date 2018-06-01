/********************************************************************************
** Form generated from reading UI file 'groupwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPWIDGET_H
#define UI_GROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupWidget
{
public:
    QLabel *mGroupLabelBK;
    QPushButton *mPButtonGroupSpace;
    QLabel *mLabelGroupNickChat;
    QStackedWidget *mGroupStackedWidget;
    QToolButton *mTButtonGroupFile;

    void setupUi(QWidget *GroupWidget)
    {
        if (GroupWidget->objectName().isEmpty())
            GroupWidget->setObjectName(QStringLiteral("GroupWidget"));
        GroupWidget->resize(630, 600);
        mGroupLabelBK = new QLabel(GroupWidget);
        mGroupLabelBK->setObjectName(QStringLiteral("mGroupLabelBK"));
        mGroupLabelBK->setGeometry(QRect(1, 0, 629, 67));
        mPButtonGroupSpace = new QPushButton(GroupWidget);
        mPButtonGroupSpace->setObjectName(QStringLiteral("mPButtonGroupSpace"));
        mPButtonGroupSpace->setGeometry(QRect(20, 45, 20, 20));
        mLabelGroupNickChat = new QLabel(GroupWidget);
        mLabelGroupNickChat->setObjectName(QStringLiteral("mLabelGroupNickChat"));
        mLabelGroupNickChat->setGeometry(QRect(20, 8, 300, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        mLabelGroupNickChat->setFont(font);
        mGroupStackedWidget = new QStackedWidget(GroupWidget);
        mGroupStackedWidget->setObjectName(QStringLiteral("mGroupStackedWidget"));
        mGroupStackedWidget->setGeometry(QRect(0, 111, 629, 489));
        mTButtonGroupFile = new QToolButton(GroupWidget);
        mTButtonGroupFile->setObjectName(QStringLiteral("mTButtonGroupFile"));
        mTButtonGroupFile->setGeometry(QRect(220, 70, 50, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        mTButtonGroupFile->setFont(font1);

        retranslateUi(GroupWidget);

        QMetaObject::connectSlotsByName(GroupWidget);
    } // setupUi

    void retranslateUi(QWidget *GroupWidget)
    {
        GroupWidget->setWindowTitle(QApplication::translate("GroupWidget", "Form", 0));
        mGroupLabelBK->setText(QString());
        mPButtonGroupSpace->setText(QString());
        mLabelGroupNickChat->setText(QString());
        mTButtonGroupFile->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GroupWidget: public Ui_GroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPWIDGET_H
