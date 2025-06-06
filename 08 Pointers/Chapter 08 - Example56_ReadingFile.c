/* Reading and printing a sequential file */
#include <stdio.h>
#include <unistd.h>

int main( void )
{ 
   int account; /* account number */
   char name[ 30 ]; /* account name */
   double balance; /* account balance */

   char cwd[1024];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
   }

   FILE *cfPtr; /* cfPtr = clients.dat file pointer */

   /* fopen opens file; exits program if file cannot be opened */ 
   if ( ( cfPtr = fopen( "clients.dat", "r" ) ) == NULL ) {
      printf( "File could not be opened\n" );
   }
   else { /* read account, name and balance from file */
      printf( "%-10s%-13s%s\n", "Account", "Name", "Balance" );
      fscanf( cfPtr, "%d%s%lf", &account, name, &balance );

      /* while not end of file */
      while ( !feof( cfPtr ) ) { 
         printf( "%-10d%-13s%7.2f\n", account, name, balance );
         fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
      }

      fclose( cfPtr ); /* fclose closes the file */
   }

   return 0;
}
