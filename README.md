ndim-portability-test
=====================

Test generating libraries and executables for Linux and Windows.

Also, test generating a library dynamically loading plugins which in
turn use functions from that library. And that works - at least
natively on Linux and cross-compiling with mingw and running with
Wine.


Some links
----------

  * https://stackoverflow.com/questions/20007973/how-do-i-generate-an-import-lib-for-an-exe-using-automake-autoconf-libtool
    This answers the main issue of how to create the import library.

  * https://stackoverflow.com/questions/19300276/best-way-to-load-plugins-on-windows-that-link-to-executable
    Does not really help the linking issue.

  * https://github.com/dlfcn-win32/dlfcn-win32
    dlfcn-win32 is not really necessary if you use libtool's libltdl.
