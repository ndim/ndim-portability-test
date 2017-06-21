#include <stdio.h>

#include "config.h"

void print_version(void)
{
  fprintf(stdout,
	  "wintest (%s) %s\n"
	  "Copyright (C) 2017 TBD\n",
	  PACKAGE, VERSION);
}

void print_help(void)
{
  fprintf(stdout, "HELP\n");
}
