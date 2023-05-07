#include"studyaidspage.hpp"


StudyAidsPage::StudyAidsPage(QWidget* parent)
	:QWidget(parent),currentWidget(nullptr)
{
	setupView();
	setupWidgets();
}

StudyAidsPage::~StudyAidsPage()
{
}

void StudyAidsPage::setupView()
{
	view.setupUi(this);

	close();
}

void StudyAidsPage::setupWidgets()
{
	widgets = {
		new FocusWidget(this),
		new ScheduleWidget(this)
	};
}

void StudyAidsPage::setupLocalDatamanager()
{
	widgets.focusWidget->initDataManager();
	widgets.schedulWidget->initDataManager();
}

void StudyAidsPage::switchToWidget(WidgetOptions option)
{
	if (currentWidget != nullptr)
		currentWidget->close();

	switch (option)
	{
	case StudyAidsPage::Focus:
		currentWidget = widgets.focusWidget;
		break;
	case StudyAidsPage::Course:
		break;
	case StudyAidsPage::Target:
		break;
	case StudyAidsPage::Schedule:
		currentWidget = widgets.schedulWidget;
		break;
	default:
		break;
	}
	currentWidget->show();
}