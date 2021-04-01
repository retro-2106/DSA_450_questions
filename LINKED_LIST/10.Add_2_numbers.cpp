struct Node* reverse(struct Node*head)
{
    if(head == NULL)
    return head;
    
    Node *q;
    Node*prev = NULL;
    Node *curr = head;
    
    while(curr != NULL)
    {
        q = curr->next;
        curr->next = prev;
        prev = curr;
        curr = q;
    }
    
    return prev;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    if(first == NULL)
    return second;
    
    if(second == NULL)
    return first;
    
    first = reverse(first);
    second = reverse(second);
    
    struct Node* ans = new Node(0);
    //ans->data = 0;
    Node*t = ans;
    int carry = 0;
    int sum;
    while(first != NULL || second != NULL)
    {
        int a = first==NULL ? 0:first->data;
        int b = second == NULL ? 0 : second->data;
        
        sum = (a+b+carry)%10;
        carry = (a+b+carry)/10;
        struct Node* p = new Node(sum);
        //p->data = sum;
        ans->next = p;
        ans = ans->next;
        if(first != NULL)
        first = first->next;
        
        if(second != NULL)
        second = second->next;
    }
    if(carry > 0)
    {
        Node* p = new Node(carry);
        //p->data = carry;
        ans->next = p;
    }
    Node* result = reverse(t->next);
    return result;
}