#include <bits/stdc++.h>

using namespace std;

bool issubset(int arr1[],int arr2[],int n1,int n2)
{
    unordered_map<int,int> mapp;
    
    for(int i=0;i<n1;i++)
    {
        mapp[arr1[i]]++;
    }
    
    for(int i=0;i<n2;i++)
    {
        if(mapp[arr2[i]] == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    
	    int arr1[n1],arr2[n2];
	    
	    for(int i=0;i<n1;i++)
	    {
	        cin>>arr1[i];
	    }
	    
	    for(int i=0;i<n2;i++)
	    {
	        cin>>arr2[i];
	    }
	
	if(issubset(arr1,arr2,n1,n2))
	{
	    cout<<"Yes"<<endl;
	}
	else
	{
	    cout<<"No"<<endl;
	}
	}
}