/********************************************************************************
** Form generated from reading UI file 'comchatpagetCbwCx.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef COMCHATPAGETCBWCX_H
#define COMCHATPAGETCBWCX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uicomchatpage
{
public:
    QTextEdit* sendMsgBlock;
    QScrollArea* recvMsgBlock;
    QWidget* recvMsgBlockContent;
    QToolButton* sendMsgButton;

    void setupUi(QWidget* uicomchatpage)
    {
        if (uicomchatpage->objectName().isEmpty())
            uicomchatpage->setObjectName("uicomchatpage");
        uicomchatpage->resize(870, 700);
        uicomchatpage->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        sendMsgBlock = new QTextEdit(uicomchatpage);
        sendMsgBlock->setObjectName("sendMsgBlock");
        sendMsgBlock->setGeometry(QRect(0, 510, 871, 161));
        sendMsgBlock->setFocusPolicy(Qt::StrongFocus);
        sendMsgBlock->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
            "font: 16pt \"Microsoft YaHei UI\";"));
        sendMsgBlock->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sendMsgBlock->setAcceptRichText(false);
        recvMsgBlock = new QScrollArea(uicomchatpage);
        recvMsgBlock->setObjectName("recvMsgBlock");
        recvMsgBlock->setGeometry(QRect(0, 0, 871, 501));
        recvMsgBlock->setFocusPolicy(Qt::StrongFocus);
        recvMsgBlock->setStyleSheet(QString::fromUtf8(""));
        recvMsgBlock->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        recvMsgBlock->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        recvMsgBlock->setWidgetResizable(true);
        recvMsgBlockContent = new QWidget();
        recvMsgBlockContent->setObjectName("recvMsgBlockContent");
        recvMsgBlockContent->setGeometry(QRect(0, 0, 852, 499));
        recvMsgBlock->setWidget(recvMsgBlockContent);
        sendMsgButton = new QToolButton(uicomchatpage);
        sendMsgButton->setObjectName("sendMsgButton");
        sendMsgButton->setGeometry(QRect(805, 675, 61, 22));
        sendMsgButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);\n"
            "border-radius : 8px;"));

        retranslateUi(uicomchatpage);

        QMetaObject::connectSlotsByName(uicomchatpage);
    } // setupUi

    void retranslateUi(QWidget* uicomchatpage)
    {
        uicomchatpage->setWindowTitle(QCoreApplication::translate("uicomchatpage", "Form", nullptr));
        sendMsgButton->setText(QCoreApplication::translate("uicomchatpage", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uicomchatpage : public Ui_uicomchatpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // COMCHATPAGETCBWCX_H
