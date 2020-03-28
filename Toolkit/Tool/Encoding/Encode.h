///************************************************************************
/// <copyrigth>2018-2019 Corporation.All Rights Reserved</copyrigth>
/// <author>tangyingzhong</author>
/// <contact>tangyz114987@outlook.com</contact>
/// <version>v1.0.0</version>
/// <describe>
/// You must confirm that what encoding page you are in.
///</describe>
/// <date>2020/3/28</date>
///***********************************************************************
#ifndef ENCODE_H
#define ENCODE_H

#include <string>

namespace System
{
	namespace Encoding
	{
		// Current local lang is UTF-8
		namespace UTF8
		{
			// Get UTF-8 string
			std::string GetString(const std::wstring& strData);

			// Get wide string from UTF-8
			std::wstring GetWString(const std::string& strData);
		}

		// Current local lang is not UTF-8
		namespace ANSI
		{
			// Get Ansi string
			std::string GetString(const std::wstring& strData, const std::string strLocal="");

			// Get wide string from Ansi
			std::wstring GetWString(const std::string& strData, const std::string strLocal="");
		}
	}
}
#endif // ENCODE_H
