#pragma once

#include<qstring.h>

namespace data
{
	namespace guard
	{
		uint isValid_UserName(QString&& username);
		uint isValid_UserName(QString& username);

		bool isValid_email(QString&& email);
		bool isValid_email(QString& email);

		uint isValid_password(QString&& password);
		uint isValid_password(QString& password);

		bool isValid_readImageFormat(QString& suffix);
		bool isValid_readImageFormat(QString&& suffix);
	}
}