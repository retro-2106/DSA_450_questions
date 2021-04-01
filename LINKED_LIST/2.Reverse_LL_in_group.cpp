struct node *reverse (struct node *head, int k)
{ 
    if(head == NULL)
    return head;
    
    node* q;
    node*prev;
    node *curr = head;
    
    int counter = k;
    while(counter-- && curr != NULL)
    {
        q = curr->next;
        curr->next = prev;
        prev = curr;
        curr = q;
    }
    
    if(head != NULL)
    {
        head->next = reverse(q,k);
    }
    
    return prev;
}