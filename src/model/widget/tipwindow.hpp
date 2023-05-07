#ifndef _TIPWINDOW_HPP_
#define _TIPWINDOW_HPP_

#include"view/widget/ui_tipwindow.hpp"

#include<QtWidgets/qwidget.h>
#include<QtGui/qevent.h>

class TipWindow:public QWidget {
	Q_OBJECT
private:
	Ui::tipwindowui view;

	bool showing;
	QPoint informPos;
	QPoint remindPos;

	void setPos();

public:
	TipWindow(QWidget* parent=nullptr);

	void setupView();
	void setupDelegate();
	void inform(const char32_t* msg);
	void inform(QString&& msg);
	void remind(QString&& msg);

	void keyPressEvent(QKeyEvent* event)override;
signals:
	void confirmed();

public slots:
	void closeWindow();
};

#endif