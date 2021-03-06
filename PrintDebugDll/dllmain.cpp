//    This file is part of WindowsRuntimeDemos.
//    Copyright (C) James Forshaw 2018
//
//    WindowsRuntimeDemos is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    WindowsRuntimeDemos is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with WindowsRuntimeDemos.  If not, see <http://www.gnu.org/licenses/>.

#include "stdafx.h"

static HMODULE g_module = nullptr;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		g_module = hModule;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

DWORD CALLBACK EntryPoint(LPVOID p)
{
	OutputDebugStringW(static_cast<LPCWSTR>(p));
	FreeLibraryAndExitThread(g_module, 0);
}
