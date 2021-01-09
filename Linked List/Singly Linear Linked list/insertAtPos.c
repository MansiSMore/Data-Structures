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

//Inserting element in the linkedlist at particular position
void insertAtPos(struct node** first , int val , int pos)
{
	struct node* temp = (*first) , *newN = createNewnode(val);
	int cnt = count(*first), i = 1;
	
	//Inserting element at first position
	if(pos == 1)
	{
		insertAtFirst(first,val);
	}
	else if(pos == cnt + 1)
	{
		insertAtLast(first,val);
	}
	else if(pos > 1 && pos < cnt+1)
	{
		while(i != (pos-1))
		{
			temp = temp -> next;
			i++;
		}
		
		newN -> next = temp -> next;
		temp -> next = newN;
		printf("Element inserted successfully...!!\n");
	}
	else
	{
		printf("Wrong position...!\n\n");
	}
}

