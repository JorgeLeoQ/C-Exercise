/* Using the break statement in a for statement */
#include <stdio.h>

int main( void ) {
   int x; /* counter */
   
   /* loop 10 times */
   for ( x = 1; x <= 10; x++ ) {

      /* if x is 5, terminate loop */
      if ( x == 5 ) {
         break; /* break loop only if x is 5 */
      }

      printf( "%d ", x ); /* display value of x */
   }
   
   printf( "\nBroke out of loop at x == %d\n", x );
   return 0;
} 