/* Double-subscripted array example */
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

int minimum( const int grades[][ EXAMS ], int pupils, int tests );
int maximum( const int grades[][ EXAMS ], int pupils, int tests );
double average( const int setOfGrades[], int tests );
void printArray( const int grades[][ EXAMS ], int pupils, int tests );

int main( void ) {
   int student; /* student counter */

   /* initialize student grades for three students (rows) */
   const int studentGrades[ STUDENTS ][ EXAMS ] =  
      { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };

   /* output array studentGrades */
   printf( "The array is:\n" );
   printArray( studentGrades, STUDENTS, EXAMS );

   /* determine smallest and largest grade values */
   printf( "\n\nLowest grade: %d\nHighest grade: %d\n",
      minimum( studentGrades, STUDENTS, EXAMS ),
      maximum( studentGrades, STUDENTS, EXAMS ) );

   /* calculate average grade for each student */
   for ( student = 0; student < STUDENTS; student++ ) {
      printf( "The average grade for student %d is %.2f\n", 
         student, average( studentGrades[ student ], EXAMS ) );
   }

   return 0;
}

/* Find the minimum grade */
int minimum( const int grades[][ EXAMS ], int pupils, int tests ) {
   int i; /* student counter */
   int j; /* exam counter */
   int lowGrade = 100; /* initialize to highest possible grade */

   /* loop through rows of grades */
   for ( i = 0; i < pupils; i++ ) {

      /* loop through columns of grades */
      for ( j = 0; j < tests; j++ ) {

         if ( grades[ i ][ j ] < lowGrade ) {
            lowGrade = grades[ i ][ j ];
         }
      }
   }

   return lowGrade; /* return minimum grade */ 
} 

/* Find the maximum grade */
int maximum( const int grades[][ EXAMS ], int pupils, int tests ) {
   int i; /* student counter */
   int j; /* exam counter */
   int highGrade = 0; /* initialize to lowest possible grade */

   /* loop through rows of grades */
   for ( i = 0; i < pupils; i++ ) {

      /* loop through columns of grades */
      for ( j = 0; j < tests; j++ ) {

         if ( grades[ i ][ j ] > highGrade ) {
            highGrade = grades[ i ][ j ];
         } 
      } 
   } 

   return highGrade; /* return maximum grade */
} 

/* Determine the average grade for a particular student */
double average( const int setOfGrades[], int tests ) {
   int i; /* exam counter */
   int total = 0; /* sum of test grades */

   /* total all grades for one student */
   for ( i = 0; i < tests; i++ ) {
      total += setOfGrades[ i ];
   }

   return ( double ) total / tests; /* average */
}

/* Print the array */
void printArray( const int grades[][ EXAMS ], int pupils, int tests ) {
   int i; /* student counter */
   int j; /* exam counter */

   /* output column heads */
   printf( "                 [0]  [1]  [2]  [3]" );

   /* output grades in tabular format */
   for ( i = 0; i < pupils; i++ ) {

      /* output label for row */
      printf( "\nstudentGrades[%d] ", i );

      /* output grades for one student */
      for ( j = 0; j < tests; j++ ) {
         printf( "%-5d", grades[ i ][ j ] );
      } 
   } 
}
