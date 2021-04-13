class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        long long mod = pow(10,9)+7;
        int dp[n+1];
        
        for(int i=0;i<=n;i++)
        {
            if(i <= 2)
            {
                dp[i] = i;
            }
            else
            {
                dp[i] = (dp[i - 1]%mod + ((i - 1)%mod * dp[i - 2])%mod)%mod;
            }
        }
        
        return dp[n];
    }
};    
