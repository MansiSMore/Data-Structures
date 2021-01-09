//Singly Cicular Linked List

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

//Function Declarations

//1.Counting elements from LinkedList
int count(struct node*);

//2.Display LinkedList
void display(struct node*);

//3.Search element from linked list
bool Search(struct node*, int);

//4.Inserting element in the linkedlist at first position
void insertAtFirst(struct node**, int);

//5.Inserting element in the linkedlist at Last position
void insertAtLast(struct node**, int);

//6.Inserting element in the linkedlist at any position
void insertAtPos(struct node**, int, int);

//7.Delete element position wise
void deleteByPosition(struct node**, int);

//8.Delete elements by their value without using Search Function - TWO POINTER APPROACH 
bool deleteByValue(struct node**, int);
