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
          [saved_[$1]="$[$1]"
           [$1]="$ADD_[$1] $2"
           AC_MSG_CHECKING([whether compiler accepts flags [$2]])
           AC_COMPILE_IFELSE([AC_LANG_SOURCE([[int main() { return 0; }]])],
                             [AC_MSG_RESULT([yes (added to ADD_[$1])])
                              ADD_[$1]="$ADD_[$1] [$2]"],
                             [AC_MSG_RESULT([no (not added to ADD_[$1])])])
           [$1]="$saved_[$1]"
          ],
          [CPPFLAGS],
          [saved_[$1]="$[$1]"
           [$1]="$ADD_[$1] $2"
           AC_MSG_CHECKING([whether preprocessor accepts flags [$2]])
           AC_PREPROC_IFELSE([AC_LANG_SOURCE([[int main() { return 0; }]])],
                             [AC_MSG_RESULT([yes (added to ADD_[$1])])
	                      ADD_[$1]="$ADD_[$1] [$2]"],
                             [AC_MSG_RESULT([no (not added to ADD_[$1])])])
           [$1]="$saved_[$1]"
          ],
          [LDFLAGS],
          [saved_[$1]="$[$1]"
           [$1]="$ADD_[$1] $2"
           AC_MSG_CHECKING([whether linker accepts flags [$2]])
           AC_LINK_IFELSE([AC_LANG_SOURCE([[int main() { return 0; }]])],
                          [AC_MSG_RESULT([yes (added to ADD_[$1])])
                           ADD_[$1]="$ADD_[$1] $2"],
                          [AC_MSG_RESULT([no (not added to ADD_[$1])])])
           [$1]="$saved_[$1]"
          ],
          [m4_fatal([Unhandled flags variable: $1])])dnl
])dnl
dnl
