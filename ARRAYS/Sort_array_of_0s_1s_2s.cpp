#include <bits/stdc++.h>

using namespace std;


void sort_modified(int arr[],int size)
{
    int i=0,j=i,k=size-1;
    
    while(j <= k)
    {
        if(arr[j] == 0)
        {     
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        else if(arr[j] == 2)
        {
            swap(arr[j],arr[k]);
            k--;
            //j++;
        }
        else
        {
            j++;
        }
    }
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int size;
	    cin>>size;
	    
	    int arr[size];
	    for(int i=0;i<size;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    sort_modified(arr,size);
	    
	    for(int i=0;i<size;i++)
	    {
	        cout<<arr[i]<<" ";
	    }
	    
	    cout<<endl;
	}
}