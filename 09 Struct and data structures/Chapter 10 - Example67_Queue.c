/* Operating and maintaining a queue */
#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
struct queueNode 
{   
   char data; /* define data as a char */
   struct queueNode *nextPtr; /* queueNode pointer */
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

/* function prototypes */
void printQueue( QueueNodePtr currentPtr );
int isEmpty( QueueNodePtr headPtr );
char dequeue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr );
void enqueue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value );
void instructions( void );

/* function main begins program execution */
int main( void )
{ 
  QueueNodePtr headPtr = NULL; /* initialize headPtr */
  QueueNodePtr tailPtr = NULL; /* initialize tailPtr */
  int choice; /* user's menu choice */
  char item; /* char input by user */

  instructions(); /* display the menu */
  printf( "? " );
  scanf( "%d", &choice );

  /* while user does not enter 3 */
  while ( choice != 3 ) { 
    switch( choice ) { 
      /* enqueue value */
      case 1:
        printf( "Enter a character: " );
        scanf( "\n%c", &item );
        enqueue( &headPtr, &tailPtr, item );
        printQueue( headPtr );
        break;
      /* dequeue value */
      case 2:
        /* if queue is not empty */
        if ( !isEmpty( headPtr ) ) { 
          item = dequeue( &headPtr, &tailPtr );
          printf( "%c has been dequeued.\n", item );
        }
        printQueue( headPtr );
        break;
      default:
        printf( "Invalid choice.\n\n" );
        instructions();
        break;
    }
    printf( "? " );
    scanf( "%d", &choice );
  }
  printf( "End of run.\n" );
  return 0;
}

/* display program instructions to user */
void instructions( void )
{ 
 printf ( "Enter your choice:\n"
         "   1 to add an item to the queue\n"
         "   2 to remove an item from the queue\n"
         "   3 to end\n" );
} 

/* insert a node a queue tail */
void enqueue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value )
{ 
  QueueNodePtr newPtr; /* pointer to new node */

  newPtr = (QueueNode *)malloc( sizeof( QueueNode ) );

  if ( newPtr != NULL ) { /* is space available */ 
    newPtr->data = value;
    newPtr->nextPtr = NULL;

    /* if empty, insert node at head */
    if ( isEmpty( *headPtr ) ) {
      *headPtr = newPtr;
    }
    else {
      ( *tailPtr )->nextPtr = newPtr;
    }

    *tailPtr = newPtr;
  }
  else {
    printf( "%c not inserted. No memory available.\n", value );
  }
}

/* remove node from queue head */
char dequeue( QueueNodePtr *headPtr, QueueNodePtr *tailPtr )
{ 
  char value; /* node value */
  QueueNodePtr tempPtr; /* temporary node pointer */

  value = ( *headPtr )->data;
  tempPtr = *headPtr;
  *headPtr = ( *headPtr )->nextPtr;

  /* if queue is empty */
  if ( *headPtr == NULL ) {
    *tailPtr = NULL;
  }

  free( tempPtr );
  return value;
}

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( QueueNodePtr headPtr )
{ 
  return headPtr == NULL;
}

/* Print the queue */
void printQueue( QueueNodePtr currentPtr )
{ 
  /* if queue is empty */
  if ( currentPtr == NULL ) {
     printf( "Queue is empty.\n\n" );
  }
  else { 
    printf( "The queue is:\n" );

    /* while not end of queue */
    while ( currentPtr != NULL ) { 
      printf( "%c --> ", currentPtr->data );
      currentPtr = currentPtr->nextPtr;
    }

    printf( "NULL\n\n" );
  }
}
