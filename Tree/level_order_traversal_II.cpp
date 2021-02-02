void levelOrder(TNODE head)
{
    if(head == NULL)
        return;
    queue<TNODE> qobj;
    qobj.push(root);
    while(qobj.empty() == false)
    {
        TNODE temp = qobj.front();
        qobj.pop();
        cout << temp->data << " ";
        if(temp -> left != NULL)
             qobj.push(temp -> left);
        if(temp -> right != NULL)
             qobj.push(temp -> right);
    }
}
