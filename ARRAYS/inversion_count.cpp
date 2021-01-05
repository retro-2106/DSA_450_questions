#include <iostream>
using namespace std;

long long merge(int arr[],int s,int mid, int e)
{
    if(s > e)
    return 0;
    
    int i,j,k;
    long long count = 0;
    int temp[e-s+1];
    i= s;
    j = mid;
    k = 0;
    
    while(i < mid && j <= e)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            
            count += (mid - i);
        }
    }
    while(i < mid)
    {
        temp[k++] = arr[i++];
    }
    
    while(j <= e)
    {
        temp[k++] = arr[j++];
    }
    k=0;
    for(i = s;i<= e;i++)
    {
        arr[i] = temp[k++];
    }
    
    return count;
}


long long merge_sort(int arr[],int s,int e)
{
    int count=0;
    if(s < e)
    {
        int mid = s + (e - s)/2;
        long long left = merge_sort(arr,s,mid);
        long long right = merge_sort(arr,mid+1,e);
        
        long long extra = merge(arr,s,mid+1,e);
        
        return left + right + extra;
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
        
        cout<<merge_sort(arr,0,n-1)<<endl;
    }
}