class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum =0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }
        
        if(sum % 2 != 0)
        return 0;
        
        bool part[sum/2 + 1][n+1];
        
        for (int i = 0; i <= n; i++)
        part[0][i] = true;
        
        for(int i=0;i<=sum/2;i++)
        {
            part[i][0] = false;
        }
        
        for(int i = 1;i<= sum/2;i++)
        {
            for(int j = 1;j <=n; j++)
            {
                part[i][j] = part[i][j-1];
                
                if(i >= arr[j-1])
                {
                    part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
                }
            }
        }
        
        return part[sum/2][n];
    }
};

class Solution2{
public:
    int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
        }
        
        if(sum % 2 != 0)
        return 0;
        
        int dp[N+1][sum/2 + 1];
        
        for(int i=0;i<N+1;i++)
        {
            dp[i][0] = 1;
        }
        for(int i=0;i<sum/2+1;i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<sum/2 + 1;j++)
            {
                dp[i][j] = dp[i-1][j];
                
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
                }
            }
        }
        
        return dp[N][sum/2];
    }
};
