class Solution
{
    public:
    Node* segregate(Node *head) 
    {
        Node *temp = head;
        
        // int one=0,two=0,zero=0;
        
        // while(temp != NULL)
        // {
        //     if(temp->data == 0)
        //     zero++;
        //     if(temp->data == 1)
        //     one++;
        //     if(temp->data == 2)
        //     two++;
            
        //     temp = temp->next;
        // }
        // temp = head;
        
        // for(int i=0;i<zero;i++)
        // {
        //     temp->data = 0;
        //     temp = temp->next;
        // }
        
        // for(int i=0;i<one;i++)
        // {
        //     temp->data = 1;
        //     temp = temp->next;
        // }
        
        // for(int i=0;i<two;i++)
        // {
        //     temp->data = 2;
        //     temp = temp->next;
        // }
        // return head;
        int count[3] = {0,0,0};
        while(temp != NULL)
        {
            count[temp->data]++;
            temp = temp->next;
        }
        
        temp = head;
        int i=0;
        while(temp != NULL)
        {
            if(count[i] == 0)
            {
                i++;
            }
            else
            {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }
        return head;
    }
};