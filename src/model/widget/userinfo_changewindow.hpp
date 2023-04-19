#pragma once

#include"../../../src/view/widget/ui_userinfo_changewindow.hpp"

#include<QWidget>
#include<qfiledialog.h>


class Userinfo_Change_Window :public QWidget
{
	Q_OBJECT
private:
	Ui::userinfo_change_windowui view;
	QString* oldPassword;
	QFileDialog* fileDialog;

	bool oldPassWordMatch();
	void setupNetController();
	void setupDelegate();
	void setupView();

public:
	Userinfo_Change_Window();
	~Userinfo_Change_Window();

	void setOldInfo(QString&& username, QPixmap&& profile, QString&& intro);

public slots:
	void doChangeInfo();
	void userinfo_change_okResponse_update();
	void password_update_slot();

	void deleteWindow();
};