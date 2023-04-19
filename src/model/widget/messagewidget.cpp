#include"messagewidget.hpp"

#include"../../data/runtime_datamanager.hpp"

#include<QtWidgets/qlabel.h>
#include<QtGui/qpixmap.h>
#include<QtGui/qfontmetrics.h>

extern QSharedPointer<data::Runtime_DataManager> runtime_dataManager;

int MessageWidget::formatString(QString& str, QLabel& label,int maxLine,int& contentWidth)
{
	int lines,size;
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
		if (fontMetrics.horizontalAdvance(lineBuffer) >= maxLine )
		{
			newStr.append(lineBuffer+'\n');
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

	newStr.append(lineBuffer+ spacing);
	label.setText(newStr);
	if (lines == 1)
		contentWidth = fontMetrics.horizontalAdvance(lineBuffer+ spacing);
	else
		contentWidth = (maxLine + fontMetrics.horizontalAdvance(spacing));
	return lines;
}

MessageWidget::MessageWidget(int rheigh, int rwidth,int msgSpacing, QWidget* parent)
	:QWidget(parent), rowHeight(rheigh), rowWidth(rwidth),spacing(msgSpacing)
{
	parentWidget = parent;
	msgCount = 0;
	resize(parentWidget->width(), 0);
	setMinimumSize(rowWidth, 0);
}

void MessageWidget::
addMsg(QString&& msg, QPixmap&& senderProfile, QString&& senderUsername,Message::MessageType type,bool showName ) 
{
	QWidget* messageBlock;
	QLabel* messageContent, * messageSenderProfile, *messageSenderUsername;
	QFont messageFont("Microsoft YaHei UI",16), usernameFont("Microsoft YaHei UI", 8);
	QFontMetrics usernameFontMetrics(usernameFont);
	int lines, newHeight, contentHeight, contentWidth, reamainWidth, nameHeight;

	messageBlock = new QWidget;
	messageContent = new QLabel;
	messageSenderProfile = new QLabel;
	messageSenderUsername = new QLabel;

	nameHeight = border * 1.5;
	messageContent->setFont(messageFont);
	lines = formatString(msg, *messageContent,rowWidth,contentWidth);

	contentHeight = rowHeight * lines;

	newHeight = spacing + this->minimumHeight() + contentHeight+ nameHeight;
	reamainWidth = parentWidget->width() - rowWidth - border * 2 - rowHeight;
	
	messageBlock->setParent(this);
	messageContent->setParent(messageBlock);
	messageSenderProfile->setParent(messageBlock);
	messageSenderUsername->setParent(messageBlock);

	if(showName)
		messageSenderUsername->setText(senderUsername);
	messageSenderProfile->setPixmap(senderProfile.scaled(profile_width, profile_height));
	messageSenderProfile->resize(rowHeight, rowHeight);
	messageContent->resize(contentWidth, contentHeight);
	messageBlock->resize(this->width(), contentHeight+border*2+nameHeight);

	messageContent->setStyleSheet("background-color: rgb(225, 225, 225);border-radius:16px;");
	messageSenderProfile->setStyleSheet("border-radius:16px;");
	if (type == Message::Receiver)
	{
		messageSenderProfile->move(border,border);
		messageContent->move(border*2+rowHeight,border+nameHeight);
		messageSenderUsername->move(messageContent->x(), 0);
	}
	else if(type == Message::Sender)
	{
		messageSenderProfile->move(parentWidget->width()-rowHeight-border,border);
		messageContent->move(reamainWidth-border + rowWidth - contentWidth, border + nameHeight);
		messageSenderUsername->setGeometry(0,0,messageBlock->width()-profile_width-border*2, 20);
		messageSenderUsername->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	}
	messageBlock->move(0, this->height());

	this->setMinimumHeight(newHeight);
	parentWidget->setMinimumHeight(newHeight);
	++msgCount;

	messageContent->show();
	messageSenderProfile->show(); 
	messageBlock->show();

	if(type == Message::Sender)
	{
		runtime_dataManager->add_personalInfo_smallProfileObject(messageSenderProfile);
		runtime_dataManager->add_personalInfo_usernameObject(messageSenderUsername);
	}
}