#include <bits/stdc++.h>
using namespace std;

int find_minimum(int arr[],int n)
{
    int *dp = new int[n];
    
    dp[n-1] = 0;
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i] == 0)
        {
            dp[i] = INT_MAX;
        }
        else if( arr[i] >= n-i-1)
        {
            dp[i] = 1;
        }
        else
        {
            int minimum = INT_MAX;
            for(int j=i+1;j < n && j <= arr[i]+i;j++)
            {
                if(dp[j] < minimum)
                {
                    minimum = dp[j];
                }
            }
            
            if(minimum != INT_MAX)
            dp[i] = minimum + 1;
            else
            dp[i] = minimum;
        }
    }
    if(dp[0] == INT_MAX)
    return -1;
    else
    return dp[0];
}

int main() 
{
	int test;
	cin>>test;
	
	while(test--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    cout<<find_minimum(arr,n)<<endl;
	}
}