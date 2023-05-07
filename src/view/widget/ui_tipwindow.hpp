/********************************************************************************
** Form generated from reading UI file 'tipwindowNwUgEl.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TIPWINDOWNWUGEL_H
#define TIPWINDOWNWUGEL_H

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
    QLabel* background;

    void setupUi(QWidget* tipwindowui)
    {
        if (tipwindowui->objectName().isEmpty())
            tipwindowui->setObjectName("tipwindowui");
        tipwindowui->resize(300, 180);
        tipwindowui->setStyleSheet(QString::fromUtf8(""));
        okButton = new QPushButton(tipwindowui);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(50, 140, 200, 30));
        okButton->setStyleSheet(QString::fromUtf8("background-color: rgb(197, 197, 197);\n"
            "font-size: 16px;\n"
            "border-radius: 10px;\n"
            "opacity: 0.1;"));
        msgLabel = new QLabel(tipwindowui);
        msgLabel->setObjectName("msgLabel");
        msgLabel->setGeometry(QRect(25, 15, 250, 100));
        QFont font;
        font.setPointSize(12);
        msgLabel->setFont(font);
        msgLabel->setWordWrap(true);
        background = new QLabel(tipwindowui);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 300, 180));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
            "border-width: 2px;\n"
            "border-radius: 12px;\n"
            "border-style: solid;\n"
            "border-color:  rgb(0, 0, 0);"));
        background->raise();
        okButton->raise();
        msgLabel->raise();

        retranslateUi(tipwindowui);

        QMetaObject::connectSlotsByName(tipwindowui);
    } // setupUi

    void retranslateUi(QWidget* tipwindowui)
    {
        tipwindowui->setWindowTitle(QCoreApplication::translate("tipwindowui", "MessageBar", nullptr));
        okButton->setText(QCoreApplication::translate("tipwindowui", "\345\245\275\347\232\204", nullptr));
        msgLabel->setText(QCoreApplication::translate("tipwindowui", "TipContent", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tipwindowui : public Ui_tipwindowui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TIPWINDOWNWUGEL_H
