#include<bits/stdc++.h>

using namespace std;

int count_fun(int arr[],int n)
{
	int count=0;
	unordered_map<int,int>  mapp;

	for(int i=0;i<n;i++)
	{
		mapp[arr[i]]++;
	}

	for(int it=mapp.begin();it != mapp.end();i++)
	{
		if(it->second == n/k)
		{
			count++;
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

		cout<<count_fun(arr,n)<<endl;
	}
}