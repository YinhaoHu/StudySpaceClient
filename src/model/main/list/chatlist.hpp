#include"view/main/list/ui_chatlist.hpp"
#include"model/main/page/chatpage.hpp"
#include"model/widget/chat/privatechatlistitem.hpp"

#include<qlistwidget.h>
#include<qhash.h>

class ChatList: public QWidget
{
	Q_OBJECT

friend class MainWindow;

private:
	Ui::ChatList view;
	ChatPage* relatedPage;

	QHash<uint, QListWidgetItem*>* dialogItems;
	QHash<uint, PrivateChatListItemWidget*>* privateDialogWidgets;

	void addDialogItem(uint otherID);

	void setupView();
	void setupNetController()const;
	void setupDelegate()const;
	void setRealatedPage(ChatPage* page);
	void setupLocalData();

public:
	ChatList(QWidget* parent);
	~ChatList();
	 
public slots:
	void forwardItemInfo_slot(QListWidgetItem* whichItem);

	void getPrivateChatNotice_netSlot(uint userID);
	void removeDialogItem(QString otherID);
	void jumpToDialog_slot(uint userID);

signals:
	void privateChat_noticeOpenPage_signal(uint  userID);
	void privateChat_noticeRemovePage_signal(uint otherID);
};