#include"focuswidget.hpp"

#include"inc_data/extern_data.hpp"
#include"inc_data/studyaids/smartextern_focus.hpp"

FocusWidget::FocusWidget(QWidget* parent)
	:QWidget(parent),currentContent(nullptr)
{
	setupView();
	setupDelegate();
	setupWidgets();
}

FocusWidget::~FocusWidget()
{
	if(currentContent != nullptr)
		currentContent->close();
	delete focusDataManager;
}

void FocusWidget::initDataManager()
{
	::focusDataManager = new data::FocusDataManager;

	widgets.dataView->initView();
}

void FocusWidget::setupView()
{
	view.setupUi(this);
	close();
}

void FocusWidget::setupDelegate()
{
	connect(this, &FocusWidget::noticeSwitchToContentWidget, 
		this, &FocusWidget::switchToContentWidget);

	connect(view.dataViewButton, &QPushButton::pressed,
		this, [=]() {emit noticeSwitchToContentWidget(DataView); });
	
	connect(view.startFocusButton, &QPushButton::pressed,
		this, [=]() {emit noticeSwitchToContentWidget(StartFocus); });

}

void FocusWidget::setupWidgets()
{
	widgets = {new DataViewWidget(view.contentWidget),
				new StartFocusWidget(view.contentWidget)};

	connect(widgets.startFocus, SIGNAL(dataUpdated()),
		widgets.dataView, SLOT(updateView()));

	currentContent = widgets.startFocus;
	currentContent->show();
}

void FocusWidget::switchToContentWidget(ContentOption option)
{	
	currentContent->close();

	switch (option) 
	{
	case FocusWidget::StartFocus:
		currentContent = widgets.startFocus;
		break;
	case FocusWidget::DataView:
		currentContent = widgets.dataView;
		break;
	default:
		break;
	}

	currentContent->show();
}
