#ifndef NPTTWO_PLUGIN_API_H
#define NPTTWO_PLUGIN_API_H

typedef void (*npttwo_func1_type)(const char *const prefix);
typedef int  (*npttwo_func2_type)(const char *const prefix, int);
typedef int  (*npttwo_func3_type)(const char *const prefix, int);

typedef struct {
  const char *name;
  npttwo_func1_type func1;
  npttwo_func2_type func2;
  npttwo_func3_type func3;
} npttwo_plugin;

#endif /* NPTTWO_PLUGIN_API_H */
