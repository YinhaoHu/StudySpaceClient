#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include"../../view/main/ui_mainwindow.hpp"
#include"../widget/messagewidget.hpp"
#include"list/comchatlist.hpp"
#include"list/englearnlist.hpp"
#include"page/englearnpage.hpp"
#include"page/comchatpage.hpp"

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

	void generateService();
	void setupView();
	void setupDelegate() const;
	void setupNetController() const;
	void serveFor(int option);
	
public:
	TipWindow tipWindow; 
	struct {
		Page::ComChat* comChat;
		Page::EngLearn* engLearn;
	}Pages;
	struct {
		List::ComChat* comChat;
		List::EngLearn* engLearn;
	}Lists;

	MainWindow(QWidget* parent = nullptr);

	void keyPressEvent(QKeyEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;

public slots:
	void init();

private slots:
	void userQuit();

	void comChatOptionSlot();
	void engLearnOptionSlot();
};

#endif