#ifndef LIBWINTEST0_WINTEST_H
#define LIBWINTEST0_WINTEST_H

#ifdef BULDING_LIBWINTEST0_DLL
# define LIBWINTEST0_DLL __declspec(dllexport)
#else
# define LIBWINTEST0_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

void LIBWINTEST0_DLL wintest_one(void);

#ifdef __cplusplus
}
#endif

#endif /* LIBWINTEST0_WINTEST_H */
