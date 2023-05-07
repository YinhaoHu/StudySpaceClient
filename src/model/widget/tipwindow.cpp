#include"tipwindow.hpp"

#include<qobject.h>
#include<qfontmetrics.h>
#include<qstring.h>


TipWindow::TipWindow(QWidget* parent):
	QWidget(parent),showing(false)
{
	close();

	setupView();
	setupDelegate();
	setPos();
}

void TipWindow::setPos()
{
	auto sw = this->screen()->size().width();
	auto sh = this->screen()->size().height();
	auto tw = width();
	auto th = height();

	auto rdy = th * 0.3;
	auto rx = sw - tw;
	auto ry = sh - th;
	remindPos.setX(rx);
	remindPos.setY(ry - rdy);


	auto cx = sw * 0.5 - tw * 0.5;
	auto cy = sh * 0.5 - th * 0.5;
	informPos.setX(cx);
	informPos.setY(cy);
}

void TipWindow::setupView() {
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowOpacity(0.85);
	view.setupUi(this);	
	view.msgLabel->setAlignment(Qt::AlignCenter);
	view.msgLabel->setText("");
}

void TipWindow::setupDelegate() {
	QObject::connect(view.okButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.okButton, SIGNAL(pressed()), this, SLOT(closeWindow()));
	QObject::connect(view.okButton, SIGNAL(pressed()), SIGNAL(confirmed()));
}

void TipWindow::closeWindow() {
	showing = false;
	close();
}

void TipWindow::inform(const char32_t* msg)
{
	inform(QString::fromStdU32String(msg));
}

void TipWindow::inform(QString&& msg)
{
	if (showing)
		closeWindow();
	view.msgLabel->setText(msg);
	move(informPos);
	show();
	showing = true;
}

void TipWindow::remind(QString&& msg)
{
	if (showing)
		closeWindow();
	view.msgLabel->setText(msg);

	this->setWindowFlag(Qt::WindowStaysOnTopHint);
	this->move(remindPos);
	this->show();
	showing = true;
}

void TipWindow::keyPressEvent(QKeyEvent* event) {
	if (event->matches(QKeySequence::InsertParagraphSeparator))
		view.okButton->click();
	else if (event->matches(QKeySequence::Cancel))
		closeWindow();
}