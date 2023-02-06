#include"HData.hpp"

using namespace ceh::Data;
using namespace std;

HData::HData(const char* filename, int _delimiter )
{
	fileObject.open(filename, ios_base::out | ios_base::in);
	delimiter = _delimiter;
}
HData::~HData()
{
	fileObject.close();
}

HDataItem& HData::operator[](int idx)
{
	return dataBuffer[idx];
}

void HData::load()
{
	string lineStr;
	HDataItem item;
	
	dataBuffer.clear();
	while (getline(fileObject, lineStr).good())
	{
		item = HDataItem::fromStdString(lineStr);
		dataBuffer.push_back(item);
	}
	fileObject.clear();
	fileObject.seekp(0);
}
void HData::save()
{
	for (int i = 0; i < dataBuffer.size(); ++i)
	{ 
		fileObject << HDataItem::toStdString(dataBuffer[i]) + "\n";
	}
	fileObject.clear();
	fileObject.seekg(0);
}

bool HData::fail()
{
	return fileObject.fail();
}
int HData::size()
{
	return dataBuffer.size();
}

int HData::find(ceh::Data::HDataItem& x)
{
	for (int idx = 0; idx < dataBuffer.size(); ++idx)
	{
		if (x == dataBuffer[idx])
			return idx;
	}
	return -1;
}
HDataItem& HData::access(int idx)
{
	if (idx >= dataBuffer.size())
		throw out_of_range("[Hdata]Access out of range.\n");
	return dataBuffer[idx];
}
bool HData::modify(int idx, ceh::Data::HDataItem& newItem)
{
	if (idx >= dataBuffer.size())
		return false;
	else
	{
		dataBuffer[idx] = newItem;
		return true;
	}
}
bool HData::remove(int idx)
{
	if (idx >= dataBuffer.size())
		return false;
	else
	{
		dataBuffer.erase(dataBuffer.begin() + idx);
		return true;
	}
}
void HData::append(ceh::Data::HDataItem& newItem)
{
	dataBuffer.push_back(newItem);
}
void HData::append(ceh::Data::HDataItem&& newItem)
{
	dataBuffer.push_back(newItem);
}
