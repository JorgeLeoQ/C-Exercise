/* Set a new locale */

#include <stdio.h>
#include <locale.h>

int main( void ) {
    printf ("locale is %s\n",setlocale (LC_ALL,NULL));
    
    printf ("àèìòù\n");
    printf("%f\n", 10.2f);
    
    setlocale (LC_ALL,"it_IT");
    
    printf ("locale is %s\n",setlocale (LC_ALL,NULL));
    printf ("àèìòù\n");
    printf("%f\n", 10.2f);
    
    return 0;
}
