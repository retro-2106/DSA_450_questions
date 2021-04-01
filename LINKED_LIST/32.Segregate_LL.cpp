class Solution{
public:
    Node* divide(int N, Node *head)
    {
        Node *even_head = NULL,*even_tail,*odd_head = NULL,*odd_tail;
        
        Node *temp = head;
        
        while(temp != NULL)
        {
            if(temp->data % 2 == 0)
            {
                Node *t = new Node(temp->data);
                if(even_head == NULL)
                {
                    even_head = t;
                    even_tail = t;
                }
                else
                {
                    even_tail->next = t;
                    even_tail = even_tail->next;
                }
            }
            else
            {
                Node *t = new Node(temp->data);
                if(odd_head == NULL)
                {
                    odd_head = t;
                    odd_tail = t;
                }
                else
                {
                    odd_tail->next = t;
                    odd_tail = odd_tail->next;
                }
            }
            temp = temp->next;
        }
        if(even_head == NULL)
        return odd_head;
        
        even_tail->next = odd_head;
        return even_head;
    }
};