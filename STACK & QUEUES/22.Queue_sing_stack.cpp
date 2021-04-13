void StackQueue :: push(int x)
 {
        
        
        while(!s1.empty())
        {
            int t = s1.top();
            s1.pop();
            
            s2.push(t);
        }
        s1.push(x);
        
        while(!s2.empty())
        {
            int t = s2.top();
            s2.pop();
            
            s1.push(t);
        }
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if(!s1.empty())
    {
        int t = s1.top();
        s1.pop();
        return t;
    }
    return -1;
}
