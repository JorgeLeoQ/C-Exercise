/* The name of an array is the same as &array[ 0 ] */
#include <stdio.h>

int main( void ) {
   char array[ 5 ]; /* define an array of size 5 */

   printf( "    array = %p\n&array[2] = %p\n   &array = %p\n",
      array, &array[ 2 ], &array );

   return 0; 
}

