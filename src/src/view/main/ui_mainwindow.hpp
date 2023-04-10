/********************************************************************************
** Form generated from reading UI file 'mainwindowHQOQpF.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWHQOQPF_H
#define MAINWINDOWHQOQPF_H

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
    QWidget* mainArea;
    QWidget* listArea;
    QWidget* infoArea;
    QToolButton* closeButton;
    QToolButton* minimizeButton;
    QLabel* profileLabel;
    QLabel* usernameLabel;
    QWidget* logoArea;
    QLabel* logo;
    QWidget* funcOptionArea;
    QPushButton* comChatOption;
    QPushButton* engLearnOption;
    QPushButton* engLearnOption_2;

    void setupUi(QWidget* mainwindowui)
    {
        if (mainwindowui->objectName().isEmpty())
            mainwindowui->setObjectName("mainwindowui");
        mainwindowui->resize(1121, 736);
        mainwindowui->setStyleSheet(QString::fromUtf8("background-color:white;"));
        mainArea = new QWidget(mainwindowui);
        mainArea->setObjectName("mainArea");
        mainArea->setGeometry(QRect(250, 40, 871, 701));
        mainArea->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);"));
        listArea = new QWidget(mainwindowui);
        listArea->setObjectName("listArea");
        listArea->setGeometry(QRect(50, 40, 201, 701));
        listArea->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        infoArea = new QWidget(mainwindowui);
        infoArea->setObjectName("infoArea");
        infoArea->setGeometry(QRect(250, 0, 871, 41));
        infoArea->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225)"));
        closeButton = new QToolButton(infoArea);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(830, 0, 41, 41));
        closeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
            "border-radius: 32px;"));
        closeButton->setCheckable(true);
        minimizeButton = new QToolButton(infoArea);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setGeometry(QRect(790, 0, 41, 41));
        minimizeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
            "border-radius: 32px;"));
        minimizeButton->setCheckable(true);
        profileLabel = new QLabel(infoArea);
        profileLabel->setObjectName("profileLabel");
        profileLabel->setGeometry(QRect(570, 9, 32, 32));
        profileLabel->setStyleSheet(QString::fromUtf8(""));
        usernameLabel = new QLabel(infoArea);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(610, 9, 120, 32));
        usernameLabel->setStyleSheet(QString::fromUtf8(""));
        logoArea = new QWidget(mainwindowui);
        logoArea->setObjectName("logoArea");
        logoArea->setGeometry(QRect(50, 0, 201, 41));
        logoArea->setStyleSheet(QString::fromUtf8("background-color: rgb(202, 202, 202);"));
        logo = new QLabel(logoArea);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 0, 201, 41));
        logo->setMouseTracking(true);
        funcOptionArea = new QWidget(mainwindowui);
        funcOptionArea->setObjectName("funcOptionArea");
        funcOptionArea->setGeometry(QRect(0, 0, 51, 741));
        funcOptionArea->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 186, 186);"));
        comChatOption = new QPushButton(funcOptionArea);
        comChatOption->setObjectName("comChatOption");
        comChatOption->setGeometry(QRect(4, 60, 41, 41));
        comChatOption->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
            "border-radius : 16px;"));
        engLearnOption = new QPushButton(funcOptionArea);
        engLearnOption->setObjectName("engLearnOption");
        engLearnOption->setGeometry(QRect(4, 120, 41, 41));
        engLearnOption->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
            "border-radius : 16px;"));
        engLearnOption_2 = new QPushButton(funcOptionArea);
        engLearnOption_2->setObjectName("engLearnOption_2");
        engLearnOption_2->setGeometry(QRect(4, 180, 41, 41));
        engLearnOption_2->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
            "border-radius : 16px;"));

        retranslateUi(mainwindowui);

        QMetaObject::connectSlotsByName(mainwindowui);
    } // setupUi

    void retranslateUi(QWidget* mainwindowui)
    {
        mainwindowui->setWindowTitle(QCoreApplication::translate("mainwindowui", "StudySpace", nullptr));
        closeButton->setText(QCoreApplication::translate("mainwindowui", "X", nullptr));
        minimizeButton->setText(QCoreApplication::translate("mainwindowui", "\342\200\224", nullptr));
        profileLabel->setText(QString());
        usernameLabel->setText(QCoreApplication::translate("mainwindowui", "<html><head/><body><p><span style=\" font-size:12pt; color:#9e9e9e;\">USERNAME</span></p></body></html>", nullptr));
        logo->setText(QCoreApplication::translate("mainwindowui", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700; font-style:italic;\">Study Space</span></p></body></html>", nullptr));
        comChatOption->setText(QCoreApplication::translate("mainwindowui", "Chat", nullptr));
        engLearnOption->setText(QCoreApplication::translate("mainwindowui", "Eng", nullptr));
        engLearnOption_2->setText(QCoreApplication::translate("mainwindowui", "Eg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindowui : public Ui_mainwindowui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWHQOQPF_H
