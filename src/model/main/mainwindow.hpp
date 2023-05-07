#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include"../../view/main/ui_mainwindow.hpp"
#include"../widget/messagewidget.hpp"
#include"../widget/userinfo_selfshow_window.hpp"
#include"model/widget/feedback_window.hpp"

#include"list/comchatlist.hpp"
#include"list/englearnlist.hpp"
#include"list/contactslist.hpp"
#include"list/chatlist.hpp"
#include"list/studyaidslist.hpp"
#include"page/studyaidspage.hpp"
#include"page/chatpage.hpp"
#include"page/englearnpage.hpp"
#include"page/comchatpage.hpp"
#include"page/contactspage.hpp"

#include<QtWidgets/qwidget.h>
#include<QtGui/qevent.h>

class MainWindow :public QWidget {
	Q_OBJECT

private:
	struct {
		QString noticeServiceStyle = QString::fromUtf8("color: rgb(255, 0, 0); \n background-color: rgb(240, 240, 240);\n border-style: solid;\n border-radius : 16px;");
		QString disnoticeServiceStyle= QString::fromUtf8("color: rgb(0, 0, 0); \n background-color: rgb(240, 240, 240);\n border-style: solid;\n border-radius : 16px;");
	};

	Ui::mainwindowui view;
	enum OptionList { comChat, engLearn, contacts, chat , studyAids};
	struct {
		QWidget* curPage;
		QWidget* curList;
		QPoint mousePoint;
	}status;

	struct {
		Userinfo_SelfShow_Window* userinfo_selfshow_window;
		FeedBackWindow* feedBack_window;
	}miscellanea;
	
	bool windowMovingOn;

private:
	void generateService();
	void generateMiscellanea();
	void setupView();
	void setupDelegate() const;
	
	void initUserNetData()const;
	void initNotification()const;
	void initNetControllerThread()const;
	void initUserRuntimeData()const;
	void initUserLocalData()const;
	void initNetcontroller()const;

private:
	void serveFor(OptionList option);

public:
	struct {
		ChatPage* chat;
		Page::EngLearn* engLearn;
		ContactsPage* contacts;
		StudyAidsPage* studyAids;
	}Pages;
	struct {
		ChatList* chat;
		List::EngLearn* engLearn;
		ContactsList* contacts;
		StudyAidsList* studyAids;
	}Lists;

	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void keyPressEvent(QKeyEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;

public slots:
	void init();

private slots:
	void userQuit();

	void chatOptionSlot();
	void engLearnOptionSlot();
	void contactsOptionSlot();
	void studyAidsOptionSlot();

	void feedbackOptionSlot();
	void userinfoOptionSlot();

private slots:
	void notice_contactsService();
	void disnotice_contactsService();
	void notice_chatService();
	void disnotice_chatService();

};

#endif