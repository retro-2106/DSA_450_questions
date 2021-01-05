#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int> arr,int n)
{
    int max_val = INT_MIN;
    int curr_max=0;
    
    for(int i=0;i<n;i++)
    {
        curr_max += arr[i];
        
        if(curr_max > max_val)
        {
            max_val = curr_max;
        }
        
        if(curr_max < 0)
        {
            curr_max = 0;
        }
    }
    
    return max_val;
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    vector<int> arr;
	    int n;
	    cin>>n;
	    
	    for(int i=0;i<n;i++)
	    {
	        int a;
	        cin>>a;
	        arr.push_back(a);
	    }
	    
	    cout<<kadane(arr,n)<<endl;
	}
}