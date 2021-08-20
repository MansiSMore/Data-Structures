//Binary Search Tree in C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 


//Structure of binary tree
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

//typedefs
typedef struct tree tobj;
typedef struct tree *TNODE;
typedef struct tree **TTNODE;

//Function definitions

//Creating a new node
TNODE createNewnode(int data)
{
	TNODE newN = (TNODE)malloc(sizeof(TNODE));
	newN -> data = data;
	newN -> left = NULL;
	newN -> right = NULL;
	
	return newN;
}

//Inserting a node in a tree
void insertNode(TTNODE head, int data)
{
	TNODE temp = (*head), newNode = NULL;
	
	//Creating new node for new data
	newNode = createNewnode(data);
	
	//If tree is empty
	if(temp == NULL)
	{
		(*head) = newNode;
	}
	//If tree contains at least one element
	else
	{
		while(1)
		{
			//If you found Duplicate Node, then free the memory for allocated newNode.
			if(temp -> data == data)
			{
				free(newNode);
				break;
			}
			//If the given value is less than value pointed by the current temp, then go to left of the tree. 
			else if(temp -> data > data)
			{
				//Checking for empty left null, so that we can insert there.
				if(temp -> left == NULL)
				{
					temp -> left = newNode;
					break;
				}
				temp = temp -> left;
			}
			//If the given value is greater than value pointed by the current temp, then go to right of the tree. 
			else
			{
				//Checking for empty right null, so that we can insert there.
				if(temp -> right == NULL)
				{
					temp -> right = newNode;
					break;
				}
				temp = temp -> right;
			}
		}
	}
	printf("Data inserted successfully..!\n\n");
	
}

//Display data in L - R - D format.
//Postorder Traversal :: Light - Right - Data(L - R - D).
void postorder(TNODE head)
{	
	//Traverse light subtree -> Visit data -> Traverse right subtree.
	if(head != NULL)
	{
		postorder(head -> left);
		postorder(head -> right);
		printf("%d\n", head -> data);
		
	}
}


//Display data in D - L- R format.
//Preorder Traversal :: Data - Light - Right(D - L - R).
void preorder(TNODE head)
{	
	//Visit data -> Traverse right subtree -> Traverse light subtree.
	if(head != NULL)
	{
		printf("%d\n", head -> data);
		preorder(head -> left);
		preorder(head -> right);
	}
}


//Display data in L - D - R format.
//Inorder Traversal :: Left - Data - Right(L - D - R).
void inorder(TNODE head)
{	
	//Traverse left subtree -> Visit data -> Traverse right subtree
	if(head != NULL)
	{
		inorder(head -> left);
		printf("%d\n", head -> data);
		inorder(head -> right);
	}
}

//Count the number of nodes from a tree.
int count(TNODE head)
{
	static int cnt = 0;
	
	if(head != NULL)
	{
		cnt++;
		count(head -> left);
		count(head -> right);
	}
	return cnt;
}

//Searching for an value from a tree
bool searchNode(TNODE head, int data)
{
	if(head == NULL)
		return false;
	while(head != NULL)
	{
		//If data of head is equal to given data, then return true.
		if(head -> data == data)
		{
			return true;
		}
		//If the given value is less than value pointed by the current head, then go to left of head and search again. 
		else if(head -> data > data)
		{
			head = head -> left;
		}
		//If the given value is greater than value pointed by the current temp, then go to right of head and search again. 
		else
		{
			head = head -> right;
		}
		
	}
	return false;
}

//Entry point function
int main()
{
	int i = 0 , cnt = 0 , ele = 0 , pos = 0 , no = 0 ;
	
	TNODE head = NULL;
	
	printf("************** Binary Tree **************\n\n");
	while(1)
	{
		printf("1.Inserting an element into a tree \n\n2.Delete an element from a tree \n\n3.Searching for an element \n\n4.Preorder Traversal \n\n5.Inorder Traversal \n\n6.Postorder Traversal \n\n7.Count number of nodes from a tree \n\n0.Exit\n");
		printf("\nEnter your choice :\n");
		scanf("%d",&no);
		
		switch(no)
		{
			case 1:
					printf("Enter the value that you want to insert :\n");
					scanf("%d",&ele);
					insertNode(&head,ele);
					break;
			
			case 3:
					printf("Enter the value that you want to search :\n");
					scanf("%d",&ele);
					if(searchNode(head,ele))
						printf("Number is present in a tree..!\n\n");
					else
						printf("Number is not present in a tree..!\n\n");
					break;
					
			case 4:
					printf("Preorder traversal of binary tree :\n");
					preorder(head);
					break;
			
			case 5:
					printf("Inorder traversal of binary tree :\n");
					inorder(head);
					break;
					
			case 6:
					printf("Postorder traversal of binary tree :\n");
					postorder(head);
					break;
					
			case 7:
					cnt = count(head);
					printf("Number of nodes from a tree : %d\n\n", cnt);
					break;
			
			case 0:
					exit(0);
					
			default:
					printf("Wrong choice...!\n\n");
					break;
		}
	}
	
	return 0;
}

