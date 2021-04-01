
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> stk;
    stk.push(arr[0]);
    vector<long long> ans;
    unordered_map<long long, long long> mp;
    for(int i=1;i<n;i++)
    {
        if(stk.empty())
        {
            stk.push(arr[i]);
            continue;
        }
        
        
        while(!stk.empty() && stk.top() < arr[i])
        {
            mp[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(arr[i]);
    }
    while(!stk.empty())
    {
        mp[stk.top()] = -1;
        stk.pop();
    }
    for(int i=0;i<n;i++)
    {
        ans.push_back(mp[arr[i]]);
    }
    return ans;
}