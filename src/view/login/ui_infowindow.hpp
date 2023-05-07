/********************************************************************************
** Form generated from reading UI file 'infowindowovviie.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef INFOWINDOWOVVIIE_H
#define INFOWINDOWOVVIIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_infowindow_ui
{
public:
    QLabel* titleBar;
    QPushButton* minimizeButton;
    QPushButton* closeButton;
    QWidget* verticalLayoutWidget;
    QVBoxLayout* verticalLayout;
    QTextBrowser* infoBrowser;
    QLabel* contactLabel;
    QLabel* copyrightLabel;

    void setupUi(QWidget* infowindow_ui)
    {
        if (infowindow_ui->objectName().isEmpty())
            infowindow_ui->setObjectName("infowindow_ui");
        infowindow_ui->resize(422, 494);
        infowindow_ui->setStyleSheet(QString::fromUtf8("background-color: white;"));
        titleBar = new QLabel(infowindow_ui);
        titleBar->setObjectName("titleBar");
        titleBar->setGeometry(QRect(0, 0, 431, 91));
        titleBar->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 255, 255);"));
        minimizeButton = new QPushButton(infowindow_ui);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setGeometry(QRect(370, 0, 21, 24));
        minimizeButton->setStyleSheet(QString::fromUtf8("border-radius : 10px;\n"
            "background-color:rgb(170, 255, 255);"));
        closeButton = new QPushButton(infowindow_ui);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(400, 0, 21, 24));
        closeButton->setStyleSheet(QString::fromUtf8("border-radius : 16px;\n"
            "background-color: rgb(170, 255, 255);"));
        verticalLayoutWidget = new QWidget(infowindow_ui);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 100, 421, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        infoBrowser = new QTextBrowser(verticalLayoutWidget);
        infoBrowser->setObjectName("infoBrowser");

        verticalLayout->addWidget(infoBrowser);

        contactLabel = new QLabel(verticalLayoutWidget);
        contactLabel->setObjectName("contactLabel");

        verticalLayout->addWidget(contactLabel);

        copyrightLabel = new QLabel(verticalLayoutWidget);
        copyrightLabel->setObjectName("copyrightLabel");

        verticalLayout->addWidget(copyrightLabel);


        retranslateUi(infowindow_ui);

        QMetaObject::connectSlotsByName(infowindow_ui);
    } // setupUi

    void retranslateUi(QWidget* infowindow_ui)
    {
        infowindow_ui->setWindowTitle(QCoreApplication::translate("infowindow_ui", "StudySpace", nullptr));
        titleBar->setText(QCoreApplication::translate("infowindow_ui", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700;\">\345\205\263\344\272\216 Study Space</span></p></body></html>", nullptr));
        minimizeButton->setText(QCoreApplication::translate("infowindow_ui", "\342\200\224", nullptr));
        closeButton->setText(QCoreApplication::translate("infowindow_ui", "X", nullptr));
        infoBrowser->setHtml(QCoreApplication::translate("infowindow_ui", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
            "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
            "p, li { white-space: pre-wrap; }\n"
            "hr { height: 1px; border-width: 0; }\n"
            "li.unchecked::marker { content: \"\\2610\"; }\n"
            "li.checked::marker { content: \"\\2612\"; }\n"
            "</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
            "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">        Info: StudySpace is an open source software which is based on Qt framework and written in C++ programming language. </span></p>\n"
            "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">        Situation: building.</span></p>\n"
            "<p style=\" margin-top:"
            "0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">        Version: 1.0</span></p></body></html>", nullptr));
        contactLabel->setText(QCoreApplication::translate("infowindow_ui", "<html><head/><body><p align=\"center\">Contact: henryhoo@qq.com</p></body></html>", nullptr));
        copyrightLabel->setText(QCoreApplication::translate("infowindow_ui", "<html><head/><body><p align=\"center\">Copyright \302\2512023-2023 Henry Hoo. All Right Reserved.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infowindow_ui : public Ui_infowindow_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INFOWINDOWOVVIIE_H
