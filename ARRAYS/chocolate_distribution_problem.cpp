#include <bits/stdc++.h>

using namespace std;

int chocolate(int arr[],int n,int m)
{
    if(n == 0||m==0)
    return 0;
    
    if(n < m)
    return -1;
    
    int min_diff = INT_MAX;
    
    for(int i=0;i + m -1 < n;i++)
    {
        int d = arr[i+m-1] - arr[i];
        if(d < min_diff)
        {
            min_diff = d;
        }
    }
    
    return min_diff;
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
	    sort(arr,arr+n);
	    int m;
	    cin>>m;
	    cout<<chocolate(arr,n,m)<<endl;
	}
}