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

long double __octfloattofloattintpart(const char *buffer) {
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
      res = res + (get_digit(buffer[i])*powl(8,c)) ; /** get the hexadecimal value from char */
    }
    else {
      /** Case for first digit */
      res = get_digit(buffer[i]) ; /** get the hexadecimal value from char */
    }
  }
 
 
  return res ;
 
}


void __inttooctfloatpart(long double value, char *buffer, int precision) {
  /* Set the float part value in an octal string stored in the given pointer ;
   ***************************************************************************/
 
  /** temporary final result container variable used for computing */
  char *oct_str_saved=malloc(96) ;
  memset(oct_str_saved,'\0',96) ;

  int c=0 ;
  if (value < 0) {
    /** value needed for computing */
    value=fabs(value) ;
  }
  while (c < (precision)) {
    /** loop for computing until precision is reach */
   
    char *to_oct=malloc(48) ;
    memset(to_oct,'\0',48) ;
   
    long double res_int ;
    long double res_float ;
   
    res_float=modfl(value* 8.0,&res_int) ; /** modulo float */
   
    inttooct(res_int,to_oct) ;  /** getting the octal string of the integer to add to float part */
   
    strcat(oct_str_saved,to_oct) ;
    if ( res_float == 0.0 ) {
      break ; /** reach end of octal string computing */
    }
   
    value=res_float ; /** updating value */
    c++ ;
  }
 
  sprintf(buffer,"%s",oct_str_saved) ;
  free(oct_str_saved) ;
 
}



char *floattooctfloat(long double value, char *buffer) {
  /* Convert an float value in an octal string stored in the given pointer;
   ************************************************************************/
 
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

  float_part=modfl(value,&int_part) ; /** modulo float */
 
  /** variables for splitting in integer and float part */
  char *int_part_str_oct=malloc(128) ;
  char *float_part_str_oct=malloc(128) ;
  memset(int_part_str_oct,'\0',128) ;
  memset(float_part_str_oct,'\0',128) ;
 
  /** Perform splitting in integer and float part */
  inttooct(int_part,int_part_str_oct) ;
  __inttooctfloatpart(float_part,float_part_str_oct,127) ;

  /** result octal string variable (pointer given as argument) */
  memset(buffer,'\0',128) ;
 
  if ( (value  < 0) && (int_part_str_oct[0] != '-') ) {
    /** Case value to convert in binfloat string is negativ */
    strcpy(buffer,"-") ;
  }
 
  /** Assemble final binar string */
  strcat(buffer,int_part_str_oct) ;
  strcat(buffer,".") ;
  strcat(buffer,float_part_str_oct) ;
 
  return buffer ;
}

long double octfloattofloat(const char *float_string) {
  /* Convert an octal string from the given pointer in an float value ;
   ********************************************************************/
 
  if (float_string == NULL) {
    /** Invalid argument **/
    fprintf(stderr,"%s %s\n",__func__,strerror(EINVAL)) ;
    exit(EXIT_FAILURE) ;
  }
 
  if ( ! is_string_oct(float_string,true) ) {
    /** Invalid argument **/
    fprintf(stderr,"%s %s\n",__func__,strerror(EINVAL)) ;
    exit(EXIT_FAILURE) ;
  }
 
  if ( strchr(float_string,'.') == NULL) {
    /** Case argument string is not a float, return integer value (long double) cast */
    return __octfloattofloattintpart(float_string) ;
  }
  char *oct_float_str_saved=strdup(float_string) ;
  _Bool is_negativ=false ;
  if ( float_string[0] == '-' ) {
    /** Case argument string is an negativ value we remember it for returning */
    is_negativ=true ;
    int i,c ;
     for (i=1,c=0 ; i < (int) strlen(float_string) ; i++,c++) {
       oct_float_str_saved[c]=float_string[i] ;
     }
     oct_float_str_saved[c]='\0' ;
  }
  else {
    oct_float_str_saved=strdup(float_string) ;
  }
 
  /** variables for splitting in integer and float part */
 
  char *oct_int_part=malloc(64) ;
  char *oct_float_part=malloc(64) ;
  memset(oct_int_part,'\0',64) ;
  memset(oct_float_part,'\0',64) ;
 
  /** Perform splitting for getting float part we are interest */
  splitter(oct_float_str_saved,oct_int_part,oct_float_part) ;
 
  long double res_int = __octfloattofloattintpart(oct_int_part) ; /** value to return for the integer part */
 
  unsigned int c  ;           /** float part index */
  int cc ;                    /** float exponent value */
  long double res_float=0.0 ; /** variable for computing float part */
 
  for(c=0 ,cc=-1 ; c < (unsigned int) strlen(oct_float_part) ; c++,cc--) {
    res_float += (long double) get_digit(oct_float_part[c]) * powl(8,cc) ;
  }
 
  free(oct_int_part) ;
  free(oct_float_part) ;
  free(oct_float_str_saved) ;
 
  if ( is_negativ ) {
     return - (long double) (res_int + res_float) ;
   }
   else {
     return (long double) res_int + res_float ;
   }
}

