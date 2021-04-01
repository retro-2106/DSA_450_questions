#include <bits/stdc++.h>

using namespace std;

vector<string> result;

void dfs(string s,unordered_set<string> &word,string temp)
{
    if(s.size() == 0)
    {
        temp.erase(temp.end()-1);
        result.push_back(temp);
        return;
    }
    
    for(int i=0;i<s.size();i++)
    {
        string t = s.substr(0,i+1);
        if(word.find(t) != word.end())
        {
            string new_t = s.substr(i+1);
            dfs(new_t,word,temp+t+" ");
        }
    }
}
vector<string> word_break(vector<string> dict,string input,int n)
{
    unordered_set<string> word(dict.begin(),dict.end());
    
    string temp;
    dfs(input,word,temp);
    
    return result;
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
    {
        int n;
        cin>>n;
        vector<string> dict;
        result.clear();
        for(int i=0;i<n;i++)
        {
            string a;
            cin>>a;
            dict.push_back(a);
        }
        
        string input;
        cin>>input;
        
        vector<string> ans = word_break(dict,input,n);
        
        for(auto it : ans)
        {
            cout<<"("<<it<<")";
        }
        cout<<endl;
    }
	return 0;
}