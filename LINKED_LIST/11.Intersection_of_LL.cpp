Node* findIntersection(Node* head1, Node* head2)
{
    Node *l1,*l2;
    Node *ans = NULL,*tail=NULL;
    l1 = head1;
    l2 = head2;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data < l2->data)
        {
            l1 = l1->next;
        }
        else if(l1->data > l2->data)
        {
            l2 = l2->next;
        }
        else
        {
            if(ans == NULL)
            {
                ans = new Node(l1->data);
                tail=ans;
            }
            else
            {
                Node *new_node = new Node(l1->data);
                tail->next = new_node;
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    return ans;
}