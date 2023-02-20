/********************************************************************************
** Form generated from reading UI file 'englearnpageHHBFAD.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ENGLEARNPAGEHHBFAD_H
#define ENGLEARNPAGEHHBFAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_englearnpageui
{
public:
    QLabel* displayLabel;

    void setupUi(QWidget* englearnpageui)
    {
        if (englearnpageui->objectName().isEmpty())
            englearnpageui->setObjectName("englearnpageui");
        englearnpageui->resize(870, 700);
        englearnpageui->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        displayLabel = new QLabel(englearnpageui);
        displayLabel->setObjectName("displayLabel");
        displayLabel->setGeometry(QRect(0, 0, 871, 701));

        retranslateUi(englearnpageui);

        QMetaObject::connectSlotsByName(englearnpageui);
    } // setupUi

    void retranslateUi(QWidget* englearnpageui)
    {
        englearnpageui->setWindowTitle(QCoreApplication::translate("englearnpageui", "Form", nullptr));
        displayLabel->setText(QCoreApplication::translate("englearnpageui", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; font-weight:700;\">:)</span></p><p align=\"center\"><span style=\" font-size:48pt;\">Comming Soon...</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class englearnpageui : public Ui_englearnpageui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ENGLEARNPAGEHHBFAD_H
