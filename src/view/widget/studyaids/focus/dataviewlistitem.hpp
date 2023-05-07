/********************************************************************************
** Form generated from reading UI file 'dataviewlistitemXMzdhR.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DATAVIEWLISTITEMXMZDHR_H
#define DATAVIEWLISTITEMXMZDHR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataViewListItem
{
public:
    QLabel *background;
    QLabel *indexLabel;
    QLabel *dateLabel;
    QLabel *durationLabel;
    QLabel *ratingLabel;

    void setupUi(QWidget *DataViewListItem)
    {
        if (DataViewListItem->objectName().isEmpty())
            DataViewListItem->setObjectName("DataViewListItem");
        DataViewListItem->resize(240, 48);
        background = new QLabel(DataViewListItem);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 240, 48));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        indexLabel = new QLabel(DataViewListItem);
        indexLabel->setObjectName("indexLabel");
        indexLabel->setGeometry(QRect(0, 0, 48, 48));
        indexLabel->setAlignment(Qt::AlignCenter);
        dateLabel = new QLabel(DataViewListItem);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setGeometry(QRect(60, 0, 100, 20));
        durationLabel = new QLabel(DataViewListItem);
        durationLabel->setObjectName("durationLabel");
        durationLabel->setGeometry(QRect(60, 25, 100, 20));
        ratingLabel = new QLabel(DataViewListItem);
        ratingLabel->setObjectName("ratingLabel");
        ratingLabel->setGeometry(QRect(180, 5, 50, 32));

        retranslateUi(DataViewListItem);

        QMetaObject::connectSlotsByName(DataViewListItem);
    } // setupUi

    void retranslateUi(QWidget *DataViewListItem)
    {
        DataViewListItem->setWindowTitle(QCoreApplication::translate("DataViewListItem", "Form", nullptr));
        background->setText(QString());
        indexLabel->setText(QCoreApplication::translate("DataViewListItem", "INDEX", nullptr));
        dateLabel->setText(QCoreApplication::translate("DataViewListItem", "YYYY-MM-DD", nullptr));
        durationLabel->setText(QCoreApplication::translate("DataViewListItem", "DURATION", nullptr));
        ratingLabel->setText(QCoreApplication::translate("DataViewListItem", "RATING", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataViewListItem: public Ui_DataViewListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DATAVIEWLISTITEMXMZDHR_H
