#include <bits/stdc++.h>
using namespace std;

int print(int p[],int n)
{
    int k=0;
    if(p[n] == 1)
    {
        k = 1;
    }
    else
    {
        k = print(p,p[n] - 1) + 1;
    }
    
    cout<<p[n]<<" "<<n<<" ";
    return k;
}
void wordwrap(int l[],int n,int M)
{
    // one extra space for simplicity
    int extras[n+1][n+1];
    int dp[n+1][n+1];
    
    int c[n+1];
    int p[n+1];
    
    //first we will fill extra matrix
    //this stores the space left in each line after
    //words frmom i to j are stored in a line
    
    for(int i=1;i<=n;i++)
    {
        extras[i][i] = M - l[i-1];
        
        for(int j=i+1;j<=n;j++)
        {
            extras[i][j] = extras[i][j-1] - l[j-1] -1;
        }
    }
    
    //Now we will fil dp which contain cost
    //when words from i to j are filled in a line
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(extras[i][j] < 0)
            {
                dp[i][j] = INT_MAX;
            }
            else if(j == n && extras[i][j] >= 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = extras[i][j]*extras[i][j];
            }
        }
    }
    
    //Now we will fill p array which contain
    //minimum cost when words ffrom 1 to j are placed
    c[0] = 0;
    for(int j=1;j<=n;j++)
    {
        c[j] =INT_MAX;
        for(int i=1;i<=j;i++)
        {
            if(c[i-1] != INT_MAX && dp[i][j] != INT_MAX && c[i-1]+dp[i][j] < c[j])
            {
                c[j] = c[i-1] + dp[i][j];
                p[j] = i;
            }
        }
    }
    
    print(p,n);
}




int main() {
	int t;
	
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int M;
	    cin>>M;
	    
	    wordwrap(arr,n,M);
	    cout<<endl;
	}
	return 0;
}
