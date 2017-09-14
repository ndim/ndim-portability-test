#ifndef NPTTWO_PLUGIN_API_H
#define NPTTWO_PLUGIN_API_H

typedef void (*npttwo_func1)(void);
typedef int  (*npttwo_func2)(int);

typedef struct {
  const char *name;
  npttwo_func1 func1;
  npttwo_func2 func2;
} npttwo_plugin;

#endif /* NPTTWO_PLUGIN_API_H */
