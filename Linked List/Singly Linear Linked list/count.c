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

