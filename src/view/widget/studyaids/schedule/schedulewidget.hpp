/********************************************************************************
** Form generated from reading UI file 'schedulewidgetHfpWjZ.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SCHEDULEWIDGETHFPWJZ_H
#define SCHEDULEWIDGETHFPWJZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scheduleWidget
{
public:
    QLabel* background;
    QWidget* navwidget;
    QLabel* navbackground;
    QPushButton* todayschedulebutton;
    QPushButton* duemissionbutton;
    QPushButton* weeklyschedulebutton;
    QWidget* contentwidget;

    void setupUi(QWidget* scheduleWidget)
    {
        if (scheduleWidget->objectName().isEmpty())
            scheduleWidget->setObjectName("scheduleWidget");
        scheduleWidget->resize(870, 700);
        background = new QLabel(scheduleWidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 234, 234);"));
        navwidget = new QWidget(scheduleWidget);
        navwidget->setObjectName("navwidget");
        navwidget->setGeometry(QRect(0, 650, 870, 50));
        navwidget->setStyleSheet(QString::fromUtf8(""));
        navbackground = new QLabel(navwidget);
        navbackground->setObjectName("navbackground");
        navbackground->setGeometry(QRect(0, 0, 870, 50));
        navbackground->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 46, 46);"));
        todayschedulebutton = new QPushButton(navwidget);
        todayschedulebutton->setObjectName("todayschedulebutton");
        todayschedulebutton->setGeometry(QRect(5, 5, 280, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(todayschedulebutton->sizePolicy().hasHeightForWidth());
        todayschedulebutton->setSizePolicy(sizePolicy);
        todayschedulebutton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-radius: 1em;\n"
            "border-width:2px;\n"
            "background-color: rgb(126, 126, 126);\n"
            "font: 12pt \"Microsoft YaHei UI\";"));
        duemissionbutton = new QPushButton(navwidget);
        duemissionbutton->setObjectName("duemissionbutton");
        duemissionbutton->setGeometry(QRect(584, 5, 280, 40));
        sizePolicy.setHeightForWidth(duemissionbutton->sizePolicy().hasHeightForWidth());
        duemissionbutton->setSizePolicy(sizePolicy);
        duemissionbutton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-radius: 1em;\n"
            "border-width:2px;\n"
            "background-color: rgb(126, 126, 126);\n"
            "font: 12pt \"Microsoft YaHei UI\";"));
        weeklyschedulebutton = new QPushButton(navwidget);
        weeklyschedulebutton->setObjectName("weeklyschedulebutton");
        weeklyschedulebutton->setGeometry(QRect(293, 5, 280, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(weeklyschedulebutton->sizePolicy().hasHeightForWidth());
        weeklyschedulebutton->setSizePolicy(sizePolicy1);
        weeklyschedulebutton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-radius: 1em;\n"
            "border-width:2px;\n"
            "background-color: rgb(126, 126, 126);\n"
            "font: 12pt \"Microsoft YaHei UI\";"));
        contentwidget = new QWidget(scheduleWidget);
        contentwidget->setObjectName("contentwidget");
        contentwidget->setGeometry(QRect(0, 0, 870, 650));

        retranslateUi(scheduleWidget);

        QMetaObject::connectSlotsByName(scheduleWidget);
    } // setupUi

    void retranslateUi(QWidget* scheduleWidget)
    {
        scheduleWidget->setWindowTitle(QCoreApplication::translate("scheduleWidget", "Form", nullptr));
        background->setText(QString());
        navbackground->setText(QString());
        todayschedulebutton->setText(QCoreApplication::translate("scheduleWidget", "\344\273\212\346\227\245\344\273\273\345\212\241", nullptr));
        duemissionbutton->setText(QCoreApplication::translate("scheduleWidget", "\345\200\222\350\256\241\346\227\266\344\273\273\345\212\241", nullptr));
        weeklyschedulebutton->setText(QCoreApplication::translate("scheduleWidget", "\345\221\250\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scheduleWidget : public Ui_scheduleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SCHEDULEWIDGETHFPWJZ_H
