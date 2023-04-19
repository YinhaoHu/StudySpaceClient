#pragma once

#include"userinfo_window.hpp"
#include"userinfo_changewindow.hpp"

#include<string>

#include<qwidget.h>


class Userinfo_SelfShow_Window
	:public UserInfoWindow
{
	Q_OBJECT
private:
	Userinfo_Change_Window* userinfo_change_window;
	//Dot not delete it in this class, it will be delete by it self.

	void setupRuntimeDataManager();
	void setupView();
	void setupDelegate();

public:
	Userinfo_SelfShow_Window();

	~Userinfo_SelfShow_Window();

public slots:
	void enterChangeInfo();
	void display()override;
	void deleteWindow()override;
};