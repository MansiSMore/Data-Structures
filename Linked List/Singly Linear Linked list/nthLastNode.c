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


//Printing nth last node
void NthLastNode(struct node *first, int n)
{
	struct node *temp1 = first , *temp2 = first;
	int cnt = 0;
	if(first == NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	else if(count(first) < n)
	{
		printf("Linked list doesn't contain that much element..!\n",n);
		return;
	}
	else
	{
		while(temp1 -> next != NULL)
		{
			cnt++;
			if(cnt >= n)
			{
				temp2 = temp2 -> next;
				//printf("temp2 -> data :: %d\n",temp2->data);
			}
			temp1 = temp1 -> next;
			//printf("cnt :: %d\n",cnt);
		}
		printf("%dth node from Last : %d\n",n,temp2->data);
	}
		
}

