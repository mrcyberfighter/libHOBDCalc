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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/time.h>
#include <hobdcalc.h>



#define DEBUG

void float_operations_test(void) ;

void integer_operations_test(void) ;

int main() {
 
  /** By to traversing this functions all functions from the hobdcalc library are called.
   *
   *  If an error occurs the programm stop immediately and display an error message.
   *
   *  Note that the given argument are cast to the type double, in case of floating-point operation,
   *  to get an exact value by conversion and operation.
   *
   *  Think that the library work internally with the long double type (10 bytes) but can only guarantee
   *  an exact conversion or operation result with the double cast...
   *
   *  You can test any value you like as long you cast it to the double type for floating-point operations.
   *
   ********************************************************************************************************/
 
  int c ;
 
  for (c=1; c < 101 ; c++) {
    float_operations_test() ;
    integer_operations_test() ;
    fprintf(stdout,"%i iterations of the float operations assertion successfull !!!\n",c*1000) ;
    fprintf(stdout,"%i iterations of the integer operations assertion successfull !!!\n",c*1000) ;
 
  }
   
   
 
 
}

void float_operations_test(void) {
  long double op1,op2 ;
  struct timeval tv ;
  char *op1_str=malloc(128) ;
  char *op2_str=malloc(128) ;
  int c ;
 
  for (c=0 ; c < 1000 ; c++) {
    /** Loop for assertions for float operations */
    gettimeofday(&tv,NULL) ;   /** get an random seed */
   
    srand(tv.tv_usec / 4) ;    /** setting the first operand random seed */
    op1= (double) ((rand() % 9223372036854775807) + 0.1) / 3   ;
   
    if (rand() % 2) {
      op1=-op1 ;  /** We take a negativ value. */
    }
   
    srand(tv.tv_usec / 3) ;   /** setting the second operand random seed */
    op2= (double) (rand() % (9223372036854775807/2)) / ((rand() % (9223372036854775807/2))+1.0) ;   /** We take a positiv value. */
   
    if (op2 == 0.0) {
      op2=2.2 ; /** In case to prevent zero division errors. **/
    }
   
    if (rand() % 2) {
      op2=-op2 ;  /** We take a negativ value. */
    }
   
    memset(op1_str,'\0',128) ;
    memset(op2_str,'\0',128) ;
   
    floattobinfloat(op1,op1_str) ; /** Convert the float op1 in an binary string op1_str */
    floattobinfloat(op2,op2_str) ; /** Convert the float op2 in an binary string op2_str */
   
   
   
    #ifdef DEBUG
      /** Check if the values are correct converted */
      printf("%.15Lf == %.15Lf\n",op1,binfloattofloat(op1_str)) ;
      printf("%.15Lf == %.15Lf\n",op2,binfloattofloat(op2_str)) ;
      printf("\n") ;
    #endif
 
    if (op1 + op2 != binfloataddbinfloat(op1_str,op2_str) ) {
      printf("\nassertion float bin add error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,binfloataddbinfloat(op1_str,op2_str)) ;
      break ;
    }
    if (op1 - op2 != binfloatsubbinfloat(op1_str,op2_str) ) {
      printf("\nassertion float bin sub error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,binfloataddbinfloat(op1_str,op2_str)) ;
      break ;
    }
    if (op1 * op2 != binfloatmultbinfloat(op1_str,op2_str) ) {
      printf("\nassertion float bin mult error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,binfloataddbinfloat(op1_str,op2_str)) ;
      break ;
    }
    if ( (long double) op1 / (long double) op2 != binfloatdivbinfloat(op1_str,op2_str) ) {
      printf("\nassertion float bin div error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,binfloataddbinfloat(op1_str,op2_str)) ;
      break ;
    }
   
    #ifdef DEBUG
      /** printing all computing results. */
      printf("  %s\n+ %s\n= %.15Lf\n\n  %s \n- %s\n= %.15Lf\n\n  %s \n* %s\n= %.15Lf\n\n  %s \n/ %s\n= %.15Lf\n\n",op1_str,op2_str,binfloataddbinfloat(op1_str,op2_str),op1_str,op2_str,binfloatsubbinfloat(op1_str,op2_str),op1_str,op2_str,binfloatmultbinfloat(op1_str,op2_str),op1_str,op2_str,binfloatdivbinfloat(op1_str,op2_str)) ;
    #endif
   
    memset(op1_str,'\0',128) ;
    memset(op2_str,'\0',128) ;
    floattooctfloat(op1,op1_str) ; /** Convert the float op1 in an octal string op1_str */
    floattooctfloat(op2,op2_str) ; /** Convert the float op2 in an octal string op2_str */
   
    #ifdef DEBUG
    /** Check if the values are correct converted */
    printf("%.15Lf == %.15Lf\n",op1,octfloattofloat(op1_str)) ;
    printf("%.15Lf == %.15Lf\n",op2,octfloattofloat(op2_str)) ;
    printf("\n") ;
    #endif
   
    if (op1 + op2 != octfloataddoctfloat(op1_str,op2_str) ) {
      printf("\nassertion float oct add error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,octfloataddoctfloat(op1_str,op2_str)) ;
      break ;
    }
    if (op1 - op2 != octfloatsuboctfloat(op1_str,op2_str) ) {
      printf("\nassertion float oct sub error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,octfloatsuboctfloat(op1_str,op2_str)) ;
      break ;
    }
    if (op1 * op2 != octfloatmultoctfloat(op1_str,op2_str) ) {
      printf("\nassertion float oct mult error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,octfloatmultoctfloat(op1_str,op2_str)) ;
      break ;
    }
    if ( (long double) op1 / (long double) op2 != octfloatdivoctfloat(op1_str,op2_str) ) {
      printf("\nassertion float oct div error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,octfloatdivoctfloat(op1_str,op2_str)) ;
      break ;
    }
   
    #ifdef DEBUG
      /** printing all computing results. */
      printf("  %s\n+ %s\n= %.15Lf\n\n  %s \n- %s\n= %.15Lf\n\n  %s \n* %s\n= %.15Lf\n\n  %s \n/ %s\n= %.15Lf\n\n",op1_str,op2_str,octfloataddoctfloat(op1_str,op2_str),op1_str,op2_str,octfloatsuboctfloat(op1_str,op2_str),op1_str,op2_str,octfloatmultoctfloat(op1_str,op2_str),op1_str,op2_str,octfloatdivoctfloat(op1_str,op2_str)) ;
    #endif
   
   
   
    memset(op1_str,'\0',128) ;
    memset(op2_str,'\0',128) ;
    floattohexfloat(op1,op1_str) ; /** Convert the float op1 in an hexadecimal string op1_str */
    floattohexfloat(op2,op2_str) ; /** Convert the float op2 in an hexadecimal string op2_str */
    op1_str[128]='\0' ;
    op2_str[128]='\0' ;
    
   
    #ifdef DEBUG
    /** Check if the values are correct converted */
    printf("%.15Lf == %.15Lf\n",op1,hexfloattofloat(op1_str)) ;
    printf("%.15Lf == %.15Lf\n",op2,hexfloattofloat(op2_str)) ;
    printf("\n") ;
    #endif
   
    if (op1 + op2 != hexfloataddhexfloat(op1_str,op2_str) ) {
      printf("\nassertion float hex add error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,hexfloataddhexfloat(op1_str,op2_str)) ;
      break ;
    }
   
    if (op1 - op2 != hexfloatsubhexfloat(op1_str,op2_str) ) {
      printf("\nassertion float hex sub error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,hexfloataddhexfloat(op1_str,op2_str)) ;
      break ;
    }
   
    if (op1 * op2 != hexfloatmulthexfloat(op1_str,op2_str) ) {
      printf("\nassertion float hex mult error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,hexfloataddhexfloat(op1_str,op2_str)) ;
      break ;
    }
    if ( (long double) op1 / (long double) op2 != hexfloatdivhexfloat(op1_str,op2_str) ) {
      printf("\nassertion float hex div error by iteration %d:\nop1: %.15Lf == %s\nop2: %.15Lf == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,op1+op2,hexfloataddhexfloat(op1_str,op2_str)) ;
      break ;
    }

    #ifdef DEBUG
      /** printing all computing results. */
      printf("  %s\n+ %s\n= %.15Lf\n\n  %s \n- %s\n= %.15Lf\n\n  %s \n* %s\n= %.15Lf\n\n  %s \n/ %s\n= %.15Lf\n\n",op1_str,op2_str,hexfloataddhexfloat(op1_str,op2_str),op1_str,op2_str,hexfloatsubhexfloat(op1_str,op2_str),op1_str,op2_str,hexfloatmulthexfloat(op1_str,op2_str),op1_str,op2_str,hexfloatdivhexfloat(op1_str,op2_str)) ;
    #endif
   
   
   
   
  }
  free(op1_str) ;
  free(op2_str) ;
 
  return  ;
}

void integer_operations_test(void) {
  int c ;
  long long op1,op2 ;
  char *op1_str, *op2_str ;
  op1_str=malloc(128) ;
 
  op2_str=malloc(128) ;
 
  struct timeval tv ;
 
  for (c=0 ; c < 1000 ; c++) {
    /** Loop for assertions for integer operations */
    gettimeofday(&tv,NULL) ;   /** get an random seed */
   
    srand(tv.tv_usec /4 ) ;    /** setting the first operand random seed */
    op1= ((long long ) rand() * (4096*8)) ; /** We take a positiv value. */
   
    srand(tv.tv_usec / 3 ) ;   /** setting the second operand random seed */
    op2=  -  ((long long) rand() % (INT_MAX/(4096*8))) ; /** We take a negativ value. */
   
    if (op2 == 0) {
      op2=2 ;  /** In case to prevent zero division errors. **/
    }
   
    memset(op1_str,'\0',128) ;
    memset(op2_str,'\0',128) ;
    inttobin(op1,op1_str) ; /** Convert the integer op1 in an binary string op1_str */
    inttobin(op2,op2_str) ; /** Convert the integer op2 in an binary string op2_str */
   
    #ifdef DEBUG
      /** Check if the values are correct converted */
      printf("%Li == %Li\n",op1,bintoint(op1_str)) ;
      printf("%Li == %Li\n",op2,bintoint(op2_str)) ;
      printf("\n") ;
    #endif
   
    if (! (op1 + op2 == binaddbin(op1_str,op2_str) ) ) {
      printf("\nassertion integer bin add error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,binaddbin(op1_str,op2_str)) ;
      break ;
    }
    if (! (op1 - op2 == binsubbin(op1_str,op2_str)) ) {
      printf("\nassertion integer bin sub error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,binsubbin(op1_str,op2_str)) ;
      break ;
    }
    if (! (op1 * op2 == binmultbin(op1_str,op2_str)) ) {
      printf("\nassertion integer bin mult error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,binmultbin(op1_str,op2_str)) ;
      break ;
    }
    if (! ((long double) op1 / (long double) op2 == bindivbin(op1_str,op2_str)) ) {
      printf("\nassertion integer bin div error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,(long double)op1+op2,bindivbin(op1_str,op2_str)) ;
      break ;
    }
   
    #ifdef DEBUG
      /** printing all computing results. */
      printf("  %s\n+ %s\n= %Li\n\n  %s \n- %s\n= %Li\n\n  %s \n* %s\n= %Li\n\n  %s \n/ %s\n= %.15Lf\n\n",op1_str,op2_str,binaddbin(op1_str,op2_str),op1_str,op2_str,binsubbin(op1_str,op2_str),op1_str,op2_str,binmultbin(op1_str,op2_str),op1_str,op2_str,bindivbin(op1_str,op2_str)) ;
    #endif
   
 
   
    memset(op1_str,'\0',128) ;
    memset(op2_str,'\0',128) ;
    inttooct(op1,op1_str) ; /** Convert the integer op1 in an octal string op1_str */
    inttooct(op2,op2_str) ; /** Convert the integer op2 in an octal string op2_str */
   
    #ifdef DEBUG
      /** Check if the values are correct converted */
      printf("%Li == %Li\n",op1,octtoint(op1_str)) ;
      printf("%Li == %Li\n",op2,octtoint(op2_str)) ;
      printf("\n") ;
    #endif
   

    if (! (op1 + op2 == octaddoct(op1_str,op2_str) ) ) {
      printf("\nassertion integer oct add error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,octaddoct(op1_str,op2_str)) ;
      break ;
    }
    if (! (op1 - op2 == octsuboct(op1_str,op2_str)) ) {
      printf("\nassertion integer oct sub error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,octsuboct(op1_str,op2_str)) ;
      break ;
    }
    if (! (op1 * op2 == octmultoct(op1_str,op2_str)) ) {
      printf("\nassertion integer oct mult error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,octmultoct(op1_str,op2_str)) ;
      break ;
    }
    if (! ((long double) op1 / (long double) op2 == octdivoct(op1_str,op2_str)) ) {
      printf("\nassertion integer oct div error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,(long double)op1+op2,octdivoct(op1_str,op2_str)) ;
      break ;
    }
   
    #ifdef DEBUG
      /** printing all computing results. */
      printf("  %s\n+ %s\n= %Li\n\n  %s \n- %s\n= %Li\n\n  %s \n* %s\n= %Li\n\n  %s \n/ %s\n= %.15Lf\n\n",op1_str,op2_str,octaddoct(op1_str,op2_str),op1_str,op2_str,octsuboct(op1_str,op2_str),op1_str,op2_str,octmultoct(op1_str,op2_str),op1_str,op2_str,octdivoct(op1_str,op2_str)) ;
    #endif
    
  
    memset(op1_str,'\0',128) ;
    memset(op2_str,'\0',128) ;
    inttohex(op1,op1_str) ; /** Convert the integer op1 in an hexadecimal string op1_str */
    inttohex(op2,op2_str) ; /** Convert the integer op2 in an hexadecimal string op2_str */
   
    #ifdef DEBUG
      /** Check if the values are correct converted */
      printf("%Li == %Li\n",op1,hextoint(op1_str)) ;
      printf("%Li == %Li\n",op2,hextoint(op2_str)) ;
      printf("\n") ;
    #endif

    if (! (op1 + op2 == hexaddhex(op1_str,op2_str) ) ) {
      printf("\nassertion integer hex add error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,hexaddhex(op1_str,op2_str)) ;
      break ;
    }
    if (! (op1 - op2 == hexsubhex(op1_str,op2_str)) ) {
      printf("\nassertion integer hex sub error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,hexsubhex(op1_str,op2_str)) ;
      break ;
    }
    if (! (op1 * op2 == hexmulthex(op1_str,op2_str)) ) {
      printf("\nassertion integer hex mult error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %Li\nerror: %Li\n",c,op1,op1_str,op2,op2_str,op1+op2,hexmulthex(op1_str,op2_str)) ;
      break ;
    }
    if (! ((long double) op1 / (long double) op2 == hexdivhex(op1_str,op2_str)) ) {
      printf("\nassertion integer hex div error by iteration %d:\nop1: %Li == %s\nop2: %Li == %s\nresult: %.15Lf\nerror: %.15Lf\n",c,op1,op1_str,op2,op2_str,(long double)op1+op2,hexdivhex(op1_str,op2_str)) ;
      break ;
    }
   
    #ifdef DEBUG
      /** printing all computing results. */
      printf("  %s\n+ %s\n= %Li\n\n  %s \n- %s\n= %Li\n\n  %s \n* %s\n= %Li\n\n  %s \n/ %s\n= %.15Lf\n\n",op1_str,op2_str,hexaddhex(op1_str,op2_str),op1_str,op2_str,hexsubhex(op1_str,op2_str),op1_str,op2_str,hexmulthex(op1_str,op2_str),op1_str,op2_str,hexdivhex(op1_str,op2_str)) ;
    #endif
   
   
  }
 
  free(op1_str) ;
  free(op2_str) ;
  return ;
 
}

