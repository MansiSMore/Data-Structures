#include "binary_search_tree_header.h"

//The height of the binary search tree is the longest path from root node to any leaf node in the tree.
int heightOfTree(TNODE head)
{
	int lheight = 0, rheight = 0;	
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		lheight += sizeOfTree(head -> left);
		rheight += sizeOfTree(head -> right);
		
		if(lheight > rheight)
			return lheight;
		else
			return rheight;
	}
}
