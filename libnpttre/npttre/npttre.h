#ifndef LIBNPTTRE0_NPTTRE_H
#define LIBNPTTRE0_NPTTRE_H

#ifdef NPT_BUILD_FOR_WINDOWS
# ifdef BULDING_LIBNPTTRE0_DLL
#  define LIBNPTTRE0_DLL __declspec(dllexport)
# else
#  define LIBNPTTRE0_DLL __declspec(dllimport)
# endif
#else
# define LIBNPTTRE0_DLL
#endif

#ifdef __cplusplus
extern "C" {
#endif

  /* library API for library users */
  void LIBNPTTRE0_DLL npttre_fun(void);
  void LIBNPTTRE0_DLL npttre_func1(const char *const prefix);
  void LIBNPTTRE0_DLL npttre_func2(const char *const prefix);
  void LIBNPTTRE0_DLL npttre_func3(const char *const prefix);

  /* library API for use by plugins internal to library */
  int LIBNPTTRE0_DLL npttre_call_from_plugin(int value);

#ifdef __cplusplus
}
#endif

#endif /* LIBNPTTRE0_NPTTRE_H */
