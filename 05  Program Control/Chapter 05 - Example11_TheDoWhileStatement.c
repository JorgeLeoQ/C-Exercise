/* Using the do/while repetition statement */
#include <stdio.h>

int main( void ) {
   int counter = 1; /* initialize counter */
   
   do {
      printf( "%d  ", counter ); /* display counter */
   } while ( ++counter <= 10 ); /* end do...while */

   return 0;
}
