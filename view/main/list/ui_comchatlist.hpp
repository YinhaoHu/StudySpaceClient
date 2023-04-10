/********************************************************************************
** Form generated from reading UI file 'comchatyJpbdI.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef COMCHATYJPBDI_H
#define COMCHATYJPBDI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uicomchat
{
public:
    QTextBrowser* sloganBar;

    void setupUi(QWidget* uicomchat)
    {
        if (uicomchat->objectName().isEmpty())
            uicomchat->setObjectName("uicomchat");
        uicomchat->resize(200, 700);
        uicomchat->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        sloganBar = new QTextBrowser(uicomchat);
        sloganBar->setObjectName("sloganBar");
        sloganBar->setGeometry(QRect(0, 0, 201, 131));
        sloganBar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
            "border-color: rgb(0, 0, 0);"));

        retranslateUi(uicomchat);

        QMetaObject::connectSlotsByName(uicomchat);
    } // setupUi

    void retranslateUi(QWidget* uicomchat)
    {
        uicomchat->setWindowTitle(QCoreApplication::translate("uicomchat", "Form", nullptr));
        sloganBar->setHtml(QCoreApplication::translate("uicomchat", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
            "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
            "p, li { white-space: pre-wrap; }\n"
            "hr { height: 1px; border-width: 0; }\n"
            "li.unchecked::marker { content: \"\\2610\"; }\n"
            "li.checked::marker { content: \"\\2612\"; }\n"
            "</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
            "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">  \347\244\276\345\214\272\350\256\250\350\256\272</span></p>\n"
            "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\342\200\224\342\200\224\342\200\224\342\200\224\342\200\224</span></p>\n"
            "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; m"
            "argin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">	\345\234\250\350\277\231\351\207\214\357\274\214\344\270\216\344\275\240\347\232\204\344\274\231\344\274\264\344\272\244\346\265\201\343\200\202</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uicomchat : public Ui_uicomchat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // COMCHATYJPBDI_H
