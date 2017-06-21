#include <stdio.h>

#include <wintest/wintest.h>

void wintest_bin(void)
{
  printf("%s:%d: %s %s\n", __FILE__, __LINE__, __FUNCTION__, PROGNAME);
  wintest_one();
}
