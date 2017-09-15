#include <stdio.h>

#include "npttwo/npttwo.h"
#include "npttwo/plugin-api.h"

static
void b_func1(const char *const prefix)
{
  printf("%s   two plugin b func1\n", prefix);
}

static
int b_func2(const char *const prefix, int x)
{
  printf("%s   two plugin b func2\n", prefix);
  return x*x;
}

static
int b_func3(const char *const prefix, int x)
{
  printf("%s   two plugin b func3\n", prefix);
  const int y = npttwo_call_from_plugin(x);
  return y*y*y;
}

npttwo_plugin plugin = {
  "Plugin B two",
  b_func1,
  b_func2,
  b_func3
};
