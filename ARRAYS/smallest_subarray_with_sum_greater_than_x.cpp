#include <bits/stdc++.h>
using namespace std;

int min_length(int arr[],int n,int k)
{
    int len = n+1;
    
    
    for(int i=0;i<n;i++)
    {
        int curr = arr[i];
        
        if(curr > k)
        return 1;
        
        for(int j=i+1;j<n;j++)
        {
            curr += arr[j];
            
            if(curr > k && (j-i+1) < len)
            {
                len = j-i+1;
            }
        }
    }
    
    return len;
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    cout<<min_length(arr,n,k)<<endl;
	}
}