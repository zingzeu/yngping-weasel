// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Globals.h"

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID pvReserved)
{
	OutputDebugString(_T("YP DllMain\n"));
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString(_T("DLL_PROCESS_ATTACH\n"));
		g_hInst = hInstance;
		if (!InitializeCriticalSectionAndSpinCount(&g_cs, 0)) {
			OutputDebugString(_T("DllMain Fail\n"));
			return FALSE;
		}
		break;

	case DLL_PROCESS_DETACH:
		OutputDebugString(_T("DLL_PROCESS_DETACH\n"));
		DeleteCriticalSection(&g_cs);
		break;
	}
	OutputDebugString(_T("DllMain OK\n"));
	return TRUE;
}

