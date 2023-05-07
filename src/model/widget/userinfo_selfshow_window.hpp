#pragma once

#include"userinfo_window.hpp"
#include"userinfo_changewindow.hpp"

#include<string>

#include<qwidget.h>


class Userinfo_SelfShow_Window
	:public UserInfoWindow
{
	Q_OBJECT
friend class MainWindow;

private:
	Userinfo_Change_Window* userinfo_change_window;
	//Dot not delete it in this class, it will be delete by it self.

	void setupView();
	void setupDelegate();

protected:
	void setupRuntimeDataManager();

public:
	Userinfo_SelfShow_Window();

	~Userinfo_SelfShow_Window();

public slots:
	void enterChangeInfo();
	void display()override;
	void deleteWindow()override;
};