#ifndef _MACRO_HPP
#define _MACRO_HPP

//For some reason, this is a silly design
inline const int maxFieldSize = 64;
inline const int maxArgsSize = 1000;
inline const int maxLineSize = 1024;
inline const int maxSockBufferSize = 1024;
inline const int maxSockBufferBytes = 4096;
inline const int maxFileSize = 1024000;

namespace standard{
    inline const char* userProfileDir = "data/userprofile/";
    inline const char* dataFileDir = "data/";
    inline const char* userDataFile = "data/users.hdat";

    inline const int userid_begin = 10001;

    namespace userDataField{
        inline const int  username = 0;
        inline const int  password = 1;
        inline const int  email = 2;
        inline const int  regyear = 3;
        inline const int  regmonth = 4;
        inline const int  regday = 5;
    }
}

#endif