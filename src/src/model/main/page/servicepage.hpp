#ifndef _SERVICEPAGE_HPP_
#define _SERVICEPAGE_HPP_

#include"../../../view/main/page/ui_servicepage.hpp"
#include"abstractpage.hpp"

namespace Page {
	class ServicePage;
}

class Page::ServicePage:public AbstractPage 
{
private:
	Ui::servicepageui view;

	bool showDYT;

public:
	ServicePage(QWidget* parent);
	~ServicePage()override;

	void setupView()override;
	void setupDelegate() const override;
	void setupNetController() const override;

public slots:
	void addNumber();
};


#endif