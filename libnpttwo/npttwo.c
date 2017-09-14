#include "npttwo/npttwo.h"
#include "npttwo/plugin-api.h"

#include <ltdl.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


#define REALLOC_INCREMENT 50


static npttwo_plugin **plugins;
static size_t mem_idx;
static size_t used_idx;


static
void npttwo_init(void)
  __attribute__((constructor))
  __attribute__((used))
  ;


static
void npttwo_done(void)
  __attribute__((destructor))
  __attribute__((used))
  ;


void npttwo_fun(void)
{
  printf("npttwo_fun\n");
  assert(plugins);
}


static int
foreach_func(const char *filename, lt_ptr data __attribute__((unused)))
{
  printf("  * npttwo foreach_func %s\n", filename);

  lt_dlhandle lh = lt_dlopenext(filename);
  if (!lh) {
    printf("      * cannot load %s: %s\n", filename, lt_dlerror());
    return 1;
  }

  npttwo_plugin *plugin = lt_dlsym(lh, "plugin");
  if (!plugin) {
    printf("      * no 'plugin' symbol found: %s\n", lt_dlerror());
    lt_dlclose(lh);
    return 1;
  }

  printf("      * found plugin '%s'\n", plugin->name);

  if (mem_idx <= used_idx) {
    size_t new_mem_idx = mem_idx + REALLOC_INCREMENT;
    printf("      * realloc from %d to %d plugins\n", mem_idx, new_mem_idx);
    npttwo_plugin **new_plugins = realloc(plugins, new_mem_idx * sizeof(npttwo_plugin *));
    assert(new_plugins);
    plugins = new_plugins;
    mem_idx = new_mem_idx;
  }

  assert(mem_idx > used_idx);
  plugins[used_idx] = plugin;
  used_idx++;

  return 0;
}


static
void npttwo_init(void)
{
  printf("npttwo_init\n");
  const char *const tmp_dir = getenv("NPTTWO_PLUGINS");
  const char *const plugindir = tmp_dir?tmp_dir:NPTTWO_PLUGINDIR;
  printf("npttwo_init: plugindir = %s\n", plugindir);
  assert(0 == lt_dlinit());
  lt_dladdsearchdir(plugindir);

  printf("Scanning plugin directory:\n");
  assert(0 == lt_dlforeachfile(plugindir, foreach_func, NULL));

  printf("Plugin list:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("  %d. %s\n", i+1, plugins[i]->name);
  }
}


static
void npttwo_done(void)
{
  if (plugins) {
    printf("Freeing plugins");
    free(plugins);
    plugins = NULL;
    mem_idx = 0;
    used_idx = 0;
  }
}


void npttwo_func1(void)
{
  printf("Plugin list:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%d. %s\n", i+1, plugins[i]->name);
    plugins[i]->func1();
  }
}


void npttwo_func2(void)
{
  printf("Plugin list:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%d. %s\n", i+1, plugins[i]->name);
    const int v = 5;
    const int ret = plugins[i]->func2(v);
    printf("    %d = func2(%d)\n", ret, v);
  }
}


void npttwo_func3(void)
{
  printf("Plugin list:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%d. %s\n", i+1, plugins[i]->name);
    const int v = 2;
    const int ret = plugins[i]->func3(npttwo_call_from_plugin(v));
    printf("    %d = func3(%d)\n", ret, v);
  }
}


int npttwo_call_from_plugin(int value)
{
  return (value+1);
}
