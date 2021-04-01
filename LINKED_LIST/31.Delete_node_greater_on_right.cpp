Node* reverse(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node *temp =reverse(head->next);
    
    head->next->next = head;
    head->next = NULL;
    return temp;
}
Node *compute(Node *head)
{
   if(head == NULL || head->next == NULL)
   return head;
   
   
   head = reverse(head);
  
   Node *curr = head;
   Node *max_node = head;
   Node *t;
   while(curr != NULL && curr->next != NULL)
   {
       if(curr->next->data < max_node->data)
       {
           t = curr->next;
           curr->next = t->next;
           delete t;
       }
       else
       {
           curr = curr->next;
           max_node = curr;
       }
   }
   
   head = reverse(head);
   return head;
}
