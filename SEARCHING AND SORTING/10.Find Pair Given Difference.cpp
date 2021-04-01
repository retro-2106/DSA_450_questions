#include <bits/stdc++.h>
using namespace std;

int found(int arr[],int L,int N)
{
    set<int> s;
    for(int i=0;i<L;i++)
    {
        s.insert(arr[i]);
    }
    
    for(int i=0;i<L;i++)
    {
        if(s.find(abs(arr[i] - N)) != s.end())
        return 1;
    }
    return -1;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int L,N;
	    cin>>L>>N;
	    
	    int arr[L];
	    for(int i=0;i<L;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr,arr+L);
	    cout<<found(arr,L,N);
	    cout<<endl;
	}
	return 0;
}