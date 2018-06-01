/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "messagewidget/messagelist.h"

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QHBoxLayout *horizontalLayout;
    MessageList *messageWidget;
    QFrame *separateLine;
    QStackedWidget *chatStackedWidget;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QStringLiteral("ChatWidget"));
        ChatWidget->resize(709, 462);
        horizontalLayout = new QHBoxLayout(ChatWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        messageWidget = new MessageList(ChatWidget);
        messageWidget->setObjectName(QStringLiteral("messageWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(messageWidget->sizePolicy().hasHeightForWidth());
        messageWidget->setSizePolicy(sizePolicy);
        messageWidget->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(messageWidget);

        separateLine = new QFrame(ChatWidget);
        separateLine->setObjectName(QStringLiteral("separateLine"));
        separateLine->setMinimumSize(QSize(2, 0));
        separateLine->setMaximumSize(QSize(2, 16777215));
        separateLine->setCursor(QCursor(Qt::SizeHorCursor));
        separateLine->setFrameShadow(QFrame::Raised);
        separateLine->setLineWidth(0);
        separateLine->setFrameShape(QFrame::VLine);

        horizontalLayout->addWidget(separateLine);

        chatStackedWidget = new QStackedWidget(ChatWidget);
        chatStackedWidget->setObjectName(QStringLiteral("chatStackedWidget"));

        horizontalLayout->addWidget(chatStackedWidget);


        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QApplication::translate("ChatWidget", "ChatWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
