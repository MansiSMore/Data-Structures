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

//Delete element position wise
void deleteByPosition(struct node** first, int pos)
{
	struct node* temp = (*first) , *t2 = NULL;
	int cnt = count(*first), i = 1;
	//If the linked list is empty
	if(*first == NULL)
	{
		printf("LinkedList is Empty...!\n");
	}
	else
	{
		//Delete the first element
		if(pos == 1)
		{
			(*first) = temp -> next;
			free(temp);
			printf("Node Deleted Successfully..!!\n");
		}
		//delete the last element
		else if(pos == cnt)
		{
			while(i != (pos-1))
			{
				i++;
				temp = temp -> next;
			}
			free(temp -> next);
			temp -> next = NULL;
			printf("Node Deleted Successfully..!!\n");
		}
		//delete the particular element
		else if(pos > 1 && pos < cnt)
		{
			while(i != (pos-1))
			{
				i++;
				temp = temp -> next;
			}
			t2 = temp -> next;
			temp -> next = t2 -> next;
			free(t2);
			printf("Node Deleted Successfully..!!\n");
		}
		else
		{
			printf("Wrong POSITION....!!\n");
		}
	}
}

