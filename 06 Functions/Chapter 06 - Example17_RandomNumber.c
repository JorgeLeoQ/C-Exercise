/* Shifted, scaled integers produced by 1 + rand() */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void ) {
   srand(time(NULL));
   int i; /* counter */
   
   /* loop 20 times */
   for ( i = 1; i <= 20; i++ ) {
  
      /* pick random number from 1 to 6 and output it */
      int x = rand();
      printf( "%10d", 1 + ( x % 6 ) );

      /* if counter is divisible by 5, begin new line of output */
      if ( i % 5 == 0 ) {
         printf( "\n" );
      }
   }

   return 0;
}
