#include <bits/stdc++.h>
using namespace std;


int trapping_water(int arr[],int n)
{
    int water=0;
    
    int left[n],right[n];
    
    left[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        left[i] = max(left[i-1],arr[i]);
    }
    
    right[n-1] = arr[n-1];
    
    for(int i=n-2;i>=0;i--)
    {
        right[i] = max(right[i+1],arr[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        water += min(left[i],right[i]) - arr[i];
    }
    
    return water;
}

int main() 
{
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
	    
	    cout<<trapping_water(arr,n)<<endl;
	}
}