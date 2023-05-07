/********************************************************************************
** Form generated from reading UI file 'addfriendformkYhPjE.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADDFRIENDFORMKYHPJE_H
#define ADDFRIENDFORMKYHPJE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendForm
{
public:
    QLabel* background;
    QLabel* idLabel;
    QLineEdit* numberInput;
    QPushButton* makeAddButton;

    void setupUi(QWidget* AddFriendForm)
    {
        if (AddFriendForm->objectName().isEmpty())
            AddFriendForm->setObjectName("AddFriendForm");
        AddFriendForm->resize(500, 400);
        background = new QLabel(AddFriendForm);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 500, 400));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
            "border-width: 2px;\n"
            "border-style: solid;\n"
            "border-color:   rgb(0, 0, 0);\n"
            "border-radius: 8px;"));
        idLabel = new QLabel(AddFriendForm);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(90, 160, 50, 50));
        numberInput = new QLineEdit(AddFriendForm);
        numberInput->setObjectName("numberInput");
        numberInput->setGeometry(QRect(160, 160, 231, 50));
        QFont font;
        font.setPointSize(20);
        numberInput->setFont(font);
        numberInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        makeAddButton = new QPushButton(AddFriendForm);
        makeAddButton->setObjectName("makeAddButton");
        makeAddButton->setGeometry(QRect(160, 240, 231, 41));
        makeAddButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(AddFriendForm);

        QMetaObject::connectSlotsByName(AddFriendForm);
    } // setupUi

    void retranslateUi(QWidget* AddFriendForm)
    {
        AddFriendForm->setWindowTitle(QCoreApplication::translate("AddFriendForm", "Form", nullptr));
        background->setText(QString());
        idLabel->setText(QCoreApplication::translate("AddFriendForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700;\">ID</span></p></body></html>", nullptr));
        numberInput->setText(QString());
        makeAddButton->setText(QCoreApplication::translate("AddFriendForm", "\346\267\273\345\212\240\346\255\244\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriendForm : public Ui_AddFriendForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADDFRIENDFORMKYHPJE_H
