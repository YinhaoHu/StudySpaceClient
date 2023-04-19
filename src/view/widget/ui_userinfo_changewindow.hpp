/********************************************************************************
** Form generated from reading UI file 'userinfo_change_windowVLPaVA.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef USERINFO_CHANGE_WINDOWVLPAVA_H
#define USERINFO_CHANGE_WINDOWVLPAVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfo_change_windowui
{
public:
    QLabel* profileLabel;
    QPushButton* saveButton;
    QPushButton* quitButton;
    QWidget* formLayoutWidget;
    QFormLayout* formLayout;
    QLabel* usernameLabel;
    QLineEdit* usernameInput;
    QLabel* oldpasswordLabel;
    QLineEdit* oldpasswordInput;
    QLabel* newpasswordLabel;
    QLineEdit* newpasswordInput;
    QLabel* introLabel;
    QTextEdit* introInput;
    QPushButton* newProfile;
    QLabel* background;

    void setupUi(QWidget* userinfo_change_windowui)
    {
        if (userinfo_change_windowui->objectName().isEmpty())
            userinfo_change_windowui->setObjectName("userinfo_change_windowui");
        userinfo_change_windowui->resize(300, 491);
        userinfo_change_windowui->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        profileLabel = new QLabel(userinfo_change_windowui);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(100, 30, 100, 100));
        profileLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        saveButton = new QPushButton(userinfo_change_windowui);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(70, 450, 141, 31));
        quitButton = new QPushButton(userinfo_change_windowui);
        quitButton->setObjectName("quitButton");
        quitButton->setGeometry(QRect(270, 0, 31, 20));
        quitButton->setStyleSheet(QString::fromUtf8("border-radius:16px;\n"
            "background-color: rgb(186, 186, 186);"));
        formLayoutWidget = new QWidget(userinfo_change_windowui);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 150, 261, 281));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setVerticalSpacing(40);
        formLayout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(formLayoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, usernameLabel);

        usernameInput = new QLineEdit(formLayoutWidget);
        usernameInput->setObjectName("usernameInput");

        formLayout->setWidget(0, QFormLayout::FieldRole, usernameInput);

        oldpasswordLabel = new QLabel(formLayoutWidget);
        oldpasswordLabel->setObjectName("oldpasswordLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, oldpasswordLabel);

        oldpasswordInput = new QLineEdit(formLayoutWidget);
        oldpasswordInput->setObjectName("oldpasswordInput");

        formLayout->setWidget(1, QFormLayout::FieldRole, oldpasswordInput);

        newpasswordLabel = new QLabel(formLayoutWidget);
        newpasswordLabel->setObjectName("newpasswordLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, newpasswordLabel);

        newpasswordInput = new QLineEdit(formLayoutWidget);
        newpasswordInput->setObjectName("newpasswordInput");

        formLayout->setWidget(2, QFormLayout::FieldRole, newpasswordInput);

        introLabel = new QLabel(formLayoutWidget);
        introLabel->setObjectName("introLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, introLabel);

        introInput = new QTextEdit(formLayoutWidget);
        introInput->setObjectName("introInput");

        formLayout->setWidget(3, QFormLayout::FieldRole, introInput);

        newProfile = new QPushButton(userinfo_change_windowui);
        newProfile->setObjectName("newProfile");
        newProfile->setGeometry(QRect(230, 450, 51, 31));
        background = new QLabel(userinfo_change_windowui);
        background->setObjectName("background");
        background->setGeometry(QRect(-20, -10, 401, 541));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 186, 186);"));
        background->raise();
        profileLabel->raise();
        saveButton->raise();
        quitButton->raise();
        formLayoutWidget->raise();
        newProfile->raise();

        retranslateUi(userinfo_change_windowui);

        QMetaObject::connectSlotsByName(userinfo_change_windowui);
    } // setupUi

    void retranslateUi(QWidget* userinfo_change_windowui)
    {
        userinfo_change_windowui->setWindowTitle(QCoreApplication::translate("userinfo_change_windowui", "Form", nullptr));
        profileLabel->setText(QString());
        saveButton->setText(QCoreApplication::translate("userinfo_change_windowui", "\344\277\235\345\255\230\346\233\264\346\224\271", nullptr));
        quitButton->setText(QCoreApplication::translate("userinfo_change_windowui", "X", nullptr));
        usernameLabel->setText(QCoreApplication::translate("userinfo_change_windowui", "\347\224\250\346\210\267\345\220\215", nullptr));
        oldpasswordLabel->setText(QCoreApplication::translate("userinfo_change_windowui", "\345\216\237\345\257\206\347\240\201", nullptr));
        newpasswordLabel->setText(QCoreApplication::translate("userinfo_change_windowui", "\346\226\260\345\257\206\347\240\201", nullptr));
        introLabel->setText(QCoreApplication::translate("userinfo_change_windowui", "\347\256\200\344\273\213", nullptr));
        newProfile->setText(QCoreApplication::translate("userinfo_change_windowui", "\346\226\260\345\244\264\345\203\217", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class userinfo_change_windowui : public Ui_userinfo_change_windowui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // USERINFO_CHANGE_WINDOWVLPAVA_H
