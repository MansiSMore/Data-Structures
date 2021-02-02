#include "binary_search_tree_header.h"

//Print nodes at a given level
void atLevel(TNODE head, int level) 
{ 
    if(head == NULL)
    	return; 
    if(level == 1) 
		printf("%d\n", head -> data);
    else if(level > 1) 
    { 
    	//printf("before %d\n", head -> data);
        atLevel(head -> left, level-1); 
    	//printf("before 1 %d\n", head -> data);
        atLevel(head -> right, level-1); 
    	//printf("after %d\n", head -> data);
    } 
} 

//Level order traversal of a tree is breadth first traversal for the tree. 
//Traversing child nodes of single parent and then move on.
void levelOrder(TNODE head)
{	
	int h = heightOfTree(head); 
    int i; 
    for (i = 1; i <= h; i++) 
        atLevel(head, i); 
}
