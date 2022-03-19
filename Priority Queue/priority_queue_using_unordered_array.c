//Priority queue using Array (Unordered Array).
//We insert the item at the end of the queue.While inserting, we do not maintain the order.
//In unordered array deletion takes O(n) time complexity because it search for the element in Queue for the deletion and enqueue takes o(1) time complexity.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define bool int
#define TRUE 1
#define FALSE 0

//Structure for the elements in the priority queue
struct node
{
	int ele;
    int priority;
};

//Priority queue of 100 elements.
struct node arr[MAX];

//index
int ind = -1;

//isFull : queue is full or not.
bool isFull()
{
	return ind == MAX - 1;
}

//isEmpty : queue is empty or not.
bool isEmpty()
{
    return ind == -1;
}

//display : display the queue.
void display()
{
	//If queue is Empty, it's underflow.
	if(isEmpty())
	{
		printf("\nERROR: Queue is empty\n");
	}
	else
	{
		printf("\nElement		   Priority\n");
		for(int i = 0; i <= ind; i++) 
		{
	    	printf("%d			%d\n",arr[i].ele, arr[i].priority);
		} 
	}
}

//topElement : get the highest priority element's index in the queue without removing it from the queue.
int topElement()
{
	int top = INT_MIN, j = -1;
		
	for(int i = 0; i <= ind; i++)
	{
		// If priority is same choose the element with the highest value
		if(top == arr[i].priority && j > -1 && arr[j].ele < arr[i].ele)
		{
			top = arr[i].priority;
			j = i;
		}
		else if(top < arr[i].priority)
		{
			top = arr[i].priority;
			j = i;
		}
	}
		
	return j;
}

//enqueue : inserts the element at the end of queue.
void enqueue(int ele, int pr)
{
	if(!isFull())
	{
		ind++;

        //Assign the values.
		arr[ind].ele = ele;
        arr[ind].priority = pr;
	}
	printf("Element inserted successfully..!\n");
}

//dequeue : removes the element with the highest priority from the queue.
void dequeue()
{
	//If queue is Empty, it's underflow.
	if(isEmpty())
	{
		printf("\nERROR: Queue is empty\n");
	}
	else
	{
		//Getting the index of highest priority element.
		int top = topElement();
		
		//After getting the index of highest priority element, we need to move all the items after it one step to the left. 
		for(int i = top; i < ind; i++)
		{
			arr[i] = arr[i + 1];
		}
		ind--;
		
		printf("Element removed successfully..!\n");
	}
}



int main()
{
	printf("**************Priority Queue Using Array (Unordered array)**************\n\n");
	int ele = 0, pr = 0, no = 0;
	while(1)
	{
		printf("\n1.Insert an element into queue\n\n2.Delete an element from queue\n\n3.Get highest priority element (top/peek)\n\n4.Display the elements\n\n0.Exit\n");
		printf("\nEnter your choice :\n");
		scanf("%d",&no);
		
		switch(no)
		{
			case 1:
					printf("\nEnter the element with priority : \n");
					scanf("%d%d", &ele, &pr);
					enqueue(ele, pr);
					break;
					
			case 2:
					dequeue();
					break;
					
			case 3:
					if(topElement() == -1)
						printf("\nERROR: Queue is empty\n");
					else
						printf("\nElement with highest priority : %d\n", arr[topElement()].ele);
					break;
			
			case 4:
					display();
					break;
			
			case 0:
					exit(0);
					
			default:
					printf("Wrong choice...!\n\n");
		}
	}
	
	return 0;
}
