#include <stdio.h>

#include "auto-config.h"

#include "npt-cmdline.h"

void print_version(void)
{
  fprintf(stdout,
	  "%s (%s) %s\n"
	  "Copyright (C) 2017 TBD\n",
	  PROGNAME,
	  PACKAGE_TARNAME, PACKAGE_VERSION);
}

void print_help(void)
{
  fprintf(stdout, "HELP\n");
}
