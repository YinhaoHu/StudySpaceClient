#ifndef  _LOGINWINDOW_HPP_
#define _LOGINWINDOW_HPP_

#include"../../view/login/ui_loginwindow.hpp"
#include"../widget/tipwindow.hpp"
#include"registerwindow.hpp"
#include"infowindow.hpp"

#include<QtWidgets/QWidget>
#include<QtGui/qkeysequence.h>
#include<QtGui/qevent.h>
#include<QtCore/qstring.h>


class LoginWindow :public QWidget
{
	Q_OBJECT
private:
	InfoWindow* infoWindow;
	RegisterWindow* registerWindow;
	Ui::loginwindowui view;

	static constexpr unsigned int autoLoginExpiryDays = 3;

	bool windowMovingOn;
	QPoint mousePoint;

	uint checkAutoLogin()const;
	void setAutoLoginData()const;

private slots:
	void doLogin();

public slots:
	void launch();

public:
	LoginWindow(QWidget* parent = nullptr);

	void setupView();
	void setupDelegate();

	int checkLogin(QString& number, QString& password);
	void sendLoginInfo(QString& number, QString& password);
	int recvLoginState();
	void informUser(const char32_t* msg);

	void keyPressEvent(QKeyEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;

signals:
	void properLogin();
};

#endif