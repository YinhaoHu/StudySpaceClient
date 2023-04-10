/********************************************************************************
** Form generated from reading UI file 'servicelisttzMsPS.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SERVICELISTTZMSPS_H
#define SERVICELISTTZMSPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_servicelisui
{
public:
    QLabel *label;

    void setupUi(QWidget *servicelisui)
    {
        if (servicelisui->objectName().isEmpty())
            servicelisui->setObjectName("servicelisui");
        servicelisui->resize(200, 700);
        label = new QLabel(servicelisui);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 200, 300));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));

        retranslateUi(servicelisui);

        QMetaObject::connectSlotsByName(servicelisui);
    } // setupUi

    void retranslateUi(QWidget *servicelisui)
    {
        servicelisui->setWindowTitle(QCoreApplication::translate("servicelisui", "Form", nullptr));
        label->setText(QCoreApplication::translate("servicelisui", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; font-weight:700;\">?</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class servicelisui: public Ui_servicelisui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SERVICELISTTZMSPS_H
