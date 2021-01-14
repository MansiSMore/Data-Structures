#include "binary_search_tree_header.h"

//Counting all leaf nodes from a tree.
int countLeafNodes(TNODE head)
{
	if(head == NULL)
	{
		return 0;
	}
	
	//Leaf Nodes.
	if(head -> left == NULL && head -> right == NULL)
	{
		return 1;
	}
	
	return countLeafNodes(head -> left) + countLeafNodes(head -> right);
}
