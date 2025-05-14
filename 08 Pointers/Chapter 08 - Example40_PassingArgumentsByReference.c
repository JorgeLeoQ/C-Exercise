/* Cube a variable using call-by-value */
#include <stdio.h>

int cubeByValue( int n );
void cubeByReference( int *nPtr );

int main( void )
{
   int number = 5; /* initialize number */
   printf( "The original value of number is %d", number );
   /* pass number by value to cubeByValue */
   number = cubeByValue( number );
   printf( "\nThe new value of number is %d\n", number );

   number = 5; /* initialize number */
   printf( "The original value of number is %d", number );
   /* pass address of number to cubeByReference */
   cubeByReference( &number );
   printf( "\nThe new value of number is %d\n", number );

   return 0; 
}

/* calculate and return cube of integer argument */
int cubeByValue( int n )
{
   return n * n * n; /* cube local variable n and return result */
} 

/* calculate cube of *nPtr; modifies variable number in main */
void cubeByReference( int *nPtr )
{
   *nPtr = *nPtr * *nPtr * *nPtr; /* cube *nPtr */
}

