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

long double __binfloattofloatintpart(const char *buffer) {
  unsigned int c,i ; /** c = exponent ; i = index ; (the string is reversed for pow(base,index)) */
  long double res= 0.0 ;
  for (c=0,i=strlen(buffer)-1 ; c < strlen(buffer) ; c++,i--) {
    if (buffer[i] == '1') {
      res += (long long) powl(2,c) ; /** get the octal digit integer value from char */
    }
  }

  return res ;

}

void __inttobinfloatpart(long double value, char *buffer, int precision) {
  /* Set the float part value in an binary string stored in the given pointer ;
   ***************************************************************************/
 
  /** temporary final result container variable used for computing */
  char *bin_str_saved=malloc(96) ;
  memset(bin_str_saved,'\0',96) ;
 
  int c=0 ;
  if (value < 0) {
    /** value needed for computing */
    value=fabs(value) ;
  }
  while (c < precision) {
    /** loop for computing until precision is reach */
   
    long double res_int ;
    long double res_float ;
   
    res_float=modfl(value * 2.0,&res_int) ; /** modulo float */
   
   
    if ( res_int  == 0) {
      strcat(bin_str_saved,"0") ; /** getting the binary string component as the integer to add to float part */
    }
    else if ( res_int  == 1 ) {
      strcat(bin_str_saved,"1") ; /** getting the binary string component as the integer to add to float part */
    }
    else {
      return ;
    }
   
    if ( res_float == 0.0 ) {
      break ; /** reach end of binary float string computing */
    }
   
    value=res_float ;
   
    c++ ;
  }
 
  c=sprintf(buffer,"%s",bin_str_saved) ;
  buffer[c]='\0' ;
  free(bin_str_saved) ;
}

long double binfloattofloat(const char *float_string) {
  /* Convert an binary string from the given pointer in an float value ;
   *******************************************************************/
  if (float_string == NULL) {
    /** Invalid argument **/
    fprintf(stderr,"%s %s\n",__func__,strerror(EINVAL)) ;
    exit(EXIT_FAILURE) ;
  }
 
  if ( ! is_string_bin(float_string,true) ) {
    /** Invalid argument **/
    fprintf(stderr,"%s %s\n",__func__,strerror(EINVAL)) ;
    exit(EXIT_FAILURE) ;
  }
  
  if ( strchr(float_string,'.') == NULL) {
    /** Case argument string is not a float, return integer value (long double) cast */
    return __binfloattofloatintpart(float_string) ;
  }
 
  _Bool is_negativ=false ;
  if ( float_string[0] == '-' ) {
     /** Case argument string is an negativ value we remember it for returning */
     is_negativ=true ;
   }
 
  /** variables for splitting in integer and float part */
  char *bin_float_str_saved=strdup(float_string) ;
  char *bin_int_part=malloc(64) ;
  char *bin_float_part=malloc(64) ;
  memset(bin_int_part,'\0',64) ;
  memset(bin_float_part,'\0',64) ;
 
  /** Perform splitting for getting float part we are interest */
  splitter(bin_float_str_saved,bin_int_part,bin_float_part) ;
 
  long double res_int = __binfloattofloatintpart(bin_int_part) ; /** value to return for the integer part */
 
 
  unsigned int c ;        /** float part index */
  int cc ;                /** float exponent value */
  double res_float=0.0 ;  /** variable for computing float part */
 
  for(c=0 ,cc=-1 ; c < strlen(bin_float_part) ; c++,cc--) {
    res_float += (long double) (((int) bin_float_part[c]-'0') * powl(2,cc)) ;
  }
 
  free(bin_int_part) ;
  free(bin_float_part) ;
  free(bin_float_str_saved) ;
 
  if ( is_negativ ) {
     return - (long double) (res_int + res_float) ;
   }
   else {
     return (long double) res_int + res_float ;
   }

} 



char *floattobinfloat(long double value, char *buffer) {
  /* Convert an float value in an binary string stored in the given pointer;
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
  char *int_part_str_bin=malloc(128) ;
  char *float_part_str_bin=malloc(128) ;
  memset(int_part_str_bin,'\0',128) ;
  memset(float_part_str_bin,'\0',128) ;
 
  /** Perform splitting in integer and float part */
  inttobin((long long) int_part,int_part_str_bin) ;
  __inttobinfloatpart(float_part,float_part_str_bin,128) ;
 
  /** result binary string variable (pointer given as argument) */
  memset(buffer,'\0',128) ;
  if ( ( value  < 0) && (int_part_str_bin[0] != '-') ) {
    /** Case value to convert in binfloat string is negativ */
    strcpy(buffer,"-") ;
  }
 
  /** Assemble final binary string */
  strcat(buffer,int_part_str_bin) ;
  strcat(buffer,".") ;
  strcat(buffer,float_part_str_bin) ;
 
  buffer[127]='\0' ;
 
  return buffer ;
 
}




