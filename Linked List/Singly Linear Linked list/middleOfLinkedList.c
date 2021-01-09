#include "singlyLinkedList.h"

//Counting elements from LinkedList
int count(struct node *first)
{
	int cnt = 0;
	while(first != NULL)
	{
		cnt++;
		first = first -> next;
	}
	return cnt;
}

//Middle of the linked list
void middleOfLinkedList(struct node *first)
{
	struct node *temp1 = first, *temp2 = first;
	if(count(first) == 1)
		printf("%d\n",first -> data);
	else
	{
		while(temp2 -> next != NULL && temp2 -> next -> next != NULL)
		{
			temp1 = temp1 -> next;
			temp2 = temp2 -> next -> next;
		}
		printf("%d\n",temp1 -> data);		
	}
}
