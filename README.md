ndim-portability-test
=====================

Test generating libraries and executables for Linux and Windows.

Also, test generating a library dynamically loading plugins which in
turn use functions from that library. And that works - at least
natively on Linux and cross-compiling with mingw and running with
Wine.


Usage
-----

### Prepare the source tree ###

    $ cd ndim-portability-test
    $ autoreconf -vis


### Compile for native GNU/Linux system ###

    $ mkdir _build-native
    $ cd _build-native
	$ ../configure --prefix=$PWD/_i
	$ make check || cat test-suite.log


### Cross-compile for Windows32 system ###

    $ mkdir _build-win32
    $ cd _build-win32
	$ ../configure --prefix=$PWD/_i --host=i686-w64-mingw32
	$ # TODO: Give wine the opportunity to find some DLLs.
	$ make check || cat test-suite.log

For the `make check` to succeed, the following DLLs need to be put in
a place wine can find, such as `$PWD/_i/bin/`:

  * `libltdl-7.dll`
    `/usr/i686-w64-mingw32/sys-root/mingw/bin/libltdl-7.dll`

  * `libgcc_s_sjlj-1.dll`
    `/usr/i686-w64-mingw32/sys-root/mingw/bin/libgcc_s_sjlj-1.dll`

  * `libwinpthread-1.dll`
    `/usr/i686-w64-mingw32/sys-root/mingw/bin/libwinpthread-1.dll`


### Cross-compile for Windows64 system ###

    $ mkdir _build-win64
    $ cd _build-win64
	$ ../configure --prefix=$PWD/_i --host=x86_64-w64-mingw32
	$ # TODO: Give wine the opportunity to find some DLLs.
	$ make check || cat test-suite.log

For the `make check` to succeed, the following DLLs need to be put in
a place wine can find, such as `$PWD/_i/bin/`:

  * `libltdl-7.dll`
    `/usr/x86_64-w64-mingw32/sys-root/mingw/bin/libltdl-7.dll`


How it works
------------

    Executable:    npt-console.exe                 npt

      linked to

    Library:       libnpttwo0.dll                  libnpttwo0.so.*

      loading

    Plugins:       a.dll                           a.so

      which in turn are linked to to

    import lib     libnpttwo0.dll.a (statically)
    actual lib                                     libnpttwo0.so.* (dynamically)


Some links
----------

  * https://stackoverflow.com/questions/20007973/how-do-i-generate-an-import-lib-for-an-exe-using-automake-autoconf-libtool
    This answers the main issue of how to create the import library.

  * https://stackoverflow.com/questions/19300276/best-way-to-load-plugins-on-windows-that-link-to-executable
    Does not really help the linking issue.

  * https://github.com/dlfcn-win32/dlfcn-win32
    dlfcn-win32 is not really necessary if you use libtool's libltdl.
