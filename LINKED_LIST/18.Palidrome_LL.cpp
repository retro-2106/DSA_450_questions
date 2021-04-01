bool isPalindrome(Node *head)
{
    stack<int> stk;
    
    Node *temp = head;
    while(temp!= NULL)
    {
        stk.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(!stk.empty())
    {
        int a = stk.top();
        stk.pop();
        
        if(temp->data != a)
        return false;
        
        temp = temp->next;
    }
    
    return true;
}
