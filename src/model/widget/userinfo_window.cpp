#include"userinfo_window.hpp"


//public scope:

UserInfoWindow::UserInfoWindow()
{
	view.setupUi(this);

	functionButton = view.functionButton;
	close();
}

void UserInfoWindow::setInfo(QString&& id, QString&& name, QPixmap&& profile, QString&& intro)
{
	setWindowFlag(Qt::FramelessWindowHint);

	view.idLabel->setText(id);
	view.nameLabel->setText(name);
	view.profileLabel->setPixmap(profile.scaled(100,100));
	view.introArea->setText(intro);

	connect(view.quitButton, SIGNAL(pressed()), this, SLOT(deleteWindow()));
}

//public slots scope:

void UserInfoWindow::display()
{
	show();
	view.functionButton->close();
}

void UserInfoWindow::deleteWindow()
{
	this->close();
	delete this;
}
