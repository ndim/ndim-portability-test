#ifndef LIBNPTTWO0_NPTTWO_H
#define LIBNPTTWO0_NPTTWO_H

#ifdef NPT_BUILD_FOR_WINDOWS
# ifdef BULDING_LIBNPTTWO0_DLL
#  define LIBNPTTWO0_DLL __declspec(dllexport)
# else
#  define LIBNPTTWO0_DLL __declspec(dllimport)
# endif
#else
# define LIBNPTTWO0_DLL
#endif

#ifdef __cplusplus
extern "C" {
#endif

  /* library API for library users */
  void LIBNPTTWO0_DLL npttwo_fun(void);
  void LIBNPTTWO0_DLL npttwo_func1(void);
  void LIBNPTTWO0_DLL npttwo_func2(void);
  void LIBNPTTWO0_DLL npttwo_func3(void);

  /* library API for use by plugins internal to library */
  int LIBNPTTWO0_DLL npttwo_call_from_plugin(int value);

#ifdef __cplusplus
}
#endif

#endif /* LIBNPTTWO0_NPTTWO_H */
