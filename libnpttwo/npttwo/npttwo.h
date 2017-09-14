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

void LIBNPTTWO0_DLL npttwo_fun(void);

#ifdef __cplusplus
}
#endif

#endif /* LIBNPTTWO0_NPTTWO_H */
