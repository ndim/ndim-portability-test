#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "npt-cmdline.h"
#include "npt-common.h"

int main(const int argc, const char *argv[])
{
  if (argc < 1) {
    fputs(PROGNAME ": error parsing command line (argc < 1)\n", stderr);
    exit(EXIT_FAILURE);
  } else {

    assert(argv[0]);
    const char *last_slash = strrchr(argv[0], '/');
    const char *prog = last_slash?(last_slash+1):argv[0];

    if (argc > 2) {
      fprintf(stderr, "%s: too many arguments (%d)\n", prog, argc);
      exit(EXIT_FAILURE);
    } else if (argc == 2) {
      if (0) {
      } else if (0 == strcmp("--help", argv[1])) {
	print_help();
	exit(EXIT_SUCCESS);
      } else if (0 == strcmp("--version", argv[1])) {
	print_version();
	exit(EXIT_SUCCESS);
      } else {
	fprintf(stderr, "%s: Unknown command line parameter: %s\n", prog, argv[1]);
      }
    } else {
      npt_common();
    }
  }
  return 0;
}
