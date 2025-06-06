/* Credit inquiry program */
#include <stdio.h>

/* function main begins program execution */
int main( void )
{
    int request; /* request number */
    int account; /* account number */
    double balance; /* account balance */
    char name[ 30 ]; /* account name */
    FILE *cfPtr; /* clients.dat file pointer */
    
    /* fopen opens the file; exits program if file cannot be opened */
    if ( ( cfPtr = fopen( "clients.dat", "r" ) ) == NULL ) {
        printf( "File could not be opened\n" );
    }
    else {
        
        /* display request options */
        printf( "Enter request\n"
               " 1 - List accounts with zero balances\n"
               " 2 - List accounts with credit balances\n"
               " 3 - List accounts with debit balances\n"
               " 4 - End of run\n? " );
        scanf( "%d", &request );
        
        /* process user's request */
        while ( request != 4 ) {
            
            /* read account, name and balance from file */
            fscanf( cfPtr, "%d%s%lf", &account, name, &balance );
            
            switch ( request ) {
                    
                case 1:
                    printf( "\nAccounts with zero balances:\n" );
                    
                    /* read file contents (until eof) */
                    while ( !feof( cfPtr ) ) {
                        
                        if ( balance == 0 ) {
                            printf( "%-10d%-13s%7.2f\n",
                                   account, name, balance );
                        }
                        
                        /* read account, name and balance from file */
                        fscanf( cfPtr, "%d%s%lf",
                               &account, name, &balance );
                    }
                    
                    break;
                    
                case 2:
                    printf( "\nAccounts with credit balances:\n" );
                    
                    /* read file contents (until eof) */
                    while ( !feof( cfPtr ) ) {
                        
                        if ( balance < 0 ) {
                            printf( "%-10d%-13s%7.2f\n",
                                   account, name, balance );
                        }
                        
                        /* read account, name and balance from file */
                        fscanf( cfPtr, "%d%s%lf",
                               &account, name, &balance );
                    }
                    
                    break;
                    
                case 3:
                    printf( "\nAccounts with debit balances:\n" );
                    
                    /* read file contents (until eof) */
                    while ( !feof( cfPtr ) ) {
                        
                        if ( balance > 0 ) {
                            printf( "%-10d%-13s%7.2f\n",
                                   account, name, balance );
                        }
                        
                        /* read account, name and balance from file */
                        fscanf( cfPtr, "%d%s%lf", 
                               &account, name, &balance );
                    }
                    
                    break;           
                    
            }
            
            rewind( cfPtr ); /* return cfPtr to beginning of file */
            
            printf( "\n? " );
            scanf( "%d", &request );
        }
        
        printf( "End of run.\n" );
        fclose( cfPtr ); /* fclose closes the file */
    } 
    
    return 0;
} 

