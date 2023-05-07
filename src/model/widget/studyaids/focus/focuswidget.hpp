#pragma once

#define _FOCUS_WIDGET_

#include"view/widget/studyaids/focus/focuswidget.hpp"
#include"model/widget/studyaids/focus/dataview.hpp"
#include"model/widget/studyaids/focus/startfocus.hpp"

class FocusWidget : public QWidget
{
	Q_OBJECT
private:
	enum ContentOption {StartFocus, DataView};
	
	static const uint contentHeight = 620;
	static const uint contentWidth = 870;

	Ui::FocusWidget view;
	QWidget* currentContent;

	struct {
		DataViewWidget* dataView;
		StartFocusWidget* startFocus;
	}widgets;

	void setupView();
	void setupDelegate();
	void setupWidgets();

public:
	FocusWidget(QWidget* parent);
	~FocusWidget();

	void initDataManager();

private slots:
	void switchToContentWidget(ContentOption option);

signals:
	void noticeSwitchToContentWidget(ContentOption option);
};