#include"netcontroller.hpp"
#include"net.hpp"
#include"standard.hpp"
#include"inc_data/extern_data.hpp"

#include<algorithm>
#include<mutex>
#include<string>

#include<cstdio>

#include<QtGui/qpixmap.h>
#include<QtCore/qstring.h>

using namespace std;
using namespace net;

using CMD = u32string;
using NOTICE = QString;

extern NetController* netController;
extern std::mutex NetControllerMutexLock;
extern net::Client* clientNet;
extern std::mutex netMutexLock;

static inline bool matchCmd(CMD& eventTypeStr, CMD& cmd);

static inline void comChatRecv_handler();
static inline void userinfoChangePassword_Handler();
static inline void changeInfoChangeOk_Handler();
static inline void getFriendListOK_hander();
static inline void addFriendRequest_Handler();
static inline void getNotification_Handler();
static inline void loadNewFriendInfo_Handler();

//Any communication with server should be registered here.

static struct {
	CMD comChatRecv =U"COMCHATRECV";
	CMD userinfoChangePasswordRecv = U"USERINFO_CHANGE_OLDPASSWORD";
	CMD userinfoChangeOk = U"USERINFO_CHANGE_OK";
	CMD getFriendListOK = U"GETFRIENDSLIST_OK";
	CMD addFriendRequest = U"ADDFRIEND_REQUEST";
	CMD notification = U"NOTICE";
	CMD loadNewFriendInfo = U"LOAD_NEW_FRIEND_INFO";
	CMD removeFriend = U"REMOVE_FRIEND";
}cmdList;

static struct {
	NOTICE addFriend_Confirm = "ADDFRIEND_CONFIRM" ;
	NOTICE addFriend_request = "ADDFRIEND_REQUEST";
	NOTICE removeFriend = "REMOVE_FRIEND";
}noticeList;

void net::netControllerEntry(NetController* controller)
{
	char32_t* eventType;
	u32string eventTypeStr;

	eventType = new char32_t[net::sockMsgLen];//Do NOT delete.
	memset(eventType, 0, net::sockMsgBytes);

	// It is forced to use recvMsg to get the cmd
	while (clientNet->recvMsg(eventType) > 0)
	{
		eventTypeStr = eventType;

		if (matchCmd(eventTypeStr, cmdList.comChatRecv))
		{
			comChatRecv_handler();
		}
		else if (matchCmd(eventTypeStr, cmdList.userinfoChangePasswordRecv))
		{
			userinfoChangePassword_Handler();
		}
		else if (matchCmd(eventTypeStr, cmdList.userinfoChangeOk))
		{
			changeInfoChangeOk_Handler();
		}
		else if(matchCmd(eventTypeStr, cmdList.getFriendListOK))
		{
			getFriendListOK_hander();
		}
		else if (matchCmd(eventTypeStr, cmdList.addFriendRequest))
		{
			addFriendRequest_Handler();
		}
		else if (matchCmd(eventTypeStr, cmdList.notification))
		{
			getNotification_Handler();
		}
		else if (matchCmd(eventTypeStr, cmdList.loadNewFriendInfo))
		{
			loadNewFriendInfo_Handler();
		}
	}
}

//Comchat part.
void NetController::initComChatRecv_data()
{
	comChatRecv_data.senderProfile = QPixmap();
	comChatRecv_data.sendername = QString();
	comChatRecv_data.msg = QString();
}


//Get friendList part.
void NetController::getFriendList_initData()
{
	auto& data = getFriendList_data;
	if (data.inited)
		return;

	data.id = new QVarLengthArray<QString>;
	data.onlineStatus = new QVarLengthArray<QString>;
	data.name = new QVarLengthArray<QString>;
	data.intro = new QVarLengthArray<QString>;
	data.inited = true;
}

void NetController::getFriendList_deleteData()
{
	auto& data = netController->getFriendList_data;
	if (data.inited == false)
		return;
	delete data.id;
	delete data.onlineStatus;
	delete data.name;
	delete data.intro;
	data.inited = false;
}

//Update part.

static inline bool matchCmd(CMD& eventTypeStr, CMD& cmd)
{
	return equal(eventTypeStr.begin(), eventTypeStr.end(),
		cmd.begin(), cmd.end());
}

static inline void comChatRecv_handler()
{
	//Socket Message Format:
	//<USERNMAE>
	//<MSG>
	//<SIZE>
	//<PROFILE SIZE>
	//<PROFILE>
	const int sizeBufBytes = 16, idStrBytes = 16;
	int profile_size;
	char32_t* username_buf, *msg_buf;
	char* profile_buf, profile_sizeStr[sizeBufBytes],id_str[idStrBytes], * end;
	QString usernmae_str, msg_str;
	QPixmap profile_pixmap;

	username_buf = new char32_t[net::sockMsgLen];
	msg_buf = new char32_t[net::sockMsgLen];
	
	memset(username_buf, 0, net::sockMsgBytes);
	memset(msg_buf, 0, net::sockMsgBytes);
	memset(id_str, 0, idStrBytes);

	netMutexLock.lock();
	//Critical section: begin
	clientNet->recvMsg(username_buf);
	clientNet->recvMsg(msg_buf);
	clientNet->recvFile(profile_sizeStr, sizeBufBytes);

	profile_size = strtol(profile_sizeStr,&end,10);
	profile_buf = new char[profile_size];
	
	clientNet->recvFile(id_str, idStrBytes);
	clientNet->recvFile(profile_buf, profile_size);
	//Critical section: end
	netMutexLock.unlock();

	char tempFilename[standard::size::fieldBytes];
	memset(tempFilename, 0, standard::size::fieldBytes);
	strcpy(tempFilename, standard::dir::old_sub0_tempDir);
	strcat(tempFilename, "profile");
	strcat(tempFilename, id_str);
	strcat(tempFilename, ".jpg");
	
	FILE* tempFile = fopen(tempFilename, "wb");
	fwrite(profile_buf, sizeof(char), profile_size, tempFile);
	fclose(tempFile);

	profile_pixmap.load(tempFilename);
	usernmae_str = QString::fromStdU32String(username_buf);
	msg_str = QString::fromStdU32String(msg_buf);


	NetControllerMutexLock.lock();
	//Critical section: begin
	netController->comChatRecv_data.msg = msg_str;
	netController->comChatRecv_data.sendername = usernmae_str;
	netController->comChatRecv_data.senderProfile = profile_pixmap;
	//Critical section: end
	NetControllerMutexLock.unlock();

	emit netController->comChatRecv_update();
}

static inline void userinfoChangePassword_Handler()
{
	char32_t* oldPassWord_cstr = new char32_t[net::sockMsgLen];

	memset(oldPassWord_cstr, 0, net::sockMsgBytes);
	{
		unique_lock lock(netMutexLock);
		clientNet->recvMsg(oldPassWord_cstr);
	}

	netController->userInfo_change_data.oldPassword
		= new QString(QString::fromStdU32String(oldPassWord_cstr));

	delete[] oldPassWord_cstr;

	emit netController->password_update_signal();
}

static inline void changeInfoChangeOk_Handler()
{
	emit netController->changeInfo_update_signal();
}

static inline void getFriendListOK_hander()
{
	{
		unique_lock lock(NetControllerMutexLock);
		netController->getFriendList_initData();
		auto& data = netController->getFriendList_data;
		{
			unique_lock lock(netMutexLock);
			auto recvHead_num = clientNet->easyRecv_QString_U32()->toInt();

			for (unsigned int i = 0; i < recvHead_num; ++i)
			{
				auto recvLoop1_id = clientNet->easyRecv_QString_U32();
				auto recvLoop2_name = clientNet->easyRecv_QString_U32();
				auto recvLoop3_status = clientNet->easyRecv_QString_U32();
				auto recvLoop4_intro = clientNet->easyRecv_QString_U32();
				auto recvLoop5_profile = clientNet->easyRecv_File();

				data.id->push_back(*recvLoop1_id);
				data.name->push_back(*recvLoop2_name);
				data.onlineStatus->push_back(*recvLoop3_status);
				data.intro->push_back(*recvLoop4_intro);
				local_dataManager->updateFriendProfile
				(recvLoop1_id->toUInt(), recvLoop5_profile);
			}
		}
	}
	emit netController->getFriendList_update_signal();
}

static inline void addFriendRequest_Handler()
{
	/*
	PROBABLY:
		NONEXIST
		ALREADY
		OK
	*/
	decltype(clientNet->easyRecv_QString_U32()) response;
	{
		unique_lock lock(netMutexLock);
		response = clientNet->easyRecv_QString_U32();
	}

	if (response->compare("NONEXIST") == 0)
		emit netController->addFriend_Check_signal(QString("不存在这个用户"));
	else if (response->compare("ALREADY") == 0)
		emit netController->addFriend_Check_signal(QString("你已经是TA的好友"));
	else if (response->compare("OK") == 0)
		emit netController->addFriend_Check_signal(QString("申请已发送"));
	else if (response->compare("REQUESTED") == 0)
		emit netController->addFriend_Check_signal(QString("不可重复申请添加"));
	else
		emit netController->addFriend_Check_signal(QString("未知信息"));
}

static inline void getNotification_Handler()
{
	decltype(clientNet->easyRecv_QString_U32())notification;
	{
		unique_lock lock(netMutexLock);
		notification = clientNet->easyRecv_QString_U32();
	}

	auto sections = notification->split(' ');
	auto& prog = sections.front();

	if (prog == noticeList.addFriend_request)
	{
		auto& username = sections[1];
		auto& userID = sections[2];

		emit netController->addFriend_Notice_signal(username, userID);
	}
	else if(prog == noticeList.addFriend_Confirm)
	{
		 auto& fromID = sections[1];
		 auto& res = sections[2];

		 if (res == QString("ACCEPT"))
			 emit netController->addFriend_accepted_signal(fromID);
		 else
			 emit netController->addFriend_rejected_signal(fromID);
	}
	else if (prog == noticeList.removeFriend)
	{
		auto& ID_toDelete = sections[1];

		emit netController->removeFriend_signal(std::move(ID_toDelete));
	}
}

static inline void loadNewFriendInfo_Handler()
{
	decltype(clientNet->easyRecv_File())recv1_profile;
	decltype(clientNet->easyRecv_QString_U32())recv2_username,
		recv3_intro, recv4_onlineStatus,recv5_userid;
	//All data is of the new friend
	{
		unique_lock lock(netMutexLock);
		recv1_profile = clientNet->easyRecv_File();
		recv2_username = clientNet->easyRecv_QString_U32();
		recv3_intro = clientNet->easyRecv_QString_U32();
		recv4_onlineStatus = clientNet->easyRecv_QString_U32();
		recv5_userid = clientNet->easyRecv_QString_U32();
	}

	auto userIDNum = recv5_userid->toULong();
	
	local_dataManager->updateFriendProfile(userIDNum, recv1_profile);

	runtime_dataManager->update_friendsInfo_bigProfileObject(userIDNum);
	runtime_dataManager->update_friendsInfo_smallProfileObject(userIDNum);
	runtime_dataManager->update_friendsInfo_introObjects
			(userIDNum, std::move(*recv3_intro));
	runtime_dataManager->update_friendsInfo_usernameObject
			(userIDNum, std::move(*recv2_username));
	runtime_dataManager->update_friendsInfo_onlineStatusObject
			(userIDNum, std::move(*recv4_onlineStatus));

	emit netController->addFriend_makeListItem_signal(userIDNum);
}
