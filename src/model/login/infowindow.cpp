#include"infowindow.hpp"

#include<QtGui/qkeysequence.h>


void InfoWindow::setuiView() {
	this->setWindowFlag(Qt::FramelessWindowHint);

	view.setupUi(this);
}
void InfoWindow::setuiDelegate() {
	QObject::connect(view.closeButton, SIGNAL(pressed()), this, SLOT(closeButtonClicked()));
	QObject::connect(view.closeButton, SIGNAL(pressed()), this, SLOT(close()));
	
	QObject::connect(view.minimizeButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.minimizeButton, SIGNAL(pressed()), this, SLOT(showMinimized()));
}
void InfoWindow::closeButtonClicked() {
	emit closed();
}


void InfoWindow::keyPressEvent(QKeyEvent* event)
{
	if (event->matches(QKeySequence::Cancel))
	{
		close();
		emit closed();
	}
}

InfoWindow::InfoWindow(QWidget* parent) {
	setuiView();
	setuiDelegate();
}