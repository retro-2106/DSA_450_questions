#include <iostream>

using namespace std;

void rotate(int arr[],int size)
{
    int temp;
    temp = arr[size-1];
    
    for(int i=size-1;i>0;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

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
            cin>>arr[i];
        }
        
        rotate(arr,size);
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}