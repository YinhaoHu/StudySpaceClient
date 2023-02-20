#include"HData.hpp"

using namespace ceh::Data;
using namespace std;

HDataItem::HDataItem()
{
	key = HDataItem_key();
	values = HDataItem_values();
}
HDataItem::HDataItem(const HDataItem& rhs)
{
	key = rhs.key;
	values = rhs.values;
}
HDataItem::HDataItem(HDataItem_key& _key, HDataItem_values& _values)
{
	key = _key;
	values = _values;
}
HDataItem::HDataItem(HDataItem_key&& _key, HDataItem_values&& _values)
{
	key = _key;
	values = _values;
}
HDataItem::~HDataItem()
{
	key.clear();
	values.clear();
}

bool HDataItem::operator==(HDataItem& rhs)
{
	bool valuesEqual = equal(rhs.values.begin(), rhs.values.end(), values.begin(), values.end());
	bool keyEqual = (rhs.key == key);

	return valuesEqual && keyEqual;
}
HDataItem& HDataItem::operator=(HDataItem& rhs)
{
	key = rhs.key;
	values = rhs.values;

	return *this;
}
HDataItem& HDataItem::operator=(HDataItem&& rhs)
{
	key = rhs.key;
	values = rhs.values;
	return *this;
}

