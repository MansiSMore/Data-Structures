#include "binary_search_tree_header.h"

//Counting all internal nodes from a tree.
int countInternalNodes(TNODE head)
{
	if(head == NULL)
	{
		return 0;
	}
	
	//Leaf nodes.
	if(head -> left == NULL && head -> right == NULL)
	{
		return 0;
	}
	
	//The number of internal nodes in the left sub-tree + the number of inner nodes in the right sub-tree, plus 1 for root node.
	return countInternalNodes(head -> left) + countInternalNodes(head -> right) + 1;
}
