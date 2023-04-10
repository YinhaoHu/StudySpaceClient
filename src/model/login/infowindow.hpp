#ifndef _INFOWINDOW_HPP_
#define _INFOWINDOW_HPP_

#include"../../view/login/ui_infowindow.hpp"

#include<qobject.h>
#include<QtWidgets/qwidget.h>
#include<QtGui/qevent.h>

class InfoWindow: public QWidget {
	Q_OBJECT
private:
	Ui::infowindow_ui view;

	void setuiView();
	void setuiDelegate();
public slots:
	void closeButtonClicked();
signals:
	void confirmed();
	void closed();
public:
	InfoWindow(QWidget* parent = nullptr);

	void keyPressEvent(QKeyEvent* event)override;
};

#endif