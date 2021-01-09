#include "singlyLinkedList.h"

//Inserting element in the linkedlist at Last position
void insertAtLast(struct node** first , int val)
{
	struct node* newN = createNewnode(val) , *temp = (*first);
	
	//If the linked list is empty 
	if(*first == NULL)
	{
		*first = newN;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newN;
	}
	printf("Element inserted successfully...!!\n");
}

