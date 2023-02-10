#ifndef _HDATA_HPP_
#define _HDATA_HPP_

//	Centhoo Library: HData
//  Author: Henry Hoo
//  Note: More information is written in the README.md

#include<algorithm>
#include<string>
#include<vector>
#include<fstream>
#include<codecvt>
#include<locale>

namespace ceh
{
	namespace Data
	{
		class HData;
		class HWData;
		class HDataItem;
		class HWDataItem;

		using HDataItem_key = std::string;
		using HDataItem_value = std::string;
		using HDataItem_values = std::vector<HDataItem_value>;

		using HWDataItem_key = std::wstring;
		using HWDataItem_value = std::wstring;
		using HWDataItem_values = std::vector<HWDataItem_value>;

		static inline std::wstring UTF8toStdWstring(const std::string& utf8Str)
		{
			std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
			return myconv.from_bytes(utf8Str);
		}
		static inline std::string stdWstringToUTF8(const std::wstring& wStr)
		{
			std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
			return myconv.to_bytes(wStr);
		}
	};
}



struct ceh::Data::HDataItem
{
	std::string key;
	std::vector<std::string> values;

	HDataItem();
	HDataItem(const HDataItem& rhs);
	HDataItem(HDataItem_key& _key, HDataItem_values& _values);
	HDataItem(HDataItem_key&& _key, HDataItem_values&& _values);
	~HDataItem();

	bool operator==(HDataItem& rhs);
	HDataItem& operator=(HDataItem& rhs);
	HDataItem& operator=(HDataItem&& rhs);


	static inline std::string toStdString(HDataItem& item, char delimeter = ' ')
	{
		std::string retString = item.key + delimeter;
		int border = item.values.size() - 1;

		for (int i = 0; i < border; ++i)
		{
			retString += item.values[i] + delimeter;
		}
		retString += item.values[border];

		return retString;

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
		copy(beginIter, endIter, key.begin());
		while(endIter!=str.end())
		{
			beginIter = endIter + 1;
			endIter = find(beginIter, str.end(), delimeter);

			tempValue.resize(endIter - beginIter);
			copy(beginIter, endIter, tempValue.begin());
			values.push_back(tempValue);
		}
		item.key = key;
		item.values = values;

		return item;
		
	}
	static inline HDataItem fromStdString(std::string&& str, char delimeter = ' ')
	{
		fromStdString(std::move(str),delimeter);
	}

};

struct ceh::Data::HWDataItem
{
	HWDataItem_key key;
	HWDataItem_values values;

	HWDataItem();
	HWDataItem(const HWDataItem& rhs);
	HWDataItem(HWDataItem_key& k, HWDataItem_values& values);
	HWDataItem(HWDataItem_key&& k, HWDataItem_values&& values);
	~HWDataItem();

	bool operator==(HWDataItem& rhs);
	HWDataItem& operator=(HWDataItem& rhs);
	HWDataItem& operator=(HWDataItem&& rhs);


	static inline std::wstring toStdWString(HWDataItem& item, wchar_t delimeter = L' ')
	{
		std::wstring retString = item.key + delimeter;
		int border = item.values.size() - 1;

		for (int i = 0; i < border; ++i)
		{
			retString += item.values[i] + delimeter;
		}
		retString += item.values[border];

		return retString;
	}
	static inline std::wstring toStdWString(const HWDataItem& item, wchar_t delimeter = L' ') {
		return toStdWString(const_cast<HWDataItem&>(item));
	}
	static inline HWDataItem fromStdWString(std::wstring& str, wchar_t delimeter = L' ')
	{
		HWDataItem item;
		HWDataItem_key key;
		HWDataItem_values values;
		HWDataItem_value tempValue;

		auto beginIter = str.begin(), endIter = find(beginIter, str.end(), delimeter);
		key.resize(endIter - beginIter);
		copy(beginIter, endIter, key.begin());
		while (endIter != str.end())
		{
			beginIter = endIter + 1;
			endIter = find(beginIter, str.end(), delimeter);

			tempValue.resize(endIter - beginIter);
			copy(beginIter, endIter, tempValue.begin());
			values.push_back(tempValue);
		}
		item.key = key;
		item.values = values;

		return item;
	}
	static inline HWDataItem fromStdWString(std::wstring&& str, wchar_t delimeter = L' ')
	{
		return fromStdWString(std::move(str), delimeter);
	}
};

class ceh::Data::HData
{
public:
	HData(const char* filename, int delimiter = ' ');
	~HData();

	HDataItem& operator[](int idx);

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

class ceh::Data::HWData
{
public:
	HWData(const char* filename, wchar_t delimiter = L' ');
	~HWData();

	HWDataItem& operator[](int idx);

	void load();
	void save();

	bool fail();
	int size();

	int find(ceh::Data::HWDataItem& x);
	HWDataItem& access(int idx);
	bool modify(int idx, ceh::Data::HWDataItem& newItem);
	bool remove(int idx);
	void append(ceh::Data::HWDataItem& newItem);
	void append(ceh::Data::HWDataItem&& newItem);
private:
	wchar_t delimiter;
	std::wfstream fileObject;
	std::vector<HWDataItem> dataBuffer;
};

#endif
