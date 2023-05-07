/********************************************************************************
** Form generated from reading UI file 'notificationAaYxBW.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NOTIFICATIONAAYXBW_H
#define NOTIFICATIONAAYXBW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notification
{
public:
    QLabel* background;
    QWidget* addFriendWidget;
    QLabel* messageLabel;
    QPushButton* yesButton;
    QLabel* userinfoLabel;
    QPushButton* noButton;
    QWidget* pureNoticeWidget;
    QLabel* noticeLabel;
    QPushButton* confirmButton;

    void setupUi(QWidget* Notification)
    {
        if (Notification->objectName().isEmpty())
            Notification->setObjectName("Notification");
        Notification->resize(200, 76);
        Notification->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        background = new QLabel(Notification);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 200, 76));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        addFriendWidget = new QWidget(Notification);
        addFriendWidget->setObjectName("addFriendWidget");
        addFriendWidget->setGeometry(QRect(0, 0, 200, 76));
        messageLabel = new QLabel(addFriendWidget);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setGeometry(QRect(5, 40, 115, 32));
        QFont font;
        font.setPointSize(10);
        messageLabel->setFont(font);
        messageLabel->setWordWrap(true);
        yesButton = new QPushButton(addFriendWidget);
        yesButton->setObjectName("yesButton");
        yesButton->setGeometry(QRect(135, 5, 40, 32));
        userinfoLabel = new QLabel(addFriendWidget);
        userinfoLabel->setObjectName("userinfoLabel");
        userinfoLabel->setGeometry(QRect(5, 5, 115, 32));
        userinfoLabel->setFont(font);
        userinfoLabel->setWordWrap(true);
        noButton = new QPushButton(addFriendWidget);
        noButton->setObjectName("noButton");
        noButton->setGeometry(QRect(135, 40, 40, 32));
        pureNoticeWidget = new QWidget(Notification);
        pureNoticeWidget->setObjectName("pureNoticeWidget");
        pureNoticeWidget->setGeometry(QRect(0, 0, 200, 76));
        noticeLabel = new QLabel(pureNoticeWidget);
        noticeLabel->setObjectName("noticeLabel");
        noticeLabel->setGeometry(QRect(10, 10, 115, 50));
        noticeLabel->setWordWrap(true);
        confirmButton = new QPushButton(pureNoticeWidget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(135, 15, 40, 40));
        confirmButton->raise();
        noticeLabel->raise();
        background->raise();
        pureNoticeWidget->raise();
        addFriendWidget->raise();

        retranslateUi(Notification);

        QMetaObject::connectSlotsByName(Notification);
    } // setupUi

    void retranslateUi(QWidget* Notification)
    {
        Notification->setWindowTitle(QCoreApplication::translate("Notification", "Form", nullptr));
        background->setText(QString());
        messageLabel->setText(QCoreApplication::translate("Notification", "Request", nullptr));
        yesButton->setText(QCoreApplication::translate("Notification", "\345\220\214\346\204\217", nullptr));
        userinfoLabel->setText(QCoreApplication::translate("Notification", "<html><head/><body><p>ID + username</p><p><br/></p></body></html>", nullptr));
        noButton->setText(QCoreApplication::translate("Notification", "\346\213\222\347\273\235", nullptr));
        noticeLabel->setText(QString());
        confirmButton->setText(QCoreApplication::translate("Notification", "\346\224\266\345\210\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notification : public Ui_Notification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NOTIFICATIONAAYXBW_H
