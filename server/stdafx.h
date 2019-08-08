// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once
// Change these values to use different versions
#define WINVER		0x0601	// Windows 7
#define _WIN32_WINNT	0x0601	// Windows 7
#define _WIN32_IE	0x0800	// Windows 7
#define _RICHEDIT_VER	0x0200	// IE 8 (Comes with Windows 7)

// This project was generated for VC++ 2005 Express and ATL 3.0 from Platform SDK.
// Comment out this line to build the project with different versions of VC++ and ATL.
//#define _WTL_SUPPORT_SDK_ATL3

// Support for VS2005 Express & SDK ATL
#ifdef _WTL_SUPPORT_SDK_ATL3
  #define _CRT_SECURE_NO_DEPRECATE
  #pragma conform(forScope, off)
  #pragma comment(linker, "/NODEFAULTLIB:atlthunk.lib")
#endif // _WTL_SUPPORT_SDK_ATL3

#include <atlbase.h>
#include <atlwin.h>

// Support for VS2005 Express & SDK ATL
#ifdef _WTL_SUPPORT_SDK_ATL3
  namespace ATL
  {
	inline void * __stdcall __AllocStdCallThunk()
	{
		return ::HeapAlloc(::GetProcessHeap(), 0, sizeof(_stdcallthunk));
	}

	inline void __stdcall __FreeStdCallThunk(void *p)
	{
		::HeapFree(::GetProcessHeap(), 0, p);
	}
  };
#endif // _WTL_SUPPORT_SDK_ATL3

#include "third_party/wtl/atlapp.h"
#include "third_party/wtl/atlframe.h"
#include "third_party/wtl/atlctrls.h"
#include "third_party/wtl/atldlgs.h"

#include <VersionHelpers.h>

typedef HRESULT (WINAPI *PRAR)(PCWSTR, DWORD);

extern CAppModule _Module;

#include <cstdio>
#include <iostream>