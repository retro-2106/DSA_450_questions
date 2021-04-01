#include<bits/stdc++.h>
using namespace std;


int countreversals(string input)
{
    stack<char> stk;
    if(input.length() % 2 != 0)
    return -1;
    
    for(int i=0;i<input.length();i++)
    {
        if(input[i] == '}')
        {
            if(!stk.empty() && stk.top() == '{')
            {
                stk.pop();
            }
            else
            {
                stk.push(input[i]);
            }
        }
        else
        {
            stk.push(input[i]);
        }
    }
    
    
    int ans = 0;
    
    while(!stk.empty())
    {
        char a = stk.top();
        stk.pop();
        char b = stk.top();
        stk.pop();
        
        if(a == b)
        {
            ans ++;
        }
        else
        {
            ans+=2;
        }
    }
    
    return ans;
}
int main() 
{
    int n;
    cin>>n;
    
    
    while(n--)
    {
        string input;
        cin>>input;
        
        cout<<countreversals(input)<<endl;
    }
	return 0;
}
