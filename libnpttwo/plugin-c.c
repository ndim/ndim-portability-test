#include <stdio.h>

#include "npttwo/plugin-api.h"

static
void c_func1(void)
{
  printf("plugin c func1\n");
}

static
int c_func2(int x)
{
  printf("plugin c func2\n");
  return x*x;
}

npttwo_plugin plugin = {
  "Plugin C",
  c_func1,
  c_func2
};
