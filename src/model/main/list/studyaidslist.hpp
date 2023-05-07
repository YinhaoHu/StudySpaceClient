#pragma once

#include"view/main/list/ui_studyaidslist.hpp"
#include"model/main/page/studyaidspage.hpp"

class StudyAidsList : public QWidget
{
	Q_OBJECT

private:
	Ui::StudyAidsList view;

	void setupView();
	void setupDelegate();

public :
	StudyAidsList(QWidget* parent);
	~StudyAidsList(); 


signals:
	void noticePageSwitchToWidget
		(StudyAidsPage::WidgetOptions option);

};