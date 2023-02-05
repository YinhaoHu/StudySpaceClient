#ifndef _HDATA_HPP_
#define _HDATA_HPP_

//	Centhoo Library: HData
//  Author: Henry Hoo
//  Note: More information is written in the README.md

#include<algorithm>
#include<string>
#include<vector>
#include<fstream>

namespace ceh
{
	namespace Data
	{
		class HData;
		class HDataItem;

		using HDataItem_key = std::string;
		using HDataItem_value = std::string;
		using HDataItem_values = std::vector<std::string>;
	};
}

struct ceh::Data::HDataItem
{
	std::string key;
	std::vector<std::string> values;

	HDataItem();
	HDataItem(const HDataItem& rhs);
	HDataItem(std::string& k, std::vector<std::string>& values);
	HDataItem(std::string&& k, std::vector<std::string>&& values);
	~HDataItem();

	bool operator==(HDataItem& rhs);
	HDataItem& operator=(HDataItem& rhs);
	HDataItem& operator=(HDataItem&& rhs);

	
	static inline std::string toStdString(HDataItem& item, char delimeter = ' ')
	{
		std::string retString = item.key + delimeter;

		for (const std::string& value : item.values)
		{
			retString += value + delimeter;
		}
		retString.back() = '\0';

		return retString;
	}
	static inline std::string toStdString(const HDataItem& item, char delimeter = ' ') {
		return toStdString(const_cast<HDataItem&>(item));
	}
	static inline HDataItem fromStdString(std::string& str, char delimeter = ' ')
	{
		HDataItem item;
		HDataItem_key key;
		HDataItem_values values;
		HDataItem_value tempValue;

		auto beginIter = str.begin(), endIter = find(beginIter, str.end(), delimeter);
		key.resize(endIter - beginIter);
		copy(beginIter, endIter , key.begin());
		beginIter = endIter + 1;
		while (beginIter  != str.end())
		{
			endIter = find(beginIter, str.end(), delimeter);
			tempValue.resize(endIter - beginIter);
			copy(beginIter, endIter, tempValue.begin());
			values.push_back(tempValue);

			beginIter = (endIter == str.end()) ? str.end() : endIter + 1;
		}
		item.key = key;
		item.values = values;

		return item;
	}
};

class ceh::Data::HData
{
public:
	HData(const char* filename, int delimiter = ' ');
	~HData();

	HDataItem& operator[](int idx)
	{
		return dataBuffer[idx];
	}

	void load();
	void save();

	bool fail();
	int size();

	int find(ceh::Data::HDataItem& x);
	HDataItem& access(int idx);
	bool modify(int idx, ceh::Data::HDataItem& newItem);
	bool remove(int idx);
	void append(ceh::Data::HDataItem& newItem);
	void append(ceh::Data::HDataItem&& newItem);
private:
	int delimiter;
	std::fstream fileObject;
	std::vector<HDataItem> dataBuffer;
};

#endif