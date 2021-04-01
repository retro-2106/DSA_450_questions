#include <bits/stdc++.h>
using namespace std;

bool solve(string input)
{
    map<char,int> mapp;
    
    for(int i=0;i<input.length();i++)
    {
        mapp[input[i]]++;
    }
    
    priority_queue<pair<int,char>> pq;
    
    for(auto it = mapp.begin();it != mapp.end();it++)
    {
        pq.push(make_pair(it->second,it->first));
    }
    
    pair<int,char> prev;
    prev.first = -1;
    prev.second = '#';
    string ans = "";
    while(!pq.empty())
    {
        pair<int,char> temp = pq.top();
        pq.pop();
        
        ans += temp.second;
        
        temp.first--;
        if(prev.first > 0)
        {
            pq.push(prev);
        }
        
        prev = temp;
    }
    
    if(ans.length() == input.length())
    return true;
    
    return false;
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    string input;
	    cin>>input;
	    
	    cout<<solve(input)<<endl;
	}
	return 0;
}