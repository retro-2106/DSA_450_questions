bool ispar(string x)
{
    stack<char> stk;
    
    for(int i=0;i<x.length();i++)
    {
        if(x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            stk.push(x[i]);
        }
        else
        {
            if(stk.empty())
            {
                return false;
            }
            else
            {
                char top = stk.top();
                if(x[i] == ')')
                {
                    if(top == '(')
                    {
                        stk.pop();
                    }
                    else 
                    return false;
                }
                else if(x[i] == '}')
                {
                    if(top == '{')
                    {
                        stk.pop();
                    }
                    else 
                    return false;
                }
                else
                {
                    if(top == '[')
                    {
                        stk.pop();
                    }
                    else 
                    return false;
                }
            }
        }
    }
    return stk.empty();
}
