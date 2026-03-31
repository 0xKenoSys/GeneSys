#include <stdio.h>
#include <windows.h>

#ifndef _DEBUG_INFO_HEADER_

#define _DEBUG_INFO_HEADER_
#if (defined UNICODE) || (defined _UNICODE)
#define DebugInfo DebugInfoW
#else
#define DebugInfo DebugInfoA
#endif

void DebugInfoA(char* str, ...) {
    char szBuffer[500];
    va_list Argv;
    va_start(Argv, str);
    _vsnprintf_s(szBuffer, 500, str, Argv);
    va_end(Argv);
    OutputdebugStringA(szbuffer);
}

void DebugInfoW(wchar_t* str, ...) {
    wchar_t szBuffer[1000];
    va_list Argv;
    va_start (Argv, str);
    _vsnwprintf_s(szBuffer, 500, str, Argv);
    va_end(Argv);
    OutputDebugStringW(szBuffer);
}
#endif

//
// Created by Madeleine on 2026/2/3.
//