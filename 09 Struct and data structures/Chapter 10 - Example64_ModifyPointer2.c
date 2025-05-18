#include <stdio.h>

void f(int** ptr, int *j);

int main( void )
{
   int i = 4;
   int j = 5;

   int *ptr = &i;
	
   printf("i=%i j=%i ptr=%p\n", i, j, ptr);

   f(&ptr, &j);

   printf("i=%i j=%i ptr=%p\n", i, j, ptr);

   return 0;
}

void f(int** ptr, int *j)
{
	**ptr = 6;

	*ptr = j;

	**ptr = 7;
}
