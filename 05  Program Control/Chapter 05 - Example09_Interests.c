/* Calculating compound interest */
#include <stdio.h>
#include <math.h>  

int main( void ) {
   double amount; /* amount on deposit */
   double principal = 1000.0; /* starting principal */
   double rate = .05; /* annual interest rate */
   int year; /* year counter */

   /* output table column head */
   printf( "%4s%21s\n", "Year", "Amount on deposit" );

   /* calculate amount on deposit for each of ten years */
   for ( year = 1; year <= 10; year++ ) {

      /* calculate new amount for specified year */
      amount = principal * pow( 1.0 + rate, year );

      /* output one table row */
      printf( "%4d%21.2f\n", year, amount );   
   }

   return 0;
}
