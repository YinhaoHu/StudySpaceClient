/********************************************************************************
** Form generated from reading UI file 'dataviewvECrtQ.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DATAVIEWVECRTQ_H
#define DATAVIEWVECRTQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataView
{
public:
    QLabel *background;
    QWidget *listContainer;
    QListWidget *listWidget;
    QLabel *listLabel;
    QGraphicsView *chartView;
    QWidget *widget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *totalCountTip;
    QLabel *totalCountDisplay;
    QLabel *totalDurationTip;
    QLabel *totalDurationDisplay;
    QLabel *averageDurationTip;
    QLabel *averageDurationDisplay;
    QLabel *averageScoreTip;
    QLabel *averageScoreDisplay;

    void setupUi(QWidget *DataView)
    {
        if (DataView->objectName().isEmpty())
            DataView->setObjectName("DataView");
        DataView->resize(870, 620);
        background = new QLabel(DataView);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 620));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 234, 234);"));
        listContainer = new QWidget(DataView);
        listContainer->setObjectName("listContainer");
        listContainer->setGeometry(QRect(620, 10, 240, 601));
        listWidget = new QListWidget(listContainer);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 70, 241, 530));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listLabel = new QLabel(listContainer);
        listLabel->setObjectName("listLabel");
        listLabel->setGeometry(QRect(0, 0, 241, 70));
        QFont font;
        font.setPointSize(16);
        listLabel->setFont(font);
        listLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        listLabel->setAlignment(Qt::AlignCenter);
        chartView = new QGraphicsView(DataView);
        chartView->setObjectName("chartView");
        chartView->setGeometry(QRect(50, 30, 520, 320));
        chartView->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);"));
        widget = new QWidget(DataView);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 430, 181, 131));
        widget->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
"border-color: rgb(0, 0, 0);\n"
"border-width: 1px;"));
        formLayoutWidget = new QWidget(widget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 0, 181, 128));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        totalCountTip = new QLabel(formLayoutWidget);
        totalCountTip->setObjectName("totalCountTip");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(totalCountTip->sizePolicy().hasHeightForWidth());
        totalCountTip->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, totalCountTip);

        totalCountDisplay = new QLabel(formLayoutWidget);
        totalCountDisplay->setObjectName("totalCountDisplay");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(totalCountDisplay->sizePolicy().hasHeightForWidth());
        totalCountDisplay->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, totalCountDisplay);

        totalDurationTip = new QLabel(formLayoutWidget);
        totalDurationTip->setObjectName("totalDurationTip");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(totalDurationTip->sizePolicy().hasHeightForWidth());
        totalDurationTip->setSizePolicy(sizePolicy2);

        formLayout->setWidget(1, QFormLayout::LabelRole, totalDurationTip);

        totalDurationDisplay = new QLabel(formLayoutWidget);
        totalDurationDisplay->setObjectName("totalDurationDisplay");

        formLayout->setWidget(1, QFormLayout::FieldRole, totalDurationDisplay);

        averageDurationTip = new QLabel(formLayoutWidget);
        averageDurationTip->setObjectName("averageDurationTip");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(averageDurationTip->sizePolicy().hasHeightForWidth());
        averageDurationTip->setSizePolicy(sizePolicy3);

        formLayout->setWidget(2, QFormLayout::LabelRole, averageDurationTip);

        averageDurationDisplay = new QLabel(formLayoutWidget);
        averageDurationDisplay->setObjectName("averageDurationDisplay");

        formLayout->setWidget(2, QFormLayout::FieldRole, averageDurationDisplay);

        averageScoreTip = new QLabel(formLayoutWidget);
        averageScoreTip->setObjectName("averageScoreTip");
        sizePolicy2.setHeightForWidth(averageScoreTip->sizePolicy().hasHeightForWidth());
        averageScoreTip->setSizePolicy(sizePolicy2);

        formLayout->setWidget(3, QFormLayout::LabelRole, averageScoreTip);

        averageScoreDisplay = new QLabel(formLayoutWidget);
        averageScoreDisplay->setObjectName("averageScoreDisplay");

        formLayout->setWidget(3, QFormLayout::FieldRole, averageScoreDisplay);


        retranslateUi(DataView);

        QMetaObject::connectSlotsByName(DataView);
    } // setupUi

    void retranslateUi(QWidget *DataView)
    {
        DataView->setWindowTitle(QCoreApplication::translate("DataView", "Form", nullptr));
        background->setText(QString());
        listLabel->setText(QCoreApplication::translate("DataView", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        totalCountTip->setText(QCoreApplication::translate("DataView", "\346\200\273\346\254\241\346\225\260", nullptr));
        totalCountDisplay->setText(QCoreApplication::translate("DataView", "X", nullptr));
        totalDurationTip->setText(QCoreApplication::translate("DataView", "\346\200\273\346\227\266\351\225\277", nullptr));
        totalDurationDisplay->setText(QCoreApplication::translate("DataView", "X", nullptr));
        averageDurationTip->setText(QCoreApplication::translate("DataView", "\345\271\263\345\235\207\346\227\266\351\225\277", nullptr));
        averageDurationDisplay->setText(QCoreApplication::translate("DataView", "X", nullptr));
        averageScoreTip->setText(QCoreApplication::translate("DataView", "\345\271\263\345\235\207\345\276\227\345\210\206", nullptr));
        averageScoreDisplay->setText(QCoreApplication::translate("DataView", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataView: public Ui_DataView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DATAVIEWVECRTQ_H
