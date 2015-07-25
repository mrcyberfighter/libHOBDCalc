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

enum {HEX_0=0,HEX_1,HEX_2,HEX_3,HEX_4,HEX_5,HEX_6,HEX_7,HEX_8,HEX_9} ;
enum {HEX_A=10,HEX_B,HEX_C,HEX_D,HEX_E,HEX_F} ;


int get_digit(int c) {
  
  /** Return the value for char if HEXADECIMAL else for getting the integer value from base */
  char res ;
  res=(char) c ;
  if ((res == 'F') || (res == 'f')) {
    return HEX_F ;
  }
  else if ((res == 'E') || (res == 'e')){
    return HEX_E ;
  }
  else if ((res == 'D') || (res == 'd')) {
    return HEX_D ;
  }
  else if ((res == 'C') || (res == 'c')) {
    return HEX_C ;
  }
  else if ((res == 'B') || (res == 'b')) {
    return HEX_B ;
  }
  else if ((res == 'A') || (res == 'a')) {
    return HEX_A ;
  }
  else if (res == '9') {
    return HEX_9 ;
  }
  else if (res == '8') {
    return HEX_8 ;
  }
  else if (res == '7') {
    return HEX_7 ;
  }
  else if (res == '6') {
    return HEX_6 ;
  }
  else if (res == '5') {
    return HEX_5 ;
  }
  else if (res == '4') {
    return HEX_4 ;
  }
  else if (res == '3') {
    return HEX_3 ;
  }
  else if (res == '2') {
    return HEX_2 ;
  }
  else if (res == '1') {
    return HEX_1 ;
  }
  else if (res == '0') {
    return HEX_0 ;
  }
  return -1 ;
  
}

char set_digit(int c) {
  /** Return the char if HEXADECIMAL else for setting the integer value from base */
  if (c == 15) {
    return 'F' ;
  }
  else if (c == 14){
    return 'E' ;
  }
  else if (c== 13) {
    return 'D' ;
  }
  else if (c == 12) {
    return 'C' ;
  }
  else if (c == 11) {
    return 'B' ;
  }
  else if (c == 10) {
    return 'A' ;
  }
  else if (c == 9) {
    return '9' ;
  }
  else if (c == 8) {
    return '8' ;
  }
  else if (c == 7) {
    return '7' ;
  }
  else if (c == 6) {
    return '6' ;
  }
  else if (c == 5) {
    return '5' ;
  }
  else if (c == 4) {
    return '4' ;
  }
  else if (c == 3) {
    return '3' ;
  }
  else if (c == 2) {
    return '2' ;
  }
  else if (c == 1) {
    return '1' ;
  }
  else if (c == 0) {
    return '0' ;
  }
  return -1 ;
  
}


void splitter(char *string,char *res_int,char *res_float) {
  char *str_to_split=malloc(strlen(string)+1) ;
  strcpy(str_to_split,string) ;
  char *token=NULL ;
  int part=0 ;
  
  while (str_to_split != NULL) {
    token=strtok(str_to_split,".") ;
    if (token == NULL) {
      break ;
    }
    else {
      if ( part == 0) { 
        strcpy(res_int,token) ;
        part=1 ;
	str_to_split += strlen(token)+1 ;
	continue ;
      }
      else if (part == 1) {
        strcpy(res_float,token) ;
        str_to_split=NULL ;	
      }
      
      
    }
  }
  
  str_to_split=NULL ;
  return ;
}

_Bool is_string_bin(const char *bin_str,_Bool is_float) {
  int c = 0 ;
  uint8_t comma_counter = 0 ;  
  
  if (bin_str[0] == '-') {
    c++ ;
  }
  
  for ( ; c < (int) strlen(bin_str) ; c++) {
    
    if (bin_str[c] != '0' && bin_str[c] != '1' && bin_str[c] != '.') {
      return false ;
    }
    
    if (bin_str[c] == '.') {
      comma_counter++ ;
      if (comma_counter > 1) {
	return false ;
      }
      if ( ! is_float) {
	return false ;
      }
    }
    
  }
  
  return true ;
}

_Bool is_string_oct(const char *oct_str,_Bool is_float) {
  int c = 0 ;
  uint8_t comma_counter = 0 ;  
  
  if (oct_str[0] == '-') {
    c++ ;
  }
  
  for ( ; c < (int) strlen(oct_str) ; c++) {
    if ( get_digit(oct_str[c]) == -1 && oct_str[c] != '.' ) {
      return false ;
    }
    
    if (oct_str[c] == '.') {
      comma_counter++ ;
      if (comma_counter > 1) {
	return false ;
      }
      if ( ! is_float) {
	return false ;
      }
    }
    
  }
  
  return true ;
}
  
_Bool is_string_hex(const char *hex_str,_Bool is_float) {
  int c = 0 ;
  uint8_t comma_counter = 0 ;  
  
  if (hex_str[0] == '-') {
    c++ ;
  }
  
  for ( ; c < (int) strlen(hex_str) ; c++) {
    if ( get_digit(hex_str[c]) == -1 && hex_str[c] != '.' ) {
      return false ;
    }
    
    if (hex_str[c] == '.') {
      comma_counter++ ;
      if (comma_counter > 1) {
	return false ;
      }
      if ( ! is_float) {
	return false ;
      }
    }
    
  }
  
  return true ;
}

void strip_to_int(char *string) {
  int c ;
  
  for (c=((int) strlen(string))-1 ; string[c] != '.' ; c--) {
    string[c]='\0' ;
  }

  string[c]='\0' ;
  
  return ;
}
