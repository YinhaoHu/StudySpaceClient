#pragma once

#include"../../../src/view/widget/ui_userinfo_changewindow.hpp"

#include<QWidget>
#include<qfiledialog.h>


class Userinfo_Change_Window :public QWidget
{
	Q_OBJECT
private:
	Ui::userinfo_change_windowui view;
	QFileDialog* fileDialog;

	bool oldPassWordMatch(QString& oldpassword);
	void setupNetController();
	void setupDelegate();
	void setupView();

	void tempShowNewProfile(QString filename);

public:
	Userinfo_Change_Window();
	~Userinfo_Change_Window();

	void setOldInfo(QString&& username, QPixmap&& profile, QString&& intro);

private slots:
	void checkAndTempShowProfile(QString filename);

public slots:
	void doChange_entry();
	void doChange_implement(QString oldPassword);
	
	void userinfo_change_okResponse_update();

	void deleteWindow();
};