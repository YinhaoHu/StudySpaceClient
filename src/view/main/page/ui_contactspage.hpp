/********************************************************************************
** Form generated from reading UI file 'contactspagenbAEww.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTACTSPAGENBAEWW_H
#define CONTACTSPAGENBAEWW_H

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
    QLabel* viewBackground;
    QLabel* label;
    QLabel* IDTip;
    QLabel* label_2;
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
        viewFriendWidget->setStyleSheet(QString::fromUtf8(""));
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
        nameLabel->setGeometry(QRect(290, 150, 100, 30));
        nameLabel->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
            "border-width:1px;\n"
            "border-color: rgb(225, 225, 225)"));
        introLabel = new QLabel(viewFriendWidget);
        introLabel->setObjectName("introLabel");
        introLabel->setGeometry(QRect(160, 200, 230, 100));
        introLabel->setStyleSheet(QString::fromUtf8("border-width: 1px;\n"
            "border-style: solid;\n"
            "border-color:  rgb(225, 225, 225);"));
        introLabel->setWordWrap(true);
        deleteFriendButton = new QPushButton(viewFriendWidget);
        deleteFriendButton->setObjectName("deleteFriendButton");
        deleteFriendButton->setGeometry(QRect(270, 320, 121, 41));
        deleteFriendButton->setStyleSheet(QString::fromUtf8("font: 16pt \"Microsoft YaHei UI\";"));
        IDLabel = new QLabel(viewFriendWidget);
        IDLabel->setObjectName("IDLabel");
        IDLabel->setGeometry(QRect(290, 100, 100, 30));
        IDLabel->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
            "border-width:1px;\n"
            "border-color: rgb(225, 225, 225)"));
        viewBackground = new QLabel(viewFriendWidget);
        viewBackground->setObjectName("viewBackground");
        viewBackground->setGeometry(QRect(0, 0, 500, 400));
        viewBackground->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
            "border-width: 2px;\n"
            "border-style: solid;\n"
            "border-radius: 16px;\n"
            "border-color: rgb(0, 0, 0);"));
        label = new QLabel(viewFriendWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 200, 30, 100));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
            "border-width:1px;\n"
            "border-color: rgb(225, 225, 225)"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        IDTip = new QLabel(viewFriendWidget);
        IDTip->setObjectName("IDTip");
        IDTip->setGeometry(QRect(240, 100, 40, 30));
        QFont font1;
        font1.setPointSize(12);
        IDTip->setFont(font1);
        IDTip->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
            "border-width:1px;\n"
            "border-color: rgb(225, 225, 225)"));
        IDTip->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(viewFriendWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 150, 40, 30));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
            "border-width:1px;\n"
            "border-color: rgb(225, 225, 225)"));
        label_2->setAlignment(Qt::AlignCenter);
        viewBackground->raise();
        IDLabel->raise();
        deleteFriendButton->raise();
        introLabel->raise();
        nameLabel->raise();
        profileLabel->raise();
        sendMsgButton->raise();
        label->raise();
        IDTip->raise();
        label_2->raise();
        background = new QLabel(ContactsPage);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        addFriendWidget = new QWidget(ContactsPage);
        addFriendWidget->setObjectName("addFriendWidget");
        addFriendWidget->setGeometry(QRect(160, 100, 500, 400));
        addFriendWidget->setStyleSheet(QString::fromUtf8(""));
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
        viewBackground->setText(QString());
        label->setText(QCoreApplication::translate("ContactsPage", "<html><head/><body><p>\347\256\200\344\273\213</p></body></html>", nullptr));
        IDTip->setText(QCoreApplication::translate("ContactsPage", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("ContactsPage", "\345\220\215\347\247\260", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContactsPage : public Ui_ContactsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTACTSPAGENBAEWW_H
