ACLOCAL_AMFLAGS = -I auto-m4

AM_INSTALLCHECK_STD_OPTIONS_EXEMPT =

AM_DISTCHECK_CONFIGURE_FLAGS =
AM_DISTCHECK_CONFIGURE_FLAGS += --host=$(host) --build=$(build)

AM_CPPFLAGS =
AM_CFLAGS =
BUILT_SOURCES =
CLEANFILES =
EXTRA_DIST =
bin_PROGRAMS =
lib_LTLIBRARIES =

if BUILD_FOR_WINDOWS
AM_CFLAGS += -municode
AM_CPPFLAGS += -DNPT_BUILD_FOR_WINDOWS
endif

AM_CFLAGS += -std=c11
AM_CFLAGS += -Wall
AM_CFLAGS += -Wextra
AM_CFLAGS += -Wpedantic
AM_CFLAGS += -Werror

include build-helpers/package-version.mk

include libnptone/Makefile-files
include src/Makefile-files
