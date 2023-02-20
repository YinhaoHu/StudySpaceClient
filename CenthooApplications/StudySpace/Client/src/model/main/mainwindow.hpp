#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include"../../view/main/ui_mainwindow.hpp"
#include"../widget/messagewidget.hpp"
#include"list/comchat.hpp"
#include"list/englearnlist.hpp"
#include"page/englearnpage.hpp"
#include"page/chatpage.hpp"

#include<QtWidgets/qwidget.h>
#include<QtGui/qevent.h>

class MainWindow :public QWidget {
	Q_OBJECT
private:
	Ui::mainwindowui view;

	enum OptionList{comChat,engLearn};
	struct {
		QWidget* curPage;
		QWidget* curList;
		QPoint mousePoint;
	}status;
	bool windowMovingOn;

	void setupUi();
	void setuiDelegate();
	void setupNetController();
	void windowController(int option);
	
public:
	TipWindow tipWindow; 
	struct {
		ChatPage* comChat;
		Page::EngLearn* engLearn;
	}Pages;
	struct {
		List::ComChat* comChat;
		List::EngLearn* engLearn;
	}Lists;
	struct {
		QPixmap* selfProfile;
	}userWindowData;

	MainWindow(QWidget* parent = nullptr);

	void keyPressEvent(QKeyEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;

public slots:
	void init();

private slots:
	void comChatOptionSlot();
	void engLearnOptionSlot();
};

#endif