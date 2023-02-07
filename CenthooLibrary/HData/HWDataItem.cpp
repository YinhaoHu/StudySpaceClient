#include"HData.hpp"

using namespace ceh::Data;
using namespace std;

HWDataItem::HWDataItem()
{
	key = HWDataItem_key();
	values = HWDataItem_values();
}
HWDataItem::HWDataItem(const HWDataItem& rhs)
{
	key = rhs.key;
	values = rhs.values;
}
HWDataItem::HWDataItem(HWDataItem_key& _key, HWDataItem_values& _values)
{
	key = _key;
	values = _values;
}
HWDataItem::HWDataItem(HWDataItem_key&& _key, HWDataItem_values&& _values)
{
	key = _key;
	values = _values;
}
HWDataItem::~HWDataItem()
{
	key.clear();
	values.clear();
}

bool HWDataItem::operator==(HWDataItem& rhs)
{
	bool valuesEqual = equal(rhs.values.begin(), rhs.values.end(), values.begin(), values.end());
	bool keyEqual = (rhs.key == key);

	return valuesEqual && keyEqual;
}
HWDataItem& HWDataItem::operator=(HWDataItem& rhs)
{
	key = rhs.key;
	values = rhs.values;

	return *this;
}
HWDataItem& HWDataItem::operator=(HWDataItem&& rhs)
{
	key = rhs.key;
	values = rhs.values;
	return *this;
}

