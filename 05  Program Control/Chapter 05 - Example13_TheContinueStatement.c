/* Using the continue statement in a for statement */
#include <stdio.h>

int main( void ) {
   int x; /* counter */

   /* loop 10 times */
   for ( x = 1; x <= 10; x++ ) {

      /* if x is 5, continue with next iteration of loop */
      if ( x == 5 ) {   
         continue; /* skip remaining code in loop body */
      }

      printf( "%d ", x ); /* display value of x */
   }
   
   printf( "\nUsed continue to skip printing the value 5\n" );
   return 0;
}
