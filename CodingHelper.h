#pragma once

#include <Windows.h>

class CCodingHelper
{
public:
	CCodingHelper(void);
	virtual ~CCodingHelper(void);

	static char* Unicode2Ansi( LPCWSTR lpUnicode );
	static wchar_t* Ansi2Unicode( char * lpAnsi );
	static char* Unicode2Utf8( LPCWSTR lpUtf8 );
	static wchar_t* Utf8ToUnicode( char * lpUtf8 );
	static wchar_t* Utf8ToUnicode( char * lpUtf8, DWORD dwLen );
};
