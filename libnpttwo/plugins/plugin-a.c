#include <stdio.h>

#include "npttwo/npttwo.h"
#include "npttwo/plugin-api.h"

static
void a_func1(const char *const prefix)
{
  printf("%s   plugin a func1\n", prefix);
}

static
int a_func2(const char *const prefix, int x)
{
  printf("%s   plugin a func2\n", prefix);
  return x*x;
}

static
int a_func3(const char *const prefix, int x)
{
  printf("%s   plugin a func3\n", prefix);
  const int y = npttwo_call_from_plugin(x);
  return y*y*y;
}

npttwo_plugin plugin = {
  "Plugin A",
  a_func1,
  a_func2,
  a_func3
};
