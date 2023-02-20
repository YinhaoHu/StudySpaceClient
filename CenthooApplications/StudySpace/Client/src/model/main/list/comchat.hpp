#include"../../../view/main/list/uicomchat.hpp"

#include<qobject.h>
#include<QtWidgets/qwidget.h>

namespace List {
	class ComChat;
}

class List::ComChat :public QWidget {
	Q_OBJECT
private:
	Ui::uicomchat view;
public:
	ComChat(QWidget* parent) :QWidget(parent)
	{
		setParent(parent);
		view.setupUi(this);

		close();
	};
};

