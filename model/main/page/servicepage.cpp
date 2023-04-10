#include"servicepage.hpp"

using namespace Page;

ServicePage::ServicePage(QWidget* parent = nullptr)
	:showDYT(true)
{
	setParent(parent);

	setupView();
	setupDelegate();

	close();
}

ServicePage::~ServicePage()
{

}

void ServicePage::setupNetController()const
{

}


void ServicePage::setupView()
{
	view.setupUi(this);

	view.colorLabel->show();
}

void ServicePage::setupDelegate() const
{
	QObject::connect(view.button, SIGNAL(pressed()), 
		this,SLOT(changeColor()));
}

void ServicePage::changeColor()
{
	if(showDYT)
	{
		view.colorLabel->setText("DYT");
		showDYT = false;
	}
	else
	{
		view.colorLabel->setText("HOO");
		showDYT = true;
	}
}