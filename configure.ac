#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([ndim windows posix portability test],
	[0.0],
	[ndim@n-dimensional.de],
	[ndim-portability-test],
	[http://lauft.net/])
AC_CONFIG_AUX_DIR([auto-aux])
AC_CONFIG_HEADER([include/auto-config.h])
AC_CONFIG_SRCDIR([libnptone/nptone.c])
AC_CONFIG_MACRO_DIR([auto-m4])
AM_INIT_AUTOMAKE([-Wall -Werror foreign no-dist-gzip dist-xz readme-alpha tar-pax subdir-objects std-options])

# Checks for programs.
AM_PROG_AR
# FIXME: win32-dll does not build DLL for 64bit Windows. WHY?
LT_INIT([disable-static dlopen shared win32-dll])
AC_PROG_CC
AM_PROG_CC_C_O

AC_LANG_WERROR

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
AM_CONDITIONAL([BUILD_FOR_WINDOWS], [test "x$build_for_windows" = "xyes"])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT

cat<<EOF

Build configuration:
  package: ${PACKAGE}
  version: ${VERSION}

  srcdir:  ${srcdir}

  host:    ${host}
  build:   ${build}

  CC:      ${AR}
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
