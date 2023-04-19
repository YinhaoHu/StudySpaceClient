/********************************************************************************
** Form generated from reading UI file 'friendlistitemEwRKWz.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FRIENDLISTITEMEWRKWZ_H
#define FRIENDLISTITEMEWRKWZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendListItem
{
public:
    QLabel* profileLabel;
    QLabel* nameLabel;
    QLabel* statusLabel;
    QLabel* background;

    void setupUi(QWidget* FriendListItem)
    {
        if (FriendListItem->objectName().isEmpty())
            FriendListItem->setObjectName("FriendListItem");
        FriendListItem->resize(200, 38);
        profileLabel = new QLabel(FriendListItem);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(10, 3, 32, 32));
        profileLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 255);"));
        nameLabel = new QLabel(FriendListItem);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(52, 3, 100, 32));
        nameLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 255, 254);"));
        statusLabel = new QLabel(FriendListItem);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(155, 3, 32, 32));
        statusLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 255, 254);"));
        background = new QLabel(FriendListItem);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 200, 54));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 255, 254);"));
        background->raise();
        profileLabel->raise();
        nameLabel->raise();
        statusLabel->raise();

        retranslateUi(FriendListItem);

        QMetaObject::connectSlotsByName(FriendListItem);
    } // setupUi

    void retranslateUi(QWidget* FriendListItem)
    {
        FriendListItem->setWindowTitle(QCoreApplication::translate("FriendListItem", "Form", nullptr));
        profileLabel->setText(QString());
        nameLabel->setText(QString());
        statusLabel->setText(QString());
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendListItem : public Ui_FriendListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FRIENDLISTITEMEWRKWZ_H
