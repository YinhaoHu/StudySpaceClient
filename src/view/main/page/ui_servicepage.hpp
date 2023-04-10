/********************************************************************************
** Form generated from reading UI file 'servicepageCNrpao.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SERVICEPAGECNRPAO_H
#define SERVICEPAGECNRPAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_servicepageui
{
public:
    QPushButton* button;
    QLCDNumber* lcdNumber;

    void setupUi(QWidget* servicepageui)
    {
        if (servicepageui->objectName().isEmpty())
            servicepageui->setObjectName("servicepageui");
        servicepageui->resize(870, 700);
        button = new QPushButton(servicepageui);
        button->setObjectName("button");
        button->setGeometry(QRect(320, 340, 251, 141));
        lcdNumber = new QLCDNumber(servicepageui);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(250, 90, 371, 121));

        retranslateUi(servicepageui);

        QMetaObject::connectSlotsByName(servicepageui);
    } // setupUi

    void retranslateUi(QWidget* servicepageui)
    {
        servicepageui->setWindowTitle(QCoreApplication::translate("servicepageui", "Form", nullptr));
        button->setText(QCoreApplication::translate("servicepageui", "Change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class servicepageui : public Ui_servicepageui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SERVICEPAGECNRPAO_H
