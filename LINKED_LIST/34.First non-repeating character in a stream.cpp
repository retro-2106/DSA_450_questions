class Solution {
	public:
	
	struct node
	{
	    char a;
	    struct node *next,*prev;
	};
	
	void appendNode(struct node **head_ref,struct node **tail_ref,char x)
	{
	   struct node* temp = new node; 
    temp->a = x; 
    temp->prev = temp->next = NULL; 
  
    if (*head_ref == NULL) { 
        *head_ref = *tail_ref = temp; 
        return; 
    } 
    (*tail_ref)->next = temp; 
    temp->prev = *tail_ref; 
    *tail_ref = temp; 
	    
	}
	
	void removeNode(struct node** head_ref,struct node **tail_ref,struct node *temp)
	{
	    if(*head_ref == NULL)
	    {
	        return;
	    }
	    
	    if (*head_ref == temp) 
        *head_ref = (*head_ref)->next; 
    if (*tail_ref == temp) 
        *tail_ref = (*tail_ref)->prev; 
    if (temp->next != NULL) 
        temp->next->prev = temp->prev; 
    if (temp->prev != NULL) 
        temp->prev->next = temp->next; 
  
    delete (temp); 
	}
	
	string FirstNonRepeating(string A)
	{
	    string ans = "";
	    struct node* inDLL[256];
	    bool repeated[256];
	    
	    struct node *head = NULL, *tail = NULL;
	    for(int i=0;i<256;i++)
	    {
	        inDLL[i] = NULL;
	        repeated[i] = false;
	    }
	    
	    for(int i=0;i<A.length();i++)
	    {
	        char x = A[i];
	        if(!repeated[x])
	        {
	            if(inDLL[x] == NULL)
	            {
	                appendNode(&head,&tail,A[i]);
	                inDLL[x] = tail;
	            }
	            else
	            {
	                removeNode(&head,&tail,inDLL[x]);
	                inDLL[x] = NULL;
	                repeated[x] = true;
	            }
	        }
	        
	        if(head != NULL)
	        {
	            ans += head->a;
	        }
	        else
	        {
	            ans += '#';
	        }
	    }
	    return ans;
	}

};