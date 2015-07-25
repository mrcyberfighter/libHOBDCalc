#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libHOBDCalc], [1.0.0], [mrcyberfighter@gmail.com])

AM_INIT_AUTOMAKE

LT_INIT

AC_CONFIG_SRCDIR([./Sources])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])



# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C_O
AC_PROG_INSTALL
AC_PROG_MKDIR_P
AC_PROG_LN_S
#AC_PROG_RANLIB
AC_PROG_SED

# Checks for libraries.
AC_CHECK_LIB([m],
             [powl], ,
             AC_MSG_ERROR([math library don't found !!!
           
             ***** math library don't found !!! *****
             libHOBDcalc require the math library !!!
           
             ])  )


#Check for function.

HAVE_MALLOC_USABLE_SIZE=yes

AC_CHECK_FUNCS([malloc_usable_size],
              ,
              HAVE_MALLOC_USABLE_SIZE=no)



prefix=/usr

# Checks for header files.
AC_CHECK_HEADERS([fenv.h inttypes.h limits.h malloc.h stdlib.h string.h tgmath.h sys/time.h])
AC_HEADER_STDC

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_UINT8_T
AC_TYPE_LONG_DOUBLE
AC_TYPE_LONG_LONG_INT

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_STRTOLD

AC_CHECK_FUNCS([memset strchr strdup strerror gettimeofday])

AC_CONFIG_FILES([Makefile Sources/Makefile man/Makefile Data/Makefile])

AC_CHECK_HEADERS_ONCE([math.h])

#Warning about the malloc_usable_size function.
if test "x${HAVE_MALLOC_USABLE_SIZE}" = xno ; then
AC_MSG_NOTICE([Cannot find malloc_usable_size function !!!
           
    **********   hobdcalc required malloc_usable_size function.   *********
    malloc_usable_size is a GNU extension not available on your system.
  
    So libHOBDCalc will be compile without this function.
   
    Take simply care of the bufer size given to the following functions:
    *) floattobinfloat(...)  /** You can give NULL as buffer the function
    *) floattooctfloat(...)    * will return an allocated char buffer.
    *) floattohexfloat(...)    *
    *) inttobin(...)           * Recommended buffer size: 128 bytes. 
    *) inttooct(...)           * Recommended buffer size:  48 bytes. 
    *) inttohex(...)           * Recommended buffer size:  32 bytes.     */
    ***********************************************************************
    ])
fi

AC_OUTPUT




echo "
      *** Package: ${PACKAGE_STRING} ***
    
      ${PACKAGE_NAME} Version ${PACKAGE_VERSION}
      Prefix: ${prefix}
      Compiler: ${CC}
      libraries: ${LIBS}
      Needed function: malloc_usable_size() // A GNU extension.
    
      Link program using the ${PACKAGE_NAME} library with:
      -lHOBDcalc
    
      Take a look at the assertions file located at:
      /usr/share/libhobdcalc/hobdcalc_assertions.c
    
      And manpages are available at section 3.
    
      System checks OK, now run:
      $ make
      $ sudo make install
    
      Enjoy to use ${PACKAGE_NAME} !!!
      "