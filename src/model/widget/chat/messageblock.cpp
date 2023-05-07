#include"messageblock.hpp"

#include"inc_data/extern_data.hpp"


void MessageBlock::setupRuntimeData()const
{
	if(type == Type::Left)
	{
		runtime_dataManager->add_friendsInfo_smallProfileObject(senderID, profile);
		runtime_dataManager->add_friendsInfo_usernameObject(senderID, username);
	}
	else if (type == Type::Right)
	{
		runtime_dataManager->add_personalInfo_smallProfileObject(profile);
		runtime_dataManager->add_personalInfo_usernameObject(username);
	}
}

int MessageBlock::formatString(QString&& str, QLabel& label, int maxLine, int& contentWidth)
{
	int lines, size;
	QString newStr, lineBuffer, spacing;
	QFontMetrics fontMetrics(label.font());

	spacing = "    ";
	lines = 1;
	size = str.size();
	maxLine -= fontMetrics.horizontalAdvance(spacing);
	lineBuffer = "  ";
	for (int i = 0; i < size; ++i)
	{
		lineBuffer.push_back(str[i]);
		if (fontMetrics.horizontalAdvance(lineBuffer) >= maxLine)
		{
			newStr.append(lineBuffer + '\n');
			++lines;
			lineBuffer = "  ";
		}
		else if (lineBuffer.back() == QChar('\n'))
		{
			newStr.append(lineBuffer);
			++lines;
			lineBuffer = "  ";
		}
	}

	newStr.append(lineBuffer + spacing);
	label.setText(newStr);
	if (lines == 1)
		contentWidth = fontMetrics.horizontalAdvance(lineBuffer + spacing);
	else
		contentWidth = (maxLine + fontMetrics.horizontalAdvance(spacing));
	return lines;
}

void MessageBlock::setupView()
{
	/*
		++++++++++++++++++++++++++++++++++++++++++++++++++++++ Border between two messages
											|NameLabel |
		------------------------------------------------  ---- 
		|											   |  |  |
		------------------------------------------------  ----
		++++++++++++++++++++++++++++++++++++++++++++++++++++++ Border between two messages
	*/
	message->setParent(this);
	profile->setParent(this);
	username->setParent(this);
	
	const uint border = 10, profile_height =32, profile_width = 32;
	QFont messageFont("Microsoft YaHei UI", 12), usernameFont("Microsoft YaHei UI", 8);
	QFontMetrics usernameFontMetrics(usernameFont);
	QFontMetrics messageFontMetrics(messageFont);
	int lines, contentHeight, contentWidth, reamainWidth, nameHeight;

	uint rowWidth = blockWidth*0.68, rowHeight = 40, textHeight = messageFontMetrics.height()*0.5;
	nameHeight = usernameFontMetrics.height() * 1.2;
	message->setFont(messageFont);
	lines = formatString(message->text(), *message, rowWidth, contentWidth);
	contentHeight = messageFontMetrics.height() * lines ;
	reamainWidth = blockWidth - rowWidth - border * 2 - rowHeight;

	if (showName)
		username->show();
	else
		username->close();

	message->resize(contentWidth, contentHeight+textHeight*2);
	blockHeight = contentHeight + textHeight * 3 + nameHeight;
	this->resize(blockWidth, blockHeight);

	message->setStyleSheet("background-color: rgb(225, 225, 225);border-radius:8px; border-style: solid;");
	profile->setStyleSheet("border-style: solid");
	if (type == Type::Left)
	{
		profile->move(border, border);
		message->move(border * 2 + rowHeight, textHeight*0.5 + nameHeight);
		username->setGeometry(message->x(), 0, this->width() - profile_width - border * 2, nameHeight);
	}
	else if (type == Type::Right)
	{
		profile->move(blockWidth - rowHeight - border, border);
		message->move(reamainWidth - border + rowWidth - contentWidth, textHeight*0.5 + nameHeight);
		username->setGeometry(0, 0, this->width() - profile_width - border * 2, nameHeight);
		username->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	}
	

	this->show();
}

MessageBlock::MessageBlock(QListWidget* _parent,QString&& msg, uint userID, Type _type, bool _showName)
	:QWidget(_parent), senderID(userID), profile(new QLabel), message(new QLabel),
	username(new QLabel(this)),type(_type),showName(_showName)
{
	message->setText(msg);

	setupRuntimeData();
	setupView();
}

MessageBlock::~MessageBlock()
{
	if(type == Type::Left)
	{
		runtime_dataManager->remove_friendsInfo_samllProfileObject(senderID, profile);
		runtime_dataManager->remove_friendsInfo_usernameObject(senderID, username);
	}
	else if (type == Type::Right)
	{
		runtime_dataManager->remove_personalInfo_smallProfileObject(profile);
		runtime_dataManager->remove_personalInfo_usernameObject(username);
	}

	delete message;
	delete profile;
	delete username;
}

uint MessageBlock::getHeight()const
{
	return this->blockHeight;
}

uint MessageBlock::getWidth()const
{
	return this->blockWidth;
}