class Solution{
    public:
    // The main function that returns value of a given postfix expression
    int evaluatePostfix(string S)
    {
       stack<int> stk;
        for(int i=0;i<S.length();i++)
        {
            if(isdigit(S[i]))
            {
                stk.push(S[i]-'0');
            }
            else if(S[i] == '+')
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                
                stk.push(a+b);
            }
            else if(S[i] == '-')
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                
                stk.push(b-a);
            }
            else if(S[i] == '/')
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                
                stk.push(b/a);
            }
            else if(S[i] == '*')
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                
                stk.push(a*b);
            }
        }
        if(!stk.empty())
        return stk.top();
        
        return -1;
    }
};
