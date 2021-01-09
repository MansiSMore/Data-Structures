#include "singlyLinkedList.h"

//Display LinkedList
void display(struct node *first)
{
	//if(first == NULL)
		//printf("LinkedList is Empty...!!\n\n");
		//return;
	while(first != NULL)
	{
		printf("%d\t",first -> data);
		first = first -> next;
	}
	printf("\n");
}
