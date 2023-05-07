#ifndef _ENGLEARNLIST_HPP_
#define _ENGLEARNLIST_HPP_

#include"../../../view/main/list/ui_englearnlist.hpp"

#include<QtWidgets/qwidget.h>

namespace List {
	class EngLearn;
}

class List::EngLearn :public QWidget {
	Q_OBJECT
private:
	Ui::englearnlistui view;

public:
	EngLearn(QWidget* parent) :QWidget(parent)
	{
		view.setupUi(this);

		close();
	};
};

#endif