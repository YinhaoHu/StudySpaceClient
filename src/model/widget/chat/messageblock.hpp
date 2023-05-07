#pragma once

#include<qwidget.h>
#include<qlabel.h>
#include<qlistwidget.h>


class MessageBlock: public QWidget
{
	Q_OBJECT
public:
	enum Type{Left, Right};

private:
	const static uint blockWidth = 870;
	uint messageMaxWidth = blockWidth * 0.618;
	uint blockHeight;
	QLabel* message, *profile, * username;
	uint senderID;
	Type type;
	bool showName;

	void setupRuntimeData()const;
	void setupView();
	int formatString(QString&& str, QLabel& label, int maxLine, int& contentWidth);

public:

	MessageBlock(QListWidget* _parent, QString&& msg, uint userID,
		Type _type,bool showName = true);
	~MessageBlock();

	uint getHeight()const;
	uint getWidth()const;
};