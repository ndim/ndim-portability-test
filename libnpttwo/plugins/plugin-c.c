#include <stdio.h>

#include "npttwo/npttwo.h"
#include "npttwo/plugin-api.h"

static
void c_func1(const char *const prefix)
{
  printf("%s   plugin c func1\n", prefix);
}

static
int c_func2(const char *const prefix, int x)
{
  printf("%s   plugin c func2\n", prefix);
  return x*x;
}

static
int c_func3(const char *const prefix, int x)
{
  printf("%s   plugin c func3\n", prefix);
  const int y = npttwo_call_from_plugin(x);
  return y*y*y;
}

npttwo_plugin plugin = {
  "Plugin C",
  c_func1,
  c_func2,
  c_func3
};
