#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([ndim windows posix portability test],
        [m4_esyscmd([./build-helpers/package-version.sh . version-stamp])],
        [ndim@n-dimensional.de],
        [ndim-portability-test],
        [http://lauft.net/])
AC_CONFIG_AUX_DIR([auto-aux])
AC_CONFIG_HEADER([include/auto-config.h])
AC_CONFIG_SRCDIR([libnptone/nptone.c])
AC_CONFIG_MACRO_DIR([auto-m4])
AM_INIT_AUTOMAKE([-Wall -Werror foreign no-dist-gzip dist-xz readme-alpha tar-pax subdir-objects std-options])

# Checks for programs.
AC_PROG_SED
AM_PROG_AR
# FIXME: win32-dll does not build DLL for 64bit Windows. WHY?
LT_INIT([disable-static dlopen shared win32-dll])
AC_PROG_CC
AM_PROG_CC_C_O

AC_LANG_WERROR

AC_ARG_VAR([GIT], [git revision control system])
AC_PATH_PROG([GIT], [git], [no])
AM_CONDITIONAL([HAVE_GIT], [test "x$GIT" != "xno"])

m4_pattern_forbid([ADD_FLAGS])
ADD_FLAGS([CFLAGS],   [-std=c11 -pedantic])
ADD_FLAGS([CFLAGS],   [-Wall])
ADD_FLAGS([CFLAGS],   [-Wextra])
ADD_FLAGS([CFLAGS],   [-Werror])
ADD_FLAGS([CPPFLAGS], [-DFOO=42])
dnl ADD_FLAGS([LDFLAGS],  [-Wl,-blubb])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

build_for_windows=no
case "${host_os}" in
     cygwin*|mingw*)
        build_for_windows=yes
        ;;
esac
AM_CONDITIONAL([BUILD_FOR_WINDOWS],
               [test "x$build_for_windows" = "xyes"])
AM_CONDITIONAL([BUILD_FOR_POSIX],
               [test "x$build_for_windows" != "xyes"])

AC_SUBST([LIBLTDL], [-lltdl])
AC_SUBST([LTDLINCL], [])

AC_CONFIG_FILES([GNUmakefile])
AC_CONFIG_FILES([Makefile])

AC_OUTPUT

cat<<EOF

Build configuration:
  package: ${PACKAGE}
  version: ${VERSION}

  srcdir:  ${srcdir}

  host:    ${host}
  build:   ${build}
  windows: ${build_for_windows}

  AR:      ${AR}
  CC:      ${CC}
  CPP:     ${CPP}
  DLLTOOL: ${DLLTOOL}
  LD:      ${LD}
  NM:      ${NM}
  OBJDUMP: ${OBJDUMP}
  RANLIB:  ${RANLIB}
  STRIP:   ${STRIP}

  prefix:  ${prefix}
  bindir:  ${bindir}

You can run "make" and "make install" now.
EOF
