#include"todolistitem.hpp"

 void TodoListItem::setup()
{
	view.setupUi(this);

	setWindowFlag(Qt::FramelessWindowHint);
	connect(view.finishButton, &QPushButton::pressed,
		this, &TodoListItem::forwardFinished);
}

TodoListItem::TodoListItem(QListWidget* parent, QString&& content, uint _index, bool _finishedFlag )
	:QWidget(parent), index(_index), finished_flag(_finishedFlag), task(content)
{
	setup();
	view.contentLabel->setText(content);
	if (finished_flag == true)
		makeFinished();
}

TodoListItem::TodoListItem(TodoListItem& rhs)
	:QWidget(rhs.parentWidget()), task(rhs.task), finished_flag(rhs.finished_flag)
{
	setup();
	view.contentLabel->setText(task);
	if (finished_flag == true)
		makeFinished();
}

TodoListItem::~TodoListItem() {}

void TodoListItem::setID(uint newID)
{
	index = newID;
}

void TodoListItem::makeFinished()
{
	this->finished_flag = true;

	QFont bfont;
	bfont.setFamilies({ QString::fromUtf8("Microsoft YaHei UI") });
	bfont.setPointSize(6);

	view.finishButton->setStyleSheet(QString::fromUtf8("border-style: solid;\n"
		"border-radius: 0.5em;\n"
		"color: rgb(255, 255, 255);\n"
		"background-color: rgb(42, 131, 93);"));
	view.finishButton->setText(QString::fromUtf8("√"));
	view.finishButton->setFont(bfont);

	QFont font;
	font.setFamilies({ QString::fromUtf8("Microsoft YaHei UI") });
	font.setPointSize(13);
	font.setStrikeOut(true);

	view.contentLabel->setStyleSheet(QString::fromUtf8("color: rgb(126, 126, 126);background-color: rgb(246, 246, 246);"));
	view.contentLabel->setFont(font);

	disconnect(view.finishButton, &QPushButton::pressed,
		this, &TodoListItem::forwardFinished);
}

bool TodoListItem::isFinished()const
{
	return this->finished_flag;
}

QString TodoListItem::getTask()const {
	return task;
}

void TodoListItem::forwardFinished()
{
	makeFinished();
	disconnect(view.finishButton, &QPushButton::pressed,
		this, &TodoListItem::forwardFinished);
	emit finished(index);
}