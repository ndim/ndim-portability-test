#ifndef NPTTRE_PLUGIN_API_H
#define NPTTRE_PLUGIN_API_H

typedef void (*npttre_func1_type)(const char *const prefix);
typedef int  (*npttre_func2_type)(const char *const prefix, int);
typedef int  (*npttre_func3_type)(const char *const prefix, int);

typedef struct {
  const char *name;
  npttre_func1_type func1;
  npttre_func2_type func2;
  npttre_func3_type func3;
} npttre_plugin;

#endif /* NPTTRE_PLUGIN_API_H */
