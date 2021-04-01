int intersectPoint(Node* head1, Node* head2)
{
    Node *l1=head1;
    Node *l2 = head2;
    
    while(l1 != l2)
    {
        if(l1 == NULL)
        {
            l1 = head2;
        }
        else
        {
            l1 = l1->next;
        }
        if(l2 == NULL)
        {
            l2 = head1;
        }
        else
        {
            l2 = l2->next;
        }
    }
    if(l1 == NULL)
    return -1;
    
    return l1->data;
}