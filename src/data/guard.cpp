#include"guard.hpp"
#include"standard.hpp"
#include"qimagereader.h"
using namespace standard::guard;


//return-> 0: ok	1:	length		2: include space (No empty check)
uint data::guard::isValid_UserName(QString&& username)
{
    if (username.length() > username_maxLen)
		return 1;
	else if (username.contains(' '))
		return 2;
	else
		return 0;
}

//return-> 0: ok	1:	length		2: include space (No empty check)
uint data::guard::isValid_UserName(QString& username)
{
	return data::guard::isValid_UserName(std::move(username));
}

//Only check format, no empty check.
bool data::guard::isValid_email(QString&& email)
{
	uint8_t dotCount = 0;
	bool atFoundFlag = false;

	for (auto& theCh : email)
	{
		if (theCh == '.')
			dotCount += 1;
		else if (dotCount == 0 && theCh == '@')
			atFoundFlag = true;
	}

	return dotCount == 1 && atFoundFlag && email.back() != '.';
}

//Only check format, no empty check.
bool data::guard::isValid_email(QString& email)
{
	return data::guard::isValid_email(std::move(email));
}

//return-> 0:ok		1:code(only: letter & digit.)		2:length	 (No empty check)
uint data::guard::isValid_password(QString&& password)
{
	if (password.length() > password_maxLen || password.length() < password_minLen)
		return 2;

	for (auto ch : password.toStdU16String())
	{
		if ( !( (ch >= u'0') && (ch <= u'9') )
			&& !( (ch >= u'a') && (ch <= u'z') )
			&& !( (ch >= u'A') && (ch <=u'Z')) )
			return 1;
	}

	return 0;
}

//return-> 0:ok		1:code(only: letter & digit.)		2:length	 (No empty check)
uint data::guard::isValid_password(QString& password)
{
	return data::guard::isValid_password(std::move(password));
}

bool data::guard::isValid_readImageFormat(QString& suffix)
{
	return isValid_readImageFormat(std::move(suffix));
}

bool data::guard::isValid_readImageFormat(QString&& suffix)
{
	auto formats = QImageReader::supportedImageFormats();

	return formats.contains(suffix);
}