#include "binary_search_tree_header.h"

//Finding maximum element from a tree
int maximumElement(TNODE head)
{
	if(head == NULL)
		return INT_MIN;
	int max = INT_MIN;
	while(head != NULL)
	{
		if(head -> data > max)
			max = head -> data;
		head = head -> right;
	}
	
	return max;
}
