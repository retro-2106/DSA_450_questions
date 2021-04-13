queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> stk;
    int t = k;
    while(t-- && !q.empty())
    {
        stk.push(q.front());
        q.pop();
    }
    queue<int> temp;
    while(!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }
    
    while(!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }
    while(!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
    
    return q;

