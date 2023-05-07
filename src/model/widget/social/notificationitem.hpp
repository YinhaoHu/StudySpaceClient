#include"view/widget/social/ui_notification.hpp"

#include<qlistwidget.h>

class NotificationItem : public QWidget
{
	Q_OBJECT

public:
	enum Type { FriendRequest, PureNotice };

	static const unsigned int itemHeight = 76;
	static const unsigned int itemWidth = 200;

private:
	Ui::Notification view;
	Type type;

private:
	uint userIDNum;
	QString* userName;
	QString* userID;

private:
	uint pureNoticeID;//0~1e5 only
	QString* pureNotification;

private:
	void setupView();
	void setupDelegate()const;

public:
	NotificationItem(QListWidget* parent,uint idnum,
		QString&& username, QString&& userid,Type _type=Type::FriendRequest);
	NotificationItem(QListWidget* parent,QString&& msg, 
		uint noticeID, Type _type=Type::PureNotice);
	~NotificationItem();

public slots:
	void addFriend_sendAccept();
	void addFriend_sendReject();
	void pureNotice_confirmSlot();

signals:
	void deleteMe(uint id);
};
