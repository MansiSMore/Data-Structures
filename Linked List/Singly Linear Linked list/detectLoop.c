#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int bool;

//Structure of linkedlist
struct node
{
	int data;
	struct node *next;
};

//Creating NewNode
struct node* createNewnode(int data)
{
	struct node* newN = (struct node*)malloc(sizeof(struct node*));
	newN -> data = data;
	newN -> next = NULL;
	
	return newN;
}

void append(struct node** first , int val)
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
/*Approach 1
bool detectLoop(struct node* head)
{
    struct node *temp1 = head, *temp2 = head;
	while(temp1 != NULL && temp2 != NULL && temp2 -> next != NULL)
	{
		temp1 = temp1 -> next;
		temp2 = temp2 -> next -> next;
		if(temp1 == temp2)
		    return true;
	}
	return false;
}
*/

//Approach 2
bool detectLoop(struct node* first)
{
	struct node *temp1 = first, *temp2 = first;
	while(temp1 != NULL && temp2 != NULL && temp2->next != temp1)
	{
		temp1 = temp1 -> next;
		temp2 = temp2 -> next -> next;
	}
	if(temp1 == NULL || temp2 == NULL)
		return FALSE;	
	//if(temp2 -> next == temp1)
	else
	{
		return TRUE;
	}
	
}

int main()
{
	int i = 0 , cnt = 0 , ele = 0 , pos = 0 , no = 0 ;
	
	struct node* head = NULL;
	
	append(&head, 10);
	append(&head, 20);
	append(&head, 30);
	append(&head, 40);
	head->next->next->next->next = head;
	
	if(detectLoop(head))
		printf("Loop...!");
	else
		printf("No loop...!");	
	return 0;
} 
  
