//Program to find minimum and maximum elements
//We can don a simple linear search but here we want to reduce the number of comparisons
//The overall complexity will remain O(n) but the number of comparisons will reduce

#include<bits/stdc++.h>

using namespace std;

class Pair
{
public:
	int minimum;
	int maximum;
};

Pair find(vector<int> arr)
{
	Pair ans;
	int i;
	if(arr.size() % 2 == 0)
	{
		ans.minimum = min(arr[0],arr[1]);
		ans.maximum = max(arr[0],arr[1]);

		i = 2;
	}
	else
	{
		ans.minimum = ans.maximum = arr[0];
		i = 1;
	}

	while(i < arr.size())
	{
		if(arr[i] > arr[i+1])
		{
			if(arr[i] > ans.maximum)
				ans.maximum = arr[i];

			if(arr[i+1] < ans.minimum)
				ans.minimum = arr[i+1];
		}
		else
		{
			if(arr[i+1] > ans.maximum)
				ans.maximum = arr[i+1];
			if(arr[i] < ans.minimum)
				ans.minimum = arr[i];
		}
		i+=2;
	}

	return ans;
}

int main()
{
	int size;

	cin>>size;
	vector<int> arr;
	for(int i=0;i<size;i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	Pair ans;
	ans = find(arr);
	cout<<"Minimum :"<<ans.minimum<<" "<<"Maximum :"<<ans.maximum;

}