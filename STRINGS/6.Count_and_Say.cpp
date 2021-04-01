class Solution {
public:
    string countAndSay(int n) 
    {
        if( n <=0)
            return "";
        
        string ans = "1";
        
        
        for(int i=2;i<=n;i++)
        {
            string s = ans;
            ans = "";
            int prev = 0;
            for(int j=1;j<=s.size();j++)
            {
                if(s[j] != s[prev])
                {
                    ans +=  to_string(j-prev);
                    ans +=s[prev];
                    prev = j;
                }
            }
        }
        return ans;
    }
};