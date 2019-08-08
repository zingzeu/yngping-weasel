// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

//#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define max(a, b)  (((a) > (b)) ? (a) : (b)) 
#include <atlbase.h>
#include <atlwin.h>
#include <windows.h>

#include "third_party/wtl/atlapp.h"
#include "third_party/wtl/atlframe.h"
#include "third_party/wtl/atlgdi.h"
#include "third_party/wtl/atlmisc.h"

#include <string>
#include <vector>

//#include <logging.h>
