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

long long hexaddhex(const char *hex_str_1, const char *hex_str_2) {
  long long hex_value_1 = hextoint(hex_str_1) ;
  long long hex_value_2 = hextoint(hex_str_2) ;
  
  /** Here we warn in overflow case. **/
  long double value1, value2 ;
  value1 = (long double) hex_value_1 ;
  value2 = (long double) hex_value_2 ;
  char *res_str=calloc(32,sizeof(char)) ;
  sprintf(res_str,"%Lf",value1 + value2) ;
  strip_to_int(res_str) ;
  errno=0 ;
  strtoll(res_str,NULL,0) ; /** In case of overflow errno = ERANGE **/
  free(res_str) ;
  
  return hex_value_1 + hex_value_2 ;
}

long long hexsubhex(const char *hex_str_1, const char *hex_str_2) {
  long long hex_value_1 = hextoint(hex_str_1) ;
  long long hex_value_2 = hextoint(hex_str_2) ;
  
  /** Here we warn in overflow case. **/
  long double value1, value2 ;
  value1 = (long double) hex_value_1 ;
  value2 = (long double) hex_value_2 ;
  char *res_str=calloc(32,sizeof(char)) ;
  sprintf(res_str,"%Lf",value1 - value2) ;
  strip_to_int(res_str) ;
  errno=0 ;
  strtoll(res_str,NULL,0) ; /** In case of overflow errno = ERANGE **/
  free(res_str) ;
  
  return hex_value_1 - hex_value_2 ;
}

long long hexmulthex(const char *hex_str_1, const char *hex_str_2) {
  long long hex_value_1 = hextoint(hex_str_1) ;
  long long hex_value_2 = hextoint(hex_str_2) ;
  
  /** Here we warn in overflow case. **/
  long double value1, value2 ;
  value1 = (long double) hex_value_1 ;
  value2 = (long double) hex_value_2 ;
  char *res_str=calloc(32,sizeof(char)) ;
  sprintf(res_str,"%Lf",value1 * value2) ;
  strip_to_int(res_str) ;
  errno=0 ;
  strtoll(res_str,NULL,0) ; /** In case of overflow errno = ERANGE **/
  free(res_str) ;
  
  return hex_value_1 * hex_value_2 ;
}

long double hexdivhex(const char *hex_str_1, const char *hex_str_2) {
  long double hex_value_1 = (long double) hextoint(hex_str_1) ;
  long double hex_value_2 = (long double) hextoint(hex_str_2) ;
  
  if (hex_value_2 == 0.0) {
    fprintf(stderr,"%s Zero division error\n",__func__) ;
    exit(EXIT_FAILURE) ;
  }
  
  feclearexcept(FE_OVERFLOW|FE_UNDERFLOW);
  
  long double res = hex_value_1 / hex_value_2  ;
  
  if (fetestexcept(FE_OVERFLOW|FE_UNDERFLOW) != 0) {
    errno=ERANGE ;
  }
  
  return res ;
}