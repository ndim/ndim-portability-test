#ifndef LIBNPTONE0_NPTONE_H
#define LIBNPTONE0_NPTONE_H

#ifdef NPT_BUILD_FOR_WINDOWS
# ifdef BULDING_LIBNPTONE0_DLL
#  define LIBNPTONE0_DLL __declspec(dllexport)
# else
#  define LIBNPTONE0_DLL __declspec(dllimport)
# endif
#else
# define LIBNPTONE0_DLL
#endif

#ifdef __cplusplus
extern "C" {
#endif

void LIBNPTONE0_DLL nptone_fun(void);

#ifdef __cplusplus
}
#endif

#endif /* LIBNPTONE0_NPTONE_H */
