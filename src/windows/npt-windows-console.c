#include <stdio.h>
#include <string.h>

#include "auto-config.h"

#include "npt-cmdline.h"
#include "npt-common.h"


int main(int argc, char *argv[])
{
  for (int i=1; i<argc; ++i) {
    printf("ARG %d: '%s'\n", i, argv[i]);
    if (0) {
      /* do nothing */
    } else if (0 == strcmp("--help", argv[i])) {
      print_help();
      return 0;
    } else if (0 == strcmp("--version", argv[i])) {
      print_version();
      return 0;
    } else {
      fprintf(stderr, "%s: Unhandled command line parameter\n", PROGNAME);
      return 11;
    }
  }

  npt_common();

  return 0;
}
