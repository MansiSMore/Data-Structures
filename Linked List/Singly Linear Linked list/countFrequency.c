#include "singlyLinkedList.h"

//Count the frequency of given number 
int countFrequency(struct node* first, int val)
{
	int cnt = 0;	
	while(first != NULL)
	{
		if(first-> data == val)
		{
			cnt++;
		}
		first = first -> next;
	}
	return cnt;
}

