#include"tipwindow.hpp"

#include<qobject.h>

TipWindow::TipWindow(QWidget* parent):QWidget(parent)
{
	close();

	setupView();
	setupDelegate();
}

void TipWindow::setupView() {
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowOpacity(0.85);
	view.setupUi(this);
	view.msgLabel->setText("");
}

void TipWindow::setupDelegate() {
	QObject::connect(view.okButton, SIGNAL(pressed()), SLOT(toggle()));
	QObject::connect(view.okButton, SIGNAL(pressed()), this, SLOT(close()));
	QObject::connect(view.okButton, SIGNAL(pressed()), SIGNAL(confirmed()));
}

void TipWindow::inform(const char32_t* msg)
{
	view.msgLabel->setAlignment(Qt::AlignCenter);
	view.msgLabel->setText(QString::fromStdU32String(msg));
	show();
}

void TipWindow::keyPressEvent(QKeyEvent* event) {
	if (event->matches(QKeySequence::InsertParagraphSeparator))
		view.okButton->click();
	else if (event->matches(QKeySequence::Cancel))
		close();
}