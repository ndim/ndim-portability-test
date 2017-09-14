#include <stdio.h>

#include "npttwo/plugin-api.h"

static
void b_func1(void)
{
  printf("plugin b func1\n");
}

static
int b_func2(int x)
{
  printf("plugin b func2\n");
  return x*x;
}

npttwo_plugin plugin = {
  "Plugin B",
  b_func1,
  b_func2
};
