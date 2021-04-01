Node *removeDuplicates(Node *root)
{
    if(!root || root->next == NULL)
    return root;
    
    Node *temp = root;
    
    while(temp->next != NULL)
    {
        Node *t = temp->next;
        if(temp->data == t->data)
        {
            temp->next = t->next;
            t->next = NULL;
        }
        else
        temp = temp->next;
    }
    
    return root;
}