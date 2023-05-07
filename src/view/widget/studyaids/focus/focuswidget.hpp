/********************************************************************************
** Form generated from reading UI file 'focuswidgetQQyjTC.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FOCUSWIDGETQQYJTC_H
#define FOCUSWIDGETQQYJTC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FocusWidget
{
public:
    QLabel *background;
    QLabel *navBarBackGround;
    QWidget *contentWidget;
    QPushButton *startFocusButton;
    QPushButton *dataViewButton;

    void setupUi(QWidget *FocusWidget)
    {
        if (FocusWidget->objectName().isEmpty())
            FocusWidget->setObjectName("FocusWidget");
        FocusWidget->resize(870, 700);
        FocusWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        background = new QLabel(FocusWidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 234, 234);"));
        navBarBackGround = new QLabel(FocusWidget);
        navBarBackGround->setObjectName("navBarBackGround");
        navBarBackGround->setGeometry(QRect(0, 630, 870, 70));
        navBarBackGround->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 234, 234);"));
        contentWidget = new QWidget(FocusWidget);
        contentWidget->setObjectName("contentWidget");
        contentWidget->setGeometry(QRect(0, 0, 870, 621));
        contentWidget->setStyleSheet(QString::fromUtf8(""));
        startFocusButton = new QPushButton(FocusWidget);
        startFocusButton->setObjectName("startFocusButton");
        startFocusButton->setGeometry(QRect(5, 625, 425, 69));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startFocusButton->sizePolicy().hasHeightForWidth());
        startFocusButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        startFocusButton->setFont(font);
        startFocusButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 2px;\n"
"border-color:   rgb(0, 0, 0);\n"
"background-color:  rgb(240, 240, 240);\n"
"border-radius: 2em;"));
        dataViewButton = new QPushButton(FocusWidget);
        dataViewButton->setObjectName("dataViewButton");
        dataViewButton->setGeometry(QRect(435, 625, 425, 69));
        sizePolicy.setHeightForWidth(dataViewButton->sizePolicy().hasHeightForWidth());
        dataViewButton->setSizePolicy(sizePolicy);
        dataViewButton->setFont(font);
        dataViewButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-width: 2px;\n"
"border-color:   rgb(0, 0, 0);\n"
"background-color:  rgb(240, 240, 240);\n"
"border-radius: 2em;"));
        background->raise();
        navBarBackGround->raise();
        startFocusButton->raise();
        dataViewButton->raise();
        contentWidget->raise();

        retranslateUi(FocusWidget);

        QMetaObject::connectSlotsByName(FocusWidget);
    } // setupUi

    void retranslateUi(QWidget *FocusWidget)
    {
        FocusWidget->setWindowTitle(QCoreApplication::translate("FocusWidget", "Form", nullptr));
        background->setText(QString());
        navBarBackGround->setText(QString());
        startFocusButton->setText(QCoreApplication::translate("FocusWidget", "\345\274\200\345\247\213\344\270\223\346\263\250", nullptr));
        dataViewButton->setText(QCoreApplication::translate("FocusWidget", "\350\256\260\345\275\225\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FocusWidget: public Ui_FocusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FOCUSWIDGETQQYJTC_H
