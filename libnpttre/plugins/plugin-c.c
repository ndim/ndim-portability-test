#include <stdio.h>

#include "npttre/npttre.h"
#include "npttre/plugin-api.h"

static
void c_func1(const char *const prefix)
{
  printf("%s   tre plugin c func1\n", prefix);
}

static
int c_func2(const char *const prefix, int x)
{
  printf("%s   tre plugin c func2\n", prefix);
  return x*x;
}

static
int c_func3(const char *const prefix, int x)
{
  printf("%s   tre plugin c func3\n", prefix);
  const int y = npttre_call_from_plugin(x);
  return y*y*y;
}

npttre_plugin plugin = {
  "Plugin C tre",
  c_func1,
  c_func2,
  c_func3
};
