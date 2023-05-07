#include"feedback_window.hpp"

#include"inc_net/extern_net.hpp"
#include"inc_tip/extern_tipwindow.hpp"
#include"inc_data/extern_data.hpp"

FeedBackWindow::FeedBackWindow()
{
	view.setupUi(this);
	setWindowFlag(Qt::FramelessWindowHint);

	connect(view.sendButton, SIGNAL(pressed()), this, SLOT(sendFeedBack()));
	connect(view.quitButton, SIGNAL(pressed()), this, SLOT(close()));

	close();
}

FeedBackWindow::~FeedBackWindow()
{

}

void FeedBackWindow::sendFeedBack()
{
	auto content = view.inputArea->toPlainText();

	if (content.isEmpty())
		tipWindow->inform(QString("请输入反馈内容"));
	else
	{
		view.inputArea->clear();
		clientNet->easySend_Request(std::move(QString("FEEDBACK")), local_dataManager->getUserID());
		clientNet->easySend_U32String(std::move(content));
		tipWindow->inform(QString("收到你的反馈 :)"));
	}
}

