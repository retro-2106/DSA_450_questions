stack<pair<int,int>> stk;
void push(int a)
{
    if(stk.empty())
    {
        stk.push(make_pair(a,a));
        return;
    }
    
    int minimum = min(a,stk.top().second);
    stk.push(make_pair(a,minimum));
}

bool isFull(int n)
{
     return stk.size() == n;
}

bool isEmpty()
{
    return stk.empty();
}

int pop()
{
    int ans = stk.top().first;
    stk.pop();
    return ans;
}

int getMin()
{
   return stk.top().second;
}