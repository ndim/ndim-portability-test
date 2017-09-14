#include "compiler-compatibility.h"

#include <windows.h>

#include <stdio.h>


LPWSTR type2str(DWORD BinaryType)
{
  switch (BinaryType) {
  case SCS_DOS_BINARY:   return L"DOS";
  case SCS_PIF_BINARY:   return L"POF";
  case SCS_64BIT_BINARY: return L"64BIT";
  case SCS_32BIT_BINARY: return L"32BIT";
  case SCS_WOW_BINARY:   return L"WOW";
  case SCS_OS216_BINARY: return L"OS216";
  }
  return L"???";
}


int WINAPI wWinMain(HINSTANCE UP(hInstance),
		    HINSTANCE UP(hPrevInstance),
		    LPWSTR    UP(lpCmdLine),
		    int       UP(cmdShow))
{
  int argc;
  LPCWSTR lpwCmdLine = GetCommandLineW();
  LPWSTR *argvW = CommandLineToArgvW(lpwCmdLine, &argc);

  wprintf(L"%s: BEGIN\n", PROGNAMEW);
  wprintf(L"bool  type  type   filename\n");
  for (int i=0; i<argc; ++i) {
    const LPCWSTR lpApplicationName = argvW[i];
    DWORD BinaryType = -1;
    const BOOL exetype = GetBinaryTypeW(lpApplicationName, &BinaryType);
    const LPWSTR typestr = type2str(BinaryType);
    wprintf(L"%-5s  % -4d %-6s %s\n", exetype?L"true":L"false",
	    BinaryType, typestr, lpApplicationName);
  }
  wprintf(L"%s: END\n", PROGNAMEW);

  return 0;
}
