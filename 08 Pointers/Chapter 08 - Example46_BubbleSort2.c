/* This program puts values into an array, sorts the values into
   ascending order, and prints the resulting array. */

#include <stdio.h>
#define SIZE 10

void bubbleSort( int *list, const int size );
void swap( int *element1Ptr, int *element2Ptr );

int main( void )
{
   int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
   
   int i; /* counter */

   printf( "Data items in original order\n" );
   /* loop through array a */
   for ( i = 0; i < SIZE; i++ ) {
      printf( "%4d", a[ i ] );
   }

   bubbleSort( a, SIZE ); /* sort the array */

   printf( "\nData items in ascending order\n" );
   /* loop through array a */
   for ( i = 0; i < SIZE; i++ ) {
      printf( "%4d", a[ i ] );   
   }
   
   printf( "\n" );
   
   return 0;
}

/* sort an array of integers using bubble sort algorithm */
void bubbleSort( int *list, const int size )
{
   int pass; /* pass counter */
   int j; /* comparison counter */
   
   /* loop to control passes */
   for ( pass = 0; pass < size - 1; pass++ ) {

      /* loop to control comparisons during each pass */
      for ( j = 0; j < size - 1; j++ ) {

         /* swap adjacent elements if they are out of order */
         if ( list[ j ] > list[ j + 1 ] ) {
            swap( &list[ j ], &list[ j + 1 ] );
         }
      }
   }
}

/* swap values at memory locations to which element1Ptr and element2Ptr point */
void swap( int *element1Ptr, int *element2Ptr )
{
   int hold = *element1Ptr;
   *element1Ptr = *element2Ptr;
   *element2Ptr = hold;
}













