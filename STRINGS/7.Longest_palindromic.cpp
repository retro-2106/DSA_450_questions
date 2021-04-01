#include <bits/stdc++.h>
using namespace std;


int expand(string input,int i,int j)
{
    while(i >= 0 && j < input.length())
    {
        if(input[i] != input[j])
        break;
        
        i--;
        j++;
    }
    
    return (j-i)-1;
}

string longest_sub(string input)
{
    int start=0,end=0;
    int max_len=-1;
    for(int i=0;i<input.size();i++)
    {
        int len1 = expand(input,i,i);
        int len2 = expand(input,i,i+1);
        
        
        int len = max(len1,len2);
        
        if(len > (max_len))
        {
            start = i - (len-1)/2;
            end = i+ (len)/2;
            max_len=len;
        }
    }
    
    return input.substr(start,(end-start+1));
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	{
	    string input;
	    cin>>input;
	    
	    cout<<longest_sub(input)<<endl;
	}
	return 0;
}
