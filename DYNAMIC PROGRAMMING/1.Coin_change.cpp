#include<bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        long long dp[n+1][m];
        
        for(int i=0;i < m;i++)
        {
            dp[0][i] = 1;
        }
        for(int i=1;i<n + 1;i++)
        {
            for(int j=0;j<m;j++)
            {
                long long x = (i - S[j] >= 0) ? dp[i-S[j]][j] : 0;
                long long y = (j >= 1)? dp[i][j-1] : 0;
                
                dp[i][j] = x + y;
            }
        }
        return dp[n][m-1];
    }
};

class Solution2
{
  public:
    long long int count( int S[], int m, int n )
    {
        long long int dp[m+1][n+1];
       
       for(int i=0;i<m+1;i++)
       {
           dp[i][0] = 1;
       }
      for(int j=0; j < n+1;j++)
      {
          dp[0][j] = 0;
      }
       
       for(int i=1;i<m+1;i++)
       {
           for(int j=1;j<n+1;j++)
           {
               if(S[i-1] > j)
               {
                   dp[i][j] = dp[i-1][j];
               }
               else
               {
                   dp[i][j] = dp[i][j - S[i-1]] + dp[i-1][j];
               }
           }
       }
       return dp[m][n];
    }
};