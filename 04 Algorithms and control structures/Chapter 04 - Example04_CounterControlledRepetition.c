/* Class average program with counter-controlled repetition */
#include <stdio.h>
#define NUMSTUDENTS 10

int main( void ) {

   int counter; /* number of grade to be entered next */
   int grade; /* grade value */
   int total; /* sum of grades input by user */
   float average = 0; /* average of grades */
   
   /* initialization phase */
   total = 0; /* initialize total */
   counter = 0; /* initialize loop counter */
   
   /* processing phase */
   while ( counter < NUMSTUDENTS ) { /* loop 10 times */
      printf( "Enter grade: " ); /* prompt for input */
      scanf( "%d", &grade ); /* read grade from user */
      total = total + grade; /* add grade to total */
      counter = counter + 1; /* increment counter */
   } /* end while */
   
   /* termination phase */
   average = (float)total / NUMSTUDENTS; /* integer division */

   printf( "Class average is %f\n", average ); /* display result */
   return 0; /* indicate program ended successfully */
} 
