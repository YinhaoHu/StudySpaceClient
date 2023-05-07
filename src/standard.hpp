#ifndef _STANDRAD_HPP_
#define _STANDRAD_HPP_

#include<qstring.h>

namespace standard {
	namespace file {
		 inline const char* netConfigFile = "config/netconfig.json";
		 inline const char* loginInfoFile = "config/logininfo.json";
		 inline const char* homepageImage = "config/homepage.png";
	
		 inline const char* focusdata = "focusdata.json";
		 inline const char* todayScheduleData = "today.json";
	}

	namespace dir {
		inline const char* root = "userdata";

		inline const char* sub1_privateChat = "privatechat";
		inline const char* sub1_temp = "temp";
		inline const char* sub1_friends = "friends";
		inline const char* sub1_schedule = "schedule";
		inline const char* sub2_friends_profile = "profile";

		inline const char* old_sub0_tempDir = "userdata/temp";//Just compatiable with comchat, do not use this!
	}
	
	namespace size{
		inline const uint Byte = 8;
		inline const uint KB = 1024 * Byte;
		inline const uint MB = 1024 * KB;
		inline const uint profile_maxBytes = MB * 4;
		inline const uint fieldBytes = 64;
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
			QString selfIntro;
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
	namespace scale {
		inline constexpr size_t smallProfileSideLen = 32;
		inline constexpr size_t bigProfileSideLen = 100;
	}

	namespace guard
	{
		inline constexpr size_t username_maxLen = 12;
		inline constexpr size_t password_maxLen = 16;
		inline constexpr size_t password_minLen = 8;

	}
}

#endif

