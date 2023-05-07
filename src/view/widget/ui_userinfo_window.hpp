/********************************************************************************
** Form generated from reading UI file 'userinfo_windowiazQeo.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef USERINFO_WINDOWIAZQEO_H
#define USERINFO_WINDOWIAZQEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfo_windowui
{
public:
    QLabel* profileLabel;
    QPushButton* functionButton;
    QPushButton* quitButton;
    QLabel* background;
    QLabel* idLabel;
    QLabel* nameLabel;
    QTextEdit* introArea;
    QLabel* label;
    QLabel* nameTip;
    QLabel* introTip;

    void setupUi(QWidget* userinfo_windowui)
    {
        if (userinfo_windowui->objectName().isEmpty())
            userinfo_windowui->setObjectName("userinfo_windowui");
        userinfo_windowui->resize(300, 500);
        userinfo_windowui->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        profileLabel = new QLabel(userinfo_windowui);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(100, 30, 100, 100));
        profileLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        functionButton = new QPushButton(userinfo_windowui);
        functionButton->setObjectName("functionButton");
        functionButton->setGeometry(QRect(75, 430, 200, 31));
        quitButton = new QPushButton(userinfo_windowui);
        quitButton->setObjectName("quitButton");
        quitButton->setGeometry(QRect(260, 5, 31, 31));
        quitButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
            "border-style: solid;\n"
            "border-radius:16px;\n"
            "font: 700 16pt \"Microsoft YaHei UI\";"));
        background = new QLabel(userinfo_windowui);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 300, 500));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
            "border-color: rgb(0, 0, 0);\n"
            "border-width : 2px;\n"
            "border-style: solid;\n"
            "border-radius: 16px;"));
        idLabel = new QLabel(userinfo_windowui);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(75, 220, 200, 32));
        nameLabel = new QLabel(userinfo_windowui);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(75, 170, 200, 32));
        nameLabel->setStyleSheet(QString::fromUtf8(""));
        introArea = new QTextEdit(userinfo_windowui);
        introArea->setObjectName("introArea");
        introArea->setGeometry(QRect(75, 270, 200, 120));
        introArea->setStyleSheet(QString::fromUtf8("font: 16pt \"Microsoft YaHei UI\";"));
        introArea->setReadOnly(true);
        introArea->setTextInteractionFlags(Qt::TextSelectableByMouse);
        label = new QLabel(userinfo_windowui);
        label->setObjectName("label");
        label->setGeometry(QRect(15, 220, 50, 32));
        nameTip = new QLabel(userinfo_windowui);
        nameTip->setObjectName("nameTip");
        nameTip->setGeometry(QRect(15, 170, 50, 32));
        introTip = new QLabel(userinfo_windowui);
        introTip->setObjectName("introTip");
        introTip->setGeometry(QRect(15, 270, 50, 32));
        introTip->setStyleSheet(QString::fromUtf8("opacity:0.5;"));
        background->raise();
        profileLabel->raise();
        functionButton->raise();
        quitButton->raise();
        idLabel->raise();
        nameLabel->raise();
        introArea->raise();
        label->raise();
        nameTip->raise();
        introTip->raise();

        retranslateUi(userinfo_windowui);

        QMetaObject::connectSlotsByName(userinfo_windowui);
    } // setupUi

    void retranslateUi(QWidget* userinfo_windowui)
    {
        userinfo_windowui->setWindowTitle(QCoreApplication::translate("userinfo_windowui", "Form", nullptr));
        profileLabel->setText(QString());
        functionButton->setText(QCoreApplication::translate("userinfo_windowui", "\345\212\237\350\203\275\346\214\211\351\222\256", nullptr));
        quitButton->setText(QCoreApplication::translate("userinfo_windowui", "X", nullptr));
        background->setText(QString());
        idLabel->setText(QCoreApplication::translate("userinfo_windowui", "<html><head/><body><p><span style=\" font-size:16pt;\">TextLabel</span></p></body></html>", nullptr));
        nameLabel->setText(QCoreApplication::translate("userinfo_windowui", "<html><head/><body><p><span style=\" font-size:16pt;\">username</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("userinfo_windowui", "<html><head/><body><p><span style=\" font-size:16pt;\">\350\264\246\345\217\267</span></p></body></html>", nullptr));
        nameTip->setText(QCoreApplication::translate("userinfo_windowui", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\220\215\347\247\260</span></p></body></html>", nullptr));
        introTip->setText(QCoreApplication::translate("userinfo_windowui", "<html><head/><body><p><span style=\" font-size:16pt;\">\347\256\200\344\273\213</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userinfo_windowui : public Ui_userinfo_windowui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // USERINFO_WINDOWIAZQEO_H
