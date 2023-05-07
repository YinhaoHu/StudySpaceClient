/********************************************************************************
** Form generated from reading UI file 'studyaidspageWOBFHn.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STUDYAIDSPAGEWOBFHN_H
#define STUDYAIDSPAGEWOBFHN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studyaidspage
{
public:
    QLabel* background;

    void setupUi(QWidget* studyaidspage)
    {
        if (studyaidspage->objectName().isEmpty())
            studyaidspage->setObjectName("studyaidspage");
        studyaidspage->resize(870, 700);
        background = new QLabel(studyaidspage);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(studyaidspage);

        QMetaObject::connectSlotsByName(studyaidspage);
    } // setupUi

    void retranslateUi(QWidget* studyaidspage)
    {
        studyaidspage->setWindowTitle(QCoreApplication::translate("studyaidspage", "Form", nullptr));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class studyaidspage : public Ui_studyaidspage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STUDYAIDSPAGEWOBFHN_H
