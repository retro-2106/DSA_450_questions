bool isCircular(Node *head)
{
   Node *t = head;
   head = head->next;
   while(head != NULL)
   {
       if(head == t)
       return true;
       
       head = head->next;
   }
   
   return false;
}