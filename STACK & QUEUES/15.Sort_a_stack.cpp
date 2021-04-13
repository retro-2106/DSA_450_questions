void insert(stack<int> &s,int x)
{
    if(s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }
    else
    {
        int a = s.top();
        s.pop();
        
        insert(s,x);
        s.push(a);
    }
}

void SortedStack :: sort()
{
   if(s.empty())
   {
       return;
   }
   else
   {
       int temp = s.top();
       s.pop();
       sort();
       
       insert(this->s,temp);
   }
}
