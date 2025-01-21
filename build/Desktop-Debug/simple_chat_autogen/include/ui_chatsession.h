/********************************************************************************
** Form generated from reading UI file 'chatsession.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATSESSION_H
#define UI_CHATSESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatSession
{
public:
    QAction *actionConnect_to_server;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QPushButton *sendButton;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QMenu *menusimple_chat;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chatSession)
    {
        if (chatSession->objectName().isEmpty())
            chatSession->setObjectName(QString::fromUtf8("chatSession"));
        chatSession->resize(800, 600);
        actionConnect_to_server = new QAction(chatSession);
        actionConnect_to_server->setObjectName(QString::fromUtf8("actionConnect_to_server"));
        centralwidget = new QWidget(chatSession);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 450, 761, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);

        sendButton = new QPushButton(horizontalLayoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout->addWidget(sendButton);

        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(60, 40, 661, 371));
        textEdit_2->setStyleSheet(QString::fromUtf8(""));
        textEdit_2->setReadOnly(true);
        chatSession->setCentralWidget(centralwidget);
        menubar = new QMenuBar(chatSession);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menusimple_chat = new QMenu(menubar);
        menusimple_chat->setObjectName(QString::fromUtf8("menusimple_chat"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        chatSession->setMenuBar(menubar);
        statusbar = new QStatusBar(chatSession);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        chatSession->setStatusBar(statusbar);

        menubar->addAction(menusimple_chat->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionConnect_to_server);

        retranslateUi(chatSession);

        QMetaObject::connectSlotsByName(chatSession);
    } // setupUi

    void retranslateUi(QMainWindow *chatSession)
    {
        chatSession->setWindowTitle(QCoreApplication::translate("chatSession", "chatSession", nullptr));
        actionConnect_to_server->setText(QCoreApplication::translate("chatSession", "Connect to server", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("chatSession", "type your message here to send...", nullptr));
        sendButton->setText(QCoreApplication::translate("chatSession", "Send", nullptr));
        menusimple_chat->setTitle(QCoreApplication::translate("chatSession", "simple_chat", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("chatSession", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatSession: public Ui_chatSession {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATSESSION_H
