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

/**
 *  @file hobdcalc.h
 *
 *  Include header for the HOBDCalc (Hexadecimal, Octal, Binary, Decimal Calculator) library.
 *
 ********************************************************************************************/

/** Compil your source code with the linking of the @hobdcalc:
 *
 *  $ cc src.c -lHOBDCalc
 *
 *  In case of linking problems :
 *  Compil your source code with the linking of the @hobdcalc library first and then the @math:
 *
 *  $ cc src.c -lHOBDCalc -lm  # In this order.
 ****************************************************************************************************/

/** Conversion from an signed long long value in an string in base (2, 8 & 16). **/

/** @Parameters:
 * 
 *  @value:   The value to convert in an string in base (2, 8, 16).
 *  @buffer:  A pointer on a buffer to get the converted string.
 *            You can pass an NULL pointer as value.
 *
 *  @Return: an pointer on the given buffer pointer holding the converted string.
 *
 ********************************************************************************/

#ifndef LIB_HOBDCALC_H
#define LIB_HOBDCALC_H

char *inttobin(long long value, char *buffer) ; /** Convert an value in an string representing the converted value in binary base (2).                         **/

char *inttooct(long long value, char *buffer) ; /** Convert an value in an string representing the converted value in octal base (8).                          **/

char *inttohex(long long value, char *buffer) ; /** Convert an value in an string representing the converted value in hexadecimal base (16).                   **/



/** Conversion from an string representing an value in base (2, 8 & 16) to an singed long long value **/

/** @Parameter:
 * 
 * 	@string: An pointer on an string representing an integer value in base (2, 8, 16).
 *
 *  @Return: The converted value as an signed long long value.
 *
 *******************************************************************************************/

long long bintoint(const char *string)  ;  /** Convert the given string representing an value in binary base (2) to the value in base 10.                       **/

long long octtoint(const char *string)  ;  /** Convert the given string representing an value in octal base (8) to the value in base 10.                        **/

long long hextoint(const char *string)  ;  /** Convert the given string representing an value in hexadecimal base (16) to the value in base 10.                 **/





/** Conversion from an signed long double value in an string in base (2, 8 & 16). **/

/** @Parameters:
 * 
 *  @value:   The value to convert in an string in base (2, 8, 16).
 *  @buffer:  A pointer on a buffer to get the converted string.
 *            You can pass an NULL pointer as value.
 *
 *  @Return: an pointer on the given buffer pointer holding the converted string.
 *
 *******************************************************************************/

char *floattobinfloat(long double value, char *buffer)  ;  /** Convert an value in an string representing the converted value in binary base (2).              **/

char *floattooctfloat(long double value, char *buffer)  ;  /** Convert an value in an string representing the converted value in octal base (8).               **/

char *floattohexfloat(long double value, char *buffer)  ;  /** Convert an value in an string representing the converted value in hexadecimal base (16).        **/





/** Conversion from an string representing an value in base (2, 8 & 16) to an singed long double value **/

/** @Parameter:
 * 
 *  @float_string: an pointer on an string representing an integer value in base (2, 8, 16).
 *
 *  @Return: The converted value as an signed long double value.
 *
 ******************************************************************************************************/

long double binfloattofloat(const char *float_string)  ;  /** Convert the given string representing an value in binary base (2) to the value in base 10.        **/

long double octfloattofloat(const char *float_string)  ;  /** Convert the given string representing an value in octal base (8) to the value in base 10.         **/

long double hexfloattofloat(const char *float_string)  ;  /** Convert the given string representing an value in hexadecimal base (16) to the value in base 10.  **/




/** Operations from two strings representing an integer value in binary base (2) **/

/** @Parameters:
 * 
 *  @bin_str_1: An string representing an value in binary base (2).
 *  @bin_str_2: An string representing an value in binary base (2).
 *
 *  @Return: The result from the operation apply on the two string in base 10.
 *
 ****************************************************************************/

long long binaddbin(const char *bin_str_1, const char *bin_str_2)   ;  /** Add the two given string representing an value in binary base (2) and return the result in base 10.              **/

long long binsubbin(const char *bin_str_1, const char *bin_str_2)   ;  /** Substract the two given string representing an value in binary base (2) and return the result in base 10.        **/                                         

long long binmultbin(const char *bin_str_1, const char *bin_str_2)  ;  /** Multiply the two given string representing an value in binary base (2) and return the result in base 10.         **/

long double bindivbin(const char *bin_str_1, const char *bin_str_2) ;  /** Divide the two given string representing an value in binary base (2) and return the result in base 10.           **/






/** Operations from two strings representing an integer value in octal base (8) **/

/** @Parameters:
 * 
 *  @oct_str_1: An string representing an value in octal base (2).
 *  @oct_str_2: An string representing an value in octal base (2).
 *
 *  @Return: The result from the operation apply on the two string in base 10.
 *
 ****************************************************************************/

long long octaddoct(const char *oct_str_1, const char *oct_str_2)   ;  /** Add the two given string representing an value in octal base (8) and return the result in base 10.              **/

long long octsuboct(const char *oct_str_1, const char *oct_str_2)   ;  /** Substract the two given string representing an value in octal base (8) and return the result in base 10.        **/                                         

long long octmultoct(const char *oct_str_1, const char *oct_str_2)  ;  /** Multiply the two given string representing an value in octal base (8) and return the result in base 10.         **/

long double octdivoct(const char *oct_str_1, const char *oct_str_2) ;  /** Divide the two given string representing an value in octal base (8) and return the result in base 10.           **/





/** Operations from two strings representing an integer value in hexadecimal base (16) **/

/** @Parameters:
 * 
 *  @hex_str_1: An string representing an value in hexdecimal base (16).
 *  @hex_str_2: An string representing an value in hexdecimal base (16).
 *
 *  @Return: The result from the operation apply on the two string in base 10.
 *
 ****************************************************************************/

long long hexaddhex(const char *hex_str_1, const char *hex_str_2)   ;  /** Add the two given string representing an value in hexdecimal base (16) and return the result in base 10.        **/

long long hexsubhex(const char *hex_str_1, const char *hex_str_2)   ;  /** Substract the two given string representing an value in hexdecimal base (16) and return the result in base 10.  **/                                         

long long hexmulthex(const char *hex_str_1, const char *hex_str_2)  ;  /** Multiply the two given string representing an value in hexdecimal base (16) and return the result in base 10.   **/

long double hexdivhex(const char *hex_str_1, const char *hex_str_2) ;  /** Divide the two given string representing an value in hexdecimal base (16) and return the result in base 10.     **/





/** Operations from two strings representing an floating-point value in binary base (2) **/

/** @Parameters:
 * 
 *  @bin_float_str_1: An string representing an value in binary base (2).
 *  @bin_float_str_2: An string representing an value in binary base (2).
 *
 *  @Return: The result from the operation apply on the two string in base 10.
 *
 ****************************************************************************/

long double binfloataddbinfloat(const char *bin_float_str_1, const char *bin_float_str_2)   ;  /** Add the two given string representing an value in binary base (2) and return the result in base 10.               **/

long double binfloatsubbinfloat(const char *bin_float_str_1, const char *bin_float_str_2)   ;  /** Substract the two given string representing an value in binary base (2) and return the result in base 10.         **/

long double binfloatmultbinfloat(const char *bin_float_str_1, const char *bin_float_str_2)  ;  /** Multiply the two given string representing an value in binary base (2) and return the result in base 10.          **/

long double binfloatdivbinfloat(const char *bin_float_str_1, const char *bin_float_str_2)   ;  /** Divide the two given string representing an value in binary base (2) and return the result in base 10.            **/



/** Operations from two strings representing an floating-point value in octal base (8) **/

/** @Parameters:
 * 
 *  @oct_float_str_1: An string representing an value in octal base (8).
 *  @oct_float_str_2: An string representing an value in octal base (8).
 *
 *  @Return: The result from the operation apply on the two string in base 10.
 *
 ****************************************************************************/

long double octfloataddoctfloat(const char *oct_float_str_1, const char *oct_float_str_2)   ;  /** Add the two given string representing an value in octal base (8) and return the result in base 10.               **/

long double octfloatsuboctfloat(const char *oct_float_str_1, const char *oct_float_str_2)   ;  /** Substract the two given string representing an value in octal base (8) and return the result in base 10.         **/

long double octfloatmultoctfloat(const char *oct_float_str_1, const char *oct_float_str_2)  ;  /** Multiply the two given string representing an value in octal base (8) and return the result in base 10.          **/

long double octfloatdivoctfloat(const char *oct_float_str_1, const char *oct_float_str_2)   ;  /** Divide the two given string representing an value in octal base (8) and return the result in base 10.            **/


/** Operations from two strings representing an floating-point value in hexadecimal base (16) **/

/** @Parameters:
 * 
 *  @hex_float_str_1: An string representing an value in hexadecimal base (16).
 *  @hex_float_str_2: An string representing an value in hexadecimal base (16).
 *
 *  @Return: The result from the operation apply on the two string in base 10.
 *
 ***********************************************************************************/

long double hexfloataddhexfloat(const char *hex_float_str_1, const char *hex_float_str_2)   ;  /** Add the two given string representing an value in hexadecimal base (16) and return the result in base 10.        **/

long double hexfloatsubhexfloat(const char *hex_float_str_1, const char *hex_float_str_2)   ;  /** Substract the two given string representing an value in hexadecimal base (16) and return the result in base 10.  **/

long double hexfloatmulthexfloat(const char *hex_float_str_1, const char *hex_float_str_2)  ;  /** Multiply the two given string representing an value in hexadecimal base (16) and return the result in base 10.   **/

long double hexfloatdivhexfloat(const char *hex_float_str_1, const char *hex_float_str_2)   ;  /** Divide the two given string representing an value in hexadecimal base (16) and return the result in base 10.     **/

#endif

