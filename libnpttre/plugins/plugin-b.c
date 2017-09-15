#include <stdio.h>

#include "npttre/npttre.h"
#include "npttre/plugin-api.h"

static
void b_func1(const char *const prefix)
{
  printf("%s   tre plugin b func1\n", prefix);
}

static
int b_func2(const char *const prefix, int x)
{
  printf("%s   tre plugin b func2\n", prefix);
  return x*x;
}

static
int b_func3(const char *const prefix, int x)
{
  printf("%s   tre plugin b func3\n", prefix);
  const int y = npttre_call_from_plugin(x);
  return y*y*y;
}

npttre_plugin plugin = {
  "Plugin B tre",
  b_func1,
  b_func2,
  b_func3
};
