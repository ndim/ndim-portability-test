#include "npttwo/npttwo.h"
#include "npttwo/plugin-api.h"

#include <ltdl.h>

#include <assert.h>
#include <inttypes.h>
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


void LIBNPTTWO0_DLL npttwo_fun(void)
{
  printf("npttwo_fun\n");
  assert(plugins);
}


static int
foreach_func(const char *filename, lt_ptr data __attribute__((unused)))
{
  printf("  * npttwo foreach_func %s\n", filename);

  lt_dlhandle lh = lt_dlopen(filename);
  if (lh == 0) {
    lh = lt_dlopenext(filename);
  }
  if (!lh) {
    printf("      * cannot load %s: %s\n", filename, lt_dlerror());
    return 0;
  }

  const lt_dlinfo *info = lt_dlgetinfo(lh);
  if (info) {
    printf("      * lt_dlinfo:\n");
    printf("          * filename:     %s\n", info->filename);
    printf("          * name:         %s\n", info->name);
    printf("          * ref_count:    %d\n", info->ref_count);
    printf("          * is_resident:  %d\n", info->is_resident);
    printf("          * is_symglobal: %d\n", info->is_symglobal);
    printf("          * is_symlocal:  %d\n", info->is_symlocal);
  }

  npttwo_plugin *plugin = lt_dlsym(lh, "plugin");
  if (!plugin) {
    printf("      * no 'plugin' symbol found: %s\n", lt_dlerror());
    lt_dlclose(lh);
    return 1;
  }

  printf("      * found plugin '%s'\n", plugin->name);

  if (mem_idx <= used_idx) {
    const size_t new_mem_idx = mem_idx + REALLOC_INCREMENT;
    printf("      * realloc from %zu to %zu plugins\n",
	   mem_idx, new_mem_idx);
    npttwo_plugin **new_plugins =
      realloc(plugins, new_mem_idx * sizeof(npttwo_plugin *));
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
  assert(0 == lt_dladdsearchdir(plugindir));

  printf("Scanning plugin directory two:\n");
  assert(0 == lt_dlforeachfile(plugindir, foreach_func, NULL));

  printf("Plugin list two:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("  %zu. %s\n", i+1, plugins[i]->name);
  }

  assert(used_idx > 0);
}


static
void npttwo_done(void)
{
  if (plugins) {
    printf("Freeing plugins two");
    free(plugins);
    plugins = NULL;
    mem_idx = 0;
    used_idx = 0;

    lt_dlexit();
  }
}


void LIBNPTTWO0_DLL npttwo_func1(const char *const prefix)
{
  printf("Plugin list func1 two:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%s%zu. %s\n", prefix, i+1, plugins[i]->name);
    plugins[i]->func1(prefix);
  }
}


void LIBNPTTWO0_DLL npttwo_func2(const char *const prefix)
{
  printf("Plugin list func2 two:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%s%zu. %s\n", prefix, i+1, plugins[i]->name);
    const int v = 5;
    const int ret = plugins[i]->func2(prefix, v);
    printf("%s   %d = func2(%d)\n", prefix, ret, v);
  }
}


void LIBNPTTWO0_DLL npttwo_func3(const char *const prefix)
{
  printf("Plugin list func3 two:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%s%zu. %s\n", prefix, i+1, plugins[i]->name);
    const int v = 2;
    const int ret = plugins[i]->func3(prefix, v);
    printf("%s   %d = func3(%d)\n", prefix, ret, v);
  }
}


int LIBNPTTWO0_DLL npttwo_call_from_plugin(int value)
{
  return (value+5);
}
