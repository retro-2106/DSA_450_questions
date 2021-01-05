#include <bits/stdc++.h>
using namespace std;

bool find_subarray(int arr[],int n)
{
    set<int>  ispresent;
    int sum = 0;
    
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        
        if(sum == 0 || ispresent.find(sum) != ispresent.end())
        {
            return 1;
        }
        
        ispresent.insert(sum);
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
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    if(find_subarray(arr,n))
	    {
	        cout<<"Yes"<<endl;
	    }
	    else
	    {
	        cout<<"No"<<endl;
	    }
	}
}