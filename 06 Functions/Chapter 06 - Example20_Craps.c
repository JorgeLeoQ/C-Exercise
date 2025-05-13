/* Craps */
#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* contains prototype for function time */

/* enumeration constants represent game status */
enum Status { CONTINUE, WON, LOST };

int rollDice( void ); /* function prototype */

int main( void ) {
   int sum; /* sum of rolled dice */
   int myPoint; /* point earned */

   enum Status gameStatus; /* can contain CONTINUE, WON, or LOST */

   /* randomize random number generator using current time */
   srand( (unsigned int) time( NULL ) );

   sum = rollDice(); /* first roll of the dice */

   /* determine game status based on sum of dice */
   switch( sum ) {
      /* win on first roll */
      case 7: 
      case 11:          
         gameStatus = WON;
         break;

      /* lose on first roll */
      case 2: 
      case 3: 
      case 12:  
         gameStatus = LOST;
         break;

      /* remember point */
      default:                  
         gameStatus = CONTINUE;
         myPoint = sum;
         printf( "Point is %d\n", myPoint );
         break;
   } 

   /* while game not complete */
   while ( gameStatus == CONTINUE ) {    
      sum = rollDice(); /* roll dice again */

      /* determine game status */
      if ( sum == myPoint ) { /* win by making point */
         gameStatus = WON; /* game over, player won */
      } 
      else {
         if ( sum == 7 ) { /* lose by rolling 7 */
            gameStatus = LOST; /* game over, player lost */
         } 
      } 
   } 

   /* display won or lost message */
   if ( gameStatus == WON ) { /* did player win? */
      printf( "Player wins\n" );
   } 
   else { /* player lost */ 
      printf( "Player loses\n" );
   } 

   return 0;
}

/* roll dice, calculate sum and display results */
int rollDice( void ) {
   int die1; /* first die */
   int die2; /* second die */
   int workSum; /* sum of dice */

   die1 = 1 + ( rand() % 6 ); /* pick random die1 value */
   die2 = 1 + ( rand() % 6 ); /* pick random die2 value */
   workSum = die1 + die2; /* sum die1 and die2 */

   /* display results of this roll */
   printf( "Player rolled %d + %d = %d\n", die1, die2, workSum );
   return workSum;
}
