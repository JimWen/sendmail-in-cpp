/************************************************************************/
/* wenzhou @ 2017.3.26                                                  */
/************************************************************************/

#include "CodingHelper.h"

CCodingHelper::CCodingHelper(void)
{
}

CCodingHelper::~CCodingHelper(void)
{
}

//Unicodeת��Ansi
char* CCodingHelper::Unicode2Ansi( LPCWSTR lpUnicode )
{
	char* lpsz = NULL;

	int iLen = 0;

	iLen = WideCharToMultiByte( CP_ACP, 0, lpUnicode, wcslen( lpUnicode ), NULL, 0, NULL, NULL );

	if( 0 != iLen )
	{
		iLen++;
		lpsz = new char[ iLen ];

		if( NULL != lpsz )
		{
			ZeroMemory( lpsz, sizeof( char ) * iLen );
			WideCharToMultiByte( CP_ACP, 0, lpUnicode, wcslen( lpUnicode ), lpsz, iLen, NULL, NULL );
		}
	}

	return lpsz;
}

//AnsiתUnicode
wchar_t* CCodingHelper::Ansi2Unicode( char * lpAnsi )
{
	wchar_t* lpsz = NULL;

	int iLen = 0;

	iLen = MultiByteToWideChar( CP_ACP, 0, lpAnsi, strlen( lpAnsi ), NULL, 0 );

	if( 0 != iLen )
	{
		iLen++;
		lpsz = new wchar_t[ iLen ];

		if( NULL != lpsz )
		{
			ZeroMemory( lpsz, sizeof( wchar_t ) * iLen );
			MultiByteToWideChar( CP_ACP, 0, lpAnsi, strlen( lpAnsi ), lpsz, iLen );
		}
	}

	return lpsz;
}

//UnicodeתUtf8
char* CCodingHelper::Unicode2Utf8( LPCWSTR lpUtf8 )
{
	char* lpsz = NULL;

	int iLen = 0;

	iLen = WideCharToMultiByte( CP_UTF8, 0, lpUtf8, wcslen( lpUtf8 ), NULL, 0, NULL, NULL );

	if( 0 != iLen )
	{
		iLen++;
		lpsz = new char[ iLen ];

		if( NULL != lpsz )
		{
			ZeroMemory( lpsz, sizeof( char ) * iLen );
			WideCharToMultiByte( CP_UTF8, 0, lpUtf8, wcslen( lpUtf8 ), lpsz, iLen, NULL, NULL );
		}
	}

	return lpsz;
}

//Utf8תUnicode
wchar_t* CCodingHelper::Utf8ToUnicode( char * lpUtf8 )
{
	wchar_t* lpsz = NULL;

	int iLen = 0;

	iLen = MultiByteToWideChar( CP_UTF8, 0, lpUtf8, strlen( lpUtf8 ), NULL, 0 );

	if( 0 != iLen )
	{
		iLen++;
		lpsz = new wchar_t[ iLen ];

		if( NULL != lpsz )
		{
			ZeroMemory( lpsz, sizeof( wchar_t ) * iLen );
			MultiByteToWideChar( CP_UTF8, 0, lpUtf8, strlen( lpUtf8 ), lpsz, iLen );
		}
	}

	return lpsz;
}

//Utf8תUnicode��֧��ָ���ֽڳ���ת��
wchar_t* CCodingHelper::Utf8ToUnicode( char * lpUtf8, DWORD dwLen )
{
	wchar_t* lpsz = NULL;

	int iLen = 0;

	iLen = MultiByteToWideChar( CP_UTF8, 0, lpUtf8, dwLen, NULL, 0 );

	if( 0 != iLen )
	{
		iLen++;
		lpsz = new wchar_t[ iLen ];

		if( NULL != lpsz )
		{
			ZeroMemory( lpsz, sizeof( wchar_t ) * iLen );
			MultiByteToWideChar( CP_UTF8, 0, lpUtf8, dwLen, lpsz, iLen );
		}
	}

	return lpsz;
}
