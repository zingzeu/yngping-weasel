#include <windows.h>

#include "ui/WeaselUI.h"
#include "ui/WeaselCommon.h"

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{   
   //weasel
   weasel::UI _ui;
   bool result = _ui.Create(0);
  printf("Create result: %d\n", result);

  _ui.UpdateInputPosition({50, 1140, 100, 1190});
  weasel::Context cc = weasel::Context();
  cc.preedit = weasel::Text(L"SomeText");
  _ui.Update(cc, weasel::Status());
  _ui.Show();
  printf("Is shown: %d\n", _ui.IsShown());
  int x;
  scanf("%d",&x);
  return 0;
}