#ifndef _MESSAGEWIDGET_HPP_
#define _MESSAGEWIDGET_HPP_

#include<QtCore/qstring.h>
#include<QtWidgets/qwidget.h>
#include<QtWidgets/qlabel.h>

//MessageWidget is used as the main widget
//of the QScroolArea.
class MessageWidget :public QWidget {
	Q_OBJECT
private:
	static const int border = 10;
	
	QWidget* parentWidget;
	int rowHeight, rowWidth,spacing;
	int msgCount;

	int formatString(QString& str, QLabel& label,int maxLine, int& contentWidth);
public:
	MessageWidget(int rheigh, int rwidth, int msgSpacing ,
		QWidget* parent = nullptr);

	//Type: 0->recvedMsg 1->sentMsg
	void addMsg(QString& msg, QPixmap& senderProfile,
		QString& usernmame, int type = 0);
	
};

#endif