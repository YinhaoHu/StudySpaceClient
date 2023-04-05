#ifndef _ABSTRACTLIST_HPP_
#define _ABSTRACTLIST_HPP_

#include"../../../standard.hpp"

#include<QtCore/QObject>
#include<QtWidgets/QWidget>

class AbstractList : public QWidget
{
	QOBJECT_H
protected:
	virtual void setupView() = 0;
	virtual void setupDelegate() const = 0;
	virtual void setupNetController() const = 0;

	static constexpr int listWidth = standard::view::list::width;
	static constexpr int listHeight = standard::view::list::height;

public:
	AbstractList(QWidget* parent)
	{

	}
	virtual ~AbstractList() = 0;
};


#endif