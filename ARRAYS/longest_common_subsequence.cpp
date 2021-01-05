#include <bits/stdc++.h>
using namespace std;

int lcs(int arr[],int n)
{
    unordered_map<int,int> ispresent;
    
    for(int i=0;i<n;i++)
    {
        ispresent[arr[i]]++;
    }
    
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        int curr=0;
        if(ispresent[arr[i] - 1] == 0)
        {
            int t = arr[i];
            while(ispresent[t] > 0)
            {
                curr++;
                t++;
            }
        }
        
        if(curr > count)
        {
            count = curr;
        }
    }
    
    return count;
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
        
        cout<<lcs(arr,n)<<endl;
    }
}