/********************************************************************************
** Form generated from reading UI file 'chatlistrniWgt.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CHATLISTRNIWGT_H
#define CHATLISTRNIWGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatList
{
public:
    QLabel* background;
    QListWidget* dialogListWidget;
    QLabel* label;

    void setupUi(QWidget* ChatList)
    {
        if (ChatList->objectName().isEmpty())
            ChatList->setObjectName("ChatList");
        ChatList->resize(200, 700);
        background = new QLabel(ChatList);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 200, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 242, 255);"));
        dialogListWidget = new QListWidget(ChatList);
        dialogListWidget->setObjectName("dialogListWidget");
        dialogListWidget->setGeometry(QRect(0, 50, 200, 700));
        dialogListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        dialogListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(ChatList);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 200, 50));

        retranslateUi(ChatList);

        QMetaObject::connectSlotsByName(ChatList);
    } // setupUi

    void retranslateUi(QWidget* ChatList)
    {
        ChatList->setWindowTitle(QCoreApplication::translate("ChatList", "Form", nullptr));
        background->setText(QString());
        label->setText(QCoreApplication::translate("ChatList", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">\346\266\210\346\201\257\345\210\227\350\241\250</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatList : public Ui_ChatList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHATLISTRNIWGT_H
