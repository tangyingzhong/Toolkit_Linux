#include <locale>
#include <codecvt>
#include "Encode.h"

using namespace System::Encoding::UTF8;
using namespace System::Encoding::ANSI;

// Get UTF-8 string
std::string System::Encoding::UTF8::GetString(const std::wstring& strData)
{
	if (strData.empty())
	{
		return "";
	}

	std::wstring_convert<std::codecvt_utf8<wchar_t> > strConvert(std::string(""), std::wstring(L""));

	return strConvert.to_bytes(strData);
}

// Get wide string from UTF-8
std::wstring System::Encoding::UTF8::GetWString(const std::string& strData)
{
	if (strData.empty())
	{
		return L"";
	}

	std::wstring_convert<std::codecvt_utf8<wchar_t> > strConvert(std::string(""),std::wstring(L""));

	return strConvert.from_bytes(strData);
}

// Get Ansi string
std::string System::Encoding::ANSI::GetString(const std::wstring& strData, const std::string strLocal)
{
	if (strData.empty())
	{
		return "";
	}

	using F = std::codecvt_byname<wchar_t, char, std::mbstate_t>;

	std::wstring_convert<F> strConvert(new F(strLocal));

	return strConvert.to_bytes(strData);
}

// Get wide string from Ansi
std::wstring System::Encoding::ANSI::GetWString(const std::string& strData, const std::string strLocal)
{
	if (strData.empty())
	{
		return L"";
	}

	using F = std::codecvt_byname<wchar_t, char, std::mbstate_t>;

	std::wstring_convert<F> strConvert(new F(strLocal));

	return strConvert.from_bytes(strData);
}
