ACLOCAL_AMFLAGS = -I auto-m4 -I m4

AM_INSTALLCHECK_STD_OPTIONS_EXEMPT =

AM_DISTCHECK_CONFIGURE_FLAGS =
AM_DISTCHECK_CONFIGURE_FLAGS += --host=$(host) --build=$(build)

pkgconfigdir = $(libdir)/pkgconfig

BUILT_SOURCES =
CLEANFILES =
EXTRA_DIST =
bin_PROGRAMS =
bin_SCRIPTS =
lib_LTLIBRARIES =
noinst_DATA =
noinst_PROGRAMS =
nodist_pkgconfig_DATA =
pkgconfig_DATA =
TESTS =

EXTRA_DIST += LICENSE

if BUILD_FOR_WINDOWS
ADD_CFLAGS   += -municode
ADD_CPPFLAGS += -DNPT_BUILD_FOR_WINDOWS
ADD_CFLAGS   += -Wno-pedantic-ms-format
endif

# The GNUmakefile does not do anything useful in a tarball
# environment, but configure.ac wants to create GNUmakefile from
# GNUmakefile.in, so we ship that in the dist tarball.
EXTRA_DIST += GNUmakefile.in

SUBSTITUTIONS =
SUBSTITUTIONS += -e 's,[@]exec_prefix@,$(exec_prefix),g'
SUBSTITUTIONS += -e 's,[@]prefix@,$(prefix),g'
SUBSTITUTIONS += -e 's,[@]bindir@,$(bindir),g'
SUBSTITUTIONS += -e 's,[@]libdir@,$(libdir),g'
SUBSTITUTIONS += -e 's,[@]includedir@,$(includedir),g'
SUBSTITUTIONS += -e 's,[@]PACKAGE_NAME@,$(PACKAGE_NAME),g'
SUBSTITUTIONS += -e 's,[@]PACKAGE_URL@,$(PACKAGE_URL),g'
SUBSTITUTIONS += -e 's,[@]VERSION@,$(VERSION),g'

SUBSTITUTE = $(SED) $(SUBSTITUTIONS)

INSTALLTESTS =

include build-helpers/package-version.mk

include libnptone/Makefile-files
include libnpttwo/Makefile-files
include libnpttre/Makefile-files
include src/Makefile-files

installcheck-local: $(INSTALLTESTS)
	@set -ex; for tc in $(INSTALLTESTS); do \
		echo "Running $$tc"; \
		env DESTDIR="$(DESTDIR)" "$$tc"; \
	done
