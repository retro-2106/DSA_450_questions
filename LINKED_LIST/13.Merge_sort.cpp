Node* getMid(Node* head) {
        if( head == NULL || head->next == NULL)
    return head;
    
    Node *slow = head,*fast=head->next->next;
    
    while(fast!= NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow->next;
    slow->next = NULL;
    return mid;
    }
Node *merge(Node *a,Node *b)
{
    if(a ==  NULL)
    return b;
    if(b == NULL)
    return a;
    
    Node *ans = new Node(0);
    Node *t = ans;
    
    while(a != NULL && b != NULL)
    {
        if(a->data < b->data)
        {
            t->next = a;
            a = a->next;
        }
        else
        {
            t->next = b;
            b = b->next;
        }
        t = t->next;
        
    }
    if(a)
    t->next = a;
    else
    t->next = b;
    
    return ans->next;
}

Node* mergeSort(Node* head) 
{
    if (!head || !head->next)
            return head;
        Node* mid = getMid(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);
        return merge(left, right);
}