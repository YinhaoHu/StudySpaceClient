#include"servicepage.hpp"

using namespace Page;

ServicePage::ServicePage(QWidget* parent = nullptr)
	:pushbuttonShown(true)
{
	setParent(parent);

	setupView();
	setupDelegate();

	close();
}

ServicePage::~ServicePage()
{
	//if the class holds the pointer to heap
	//this function should be considered.
}

void ServicePage::setupNetController()const
{
	//If you need to use the net controller,
	//this function needs implementation
}


void ServicePage::setupView()
{
	view.setupUi(this);
	
}

void ServicePage::setupDelegate() const
{
	QObject::connect(view.button, SIGNAL(pressed()),
		this,SLOT(changeLCDNumber()));
	QObject::connect(view.button, SIGNAL(pressed()),
		SLOT(toggle()));
}

void ServicePage::changeLCDNumber()
{
	int oldNum = view.lcdNumber->intValue();

	view.lcdNumber->display(oldNum + 1);
}