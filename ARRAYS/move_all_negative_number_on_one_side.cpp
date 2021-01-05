//Program to move all negative elements on one side

#include<bits/stdc++.h>

using namespace std;

void move_negative(int arr[],int size)
{
	int i=0;
	int j = size-1;

	while(i <= j)
	{
		//both are negative
		if(arr[i] < 0 && arr[j] < 0)
		{
			i++;
		}
		//left is positive and riight is negative
		else if(arr[i] > 0 && arr[j] < 0)
		{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
		//left and right both are positive
		else if(arr[i] > 0 && arr[j] > 0)
		{
			j--;
		}
		//left is negative and right is positive
		else
		{
			i++;
			j--;
		}
	}
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

		move_negative(arr,size);

		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}