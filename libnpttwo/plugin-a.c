#include <stdio.h>

#include "npttwo/plugin-api.h"

static
void a_func1(void)
{
  printf("plugin a func1\n");
}

static
int a_func2(int x)
{
  printf("plugin a func2\n");
  return x*x;
}

static
int a_func3(int x)
{
  printf("plugin a func3\n");
  return x*x*x;
}

npttwo_plugin plugin = {
  "Plugin A",
  a_func1,
  a_func2,
  a_func3
};
