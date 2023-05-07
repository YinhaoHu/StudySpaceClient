/********************************************************************************
** Form generated from reading UI file 'mainwindowhJHZsn.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWHJHZSN_H
#define MAINWINDOWHJHZSN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowui
{
public:
    QWidget *mainArea;
    QLabel *homepageimage;
    QWidget *listArea;
    QWidget *infoArea;
    QToolButton *closeButton;
    QToolButton *minimizeButton;
    QLabel *profileLabel;
    QLabel *usernameLabel;
    QWidget *logoArea;
    QLabel *logo;
    QWidget *funcOptionArea;
    QPushButton *chatOption;
    QPushButton *engLearnOption;
    QPushButton *contactsOption;
    QPushButton *userinfoOption;
    QPushButton *feedBackOption;
    QPushButton *studyAidsOption;
    QLabel *background;

    void setupUi(QWidget *mainwindowui)
    {
        if (mainwindowui->objectName().isEmpty())
            mainwindowui->setObjectName("mainwindowui");
        mainwindowui->resize(1120, 739);
        mainwindowui->setStyleSheet(QString::fromUtf8("background-color:white;"));
        mainArea = new QWidget(mainwindowui);
        mainArea->setObjectName("mainArea");
        mainArea->setGeometry(QRect(249, 38, 870, 700));
        mainArea->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);"));
        homepageimage = new QLabel(mainArea);
        homepageimage->setObjectName("homepageimage");
        homepageimage->setGeometry(QRect(167, 214, 536, 272));
        homepageimage->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        listArea = new QWidget(mainwindowui);
        listArea->setObjectName("listArea");
        listArea->setGeometry(QRect(48, 38, 200, 700));
        listArea->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        infoArea = new QWidget(mainwindowui);
        infoArea->setObjectName("infoArea");
        infoArea->setGeometry(QRect(249, 1, 870, 38));
        infoArea->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 126);"));
        closeButton = new QToolButton(infoArea);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(830, 0, 41, 41));
        closeButton->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(126, 126, 126);\n"
"border-radius: 32px;"));
        closeButton->setCheckable(true);
        minimizeButton = new QToolButton(infoArea);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setGeometry(QRect(790, 0, 41, 41));
        minimizeButton->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(126, 126, 126);\n"
"border-radius: 32px;"));
        minimizeButton->setCheckable(true);
        profileLabel = new QLabel(infoArea);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(570, 9, 32, 32));
        profileLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        usernameLabel = new QLabel(infoArea);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(610, 9, 120, 32));
        usernameLabel->setStyleSheet(QString::fromUtf8(""));
        logoArea = new QWidget(mainwindowui);
        logoArea->setObjectName("logoArea");
        logoArea->setGeometry(QRect(48, 1, 201, 38));
        logoArea->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);"));
        logo = new QLabel(logoArea);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 0, 201, 38));
        logo->setMouseTracking(true);
        logo->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 126);"));
        funcOptionArea = new QWidget(mainwindowui);
        funcOptionArea->setObjectName("funcOptionArea");
        funcOptionArea->setGeometry(QRect(1, 1, 48, 739));
        funcOptionArea->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 46, 46);"));
        chatOption = new QPushButton(funcOptionArea);
        chatOption->setObjectName("chatOption");
        chatOption->setGeometry(QRect(4, 60, 41, 41));
        chatOption->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"border-radius : 16px;"));
        engLearnOption = new QPushButton(funcOptionArea);
        engLearnOption->setObjectName("engLearnOption");
        engLearnOption->setGeometry(QRect(4, 180, 41, 41));
        engLearnOption->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"border-radius : 16px;"));
        contactsOption = new QPushButton(funcOptionArea);
        contactsOption->setObjectName("contactsOption");
        contactsOption->setGeometry(QRect(4, 120, 41, 41));
        contactsOption->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"border-radius : 16px;\n"
""));
        userinfoOption = new QPushButton(funcOptionArea);
        userinfoOption->setObjectName("userinfoOption");
        userinfoOption->setGeometry(QRect(4, 690, 41, 41));
        userinfoOption->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"border-radius : 16px;"));
        feedBackOption = new QPushButton(funcOptionArea);
        feedBackOption->setObjectName("feedBackOption");
        feedBackOption->setGeometry(QRect(4, 630, 41, 41));
        feedBackOption->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"border-radius : 16px;"));
        studyAidsOption = new QPushButton(funcOptionArea);
        studyAidsOption->setObjectName("studyAidsOption");
        studyAidsOption->setGeometry(QRect(4, 240, 41, 41));
        studyAidsOption->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
"border-radius : 16px;"));
        background = new QLabel(mainwindowui);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 1121, 741));
        background->setStyleSheet(QString::fromUtf8("border-width: 8px;\n"
"border-color: rgb(0, 0, 0);\n"
"border-style:solid;"));
        background->raise();
        mainArea->raise();
        listArea->raise();
        infoArea->raise();
        logoArea->raise();
        funcOptionArea->raise();

        retranslateUi(mainwindowui);

        QMetaObject::connectSlotsByName(mainwindowui);
    } // setupUi

    void retranslateUi(QWidget *mainwindowui)
    {
        mainwindowui->setWindowTitle(QCoreApplication::translate("mainwindowui", "StudySpace", nullptr));
        homepageimage->setText(QCoreApplication::translate("mainwindowui", "TextLabel", nullptr));
        closeButton->setText(QCoreApplication::translate("mainwindowui", "X", nullptr));
        minimizeButton->setText(QCoreApplication::translate("mainwindowui", "\342\200\224", nullptr));
        profileLabel->setText(QString());
        usernameLabel->setText(QCoreApplication::translate("mainwindowui", "<html><head/><body><p><span style=\" font-size:12pt; color:#9e9e9e;\">USERNAME</span></p></body></html>", nullptr));
        logo->setText(QCoreApplication::translate("mainwindowui", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700; font-style:italic;\">Study Space</span></p></body></html>", nullptr));
        chatOption->setText(QCoreApplication::translate("mainwindowui", "\346\266\210\346\201\257", nullptr));
        engLearnOption->setText(QCoreApplication::translate("mainwindowui", "\350\213\261\350\257\255", nullptr));
        contactsOption->setText(QCoreApplication::translate("mainwindowui", "\345\245\275\345\217\213", nullptr));
        userinfoOption->setText(QCoreApplication::translate("mainwindowui", "\346\210\221", nullptr));
        feedBackOption->setText(QCoreApplication::translate("mainwindowui", "\345\217\215\351\246\210", nullptr));
        studyAidsOption->setText(QCoreApplication::translate("mainwindowui", "\345\255\246\344\270\232", nullptr));
        background->setText(QCoreApplication::translate("mainwindowui", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindowui: public Ui_mainwindowui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWHJHZSN_H
