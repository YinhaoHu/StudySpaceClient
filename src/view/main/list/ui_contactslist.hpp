/********************************************************************************
** Form generated from reading UI file 'contactslistVtxaMp.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTSLISTVTXAMP_H
#define CONTACTSLISTVTXAMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_contactslist
{
public:
    QListWidget* friendsList;
    QPushButton* addFriendButton;
    QPushButton* checkNotificationButton;
    QLabel* background;
    QListWidget* notificationList;
    QLabel* noticeNewLabel;

    void setupUi(QWidget* contactslist)
    {
        if (contactslist->objectName().isEmpty())
            contactslist->setObjectName("contactslist");
        contactslist->resize(200, 700);
        friendsList = new QListWidget(contactslist);
        friendsList->setObjectName("friendsList");
        friendsList->setGeometry(QRect(0, 54, 200, 646));
        friendsList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        friendsList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        friendsList->setAutoScrollMargin(16);
        addFriendButton = new QPushButton(contactslist);
        addFriendButton->setObjectName("addFriendButton");
        addFriendButton->setGeometry(QRect(0, 0, 100, 54));
        checkNotificationButton = new QPushButton(contactslist);
        checkNotificationButton->setObjectName("checkNotificationButton");
        checkNotificationButton->setGeometry(QRect(100, 0, 100, 54));
        background = new QLabel(contactslist);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 200, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 255, 254);"));
        notificationList = new QListWidget(contactslist);
        notificationList->setObjectName("notificationList");
        notificationList->setGeometry(QRect(0, 54, 200, 646));
        notificationList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        notificationList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        notificationList->setAutoScrollMargin(16);
        noticeNewLabel = new QLabel(contactslist);
        noticeNewLabel->setObjectName("noticeNewLabel");
        noticeNewLabel->setGeometry(QRect(160, 0, 41, 20));
        background->raise();
        friendsList->raise();
        addFriendButton->raise();
        checkNotificationButton->raise();
        notificationList->raise();
        noticeNewLabel->raise();

        retranslateUi(contactslist);

        QMetaObject::connectSlotsByName(contactslist);
    } // setupUi

    void retranslateUi(QWidget* contactslist)
    {
        contactslist->setWindowTitle(QCoreApplication::translate("contactslist", "Form", nullptr));
        addFriendButton->setText(QCoreApplication::translate("contactslist", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        checkNotificationButton->setText(QCoreApplication::translate("contactslist", "\346\237\245\347\234\213\351\200\232\347\237\245", nullptr));
        background->setText(QString());
        noticeNewLabel->setText(QCoreApplication::translate("contactslist", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#ff5500;\">New</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class contactslist : public Ui_contactslist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTSLISTVTXAMP_H
