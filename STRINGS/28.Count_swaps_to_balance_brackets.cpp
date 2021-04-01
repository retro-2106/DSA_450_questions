#include <bits/stdc++.h>

using namespace std;


int count_swap(string str)
{
    vector<int> v;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '[')
        {
            v.push_back(i);//this is the position of the breacket [
        }
    }
    
    int count = 0;
    int p=0;//position of bracket [
    int sum =0;
    for(int i=0;i<str.length();i++)
    {
        //if we encounter [ we will increase the count and position of [
        if(str[i] == '[')
        {
            count++;
            p++;
        }
        else
        {
            count--;
        }
        
        //if count becomes negative we will start balancing
        if(count < 0)
        {
            sum += v[p] - i;
            swap(str[i],str[v[p]]);
            p++;
            count = 1;
        }
    }
    return sum;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    string input;
	    int n;
	    cin>>n;
	    cin>>input;
	    
	    cout<<count_swap(input)<<endl;
	}
	return 0;
}