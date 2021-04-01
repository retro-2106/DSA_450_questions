#include <bits/stdc++.h>


using namespace std;

int first_index(int arr[],int s,int e,int k)
{
    if(s <= e)
    {
    int mid = (s + e)/2;
    
    if((mid == 0 ||arr[mid-1] < k) && arr[mid] == k )
    return mid;
    
    else if(arr[mid] < k)
    {
        return first_index(arr,mid+1,e,k);
    }
    else
    {
        return first_index(arr,s,mid-1,k);
    }
    
    }
    else
    return -1;
}

int last_index(int arr[],int s,int e,int k,int n)
{
    if(s <= e)
    {
    int mid = (s + e)/2;
    
    if((mid == n-1 ||arr[mid+1] > k) && arr[mid] == k )
    return mid;
    
    else if(arr[mid] > k)
    {
        return last_index(arr,s,mid-1,k,n);
    }
    else
    {
        return last_index(arr,mid+1,e,k,n);
    }
    }
    else
    return -1;
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
	    int left;
	    left = first_index(arr,0,n-1,k);
	    cout<<left;
	    if(left != -1)
	    cout<<" "<<last_index(arr,0,n-1,k,n);
	    
	    cout<<endl;
	}
	return 0;
}