dnl Moo.
dnl
m4_pattern_forbid([ADD_FLAGS])
dnl
dnl Just keep the values off ADD_*FLAGS in case they have been set by user.
AC_DEFUN([ADD_FLAGS_ONCE], [
  AC_SUBST([ADD_CPPFLAGS])
  AC_SUBST([ADD_CFLAGS])
  AC_SUBST([ADD_LDFLAGS])
])
dnl
dnl TODO: Handle ADD_ASFLAGS.
AC_DEFUN([ADD_FLAGS], [dnl
  AC_REQUIRE([ADD_FLAGS_ONCE])
  m4_case([$1],
          [CFLAGS],
          [saved_CFLAGS="$CFLAGS"
           CFLAGS="$ADD_CFLAGS $2"
           AC_MSG_CHECKING([whether compiler accepts flags $2])
           AC_COMPILE_IFELSE([AC_LANG_SOURCE([char b;])],
                             [AC_MSG_RESULT([[yes (added to default $1)]])
                              ADD_CFLAGS="$ADD_CFLAGS $2"],
                             [AC_MSG_RESULT([[no (not added to default $1)]])])
           CFLAGS="$saved_CFLAGS"
          ],
          [CPPFLAGS],
          [saved_CPPFLAGS="$CPPFLAGS"
           CPPFLAGS="$ADD_CPPFLAGS $2"
           AC_MSG_CHECKING([whether preprocessor accepts flags $2])
           AC_PREPROC_IFELSE([AC_LANG_SOURCE([char b;])],
                             [AC_MSG_RESULT([[yes (added to default $1)]])
  	                      ADD_CPPFLAGS="$ADD_CPPFLAGS $2"],
                             [AC_MSG_RESULT([[no (not added to default $1)]])])
           CPPFLAGS="$saved_CPPFLAGS"
          ],
          [LDFLAGS],
          [saved_LDFLAGS="$LDFLAGS"
           LDFLAGS="$ADD_LDFLAGS $2"
           AC_MSG_CHECKING([whether linker accepts flags $2])
           AC_LINK_IFELSE([AC_LANG_SOURCE([char b;])],
                          [AC_MSG_RESULT([[yes (added to default $1)]])
                           ADD_LDFLAGS="$ADD_LDFLAGS $2"],
                          [AC_MSG_RESULT([[no (not added to default $1)]])])
           LDFLAGS="$saved_LDFLAGS"
          ],
          [m4_fatal([Unhandled flags variable: $1])])dnl
])dnl
dnl
