#include <bits/stdc++.h>
using namespace std;

void print_union(int arr1[],int arr2[],int size1,int size2)
{
    
    sort(arr1,arr1+size1);
    sort(arr2,arr2+size2);
    int count=0;
    int m = arr1[size1 - 1];
    int n = arr2[size2 - 1];
    
    int size = max(m,n);
    int *visited = new int[size+1];
    
    count++;//first element is always in the output
    visited[arr1[0]]++;
    for(int i=1;i<size1;i++)
    {
        if(arr1[i]  != arr1[i-1])
        {
            //cout<<arr1[i] <<" ";
            count++;
            visited[arr1[i]]++;
        }
    }
    
    
    for(int i=0;i<size2;i++)
    {
        if(visited[arr2[i]] == 0)
        {
            //cout<<arr2[i]<<" ";
            count++;
            visited[arr2[i]]++;
        }
    }
    cout<<count<<endl;
}


int main() 
{
	int t;
	
	cin>>t;
	
	while(t--)
	{
	     int size1,size2;
	     cin>>size1>>size2;
	     
	     int arr1[size1],arr2[size2];
	     
	     for(int i=0;i<size1;i++)
	     {
	         cin>>arr1[i];
	     }
	     for(int i=0;i<size2;i++)
	     {
	         cin>>arr2[i];
	     }
	     
	     print_union(arr1,arr2,size1,size2);
	}
	return 0;
}