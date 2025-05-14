/* Treating character arrays as strings */
#include <stdio.h>

int main( void ) {
   char string2[] = {'n','o','s','t','r','i','n','g'};
   char s1[] = "1234";

   string2[0] = 'x';
   printf("%s\n", string2);
   printf("%s\n", s1);
   return 0;
}
