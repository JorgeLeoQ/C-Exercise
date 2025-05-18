/* Create a binary tree and traverse it 
   preorder, inorder, and postorder */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* self-referential structure */
struct treeNode 
{ 
   struct treeNode *leftPtr; /* pointer to left subtree */
   int data; /* node value */
   struct treeNode *rightPtr; /* pointer to right subtree */
};

typedef struct treeNode TreeNode; /* synonym for struct treeNode */
typedef TreeNode *TreeNodePtr; /* synonym for TreeNode* */

/* prototypes */
void insertNode( TreeNodePtr *treePtr, int value );
void traverse( TreeNodePtr treePtr );

/* function main begins program execution */
int main( void )
{ 
  int i; /* counter to loop from 1-10 */
  int item; /* variable to hold random values */
  TreeNodePtr rootPtr = NULL; /* tree initially empty */

  srand( time( NULL ) ); 
  printf( "The numbers being placed in the tree are:\n" );

  /* insert random values between 0 and 14 in the tree */
  for ( i = 1; i <= 10; i++ ) { 
      item = rand() % 15;
      printf( "%3d", item );
      insertNode( &rootPtr, item );
  }

  /* traverse the tree inOrder */
  printf( "\n\nThe inOrder traversal is:\n" );
  traverse( rootPtr );

} 

/* insert node into tree */
void insertNode( TreeNodePtr *treePtr, int value )
{ 
  /* if tree is empty */
  if ( *treePtr == NULL ) {   
     *treePtr = (TreeNode *)malloc( sizeof( TreeNode ) );

     /* if memory was allocated then assign data */
     if ( *treePtr != NULL ) { 
        ( *treePtr )->data = value;
        ( *treePtr )->leftPtr = NULL;
        ( *treePtr )->rightPtr = NULL;
     }
     else {
        printf( "%d not inserted. No memory available.\n", value );
     }
  }  
  else { /* tree is not empty */
    /* data to insert is less than data in current node */
    if ( value < ( *treePtr )->data ) {
      insertNode( &( ( *treePtr )->leftPtr ), value );
    }

    /* data to insert is greater than data in current node */
    else if ( value > ( *treePtr )->data ) {
      insertNode( &( ( *treePtr )->rightPtr ), value );
    }
	else { /* duplicate data value ignored */
      printf( "dup" );
    }
  }
}

/* inorder traversal of tree */
void traverse( TreeNodePtr treePtr )
{ 
  /* if tree is not empty then traverse */
  if ( treePtr != NULL ) { 
     traverse( treePtr->leftPtr );
     printf( "%3d", treePtr->data );
     traverse( treePtr->rightPtr );
  }
}


