/* dynamic stack program */
#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
struct stackNode 
{   
  int data; /* define data as an int */
  struct stackNode *nextPtr; /* stackNode pointer */
};

typedef struct stackNode StackNode; /* synonym for struct stackNode */
typedef StackNode *StackNodePtr; /* synonym for StackNode* */

/* prototypes */
void push( StackNodePtr *topPtr, int info );
int pop( StackNodePtr *topPtr );
int isEmpty( StackNodePtr topPtr );
void printStack( StackNodePtr currentPtr );
void instructions( void );

/* function main begins program execution */
int main( void )
{ 
  StackNodePtr stackPtr = NULL; /* points to stack top */
  int choice; /* user's menu choice */
  int value; /* int input by user */
 
  instructions(); /* display the menu */
  printf( "? " );
  scanf( "%d", &choice );

  /* while user does not enter 3 */
  while ( choice != 3 ) { 
    switch ( choice ) { 
      /* push value onto stack */
      case 1:      
        printf( "Enter an integer: " );
        scanf( "%d", &value );
        push( &stackPtr, value );
        printStack( stackPtr );
        break;
      /* pop value off stack */
      case 2:      
        /* if stack is not empty */
        if ( !isEmpty( stackPtr ) ) {
          printf( "The popped value is %d.\n", pop( &stackPtr ) );
        }
		printStack( stackPtr );
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
  printf( "Enter choice:\n"
     "1 to push a value on the stack\n"
     "2 to pop a value off the stack\n"
     "3 to end program\n" );
}

/* Insert a node at the stack top */
void push( StackNodePtr *topPtr, int info )
{ 
  StackNodePtr newPtr; /* pointer to new node */

  newPtr = malloc( sizeof( StackNode ) );

  /* insert the node at stack top */
  if ( newPtr != NULL ) {   
    newPtr->data = info;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
  }
  else { /* no space available */
    printf( "%d not inserted. No memory available.\n", info );
  }
}

/* Remove a node from the stack top */
int pop( StackNodePtr *topPtr )
{ 
  StackNodePtr tempPtr; /* temporary node pointer */
  int popValue; /* node value */

  tempPtr = *topPtr;
  popValue = ( *topPtr )->data;
  *topPtr = ( *topPtr )->nextPtr;
  free( tempPtr );
  return popValue;
} 

/* Print the stack */
void printStack( StackNodePtr currentPtr )
{ 
  /* if stack is empty */
  if ( currentPtr == NULL ) {
    printf( "The stack is empty.\n\n" );
  }
  else { 
    printf( "The stack is:\n" );
	/* while not the end of the stack */
    while ( currentPtr != NULL ) { 
      printf( "%d --> ", currentPtr->data );
      currentPtr = currentPtr->nextPtr;
    }
    printf( "NULL\n\n" );
  }
}

/* Return 1 if the stack is empty, 0 otherwise */
int isEmpty( StackNodePtr topPtr )
{ 
  return topPtr == NULL;
}
