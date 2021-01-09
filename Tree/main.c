#include "binary_tree_header.h"
/*
You can include any .h file according to your need.
example : For counting all the nodes of a tree, include count_all_nodes.h file.
syntax : #include "count_all_nodes.h"
*/

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

