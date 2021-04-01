int wordBreak(string A, vector<string> &B) 
{
    if(A.size() == 0)
    {
        return B.empty();
    }
    if(B.size() == 0)
    {
        return 0;
    }
    
    vector<bool> dp(A.length()+1,false);
    dp[0] = true;
    for(int i=1;i<=A.length();i++)
    {
        for(auto c : B)
        {
            int start = i - c.size();
            if(start < 0 || dp[start] == false)
            {
                continue;
            }
            
            string temp = A.substr(start,c.size());
            if(temp == c)
            {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[A.length()];
}
