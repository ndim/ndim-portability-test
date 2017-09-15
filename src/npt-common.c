#include <stdio.h>

#include <nptone/nptone.h>
#include <npttwo/npttwo.h>

void npt_common(void)
{
  printf("\n");
  printf("%s:%d: %s %s\n", __FILE__, __LINE__, "npt_common", PROGNAME);

  printf("\n");
  nptone_fun();

  printf("\n");
  npttwo_func1("    ");

  printf("\n");
  npttwo_func2("    ");

  printf("\n");
  npttwo_func3("    ");
}
