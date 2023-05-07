/********************************************************************************
** Form generated from reading UI file 'focusfeedbackpRAIRi.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FOCUSFEEDBACKPRAIRI_H
#define FOCUSFEEDBACKPRAIRI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_focusfeedback
{
public:
    QLabel* background;
    QLabel* tipLabel;
    QWidget* horizontalLayoutWidget;
    QHBoxLayout* horizontalLayout;
    QPushButton* badButton;
    QPushButton* midButton;
    QPushButton* goodButton;

    void setupUi(QWidget* focusfeedback)
    {
        if (focusfeedback->objectName().isEmpty())
            focusfeedback->setObjectName("focusfeedback");
        focusfeedback->resize(336, 200);
        background = new QLabel(focusfeedback);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 336, 200));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
            "border-style: solid;\n"
            "border-radius: 1em;\n"
            "border-width: 2px;\n"
            "border-color: black;"));
        tipLabel = new QLabel(focusfeedback);
        tipLabel->setObjectName("tipLabel");
        tipLabel->setGeometry(QRect(10, 10, 321, 51));
        QFont font;
        font.setPointSize(21);
        tipLabel->setFont(font);
        tipLabel->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(focusfeedback);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 110, 271, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        badButton = new QPushButton(horizontalLayoutWidget);
        badButton->setObjectName("badButton");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(badButton->sizePolicy().hasHeightForWidth());
        badButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(16);
        badButton->setFont(font1);
        badButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-width: 2px;\n"
            "border-radius: 2em;\n"
            "background-color: rgb(225, 225, 225);\n"
            "border-color: black;\n"
            ""));

        horizontalLayout->addWidget(badButton);

        midButton = new QPushButton(horizontalLayoutWidget);
        midButton->setObjectName("midButton");
        sizePolicy.setHeightForWidth(midButton->sizePolicy().hasHeightForWidth());
        midButton->setSizePolicy(sizePolicy);
        midButton->setFont(font1);
        midButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-width: 2px;\n"
            "border-radius: 2em;\n"
            "background-color: rgb(225, 225, 225);\n"
            "border-color: black;"));

        horizontalLayout->addWidget(midButton);

        goodButton = new QPushButton(horizontalLayoutWidget);
        goodButton->setObjectName("goodButton");
        sizePolicy.setHeightForWidth(goodButton->sizePolicy().hasHeightForWidth());
        goodButton->setSizePolicy(sizePolicy);
        goodButton->setFont(font1);
        goodButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-width: 2px;\n"
            "border-radius: 2em;\n"
            "background-color: rgb(225, 225, 225);\n"
            "border-color: black;"));

        horizontalLayout->addWidget(goodButton);


        retranslateUi(focusfeedback);

        QMetaObject::connectSlotsByName(focusfeedback);
    } // setupUi

    void retranslateUi(QWidget* focusfeedback)
    {
        focusfeedback->setWindowTitle(QCoreApplication::translate("focusfeedback", "FocusFeedBack", nullptr));
        background->setText(QString());
        tipLabel->setText(QCoreApplication::translate("focusfeedback", "\350\277\231\346\254\241\344\270\223\346\263\250\346\264\273\345\212\250\346\225\210\346\236\234\345\246\202\344\275\225\357\274\237", nullptr));
        badButton->setText(QCoreApplication::translate("focusfeedback", "\345\267\256", nullptr));
        midButton->setText(QCoreApplication::translate("focusfeedback", "\344\270\200\350\210\254", nullptr));
        goodButton->setText(QCoreApplication::translate("focusfeedback", "\345\245\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class focusfeedback : public Ui_focusfeedback {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FOCUSFEEDBACKPRAIRI_H
