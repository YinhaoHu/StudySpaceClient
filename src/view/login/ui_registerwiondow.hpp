/********************************************************************************
** Form generated from reading UI file 'registerwindowacJTbT.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef REGISTERWINDOWACJTBT_H
#define REGISTERWINDOWACJTBT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registerwindowui
{
public:
    QLabel* titleBar;
    QPushButton* registerButton;
    QWidget* formLayoutWidget;
    QGridLayout* gridLayout;
    QLabel* nameLabel;
    QLineEdit* nameInput;
    QLabel* passwordLable;
    QLabel* repasswordLable;
    QLabel* emailLable;
    QLabel* codeLable;
    QLineEdit* repasswordInput;
    QLineEdit* passwordInput;
    QLineEdit* emailInput;
    QLineEdit* codeInput;
    QPushButton* minimizeButton;
    QPushButton* closeButton;

    void setupUi(QWidget* registerwindowui)
    {
        if (registerwindowui->objectName().isEmpty())
            registerwindowui->setObjectName("registerwindowui");
        registerwindowui->resize(415, 418);
        registerwindowui->setStyleSheet(QString::fromUtf8("background-color: white;"));
        titleBar = new QLabel(registerwindowui);
        titleBar->setObjectName("titleBar");
        titleBar->setGeometry(QRect(0, 0, 421, 91));
        titleBar->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 255, 255);"));
        registerButton = new QPushButton(registerwindowui);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(60, 360, 311, 41));
        registerButton->setStyleSheet(QString::fromUtf8("size: 16px;\n"
            "border-radius: 16px;\n"
            "background-color: rgb(213, 213, 213);"));
        registerButton->setIconSize(QSize(32, 32));
        registerButton->setCheckable(true);
        formLayoutWidget = new QWidget(registerwindowui);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 90, 411, 251));
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setVerticalSpacing(25);
        gridLayout->setContentsMargins(60, 10, 60, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName("nameLabel");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        nameLabel->setFont(font);

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameInput = new QLineEdit(formLayoutWidget);
        nameInput->setObjectName("nameInput");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nameInput->sizePolicy().hasHeightForWidth());
        nameInput->setSizePolicy(sizePolicy1);
        nameInput->setMinimumSize(QSize(0, 0));
        nameInput->setMaximumSize(QSize(16777215, 1000));
        nameInput->setLayoutDirection(Qt::LeftToRight);
        nameInput->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
            "background-color: rgb(236, 236, 236);"));

        gridLayout->addWidget(nameInput, 0, 1, 1, 1);

        passwordLable = new QLabel(formLayoutWidget);
        passwordLable->setObjectName("passwordLable");
        passwordLable->setFont(font);

        gridLayout->addWidget(passwordLable, 1, 0, 1, 1);

        repasswordLable = new QLabel(formLayoutWidget);
        repasswordLable->setObjectName("repasswordLable");
        repasswordLable->setFont(font);

        gridLayout->addWidget(repasswordLable, 2, 0, 1, 1);

        emailLable = new QLabel(formLayoutWidget);
        emailLable->setObjectName("emailLable");
        emailLable->setFont(font);

        gridLayout->addWidget(emailLable, 3, 0, 1, 1);

        codeLable = new QLabel(formLayoutWidget);
        codeLable->setObjectName("codeLable");
        codeLable->setFont(font);

        gridLayout->addWidget(codeLable, 4, 0, 1, 1);

        repasswordInput = new QLineEdit(formLayoutWidget);
        repasswordInput->setObjectName("repasswordInput");
        sizePolicy1.setHeightForWidth(repasswordInput->sizePolicy().hasHeightForWidth());
        repasswordInput->setSizePolicy(sizePolicy1);
        repasswordInput->setMinimumSize(QSize(0, 0));
        repasswordInput->setMaximumSize(QSize(16777215, 1000));
        repasswordInput->setLayoutDirection(Qt::LeftToRight);
        repasswordInput->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
            "background-color: rgb(225, 225, 225);"));
        repasswordInput->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(repasswordInput, 2, 1, 1, 1);

        passwordInput = new QLineEdit(formLayoutWidget);
        passwordInput->setObjectName("passwordInput");
        sizePolicy1.setHeightForWidth(passwordInput->sizePolicy().hasHeightForWidth());
        passwordInput->setSizePolicy(sizePolicy1);
        passwordInput->setMinimumSize(QSize(0, 0));
        passwordInput->setMaximumSize(QSize(16777215, 1000));
        passwordInput->setLayoutDirection(Qt::LeftToRight);
        passwordInput->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
            "background-color: rgb(225, 225, 225);"));
        passwordInput->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(passwordInput, 1, 1, 1, 1);

        emailInput = new QLineEdit(formLayoutWidget);
        emailInput->setObjectName("emailInput");
        sizePolicy1.setHeightForWidth(emailInput->sizePolicy().hasHeightForWidth());
        emailInput->setSizePolicy(sizePolicy1);
        emailInput->setMinimumSize(QSize(0, 0));
        emailInput->setMaximumSize(QSize(16777215, 1000));
        emailInput->setLayoutDirection(Qt::LeftToRight);
        emailInput->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
            "background-color: rgb(225, 225, 225);"));

        gridLayout->addWidget(emailInput, 3, 1, 1, 1);

        codeInput = new QLineEdit(formLayoutWidget);
        codeInput->setObjectName("codeInput");
        sizePolicy1.setHeightForWidth(codeInput->sizePolicy().hasHeightForWidth());
        codeInput->setSizePolicy(sizePolicy1);
        codeInput->setMinimumSize(QSize(0, 0));
        codeInput->setMaximumSize(QSize(16777215, 1000));
        codeInput->setLayoutDirection(Qt::LeftToRight);
        codeInput->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
            "background-color: rgb(225, 225, 225);"));

        gridLayout->addWidget(codeInput, 4, 1, 1, 1);

        minimizeButton = new QPushButton(registerwindowui);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setGeometry(QRect(360, 0, 21, 24));
        minimizeButton->setStyleSheet(QString::fromUtf8("border-radius : 10px;\n"
            "background-color:rgb(170, 255, 255);"));
        closeButton = new QPushButton(registerwindowui);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(390, 0, 21, 24));
        closeButton->setStyleSheet(QString::fromUtf8("border-radius : 16px;\n"
            "background-color: rgb(170, 255, 255);"));
        titleBar->raise();
        registerButton->raise();
        formLayoutWidget->raise();
        closeButton->raise();
        minimizeButton->raise();

        retranslateUi(registerwindowui);

        QMetaObject::connectSlotsByName(registerwindowui);
    } // setupUi

    void retranslateUi(QWidget* registerwindowui)
    {
        registerwindowui->setWindowTitle(QCoreApplication::translate("registerwindowui", "StudySpace", nullptr));
        titleBar->setText(QCoreApplication::translate("registerwindowui", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">\346\263\250\345\206\214\345\212\240\345\205\245Study Space</span></p></body></html>", nullptr));
        registerButton->setText(QCoreApplication::translate("registerwindowui", "\346\263\250\345\206\214", nullptr));
        nameLabel->setText(QCoreApplication::translate("registerwindowui", "\347\224\250\346\210\267\345\220\215", nullptr));
        passwordLable->setText(QCoreApplication::translate("registerwindowui", "\345\257\206\347\240\201", nullptr));
        repasswordLable->setText(QCoreApplication::translate("registerwindowui", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        emailLable->setText(QCoreApplication::translate("registerwindowui", "\351\202\256\347\256\261", nullptr));
#if QT_CONFIG(tooltip)
        codeLable->setToolTip(QCoreApplication::translate("registerwindowui", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        codeLable->setWhatsThis(QCoreApplication::translate("registerwindowui", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        codeLable->setText(QCoreApplication::translate("registerwindowui", "\346\263\250\345\206\214\347\240\201", nullptr));
        minimizeButton->setText(QCoreApplication::translate("registerwindowui", "\342\200\224", nullptr));
        closeButton->setText(QCoreApplication::translate("registerwindowui", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerwindowui : public Ui_registerwindowui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // REGISTERWINDOWACJTBT_H
