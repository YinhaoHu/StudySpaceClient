/********************************************************************************
** Form generated from reading UI file 'loginwindowCdRJWf.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGINWINDOWCDRJWF_H
#define LOGINWINDOWCDRJWF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindowui
{
public:
    QLineEdit* numberInput;
    QLineEdit* passwordInput;
    QLabel* numberLabel;
    QLabel* passwordLabel;
    QPushButton* loginButton;
    QLabel* titleLabel;
    QLabel* mainBackgroundLabel;
    QPushButton* minimizeButton;
    QPushButton* closeButton;
    QPushButton* registerButton;
    QPushButton* moreinfoButton;

    void setupUi(QWidget* loginwindowui)
    {
        if (loginwindowui->objectName().isEmpty())
            loginwindowui->setObjectName("loginwindowui");
        loginwindowui->resize(434, 274);
        loginwindowui->setMouseTracking(true);
        loginwindowui->setFocusPolicy(Qt::ClickFocus);
        loginwindowui->setStyleSheet(QString::fromUtf8("border-radius : 10px;"));
        numberInput = new QLineEdit(loginwindowui);
        numberInput->setObjectName("numberInput");
        numberInput->setGeometry(QRect(130, 110, 231, 31));
        numberInput->setStyleSheet(QString::fromUtf8("border-radius : 10px;"));
        passwordInput = new QLineEdit(loginwindowui);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setGeometry(QRect(130, 160, 231, 31));
        passwordInput->setStyleSheet(QString::fromUtf8("border-radius : 10px;"));
        passwordInput->setEchoMode(QLineEdit::Password);
        numberLabel = new QLabel(loginwindowui);
        numberLabel->setObjectName("numberLabel");
        numberLabel->setGeometry(QRect(70, 110, 51, 31));
        passwordLabel = new QLabel(loginwindowui);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(70, 150, 51, 41));
        loginButton = new QPushButton(loginwindowui);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(70, 200, 291, 41));
        loginButton->setStyleSheet(QString::fromUtf8("border-radius : 10px;\n"
            "background-color : rgb(231, 231, 231);\n"
            "font-size:24px;"));
        loginButton->setIconSize(QSize(16, 16));
        loginButton->setCheckable(true);
        titleLabel = new QLabel(loginwindowui);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(0, 0, 441, 91));
        titleLabel->setFocusPolicy(Qt::NoFocus);
        titleLabel->setStyleSheet(QString::fromUtf8(" background-color: rgb(233, 248, 255)"));
        mainBackgroundLabel = new QLabel(loginwindowui);
        mainBackgroundLabel->setObjectName("mainBackgroundLabel");
        mainBackgroundLabel->setGeometry(QRect(3, 95, 431, 181));
        mainBackgroundLabel->setStyleSheet(QString::fromUtf8(" background-color: rgb(238, 238, 238);"));
        minimizeButton = new QPushButton(loginwindowui);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setGeometry(QRect(370, 0, 31, 16));
        minimizeButton->setStyleSheet(QString::fromUtf8("border-radius : 24px;"));
        closeButton = new QPushButton(loginwindowui);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(400, 0, 31, 16));
        closeButton->setStyleSheet(QString::fromUtf8("border-radius : 24px;"));
        registerButton = new QPushButton(loginwindowui);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(0, 240, 41, 31));
        registerButton->setStyleSheet(QString::fromUtf8("border-radius : 36px;\n"
            "color: rgb(162, 162, 162);\n"
            "font-size: 14px;"));
        moreinfoButton = new QPushButton(loginwindowui);
        moreinfoButton->setObjectName("moreinfoButton");
        moreinfoButton->setGeometry(QRect(390, 240, 41, 31));
        moreinfoButton->setStyleSheet(QString::fromUtf8("border-radius : 36px;\n"
            "color: rgb(162, 162, 162);\n"
            "font-size: 14px;"));
        mainBackgroundLabel->raise();
        numberInput->raise();
        passwordInput->raise();
        numberLabel->raise();
        passwordLabel->raise();
        loginButton->raise();
        titleLabel->raise();
        minimizeButton->raise();
        closeButton->raise();
        registerButton->raise();
        moreinfoButton->raise();

        retranslateUi(loginwindowui);

        QMetaObject::connectSlotsByName(loginwindowui);
    } // setupUi

    void retranslateUi(QWidget* loginwindowui)
    {
        loginwindowui->setWindowTitle(QCoreApplication::translate("loginwindowui", "StudySpace", nullptr));
        numberLabel->setText(QCoreApplication::translate("loginwindowui", "<html><head/><body><p><span style=\" font-size:16pt;\">\350\264\246\345\217\267</span></p></body></html>", nullptr));
        passwordLabel->setText(QCoreApplication::translate("loginwindowui", "<html><head/><body><p><span style=\" font-size:16pt;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        loginButton->setText(QCoreApplication::translate("loginwindowui", "\347\231\273\345\275\225", nullptr));
        titleLabel->setText(QCoreApplication::translate("loginwindowui", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700;\">Study Space</span></p></body></html>", nullptr));
        mainBackgroundLabel->setText(QString());
        minimizeButton->setText(QCoreApplication::translate("loginwindowui", "\342\200\224", nullptr));
        closeButton->setText(QCoreApplication::translate("loginwindowui", "X", nullptr));
        registerButton->setText(QCoreApplication::translate("loginwindowui", "\346\263\250\345\206\214", nullptr));
        moreinfoButton->setText(QCoreApplication::translate("loginwindowui", "\346\233\264\345\244\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwindowui : public Ui_loginwindowui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGINWINDOWCDRJWF_H
