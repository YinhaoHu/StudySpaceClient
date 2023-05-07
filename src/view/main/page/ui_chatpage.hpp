/********************************************************************************
** Form generated from reading UI file 'chatpageNssapM.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CHATPAGENSSAPM_H
#define CHATPAGENSSAPM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
    QLabel* background;
    QLabel* titleLabel;
    QTextEdit* inputBlock;
    QPushButton* sendMsgButton;
    QWidget* messageListWidget;

    void setupUi(QWidget* ChatPage)
    {
        if (ChatPage->objectName().isEmpty())
            ChatPage->setObjectName("ChatPage");
        ChatPage->resize(870, 700);
        background = new QLabel(ChatPage);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        titleLabel = new QLabel(ChatPage);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(0, 0, 870, 30));
        titleLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
            "font: 700 12pt \"Microsoft YaHei UI\";\n"
            ""));
        titleLabel->setAlignment(Qt::AlignCenter);
        inputBlock = new QTextEdit(ChatPage);
        inputBlock->setObjectName("inputBlock");
        inputBlock->setGeometry(QRect(0, 515, 870, 150));
        QFont font;
        font.setPointSize(13);
        inputBlock->setFont(font);
        inputBlock->setFocusPolicy(Qt::ClickFocus);
        sendMsgButton = new QPushButton(ChatPage);
        sendMsgButton->setObjectName("sendMsgButton");
        sendMsgButton->setGeometry(QRect(770, 670, 101, 31));
        messageListWidget = new QWidget(ChatPage);
        messageListWidget->setObjectName("messageListWidget");
        messageListWidget->setGeometry(QRect(0, 35, 870, 470));

        retranslateUi(ChatPage);

        QMetaObject::connectSlotsByName(ChatPage);
    } // setupUi

    void retranslateUi(QWidget* ChatPage)
    {
        ChatPage->setWindowTitle(QCoreApplication::translate("ChatPage", "Form", nullptr));
        background->setText(QString());
        titleLabel->setText(QCoreApplication::translate("ChatPage", "Title", nullptr));
        sendMsgButton->setText(QCoreApplication::translate("ChatPage", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatPage : public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHATPAGENSSAPM_H
