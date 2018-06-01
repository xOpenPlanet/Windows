/********************************************************************************
** Form generated from reading UI file 'creategroupwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUPWIDGET_H
#define UI_CREATEGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <cfriendlistwidgetbase.h>

QT_BEGIN_NAMESPACE

class Ui_CreateGroupWidget
{
public:
    CFriendListWidgetBase *m_listContactsList;
    QLabel *m_lbShowGroupMembersCount;
    CFriendListWidgetBase *m_listGroupMembers;
    QLabel *m_lbAboveBkColorLeft;
    QLineEdit *m_lineSearchText;
    QLabel *m_lbAboveBkColorRight;
    QPushButton *m_btnConfirm;
    QPushButton *m_btnCancel;
    QLabel *m_lbBelowBkColorRight;
    QLineEdit *m_lineGroupName;

    void setupUi(QWidget *CreateGroupWidget)
    {
        if (CreateGroupWidget->objectName().isEmpty())
            CreateGroupWidget->setObjectName(QStringLiteral("CreateGroupWidget"));
        CreateGroupWidget->resize(570, 450);
        CreateGroupWidget->setStyleSheet(QStringLiteral(""));
        m_listContactsList = new CFriendListWidgetBase(CreateGroupWidget);
        m_listContactsList->setObjectName(QStringLiteral("m_listContactsList"));
        m_listContactsList->setGeometry(QRect(1, 89, 284, 360));
        m_lbShowGroupMembersCount = new QLabel(CreateGroupWidget);
        m_lbShowGroupMembersCount->setObjectName(QStringLiteral("m_lbShowGroupMembersCount"));
        m_lbShowGroupMembersCount->setGeometry(QRect(310, 50, 260, 20));
        m_listGroupMembers = new CFriendListWidgetBase(CreateGroupWidget);
        m_listGroupMembers->setObjectName(QStringLiteral("m_listGroupMembers"));
        m_listGroupMembers->setGeometry(QRect(285, 89, 284, 310));
        m_lbAboveBkColorLeft = new QLabel(CreateGroupWidget);
        m_lbAboveBkColorLeft->setObjectName(QStringLiteral("m_lbAboveBkColorLeft"));
        m_lbAboveBkColorLeft->setGeometry(QRect(0, 30, 285, 60));
        m_lineSearchText = new QLineEdit(CreateGroupWidget);
        m_lineSearchText->setObjectName(QStringLiteral("m_lineSearchText"));
        m_lineSearchText->setGeometry(QRect(20, 50, 241, 25));
        m_lbAboveBkColorRight = new QLabel(CreateGroupWidget);
        m_lbAboveBkColorRight->setObjectName(QStringLiteral("m_lbAboveBkColorRight"));
        m_lbAboveBkColorRight->setGeometry(QRect(285, 30, 285, 60));
        m_btnConfirm = new QPushButton(CreateGroupWidget);
        m_btnConfirm->setObjectName(QStringLiteral("m_btnConfirm"));
        m_btnConfirm->setGeometry(QRect(409, 410, 65, 26));
        m_btnCancel = new QPushButton(CreateGroupWidget);
        m_btnCancel->setObjectName(QStringLiteral("m_btnCancel"));
        m_btnCancel->setGeometry(QRect(486, 410, 65, 26));
        m_lbBelowBkColorRight = new QLabel(CreateGroupWidget);
        m_lbBelowBkColorRight->setObjectName(QStringLiteral("m_lbBelowBkColorRight"));
        m_lbBelowBkColorRight->setGeometry(QRect(285, 400, 285, 50));
        m_lineGroupName = new QLineEdit(CreateGroupWidget);
        m_lineGroupName->setObjectName(QStringLiteral("m_lineGroupName"));
        m_lineGroupName->setGeometry(QRect(297, 410, 100, 25));
        m_lbBelowBkColorRight->raise();
        m_lbAboveBkColorRight->raise();
        m_lbAboveBkColorLeft->raise();
        m_listContactsList->raise();
        m_lbShowGroupMembersCount->raise();
        m_listGroupMembers->raise();
        m_lineSearchText->raise();
        m_btnConfirm->raise();
        m_btnCancel->raise();
        m_lineGroupName->raise();

        retranslateUi(CreateGroupWidget);

        QMetaObject::connectSlotsByName(CreateGroupWidget);
    } // setupUi

    void retranslateUi(QWidget *CreateGroupWidget)
    {
        CreateGroupWidget->setWindowTitle(QApplication::translate("CreateGroupWidget", "CreateGroupWidget", 0));
        m_lbShowGroupMembersCount->setText(QApplication::translate("CreateGroupWidget", "\350\257\267\345\213\276\351\200\211\351\234\200\350\246\201\346\267\273\345\212\240\347\232\204\350\201\224\347\263\273\344\272\272", 0));
        m_lbAboveBkColorLeft->setText(QString());
        m_lbAboveBkColorRight->setText(QString());
        m_btnConfirm->setText(QApplication::translate("CreateGroupWidget", "\347\241\256\345\256\232", 0));
        m_btnCancel->setText(QApplication::translate("CreateGroupWidget", "\345\217\226\346\266\210", 0));
        m_lbBelowBkColorRight->setText(QString());
        m_lineGroupName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateGroupWidget: public Ui_CreateGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUPWIDGET_H
