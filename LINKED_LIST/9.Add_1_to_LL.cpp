int helper(Node *head)
{
    if(!head)
    return 1;
    
    int value = head->data + helper(head->next);
    
    head->data = value%10;
    return value/10;
}

Node* addOne(Node *head) 
{
    int carry = helper(head);
    
    if(carry)
    {
        Node *temp = new Node(carry);
        temp->next = head;
        
        return temp;
    }
    return head;
}