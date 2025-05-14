/* initializing an array */
#include <stdio.h>
 
int main( void ) {
   int n[10]; /* n is an array of 10 integers */
   int i; /* counter */
   
   /* initialize elements of array n to 0 */
   for ( i = 0; i < 10; i++ ) {
      n[i] = 0; /* set element at location i to 0 */
   }
   
   printf( "%s%13s\n", "Element", "Value" );

   /* output contents of array n in tabular format */
   for ( i = 0; i < 10; i++ ) {
      printf( "%7d%13d\n", i, n[i] );
   }

   return 0; 
}



