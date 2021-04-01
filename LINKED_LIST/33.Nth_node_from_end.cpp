int getNthFromLast(Node *head, int n)
{
    if(head == NULL)
    return -1;
    
    Node *slow,*fast;
    
    slow = head;
    fast = head;
    int cnt = 0;
    while(cnt < n)
    {
        if(fast == NULL)
        return -1;
        fast = fast->next;
        cnt++;
    }
    
    if(fast == NULL)
    {
        head = head->next;
        if(head != NULL)
        {
            return slow->data;
        }
    }
    else
    {
        while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
    }
    
}