#pragma once

#include"view/widget/ui_userinfo_window.hpp"

#include<QWidget>

/*
*			UserInfoWindow Class
* 
*	The base class for userinfo window.
*	By default, the function button is 
*	closed, which can be custom used.
* 
*	Attention:
*		By default, the window is closed.
*		By default, the function button
*			is closed.
* 
*	Use:	recommended to use display 
*		instead of show.
*		to show function button using
*		override display
*/
class UserInfoWindow:public QWidget
{
	Q_OBJECT
protected:
	Ui::userinfo_windowui view;

protected:
	QPushButton* functionButton;

public:
	UserInfoWindow();
	UserInfoWindow(QWidget* parent);
	
	void setInfo(QString&& id, QString&& name, QPixmap&& profile, QString&& intro);

public slots:
	virtual void display();
	virtual void deleteWindow();
};