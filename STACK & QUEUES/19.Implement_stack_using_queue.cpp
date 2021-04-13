void QueueStack :: push(int x)
{
    q1.push(x);
    
    while(!q2.empty())
    {
        int a = q2.front();
        q2.pop();
        
        q1.push(a);
    }
    swap(q1,q2);
}

int QueueStack :: pop()
{
    if(q2.empty())
    return -1;
    int a = q2.front();
    q2.pop();
    return a;
}

