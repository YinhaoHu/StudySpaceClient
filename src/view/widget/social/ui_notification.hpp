/********************************************************************************
** Form generated from reading UI file 'notificationmTXYIc.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NOTIFICATIONMTXYIC_H
#define NOTIFICATIONMTXYIC_H

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
    QLabel* userNameLabel;
    QPushButton* yesButton;
    QLabel* userIDLabel;
    QPushButton* noButton;
    QWidget* pureNoticeWidget;
    QLabel* noticeLabel;
    QPushButton* confirmButton;

    void setupUi(QWidget* Notification)
    {
        if (Notification->objectName().isEmpty())
            Notification->setObjectName("Notification");
        Notification->resize(200, 76);
        background = new QLabel(Notification);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 200, 76));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 255, 254);"));
        addFriendWidget = new QWidget(Notification);
        addFriendWidget->setObjectName("addFriendWidget");
        addFriendWidget->setGeometry(QRect(0, 0, 200, 76));
        userNameLabel = new QLabel(addFriendWidget);
        userNameLabel->setObjectName("userNameLabel");
        userNameLabel->setGeometry(QRect(5, 40, 100, 32));
        yesButton = new QPushButton(addFriendWidget);
        yesButton->setObjectName("yesButton");
        yesButton->setGeometry(QRect(130, 5, 64, 32));
        userIDLabel = new QLabel(addFriendWidget);
        userIDLabel->setObjectName("userIDLabel");
        userIDLabel->setGeometry(QRect(5, 5, 100, 32));
        noButton = new QPushButton(addFriendWidget);
        noButton->setObjectName("noButton");
        noButton->setGeometry(QRect(130, 40, 64, 32));
        pureNoticeWidget = new QWidget(Notification);
        pureNoticeWidget->setObjectName("pureNoticeWidget");
        pureNoticeWidget->setGeometry(QRect(0, 0, 200, 76));
        noticeLabel = new QLabel(pureNoticeWidget);
        noticeLabel->setObjectName("noticeLabel");
        noticeLabel->setGeometry(QRect(10, 10, 111, 50));
        noticeLabel->setWordWrap(true);
        confirmButton = new QPushButton(pureNoticeWidget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(135, 10, 50, 50));
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
        userNameLabel->setText(QCoreApplication::translate("Notification", "USERNAME", nullptr));
        yesButton->setText(QCoreApplication::translate("Notification", "Y", nullptr));
        userIDLabel->setText(QCoreApplication::translate("Notification", "<html><head/><body><p>ID</p><p><br/></p></body></html>", nullptr));
        noButton->setText(QCoreApplication::translate("Notification", "X", nullptr));
        noticeLabel->setText(QString());
        confirmButton->setText(QCoreApplication::translate("Notification", "\346\224\266\345\210\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notification : public Ui_Notification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NOTIFICATIONMTXYIC_H
