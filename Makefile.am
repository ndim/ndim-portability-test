ACLOCAL_AMFLAGS = -I auto-m4

AM_INSTALLCHECK_STD_OPTIONS_EXEMPT =

AM_DISTCHECK_CONFIGURE_FLAGS =
AM_DISTCHECK_CONFIGURE_FLAGS += --host=$(host) --build=$(build)

AM_CFLAGS =
CLEANFILES =
bin_PROGRAMS =
lib_LTLIBRARIES =

if BUILD_FOR_WINDOWS
AM_CFLAGS += -municode
endif

include libwintest/Makefile-files
include src/Makefile-files
