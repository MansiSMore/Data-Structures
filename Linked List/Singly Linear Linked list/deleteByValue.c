#include "singlyLinkedList.h"

//Delete elements by their value
bool deleteByValue(struct node** first , int val)
{
	struct node* temp1 = (*first) ,*temp2 = (*first)-> next ,*t2 = NULL;
	if(temp1 -> data == val)
	{
		t2 = (*first);
		(*first) = temp1 -> next;
		free(t2);
		return TRUE;	
	}
	else
	{
		while(temp2 != NULL)
		{
			if(temp2 -> data != val)
			{
				temp1 = temp1 -> next;
				temp2 = temp2 -> next;
			}
			else
				break;
		}
		if(temp2 != NULL)
		{
			t2 = temp1 -> next;
			temp1 -> next = temp1 -> next -> next;
			free(t2);
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	
}

