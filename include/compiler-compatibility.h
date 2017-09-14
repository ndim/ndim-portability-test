#ifndef COMPILER_COMPATIBILITY_H
#define COMPILER_COMPATIBILITY_H

#define _UP(name) unused_param_ ## name
#define UP(name) _UP(name) __attribute__((unused))

#define _UV(name) unused_var_ ## name
#define UV(name) _UV(name) __attribute__((unused))

#endif /* COMPILER_COMPATIBILITY_H */
