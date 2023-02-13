#ifndef _HSTRING_HPP_
#define _HSTRING_HPP_

#include<cmath>

namespace ceh {
	namespace String {
		static void inline uintToC8Str(unsigned int number, char* result)
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
		static void inline uintToC32Str(unsigned int number, char32_t* result)
		{
			int bits, idx, highest;
			if (number == 0)
			{
				idx = 0;
				result[idx++] = U'0';
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
					result[idx] = U'0' + number / highest;
					number -= static_cast<int>(number / highest) * highest;
					++idx;
				}
			}
			result[idx] = U'\0';
		}
	}
}
