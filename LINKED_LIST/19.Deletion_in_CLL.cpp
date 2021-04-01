void deleteNode(struct Node **head, int key)
{
    if(*head == NULL)
    return;
    
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
    
    Node *last=*head,*d;

    if((*head)->data==key) 
    {

        while(last->next!=*head)
            last=last->next;

        last->next=(*head)->next;
        free(*head);
        *head=last->next;
    }
    
    while(last->next!=*head&&last->next->data!=key) 
    {
        last=last->next;
    }
    if(last->next->data==key) 
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
    {
        return;
    }
    
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    if(*head_ref == NULL)
    {
        return;
    }
    
    struct Node *prev = NULL;
    struct Node *curr = *head_ref;
    struct Node *q = NULL;
    
    while(curr->next != *head_ref)
    {
        q = curr->next;
        curr->next = prev;
        prev =curr;
        curr = q;
    }
    
    curr->next = prev;
    prev = curr;
    (*head_ref)->next = prev;
    
    *head_ref = prev;
}