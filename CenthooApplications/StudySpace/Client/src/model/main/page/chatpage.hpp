#ifndef _CHATPAGE_HPP_
#define _CHATPAGE_HPP_

#include"../../../view/main/page/uichatpage.hpp"
#include"../../widget/messagewidget.hpp"
#include"../../widget/tipwindow.hpp"

#include<qobject.h>
#include<qpixmap.h>
#include<QtWidgets/qwidget.h>
#include<QtGui/qevent.h>

class ChatPage : public QWidget {
	Q_OBJECT

private:
	Ui::uichatpage view;
	MessageWidget* messageWidget;
	TipWindow* tipWindow;
	QPixmap* selfProfile;

	void setupView();
	void setupDelegate();

public:
	ChatPage(QWidget* parent=nullptr);

	void setupNetController();

	void setSelfProfile(QPixmap* profile);
	void addRecvMsg(QString& msg, QString& username, QPixmap& profile);

	void keyPressEvent(QKeyEvent* event)override;

public slots:
	void addSentMsg();
	void comChatRecv_update();
};


#endif