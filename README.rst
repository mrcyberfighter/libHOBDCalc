HOBDCalc (Hexadecimal, Octal, Binary, Decimal Calculator) library.
==================================================================

Description
-----------

    **HOBDCalc** is an little library for converting decimal values (*signed* *integers* or *floating-point* values) in an string representing the value in following bases. 
    
        * **Binary** base (2). 
    
        * **Octal** base (8).
    
        * **Hexadecimal** base (16).
    
        The values are converting in an string in the wanted base.
    
    And **HOBDCalc** provide the back conversion functions: 

        from an string in base 2, 8 or 16 to the corresponding value in decimal base.
    
    That's not all because HOBDCalc implement the basic operations to apply on the strings in the supported base.

        * **Addition** from 2 strings in base 2, 8 or 16.
    
        * **Substraction** from 2 strings in base 2, 8 or 16.
    
        * **Multiplication** from  2 strings in base 2, 8 or 16.
    
        * **Division** from 2 strings in base 2, 8 or 16.
    
        Either as *integer* values or as *floating-point* values.
    
Functions listing
-----------------
  
  ..
  
  char \*inttobin(long long value, char \*buffer) ; 
  
  char \*inttooct(long long value, char \*buffer) ; 
  
  char \*inttohex(long long value, char \*buffer) ; 
  
  
  long long bintoint(const char \*string)  ; 
  
  long long octtoint(const char \*string)  ; 
  
  long long hextoint(const char \*string)  ; 
  
  
  char \*floattobinfloat(long double value, char \*buffer)  ; 
  
  char \*floattooctfloat(long double value, char \*buffer)  ; 
  
  char \*floattohexfloat(long double value, char \*buffer)  ; 
  
  
  long double binfloattofloat(const char \*float_string)  ; 
  
  long double octfloattofloat(const char \*float_string)  ; 
  
  long double octfloattofloat(const char \*float_string)  ; 
  
  
  long long binaddbin(const char \*bin_str_1, const char \*bin_str_2)   ;
  
  long long binsubbin(const char \*bin_str_1, const char \*bin_str_2)   ;
  
  long long binmultbin(const char \*bin_str_1, const char \*bin_str_2)  ;
  
  long double bindivbin(const char \*bin_str_1, const char \*bin_str_2) ;
  
  
  long long octaddoct(const char \*oct_str_1, const char \*oct_str_2)   ;
  
  long long octsuboct(const char \*oct_str_1, const char \*oct_str_2)   ;
  
  long long octmultoct(const char \*oct_str_1, const char \*oct_str_2)  ;
  
  long double octdivoct(const char \*oct_str_1, const char \*oct_str_2) ;
  
  
  long long hexaddhex(const char \*hex_str_1, const char \*hex_str_2)   ;
  
  long long hexsubhex(const char \*hex_str_1, const char \*hex_str_2)   ;
  
  long long hexmulthex(const char \*hex_str_1, const char \*hex_str_2)  ;
  
  long double hexdivhex(const char \*hex_str_1, const char \*hex_str_2) ;
  
  
  long double binfloataddbinfloat(const char \*bin_float_str_1, const char \*bin_float_str_2)   ;
  
  long double binfloatsubbinfloat(const char \*bin_float_str_1, const char \*bin_float_str_2)   ;
  
  long double binfloatmultbinfloat(const char \*bin_float_str_1, const char \*bin_float_str_2)  ;
  
  long double binfloatdivbinfloat(const char \*bin_float_str_1, const char \*bin_float_str_2)   ;
  
  
  long double octfloataddoctfloat(const char \*oct_float_str_1, const char \*oct_float_str_2)   ;
  
  long double octfloatsuboctfloat(const char \*oct_float_str_1, const char \*oct_float_str_2)   ;
  
  long double octfloatmultoctfloat(const char \*oct_float_str_1, const char \*oct_float_str_2)  ;
  
  long double octfloatdivoctfloat(const char \*oct_float_str_1, const char \*oct_float_str_2)   ;
  
  
  long double hexfloataddhexfloat(const char \*hex_float_str_1, const char \*hex_float_str_2)   ;
  
  long double hexfloatsubhexfloat(const char \*hex_float_str_1, const char \*hex_float_str_2)   ;
  
  long double hexfloatmulthexfloat(const char \*hex_float_str_1, const char \*hex_float_str_2)  ;
  
  long double hexfloatdivhexfloat(const char \*hex_float_str_1, const char \*hex_float_str_2)   ;
    
Installation
------------
    
    ..  
    
        $ ./configure          # This will perform a system check and set some variables.
  
        $ make                 # This will build the shared and the static library.
  
        $ sudo make install    # This will install libHOBDCalc on your system, As shared and static library and the manpages.
     
    
Developpment with HOBDCalc
--------------------------

    By compilation of your programm simply link the **HOBDCalc** library.
    
    ..
        
        $ cc main.c -lHOBDCalc
        
    If this fail try to link *first* the **HOBDCalc** library and *after* the **math** library.    
        
    ..   
        
        $ cc main.c -HOBDCalc -lm   # In that order.    
    

Usage advice of libHOBDCalc:
----------------------------

    For the base conversions for floating-points values use the **double** type instead of the **long double** type by usage of a cast.
    
        Because libHOBDCalc compute internally with the type **long double** type but if you want an fully exact returned value use a cast to  the **double** type. 
        
        like in the provide assertions file of the library: **hobdcalc_assertions.c** which demonstrate the exactitude of **libHOBDCalc** with an correct usage and to put libHOBDCalc to the proof.    
    
    
Note for developpers:
---------------------

    I failed to implement the under|over flow detection by operations functions who deal with the type **long double**.
    
    If you know how to detect so an under|over flow thank's to contact me at: <mrcyberfighter@gmail.com>.
    
mapages:
--------

  Read the manpages available at section 3 for usage of libHOBDCalc:

  * $ man binaddbin
  
  * $ man bindivbin
  
  * $ man binfloataddbinfloat
  
  * $ man binfloatdivbinfloat
  
  * $ man binfloatmultbinfloat
  
  * $ man binfloatsubbinfloat
  
  * $ man binfloattofloat
  
  * $ man binmultbin

  * $ man binsubbin
  
  * $ man bintoint
  
  * $ man floattobinfloat
  
  * $ man floattohexfloat
  
  * $ man floattooctfloat
  
  * $ man hexaddhex
  
  * $ man hexdivhex
  
  * $ man hexfloataddhexfloat
  
  * $ man hexfloatdivhexfloat
  
  * $ man hexfloatmulthexfloat
  
  * $ man hexfloatsubhexfloat
  
  * $ man hexfloattofloat
  
  * $ man hexmulthex
  
  * $ man hexsubhex
  
  * $ man hextoint
  
  * $ man hobdcalc
  
  * $ man inttobin
  
  * $ man inttohex
  
  * $ man inttooct
  
  * $ man octaddoct
  
  * $ man octdivoct
  
  * $ man octfloataddoctfloat
  
  * $ man octfloatdivoctfloat
  
  * $ man octfloatmultoctfloat
  
  * $ man octfloatsuboctfloat
  
  * $ man octfloattofloat
  
  * $ man octmultoct
  
  * $ man octsuboct
  
  * $ man octtoint 

Credits:
--------

  Thank's to my beloved mother, my family and the doctors.
  
  Stay away from drugs: drugs destroy your brain and life. 

License
-------
                                                                                       
 libHOBDCalc is a little multibases converting and calculation
 
 facilities library.
                                         
 libHOBDCalc (C) 2014 Brüggemann Eddie (Alias mrcyberfighter).                         
                                                                                
 This file is part of libHOBDCalc.                                 
 
 libHOBDCalc is free software: you can redistribute it and/or modify
 
 it under the terms of the GNU General Public License as published by           
 
 the Free Software Foundation, either version 3 of the License, or              
 
 (at your option) any later version.                                            
                                                                                
 libHOBDCalc is distributed in the hope that it will be useful,      
 
 but WITHOUT ANY WARRANTY; without even the implied warranty of                  
 
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                   
 
 GNU General Public License for more details.                                   
                                                                                
 You should have received a copy of the GNU General Public License              
 
 along with libHOBDCalc. If not, see <http://www.gnu.org/licenses/>
                                                                                


Copyright (C) GPLv3 2014 Brüggemann Eddie <mrcyberfighter@gmail.com>.
