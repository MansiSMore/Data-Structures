#include "singlyLinkedList.h"

//Inserting element in the linkedlist at first position
void insertAtFirst(struct node** first , int val)
{
	struct node* newN = createNewnode(val);
	
	//If the linked list is empty 
	if(*first == NULL)
	{
		*first = newN;
	}
	else
	{
		newN -> next = (*first);
		(*first) = newN;
	}
	printf("Element inserted successfully...!!\n");
}

