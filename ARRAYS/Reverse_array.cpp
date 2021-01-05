//Program to reverse an array


#include<bits/stdc++.h>

using namespace std;

void reverse2(vector<int> &arr,int s,int e)
{
	while(s <= e)
	{
		int temp = arr[s];
		arr[s] = arr[e];
		arr[e] = temp;
		
		s++;
		e--;
	}
	return;
}
int main()
{
	int size;
	cin>>size;

	vector<int> arr(size);

	for(int i=0;i<size;i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}

	reverse(arr.begin(),arr.end());

	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
    cout<<endl;
	reverse2(arr,0,size-1);
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}