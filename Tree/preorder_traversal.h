#include "binary_tree_header.h"

//Preorder Traversal :: Data - Light - Right(D - L - R).
void preorder(TNODE head)
{	
	//Visit data -> Traverse right subtree -> Traverse light subtree.
	if(head != NULL)
	{
		printf("%d\n", head -> data);
		preorder(head -> left);
		preorder(head -> right);
	}
}


