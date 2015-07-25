/*
 * hobdcalc 
 * Copyright (C) 2014 Bruggemann Eddie.
 * 
 * This file is part of hobdcalc  .
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
 ************************************************************************************/

long double octfloataddoctfloat(char *oct_float_str_1,char *oct_float_str_2) {
  long double oct_float_value_1=octfloattofloat(oct_float_str_1) ;
  long double oct_float_value_2=octfloattofloat(oct_float_str_2) ;
  
  feclearexcept(FE_OVERFLOW|FE_UNDERFLOW); /** Clear flags. **/
  
  long double res = oct_float_value_1 + oct_float_value_2  ; /** Perform the operation but the flags are not set in case of [over|under]flow. **/
  
  if (fetestexcept(FE_OVERFLOW|FE_UNDERFLOW) != 0) {
    /** This [over|under]flow detection don't work...
     *  TO BUGFIX !!!
     *  Please contact me if you know how detect an long double [over|under]flow at <mrcyberfighter@gmail.com> 
     * *******************************************************************************************************/
    errno=ERANGE ;
  }
  
  
  return res ;
}

long double octfloatsuboctfloat(char *oct_float_str_1,char *oct_float_str_2) {
  long double oct_float_value_1=octfloattofloat(oct_float_str_1) ;
  long double oct_float_value_2=octfloattofloat(oct_float_str_2) ;
  
  feclearexcept(FE_OVERFLOW|FE_UNDERFLOW); /** Clear flags. **/
  
  long double res = oct_float_value_1 - oct_float_value_2  ; /** Perform the operation but the flags are not set in case of [over|under]flow. **/
  
  if (fetestexcept(FE_OVERFLOW|FE_UNDERFLOW) != 0) {
    /** This [over|under]flow detection don't work...
     *  TO BUGFIX !!!
     *  Please contact me if you know how detect an long double [over|under]flow at <mrcyberfighter@gmail.com> 
     * *******************************************************************************************************/
    errno=ERANGE ;
  }
  
  return res ;
}

long double octfloatmultoctfloat(char *oct_float_str_1,char *oct_float_str_2) {
  long double oct_float_value_1=octfloattofloat(oct_float_str_1) ;
  long double oct_float_value_2=octfloattofloat(oct_float_str_2) ;
  
  feclearexcept(FE_OVERFLOW|FE_UNDERFLOW); /** Clear flags. **/
  
  long double res = oct_float_value_1 * oct_float_value_2  ; /** Perform the operation but the flags are not set in case of [over|under]flow. **/
  
  if (fetestexcept(FE_OVERFLOW|FE_UNDERFLOW) != 0) {
    /** This [over|under]flow detection don't work...
     *  TO BUGFIX !!!
     *  Please contact me if you know how detect an long double [over|under]flow at <mrcyberfighter@gmail.com> 
     * *******************************************************************************************************/
    errno=ERANGE ;
  }
  
  return res ;
}

long double octfloatdivoctfloat(char *oct_float_str_1,char *oct_float_str_2) {
  long double oct_float_value_1=octfloattofloat(oct_float_str_1) ;
  long double oct_float_value_2=octfloattofloat(oct_float_str_2) ;
  
  if (oct_float_value_2 == 0.0) {
    fprintf(stderr,"%s Zero division error\n",__func__) ;
    exit(EXIT_FAILURE) ;
  }
  
  feclearexcept(FE_OVERFLOW|FE_UNDERFLOW); /** Clear flags. **/
  
  long double res = oct_float_value_1 / oct_float_value_2  ; /** Perform the operation but the flags are not set in case of [over|under]flow. **/
  
  if (fetestexcept(FE_OVERFLOW|FE_UNDERFLOW) != 0) {
    /** This [over|under]flow detection don't work...
     *  TO BUGFIX !!!
     *  Please contact me if you know how detect an long double [over|under]flow at <mrcyberfighter@gmail.com> 
     * *******************************************************************************************************/
    errno=ERANGE ;
  }
  
  return res ;
}