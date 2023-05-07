#include"addfriendform.hpp"
#include"inc_tip/extern_tipwindow.hpp"
#include"inc_net/extern_net.hpp"
#include"inc_data/extern_data.hpp"

#include<algorithm>

using namespace std;

void AddFriendForm::setupView()
{
	view.setupUi(this);
}

void AddFriendForm::setupDelegate()const
{
	connect(view.makeAddButton, SIGNAL(pressed()), this, SLOT(checkInput()));
}

void AddFriendForm::setupNetController()const
{
	connect(netController, &net::NetController::addFriend_Check_signal,
		this, &AddFriendForm::addFriend_Check_slot);
}

void AddFriendForm::requestAddFriend()const
{
	/*
	*		Order
	*    ->Prog: ADDFRIEND_REQUEST ID
	*    ->Msg : USERID
	*/

	QString* reqeustHead = new QString("ADDFRIEND_REQUEST ");
	reqeustHead->append(QString::number(local_dataManager->getUserID()));
	{
		unique_lock lock(netMutexLock);

		clientNet->easySend_Msg(std::move(*reqeustHead));
		clientNet->easySend_U32String(std::move(view.numberInput->text()));
	}
}

AddFriendForm::AddFriendForm(QWidget* parent)
	:QWidget(parent)
{
	setupView();
	setupDelegate();
	setupNetController();
}

void AddFriendForm::checkInput()
{
	//Empty or non digit or to many
	auto data = view.numberInput->text().toStdU32String();
	
	if (data.empty())
		tipWindow->inform(std::move(QString("请输入ID")));
	else if (data.end() != find_if(data.begin(), data.end(),
		[](char32_t ch) {return ch < U'0' || ch > U'9'; }))
		tipWindow->inform(std::move(QString("用户ID仅包含数字")));
	else if (data.length() < 5 || data.length() > 12)
		tipWindow->inform(std::move(QString("ID长度仅允许在5~12位")));
	else if (data.compare(QString::number(local_dataManager->getUserID()).toStdU32String())== 0 )
		tipWindow->inform(std::move(QString("不能添加自己为好友")));
	else
		requestAddFriend();
}

void AddFriendForm::addFriend_Check_slot(QString msg)
{
	tipWindow->inform(std::move(msg));
}
