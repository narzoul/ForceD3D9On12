#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

extern const char* const g_moduleName;

FARPROC getOrigFunc(const char* name);

#define CREATE_WRAPPER_FUNC(name) \
    namespace { static FARPROC g_orig##name = getOrigFunc(#name); } \
    extern "C" __declspec(dllexport) void name() \
	{ \
        g_orig##name(); \
	}
