Node* reverseDLL(Node * head)
{
    if(head == NULL || head->next == NULL)
    return head;
    
    Node *prev= NULL;
    Node *next = NULL;
    Node *curr = head;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->prev = next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    
    return prev;
}