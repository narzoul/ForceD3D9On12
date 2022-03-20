#include <Windows.h>
#include <d3dkmthk.h>
#include <strsafe.h>

#include "ForceD3D9On12.h"

namespace
{
	NTSTATUS APIENTRY queryAdapterInfo(const D3DKMT_QUERYADAPTERINFO* pData);

	PIMAGE_NT_HEADERS getImageNtHeaders(HMODULE module)
	{
		PIMAGE_DOS_HEADER dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(module);
		if (IMAGE_DOS_SIGNATURE != dosHeader->e_magic)
		{
			return nullptr;
		}

		PIMAGE_NT_HEADERS ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(
			reinterpret_cast<BYTE*>(dosHeader) + dosHeader->e_lfanew);
		if (IMAGE_NT_SIGNATURE != ntHeaders->Signature)
		{
			return nullptr;
		}

		return ntHeaders;
	}

	FARPROC* getProcAddressFromIat(HMODULE module, const char* procName)
	{
		PIMAGE_NT_HEADERS ntHeaders = getImageNtHeaders(module);
		if (!ntHeaders)
		{
			return nullptr;
		}

		char* moduleBase = reinterpret_cast<char*>(module);
		PIMAGE_IMPORT_DESCRIPTOR importDesc = reinterpret_cast<PIMAGE_IMPORT_DESCRIPTOR>(moduleBase +
			ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);

		for (PIMAGE_IMPORT_DESCRIPTOR desc = importDesc;
			0 != desc->Characteristics && 0xFFFF != desc->Name;
			++desc)
		{
			auto thunk = reinterpret_cast<PIMAGE_THUNK_DATA>(moduleBase + desc->FirstThunk);
			auto origThunk = reinterpret_cast<PIMAGE_THUNK_DATA>(moduleBase + desc->OriginalFirstThunk);
			while (0 != thunk->u1.AddressOfData && 0 != origThunk->u1.AddressOfData)
			{
				auto origImport = reinterpret_cast<PIMAGE_IMPORT_BY_NAME>(
					moduleBase + origThunk->u1.AddressOfData);

				if (0 == lstrcmp(origImport->Name, procName))
				{
					return reinterpret_cast<FARPROC*>(&thunk->u1.Function);
				}

				++thunk;
				++origThunk;
			}
		}

		return nullptr;
	}

	void hookIatFunction(HMODULE module, const char* funcName, void* newFunc)
	{
		FARPROC* func = getProcAddressFromIat(module, funcName);
		if (func)
		{
			DWORD oldProtect = 0;
			VirtualProtect(func, sizeof(func), PAGE_READWRITE, &oldProtect);
			*func = static_cast<FARPROC>(newFunc);
			DWORD dummy = 0;
			VirtualProtect(func, sizeof(func), oldProtect, &dummy);
		}
	}

	HMODULE hookOrigModule(const char* name)
	{
		char path[MAX_PATH];
		path[0] = 0;
		GetSystemDirectory(path, sizeof(path));
		StringCbCat(path, sizeof(path), "\\");
		StringCbCat(path, sizeof(path), name);
		HMODULE module = LoadLibrary(path);
		if (module)
		{
			hookIatFunction(module, "D3DKMTQueryAdapterInfo", queryAdapterInfo);
		}
		return module;
	}

	NTSTATUS APIENTRY queryAdapterInfo(const D3DKMT_QUERYADAPTERINFO* pData)
	{
		if (pData && KMTQAITYPE_UMDRIVERNAME == pData->Type &&
			KMTUMDVERSION_DX9 == static_cast<D3DKMT_UMDFILENAMEINFO*>(pData->pPrivateDriverData)->Version)
		{
			return STATUS_INVALID_PARAMETER;
		}
		return D3DKMTQueryAdapterInfo(pData);
	}
}

FARPROC getOrigFunc(const char* name)
{
	static HMODULE origModule = hookOrigModule(g_moduleName);
	return GetProcAddress(origModule, name);
}

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD /*ul_reason_for_call*/, LPVOID /*lpReserved*/)
{
	return TRUE;
}
