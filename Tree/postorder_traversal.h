#include "binary_tree_header.h"

//Postorder Traversal :: Light - Right - Data(L - R - D).
void postorder(TNODE head)
{	
	//Traverse light subtree -> Visit data -> Traverse right subtree.
	if(head != NULL)
	{
		postorder(head -> left);
		postorder(head -> right);
		printf("%d\n", head -> data);
		
	}
}

