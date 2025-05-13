/* Counter-controlled repetition with the for statement */
#include <stdio.h>

int main( void ) {
   int counter; /* define counter */

   /* initialization, repetition condition, and increment 
      are all included in the for statement header. */
   
   for ( counter = 1; counter <= 10; counter++ ) {
      printf( "%d\n", counter );
   }

   return 0;
}
