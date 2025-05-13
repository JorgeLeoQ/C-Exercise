/* Addition program */
#include <stdio.h>

/* function main begins program execution */
int main( void )
{
   int integer1; /* first number to be input by user  */
   int integer2; /* second number to be input by user */
   int sum; /* variable in which sum will be stored */ 

   printf( "Enter first integer\n" ); /* prompt */
   scanf( "%i", &integer1 ); /* read an integer */

   printf( "Enter second integer\n" ); /* prompt */
   scanf( "%i", &integer2 ); /* read an integer */

   sum = integer1 + integer2; /* assign total to sum */

   printf( "Sum is %i\n", sum ); /* print sum */

   return 0; /* indicate that program ended successfully */
} /* end function main */
