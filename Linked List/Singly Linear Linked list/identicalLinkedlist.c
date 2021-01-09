/*This function should return true if both 
linked lists are identical else return false.
Example 1:

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: Not identical 
Example 2:

Input:
LinkedList1: 1->2->3->4->5
LinkedList2: 1->2->3->4->5
Output: Identical
*/
bool areIdentical(struct Node *head1, struct Node *head2)
{
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data != head2 -> data)
        {
            return false;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return true;
}
