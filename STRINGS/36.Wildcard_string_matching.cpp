#include <bits/stdc++.h>
using namespace std;

bool match(string s,string p)
{
     int m = s.length(),n = p.length();
        
        bool dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++)
        {
            dp[0][i] = (p[i-1] == '*') && dp[0][i-1];
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1] != '*')
                {
                    if(p[j-1] == '?' || s[i-1] == p[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
                else
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        
        return dp[m][n];
}

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string wildcard;
        cin>>wildcard;
        
        string text;
        cin>>text;
        
       if(match(text,wildcard))
       {
           cout<<"Yes"<<endl;
       }
       else
       {
           cout<<"No"<<endl;
       }
    }
	return 0;
}