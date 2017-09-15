#include "npttre/npttre.h"
#include "npttre/plugin-api.h"

#include <ltdl.h>

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>


#define REALLOC_INCREMENT 50


static npttre_plugin **plugins;
static size_t mem_idx;
static size_t used_idx;


static
void npttre_init(void)
  __attribute__((constructor))
  __attribute__((used))
  ;


static
void npttre_done(void)
  __attribute__((destructor))
  __attribute__((used))
  ;


void LIBNPTTRE0_DLL npttre_fun(void)
{
  printf("npttre_fun\n");
  assert(plugins);
}


static int
foreach_func(const char *filename, lt_ptr data __attribute__((unused)))
{
  printf("  * npttre foreach_func %s\n", filename);

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

  npttre_plugin *plugin = lt_dlsym(lh, "plugin");
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
    npttre_plugin **new_plugins =
      realloc(plugins, new_mem_idx * sizeof(npttre_plugin *));
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
void npttre_init(void)
{
  printf("npttre_init\n");
  const char *const tmp_dir = getenv("NPTTRE_PLUGINS");
  const char *const plugindir = tmp_dir?tmp_dir:NPTTRE_PLUGINDIR;
  printf("npttre_init: plugindir = %s\n", plugindir);
  assert(0 == lt_dlinit());
  assert(0 == lt_dladdsearchdir(plugindir));

  printf("Scanning plugin directory tre:\n");
  assert(0 == lt_dlforeachfile(plugindir, foreach_func, NULL));

  printf("Plugin list tre:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("  %zu. %s\n", i+1, plugins[i]->name);
  }

  assert(used_idx > 0);
}


static
void npttre_done(void)
{
  if (plugins) {
    printf("Freeing plugins tre");
    free(plugins);
    plugins = NULL;
    mem_idx = 0;
    used_idx = 0;

    lt_dlexit();
  }
}


void LIBNPTTRE0_DLL npttre_func1(const char *const prefix)
{
  printf("Plugin list func1 tre:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%s%zu. %s\n", prefix, i+1, plugins[i]->name);
    plugins[i]->func1(prefix);
  }
}


void LIBNPTTRE0_DLL npttre_func2(const char *const prefix)
{
  printf("Plugin list func2 tre:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%s%zu. %s\n", prefix, i+1, plugins[i]->name);
    const int v = 5;
    const int ret = plugins[i]->func2(prefix, v);
    printf("%s   %d = func2(%d)\n", prefix, ret, v);
  }
}


void LIBNPTTRE0_DLL npttre_func3(const char *const prefix)
{
  printf("Plugin list func3 tre:\n");
  for (size_t i=0; i<used_idx; i++) {
    printf("%s%zu. %s\n", prefix, i+1, plugins[i]->name);
    const int v = 2;
    const int ret = plugins[i]->func3(prefix, v);
    printf("%s   %d = func3(%d)\n", prefix, ret, v);
  }
}


int LIBNPTTRE0_DLL npttre_call_from_plugin(int value)
{
  return (value+5);
}
