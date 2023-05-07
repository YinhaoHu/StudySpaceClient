/********************************************************************************
** Form generated from reading UI file 'todayscheduleNoGppX.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TODAYSCHEDULENOGPPX_H
#define TODAYSCHEDULENOGPPX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_todayScheduleWidget
{
public:
    QWidget* todolistwidget;
    QLabel* subtitleBar;
    QListWidget* listWidget;
    QLabel* titleBar;
    QLabel* background;
    QPushButton* addTaskEntryButton;
    QLineEdit* addTaskInput;
    QPushButton* addTaskButton;

    void setupUi(QWidget* todayScheduleWidget)
    {
        if (todayScheduleWidget->objectName().isEmpty())
            todayScheduleWidget->setObjectName("todayScheduleWidget");
        todayScheduleWidget->resize(870, 650);
        todolistwidget = new QWidget(todayScheduleWidget);
        todolistwidget->setObjectName("todolistwidget");
        todolistwidget->setGeometry(QRect(160, 0, 550, 590));
        todolistwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 139, 101);"));
        subtitleBar = new QLabel(todolistwidget);
        subtitleBar->setObjectName("subtitleBar");
        subtitleBar->setGeometry(QRect(0, 40, 550, 30));
        QFont font;
        font.setFamilies({ QString::fromUtf8("Microsoft YaHei UI") });
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        subtitleBar->setFont(font);
        subtitleBar->setStyleSheet(QString::fromUtf8("background-color: rgb(54, 142, 103);\n"
            "font: 10pt \"Microsoft YaHei UI\";\n"
            "color: rgb(255, 255, 255);"));
        subtitleBar->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignTop);
        listWidget = new QListWidget(todolistwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 69, 550, 515));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(54, 142, 103);\n"
            ""));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSpacing(5);
        titleBar = new QLabel(todolistwidget);
        titleBar->setObjectName("titleBar");
        titleBar->setGeometry(QRect(0, 0, 550, 41));
        QFont font1;
        font1.setFamilies({ QString::fromUtf8("Microsoft YaHei UI") });
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        titleBar->setFont(font1);
        titleBar->setStyleSheet(QString::fromUtf8("background-color: rgb(54, 142, 103);\n"
            "font: 700 20pt \"Microsoft YaHei UI\";\n"
            "color: rgb(255, 255, 255);"));
        titleBar->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);
        background = new QLabel(todayScheduleWidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 870, 650));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(54, 142, 103);"));
        addTaskEntryButton = new QPushButton(todayScheduleWidget);
        addTaskEntryButton->setObjectName("addTaskEntryButton");
        addTaskEntryButton->setGeometry(QRect(160, 600, 550, 40));
        QFont font2;
        font2.setPointSize(14);
        addTaskEntryButton->setFont(font2);
        addTaskEntryButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
            "border-radius: 16px;\n"
            "background-color: rgb(238, 246, 243);"));
        addTaskInput = new QLineEdit(todayScheduleWidget);
        addTaskInput->setObjectName("addTaskInput");
        addTaskInput->setGeometry(QRect(250, 600, 450, 40));
        addTaskInput->setStyleSheet(QString::fromUtf8("border-radius: 16px;\n"
            "border-style: solid;\n"
            "background-color: rgb(238, 246, 243);\n"
            "font: 12pt \"Microsoft YaHei UI\";"));
        addTaskButton = new QPushButton(todayScheduleWidget);
        addTaskButton->setObjectName("addTaskButton");
        addTaskButton->setGeometry(QRect(160, 600, 40, 40));
        addTaskButton->setStyleSheet(QString::fromUtf8("border-radius: 16px;\n"
            "border-style: solid;\n"
            "background-color: rgb(238, 246, 243);"));
        background->raise();
        todolistwidget->raise();
        addTaskInput->raise();
        addTaskButton->raise();
        addTaskEntryButton->raise();

        retranslateUi(todayScheduleWidget);

        QMetaObject::connectSlotsByName(todayScheduleWidget);
    } // setupUi

    void retranslateUi(QWidget* todayScheduleWidget)
    {
        todayScheduleWidget->setWindowTitle(QCoreApplication::translate("todayScheduleWidget", "Form", nullptr));
        subtitleBar->setText(QCoreApplication::translate("todayScheduleWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">  Month Day</span></p></body></html>", nullptr));
        titleBar->setText(QCoreApplication::translate("todayScheduleWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">  Month Day</span></p></body></html>", nullptr));
        background->setText(QString());
        addTaskEntryButton->setText(QCoreApplication::translate("todayScheduleWidget", "\346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
        addTaskButton->setText(QCoreApplication::translate("todayScheduleWidget", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class todayScheduleWidget : public Ui_todayScheduleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TODAYSCHEDULENOGPPX_H
