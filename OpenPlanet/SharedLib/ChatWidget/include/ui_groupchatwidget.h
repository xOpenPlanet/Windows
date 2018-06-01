/********************************************************************************
** Form generated from reading UI file 'groupchatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATWIDGET_H
#define UI_GROUPCHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <qcefview.h>

QT_BEGIN_NAMESPACE

class Ui_GroupChatWidget
{
public:
    QPushButton *mPButtonGroupExpress;
    QPushButton *mPButtonGroupFont;
    QPushButton *mPButtonGroupPicture;
    QPushButton *mPButtonGroupCloseW;
    QTextEdit *mTextEditGroup;
    QPushButton *mPButtonGroupSend;
    QLabel *mLabelSend;
    QPushButton *mPButtonGroupShake;
    QPushButton *mPButtonGroupVoiceChat;
    QPushButton *mPButtonGroupCutPicture;
    QLabel *mLabelBKTool;
    QLabel *mLabelGroupNum;
    QListWidget *mGroupUserlistWidget;
    QPushButton *mPButtonGroupLog;
    QLabel *refreshBtn;
    QPushButton *searchBtn;
    QCefView *mGroupWebView;

    void setupUi(QWidget *GroupChatWidget)
    {
        if (GroupChatWidget->objectName().isEmpty())
            GroupChatWidget->setObjectName(QStringLiteral("GroupChatWidget"));
        GroupChatWidget->resize(629, 489);
        mPButtonGroupExpress = new QPushButton(GroupChatWidget);
        mPButtonGroupExpress->setObjectName(QStringLiteral("mPButtonGroupExpress"));
        mPButtonGroupExpress->setGeometry(QRect(45, 330, 30, 24));
        mPButtonGroupFont = new QPushButton(GroupChatWidget);
        mPButtonGroupFont->setObjectName(QStringLiteral("mPButtonGroupFont"));
        mPButtonGroupFont->setGeometry(QRect(10, 330, 30, 24));
        mPButtonGroupPicture = new QPushButton(GroupChatWidget);
        mPButtonGroupPicture->setObjectName(QStringLiteral("mPButtonGroupPicture"));
        mPButtonGroupPicture->setGeometry(QRect(150, 330, 30, 24));
        mPButtonGroupCloseW = new QPushButton(GroupChatWidget);
        mPButtonGroupCloseW->setObjectName(QStringLiteral("mPButtonGroupCloseW"));
        mPButtonGroupCloseW->setGeometry(QRect(310, 458, 70, 28));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        mPButtonGroupCloseW->setFont(font);
        mTextEditGroup = new QTextEdit(GroupChatWidget);
        mTextEditGroup->setObjectName(QStringLiteral("mTextEditGroup"));
        mTextEditGroup->setGeometry(QRect(0, 360, 481, 131));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        mTextEditGroup->setFont(font1);
        mTextEditGroup->setFocusPolicy(Qt::StrongFocus);
        mPButtonGroupSend = new QPushButton(GroupChatWidget);
        mPButtonGroupSend->setObjectName(QStringLiteral("mPButtonGroupSend"));
        mPButtonGroupSend->setGeometry(QRect(400, 330, 56, 22));
        mPButtonGroupSend->setMinimumSize(QSize(56, 22));
        mPButtonGroupSend->setMaximumSize(QSize(56, 22));
        mPButtonGroupSend->setFont(font);
        mLabelSend = new QLabel(GroupChatWidget);
        mLabelSend->setObjectName(QStringLiteral("mLabelSend"));
        mLabelSend->setGeometry(QRect(1, 458, 481, 29));
        mPButtonGroupShake = new QPushButton(GroupChatWidget);
        mPButtonGroupShake->setObjectName(QStringLiteral("mPButtonGroupShake"));
        mPButtonGroupShake->setGeometry(QRect(80, 330, 30, 24));
        mPButtonGroupVoiceChat = new QPushButton(GroupChatWidget);
        mPButtonGroupVoiceChat->setObjectName(QStringLiteral("mPButtonGroupVoiceChat"));
        mPButtonGroupVoiceChat->setGeometry(QRect(115, 330, 30, 24));
        mPButtonGroupCutPicture = new QPushButton(GroupChatWidget);
        mPButtonGroupCutPicture->setObjectName(QStringLiteral("mPButtonGroupCutPicture"));
        mPButtonGroupCutPicture->setGeometry(QRect(185, 330, 30, 24));
        mLabelBKTool = new QLabel(GroupChatWidget);
        mLabelBKTool->setObjectName(QStringLiteral("mLabelBKTool"));
        mLabelBKTool->setGeometry(QRect(0, 329, 481, 28));
        mLabelGroupNum = new QLabel(GroupChatWidget);
        mLabelGroupNum->setObjectName(QStringLiteral("mLabelGroupNum"));
        mLabelGroupNum->setGeometry(QRect(482, 0, 147, 21));
        mLabelGroupNum->setFont(font);
        mGroupUserlistWidget = new QListWidget(GroupChatWidget);
        mGroupUserlistWidget->setObjectName(QStringLiteral("mGroupUserlistWidget"));
        mGroupUserlistWidget->setGeometry(QRect(482, 22, 147, 468));
        mGroupUserlistWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mPButtonGroupLog = new QPushButton(GroupChatWidget);
        mPButtonGroupLog->setObjectName(QStringLiteral("mPButtonGroupLog"));
        mPButtonGroupLog->setGeometry(QRect(310, 330, 75, 22));
        mPButtonGroupLog->setMinimumSize(QSize(75, 22));
        mPButtonGroupLog->setMaximumSize(QSize(75, 22));
        mPButtonGroupLog->setFont(font);
        refreshBtn = new QLabel(GroupChatWidget);
        refreshBtn->setObjectName(QStringLiteral("refreshBtn"));
        refreshBtn->setGeometry(QRect(570, 0, 26, 26));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(refreshBtn->sizePolicy().hasHeightForWidth());
        refreshBtn->setSizePolicy(sizePolicy);
        refreshBtn->setMinimumSize(QSize(26, 26));
        refreshBtn->setMaximumSize(QSize(26, 26));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(false);
        font2.setWeight(50);
        refreshBtn->setFont(font2);
        refreshBtn->setPixmap(QPixmap(QString::fromUtf8(":/GroupChat/Resources/groupchat/refresh.png")));
        searchBtn = new QPushButton(GroupChatWidget);
        searchBtn->setObjectName(QStringLiteral("searchBtn"));
        searchBtn->setGeometry(QRect(530, 0, 26, 26));
        sizePolicy.setHeightForWidth(searchBtn->sizePolicy().hasHeightForWidth());
        searchBtn->setSizePolicy(sizePolicy);
        searchBtn->setMinimumSize(QSize(26, 26));
        searchBtn->setMaximumSize(QSize(26, 26));
        searchBtn->setCheckable(true);
        mGroupWebView = new QCefView(GroupChatWidget);
        mGroupWebView->setObjectName(QStringLiteral("mGroupWebView"));
        mGroupWebView->setGeometry(QRect(0, 0, 481, 281));
        mLabelBKTool->raise();
        mLabelSend->raise();
        mPButtonGroupExpress->raise();
        mPButtonGroupFont->raise();
        mPButtonGroupPicture->raise();
        mPButtonGroupCloseW->raise();
        mTextEditGroup->raise();
        mPButtonGroupSend->raise();
        mPButtonGroupShake->raise();
        mPButtonGroupVoiceChat->raise();
        mPButtonGroupCutPicture->raise();
        mLabelGroupNum->raise();
        mGroupUserlistWidget->raise();
        mPButtonGroupLog->raise();
        refreshBtn->raise();
        searchBtn->raise();
        mGroupWebView->raise();

        retranslateUi(GroupChatWidget);

        QMetaObject::connectSlotsByName(GroupChatWidget);
    } // setupUi

    void retranslateUi(QWidget *GroupChatWidget)
    {
        GroupChatWidget->setWindowTitle(QApplication::translate("GroupChatWidget", "Form", 0));
        mPButtonGroupExpress->setText(QString());
        mPButtonGroupFont->setText(QString());
        mPButtonGroupFont->setShortcut(QApplication::translate("GroupChatWidget", "Shift+Return", 0));
        mPButtonGroupPicture->setText(QString());
        mPButtonGroupCloseW->setText(QApplication::translate("GroupChatWidget", "\345\205\263\351\227\255", 0));
        mPButtonGroupSend->setText(QApplication::translate("GroupChatWidget", "\345\217\221\351\200\201", 0));
        mPButtonGroupSend->setShortcut(QApplication::translate("GroupChatWidget", "Alt+S", 0));
        mLabelSend->setText(QString());
        mPButtonGroupShake->setText(QString());
        mPButtonGroupVoiceChat->setText(QString());
        mPButtonGroupCutPicture->setText(QString());
        mLabelBKTool->setText(QString());
        mLabelGroupNum->setText(QApplication::translate("GroupChatWidget", " \347\276\244\346\210\220\345\221\230", 0));
        mPButtonGroupLog->setText(QApplication::translate("GroupChatWidget", "\346\266\210\346\201\257\350\256\260\345\275\225", 0));
        refreshBtn->setText(QString());
        searchBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GroupChatWidget: public Ui_GroupChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATWIDGET_H
