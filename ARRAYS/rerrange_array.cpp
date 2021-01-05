#include<bits/stdc++.h>

using namespace std;

void rightrotate(int arr[],int n,int outofplace,int curr)
{
	int temp = arr[curr];

	for(int i=curr;i>outofplace;i--)
	{
		arr[i] = arr[i-1];
	}

	arr[outofplace] = temp;
}

void rearrange(int arr[],int n)
{
	int outofplace = -1;

	for(int i = 0;i<n;i++)
	{
		if(outofplace >= 0)
		{
			if((arr[index] >= 0 && arr[outofplace] < 0) || arr[index] < 0 && arr[outofplace] >= 0)
			{
				rightrotate(arr,n,outofplace,index);
			}

			if(index - outofplace >=2)
			{
				outofplace += 2;
			}
			else
			{
				outofplace = -1;
			}
		}

		if(outofplace == -1)
		{
			if((arr[index] > 0 && index%2 != 0) || (arr[index] < 0 && index % 2 == 0))
			{
				outofplace = index;
			}
		}

	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	rearrange(arr,n);

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<endl;
}