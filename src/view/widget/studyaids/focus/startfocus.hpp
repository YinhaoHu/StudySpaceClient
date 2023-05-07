/********************************************************************************
** Form generated from reading UI file 'startfocusZqfAMY.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STARTFOCUSZQFAMY_H
#define STARTFOCUSZQFAMY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartFocus
{
public:
    QLabel* background;
    QWidget* timeInfoWidget;
    QProgressBar* timeBar;
    QWidget* timeInfoDisplayWidget;
    QWidget* horizontalLayoutWidget;
    QHBoxLayout* timeDisplayWidgetLayout;
    QLCDNumber* hourLCD;
    QFrame* leftLine;
    QLabel* hourLabel;
    QFrame* midLine;
    QLCDNumber* minuteLCD;
    QLabel* miniteLabel;
    QFrame* rightLine;
    QLabel* timeInfoBackground;
    QWidget* timeInfoSetWidget;
    QWidget* horizontalLayoutWidget_3;
    QHBoxLayout* timeInfoSetLayout;
    QLabel* timeInfoSetTip;
    QTimeEdit* timeInfoSetInput;
    QWidget* controlWidget;
    QWidget* horizontalLayoutWidget_2;
    QHBoxLayout* controlWidgetLayout;
    QPushButton* controlButton;
    QPushButton* endButton;
    QPushButton* startButton;

    void setupUi(QWidget* StartFocus)
    {
        if (StartFocus->objectName().isEmpty())
            StartFocus->setObjectName("StartFocus");
        StartFocus->resize(870, 620);
        background = new QLabel(StartFocus);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 620));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 234, 234);"));
        timeInfoWidget = new QWidget(StartFocus);
        timeInfoWidget->setObjectName("timeInfoWidget");
        timeInfoWidget->setGeometry(QRect(289, 30, 301, 381));
        timeInfoWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
            ""));
        timeBar = new QProgressBar(timeInfoWidget);
        timeBar->setObjectName("timeBar");
        timeBar->setGeometry(QRect(30, 10, 240, 301));
        timeBar->setStyleSheet(QString::fromUtf8(""));
        timeBar->setValue(24);
        timeBar->setOrientation(Qt::Vertical);
        timeBar->setInvertedAppearance(false);
        timeInfoDisplayWidget = new QWidget(timeInfoWidget);
        timeInfoDisplayWidget->setObjectName("timeInfoDisplayWidget");
        timeInfoDisplayWidget->setGeometry(QRect(10, 320, 280, 51));
        horizontalLayoutWidget = new QWidget(timeInfoDisplayWidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 281, 51));
        timeDisplayWidgetLayout = new QHBoxLayout(horizontalLayoutWidget);
        timeDisplayWidgetLayout->setSpacing(10);
        timeDisplayWidgetLayout->setObjectName("timeDisplayWidgetLayout");
        timeDisplayWidgetLayout->setContentsMargins(0, 0, 0, 0);
        hourLCD = new QLCDNumber(horizontalLayoutWidget);
        hourLCD->setObjectName("hourLCD");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hourLCD->sizePolicy().hasHeightForWidth());
        hourLCD->setSizePolicy(sizePolicy);

        timeDisplayWidgetLayout->addWidget(hourLCD);

        leftLine = new QFrame(horizontalLayoutWidget);
        leftLine->setObjectName("leftLine");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftLine->sizePolicy().hasHeightForWidth());
        leftLine->setSizePolicy(sizePolicy1);
        leftLine->setFrameShape(QFrame::VLine);
        leftLine->setFrameShadow(QFrame::Sunken);

        timeDisplayWidgetLayout->addWidget(leftLine);

        hourLabel = new QLabel(horizontalLayoutWidget);
        hourLabel->setObjectName("hourLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(hourLabel->sizePolicy().hasHeightForWidth());
        hourLabel->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(16);
        hourLabel->setFont(font);
        hourLabel->setAlignment(Qt::AlignCenter);

        timeDisplayWidgetLayout->addWidget(hourLabel);

        midLine = new QFrame(horizontalLayoutWidget);
        midLine->setObjectName("midLine");
        sizePolicy1.setHeightForWidth(midLine->sizePolicy().hasHeightForWidth());
        midLine->setSizePolicy(sizePolicy1);
        midLine->setFrameShape(QFrame::VLine);
        midLine->setFrameShadow(QFrame::Sunken);

        timeDisplayWidgetLayout->addWidget(midLine);

        minuteLCD = new QLCDNumber(horizontalLayoutWidget);
        minuteLCD->setObjectName("minuteLCD");
        sizePolicy.setHeightForWidth(minuteLCD->sizePolicy().hasHeightForWidth());
        minuteLCD->setSizePolicy(sizePolicy);

        timeDisplayWidgetLayout->addWidget(minuteLCD);

        miniteLabel = new QLabel(horizontalLayoutWidget);
        miniteLabel->setObjectName("miniteLabel");
        sizePolicy2.setHeightForWidth(miniteLabel->sizePolicy().hasHeightForWidth());
        miniteLabel->setSizePolicy(sizePolicy2);
        miniteLabel->setFont(font);
        miniteLabel->setAlignment(Qt::AlignCenter);

        timeDisplayWidgetLayout->addWidget(miniteLabel);

        rightLine = new QFrame(horizontalLayoutWidget);
        rightLine->setObjectName("rightLine");
        rightLine->setFrameShape(QFrame::VLine);
        rightLine->setFrameShadow(QFrame::Sunken);

        timeDisplayWidgetLayout->addWidget(rightLine);

        timeDisplayWidgetLayout->setStretch(0, 6);
        timeDisplayWidgetLayout->setStretch(2, 1);
        timeDisplayWidgetLayout->setStretch(4, 6);
        timeDisplayWidgetLayout->setStretch(5, 1);
        timeInfoBackground = new QLabel(timeInfoWidget);
        timeInfoBackground->setObjectName("timeInfoBackground");
        timeInfoBackground->setGeometry(QRect(0, 0, 301, 381));
        timeInfoBackground->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-width: 2px;\n"
            "border-color:black;"));
        timeInfoSetWidget = new QWidget(timeInfoWidget);
        timeInfoSetWidget->setObjectName("timeInfoSetWidget");
        timeInfoSetWidget->setGeometry(QRect(10, 310, 281, 68));
        horizontalLayoutWidget_3 = new QWidget(timeInfoSetWidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 271, 51));
        timeInfoSetLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        timeInfoSetLayout->setObjectName("timeInfoSetLayout");
        timeInfoSetLayout->setContentsMargins(0, 0, 0, 0);
        timeInfoSetTip = new QLabel(horizontalLayoutWidget_3);
        timeInfoSetTip->setObjectName("timeInfoSetTip");
        timeInfoSetTip->setFont(font);

        timeInfoSetLayout->addWidget(timeInfoSetTip);

        timeInfoSetInput = new QTimeEdit(horizontalLayoutWidget_3);
        timeInfoSetInput->setObjectName("timeInfoSetInput");
        timeInfoSetInput->setFont(font);

        timeInfoSetLayout->addWidget(timeInfoSetInput);

        timeInfoBackground->raise();
        timeBar->raise();
        timeInfoDisplayWidget->raise();
        timeInfoSetWidget->raise();
        controlWidget = new QWidget(StartFocus);
        controlWidget->setObjectName("controlWidget");
        controlWidget->setGeometry(QRect(280, 450, 320, 75));
        controlWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget_2 = new QWidget(controlWidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 321, 81));
        controlWidgetLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        controlWidgetLayout->setSpacing(10);
        controlWidgetLayout->setObjectName("controlWidgetLayout");
        controlWidgetLayout->setSizeConstraint(QLayout::SetNoConstraint);
        controlWidgetLayout->setContentsMargins(10, 10, 10, 10);
        controlButton = new QPushButton(horizontalLayoutWidget_2);
        controlButton->setObjectName("controlButton");
        sizePolicy2.setHeightForWidth(controlButton->sizePolicy().hasHeightForWidth());
        controlButton->setSizePolicy(sizePolicy2);
        controlButton->setFont(font);
        controlButton->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
            "border-radius:8px;\n"
            "background-color: white;"));

        controlWidgetLayout->addWidget(controlButton);

        endButton = new QPushButton(horizontalLayoutWidget_2);
        endButton->setObjectName("endButton");
        sizePolicy2.setHeightForWidth(endButton->sizePolicy().hasHeightForWidth());
        endButton->setSizePolicy(sizePolicy2);
        endButton->setFont(font);
        endButton->setStyleSheet(QString::fromUtf8("border-style:solid;\n"
            "border-radius:8px;\n"
            "background-color: white;"));

        controlWidgetLayout->addWidget(endButton);

        controlWidgetLayout->setStretch(0, 1);
        controlWidgetLayout->setStretch(1, 1);
        startButton = new QPushButton(StartFocus);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(280, 450, 320, 75));
        QFont font1;
        font1.setPointSize(32);
        startButton->setFont(font1);
        startButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-radius:2em;\n"
            "background-color: rgb(255, 255, 255);"));

        retranslateUi(StartFocus);

        QMetaObject::connectSlotsByName(StartFocus);
    } // setupUi

    void retranslateUi(QWidget* StartFocus)
    {
        StartFocus->setWindowTitle(QCoreApplication::translate("StartFocus", "Form", nullptr));
        background->setText(QString());
        hourLabel->setText(QCoreApplication::translate("StartFocus", "\345\260\217\346\227\266", nullptr));
        miniteLabel->setText(QCoreApplication::translate("StartFocus", "\345\210\206\351\222\237", nullptr));
        timeInfoBackground->setText(QString());
        timeInfoSetTip->setText(QCoreApplication::translate("StartFocus", "\344\270\223\346\263\250\346\227\266\351\227\264", nullptr));
        timeInfoSetInput->setDisplayFormat(QCoreApplication::translate("StartFocus", "h:mm", nullptr));
        controlButton->setText(QCoreApplication::translate("StartFocus", "\346\232\202\345\201\234", nullptr));
        endButton->setText(QCoreApplication::translate("StartFocus", "\347\273\223\346\235\237", nullptr));
        startButton->setText(QCoreApplication::translate("StartFocus", "\345\274\200  \345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartFocus : public Ui_StartFocus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STARTFOCUSZQFAMY_H
