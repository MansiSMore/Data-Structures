#include "binary_tree_header.h"

//Searching for an value from a tree
bool searchNode(TNODE head, int data)
{
	if(head == NULL)
		return false;
	while(head != NULL)
	{
		//If data of head is equal to given data, then return true.
		if(head -> data == data)
		{
			return true;
		}
		//If the given value is less than value pointed by the current head, then go to left of head and search again. 
		else if(head -> data > data)
		{
			head = head -> left;
		}
		//If the given value is greater than value pointed by the current temp, then go to right of head and search again. 
		else
		{
			head = head -> right;
		}
		
	}
	return false;
}

