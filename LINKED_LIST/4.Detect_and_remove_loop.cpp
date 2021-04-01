void removeloop(Node* loopnode,Node *head)
{
    Node* ptr1 = loopnode;
    Node* ptr2 = loopnode;
    
    //finding the number of nodes involved in loop
    int k=1;
    while(ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }
    
    //now move one pointer k nodes ahead;
    ptr1 = head;
    ptr2 = head;
    
    for(int i=0;i<k;i++)
    {
        ptr2 = ptr2->next;
    }
    //move both pointers together
    while(ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    while(ptr2->next != ptr1)
    {
        ptr2 = ptr2->next;
    }
    
    ptr2->next = NULL;
}
void removeLoop(Node* head)
{
    if(!head)
    return;
    
    Node *slow,*fast;
    
    slow = head;
    fast = head;
    
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
        {
            removeloop(slow,head);
            return;
        }
    }
}