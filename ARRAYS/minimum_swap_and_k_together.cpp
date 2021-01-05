#include <iostream>
using namespace std;

int min_swap(int arr[],int n,int k)
{
    int good=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] <= k)
        good++;
    }
    
    int bad = 0;
    
    for(int i=0;i<good;i++)
    {
        if(arr[i] > k)
        bad++;
    }
    
    int ans = bad;
    for(int i=0,j=good;j<n;i++,j++)
    {
        if(arr[i] > k)
        bad--;
        
        if(arr[j] > k)
        bad++;
        
        
        ans = min(ans,bad);
    }
    
    return ans;
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
	    int k;
	    cin>>k;
	    cout<<min_swap(arr,n,k)<<endl;
	}
}