#include "binary_tree_header.h"

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
