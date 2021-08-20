#include "binary_search_tree_header.h"

//Finding minimum element from a tree
int minimumElement(TNODE head)
{
	if(head == NULL)
		return INT_MAX;
	int min = INT_MAX;
	while(head != NULL)
	{
		if(head -> data < min)
			min = head -> data;
		head = head -> left;
	}
	
	return min;
}
