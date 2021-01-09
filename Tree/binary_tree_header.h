//Binary Tree in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 


//Structure of binary tree
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

//typedefs
typedef struct tree tobj;
typedef struct tree *TNODE;
typedef struct tree **TTNODE;


//Creating a new node
TNODE createNewnode(int data)
{
	TNODE newN = (TNODE)malloc(sizeof(TNODE));
	newN -> data = data;
	newN -> left = NULL;
	newN -> right = NULL;
	
	return newN;
}

//Function Declarations
//1. Inserting a node in a tree
void insertNode(TTNODE , int);

//2. Searching for an value from a tree
bool searchNode(TNODE, int);

//3. Count the number of nodes from a tree.
int count(TNODE);

//4. Preorder Traversal :: Data - Light - Right(D - L - R).
void preorder(TNODE);

//5. Inorder Traversal :: Left - Data - Right(L - D - R).
void inorder(TNODE);

//6. Postorder Traversal :: Light - Right - Data(L - R - D).
void postorder(TNODE);
