/* Applying sizeof to an array name returns 
   the number of bytes in the array. */
#include <stdio.h>

size_t getSize( float *ptr ); /* prototype */

int main( void )
{
   char array[ 20 ]; /* create array */

   printf( "The number of bytes in the array is %d"
           "\nThe number of element is %d\n single element %d ",
           sizeof( array ), sizeof(array)/sizeof(array[0]),
           sizeof(array[0]));
   return 0; 
} 
