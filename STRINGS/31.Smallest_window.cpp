string findSubString(string str)
{
    int n = str.length();
    
    unordered_map<char,int> mapp;
    
    for(int i=0;i<n;i++)
    {
        mapp[str[i]]++;
    }
    
    unordered_map<char,int> curr;
    int count=0;
    int len = INT_MAX;
    int i=0;
    int j=0;
    int ans=0;
    while(j < n)
    {
        curr[str[j]]++;
        
        if(curr[str[j]] == 1)
        count++;
        
        if(count == mapp.size())
        {
            while(curr[str[i]] > 1)
            {
                curr[str[i]]--;
                i++;
            }
            
            int curr_len = j - i + 1;
        
        if(curr_len < len)
        {
            len = curr_len;
            ans = i;
        }
        }
        j++;
    }
    
    return str.substr(ans,len);
}