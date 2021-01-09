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

//2.Display the elements from LinkedList
void display(struct node*);

//3.Search element from linked list
bool Search(struct node*, int);

//4.Inserting element in the linkedlist at first position
void insertAtFirst(struct node**, int);

//5.Inserting element in the linkedlist at Last position
void insertAtLast(struct node**, int);

//6.Inserting element in the linkedlist at particular position
void insertAtPos(struct node**, int, int);

//7.Delete element position wise
void deleteByPosition(struct node**, int);

//8.Delete elements by their value
bool deleteByValue(struct node**, int);

//9.Printing nth last node
void NthLastNode(struct node*,int);

//10.Middle of the linked list
void middleOfLinkedList(struct node *);

//11.Count the frequency of given number 
int countFrequency(struct node*, int);

