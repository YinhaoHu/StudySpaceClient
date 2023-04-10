/********************************************************************************
** Form generated from reading UI file 'tipwindowvoyVTt.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TIPWINDOWVOYVTT_H
#define TIPWINDOWVOYVTT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tipwindowui
{
public:
    QPushButton* okButton;
    QLabel* msgLabel;

    void setupUi(QWidget* tipwindowui)
    {
        if (tipwindowui->objectName().isEmpty())
            tipwindowui->setObjectName("tipwindowui");
        tipwindowui->resize(287, 146);
        tipwindowui->setStyleSheet(QString::fromUtf8("background-color:rgb(154, 154, 154);\n"
            "radius: 10px;"));
        okButton = new QPushButton(tipwindowui);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(50, 100, 191, 31));
        okButton->setStyleSheet(QString::fromUtf8("background-color:rgb(202, 202, 202);\n"
            "font-size: 16px;\n"
            "border-radius: 10px;\n"
            "opacity: 0.1;"));
        msgLabel = new QLabel(tipwindowui);
        msgLabel->setObjectName("msgLabel");
        msgLabel->setGeometry(QRect(40, 10, 211, 61));
        msgLabel->setStyleSheet(QString::fromUtf8("font-size:26px;"));

        retranslateUi(tipwindowui);

        QMetaObject::connectSlotsByName(tipwindowui);
    } // setupUi

    void retranslateUi(QWidget* tipwindowui)
    {
        tipwindowui->setWindowTitle(QCoreApplication::translate("tipwindowui", "MessageBar", nullptr));
        okButton->setText(QCoreApplication::translate("tipwindowui", "\345\245\275\347\232\204", nullptr));
        msgLabel->setText(QCoreApplication::translate("tipwindowui", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">\346\217\220\347\244\272\345\206\205\345\256\271</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tipwindowui : public Ui_tipwindowui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TIPWINDOWVOYVTT_H
