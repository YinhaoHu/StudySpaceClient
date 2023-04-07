#ifndef _ABSTRACTPAGE_HPP_
#define _ABSTRACTPAGE_HPP_

#include"../../../standard.hpp"

#include<QtCore/QObject>
#include<QtWidgets/QWidget>

class AbstractPage : public QWidget
{
	QOBJECT_H
protected:
	virtual void setupView() = 0;
	virtual void setupDelegate() const = 0;
	virtual void setupNetController() const = 0;

	static constexpr int pageWidth = standard::view::page::width;
	static constexpr int pageHeight = standard::view::page::height;

public:
	AbstractPage(QWidget* parent) {

	}
	virtual ~AbstractPage() = 0;
};

#endif