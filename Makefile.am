ACLOCAL_AMFLAGS = -I auto-m4

AM_INSTALLCHECK_STD_OPTIONS_EXEMPT =

AM_DISTCHECK_CONFIGURE_FLAGS =
AM_DISTCHECK_CONFIGURE_FLAGS += --host=$(host) --build=$(build)

pkgconfigdir = $(libdir)/pkgconfig

AM_CPPFLAGS =
AM_CFLAGS =
BUILT_SOURCES =
CLEANFILES =
EXTRA_DIST =
bin_PROGRAMS =
lib_LTLIBRARIES =
noinst_DATA =
nodist_pkgconfig_DATA =
pkgconfig_DATA =

if BUILD_FOR_WINDOWS
AM_CFLAGS += -municode
AM_CPPFLAGS += -DNPT_BUILD_FOR_WINDOWS
endif

AM_CFLAGS += -std=c11
AM_CFLAGS += -Wall
AM_CFLAGS += -Wextra
AM_CFLAGS += -Wpedantic
AM_CFLAGS += -Werror

# The GNUmakefile does not do anything useful in a tarball
# environment, but configure.ac wants to create GNUmakefile from
# GNUmakefile.in, so we ship that in the dist tarball.
EXTRA_DIST += GNUmakefile.in

include build-helpers/package-version.mk

include libnptone/Makefile-files
include src/Makefile-files
