class Solution{
public:
   
int nCr(int n, int r)
    {
        long long mod = pow(10,9)+7;
        int c[n+1][r+1];
        
        memset(c,0,sizeof(c));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<= min(i,r);j++)
            {
                if(i == j || j == 0 )
                {
                    c[i][j] = 1;
                }
                else
                {
                    c[i][j] = (c[i-1][j-1]%mod + c[i-1][j]%mod)%mod;
                }
            }
        }
        
        return c[n][r];
    }
};
