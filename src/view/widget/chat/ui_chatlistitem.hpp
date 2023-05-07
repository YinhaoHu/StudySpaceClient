/********************************************************************************
** Form generated from reading UI file 'chatlistitemfUUBID.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CHATLISTITEMFUUBID_H
#define CHATLISTITEMFUUBID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatListItemWidget
{
public:
    QLabel* background;
    QLabel* profileLabel;
    QLabel* nameLabel;
    QLabel* tipLabel;

    void setupUi(QWidget* ChatListItemWidget)
    {
        if (ChatListItemWidget->objectName().isEmpty())
            ChatListItemWidget->setObjectName("ChatListItemWidget");
        ChatListItemWidget->resize(200, 50);
        ChatListItemWidget->setStyleSheet(QString::fromUtf8(""));
        background = new QLabel(ChatListItemWidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 200, 50));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        profileLabel = new QLabel(ChatListItemWidget);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(10, 10, 32, 32));
        profileLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        nameLabel = new QLabel(ChatListItemWidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(50, 10, 100, 32));
        nameLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tipLabel = new QLabel(ChatListItemWidget);
        tipLabel->setObjectName("tipLabel");
        tipLabel->setGeometry(QRect(150, 0, 31, 31));
        QFont font;
        font.setFamilies({ QString::fromUtf8("Microsoft YaHei UI") });
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(false);
        tipLabel->setFont(font);
        tipLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(ChatListItemWidget);

        QMetaObject::connectSlotsByName(ChatListItemWidget);
    } // setupUi

    void retranslateUi(QWidget* ChatListItemWidget)
    {
        ChatListItemWidget->setWindowTitle(QCoreApplication::translate("ChatListItemWidget", "Form", nullptr));
        background->setText(QString());
        profileLabel->setText(QString());
        nameLabel->setText(QCoreApplication::translate("ChatListItemWidget", "name", nullptr));
        tipLabel->setText(QCoreApplication::translate("ChatListItemWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">O</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatListItemWidget : public Ui_ChatListItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CHATLISTITEMFUUBID_H
