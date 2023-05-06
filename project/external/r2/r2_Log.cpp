#include "r2_Log.h"

#include <stdio.h>
#include <stdarg.h>

namespace r2
{
	Log::Log() : mActivate( true )
	{}

#if R2LOG_OUTPUT_TARGET == R2LOG_OUTPUT_TARGET_TYPE___TERMINAL

	void Log::Print( const char* format_string, ... )
	{
		if( !mActivate )
		{
			return;
		}

		static char buf[256] = { 0 };
		va_list argList;

		va_start( argList, format_string );
		vsnprintf( buf, 256, format_string, argList );
		va_end( argList );

		printf( "%s", buf );
	}

#elif R2LOG_OUTPUT_TARGET == R2LOG_OUTPUT_TARGET_TYPE___VS_OUTPUT_WINDOW

#include <Windows.h>

	void Log::Print( const char* format_string, ... )
	{
		if( !mActivate )
		{
			return;
		}

		static char buf[256] = { 0 };
		va_list argList;

		va_start( argList, format_string );
		vsnprintf( buf, 256, format_string, argList );
		va_end( argList );

		OutputDebugStringA( buf );
	}

#endif
}