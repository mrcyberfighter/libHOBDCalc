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

char *inttohex(long long value, char *buffer) {
 
  if (buffer == NULL) {
    /** Given an NULL pointer as argument **/
    buffer=calloc(32,sizeof(char)) ;
  }
 
  #ifdef HAVE_MALLOC_USABLE_SIZE
 
  if (malloc_usable_size(buffer) < 32)  {
    if ( realloc(buffer,32) == NULL) {
      errno=EINVAL ;	
      return NULL ;
    }
   
  }
 
  #endif
 
  memset(buffer,'\0',32) ;
 
  unsigned int i=0 ;
 
  char *hex_str_saved=malloc(128) ;
  memset(hex_str_saved,'\0',128) ;
 
  _Bool is_negativ=false ;
 
  if (value == 0) {
    /** Case value to convert in hexadecimal string is null */
    strcpy(buffer,"0") ;
    return buffer ;
  }
 
  if (value < 0) {
    /** Case value to convert in hexadecimal string is negativ */
    is_negativ=true ;
    value=fabs(value) ;
  }
 
  while (value != 0) {
    buffer[i]=set_digit((value % 16)) ; /** set the hexadecimal digit integer value */
    value /= 16 ;
    i++ ;
  }
 
  /** reversing the result string */
  unsigned int ii ;
  buffer[i]='\0' ;
  for (i=0,ii=strlen(buffer)-1 ; i < strlen(buffer) ; i++,ii--) {
    hex_str_saved[i]=buffer[ii] ;
  }
  hex_str_saved[i]='\0' ;
 
  /** Copy the result to pointer giving as argument ; */
  if (is_negativ) {
    strcpy(buffer,"-") ;
    strcat(buffer,hex_str_saved) ;
  return buffer ;
 
   
  }
  else {
    strcpy(buffer,hex_str_saved) ;
    return buffer ;
  }
}




long long hextoint(const char *string) {
 
  if (string == NULL) {
    /** Invalid argument **/
    fprintf(stderr,"%s %s\n",__func__,strerror(EINVAL)) ;
    exit(EXIT_FAILURE) ;
  }
 
  if ( ! is_string_hex(string,false) ) {
    /** Invalid argument **/
    fprintf(stderr,"%s %s\n",__func__,strerror(EINVAL)) ;
    exit(EXIT_FAILURE) ;
  }
 
  unsigned int c,i,pad ; /** c = exponent ; i = index ; (the string is reversed for pow(base,index)) */
  long long res ;
  _Bool is_negativ=false ;
  pad=0 ;
  if ( string[0] == '-' ) {
    /** Case argument string is an negativ value we remember it for returning */
     is_negativ=true ;
     pad=1 ;
   }
  
  res=0 ; 
  for (c=0,i=strlen(string)-1; c < strlen(string)-pad ; c++,i--) {
    if ( ! c == 0 ) {
      res = res + (get_digit(string[i])*powl(16,c)) ; /** get the hexadecimal value from char */
    }
    else {
      /** Case for first digit */
      res = get_digit(string[i]) ; /** get the hexadecimal value from char */
    }
  }
  if (is_negativ) {
    return - res ;
  }
  else {
    return res ;
  }
 
}


