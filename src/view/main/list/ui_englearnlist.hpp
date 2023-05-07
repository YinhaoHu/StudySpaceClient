/********************************************************************************
** Form generated from reading UI file 'englearnlistrRcYXy.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ENGLEARNLISTRRCYXY_H
#define ENGLEARNLISTRRCYXY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_englearnlistui
{
public:
    QLabel* label;
    QLabel* background;

    void setupUi(QWidget* englearnlistui)
    {
        if (englearnlistui->objectName().isEmpty())
            englearnlistui->setObjectName("englearnlistui");
        englearnlistui->resize(200, 700);
        englearnlistui->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(englearnlistui);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 181, 121));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
            "border-style: solid;\n"
            "border-width: 4px;\n"
            "border-style: solid;\n"
            "border-radius: 16px;"));
        background = new QLabel(englearnlistui);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 200, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        background->raise();
        label->raise();

        retranslateUi(englearnlistui);

        QMetaObject::connectSlotsByName(englearnlistui);
    } // setupUi

    void retranslateUi(QWidget* englearnlistui)
    {
        englearnlistui->setWindowTitle(QCoreApplication::translate("englearnlistui", "Form", nullptr));
        label->setText(QCoreApplication::translate("englearnlistui", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; color:#919191;\">English Learning </span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; color:#919191;\">Area</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; color:#919191;\">is still building.</span></p></body></html>", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class englearnlistui : public Ui_englearnlistui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ENGLEARNLISTRRCYXY_H
