#include"studyaidslist.hpp"

// Contruct and destruct
StudyAidsList::StudyAidsList(QWidget* parent)
	:QWidget(parent)
{
	setupView();
	setupDelegate();
}

StudyAidsList::~StudyAidsList() {}

//Setup section
void StudyAidsList::setupView()
{
	view.setupUi(this);
	close();
}

void StudyAidsList::setupDelegate()
{
	connect(view.focusButton, &QPushButton::pressed, 
		this, [=](){emit noticePageSwitchToWidget(StudyAidsPage::Focus); });
	connect(view.scheduleButton, &QPushButton::pressed, 
		this, [=](){emit noticePageSwitchToWidget(StudyAidsPage::Schedule); });


}
