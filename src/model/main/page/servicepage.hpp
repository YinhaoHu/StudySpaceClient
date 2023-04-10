#ifndef _SERVICEPAGE_HPP_
#define _SERVICEPAGE_HPP_

#include"../../../view/main/page/ui_servicepage.hpp"
#include"abstractpage.hpp"

namespace Page {
	class ServicePage;
}

class Page::ServicePage:public AbstractPage 
{
	Q_OBJECT
private:
	Ui::servicepageui view;

	bool pushbuttonShown;

public:
	ServicePage(QWidget* parent);
	~ServicePage()override;

	void setupView()override;
	void setupDelegate() const override;
	void setupNetController() const override;

public slots:
	void changeLCDNumber();
};


#endif