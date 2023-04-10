/********************************************************************************
** Form generated from reading UI file 'servicepagePfEVuV.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SERVICEPAGEPFEVUV_H
#define SERVICEPAGEPFEVUV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_servicepageui
{
public:
    QPushButton* button;
    QLabel* colorLabel;

    void setupUi(QWidget* servicepageui)
    {
        if (servicepageui->objectName().isEmpty())
            servicepageui->setObjectName("servicepageui");
        servicepageui->resize(870, 700);
        button = new QPushButton(servicepageui);
        button->setObjectName("button");
        button->setGeometry(QRect(320, 340, 251, 141));
        colorLabel = new QLabel(servicepageui);
        colorLabel->setObjectName("colorLabel");
        colorLabel->setGeometry(QRect(200, 60, 511, 191));

        retranslateUi(servicepageui);

        QMetaObject::connectSlotsByName(servicepageui);
    } // setupUi

    void retranslateUi(QWidget* servicepageui)
    {
        servicepageui->setWindowTitle(QCoreApplication::translate("servicepageui", "Form", nullptr));
        button->setText(QCoreApplication::translate("servicepageui", "Change Color", nullptr));
        colorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class servicepageui : public Ui_servicepageui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SERVICEPAGEPFEVUV_H
