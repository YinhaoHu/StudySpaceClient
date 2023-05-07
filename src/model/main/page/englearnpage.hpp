#ifndef _ENGLEARNPAGE_HPP_
#define _ENGLEARNPAGE_HPP_

#include"view/main/page/ui_englearnpage.hpp"

namespace Page {
	class EngLearn;
}

class Page::EngLearn :public QWidget {
	Q_OBJECT

private:
	Ui::englearnpageui view;

public:
	EngLearn(QWidget* parent) :QWidget(parent)
	{
		setParent(parent);
		view.setupUi(this);

		close();
	};
};


#endif