#include "binary_tree_header.h"

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
