#include <windows.h>

#include "ui/WeaselUI.h"
#include "common/WeaselCommon.h"
#include "include/WeaselUtility.h"

#include <string>
#include <iostream>
using namespace std;

#define WIN32_LEAN_AND_MEAN
#define _WTL_USE_CSTRING

#include "atlbase.h"               // base ATL classes
#include "third_party/wtl/atlapp.h"   // base WTL classes
extern CAppModule _Module;         // WTL version of CComModule
#include "atlwin.h"                // ATL GUI classes
#include "third_party/wtl/atlframe.h" // WTL frame window classes
#include "third_party/wtl/atlmisc.h"  // WTL utility classes like CString
#include "third_party/wtl/atlcrack.h" // WTL enhanced msg map macros

//#include <boost/serialization/vector.hpp>
#include <boost/thread.hpp>

class CMyWindow : public CFrameWindowImpl<CMyWindow>
{
public:
  DECLARE_FRAME_WND_CLASS(_T("First WTL window"), -1);

  BEGIN_MSG_MAP(CMyWindow)
  CHAIN_MSG_MAP(CFrameWindowImpl<CMyWindow>)
  END_MSG_MAP()
};

CAppModule _Module;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine, int nCmdShow)
{
  AttachConsole(ATTACH_PARENT_PROCESS);
  _Module.Init(NULL, hInstance);

  CMyWindow wndMain;
  MSG msg;

  // Create the main window
  HWND ss = wndMain.CreateEx();
  if (NULL == ss)
    return 1; // Window creation failed

  // Show the window
  wndMain.ShowWindow(nCmdShow);
  wndMain.UpdateWindow();

  //weasel
  weasel::UI _ui;
  _ui.style().text_color = 0x00ff00ff;
  _ui.style().back_color = 0x00223345;
  bool result = _ui.Create(ss);
  printf("Create result: %d\n", result);

  _ui.UpdateInputPosition({50, 50, 100, 100});
  weasel::Context cc = weasel::Context();
  cc.preedit = weasel::Text(utf8towcs("SomeText尼玛"));
  _ui.Update(cc, weasel::Status());
  _ui.Show();
  printf("Is shown: %d\n", _ui.IsShown());

  // Standard Win32 message loop
  while (GetMessage(&msg, NULL, 0, 0) > 0)
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  _Module.Term();
  return msg.wParam;
}
