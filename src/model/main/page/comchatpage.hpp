#ifndef _CHATPAGE_HPP_
#define _CHATPAGE_HPP_

#include"view/main/page/ui_comchatpage.hpp"
#include"model/widget/messagewidget.hpp"
#include"model/widget/tipwindow.hpp"

#include<qobject.h>
#include<qpixmap.h>
#include<QtWidgets/qwidget.h>
#include<QtGui/qevent.h>

namespace Page {
	class ComChat;
}


class Page::ComChat : public QWidget {
	Q_OBJECT

private:
	Ui::uicomchatpage view;
	MessageWidget* messageWidget;
	TipWindow* tipWindow;
	QPixmap* selfProfile;

	void setupView();
	void setupDelegate();

public:
	ComChat(QWidget* parent=nullptr);

	void setupNetController();

	void addRecvMsg(QString&& msg, QString&&username, QPixmap&& profile);

	void keyPressEvent(QKeyEvent* event)override;

public slots:
	void addSentMsg();
	void comChatRecv_update();
};


#endif