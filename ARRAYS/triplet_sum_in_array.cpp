#include <bits/stdc++.h>
using namespace std;

int triplet_sum(int arr[],int n,int sum)
{
    for(int i=0;i<n-2;i++)
    {
        int a = arr[i];
        
        int j = i+1;
        int k = n-1;
        
        while(j < k)
        {
            int s = a + arr[j] + arr[k];
            if(s == sum)
            {
                return 1;
            }
            else if(s < sum)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return 0;
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
	    int k;
	    cin>>k;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    
	    if(triplet_sum(arr,n,k))
	    {
	        cout<<1<<endl;
	    }
	    else
	    {
	        cout<<0<<endl;
	    }
	   
	}
}