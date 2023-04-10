/********************************************************************************
** Form generated from reading UI file 'englearnlistgPPTJt.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ENGLEARNLISTGPPTJT_H
#define ENGLEARNLISTGPPTJT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_englearnlistui
{
public:
    QLabel *label;

    void setupUi(QWidget *englearnlistui)
    {
        if (englearnlistui->objectName().isEmpty())
            englearnlistui->setObjectName("englearnlistui");
        englearnlistui->resize(200, 700);
        englearnlistui->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(englearnlistui);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 181, 121));

        retranslateUi(englearnlistui);

        QMetaObject::connectSlotsByName(englearnlistui);
    } // setupUi

    void retranslateUi(QWidget *englearnlistui)
    {
        englearnlistui->setWindowTitle(QCoreApplication::translate("englearnlistui", "Form", nullptr));
        label->setText(QCoreApplication::translate("englearnlistui", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; color:#919191;\">English Learning </span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; color:#919191;\">Area</span></p><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; font-style:italic; color:#919191;\">is still building.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class englearnlistui: public Ui_englearnlistui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ENGLEARNLISTGPPTJT_H
