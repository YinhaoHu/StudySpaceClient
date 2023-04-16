#include"HData.hpp"

#include<locale>

using namespace ceh::Data;
using namespace std;

HWData::HWData(const char* filename, wchar_t _delimiter)
	:delimiter(_delimiter)
{
	fileObject.open(filename, ios_base::out | ios_base::in);
	fileObject.imbue(std::locale(".UTF-8"));
}
HWData::~HWData()
{
	fileObject.close();
}

HWDataItem& HWData::operator[](int idx)
{
	return dataBuffer[idx];
}

void HWData::load()
{
	wstring lineStr;
	HWDataItem item;

	dataBuffer.clear();
	while (getline(fileObject, lineStr,L'\n').good())
	{
		item = HWDataItem::fromStdWString(lineStr);
		dataBuffer.push_back(item);
	}
	fileObject.clear();
	fileObject.seekp(0);
}
void HWData::save()
{
	size_t loop_end = dataBuffer.size() - 1;
	for (size_t i = 0; i < loop_end; ++i)
	{
		fileObject << HWDataItem::toStdWString(dataBuffer[i]) + L"\n";
	}
	if(dataBuffer.empty() == false)
		fileObject << HWDataItem::toStdWString(dataBuffer.back());
	fileObject.clear();
	fileObject.seekg(0);
}

bool HWData::fail()
{
	return fileObject.fail();
}
int HWData::size()
{
	return dataBuffer.size();
}

int HWData::find(ceh::Data::HWDataItem& x)
{
	for (int idx = 0; idx < dataBuffer.size(); ++idx)
	{
		if (x == dataBuffer[idx])
			return idx;
	}
	return -1;
}
HWDataItem& HWData::access(int idx)
{
	if (idx >= dataBuffer.size())
		throw out_of_range("[Hdata]Access out of range.\n");
	return dataBuffer[idx];
}
bool HWData::modify(int idx, ceh::Data::HWDataItem& newItem)
{
	if (idx >= dataBuffer.size())
		return false;
	else
	{
		dataBuffer[idx] = newItem;
		return true;
	}
}
bool HWData::remove(int idx)
{
	if (idx >= dataBuffer.size())
		return false;
	else
	{
		dataBuffer.erase(dataBuffer.begin() + idx);
		return true;
	}
}
void HWData::append(ceh::Data::HWDataItem& newItem)
{
	dataBuffer.push_back(newItem);
}
void HWData::append(ceh::Data::HWDataItem&& newItem)
{
	dataBuffer.push_back(newItem);
}
