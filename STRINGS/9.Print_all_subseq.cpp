#include<bits/stdc++.h>

using namespace std;
vector<string> v;
void print_subsequence(string input,string ans)
{
    if(input.length() == 0)
    {
        v.push_back(ans);
        return;
    }
    
    print_subsequence(input.substr(1),ans+input[0]);
    print_subsequence(input.substr(1),ans);
}

int main()
{
    string input;
    input="abc";
    
    print_subsequence(input,"");
    
    for(int i=0;i<v.size();i++)
    {
        cout<<v.at(i)<<endl;
    }
}
