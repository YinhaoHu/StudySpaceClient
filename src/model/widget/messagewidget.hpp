#ifndef _MESSAGEWIDGET_HPP_
#define _MESSAGEWIDGET_HPP_

#include<QtCore/qstring.h>
#include<QtWidgets/qwidget.h>
#include<QtWidgets/qlabel.h>

namespace Message {
	//Remark: sender means the widget will show in the right, receiver in the left.
	enum MessageType {Sender, Receiver};
}

//MessageWidget is used as the main widget
//of the QScroolArea.
class MessageWidget :public QWidget {
	Q_OBJECT
private:
	static const int border = 10;
	static const int profile_width = 32;
	static const int profile_height = 32;


	QWidget* parentWidget;
	int rowHeight, rowWidth,spacing;
	int msgCount;

	int formatString(QString& str, QLabel& label,int maxLine, int& contentWidth);
public:
	MessageWidget(int rheigh, int rwidth, int msgSpacing ,
		QWidget* parent = nullptr);

	//Type: 0->recvedMsg 1->sentMsg
	void addMsg(QString&& msg, QPixmap&& senderProfile,
		QString&& usernmame, Message::MessageType type = Message::Receiver, bool showName = true);
	
};

#endif