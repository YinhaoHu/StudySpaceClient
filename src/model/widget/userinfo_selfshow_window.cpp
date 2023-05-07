#include"userinfo_selfshow_window.hpp"

#include"../../data/runtime_datamanager.hpp"

extern QSharedPointer<data::Runtime_DataManager> runtime_dataManager;

void Userinfo_SelfShow_Window::
setupRuntimeDataManager()
{
	runtime_dataManager->add_personalInfo_usernameObject(this->view.nameLabel);
	runtime_dataManager->add_personalInfo_introObject(this->view.introArea);

}

void Userinfo_SelfShow_Window::
setupView()
{
	functionButton->setText(QString::fromStdU32String(std::u32string(U"更改信息")));
}

void Userinfo_SelfShow_Window::
setupDelegate()
{
	connect(functionButton, SIGNAL(pressed()), SLOT(enterChangeInfo()));
}

Userinfo_SelfShow_Window::
Userinfo_SelfShow_Window()
	:UserInfoWindow(),  userinfo_change_window(nullptr)
{
	setupView();
	setupDelegate();
}

Userinfo_SelfShow_Window::
~Userinfo_SelfShow_Window() {

}

void Userinfo_SelfShow_Window::
enterChangeInfo()
{
	this->userinfo_change_window = new Userinfo_Change_Window;
	userinfo_change_window->show();
	this->close();

	userinfo_change_window->setOldInfo(view.nameLabel->text(),
		view.profileLabel->pixmap(), runtime_dataManager->get_personalInfo_intro());
}

void Userinfo_SelfShow_Window::
display()
{
	this->show();
}

void Userinfo_SelfShow_Window::
deleteWindow()
{
	//According to the intention fo the mainwindow,
	//deletion of the window is not allowed, but
	//it is okay to delete the changed info window.
	this->close();
}