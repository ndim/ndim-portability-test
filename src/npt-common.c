#include <stdio.h>

#include <nptone/nptone.h>

void npt_common(void)
{
  printf("%s:%d: %s %s\n", __FILE__, __LINE__, __FUNCTION__, PROGNAME);
  nptone_fun();

  npttwo_func1();
  npttwo_func2();
}
