#include <stdio.h>

#include "npttwo/npttwo.h"
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

static
int c_func3(int x)
{
  printf("plugin c func3\n");
  const int y = npttwo_call_from_plugin(x);
  return y*y*y;
}

npttwo_plugin plugin = {
  "Plugin C",
  c_func1,
  c_func2,
  c_func3
};
