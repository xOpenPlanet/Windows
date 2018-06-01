/********************************************************************************
** Form generated from reading UI file 'imperchat.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPERCHAT_H
#define UI_IMPERCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcefview.h>

QT_BEGIN_NAMESPACE

class Ui_IMPerChat
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleWidget;
    QLabel *mLabelPerNickChat;
    QCefView *mWebView;
    QFrame *line;
    QWidget *toolWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *mPButtonPerFont;
    QPushButton *mPButtonPerExpress;
    QPushButton *mPButtonPerShake;
    QPushButton *mPButtonPerVoiceChat;
    QPushButton *mPButtonPerPicture;
    QPushButton *mPButtonPerCutPicture;
    QPushButton *mPButtonSecretLetter;
    QSpacerItem *horizontalSpacer;
    QPushButton *mPButtonPerLog;
    QPushButton *mPButtonPerSend;
    QTextEdit *mTextEditPer;

    void setupUi(QWidget *IMPerChat)
    {
        if (IMPerChat->objectName().isEmpty())
            IMPerChat->setObjectName(QStringLiteral("IMPerChat"));
        IMPerChat->resize(630, 600);
        verticalLayout = new QVBoxLayout(IMPerChat);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(IMPerChat);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleWidget->sizePolicy().hasHeightForWidth());
        titleWidget->setSizePolicy(sizePolicy);
        titleWidget->setMinimumSize(QSize(0, 42));
        mLabelPerNickChat = new QLabel(titleWidget);
        mLabelPerNickChat->setObjectName(QStringLiteral("mLabelPerNickChat"));
        mLabelPerNickChat->setGeometry(QRect(10, 6, 300, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        mLabelPerNickChat->setFont(font);

        verticalLayout->addWidget(titleWidget);

        mWebView = new QCefView(IMPerChat);
        mWebView->setObjectName(QStringLiteral("mWebView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mWebView->sizePolicy().hasHeightForWidth());
        mWebView->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(mWebView);

        line = new QFrame(IMPerChat);
        line->setObjectName(QStringLiteral("line"));
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMaximumSize(QSize(16777215, 1));
        line->setFrameShadow(QFrame::Plain);
        line->setMidLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line);

        toolWidget = new QWidget(IMPerChat);
        toolWidget->setObjectName(QStringLiteral("toolWidget"));
        sizePolicy.setHeightForWidth(toolWidget->sizePolicy().hasHeightForWidth());
        toolWidget->setSizePolicy(sizePolicy);
        toolWidget->setMinimumSize(QSize(0, 30));
        horizontalLayout = new QHBoxLayout(toolWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 4, -1, 4);
        mPButtonPerFont = new QPushButton(toolWidget);
        mPButtonPerFont->setObjectName(QStringLiteral("mPButtonPerFont"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mPButtonPerFont->sizePolicy().hasHeightForWidth());
        mPButtonPerFont->setSizePolicy(sizePolicy2);
        mPButtonPerFont->setMinimumSize(QSize(30, 24));

        horizontalLayout->addWidget(mPButtonPerFont);

        mPButtonPerExpress = new QPushButton(toolWidget);
        mPButtonPerExpress->setObjectName(QStringLiteral("mPButtonPerExpress"));
        sizePolicy2.setHeightForWidth(mPButtonPerExpress->sizePolicy().hasHeightForWidth());
        mPButtonPerExpress->setSizePolicy(sizePolicy2);
        mPButtonPerExpress->setMinimumSize(QSize(30, 24));

        horizontalLayout->addWidget(mPButtonPerExpress);

        mPButtonPerShake = new QPushButton(toolWidget);
        mPButtonPerShake->setObjectName(QStringLiteral("mPButtonPerShake"));
        sizePolicy2.setHeightForWidth(mPButtonPerShake->sizePolicy().hasHeightForWidth());
        mPButtonPerShake->setSizePolicy(sizePolicy2);
        mPButtonPerShake->setMinimumSize(QSize(30, 24));

        horizontalLayout->addWidget(mPButtonPerShake);

        mPButtonPerVoiceChat = new QPushButton(toolWidget);
        mPButtonPerVoiceChat->setObjectName(QStringLiteral("mPButtonPerVoiceChat"));
        sizePolicy2.setHeightForWidth(mPButtonPerVoiceChat->sizePolicy().hasHeightForWidth());
        mPButtonPerVoiceChat->setSizePolicy(sizePolicy2);
        mPButtonPerVoiceChat->setMinimumSize(QSize(30, 24));

        horizontalLayout->addWidget(mPButtonPerVoiceChat);

        mPButtonPerPicture = new QPushButton(toolWidget);
        mPButtonPerPicture->setObjectName(QStringLiteral("mPButtonPerPicture"));
        sizePolicy2.setHeightForWidth(mPButtonPerPicture->sizePolicy().hasHeightForWidth());
        mPButtonPerPicture->setSizePolicy(sizePolicy2);
        mPButtonPerPicture->setMinimumSize(QSize(30, 24));

        horizontalLayout->addWidget(mPButtonPerPicture);

        mPButtonPerCutPicture = new QPushButton(toolWidget);
        mPButtonPerCutPicture->setObjectName(QStringLiteral("mPButtonPerCutPicture"));
        sizePolicy2.setHeightForWidth(mPButtonPerCutPicture->sizePolicy().hasHeightForWidth());
        mPButtonPerCutPicture->setSizePolicy(sizePolicy2);
        mPButtonPerCutPicture->setMinimumSize(QSize(30, 24));

        horizontalLayout->addWidget(mPButtonPerCutPicture);

        mPButtonSecretLetter = new QPushButton(toolWidget);
        mPButtonSecretLetter->setObjectName(QStringLiteral("mPButtonSecretLetter"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mPButtonSecretLetter->sizePolicy().hasHeightForWidth());
        mPButtonSecretLetter->setSizePolicy(sizePolicy3);
        mPButtonSecretLetter->setMinimumSize(QSize(30, 24));

        horizontalLayout->addWidget(mPButtonSecretLetter);

        horizontalSpacer = new QSpacerItem(262, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mPButtonPerLog = new QPushButton(toolWidget);
        mPButtonPerLog->setObjectName(QStringLiteral("mPButtonPerLog"));
        sizePolicy3.setHeightForWidth(mPButtonPerLog->sizePolicy().hasHeightForWidth());
        mPButtonPerLog->setSizePolicy(sizePolicy3);
        mPButtonPerLog->setMinimumSize(QSize(75, 22));
        mPButtonPerLog->setMaximumSize(QSize(75, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        mPButtonPerLog->setFont(font1);

        horizontalLayout->addWidget(mPButtonPerLog);

        mPButtonPerSend = new QPushButton(toolWidget);
        mPButtonPerSend->setObjectName(QStringLiteral("mPButtonPerSend"));
        mPButtonPerSend->setMinimumSize(QSize(56, 22));
        mPButtonPerSend->setMaximumSize(QSize(56, 22));
        mPButtonPerSend->setFont(font1);

        horizontalLayout->addWidget(mPButtonPerSend);


        verticalLayout->addWidget(toolWidget);

        mTextEditPer = new QTextEdit(IMPerChat);
        mTextEditPer->setObjectName(QStringLiteral("mTextEditPer"));
        sizePolicy.setHeightForWidth(mTextEditPer->sizePolicy().hasHeightForWidth());
        mTextEditPer->setSizePolicy(sizePolicy);
        mTextEditPer->setMinimumSize(QSize(0, 150));
        mTextEditPer->setMaximumSize(QSize(16777215, 150));
        mTextEditPer->setFont(font);
        mTextEditPer->setFocusPolicy(Qt::StrongFocus);

        verticalLayout->addWidget(mTextEditPer);


        retranslateUi(IMPerChat);

        QMetaObject::connectSlotsByName(IMPerChat);
    } // setupUi

    void retranslateUi(QWidget *IMPerChat)
    {
        IMPerChat->setWindowTitle(QApplication::translate("IMPerChat", "Form", 0));
        mLabelPerNickChat->setText(QString());
        mPButtonPerFont->setText(QString());
        mPButtonPerFont->setShortcut(QApplication::translate("IMPerChat", "Shift+Return", 0));
        mPButtonPerExpress->setText(QString());
        mPButtonPerShake->setText(QString());
        mPButtonPerVoiceChat->setText(QString());
        mPButtonPerPicture->setText(QString());
        mPButtonPerCutPicture->setText(QString());
        mPButtonSecretLetter->setText(QString());
        mPButtonPerLog->setText(QApplication::translate("IMPerChat", "\346\266\210\346\201\257\350\256\260\345\275\225", 0));
        mPButtonPerSend->setText(QApplication::translate("IMPerChat", "\345\217\221\351\200\201", 0));
        mPButtonPerSend->setShortcut(QApplication::translate("IMPerChat", "Alt+S", 0));
    } // retranslateUi

};

namespace Ui {
    class IMPerChat: public Ui_IMPerChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPERCHAT_H
