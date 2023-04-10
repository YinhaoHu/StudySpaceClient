#pragma once

#include"abstractlist.hpp"
#include"../../../view/main/list/ui_servicelist.hpp"


namespace List {
	class ServiceList;
}

class List::ServiceList : public AbstractList {
	Q_OBJECT
private:
	Ui::servicelisui view;

public:
	ServiceList(QWidget* parent)
	{
		setParent(parent);

		close();
		setupView();
	}

	~ServiceList() = default;

	void setupView() override
	{
		view.setupUi(this);
		view.label->show();
	}

	void setupDelegate()  const override
	{

	}

	void setupNetController() const override
	{

	}
};