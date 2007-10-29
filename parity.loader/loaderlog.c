/****************************************************************\
*                                                                *
* Copyright (C) 2007 by Markus Duft <markus.duft@salomon.at>     *
*                                                                *
* This file is part of parity.                                   *
*                                                                *
* parity is free software: you can redistribute it and/or modify *
* it under the terms of the GNU Lesser General Public License as *
* published by the Free Software Foundation, either version 3 of *
* the License, or (at your option) any later version.            *
*                                                                *
* parity is distributed in the hope that it will be useful,      *
* but WITHOUT ANY WARRANTY; without even the implied warranty of *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *
* GNU Lesser General Public License for more details.            *
*                                                                *
* You should have received a copy of the GNU Lesser General      *
* Public License along with parity. If not,                      *
* see <http://www.gnu.org/licenses/>.                            *
*                                                                *
\****************************************************************/

#include "LoaderLog.h"
#include "LoaderInit.h"
#include "LoaderHelper.h"

#include <stdarg.h>
#include <windows.h>

static LoaderLogLevel gLevel;
static HANDLE gDebugStream;

static void formattedOutput(HANDLE file, const char* fmt, va_list args)
{
	//
	// TODO: implement using WriteFile
	//
	static isNewLine = 1;
	const char* ptr = fmt;
	const char* end = ptr;

	unsigned int iBytesWritten = 0;

	if(isNewLine)
	{
		WriteFile(file, ParityLoaderGeneratedImageName, lstrlen(ParityLoaderGeneratedImageName), &iBytesWritten, 0);
		WriteFile(file, ": ", 2, &iBytesWritten, 0);
	}

	while(end && *end != '\0')
	{
		while(*end != '%' && *end != '\0')
			++end;

		WriteFile(file, ptr, end - ptr, &iBytesWritten, 0);
		ptr = end+2;

		if(*end == '%')
		{
			int radix = 10;

			++end;

			switch(*end)
			{
			case 'p':
			case 'x':
				radix = 16;
				// fall through
			case 'd':
				{
					char buffer[64];
					unsigned char* wh = buffer + 63;

					int num = va_arg(args, int);

					*wh = '\0';

					do
					{
						unsigned long temp;

						temp = (unsigned long)num % radix;
						wh--;
						if(temp < 10)
							*wh = (unsigned char)temp + '0';
						else
							*wh = (unsigned char)temp - 10 + 'a';
						num = (unsigned long)num / radix;
					}
					while(num != 0);

					WriteFile(file, wh, lstrlen(wh), &iBytesWritten, 0);
				}
				break;
			case 's':
				{
					const char* tmp = va_arg(args, const char*);
					WriteFile(file, tmp, lstrlen(tmp), &iBytesWritten, 0);
				}
				break;
			default:
				{
					const char msgErrUnsupported[] = "<unsupported specifier>";
					WriteFile(file, msgErrUnsupported, sizeof(msgErrUnsupported), &iBytesWritten, 0);
				}
			}
		}

		if(*end != '\0')
			++end;
	}

	end--;
	if(*end == '\n')
		isNewLine = 1;
	else
		isNewLine = 0;
}

//
// WARNING: va_args may come from CRT, but most of the time
// those are just defines, so not so dangerous.
//

void LogInit()
{
	static int isInited = 0;
	unsigned int szOut = 0;
	gDebugStream = GetStdHandle(STD_OUTPUT_HANDLE);

	if(isInited)
		return;

	isInited = 1;

	if(GetEnvironmentVariable("LD_DEBUG", 0, 0))
		gLevel = LevelDebug;
	else
		gLevel = LevelWarning;

	//
	// TODO: handle LD_DEBUG_OUTPUT
	//
	if((szOut = GetEnvironmentVariable("LD_DEBUG_OUTPUT", 0, 0)) != 0)
	{
		char * ptrOut = HeapAlloc(GetProcessHeap(), 0, szOut);

		if(GetEnvironmentVariable("LD_DEBUG_OUTPUT", ptrOut, szOut) == 0)
		{
			LogWarning("cannot read LD_DEBUG_OUTPUT variable!\n");
		} else {
			HANDLE handle = CreateFile(ptrOut, FILE_WRITE_ACCESS, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
			
			if(handle == INVALID_HANDLE_VALUE) {
				LogWarning("cannot open debug output file %s!\n", ptrOut);
				LoaderWriteLastWindowsError();
			} else {
				gDebugStream = handle;
			}
		}
	}
}

void LogWarning(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	formattedOutput(GetStdHandle(STD_ERROR_HANDLE), fmt, args);

	va_end(args);
}

void LogDebug(const char* fmt, ...)
{
	if(gLevel == LevelDebug)
	{
		va_list args;
		va_start(args, fmt);

		//
		// first seek to end of file.
		//
		SetFilePointer(gDebugStream, 0, 0, FILE_END);

		formattedOutput(gDebugStream, fmt, args);

		//
		// flush immediatly
		//
		FlushFileBuffers(gDebugStream);

		va_end(args);
	}
}

void LogSetLevel(LoaderLogLevel lvl)
{
	gLevel = lvl;
}

void LogSetDebugStream(HANDLE stream)
{
	gDebugStream = stream;
}
