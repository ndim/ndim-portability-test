#include <windows.h>

#include <stdio.h>

#include "auto-config.h"

#include "npt-cmdline.h"
#include "npt-common.h"

int WINAPI WinMain(HINSTANCE hInstance,
		   HINSTANCE hPrevInstance,
		   LPTSTR    lpCmdLine,
		   int       cmdShow)
{
  int argCount;
  LPCWSTR lpwCmdLine = GetCommandLineW();
  LPWSTR *szArgList = CommandLineToArgvW(lpwCmdLine, &argCount);
  if (szArgList == NULL) {
    MessageBox(NULL,
	       TEXT(PROGNAME ": Unable to parse command line"),
	       TEXT("Error"), MB_OK);
    return 10;
  }

  FILE *logfile = fopen(PROGNAME ".log", "w");

  fprintf(logfile, PROGNAME ": %d\n", argCount);

  for (int i=1; i<argCount; ++i) {
    wprintf(L"ARG %d: '%s'\n", i, szArgList[i]);
    fwprintf(logfile, L"ARG %d: '%s'\n", i, szArgList[i]);
    if (0) {
      /* do nothing */
    } else if (0 == wcscmp(L"--help", szArgList[i])) {
      fprintf(logfile, "HELP\n");
      print_help();
      return 0;
    } else if (0 == wcscmp(L"--version", szArgList[i])) {
      fprintf(logfile, PROGNAME " (" PACKAGE_TARNAME ") " PACKAGE_VERSION "\n");
      print_version();
      return 0;
    } else {
      MessageBox(NULL,
		 TEXT(PROGNAME ": Unhandled command line parameter"),
		 TEXT("Error"), MB_OK);
      return 11;
    }
  }

  npt_common();

  LocalFree(szArgList);
  return 0;
}
