int max_rect_in_hist(int arr[],int size)
{
    vector<int> left(size),right(size);
    stack<int> stk;
    // filling the left array
    
    for(int i=0;i<size;i++)
    {
        if(stk.empty())
        {
            left[i] = 0;
            stk.push(i);
        }
        else
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i])
            {
                stk.pop();
            }
            
            left[i] = stk.empty()?0:stk.top()+1;
            
            stk.push(i);
        }
    }
    
    while(!stk.empty())
    stk.pop();
    
    for(int i=size-1;i>=0;i--)
    {
        if(stk.empty())
        {
            right[i] = size-1;
            stk.push(i);
        }
        else
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i])
            {
                stk.pop();
            }
            right[i] = stk.empty()?size-1:stk.top()-1;
            
            stk.push(i);
        }
    }
    
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans = max(ans,arr[i]*(right[i] - left[i]+1));
    }
    
    return ans;
}



/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) 
{
    int ans = max_rect_in_hist(M[0],m);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j])
            {
                M[i][j] += M[i-1][j];
            }
        }
        
        
        ans = max(ans,max_rect_in_hist(M[i],m));
    }
    
    return ans;
}