#ifndef _HSTRING_HPP_
#define _HSTRING_HPP_

#include<cmath>

namespace ceh {
	namespace String {
		static void inline uintToWStr(unsigned int number, wchar_t* result)
		{
			int bits, idx, highest;
			if (number == 0)
			{
				idx = 0;
				result[idx++] = L'0';
			}
			else
			{
				bits = 0;
				while (number / static_cast<int>(pow(10, bits)) != 0)
					++bits;
				idx = 0;
				while (--bits != -1)
				{
					highest = pow(10, bits);
					result[idx] = L'0' + number / highest;
					number -= static_cast<int>(number / highest) * highest;
					++idx;
				}
			}
			result[idx] = L'\0';
		}
		
		static void inline uintToStr(unsigned int number, char* result)
		{
			int bits, idx, highest;
			if (number == 0)
			{
				idx = 0;
				result[idx++] = '0';
			}
			else
			{
				bits = 0;
				while (number / static_cast<int>(pow(10, bits)) != 0)
					++bits;
				idx = 0;
				while (--bits != -1)
				{
					highest = pow(10, bits);
					result[idx] = '0' + number / highest;
					number -= static_cast<int>(number / highest) * highest;
					++idx;
				}
			}
			result[idx] = '\0';
		}
		

		static inline wchar_t* findwchr(wchar_t* buf, wchar_t val)
		{
    		for(wchar_t* p = buf; *p != L'\0'; ++p)
    		{
        		if(*p == val)
            		return p;
    		}	
    		return nullptr;
		}
	}
}

#endif