#include <stdio.h>

#include <npttwo/npttwo.h>
#include <npttre/npttre.h>
#include <npttre/plugin-api.h>

static
void a_func1(const char *const prefix)
{
  printf("%s   tre plugin a func1\n", prefix);
  npttwo_func1("    " "    ");
}

static
int a_func2(const char *const prefix, int x)
{
  printf("%s   tre plugin a func2\n", prefix);
  npttwo_func2("    " "    ");
  return x*x;
}

static
int a_func3(const char *const prefix, int x)
{
  printf("%s   tre plugin a func3\n", prefix);
  npttwo_func3("    " "    ");
  const int y = npttre_call_from_plugin(x);
  return y*y*y;
}

npttre_plugin plugin = {
  "Plugin A tre",
  a_func1,
  a_func2,
  a_func3
};
