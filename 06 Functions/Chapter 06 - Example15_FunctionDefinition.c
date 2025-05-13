/* Creating and using a programmer-defined function */
#include <stdio.h>

int square( int y ); /* function prototype */

int main( void ) {
   int x; /* counter */

   /* loop 10 times and calculate and output square of x each time */
   for ( x = 1; x <= 10; x++ ) {
      int val = square( x );
      printf( "%d  ", val ); /* function call */
   }

   printf( "\n" );

   return 0;
}

/* square function definition returns square of parameter */
/* y is a copy of argument to function */
int square( int y ) {
   int result = y * y; /* returns square of y as an int */
   return result;
}
