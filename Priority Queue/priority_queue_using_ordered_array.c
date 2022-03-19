//Priority queue using Array (Ordered Array).
//The element is inserted in such a way that the array remains ordered i.e. the largest priority is always in the end. 
// In ordered array enqueue operation takes O(n) time complexity because it enters elements in sorted order in queue. 
//And deletion takes O(1) time complexity. 

#include <stdio.h>
#include <stdlib.h>

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

//enqueue : insert the element at the appropriate position of the queue so that the priority order of queue is always ordered.
void enqueue(int ele, int pr)
{
	if(!isFull())
	{
		//If queue is Full, it's overflow.
		if(isFull())
		{
			printf("\nERROR: Queue is full\n");
		}
		else
		{
			ind++;
			int i = ind - 1;
			//Iterate the queue till i is greater than zero and current priority is less than ordered one, so that we 				//can find the correct place for given priority. 
        	while (i >= 0 && pr < arr[i].priority) 
        	{
                arr[i + 1].ele = arr[i].ele;
                arr[i + 1].priority = arr[i].priority;
                i--;
        	}
        	//Assign the values.
			arr[i + 1].ele = ele;
            arr[i + 1].priority = pr;
		}
		printf("Element inserted successfully..!\n");
	}
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
		//setting last index to default values.
		arr[ind].ele = 0;
		arr[ind].priority = 0;
		ind--;
		printf("Element removed successfully..!\n");
	}
}

//topElement : get the highest priority element in the queue without removing it from the queue.
int topElement()
{
	if(ind == -1)
		return -1;
	else
		return arr[ind].ele;
}

int main()
{
	printf("**************Priority Queue Using Array (ordered array)**************\n\n");
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
						printf("\nElement with highest priority : %d\n", topElement());
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
