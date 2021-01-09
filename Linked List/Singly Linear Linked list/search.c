#include "singlyLinkedList.h"

//Search element from linked list
bool Search(struct node* first, int val)
{
	while(first != NULL)
	{
		if(first-> data == val)
		{
			return TRUE;
		}
		first = first -> next;
	}
	return FALSE;
}

