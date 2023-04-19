/********************************************************************************
** Form generated from reading UI file 'contactspageqQpXBq.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTSPAGEQQPXBQ_H
#define CONTACTSPAGEQQPXBQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactsPage
{
public:
    QWidget* viewFriendWidget;
    QPushButton* sendMsgButton;
    QLabel* profileLabel;
    QLabel* nameLabel;
    QLabel* introLabel;
    QPushButton* deleteFriendButton;
    QLabel* IDLabel;
    QLabel* background;
    QWidget* addFriendWidget;

    void setupUi(QWidget* ContactsPage)
    {
        if (ContactsPage->objectName().isEmpty())
            ContactsPage->setObjectName("ContactsPage");
        ContactsPage->resize(870, 700);
        viewFriendWidget = new QWidget(ContactsPage);
        viewFriendWidget->setObjectName("viewFriendWidget");
        viewFriendWidget->setGeometry(QRect(160, 100, 500, 400));
        viewFriendWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 255, 202);"));
        sendMsgButton = new QPushButton(viewFriendWidget);
        sendMsgButton->setObjectName("sendMsgButton");
        sendMsgButton->setGeometry(QRect(120, 320, 111, 41));
        sendMsgButton->setStyleSheet(QString::fromUtf8("font: 16pt \"Microsoft YaHei UI\";"));
        profileLabel = new QLabel(viewFriendWidget);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(120, 80, 100, 100));
        profileLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        nameLabel = new QLabel(viewFriendWidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(250, 150, 131, 31));
        nameLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        introLabel = new QLabel(viewFriendWidget);
        introLabel->setObjectName("introLabel");
        introLabel->setGeometry(QRect(120, 190, 261, 111));
        introLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        introLabel->setWordWrap(true);
        deleteFriendButton = new QPushButton(viewFriendWidget);
        deleteFriendButton->setObjectName("deleteFriendButton");
        deleteFriendButton->setGeometry(QRect(270, 320, 111, 41));
        deleteFriendButton->setStyleSheet(QString::fromUtf8("font: 16pt \"Microsoft YaHei UI\";"));
        IDLabel = new QLabel(viewFriendWidget);
        IDLabel->setObjectName("IDLabel");
        IDLabel->setGeometry(QRect(250, 100, 131, 31));
        IDLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        background = new QLabel(ContactsPage);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 255, 225);"));
        addFriendWidget = new QWidget(ContactsPage);
        addFriendWidget->setObjectName("addFriendWidget");
        addFriendWidget->setGeometry(QRect(160, 100, 500, 400));
        addFriendWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 255, 202);"));
        background->raise();
        addFriendWidget->raise();
        viewFriendWidget->raise();

        retranslateUi(ContactsPage);

        QMetaObject::connectSlotsByName(ContactsPage);
    } // setupUi

    void retranslateUi(QWidget* ContactsPage)
    {
        ContactsPage->setWindowTitle(QCoreApplication::translate("ContactsPage", "Form", nullptr));
        sendMsgButton->setText(QCoreApplication::translate("ContactsPage", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        profileLabel->setText(QString());
        nameLabel->setText(QString());
        introLabel->setText(QString());
        deleteFriendButton->setText(QCoreApplication::translate("ContactsPage", "\345\210\240\351\231\244\345\245\275\345\217\213", nullptr));
        IDLabel->setText(QString());
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContactsPage : public Ui_ContactsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTSPAGEQQPXBQ_H
