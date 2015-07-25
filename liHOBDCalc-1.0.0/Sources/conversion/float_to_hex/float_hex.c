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

long double __hexfloattofloatintpart(const char *buffer) {
  unsigned int c,i,pad ; /** c = exponent ; i = index ; (the string is reversed for pow(base,index)) */
  long double res ;
  pad=0 ;
  if ( buffer[0] == '-' ) {
    /** Case argument string is an negativ value we remember it for returning */
     pad=1 ;
   }
  res=0.0 ;
 
  for (c=0,i=strlen(buffer)-1; c < strlen(buffer)-pad ; c++,i--) {
    if ( ! c == 0 ) {
      res = res + (get_digit(buffer[i])*powl(16,c)) ; /** get the hexadecimal value from char */
    }
    else {
      /** Case for first digit */
      res = get_digit(buffer[i]) ; /** get the hexadecimal value from char */
    }
  }
 
 
  return res ;
 
}

void __inttohexfloatpart(long double value, char *buffer, int precision) {
  /* Set the float part value in an hexadecimal string stored in the given pointer ;
   *********************************************************************************/
 
  /** temporary final result container variable used for computing */
  char *hex_str_saved=malloc(96) ;
  memset(hex_str_saved,'\0',96) ;
 
  int c=0 ;
  if (value < 0) {
    /** value needed for computing */
    value=fabs(value) ;
  }
 
  while (c < (precision)) {
    /** loop for computing until precision is reach */
    char *to_hex=malloc(32) ;
    memset(to_hex,'\0',32) ;
   
    long double res_int ;
    long double res_float ;
   
    res_float = modfl(value * 16.0,&res_int) ; /** modulo float */
   
    inttohex((long long) res_int,to_hex) ; /** getting the hexadecimal string of the integer to add to float part */
    strcat(hex_str_saved,to_hex) ;         

    if ( res_float == 0.0 ) {
      break ; /** reach end of hexadecimal string computing */
    }
   
    value=res_float ; /** updating value */
    c++ ;
  }
 
  snprintf(buffer,(size_t) precision,"%s",hex_str_saved) ;
  free(hex_str_saved) ;
  buffer[++c]='\0' ;
}

long double hexfloattofloat(const char *float_string) {
  /* Convert an hexadecimal string from the given pointer in an float value ;
   **************************************************************************/
 
  if (float_string == NULL) {
    /** Invalid argument **/
    fprintf(stderr,"%s %s\n",__func__,strerror(EINVAL)) ;
    exit(EXIT_FAILURE) ;
  }
 
  if ( ! is_string_hex(float_string,true) ) {
    /** Invalid argument **/
    fprintf(stderr,"%s %s\n",__func__,strerror(EINVAL)) ;
    exit(EXIT_FAILURE) ;
  }
 
  if ( strchr(float_string,'.') == NULL) {
    /** Case argument string is not a float, return integer value (long double) cast */
    return __hexfloattofloatintpart(float_string) ;
  }
  char *hex_float_str_saved=malloc(64) ;
  _Bool is_negativ=false ;
  if ( float_string[0] == '-' ) {
    /** Case argument string is an negativ value we remember it for returning */
     is_negativ=true ;
     int i,c ;
     for (i=1,c=0 ; i < (int) strlen(float_string) ; i++,c++) {
       hex_float_str_saved[c]=float_string[i] ;
     }
     hex_float_str_saved[c]='\0' ; 
   }
   else {
     hex_float_str_saved=strdup(float_string) ;
   }
  
  /** variables for splitting in integer and float part */
 
  char *hex_int_part=malloc(64) ;
  char *hex_float_part=malloc(64) ;
  memset(hex_int_part,'\0',64) ;
  memset(hex_float_part,'\0',64) ;
 
  /** Perform splitting for getting float part we are interest */
  splitter(hex_float_str_saved,hex_int_part,hex_float_part) ;
 
 
  long double res_int = __hexfloattofloatintpart(hex_int_part) ; /** value to return for the integer part */
 
  unsigned int c  ;            /** float part index */
  int cc ;                     /** float exponent value */
  long double res_float=0.0 ;  /** variable for computing float part */

  for(c=0 ,cc=-1 ; c < (unsigned int) strlen(hex_float_part) ; c++,cc--) {
    res_float += (long double) get_digit(hex_float_part[c]) * powl(16,cc) ;
  }
 
  free(hex_int_part) ;
  free(hex_float_part) ;
  free(hex_float_str_saved) ;
 
  if ( is_negativ ) {
     return - (long double) (res_int + res_float) ;
   }
   else {
     return (long double) res_int + res_float ;
   }
}

char *floattohexfloat(long double value, char *buffer) {
  /* Convert an float value in an hexadecimal string stored in the given pointer;
   ******************************************************************************/
 
  if (buffer == NULL) {
    /** Given an NULL pointer as argument **/
    buffer=calloc(128,sizeof(char)) ;
  }
 
  #ifdef HAVE_MALLOC_USABLE_SIZE
 
  if (malloc_usable_size(buffer) < 128)  {
    if ( realloc(buffer,128) == NULL) {
      errno=EINVAL ;	
      return NULL ;
    }
   
  }
 
  #endif
 
  long double int_part=0.0 ;
  long double float_part=0.0 ;
  _Bool is_negativ = false ;
  if (value < 0) {
    value=fabs(value) ;
    is_negativ=true ;
  }
 
  float_part=modfl(value,&int_part) ; /** modulo float */
 
  /** variables for splitting in integer and float part */
  char *int_part_str_hex=malloc(128) ;
  char *float_part_str_hex=malloc(128) ;
  memset(int_part_str_hex,'\0',128) ;
  memset(float_part_str_hex,'\0',128) ;
 
  /** Perform splitting in integer and float part */
  inttohex((long long) int_part,int_part_str_hex) ;
  __inttohexfloatpart(float_part,float_part_str_hex,127) ;

  /** result binar string variable (pointer given as argument) */
  memset(buffer,'\0',128) ;
 
  if ((is_negativ) && (int_part_str_hex[0] != '-')) {
    /** Case value to convert in binfloat string is negativ */
    strcpy(buffer,"-") ;
  }
 
  /** Assemble final binar string */
  strcat(buffer,int_part_str_hex) ;
  strcat(buffer,".") ;
  strcat(buffer,float_part_str_hex) ;
 
  return buffer ;
}

