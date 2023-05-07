#ifndef _REGISTERWINDOW_HPP_
#define _REGISTERWINDOW_HPP_

#include"../../view/login/ui_registerwiondow.hpp"
#include"../widget/tipwindow.hpp"

#include<QtWidgets/qwidget.h>
#include<QtGui/qevent.h>

class RegisterWindow :public QWidget {
	Q_OBJECT
private:
	struct infoFields {
		QString username;
		QString password;
		QString repassword;
		QString email;
		QString code;
	};
	TipWindow* tipWindow;
	Ui::registerwindowui view;

	void inform(const char32_t* msg);

private slots:
	void doRegister();
public:
	RegisterWindow(QWidget* parent = nullptr);
	
	void buildView();
	void buildDelegate();

	int checkRegister(infoFields& info);
	void sendToServer(infoFields& info);
	int getServerResponseCode(QString& allocatedId);
	
	void keyPressEvent(QKeyEvent* event) override;

signals:
	void closed();
	void registerOk();
};
#endif