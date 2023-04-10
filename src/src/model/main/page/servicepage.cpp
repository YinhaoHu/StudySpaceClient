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
}

void ServicePage::setupDelegate() const
{
	view.displayArea->display(10);

	QObject::connect(view.button, SIGNAL(pressed()),
		this,SLOT(addNumber()));
	QObject::connect(view.button, SIGNAL(pressed()),
		SLOT(toggle()));
}

void ServicePage::addNumber()
{
	view.displayArea->display(20);
	view.displayArea->update();
}