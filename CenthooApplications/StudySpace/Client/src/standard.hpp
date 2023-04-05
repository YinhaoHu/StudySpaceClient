﻿#ifndef _STANDRAD_HPP_
#define _STANDRAD_HPP_

#include<qstring.h>

namespace standard {
	namespace file {
		 inline const char* netConfigFile = "config/netConfig.hdat";
		 inline const char* selfProfile = "userdata/self/selfProfile.jpg";
		 inline const char* tempFileDir = "userdata/temp/";
	}
	
	namespace size {
		inline const int profileBytes = 4096;
		inline const int fieldBytes = 64;
	}

	namespace text {
		 enum fontSize{tinyFont = 8, smallFont=12,midFont = 16, 
					bigFont = 20, hugeFont = 24, titleFont = 32};
	}
	
	namespace dataStruct {
		struct UserData {
			QString selfUsername;
			QString selfID;
			QString selfProfileFilename;
		};
	}
	namespace view {
		namespace page
		{
			inline constexpr int width = 870;
			inline constexpr int height = 700;
		}
		namespace list 
		{
			inline constexpr int width = 200;
			inline constexpr int height = 700;
		}
	}
}

#endif

