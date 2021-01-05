#include <iostream>
using namespace std;

//we are storing the number in reverse order in the array

int multiply(int arr[],int x,int size)
{
    int carry = 0;
    for(int i=0;i<size;i++)
    {
        int p = arr[i] * x + carry;
        
        arr[i] = p%10;
        carry = p/10;
    }
    
    while(carry)
    {
        arr[size] = carry%10;
        carry /= 10;
        size++;
    }
    
    return size;
}

void factorial(int n)
{
    int arr[5000];
    int size;
    arr[0] = 1; ///means value of 0 factorial is 1
    size = 1;
    
    for(int x = 2;x <= n; x++)
    {
        size = multiply(arr,x,size);
    }
    
    for(int i=size-1;i>=0;i--)
    {
        cout<<arr[i];
    }
    
}


int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    factorial(n);
	    cout<<endl;
	}
}