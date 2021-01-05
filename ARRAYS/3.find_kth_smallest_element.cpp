#include <bits/stdc++.h>

using namespace std;
int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int size;
	    cin>>size;
	    int arr[size];
	    
	    for(int i=0;i<size;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    int k;
	    cin>>k;
	    sort(arr,arr+size);
	    
	    cout<<arr[k-1]<<endl;
	}
}