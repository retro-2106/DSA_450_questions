Node *copyList(Node *head) 
{
    Node *newhead =NULL;
        Node *newtail = NULL;
       // Node *t;
        unordered_map<Node*,Node*> mapp;
        Node *curr = head;
        while(curr != NULL)
        {
            Node *temp = new Node(curr->data);
            mapp[curr] = temp;
            if(newhead == NULL)
            {
                newhead = temp;
                newtail = temp;
            }
            else
            {
                newtail->next = temp;
                newtail = temp;
            }
            curr = curr->next;
        }
        curr = head;
        while(curr !=NULL)
        {
            if(curr->arb != NULL)
            {
                mapp[curr]->arb = mapp[curr->arb];
            }
            curr = curr->next;
        }
        return newhead;
}