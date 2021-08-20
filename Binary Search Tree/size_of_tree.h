#include "binary_search_tree_header.h"

//Size of a tree is the number of elements present in the tree.
int sizeOfTree(TNODE head)
{	
	if(head == NULL)
	{
		return 0;
	}
	return sizeOfTree(head -> left)+sizeOfTree(head -> right)+1;
}

