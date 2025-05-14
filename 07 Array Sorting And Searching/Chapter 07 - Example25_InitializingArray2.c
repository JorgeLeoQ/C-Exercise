/* Initializing an array with a initializer list */
#include <stdio.h>

int main( void ) {
   /* use initializer list to initialize array n */
   int n[10] ;
   int i; /* counter */
   
   printf( "%s%13s\n", "Element", "Value" );
   
   /* output contents of array in tabular format */
   for ( i = 0; i < 10; i++ ) {
      printf( "%7d%13d\n", i, n[ i ] );
   } 

   return 0; 
}

