/********************************************************************************
** Form generated from reading UI file 'feedbackwindowtDKapo.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FEEDBACKWINDOWTDKAPO_H
#define FEEDBACKWINDOWTDKAPO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeedBackWindow
{
public:
    QLabel *background;
    QLabel *titleLabel;
    QTextEdit *inputArea;
    QPushButton *sendButton;
    QPushButton *quitButton;

    void setupUi(QWidget *FeedBackWindow)
    {
        if (FeedBackWindow->objectName().isEmpty())
            FeedBackWindow->setObjectName("FeedBackWindow");
        FeedBackWindow->resize(300, 500);
        background = new QLabel(FeedBackWindow);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 300, 500));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-color:  rgb(0, 0, 0);\n"
"border-radius: 16px;"));
        titleLabel = new QLabel(FeedBackWindow);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(10, 30, 280, 50));
        titleLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 16pt \"Microsoft YaHei UI\";\n"
"text-decoration: underline;"));
        inputArea = new QTextEdit(FeedBackWindow);
        inputArea->setObjectName("inputArea");
        inputArea->setGeometry(QRect(30, 90, 251, 341));
        QFont font;
        font.setPointSize(12);
        inputArea->setFont(font);
        sendButton = new QPushButton(FeedBackWindow);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(30, 450, 251, 31));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        sendButton->setFont(font1);
        quitButton = new QPushButton(FeedBackWindow);
        quitButton->setObjectName("quitButton");
        quitButton->setGeometry(QRect(265, 5, 25, 25));
        quitButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 16px;\n"
"border-style:solid;\n"
"font: 700 16pt \"Microsoft YaHei UI\";"));

        retranslateUi(FeedBackWindow);

        QMetaObject::connectSlotsByName(FeedBackWindow);
    } // setupUi

    void retranslateUi(QWidget *FeedBackWindow)
    {
        FeedBackWindow->setWindowTitle(QCoreApplication::translate("FeedBackWindow", "Form", nullptr));
        background->setText(QString());
        titleLabel->setText(QCoreApplication::translate("FeedBackWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\345\241\253\345\206\231\344\275\240\347\232\204\345\217\215\351\246\210\345\206\205\345\256\271</span></p></body></html>", nullptr));
        sendButton->setText(QCoreApplication::translate("FeedBackWindow", "\345\217\215\351\246\210", nullptr));
        quitButton->setText(QCoreApplication::translate("FeedBackWindow", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FeedBackWindow: public Ui_FeedBackWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FEEDBACKWINDOWTDKAPO_H
