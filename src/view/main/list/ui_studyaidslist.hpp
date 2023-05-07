/********************************************************************************
** Form generated from reading UI file 'studyaidslistgktVyM.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef STUDYAIDSLISTGKTVYM_H
#define STUDYAIDSLISTGKTVYM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudyAidsList
{
public:
    QLabel* background;
    QLabel* title;
    QWidget* verticalLayoutWidget;
    QVBoxLayout* layout;
    QPushButton* courseButton;
    QPushButton* scheduleButton;
    QPushButton* targets;
    QPushButton* focusButton;

    void setupUi(QWidget* StudyAidsList)
    {
        if (StudyAidsList->objectName().isEmpty())
            StudyAidsList->setObjectName("StudyAidsList");
        StudyAidsList->resize(200, 700);
        background = new QLabel(StudyAidsList);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 200, 700));
        background->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        title = new QLabel(StudyAidsList);
        title->setObjectName("title");
        title->setGeometry(QRect(0, 0, 200, 50));
        QFont font;
        font.setPointSize(24);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("background-color: rgb(172, 172, 172);"));
        title->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(StudyAidsList);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 60, 201, 241));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setSpacing(10);
        layout->setObjectName("layout");
        layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        layout->setContentsMargins(0, 0, 0, 0);
        courseButton = new QPushButton(verticalLayoutWidget);
        courseButton->setObjectName("courseButton");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(courseButton->sizePolicy().hasHeightForWidth());
        courseButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({ QString::fromUtf8("Adobe \346\245\267\344\275\223 Std R") });
        font1.setPointSize(19);
        courseButton->setFont(font1);

        layout->addWidget(courseButton);

        scheduleButton = new QPushButton(verticalLayoutWidget);
        scheduleButton->setObjectName("scheduleButton");
        sizePolicy.setHeightForWidth(scheduleButton->sizePolicy().hasHeightForWidth());
        scheduleButton->setSizePolicy(sizePolicy);
        scheduleButton->setFont(font1);

        layout->addWidget(scheduleButton);

        targets = new QPushButton(verticalLayoutWidget);
        targets->setObjectName("targets");
        sizePolicy.setHeightForWidth(targets->sizePolicy().hasHeightForWidth());
        targets->setSizePolicy(sizePolicy);
        targets->setFont(font1);

        layout->addWidget(targets);

        focusButton = new QPushButton(verticalLayoutWidget);
        focusButton->setObjectName("focusButton");
        sizePolicy.setHeightForWidth(focusButton->sizePolicy().hasHeightForWidth());
        focusButton->setSizePolicy(sizePolicy);
        focusButton->setFont(font1);

        layout->addWidget(focusButton);

        layout->setStretch(0, 1);
        layout->setStretch(1, 1);
        layout->setStretch(2, 1);
        layout->setStretch(3, 1);

        retranslateUi(StudyAidsList);

        QMetaObject::connectSlotsByName(StudyAidsList);
    } // setupUi

    void retranslateUi(QWidget* StudyAidsList)
    {
        StudyAidsList->setWindowTitle(QCoreApplication::translate("StudyAidsList", "Form", nullptr));
        background->setText(QString());
        title->setText(QCoreApplication::translate("StudyAidsList", "\345\255\246\344\271\240\345\212\251\346\211\213", nullptr));
        courseButton->setText(QCoreApplication::translate("StudyAidsList", "\350\257\276\347\250\213", nullptr));
        scheduleButton->setText(QCoreApplication::translate("StudyAidsList", "\350\247\204\345\210\222", nullptr));
        targets->setText(QCoreApplication::translate("StudyAidsList", "\347\233\256\346\240\207", nullptr));
        focusButton->setText(QCoreApplication::translate("StudyAidsList", "\344\270\223\346\263\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudyAidsList : public Ui_StudyAidsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // STUDYAIDSLISTGKTVYM_H
