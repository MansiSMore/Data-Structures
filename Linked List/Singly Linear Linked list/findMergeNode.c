/*
Given pointers to the head nodes of 2 linked lists that merge together at some point, find the node where the two lists merge. 
The merge point is where both lists point to the same node, i.e. they reference the same memory location. 
It is guaranteed that the two head nodes will be different, and neither will be NULL. If the lists share a common node, return that node's data value.
Note: After the merge point, both lists will share the same node pointers.
*/
/*
Input in graphical form :
 1
  \
   2--->3--->NULL
  /
 1
 
 output :
 2
 
 Input in graphical form :
 
 1--->2
      \
       3--->Null
      /
     1
 output :
 3
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    SinglyLinkedListNode *temp1 = head1, *temp2 = head2;

    while(temp1 != temp2)
    {
        if(temp1 -> next != NULL)
            temp1 = temp1 -> next;
        else {
            temp1 = head2;
        }
        if(temp2 -> next != NULL)
            temp2 = temp2 -> next;
        else {
            temp2 = head1;
        }
    }
    return temp1 -> data;
}
