#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([template_test], [0.0.1], [me@bug.com])
AC_CONFIG_SRCDIR([src/wrapper_test.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign -Wall -Werror])
m4_ifdef([AM_SILENT_RULES],
    [AM_SILENT_RULES([yes])
])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

AM_PROG_AR

LT_INIT([disable-shared])

# Checks for libraries.
AX_BOOST_BASE([1.48],, [AC_MSG_ERROR([This program needs Boost, but it was not found in your system])])
AX_BOOST_SYSTEM
AX_BOOST_DATE_TIME
AX_BOOST_THREAD

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 spsc_lib/Makefile
                 src/Makefile])

AC_OUTPUT
