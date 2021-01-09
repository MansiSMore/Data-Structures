#include "binary_tree_header.h"

//Inorder Traversal :: Left - Data - Right(L - D - R).
void inorder(TNODE head)
{	
	//Traverse left subtree -> Visit data -> Traverse right subtree
	if(head != NULL)
	{
		inorder(head -> left);
		printf("%d\n", head -> data);
		inorder(head -> right);
	}
}

