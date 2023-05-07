/********************************************************************************
** Form generated from reading UI file 'todolistitemwxhWQx.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TODOLISTITEMWXHWQX_H
#define TODOLISTITEMWXHWQX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_todolistitem
{
public:
    QLabel* background;
    QPushButton* finishButton;
    QLabel* contentLabel;

    void setupUi(QWidget* todolistitem)
    {
        if (todolistitem->objectName().isEmpty())
            todolistitem->setObjectName("todolistitem");
        todolistitem->resize(550, 60);
        background = new QLabel(todolistitem);
        background->setObjectName("background");
        background->setGeometry(QRect(5, 5, 535, 50));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 246, 246);\n"
            "border-style: solid;\n"
            "border-radius: 1em;"));
        finishButton = new QPushButton(todolistitem);
        finishButton->setObjectName("finishButton");
        finishButton->setGeometry(QRect(20, 15, 20, 20));
        finishButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-radius: 0.5em;\n"
            "border-width: 2px;\n"
            "border-color: black;\n"
            "background-color: rgb(246, 246, 246);"));
        contentLabel = new QLabel(todolistitem);
        contentLabel->setObjectName("contentLabel");
        contentLabel->setGeometry(QRect(80, 5, 440, 35));
        QFont font;
        font.setPointSize(14);
        contentLabel->setFont(font);
        contentLabel->setStyleSheet(QString::fromUtf8("background-color: white;\n"
            "background-color: rgb(246, 246, 246);\n"
            ""));

        retranslateUi(todolistitem);

        QMetaObject::connectSlotsByName(todolistitem);
    } // setupUi

    void retranslateUi(QWidget* todolistitem)
    {
        todolistitem->setWindowTitle(QCoreApplication::translate("todolistitem", "Form", nullptr));
        background->setText(QString());
        finishButton->setText(QString());
        contentLabel->setText(QCoreApplication::translate("todolistitem", "Content", nullptr));
    } // retranslateUi

};

namespace Ui {
    class todolistitem : public Ui_todolistitem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TODOLISTITEMWXHWQX_H
