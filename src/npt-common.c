#include <stdio.h>

#include <nptone/nptone.h>
#include <npttwo/npttwo.h>

void npt_common(void)
{
  printf("%s:%d: %s %s\n", __FILE__, __LINE__, "npt_common", PROGNAME);
  nptone_fun();

  npttwo_func1();
  npttwo_func2();
  npttwo_func3();
}
