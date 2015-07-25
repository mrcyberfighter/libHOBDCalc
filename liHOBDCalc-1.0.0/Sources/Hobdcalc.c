/**
 * hobdcalc (hexadecimal, Octal, Binary, Decimal calculator) library.
 * Copyright (C) 2014 Bruggemann Eddie <mrcyberfighter@gmail.com>.
 *
 * This file is part of hobdcalc.
 * hobdcalc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * hobdcalc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with hobdcalc. If not, see <http://www.gnu.org/licenses/>
 *
 *********************************************************************************/

#include "../config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef HAVE_TGMATH_H
#include <tgmath.h>
#else
#include <math.h>
#endif
 
#include <ctype.h>
#include <limits.h>
#include <inttypes.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <malloc.h>


#include "conversion/utils/conversion_utils.c"

#include "conversion/int_hex/calc_int_hex.c"
#include "conversion/int_bin/calc_int_bin.c"
#include "conversion/int_oct/calc_int_oct.c"


#include "conversion/float_to_bin/float_bin.c"
#include "conversion/float_to_oct/float_oct.c"
#include "conversion/float_to_hex/float_hex.c"

#include "operations/int_result/calc_hex_int_operations.c"
#include "operations/int_result/calc_oct_int_operations.c"
#include "operations/int_result/calc_bin_int_operations.c"

#include "operations/float_result/calc_hex_float_operations.c"
#include "operations/float_result/calc_oct_float_operations.c"
#include "operations/float_result/calc_bin_float_operations.c"


/** hobdcalc can compute in the
 *  -) binar
 *  -) octal
 *  -) hexadecimal
 *  bases without problems.
 *
 *  Arithmetics functions take the 2 operand as string
 *
 *  whose you can get with the conversion functions who take as first argument an value
 *  and as second a pointer to a buffer for containing the result.
 *  The recommended buffer size are :
 *
 *  *) floattobinfloat(...)    * You can give NULL as buffer the function
 *  *) floattooctfloat(...)    * will return an allocated char buffer.
 *  *) floattohexfloat(...)    *
 *  *) inttobin(...)           * Recommended buffer size: 128 bytes. 
 *  *) inttooct(...)           * Recommended buffer size:  48 bytes. 
 *  *) inttohex(...)           * Recommended buffer size:  32 bytes.     
 *
 *  The reverse functions take a string as argument and return the [integer|float] result.
 *
 *  The limits values are for:
 *  integers: long long [-9223372036854775808 - 9223372036854775807].
 *  floats  : long double 19 digits precision.
 *
 *  To install the library extract the tarball and launch the make tool as root.
 *  $ ./configure
 *  $ make
 *  $ sudo make install
 *
 *  You must link the @hobdcalc library with:
 *
 *  $ cc src.c -lHOBDCalc
 *
 *  In case of linking problems:
 *  You must link the @hobdcalc library and the @math library with:
 *
 *  $ cc src.c -lHOBDCalc -lm # (In that order).
 *
 *  to compil the code an programm using the hobdcalc library.
 *
 *  I hope this little calculator functions will be usefull for you.   
 * ******************************************************************************************************************/

